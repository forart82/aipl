#!/usr/bin/env python3
"""Repackages editors/vscode-aipl/<name>-<version>.vsix from current workspace files.

Identity, description, engine and the packed file list are all derived from the extension's package.json
(main, icon, README, contributes.* paths), so the .vsixmanifest can never drift from the manifest VS Code
actually loads, and a newly contributed theme/grammar/snippet/icon is packed automatically. The archive is
written to a temp file and atomically renamed, so a failed run never leaves a truncated .vsix behind.
"""

import json
import os
import sys
import tempfile
import zipfile
from pathlib import Path
from xml.sax.saxutils import escape

CONTENT_TYPES = """<?xml version="1.0" encoding="utf-8"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">
  <Default Extension=".json" ContentType="application/json"/>
  <Default Extension=".js" ContentType="application/javascript"/>
  <Default Extension=".md" ContentType="text/markdown"/>
  <Default Extension=".png" ContentType="image/png"/>
  <Default Extension=".svg" ContentType="image/svg+xml"/>
  <Default Extension=".vsixmanifest" ContentType="text/xml"/>
</Types>
"""


def _rel(p):
    """Normalizes a package.json relative path ('./x/y.json') to 'x/y.json'; rejects paths escaping the extension."""
    s = str(p).replace("\\", "/")
    while s.startswith("./"):
        s = s[2:]
    norm = os.path.normpath(s).replace("\\", "/")
    if norm.startswith("../") or norm == ".." or os.path.isabs(norm):
        raise ValueError(f"package.json path escapes the extension directory: {p}")
    return norm


def collect_files(pkg):
    """Returns the ordered, de-duplicated list of extension-relative files the manifest references."""
    files = ["package.json", "README.md"]
    if pkg.get("main"):
        main = _rel(pkg["main"])
        files.append(main if main.endswith(".js") else main + ".js")
    if pkg.get("icon"):
        files.append(_rel(pkg["icon"]))
    contrib = pkg.get("contributes", {}) or {}
    for lang in contrib.get("languages", []) or []:
        if lang.get("configuration"):
            files.append(_rel(lang["configuration"]))
        icon = lang.get("icon")
        if isinstance(icon, dict):
            for key in ("light", "dark"):
                if icon.get(key):
                    files.append(_rel(icon[key]))
        elif isinstance(icon, str):
            files.append(_rel(icon))
    for section in ("grammars", "snippets", "themes", "iconThemes", "productIconThemes"):
        for entry in contrib.get(section, []) or []:
            if entry.get("path"):
                files.append(_rel(entry["path"]))
    seen = set()
    ordered = []
    for f in files:
        if f not in seen:
            seen.add(f)
            ordered.append(f)
    return ordered


def build_manifest(pkg):
    name = pkg["name"]
    version = pkg["version"]
    publisher = pkg["publisher"]
    display = pkg.get("displayName", name)
    description = pkg.get("description", "")
    tags = ",".join(pkg.get("keywords", []) or ["aipl"])
    categories = ",".join(pkg.get("categories", []) or ["Programming Languages"])
    engine = (pkg.get("engines", {}) or {}).get("vscode", "*")
    icon_xml = ""
    icon_asset = ""
    if pkg.get("icon"):
        icon_path = "extension/" + _rel(pkg["icon"])
        icon_xml = f"\n    <Icon>{escape(icon_path)}</Icon>"
        icon_asset = f'\n    <Asset Type="Microsoft.VisualStudio.Services.Icons.Default" Path="{escape(icon_path)}" Addressable="true" />'
    return f"""<?xml version="1.0" encoding="utf-8"?>
<PackageManifest Version="2.0.0" xmlns="http://schemas.microsoft.com/developer/vsx-schema/2011" xmlns:d="http://schemas.microsoft.com/developer/vsx-schema-design/2011">
  <Metadata>
    <Identity Language="en-US" Id="{escape(name)}" Version="{escape(version)}" Publisher="{escape(publisher)}" />
    <DisplayName>{escape(display)}</DisplayName>
    <Description xml:space="preserve">{escape(description)}</Description>
    <Tags>{escape(tags)}</Tags>
    <Categories>{escape(categories)}</Categories>
    <GalleryFlags>Public</GalleryFlags>
    <Properties>
      <Property Id="Microsoft.VisualStudio.Code.Engine" Value="{escape(engine)}" />
      <Property Id="Microsoft.VisualStudio.Code.ExtensionDependencies" Value="" />
      <Property Id="Microsoft.VisualStudio.Code.ExtensionPack" Value="" />
      <Property Id="Microsoft.VisualStudio.Code.LocalizedLanguages" Value="" />
    </Properties>{icon_xml}
  </Metadata>
  <Installation>
    <InstallationTarget Id="Microsoft.VisualStudio.Code"/>
  </Installation>
  <Dependencies/>
  <Assets>
    <Asset Type="Microsoft.VisualStudio.Code.Manifest" Path="extension/package.json" Addressable="true" />
    <Asset Type="Microsoft.VisualStudio.Services.Content.Details" Path="extension/README.md" Addressable="true" />{icon_asset}
  </Assets>
</PackageManifest>
"""


def package(ext_dir, out_path=None):
    ext_dir = Path(ext_dir)
    pkg = json.loads((ext_dir / "package.json").read_text(encoding="utf-8"))
    for field in ("name", "version", "publisher"):
        if not pkg.get(field):
            raise ValueError(f"package.json is missing required field '{field}'")
    vsix_path = Path(out_path) if out_path else ext_dir / f"{pkg['name']}-{pkg['version']}.vsix"
    files = collect_files(pkg)
    missing = [f for f in files if not (ext_dir / f).is_file()]
    if missing:
        raise FileNotFoundError("Missing files referenced by package.json: " + ", ".join(missing))
    fd, tmp_name = tempfile.mkstemp(prefix=".vsix-", suffix=".tmp", dir=str(vsix_path.parent))
    os.close(fd)
    try:
        with zipfile.ZipFile(tmp_name, "w", compression=zipfile.ZIP_DEFLATED) as z:
            z.writestr("[Content_Types].xml", CONTENT_TYPES)
            z.writestr("extension.vsixmanifest", build_manifest(pkg))
            for rel in files:
                z.write(ext_dir / rel, arcname="extension/" + rel)
        # mkstemp creates the file 0600; give the published archive normal umask-derived permissions
        umask = os.umask(0)
        os.umask(umask)
        os.chmod(tmp_name, 0o666 & ~umask)
        os.replace(tmp_name, vsix_path)
    except BaseException:
        if os.path.exists(tmp_name):
            os.unlink(tmp_name)
        raise
    return vsix_path, files


def main():
    root = Path(__file__).resolve().parent.parent
    ext_dir = root / "editors" / "vscode-aipl"
    out = sys.argv[1] if len(sys.argv) > 1 else None
    vsix_path, files = package(ext_dir, out)
    print(f"Successfully packaged {vsix_path} ({vsix_path.stat().st_size} bytes, {len(files)} files)")


if __name__ == "__main__":
    main()
