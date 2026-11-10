/* AIPL C99 runtime module: rt_core.c (Phase 18 split modular runtime). */
#include "aipl_runtime.h"

#if defined(__x86_64__) || defined(_M_X64)
#else
#endif
#if defined(__GNUC__) || defined(__clang__)
#else
#endif
#if defined(__linux__)
#endif
#if defined(__x86_64__) || defined(_M_X64)
#elif defined(__aarch64__)
#endif
#ifndef _WIN32
#endif
AiplVal aipl_func(AiplFnPtr fn) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_FUNC; v.ptr = (void*)fn; return v;
}

AiplVal aipl_format_val(AiplVal v, const char* spec) {
  if (!spec || spec[0] == 0) return aipl_to_str(v);
  char buf[256];
  size_t sl = strlen(spec);
  if (strcmp(spec, "bytes") == 0) {
    int64_t bval = (v.kind == AIPL_INT) ? v.i : (int64_t)v.f;
    if (bval < 1024) snprintf(buf, sizeof(buf), "%lld B", (long long)bval);
    else if (bval < 1048576LL) snprintf(buf, sizeof(buf), "%.1f KB", (double)bval / 1024.0);
    else if (bval < 1073741824LL) snprintf(buf, sizeof(buf), "%.1f MB", (double)bval / 1048576.0);
    else snprintf(buf, sizeof(buf), "%.1f GB", (double)bval / 1073741824.0);
    return aipl_str(buf);
  }
  if (spec[0] == '>' || spec[0] == '<') {
    int width = atoi(spec + 1);
    AiplVal rawS = aipl_to_str(v);
    const char* strContent = rawS.s ? rawS.s : "";
    int slen = (int)strlen(strContent);
    if (slen < width) {
      int pad = width - slen; char* padded = (char*)malloc(width + 1);
      if (spec[0] == '>') { memset(padded, ' ', pad); memcpy(padded + pad, strContent, slen); }
      else { memcpy(padded, strContent, slen); memset(padded + slen, ' ', pad); }
      padded[width] = 0; AiplVal res = aipl_str(padded); free(padded); return res;
    }
    return rawS;
  }
  if (spec[0] == '0') {
    bool allDigits = true;
    for (size_t di = 0; di < sl; di++) { if (spec[di] < '0' || spec[di] > '9') { allDigits = false; break; } }
    if (allDigits) {
      int w = atoi(spec);
      snprintf(buf, sizeof(buf), "%0*lld", w, (long long)v.i);
      return aipl_str(buf);
    }
  }
  bool valid_mods = (sl > 0 && sl < 24);
  for (size_t mi = 0; valid_mods && mi + 1 < sl; mi++) {
    char mc = spec[mi];
    if (!((mc >= '0' && mc <= '9') || mc == '.' || mc == '-' || mc == '+' || mc == ' ' || mc == '#')) {
      valid_mods = false;
    }
  }
  if (!valid_mods) return aipl_to_str(v);
  if (spec[sl - 1] == 'o') {
    char fmt[32];
    snprintf(fmt, sizeof(fmt), "%%%.*sllo", (int)(sl - 1), spec);
    snprintf(buf, sizeof(buf), fmt, (unsigned long long)v.i);
    return aipl_str(buf);
  }
  if (spec[sl - 1] == 'b') {
    int width = (sl > 1) ? atoi(spec) : 0;
    if (width >= (int)sizeof(buf)) width = (int)sizeof(buf) - 1;
    unsigned long long uval = (unsigned long long)v.i;
    char tmp[65]; int tidx = 0;
    if (uval == 0) { tmp[tidx++] = '0'; }
    else { while (uval > 0) { tmp[tidx++] = (uval & 1) ? '1' : '0'; uval >>= 1; } }
    char rev[65];
    for (int k = 0; k < tidx; k++) rev[k] = tmp[tidx - 1 - k];
    rev[tidx] = 0;
    if (width > tidx) {
      int pad = width - tidx;
      memset(buf, '0', (size_t)pad); memcpy(buf + pad, rev, (size_t)tidx); buf[width] = 0;
      return aipl_str(buf);
    }
    return aipl_str(rev);
  }
  if (sl > 0 && (spec[sl - 1] == 'd' || spec[sl - 1] == 'x' || spec[sl - 1] == 'X')) {
    char fmt[32];
    snprintf(fmt, sizeof(fmt), "%%%.*sll%c", (int)(sl - 1), spec, spec[sl - 1]);
    if (spec[sl - 1] == 'd') snprintf(buf, sizeof(buf), fmt, (long long)v.i);
    else snprintf(buf, sizeof(buf), fmt, (unsigned long long)v.i);
    return aipl_str(buf);
  }
  double fval = (v.kind == AIPL_FLOAT) ? v.f : (double)v.i;
  if (sl > 0 && spec[sl - 1] == 'g') {
    char fmt[32];
    snprintf(fmt, sizeof(fmt), "%%%.*sf", (int)(sl - 1), spec);
    snprintf(buf, sizeof(buf), fmt, fval);
    if (strchr(buf, '.')) {
      size_t blen = strlen(buf);
      while (blen > 0 && buf[blen - 1] == '0') { buf[--blen] = 0; }
      if (blen > 0 && buf[blen - 1] == '.') { buf[--blen] = 0; }
    }
    return aipl_str(buf);
  }
  if (sl > 0 && spec[sl - 1] == 'f') {
    char fmt[32];
    snprintf(fmt, sizeof(fmt), "%%%s", spec);
    snprintf(buf, sizeof(buf), fmt, fval);
    return aipl_str(buf);
  }
  return aipl_to_str(v);
}

AiplVal aipl_str_concat(AiplVal a, AiplVal b) {
  const char* sa = (a.kind == AIPL_STR && a.s) ? a.s : "";
  const char* sb = (b.kind == AIPL_STR && b.s) ? b.s : "";
  size_t la = aipl_str_byte_len(a); size_t lb = aipl_str_byte_len(b);
  size_t tot = la + lb;
  char* buf;
  if (_aipl_arena_depth > 0) {
    buf = (char*)aipl_arena_alloc_raw((int64_t)(tot + 1));
  } else {
    aipl_prof_record_alloc(tot + 1);
    buf = (char*)malloc(tot + 1);
  }
  memcpy(buf, sa, la); memcpy(buf + la, sb, lb); buf[tot] = 0;
  AiplVal v; memset(&v, 0, sizeof(v));
  v.kind = AIPL_STR; v.s = buf; v.extra_i = (tot > 0) ? (int)tot : -1;
  return v;
}

AiplVal aipl_div_slow(AiplVal a, AiplVal b) {
  if (aipl_is_vec2(a)) {
    AiplStruct* sa = (AiplStruct*)a.ptr;
    double ax = (sa->vals[0].kind == AIPL_FLOAT) ? sa->vals[0].f : (double)sa->vals[0].i;
    double ay = (sa->vals[1].kind == AIPL_FLOAT) ? sa->vals[1].f : (double)sa->vals[1].i;
    if (aipl_is_vec2(b)) {
      AiplStruct* sb = (AiplStruct*)b.ptr;
      double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
      double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
      return aipl_vec2(bx != 0.0 ? ax / bx : 0.0, by != 0.0 ? ay / by : 0.0);
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_vec2(s != 0.0 ? ax / s : 0.0, s != 0.0 ? ay / s : 0.0);
  }
  if (aipl_is_vec3(a)) {
    AiplStruct* sa = (AiplStruct*)a.ptr;
    double ax = (sa->vals[0].kind == AIPL_FLOAT) ? sa->vals[0].f : (double)sa->vals[0].i;
    double ay = (sa->vals[1].kind == AIPL_FLOAT) ? sa->vals[1].f : (double)sa->vals[1].i;
    double az = (sa->vals[2].kind == AIPL_FLOAT) ? sa->vals[2].f : (double)sa->vals[2].i;
    if (aipl_is_vec3(b)) {
      AiplStruct* sb = (AiplStruct*)b.ptr;
      double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
      double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
      double bz = (sb->vals[2].kind == AIPL_FLOAT) ? sb->vals[2].f : (double)sb->vals[2].i;
      return aipl_rt_Vec3(aipl_float(bx != 0.0 ? ax / bx : 0.0), aipl_float(by != 0.0 ? ay / by : 0.0), aipl_float(bz != 0.0 ? az / bz : 0.0));
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_rt_Vec3(aipl_float(s != 0.0 ? ax / s : 0.0), aipl_float(s != 0.0 ? ay / s : 0.0), aipl_float(s != 0.0 ? az / s : 0.0));
  }
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_float(fb != 0.0 ? fa / fb : 0.0);
  }
  if (b.i == 0) return aipl_int(0);
  if (a.i == INT64_MIN && b.i == -1) return aipl_int(INT64_MIN);
  return aipl_int(a.i / b.i);
}

AiplVal aipl_pow(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT && b.i >= 0) {
    uint64_t r = 1ULL;
    uint64_t base_u = (uint64_t)a.i;
    uint64_t exp_u = (uint64_t)b.i;
    while (exp_u > 0) {
      if (exp_u & 1ULL) r *= base_u;
      base_u *= base_u;
      exp_u >>= 1;
    }
    return aipl_int((int64_t)r);
  }
  double base = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
  double exp_val = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
  return aipl_float(pow(base, exp_val));
}

AiplVal aipl_euclid_mod(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    if (fb == 0.0) return aipl_float(0.0);
    double m = fmod(fa, fb);
    if (m < 0.0) m += fabs(fb);
    return aipl_float(m);
  }
  if (b.i == 0 || b.i == 1 || b.i == -1) return aipl_int(0);
  int64_t m = a.i % b.i;
  if (m < 0) {
    uint64_t abs_b = (b.i < 0) ? (0ULL - (uint64_t)b.i) : (uint64_t)b.i;
    m = (int64_t)((uint64_t)m + abs_b);
  }
  return aipl_int(m);
}

AiplVal aipl_array_slice(AiplVal arr_val, AiplVal start_val, AiplVal end_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_array_new(NULL, 0);
  AiplArray* a = (AiplArray*)arr_val.ptr;
  int64_t s = start_val.i; int64_t e = end_val.i;
  if (s < 0) { s += a->len; }
  if (e < 0) { e += a->len; }
  if (s < 0) { s = 0; }
  if (e > a->len) { e = a->len; }
  if (s >= e) return aipl_array_new(NULL, 0);
  return aipl_array_new(a->data + s, e - s);
}

AiplVal aipl_array_contains(AiplVal arr_val, AiplVal item) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_bool(false);
  AiplArray* a = (AiplArray*)arr_val.ptr;
  for (int64_t i = 0; i < a->len; i++) {
    if (aipl_truthy(aipl_eq(a->data[i], item))) return aipl_bool(true);
  }
  return aipl_bool(false);
}

AiplVal aipl_array_index_of(AiplVal arr_val, AiplVal item) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_int(-1);
  AiplArray* a = (AiplArray*)arr_val.ptr;
  for (int64_t i = 0; i < a->len; i++) {
    if (aipl_truthy(aipl_eq(a->data[i], item))) return aipl_int(i);
  }
  return aipl_int(-1);
}

AiplVal aipl_bytes_slice(AiplVal b_val, AiplVal start_val, AiplVal end_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_bytes_new(0);
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  int64_t s = start_val.i; int64_t e = end_val.i;
  if (s < 0) { s += b->len; }
  if (e < 0) { e += b->len; }
  if (s < 0) { s = 0; }
  if (e > b->len) { e = b->len; }
  if (s >= e) return aipl_bytes_new(0);
  int64_t n = e - s; AiplVal res = aipl_bytes_new(n); AiplBytes* rb = (AiplBytes*)res.ptr;
  memcpy(rb->data, b->data + s, n); return res;
}

AiplVal aipl_rt_readU16LE(AiplVal b, AiplVal off) { return aipl_bytes_read_u16_le(b, off); }

AiplVal aipl_rt_readU16BE(AiplVal b, AiplVal off) { return aipl_bytes_read_u16_be(b, off); }

AiplVal aipl_rt_readU32BE(AiplVal b, AiplVal off) { return aipl_bytes_read_u32_be(b, off); }

AiplVal aipl_rt_readU32LE(AiplVal b, AiplVal off) { return aipl_bytes_read_u32_le(b, off); }

AiplVal aipl_str_to_bytes(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t len = aipl_str_byte_len(s_val);
  AiplVal b_val = aipl_bytes_new(len); AiplBytes* b = (AiplBytes*)b_val.ptr;
  memcpy(b->data, s, len); return b_val;
}

AiplVal aipl_bytes_write_u8(AiplVal b_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  aipl_bytes_ensure_cap(b, 1);
  b->data[b->len++] = (uint8_t)(val.i & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u16_be(AiplVal b_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  aipl_bytes_ensure_cap(b, 2);
  uint16_t v = (uint16_t)(val.i & 0xFFFF);
  b->data[b->len++] = (uint8_t)((v >> 8) & 0xFF);
  b->data[b->len++] = (uint8_t)(v & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u16_be_at(AiplVal b_val, AiplVal off_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = off_val.i;
  if (off < 0) return b_val;
  if (off + 2 > b->len) {
    aipl_bytes_ensure_cap(b, (off + 2) - b->len);
    if (off > b->len) memset(b->data + b->len, 0, off - b->len);
    b->len = off + 2;
  }
  uint16_t v = (uint16_t)(val.i & 0xFFFF);
  b->data[off] = (uint8_t)((v >> 8) & 0xFF);
  b->data[off + 1] = (uint8_t)(v & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u16_le(AiplVal b_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  aipl_bytes_ensure_cap(b, 2);
  uint16_t v = (uint16_t)(val.i & 0xFFFF);
  b->data[b->len++] = (uint8_t)(v & 0xFF);
  b->data[b->len++] = (uint8_t)((v >> 8) & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u16_le_at(AiplVal b_val, AiplVal off_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = off_val.i;
  if (off < 0) return b_val;
  if (off + 2 > b->len) {
    aipl_bytes_ensure_cap(b, (off + 2) - b->len);
    if (off > b->len) memset(b->data + b->len, 0, off - b->len);
    b->len = off + 2;
  }
  uint16_t v = (uint16_t)(val.i & 0xFFFF);
  b->data[off] = (uint8_t)(v & 0xFF);
  b->data[off + 1] = (uint8_t)((v >> 8) & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u32_be(AiplVal b_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  aipl_bytes_ensure_cap(b, 4);
  uint32_t v = (uint32_t)(val.i & 0xFFFFFFFF);
  b->data[b->len++] = (uint8_t)((v >> 24) & 0xFF);
  b->data[b->len++] = (uint8_t)((v >> 16) & 0xFF);
  b->data[b->len++] = (uint8_t)((v >> 8) & 0xFF);
  b->data[b->len++] = (uint8_t)(v & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u32_be_at(AiplVal b_val, AiplVal off_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = off_val.i;
  if (off < 0) return b_val;
  if (off + 4 > b->len) {
    aipl_bytes_ensure_cap(b, (off + 4) - b->len);
    if (off > b->len) memset(b->data + b->len, 0, off - b->len);
    b->len = off + 4;
  }
  uint32_t v = (uint32_t)(val.i & 0xFFFFFFFF);
  b->data[off] = (uint8_t)((v >> 24) & 0xFF);
  b->data[off + 1] = (uint8_t)((v >> 16) & 0xFF);
  b->data[off + 2] = (uint8_t)((v >> 8) & 0xFF);
  b->data[off + 3] = (uint8_t)(v & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u32_le(AiplVal b_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  aipl_bytes_ensure_cap(b, 4);
  uint32_t v = (uint32_t)(val.i & 0xFFFFFFFF);
  b->data[b->len++] = (uint8_t)(v & 0xFF);
  b->data[b->len++] = (uint8_t)((v >> 8) & 0xFF);
  b->data[b->len++] = (uint8_t)((v >> 16) & 0xFF);
  b->data[b->len++] = (uint8_t)((v >> 24) & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_u32_le_at(AiplVal b_val, AiplVal off_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = off_val.i;
  if (off < 0) return b_val;
  if (off + 4 > b->len) {
    aipl_bytes_ensure_cap(b, (off + 4) - b->len);
    if (off > b->len) memset(b->data + b->len, 0, off - b->len);
    b->len = off + 4;
  }
  uint32_t v = (uint32_t)(val.i & 0xFFFFFFFF);
  b->data[off] = (uint8_t)(v & 0xFF);
  b->data[off + 1] = (uint8_t)((v >> 8) & 0xFF);
  b->data[off + 2] = (uint8_t)((v >> 16) & 0xFF);
  b->data[off + 3] = (uint8_t)((v >> 24) & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_write_string(AiplVal b_val, AiplVal s_val) {
  return aipl_bytes_write_bytes(b_val, s_val);
}

AiplVal aipl_bytes_set_byte(AiplVal b_val, AiplVal idx_val, AiplVal val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  int64_t idx = idx_val.i; if (idx < 0) return b_val;
  if (idx >= b->len) {
    aipl_bytes_ensure_cap(b, (idx + 1) - b->len);
    if (idx > b->len) memset(b->data + b->len, 0, idx - b->len);
    b->len = idx + 1;
  }
  b->data[idx] = (uint8_t)(val.i & 0xFF);
  return b_val;
}

AiplVal aipl_bytes_copy_from(AiplVal b_val, AiplVal dstOff_val, AiplVal src_val, AiplVal srcOff_val, AiplVal len_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  int64_t dstOff = dstOff_val.i; int64_t srcOff = srcOff_val.i; int64_t len = len_val.i;
  if (len <= 0 || dstOff < 0 || srcOff < 0) return b_val;
  if (src_val.kind == AIPL_BYTES && src_val.ptr) {
    AiplBytes* sb = (AiplBytes*)src_val.ptr;
    if (srcOff + len > sb->len) len = sb->len - srcOff;
    if (len <= 0) return b_val;
    if (dstOff + len > b->len) {
      aipl_bytes_ensure_cap(b, (dstOff + len) - b->len);
      if (dstOff > b->len) memset(b->data + b->len, 0, dstOff - b->len);
      b->len = dstOff + len;
    }
    memcpy(b->data + dstOff, sb->data + srcOff, len);
  }
  return b_val;
}

AiplVal aipl_bytes_to_array(AiplVal b_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_array_new(NULL, 0);
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  AiplVal* items = (AiplVal*)malloc(sizeof(AiplVal) * (b->len > 0 ? b->len : 1));
  for (int64_t i = 0; i < b->len; i++) items[i] = aipl_int((int64_t)b->data[i]);
  AiplVal res = aipl_array_new(items, b->len);
  free(items); return res;
}

// --- Low-Level Pointer & Syscall Intrinsics (Step 14.2a & 14.3a) ---
AiplVal aipl_rt_ptrAlloc(AiplVal size) {
  int64_t sz = (size.kind == AIPL_INT) ? size.i : (int64_t)size.f;
  if (sz <= 0) sz = 1;
  void* p = calloc(1, (size_t)sz);
  return aipl_int((int64_t)(intptr_t)p);
}

AiplVal aipl_rt_ptrFree(AiplVal ptr) {
  int64_t addr = (ptr.kind == AIPL_INT) ? ptr.i : 0;
  if (addr != 0) free((void*)(intptr_t)addr);
  return aipl_nil();
}

AiplVal aipl_rt_ptrReadU8(AiplVal ptr, AiplVal offset) {
  uint8_t* p = (uint8_t*)(intptr_t)ptr.i;
  int64_t off = (offset.kind == AIPL_INT) ? offset.i : 0;
  return aipl_int(p ? (int64_t)p[off] : 0);
}

AiplVal aipl_rt_ptrWriteU8(AiplVal ptr, AiplVal offset, AiplVal val) {
  uint8_t* p = (uint8_t*)(intptr_t)ptr.i;
  int64_t off = (offset.kind == AIPL_INT) ? offset.i : 0;
  int64_t v = (val.kind == AIPL_INT) ? val.i : 0;
  if (p) p[off] = (uint8_t)v;
  return aipl_nil();
}

AiplVal aipl_rt_ptrReadI64(AiplVal ptr, AiplVal offset) {
  int64_t off = (offset.kind == AIPL_INT) ? offset.i : 0;
  int64_t* p = (int64_t*)((uint8_t*)(intptr_t)ptr.i + off);
  return aipl_int(p ? *p : 0);
}

AiplVal aipl_rt_ptrWriteI64(AiplVal ptr, AiplVal offset, AiplVal val) {
  int64_t off = (offset.kind == AIPL_INT) ? offset.i : 0;
  int64_t v = (val.kind == AIPL_INT) ? val.i : (int64_t)val.f;
  int64_t* p = (int64_t*)((uint8_t*)(intptr_t)ptr.i + off);
  if (p) *p = v;
  return aipl_nil();
}

AiplVal aipl_rt_sizeofType(AiplVal typeName) {
  const char* tn = (typeName.kind == AIPL_STR && typeName.s) ? typeName.s : "";
  if (strcmp(tn, "u8") == 0 || strcmp(tn, "i8") == 0 || strcmp(tn, "bool") == 0) return aipl_int(1);
  if (strcmp(tn, "u16") == 0 || strcmp(tn, "i16") == 0) return aipl_int(2);
  if (strcmp(tn, "u32") == 0 || strcmp(tn, "i32") == 0 || strcmp(tn, "f32") == 0) return aipl_int(4);
  return aipl_int(8);
}

AiplVal aipl_rt_bitcastF64ToI64(AiplVal fval) {
  union { double d; int64_t i; } u;
  u.d = (fval.kind == AIPL_FLOAT ? fval.f : (double)fval.i);
  return aipl_int(u.i);
}

AiplVal aipl_rt_bitcastI64ToF64(AiplVal ival) {
  union { double d; int64_t i; } u;
  u.i = (ival.kind == AIPL_INT ? ival.i : (int64_t)ival.f);
  return aipl_float(u.d);
}

AiplVal aipl_rt_rawSyscall0(AiplVal nr) { return aipl_rt_rawSyscall(nr, aipl_int(0), aipl_int(0), aipl_int(0), aipl_int(0), aipl_int(0), aipl_int(0)); }

AiplVal aipl_rt_rawSyscall1(AiplVal nr, AiplVal a1) { return aipl_rt_rawSyscall(nr, a1, aipl_int(0), aipl_int(0), aipl_int(0), aipl_int(0), aipl_int(0)); }

AiplVal aipl_rt_rawSyscall2(AiplVal nr, AiplVal a1, AiplVal a2) { return aipl_rt_rawSyscall(nr, a1, a2, aipl_int(0), aipl_int(0), aipl_int(0), aipl_int(0)); }

AiplVal aipl_rt_rawSyscall3(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3) { return aipl_rt_rawSyscall(nr, a1, a2, a3, aipl_int(0), aipl_int(0), aipl_int(0)); }

AiplVal aipl_rt_rawSyscall4(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4) { return aipl_rt_rawSyscall(nr, a1, a2, a3, a4, aipl_int(0), aipl_int(0)); }

AiplVal aipl_rt_rawSyscall5(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4, AiplVal a5) { return aipl_rt_rawSyscall(nr, a1, a2, a3, a4, a5, aipl_int(0)); }

AiplVal aipl_rt_rawSyscall6(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4, AiplVal a5, AiplVal a6) { return aipl_rt_rawSyscall(nr, a1, a2, a3, a4, a5, a6); }

AiplVal aipl_bytes_index_of_byte(AiplVal b_val, AiplVal val, AiplVal fromIdx_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_int(-1);
  AiplBytes* b = (AiplBytes*)b_val.ptr; uint8_t target = (uint8_t)(val.i & 0xFF);
  int64_t start = fromIdx_val.i < 0 ? 0 : fromIdx_val.i;
  for (int64_t i = start; i < b->len; i++) { if (b->data[i] == target) return aipl_int(i); }
  return aipl_int(-1);
}

AiplVal aipl_bytes_index_of_bytes(AiplVal b_val, AiplVal needle_val, AiplVal fromIdx_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_int(-1);
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  const uint8_t* n_data = NULL; int64_t n_len = 0;
  if (needle_val.kind == AIPL_BYTES && needle_val.ptr) {
    n_data = ((AiplBytes*)needle_val.ptr)->data; n_len = ((AiplBytes*)needle_val.ptr)->len;
  } else if (needle_val.kind == AIPL_STR && needle_val.s) {
    n_data = (const uint8_t*)needle_val.s; n_len = (int64_t)strlen(needle_val.s);
  }
  if (!n_data || n_len == 0) return aipl_int(0);
  int64_t start = fromIdx_val.i < 0 ? 0 : fromIdx_val.i;
  if (start + n_len > b->len) return aipl_int(-1);
  for (int64_t i = start; i <= b->len - n_len; i++) {
    if (memcmp(b->data + i, n_data, n_len) == 0) return aipl_int(i);
  }
  return aipl_int(-1);
}

AiplVal aipl_bytes_split_byte(AiplVal b_val, AiplVal delim_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_array_new(NULL, 0);
  AiplBytes* b = (AiplBytes*)b_val.ptr; uint8_t d = (uint8_t)(delim_val.i & 0xFF);
  int64_t count = 0;
  for (int64_t i = 0; i < b->len; i++) { if (b->data[i] == d) count++; }
  AiplVal* parts = (AiplVal*)malloc(sizeof(AiplVal) * (count + 1));
  int64_t start = 0, pidx = 0;
  for (int64_t i = 0; i <= b->len; i++) {
    if (i == b->len || b->data[i] == d) {
      int64_t part_len = i - start;
      AiplVal pv = aipl_bytes_new(part_len); AiplBytes* pb = (AiplBytes*)pv.ptr;
      if (part_len > 0) memcpy(pb->data, b->data + start, part_len);
      parts[pidx++] = pv; start = i + 1;
    }
  }
  AiplVal res = aipl_array_new(parts, pidx); free(parts); return res;
}

bool aipl_is_valid_utf8(const uint8_t* data, int64_t len) {
  int64_t i = 0;
  while (i < len) {
    uint8_t c = data[i];
    if (c <= 0x7F) { i += 1; }
    else if ((c & 0xE0) == 0xC0) {
      if (i + 1 >= len || (data[i + 1] & 0xC0) != 0x80) return false;
      i += 2;
    } else if ((c & 0xF0) == 0xE0) {
      if (i + 2 >= len || (data[i + 1] & 0xC0) != 0x80 || (data[i + 2] & 0xC0) != 0x80) return false;
      i += 3;
    } else if ((c & 0xF8) == 0xF0) {
      if (i + 3 >= len || (data[i + 1] & 0xC0) != 0x80 || (data[i + 2] & 0xC0) != 0x80 || (data[i + 3] & 0xC0) != 0x80) return false;
      i += 4;
    } else { return false; }
  }
  return true;
}

AiplVal aipl_bytes_to_utf8_res(AiplVal b_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_ok(aipl_str(""));
  AiplBytes* b = (AiplBytes*)b_val.ptr; if (b->len == 0) return aipl_ok(aipl_str(""));
  if (!aipl_is_valid_utf8(b->data, b->len)) return aipl_err(aipl_str("invalid utf-8 sequence"));
  return aipl_ok(aipl_str_n((const char*)b->data, b->len));
}

void aipl_map_rh_insert(AiplMap* m, uint32_t tag, int32_t dense_idx) {
  int64_t mask = m->hash_cap - 1;
  int64_t slot = (int64_t)(tag & mask);
  int64_t cur_dist = 0;
  uint32_t cur_tag = tag;
  int32_t cur_slot_idx = dense_idx;
  while (true) {
    if (m->hash_tags[slot] == 0) {
      m->hash_tags[slot] = cur_tag;
      m->hash_slots[slot] = cur_slot_idx;
      return;
    }
    int64_t occ_dist = (slot + m->hash_cap - (m->hash_tags[slot] & mask)) & mask;
    if (cur_dist > occ_dist) {
      uint32_t tmp_tag = m->hash_tags[slot];
      int32_t tmp_idx = m->hash_slots[slot];
      m->hash_tags[slot] = cur_tag;
      m->hash_slots[slot] = cur_slot_idx;
      cur_tag = tmp_tag;
      cur_slot_idx = tmp_idx;
      cur_dist = occ_dist;
    }
    slot = (slot + 1) & mask;
    cur_dist++;
  }
}

AiplVal aipl_map_get_raw(AiplVal map_val, const char* key) {
  if (!key) key = "";
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return aipl_nil();
  AiplMap* m = (AiplMap*)map_val.ptr;
  uint32_t tag = aipl_fnv1a_hash32(key);
  int32_t idx = aipl_map_find_slot(m, key, tag);
  if (idx >= 0) return m->vals[idx];
  return aipl_nil();
}

AiplVal aipl_map_has(AiplVal map_val, const char* key) {
  if (!key) key = "";
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return aipl_bool(false);
  AiplMap* m = (AiplMap*)map_val.ptr;
  uint32_t tag = aipl_fnv1a_hash32(key);
  return aipl_bool(aipl_map_find_slot(m, key, tag) >= 0);
}

AiplVal aipl_map_remove(AiplVal map_val, const char* key) {
  if (!key) key = "";
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return aipl_none();
  AiplMap* m = (AiplMap*)map_val.ptr;
  uint32_t tag = aipl_fnv1a_hash32(key);
  int32_t idx = aipl_map_find_slot(m, key, tag);
  if (idx < 0) return aipl_none();
  AiplVal old_val = m->vals[idx];
  if (m->keys[idx]) {
    extern AiplArenaPage* _aipl_arena_head;
    bool in_arena = false;
    const uint8_t* kp = (const uint8_t*)m->keys[idx];
    for (AiplArenaPage* pg = _aipl_arena_head; pg; pg = pg->next) {
      if (pg->buf && kp >= pg->buf && kp < pg->buf + pg->cap) { in_arena = true; break; }
    }
    if (!in_arena) free((void*)m->keys[idx]);
  }
  for (int64_t i = idx; i < m->len - 1; i++) {
    m->keys[i] = m->keys[i + 1];
    m->vals[i] = m->vals[i + 1];
  }
  m->len--;
  aipl_map_rehash(m, m->hash_cap);
  return aipl_some(old_val);
}

AiplArenaPage* _aipl_arena_head = NULL;
AiplArenaPage* _aipl_arena_cur_page = NULL;
AiplArenaPage* _aipl_arena_free_pages = NULL;
int64_t _aipl_arena_free_count = 0;
AiplArenaPage* _aipl_arena_free_checkpoints = NULL;
int64_t _aipl_arena_free_checkpoint_count = 0;
int64_t _aipl_arena_depth = 0;
AiplArenaPage* aipl_current_arena = NULL;
int64_t _aipl_arena_peak = 0;
int64_t _aipl_arena_resets = 0;
int64_t _aipl_arena_reused_bytes = 0;
int64_t _aipl_prof_total_allocs = 0;
int64_t _aipl_prof_total_bytes = 0;
void* aipl_arena_alloc_raw(int64_t sz) {
  int64_t aligned_sz = (sz + 7) & ~7;
  if (aligned_sz <= 0) aligned_sz = 8;
  _aipl_prof_total_allocs++;
  _aipl_prof_total_bytes += aligned_sz;
  if (!_aipl_arena_head) {
    int64_t first_cap = aligned_sz > 16777216 ? aligned_sz * 2 : 16777216;
    _aipl_arena_head = (AiplArenaPage*)calloc(1, sizeof(AiplArenaPage));
    _aipl_arena_head->buf = (uint8_t*)malloc((size_t)first_cap);
    _aipl_arena_head->cap = first_cap;
    _aipl_arena_head->offset = 0;
    _aipl_arena_head->base_offset = 0;
    _aipl_arena_head->next = NULL;
    _aipl_arena_cur_page = _aipl_arena_head;
  }
  if (_aipl_arena_cur_page->offset + aligned_sz > _aipl_arena_cur_page->cap) {
    if (_aipl_arena_cur_page->next && _aipl_arena_cur_page->next->cap >= aligned_sz) {
      AiplArenaPage* nxt = _aipl_arena_cur_page->next;
      nxt->offset = 0;
      nxt->base_offset = _aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset;
      _aipl_arena_cur_page = nxt;
    } else {
      AiplArenaPage* new_page = NULL;
      if (_aipl_arena_free_pages && _aipl_arena_free_pages->cap >= aligned_sz) {
        new_page = _aipl_arena_free_pages;
        _aipl_arena_free_pages = _aipl_arena_free_pages->next;
        _aipl_arena_free_count--;
      } else {
        int64_t new_cap = aligned_sz > 16777216 ? aligned_sz * 2 : 16777216;
        new_page = (AiplArenaPage*)calloc(1, sizeof(AiplArenaPage));
        new_page->buf = (uint8_t*)malloc((size_t)new_cap);
        new_page->cap = new_cap;
      }
      new_page->offset = 0;
      new_page->base_offset = _aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset;
      new_page->next = _aipl_arena_cur_page->next;
      _aipl_arena_cur_page->next = new_page;
      _aipl_arena_cur_page = new_page;
    }
  }
  int64_t old_off = _aipl_arena_cur_page->offset;
  _aipl_arena_cur_page->offset += aligned_sz;
  int64_t total_alloc = _aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset;
  if (total_alloc > _aipl_arena_peak) _aipl_arena_peak = total_alloc;
  return (void*)(_aipl_arena_cur_page->buf + old_off);
}

void* aipl_arena_alloc_temp(size_t sz) {
  return aipl_arena_alloc_raw((int64_t)sz);
}

char* aipl_arena_strdup_temp(const char* s) {
  if (!s) return NULL;
  size_t len = strlen(s);
  char* p = (char*)aipl_arena_alloc_raw((int64_t)(len + 1));
  if (p) { memcpy(p, s, len + 1); }
  return p;
}

void* aipl_rt_arenaAllocBytes(int64_t sz) {
  return aipl_arena_alloc_raw(sz);
}

AiplArenaPage* aipl_arena_push(void) {
  _aipl_arena_depth++;
  if (!_aipl_arena_head) {
    aipl_arena_alloc_raw(8);
  }
  aipl_current_arena = _aipl_arena_cur_page;
  AiplArenaPage* cp = NULL;
  if (_aipl_arena_free_checkpoints) {
    cp = _aipl_arena_free_checkpoints;
    _aipl_arena_free_checkpoints = _aipl_arena_free_checkpoints->next;
    _aipl_arena_free_checkpoint_count--;
  } else {
    cp = (AiplArenaPage*)calloc(1, sizeof(AiplArenaPage));
  }
  cp->buf = (uint8_t*)_aipl_arena_cur_page;
  cp->offset = _aipl_arena_cur_page ? _aipl_arena_cur_page->offset : 0;
  cp->base_offset = _aipl_arena_cur_page ? _aipl_arena_cur_page->base_offset : 0;
  cp->cap = 0;
  cp->next = NULL;
  return cp;
}

void aipl_arena_pop(AiplArenaPage* saved) {
  int64_t before_off = _aipl_arena_cur_page ? (_aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset) : 0;
  if (_aipl_arena_depth > 0) _aipl_arena_depth--;
  _aipl_arena_resets++;
  if (saved) {
    AiplArenaPage* target_page = (AiplArenaPage*)saved->buf;
    if (target_page) {
      int64_t after_off = target_page->base_offset + saved->offset;
      if (before_off > after_off) _aipl_arena_reused_bytes += (before_off - after_off);
      target_page->offset = saved->offset;
      _aipl_arena_cur_page = target_page;
      AiplArenaPage* p = target_page->next;
      while (p) {
        p->offset = 0;
        p->base_offset = -1;
        p = p->next;
      }
    }
    if (_aipl_arena_free_checkpoint_count < 64) {
      saved->buf = NULL;
      saved->offset = 0;
      saved->next = _aipl_arena_free_checkpoints;
      _aipl_arena_free_checkpoints = saved;
      _aipl_arena_free_checkpoint_count++;
    } else {
      free(saved);
    }
  }
  aipl_current_arena = (_aipl_arena_depth > 0) ? _aipl_arena_cur_page : NULL;
}

bool aipl_ptr_in_arena_frame(AiplArenaPage* saved, const void* ptr) {
  if (!ptr) return false;
  const uint8_t* p = (const uint8_t*)ptr;
  if (saved && saved->buf) {
    AiplArenaPage* target_page = (AiplArenaPage*)saved->buf;
    if (target_page->buf && p >= target_page->buf + saved->offset && p < target_page->buf + target_page->cap) {
      return true;
    }
    AiplArenaPage* page = target_page->next;
    while (page) {
      if (page->buf && p >= page->buf && p < page->buf + page->cap) return true;
      page = page->next;
    }
    return false;
  }
  AiplArenaPage* page = _aipl_arena_head;
  while (page) {
    if (page->buf && p >= page->buf && p < page->buf + page->cap) return true;
    page = page->next;
  }
  return false;
}

static AiplVal aipl_evacuate_val_inner(AiplArenaPage* saved, AiplVal v) {
  switch (v.kind) {
    case AIPL_STR: {
      if (v.s && aipl_ptr_in_arena_frame(saved, v.s)) {
        size_t len = aipl_str_byte_len(v);
        char* copy = (char*)malloc(len + 1);
        memcpy(copy, v.s, len);
        copy[len] = 0;
        v.s = copy;
      }
      return v;
    }
    case AIPL_BYTES: {
      if (v.ptr) {
        AiplBytes* b = (AiplBytes*)v.ptr;
        if (aipl_ptr_in_arena_frame(saved, b) || aipl_ptr_in_arena_frame(saved, b->data)) {
          AiplVal nb = aipl_bytes_new(b->len);
          if (b->len > 0 && b->data) {
            memcpy(((AiplBytes*)nb.ptr)->data, b->data, (size_t)b->len);
          }
          return nb;
        }
      }
      return v;
    }
    case AIPL_ARRAY: {
      if (v.ptr) {
        AiplArray* a = (AiplArray*)v.ptr;
        for (int64_t i = 0; i < a->len; i++) {
          a->data[i] = aipl_evacuate_val_inner(saved, a->data[i]);
        }
        if (aipl_ptr_in_arena_frame(saved, a) || aipl_ptr_in_arena_frame(saved, a->data)) {
          return aipl_array_new(a->data, a->len);
        }
      }
      return v;
    }
    case AIPL_STRUCT: {
      if (v.ptr) {
        AiplStruct* st = (AiplStruct*)v.ptr;
        for (int64_t i = 0; i < st->len; i++) {
          if (st->names && st->names[i] && aipl_ptr_in_arena_frame(saved, st->names[i])) {
            st->names[i] = strdup(st->names[i]);
          }
          if (st->vals) {
            st->vals[i] = aipl_evacuate_val_inner(saved, st->vals[i]);
          }
        }
        const char* tname = (st->type_name && aipl_ptr_in_arena_frame(saved, st->type_name)) ? strdup(st->type_name) : st->type_name;
        st->type_name = tname;
        if (aipl_ptr_in_arena_frame(saved, st) || aipl_ptr_in_arena_frame(saved, st->vals) || aipl_ptr_in_arena_frame(saved, st->names)) {
          int64_t ex = st->extra_i;
          AiplVal nv = aipl_struct_new(tname, st->len, st->names, st->vals);
          ((AiplStruct*)nv.ptr)->extra_i = ex;
          nv.extra_i = (int32_t)ex;
          return nv;
        }
      }
      return v;
    }
    case AIPL_MAP: {
      if (v.ptr) {
        AiplMap* m = (AiplMap*)v.ptr;
        bool map_in_frame = aipl_ptr_in_arena_frame(saved, m) || aipl_ptr_in_arena_frame(saved, m->keys) || aipl_ptr_in_arena_frame(saved, m->vals);
        for (int64_t i = 0; i < m->len; i++) {
          if (!map_in_frame && m->keys[i] && aipl_ptr_in_arena_frame(saved, m->keys[i])) {
            m->keys[i] = strdup(m->keys[i]);
          }
          m->vals[i] = aipl_evacuate_val_inner(saved, m->vals[i]);
        }
        if (map_in_frame) {
          AiplVal nm = aipl_map_new();
          for (int64_t i = 0; i < m->len; i++) {
            aipl_map_set(nm, aipl_str_lit(m->keys[i] ? m->keys[i] : ""), m->vals[i]);
          }
          return nm;
        }
      }
      return v;
    }
    case AIPL_OPT_SOME:
    case AIPL_RES_OK:
    case AIPL_RES_ERR: {
      if (v.ptr) {
        AiplVal inner = aipl_evacuate_val_inner(saved, *(AiplVal*)v.ptr);
        if (aipl_ptr_in_arena_frame(saved, v.ptr)) {
          AiplVal* np = (AiplVal*)malloc(sizeof(AiplVal));
          *np = inner;
          v.ptr = np;
        } else {
          *(AiplVal*)v.ptr = inner;
        }
      }
      return v;
    }
    default:
      return v;
  }
}

AiplVal aipl_evacuate_val(AiplArenaPage* saved, AiplVal v) {
  int64_t old_depth = _aipl_arena_depth;
  _aipl_arena_depth = 0;
  AiplVal out = aipl_evacuate_val_inner(saved, v);
  _aipl_arena_depth = old_depth;
  return out;
}

AiplVal aipl_arena_pop_evacuate(AiplArenaPage* saved, AiplVal ret) {
  AiplVal ev = aipl_evacuate_val(saved, ret);
  aipl_arena_pop(saved);
  return ev;
}

AiplVal aipl_rt_arenaPopEvacuate(AiplVal mark_val, AiplVal ret) {
  int64_t target = mark_val.i >= 0 ? mark_val.i : 0;
  AiplArenaPage dummy_cp;
  memset(&dummy_cp, 0, sizeof(dummy_cp));
  AiplArenaPage* p = _aipl_arena_head;
  while (p) {
    if (target >= p->base_offset && (p->next == NULL || p->next->base_offset < 0 || target < p->base_offset + p->cap)) {
      dummy_cp.buf = (uint8_t*)p;
      dummy_cp.offset = target - p->base_offset;
      dummy_cp.base_offset = p->base_offset;
      break;
    }
    p = p->next;
  }
  AiplVal ev = aipl_evacuate_val(&dummy_cp, ret);
  aipl_arena_reset(mark_val);
  return ev;
}

void aipl_print_profile_report(void) {
  fprintf(stderr, "[AIPL Profile] total_allocs=%lld total_bytes=%lld arena_peak_bytes=%lld arena_resets=%lld arena_reused_bytes=%lld\n",
    (long long)_aipl_prof_total_allocs,
    (long long)_aipl_prof_total_bytes,
    (long long)_aipl_arena_peak,
    (long long)_aipl_arena_resets,
    (long long)_aipl_arena_reused_bytes);
}

#if defined(__GNUC__) || defined(__clang__)
__attribute__((destructor))
static void _aipl_prof_atexit_hook(void) {
  const char* prof = getenv("AIPL_PROFILE");
  if (prof && strcmp(prof, "1") == 0) {
    aipl_print_profile_report();
  }
}
#endif

AiplVal aipl_arena_allocated_bytes(void) {
  int64_t cur = _aipl_arena_cur_page ? _aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset : 0;
  return aipl_int(cur);
}

AiplVal aipl_arena_alloc(AiplVal sz) {
  aipl_arena_alloc_raw(sz.i > 0 ? sz.i : 8);
  int64_t cur = _aipl_arena_cur_page ? _aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset : 0;
  return aipl_int(cur);
}

AiplVal aipl_arena_stats(void) {
  int64_t total_cap = 0;
  AiplArenaPage* cp = _aipl_arena_head;
  while (cp) { total_cap += cp->cap; cp = cp->next; }
  int64_t cur = _aipl_arena_cur_page ? _aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset : 0;
  AiplVal m = aipl_map_new();
  aipl_map_set(m, aipl_str("allocated"), aipl_int(cur));
  aipl_map_set(m, aipl_str("capacity"), aipl_int(total_cap > 0 ? total_cap : 16777216));
  aipl_map_set(m, aipl_str("peak"), aipl_int(_aipl_arena_peak));
  aipl_map_set(m, aipl_str("resets"), aipl_int(_aipl_arena_resets));
  aipl_map_set(m, aipl_str("reused_bytes"), aipl_int(_aipl_arena_reused_bytes));
  aipl_map_set(m, aipl_str("total_allocs"), aipl_int(_aipl_prof_total_allocs));
  aipl_map_set(m, aipl_str("total_bytes"), aipl_int(_aipl_prof_total_bytes));
  return m;
}

// Packed RGBA colors (extra_i == 'COLR') expose std/canvas `Color` semantics: channels are
// normalized floats in [0, 1] (TS backend parity). Writes accept normalized floats or 0..255 ints.
void aipl_array_member_op_set(AiplVal arr, AiplVal idx, const char* field, AiplVal rhs, int op) {
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    int64_t i = (idx.kind == AIPL_INT) ? idx.i : (int64_t)idx.f;
    if (i < 0 || i >= a->len) return;
    AiplVal* slot = &a->data[i];
    if (slot->extra_i == 0x434F4C52 && aipl_color_channel_shift(field) >= 0) {
      int sh = aipl_color_channel_shift(field);
      AiplVal cur = aipl_color_channel_get(*slot, sh);
      AiplVal nextVal = (op == 0) ? rhs : (op == 1 ? aipl_add(cur, rhs) : (op == 2 ? aipl_sub(cur, rhs) : (op == 3 ? aipl_mul(cur, rhs) : (op == 4 ? aipl_div(cur, rhs) : (op == 5 ? aipl_mod(cur, rhs) : rhs)))));
      aipl_color_channel_set(slot, sh, nextVal);
      a->data[i] = *slot;
      return;
    }
    if (slot->kind == AIPL_STRUCT && slot->ptr) {
      AiplStruct* st = (AiplStruct*)slot->ptr;
      char c0 = (field && field[0]) ? field[0] : 0;
      int64_t found = -1;
      for (int64_t fi = 0; fi < st->len; fi++) {
        const char* fn = st->names[fi];
        if (fn && (fn == field || (fn[0] == c0 && strcmp(fn, field) == 0))) { found = fi; break; }
      }
      if (found >= 0) {
        AiplVal cur = st->vals[found];
        AiplVal nextVal = (op == 0) ? rhs : (op == 1 ? aipl_add(cur, rhs) : (op == 2 ? aipl_sub(cur, rhs) : (op == 3 ? aipl_mul(cur, rhs) : (op == 4 ? aipl_div(cur, rhs) : (op == 5 ? aipl_mod(cur, rhs) : rhs)))));
        st->vals[found] = nextVal;
      } else {
        aipl_member_set_val(*slot, field, rhs);
      }
      a->data[i] = *slot;
      return;
    }
    AiplVal cur = aipl_member_get(*slot, field);
    AiplVal nextVal = (op == 0) ? rhs : (op == 1 ? aipl_add(cur, rhs) : (op == 2 ? aipl_sub(cur, rhs) : (op == 3 ? aipl_mul(cur, rhs) : (op == 4 ? aipl_div(cur, rhs) : (op == 5 ? aipl_mod(cur, rhs) : rhs)))));
    aipl_member_set_val(*slot, field, nextVal);
    a->data[i] = *slot;
    return;
  }
  if (arr.kind == AIPL_MAP && arr.ptr) {
    const char* k = aipl_to_cstr(idx);
    AiplVal cur_opt = aipl_map_get(arr, k);
    AiplVal cur_elem = (cur_opt.kind == AIPL_OPT_SOME && cur_opt.ptr) ? *(AiplVal*)cur_opt.ptr : cur_opt;
    AiplVal cur_field = aipl_member_get(cur_elem, field);
    AiplVal nextVal = (op == 0) ? rhs : (op == 1 ? aipl_add(cur_field, rhs) : (op == 2 ? aipl_sub(cur_field, rhs) : (op == 3 ? aipl_mul(cur_field, rhs) : (op == 4 ? aipl_div(cur_field, rhs) : (op == 5 ? aipl_mod(cur_field, rhs) : rhs)))));
    aipl_member_set_val(cur_elem, field, nextVal);
    aipl_map_set(arr, idx, cur_elem);
    return;
  }
}

AiplVal aipl_rt_cloneStruct(AiplVal s) {
  if (s.kind == AIPL_STRUCT && s.ptr) {
    AiplStruct* b = (AiplStruct*)s.ptr;
    const char** out_names = b->len > 0 ? (const char**)malloc(sizeof(const char*) * (size_t)b->len) : NULL;
    AiplVal* out_vals = b->len > 0 ? (AiplVal*)malloc(sizeof(AiplVal) * (size_t)b->len) : NULL;
    for (int64_t i = 0; i < b->len; i++) {
      out_names[i] = b->names[i];
      out_vals[i] = (b->vals[i].kind == AIPL_STRUCT || b->vals[i].kind == AIPL_ARRAY) ? aipl_rt_cloneStruct(b->vals[i]) : b->vals[i];
    }
    AiplVal res = aipl_struct_new(b->type_name, b->len, out_names, out_vals);
    if (out_names) free(out_names);
    if (out_vals) free(out_vals);
    return res;
  }
  if (s.kind == AIPL_ARRAY && s.ptr) {
    AiplArray* a = (AiplArray*)s.ptr;
    AiplVal* items = a->len > 0 ? (AiplVal*)malloc(sizeof(AiplVal) * (size_t)a->len) : NULL;
    for (int64_t i = 0; i < a->len; i++) {
      items[i] = (a->data[i].kind == AIPL_STRUCT || a->data[i].kind == AIPL_ARRAY) ? aipl_rt_cloneStruct(a->data[i]) : a->data[i];
    }
    AiplVal res = aipl_array_new(items, a->len);
    if (items) free(items);
    return res;
  }
  return s;
}

AiplVal aipl_struct_spread(AiplVal base, const char* type_name, int64_t count, const char** names, const AiplVal* vals) {
  const char* tname = (type_name && strlen(type_name) > 0) ? type_name : ((base.kind == AIPL_STRUCT && base.ptr) ? ((AiplStruct*)base.ptr)->type_name : "");
  int64_t base_len = (base.kind == AIPL_STRUCT && base.ptr) ? ((AiplStruct*)base.ptr)->len : ((base.kind == AIPL_MAP && base.ptr) ? ((AiplMap*)base.ptr)->len : 0);
  AiplStruct* b = (base.kind == AIPL_STRUCT && base.ptr) ? (AiplStruct*)base.ptr : NULL;
  int64_t max_len = base_len + count;
  const char** out_names = max_len > 0 ? (const char**)malloc(sizeof(const char*) * max_len) : NULL;
  AiplVal* out_vals = max_len > 0 ? (AiplVal*)malloc(sizeof(AiplVal) * max_len) : NULL;
  int64_t out_len = 0;
  if (b) {
    for (int64_t i = 0; i < b->len; i++) {
      out_names[out_len] = b->names[i];
      out_vals[out_len] = (b->vals[i].kind == AIPL_STRUCT) ? aipl_rt_cloneStruct(b->vals[i]) : b->vals[i];
      out_len++;
    }
  } else if (base.kind == AIPL_MAP && base.ptr) {
    AiplMap* bm = (AiplMap*)base.ptr;
    for (int64_t i = 0; i < bm->len; i++) {
      out_names[out_len] = bm->keys[i];
      out_vals[out_len] = (bm->vals[i].kind == AIPL_STRUCT) ? aipl_rt_cloneStruct(bm->vals[i]) : bm->vals[i];
      out_len++;
    }
  }
  for (int64_t j = 0; j < count; j++) {
    const char* fn = names ? names[j] : "";
    AiplVal fv = vals ? vals[j] : aipl_nil();
    int64_t found = -1;
    for (int64_t k = 0; k < out_len; k++) {
      if (out_names[k] && strcmp(out_names[k], fn) == 0) { found = k; break; }
    }
    if (found >= 0) { out_vals[found] = fv; }
    else { out_names[out_len] = fn; out_vals[out_len] = fv; out_len++; }
  }
  AiplVal res = aipl_struct_new(tname, out_len, out_names, out_vals);
  if (out_names) free(out_names);
  if (out_vals) free(out_vals);
  return res;
}

AiplVal aipl_vec_repeat(AiplVal val, AiplVal count) {
  int64_t n = count.i;
  if (n <= 0) return aipl_array_new(NULL, 0);
  AiplVal* items = (AiplVal*)malloc(sizeof(AiplVal) * (n > 0 ? n : 1));
  for (int64_t i = 0; i < n; i++) items[i] = val;
  AiplVal res = aipl_array_new(items, n); free(items); return res;
}

AiplVal aipl_str_slice(AiplVal s_val, AiplVal start_val, AiplVal end_val) {
  const char* s = (s_val.kind == AIPL_STR && s_val.s) ? s_val.s : ""; int64_t len = (int64_t)aipl_str_byte_len(s_val);
  int64_t start = (start_val.kind == AIPL_INT) ? start_val.i : (int64_t)start_val.f;
  int64_t end = (end_val.kind == AIPL_INT) ? end_val.i : (int64_t)end_val.f;
  if (start < 0) { start += len; }
  if (end < 0) { end += len; }
  if (start < 0) { start = 0; }
  if (end > len) { end = len; }
  if (start >= end) return aipl_str_lit("");
  int64_t n = end - start;
  char* buf;
  if (_aipl_arena_depth > 0) {
    buf = (char*)aipl_arena_alloc_raw(n + 1);
  } else {
    aipl_prof_record_alloc((size_t)n + 1);
    buf = (char*)malloc((size_t)n + 1);
  }
  memcpy(buf, s + start, (size_t)n); buf[n] = 0;
  AiplVal v; memset(&v, 0, sizeof(v));
  v.kind = AIPL_STR; v.s = buf; v.extra_i = (n > 0) ? (int)n : -1;
  return v;
}

AiplVal aipl_rt_eachLine(AiplVal text_or_path, AiplVal cb) {
  AiplVal txt = aipl_rt_fileExists(text_or_path).b ? aipl_rt_readFile(text_or_path) : text_or_path;
  AiplVal lines = aipl_str_lines(txt);
  if (cb.kind == AIPL_NIL) return lines;
  int64_t n = aipl_member_len(lines).i;
  if (cb.kind == AIPL_FUNC && cb.ptr) {
    AiplFnPtr fn = (AiplFnPtr)cb.ptr;
    for (int64_t i = 0; i < n; i++) {
      AiplVal ln = aipl_index_get(lines, aipl_int(i));
      (void)fn(1, &ln);
    }
  }
  return aipl_int(n);
}

AiplVal aipl_str_bytes(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : "";
  size_t len = strlen(s);
  AiplVal* vals = (AiplVal*)malloc(sizeof(AiplVal) * (len > 0 ? len : 1));
  for (size_t i = 0; i < len; i++) { vals[i] = aipl_int((int64_t)(uint8_t)s[i]); }
  AiplVal res = aipl_array_new(vals, (int64_t)len); free(vals); return res;
}

AiplVal aipl_str_words(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; int64_t cap = 16;
  AiplVal* words = (AiplVal*)malloc(sizeof(AiplVal) * cap);
  int64_t count = 0; size_t i = 0; size_t len = strlen(s);
  while (i < len) {
    while (i < len && isspace((unsigned char)s[i])) i++;
    if (i >= len) break;
    size_t start = i;
    while (i < len && !isspace((unsigned char)s[i])) i++;
    if (count >= cap) { cap *= 2; words = (AiplVal*)realloc(words, sizeof(AiplVal) * cap); }
    words[count++] = aipl_str_n(s + start, (int64_t)(i - start));
  }
  AiplVal res = aipl_array_new(words, count); free(words); return res;
}

AiplVal aipl_str_skip_fields(AiplVal s_val, AiplVal n_val) {
  const char* s = s_val.s ? s_val.s : ""; int64_t n = n_val.i;
  size_t i = 0; size_t len = strlen(s);
  while (i < len && isspace((unsigned char)s[i])) i++;
  for (int64_t f = 0; f < n && i < len; f++) {
    while (i < len && !isspace((unsigned char)s[i])) i++;
    while (i < len && isspace((unsigned char)s[i])) i++;
  }
  return aipl_str(s + i);
}

AiplVal aipl_str_split_any(AiplVal s_val, AiplVal delims_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* d = delims_val.s ? delims_val.s : "";
  int64_t cap = 16; AiplVal* parts = (AiplVal*)malloc(sizeof(AiplVal) * cap);
  int64_t count = 0; size_t start = 0; size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) {
    if (strchr(d, s[i])) {
      if (count >= cap) { cap *= 2; parts = (AiplVal*)realloc(parts, sizeof(AiplVal) * cap); }
      parts[count++] = aipl_str_n(s + start, (int64_t)(i - start));
      start = i + 1;
    }
  }
  if (count >= cap) { cap += 1; parts = (AiplVal*)realloc(parts, sizeof(AiplVal) * cap); }
  parts[count++] = aipl_str_n(s + start, (int64_t)(len - start));
  AiplVal res = aipl_array_new(parts, count); free(parts); return res;
}

AiplVal aipl_str_parse_float_prefix(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; char* end = NULL;
  double v = strtod(s, &end);
  if (end == s) return aipl_none();
  return aipl_some(aipl_float(v));
}

AiplVal aipl_str_truncate(AiplVal s_val, AiplVal max_val, AiplVal ell_val) {
  if (s_val.kind == AIPL_ARRAY && s_val.ptr) {
    AiplArray* a = (AiplArray*)s_val.ptr;
    int64_t target = max_val.i < 0 ? 0 : max_val.i;
    if (a->len > target) a->len = target;
    return s_val;
  }
  const char* s = s_val.s ? s_val.s : ""; const char* ell = ell_val.s ? ell_val.s : "...";
  int64_t m = max_val.i < 0 ? 0 : max_val.i; size_t len = strlen(s);
  if ((int64_t)len <= m) return s_val;
  size_t ell_len = strlen(ell);
  if (m <= (int64_t)ell_len) {
    char* buf = (char*)malloc((size_t)m + 1);
    if (ell_len >= (size_t)m) memcpy(buf, ell, (size_t)m);
    else memcpy(buf, s, (size_t)m);
    buf[m] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
  }
  int64_t take = m - (int64_t)ell_len;
  char* buf = (char*)malloc((size_t)take + ell_len + 1);
  memcpy(buf, s, (size_t)take); memcpy(buf + take, ell, ell_len); buf[take + ell_len] = 0;
  AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_str_strip_prefix(AiplVal s_val, AiplVal pfx_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* p = pfx_val.s ? pfx_val.s : "";
  size_t pl = strlen(p);
  if (strncmp(s, p, pl) == 0) return aipl_str(s + pl);
  return s_val;
}

AiplVal aipl_str_remove_prefixes(AiplVal s_val, AiplVal pfxs_val) {
  const char* s = s_val.s ? s_val.s : "";
  if (pfxs_val.kind != AIPL_ARRAY || !pfxs_val.ptr) return s_val;
  AiplArray* arr = (AiplArray*)pfxs_val.ptr;
  for (int64_t i = 0; i < arr->len; i++) {
    const char* p = arr->data[i].s ? arr->data[i].s : ""; size_t pl = strlen(p);
    if (pl > 0 && strncmp(s, p, pl) == 0) s += pl;
  }
  return aipl_str(s);
}

AiplVal aipl_str_strip_suffix(AiplVal s_val, AiplVal suf_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* suf = suf_val.s ? suf_val.s : "";
  size_t sl = strlen(s); size_t sufl = strlen(suf);
  if (sl >= sufl && strcmp(s + sl - sufl, suf) == 0) return aipl_str_n(s, (int64_t)(sl - sufl));
  return s_val;
}

AiplVal aipl_str_between(AiplVal s_val, AiplVal open_val, AiplVal close_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* o = open_val.s ? open_val.s : ""; const char* c = close_val.s ? close_val.s : "";
  const char* p1 = strstr(s, o); if (!p1) return aipl_str("");
  p1 += strlen(o); const char* p2 = strstr(p1, c); if (!p2) return aipl_str("");
  return aipl_str_n(p1, (int64_t)(p2 - p1));
}

AiplVal aipl_str_starts_with_offset(AiplVal s_val, AiplVal pfx_val, AiplVal off_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* p = pfx_val.s ? pfx_val.s : "";
  int64_t off = off_val.i; size_t sl = strlen(s);
  if (off < 0 || (size_t)off > sl) return aipl_bool(false);
  size_t pl = strlen(p); return aipl_bool(strncmp(s + off, p, pl) == 0);
}

AiplVal aipl_str_split_once(AiplVal s_val, AiplVal delim_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* d = delim_val.s ? delim_val.s : "";
  const char* p = strstr(s, d); if (!p) return aipl_none();
  size_t dl = strlen(d); AiplVal parts[2];
  parts[0] = aipl_str_n(s, (int64_t)(p - s)); parts[1] = aipl_str(p + dl);
  return aipl_some(aipl_array_new(parts, 2));
}

AiplVal aipl_str_replace_first(AiplVal s_val, AiplVal old_val, AiplVal new_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* o = old_val.s ? old_val.s : ""; const char* n = new_val.s ? new_val.s : "";
  const char* p = strstr(s, o); if (!p) return s_val;
  size_t ol = strlen(o); size_t nl = strlen(n); size_t head = (size_t)(p - s); size_t tail = strlen(p + ol);
  char* buf = (char*)malloc(head + nl + tail + 1);
  memcpy(buf, s, head); memcpy(buf + head, n, nl); memcpy(buf + head + nl, p + ol, tail); buf[head + nl + tail] = 0;
  AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_str_replace_nth(AiplVal s_val, AiplVal old_val, AiplVal new_val, AiplVal nth_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* o = old_val.s ? old_val.s : ""; const char* n = new_val.s ? new_val.s : "";
  int64_t target_nth = nth_val.i; size_t ol = strlen(o); if (ol == 0) return s_val;
  const char* cur = s; int64_t count = 0; const char* match = NULL;
  while ((cur = strstr(cur, o)) != NULL) {
    if (count == target_nth) { match = cur; break; }
    count++; cur += ol;
  }
  if (!match) return s_val;
  size_t nl = strlen(n); size_t head = (size_t)(match - s); size_t tail = strlen(match + ol);
  char* buf = (char*)malloc(head + nl + tail + 1);
  memcpy(buf, s, head); memcpy(buf + head, n, nl); memcpy(buf + head + nl, match + ol, tail); buf[head + nl + tail] = 0;
  AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_str_equals_ignore_case(AiplVal a_val, AiplVal b_val) {
  const char* a = a_val.s ? a_val.s : ""; const char* b = b_val.s ? b_val.s : "";
  return aipl_bool(strcasecmp(a, b) == 0);
}

AiplVal aipl_str_contains_ignore_case(AiplVal s_val, AiplVal sub_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* sub = sub_val.s ? sub_val.s : "";
  return aipl_bool(strcasestr(s, sub) != NULL);
}

AiplVal aipl_str_index_of_ignore_case(AiplVal s_val, AiplVal sub_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* sub = sub_val.s ? sub_val.s : "";
  const char* p = strcasestr(s, sub); if (!p) return aipl_int(-1); return aipl_int((int64_t)(p - s));
}

AiplVal aipl_str_is_digit(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t l = strlen(s); if (l == 0) return aipl_bool(false);
  for (size_t i = 0; i < l; i++) { if (!isdigit((unsigned char)s[i])) return aipl_bool(false); }
  return aipl_bool(true);
}

AiplVal aipl_str_is_hex_digit(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t l = strlen(s); if (l == 0) return aipl_bool(false);
  for (size_t i = 0; i < l; i++) { if (!isxdigit((unsigned char)s[i])) return aipl_bool(false); }
  return aipl_bool(true);
}

AiplVal aipl_str_is_alpha(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t l = strlen(s); if (l == 0) return aipl_bool(false);
  for (size_t i = 0; i < l; i++) { if (!isalpha((unsigned char)s[i])) return aipl_bool(false); }
  return aipl_bool(true);
}

AiplVal aipl_str_is_alphanumeric(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t l = strlen(s); if (l == 0) return aipl_bool(false);
  for (size_t i = 0; i < l; i++) { if (!isalnum((unsigned char)s[i])) return aipl_bool(false); }
  return aipl_bool(true);
}

AiplVal aipl_str_is_ident_char(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t l = strlen(s); if (l == 0) return aipl_bool(false);
  for (size_t i = 0; i < l; i++) { char c = s[i]; if (!isalnum((unsigned char)c) && c != '_') return aipl_bool(false); }
  return aipl_bool(true);
}

AiplVal aipl_str_is_whitespace(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t l = strlen(s); if (l == 0) return aipl_bool(false);
  for (size_t i = 0; i < l; i++) { if (!isspace((unsigned char)s[i])) return aipl_bool(false); }
  return aipl_bool(true);
}

AiplVal aipl_str_contains(AiplVal s_val, AiplVal sub_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* sub = sub_val.s ? sub_val.s : "";
  size_t sl = aipl_str_byte_len(s_val); size_t subl = aipl_str_byte_len(sub_val);
  if (subl == 0) return aipl_bool(true);
  if (subl > sl) return aipl_bool(false);
  for (size_t i = 0; i + subl <= sl; i++) {
    if (memcmp(s + i, sub, subl) == 0) return aipl_bool(true);
  }
  return aipl_bool(false);
}

AiplVal aipl_str_index_of(AiplVal s_val, AiplVal sub_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* sub = sub_val.s ? sub_val.s : "";
  size_t sl = aipl_str_byte_len(s_val); size_t subl = aipl_str_byte_len(sub_val);
  if (subl == 0) return aipl_int(0);
  if (subl > sl) return aipl_int(-1);
  for (size_t i = 0; i + subl <= sl; i++) {
    if (memcmp(s + i, sub, subl) == 0) return aipl_int((int64_t)i);
  }
  return aipl_int(-1);
}

AiplVal aipl_str_last_index_of(AiplVal s_val, AiplVal sub_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* sub = sub_val.s ? sub_val.s : "";
  size_t sl = aipl_str_byte_len(s_val); size_t subl = aipl_str_byte_len(sub_val);
  if (subl == 0) return aipl_int((int64_t)sl);
  if (subl > sl) return aipl_int(-1);
  for (int64_t i = (int64_t)(sl - subl); i >= 0; i--) {
    if (memcmp(s + i, sub, subl) == 0) return aipl_int(i);
  }
  return aipl_int(-1);
}

AiplVal aipl_str_chars(AiplVal s_val) { return aipl_str_split(s_val, aipl_str("")); }

AiplVal aipl_clone(AiplVal v) {
  if (v.kind == AIPL_ARRAY && v.ptr) {
    AiplArray* a = (AiplArray*)v.ptr;
    return aipl_array_new(a->data, a->len);
  }
  if (v.kind == AIPL_MAP && v.ptr) {
    AiplMap* m = (AiplMap*)v.ptr;
    AiplVal res = aipl_map_new();
    for (int64_t i = 0; i < m->len; i++) {
      aipl_map_set(res, aipl_str(m->keys[i]), m->vals[i]);
    }
    return res;
  }
  return v;
}

AiplVal aipl_set_new(void) { return aipl_map_new(); }

void aipl_set_add(AiplVal s, AiplVal v) { aipl_map_set(s, aipl_to_str(v), aipl_bool(true)); }

AiplVal aipl_set_from_array(AiplVal arr_val) {
  AiplVal s = aipl_set_new();
  if (arr_val.kind == AIPL_ARRAY && arr_val.ptr) {
    AiplArray* a = (AiplArray*)arr_val.ptr;
    for (int64_t i = 0; i < a->len; i++) { aipl_set_add(s, a->data[i]); }
  }
  return s;
}

AiplVal aipl_to_array(AiplVal v) {
  if (v.kind == AIPL_ARRAY) return v;
  if (v.kind == AIPL_BYTES) return aipl_bytes_to_array(v);
  if (v.kind == AIPL_MAP) return aipl_map_keys(v);
  return aipl_array_new(NULL, 0);
}

void aipl_array_insert(AiplVal arr_val, AiplVal idx_val, AiplVal item) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return;
  AiplArray* a = (AiplArray*)arr_val.ptr;
  int64_t idx = idx_val.i; if (idx < 0) idx = 0; if (idx > a->len) idx = a->len;
  if (a->len >= a->cap) {
    a->cap = a->cap == 0 ? 8 : a->cap * 2;
    a->data = (AiplVal*)realloc(a->data, sizeof(AiplVal) * a->cap);
  }
  for (int64_t i = a->len; i > idx; i--) { a->data[i] = a->data[i - 1]; }
  a->data[idx] = item; a->len++;
}

void aipl_container_insert(AiplVal coll, AiplVal a, AiplVal b) {
  if (coll.kind == AIPL_ARRAY) { aipl_array_insert(coll, a, b); }
  else if (coll.kind == AIPL_MAP) { aipl_map_set(coll, a, b); }
}

void aipl_container_add(AiplVal coll, AiplVal a) {
  if (coll.kind == AIPL_ARRAY) { aipl_array_push(coll, a); }
  else if (coll.kind == AIPL_MAP) { aipl_set_add(coll, a); }
}

AiplVal aipl_get_or(AiplVal coll, AiplVal key, AiplVal def) {
  if (coll.kind == AIPL_MAP && coll.ptr) {
    const char* k = aipl_to_cstr(key);
    AiplVal r = aipl_map_get(coll, k);
    if (r.kind == AIPL_OPT_SOME && r.ptr) return *(AiplVal*)r.ptr;
    return def;
  }
  if (coll.kind == AIPL_ARRAY && coll.ptr) {
    AiplArray* a = (AiplArray*)coll.ptr; int64_t i = key.i;
    if (i >= 0 && i < a->len) return a->data[i];
    return def;
  }
  return def;
}

AiplVal aipl_map_get_or_insert(AiplVal map_val, AiplVal key, AiplVal def) {
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return def;
  const char* k = aipl_to_cstr(key);
  AiplVal r = aipl_map_get(map_val, k);
  if (r.kind == AIPL_OPT_SOME && r.ptr) return *(AiplVal*)r.ptr;
  aipl_map_set(map_val, key, def);
  return def;
}

void aipl_map_group_by_append(AiplVal map_val, AiplVal key_val, AiplVal elem_val) {
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return;
  const char* k = aipl_to_cstr(key_val);
  AiplMap* m = (AiplMap*)map_val.ptr;
  for (int64_t i = 0; i < m->len; i++) {
    if (m->keys[i] && strcmp(m->keys[i], k) == 0) {
      aipl_array_push(m->vals[i], elem_val); return;
    }
  }
  AiplVal arr = aipl_array_new(NULL, 0);
  aipl_array_push(arr, elem_val);
  aipl_map_set(map_val, key_val, arr);
}

AiplVal aipl_array_first(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_none();
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len == 0) return aipl_none();
  return aipl_some(a->data[0]);
}

AiplVal aipl_array_last(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_none();
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len == 0) return aipl_none();
  return aipl_some(a->data[a->len - 1]);
}

AiplVal aipl_array_head(AiplVal arr_val, AiplVal n_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_array_new(NULL, 0);
  AiplArray* a = (AiplArray*)arr_val.ptr; int64_t n = n_val.i;
  if (n <= 0) return aipl_array_new(NULL, 0); if (n > a->len) n = a->len;
  return aipl_array_new(a->data, n);
}

AiplVal aipl_array_tail(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_array_new(NULL, 0);
  AiplArray* a = (AiplArray*)arr_val.ptr; if (a->len <= 1) return aipl_array_new(NULL, 0);
  return aipl_array_new(a->data + 1, a->len - 1);
}

AiplVal aipl_array_tail_n(AiplVal arr_val, AiplVal n_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_array_new(NULL, 0);
  AiplArray* a = (AiplArray*)arr_val.ptr; int64_t n = n_val.i;
  if (n <= 0) return aipl_array_new(NULL, 0); if (n >= a->len) return aipl_array_new(a->data, a->len);
  return aipl_array_new(a->data + (a->len - n), n);
}

AiplVal aipl_array_chunks(AiplVal arr_val, AiplVal size_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr || size_val.i <= 0) return aipl_array_new(NULL, 0);
  AiplArray* a = (AiplArray*)arr_val.ptr; int64_t sz = size_val.i;
  int64_t num_chunks = (a->len + sz - 1) / sz;
  AiplVal* chunks = (AiplVal*)malloc(sizeof(AiplVal) * (num_chunks > 0 ? num_chunks : 1));
  for (int64_t i = 0; i < num_chunks; i++) {
    int64_t start = i * sz; int64_t len = sz; if (start + len > a->len) len = a->len - start;
    chunks[i] = aipl_array_new(a->data + start, len);
  }
  AiplVal res = aipl_array_new(chunks, num_chunks); free(chunks); return res;
}

AiplVal aipl_array_windows(AiplVal arr_val, AiplVal size_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr || size_val.i <= 0) return aipl_array_new(NULL, 0);
  AiplArray* a = (AiplArray*)arr_val.ptr; int64_t sz = size_val.i;
  if (a->len < sz) return aipl_array_new(NULL, 0);
  int64_t num_windows = a->len - sz + 1;
  AiplVal* wins = (AiplVal*)malloc(sizeof(AiplVal) * (num_windows > 0 ? num_windows : 1));
  for (int64_t i = 0; i < num_windows; i++) { wins[i] = aipl_array_new(a->data + i, sz); }
  AiplVal res = aipl_array_new(wins, num_windows); free(wins); return res;
}

AiplVal aipl_array_shift(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_none();
  AiplArray* a = (AiplArray*)arr_val.ptr; if (a->len == 0) return aipl_none();
  AiplVal first = a->data[0];
  for (int64_t i = 0; i < a->len - 1; i++) { a->data[i] = a->data[i + 1]; }
  a->len--; return aipl_some(first);
}

AiplVal aipl_array_unshift(AiplVal arr_val, AiplVal item) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_nil();
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len >= a->cap) {
    a->cap = a->cap == 0 ? 8 : a->cap * 2;
    a->data = (AiplVal*)realloc(a->data, sizeof(AiplVal) * a->cap);
  }
  for (int64_t i = a->len; i > 0; i--) { a->data[i] = a->data[i - 1]; }
  a->data[0] = item; a->len++; return aipl_int(a->len);
}

AiplVal aipl_array_swap_remove(AiplVal arr_val, AiplVal idx_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_none();
  AiplArray* a = (AiplArray*)arr_val.ptr; int64_t idx = idx_val.i;
  if (idx < 0 || idx >= a->len) return aipl_none();
  AiplVal v = a->data[idx]; a->data[idx] = a->data[a->len - 1]; a->len--;
  return aipl_some(v);
}

AiplVal aipl_array_extend(AiplVal arr_val, AiplVal other_val) {
  if (arr_val.kind == AIPL_ARRAY && arr_val.ptr && other_val.kind == AIPL_ARRAY && other_val.ptr) {
    AiplArray* b = (AiplArray*)other_val.ptr;
    for (int64_t i = 0; i < b->len; i++) { aipl_array_push(arr_val, b->data[i]); }
  }
  return arr_val;
}

AiplVal aipl_array_or_str_reverse(AiplVal v) {
  if (v.kind == AIPL_ARRAY && v.ptr) {
    AiplArray* a = (AiplArray*)v.ptr;
    for (int64_t i = 0, j = a->len - 1; i < j; i++, j--) {
      AiplVal t = a->data[i]; a->data[i] = a->data[j]; a->data[j] = t;
    }
    return v;
  }
  if (v.kind == AIPL_STR && v.s) {
    size_t l = strlen(v.s); char* d = (char*)malloc(l + 1);
    for (size_t i = 0; i < l; i++) d[i] = v.s[l - 1 - i];
    d[l] = 0; AiplVal r = aipl_str(d); free(d); return r;
  }
  return v;
}

AiplVal aipl_array_or_str_reversed(AiplVal v) {
  if (v.kind == AIPL_ARRAY && v.ptr) {
    AiplArray* a = (AiplArray*)v.ptr;
    AiplVal* d = (AiplVal*)malloc(sizeof(AiplVal) * (a->len > 0 ? a->len : 1));
    for (int64_t i = 0; i < a->len; i++) d[i] = a->data[a->len - 1 - i];
    AiplVal r = aipl_array_new(d, a->len); free(d); return r;
  }
  return aipl_array_or_str_reverse(v);
}

AiplVal aipl_array_copy_within(AiplVal arr_val, AiplVal target_val, AiplVal start_val, AiplVal end_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return arr_val;
  AiplArray* a = (AiplArray*)arr_val.ptr; int64_t to = target_val.i; int64_t from = start_val.i; int64_t end = end_val.i;
  if (to < 0) to += a->len; if (from < 0) from += a->len; if (end < 0) end += a->len;
  if (to < 0) to = 0; if (from < 0) from = 0; if (end > a->len) end = a->len;
  int64_t count = end - from; if (to + count > a->len) count = a->len - to;
  if (count <= 0) return arr_val;
  memmove(&a->data[to], &a->data[from], sizeof(AiplVal) * count); return arr_val;
}

AiplVal aipl_array_unique(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return arr_val;
  AiplArray* a = (AiplArray*)arr_val.ptr;
  AiplVal* out = (AiplVal*)malloc(sizeof(AiplVal) * (a->len > 0 ? a->len : 1)); int64_t out_len = 0;
  for (int64_t i = 0; i < a->len; i++) {
    bool found = false;
    for (int64_t j = 0; j < out_len; j++) { if (aipl_truthy(aipl_eq(a->data[i], out[j]))) { found = true; break; } }
    if (!found) out[out_len++] = a->data[i];
  }
  AiplVal res = aipl_array_new(out, out_len); free(out); return res;
}

AiplVal aipl_array_sort(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return arr_val;
  AiplArray* a = (AiplArray*)arr_val.ptr;
  AiplVal* out = (AiplVal*)malloc(sizeof(AiplVal) * (a->len > 0 ? a->len : 1));
  for (int64_t i = 0; i < a->len; i++) out[i] = a->data[i];
  for (int64_t i = 0; i < a->len - 1; i++) {
    for (int64_t j = i + 1; j < a->len; j++) {
      if (aipl_truthy(aipl_gt(out[i], out[j]))) { AiplVal t = out[i]; out[i] = out[j]; out[j] = t; }
    }
  }
  AiplVal res = aipl_array_new(out, a->len); free(out); return res;
}

AiplVal aipl_rt_roundTo(AiplVal x, AiplVal n) {
  double d = (x.kind == AIPL_FLOAT) ? x.f : (double)x.i;
  int64_t p = n.i; double f = pow(10.0, (double)p);
  return aipl_float(round(d * f) / f);
}

AiplVal aipl_rt_remEuclid(AiplVal a, AiplVal b) {
  if (b.i == 0 || b.i == 1 || b.i == -1) return aipl_int(0);
  int64_t r = a.i % b.i;
  if (r < 0) {
    uint64_t abs_b = (b.i < 0) ? (0ULL - (uint64_t)b.i) : (uint64_t)b.i;
    r = (int64_t)((uint64_t)r + abs_b);
  }
  return aipl_int(r);
}

AiplVal aipl_rt_popcnt(AiplVal x) {
  return aipl_int((int64_t)__builtin_popcountll((unsigned long long)x.i));
}

AiplVal aipl_rt_ctz(AiplVal x) {
  if (x.i == 0) return aipl_int(64);
  return aipl_int((int64_t)__builtin_ctzll((unsigned long long)x.i));
}

AiplVal aipl_rt_clz(AiplVal x) {
  if (x.i == 0) return aipl_int(64);
  return aipl_int((int64_t)__builtin_clzll((unsigned long long)x.i));
}

AiplVal aipl_rt_charFromCode(AiplVal x) {
  char buf[2] = { (char)x.i, 0 }; return aipl_str(buf);
}

AiplVal aipl_str_to_upper(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t len = strlen(s);
  char* buf = (char*)malloc(len + 1);
  for (size_t i = 0; i < len; i++) { buf[i] = (char)toupper((unsigned char)s[i]); }
  buf[len] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_opt_unwrap_or(AiplVal v, AiplVal def) {
  if ((v.kind == AIPL_RES_OK || v.kind == AIPL_OPT_SOME) && v.ptr) return *(AiplVal*)v.ptr;
  if (v.kind == AIPL_RES_ERR || v.kind == AIPL_OPT_NONE || v.kind == AIPL_NIL) return def;
  if (v.kind == AIPL_STR && v.s && (strcmp(v.s, "None") == 0 || strstr(v.s, "::None") != NULL)) return def;
  if (v.kind == AIPL_STRUCT && v.ptr) {
    const char* tn = ((AiplStruct*)v.ptr)->type_name;
    if (tn && (strcmp(tn, "None") == 0 || strstr(tn, "::None") || strcmp(tn, "Err") == 0 || strstr(tn, "::Err"))) return def;
    AiplVal inner = aipl_member_get(v, "value");
    if (inner.kind != AIPL_NIL) return inner;
    AiplVal data = aipl_member_get(v, "data");
    if (data.kind != AIPL_NIL) return data;
    AiplVal ok_v = aipl_member_get(v, "ok");
    if (ok_v.kind != AIPL_NIL) return ok_v;
    return v;
  }
  return v;
}

AiplVal aipl_expect(AiplVal v, AiplVal msg) {
  if ((v.kind == AIPL_RES_OK || v.kind == AIPL_OPT_SOME) && v.ptr) return *(AiplVal*)v.ptr;
  AiplVal s = aipl_to_str(msg); fprintf(stderr, "Panic: %s\n", s.s ? s.s : "explicit panic"); exit(1);
}

AiplVal aipl_enum_name(AiplVal v) {
  const char* s = (v.kind == AIPL_STRUCT && v.ptr) ? ((AiplStruct*)v.ptr)->type_name : ((v.kind == AIPL_STR && v.s) ? v.s : NULL);
  if (s) {
    const char* c = strstr(s, "::");
    if (c) return aipl_str(c + 2);
    return aipl_str(s);
  }
  return aipl_to_str(v);
}

AiplVal aipl_parse_int_res(AiplVal sVal) {
  AiplVal strV = aipl_to_str(sVal); const char* s = strV.s ? strV.s : "";
  while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++;
  if (*s == 0) return aipl_err(aipl_str("invalid int"));
  char* end = NULL; long long v = strtoll(s, &end, 10);
  if (end == s) return aipl_err(aipl_str("invalid int"));
  while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') end++;
  if (*end != 0) return aipl_err(aipl_str("invalid int"));
  return aipl_ok(aipl_int((int64_t)v));
}

AiplVal aipl_parse_float_res(AiplVal sVal) {
  AiplVal strV = aipl_to_str(sVal); const char* s = strV.s ? strV.s : "";
  while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++;
  if (*s == 0) return aipl_err(aipl_str("invalid float"));
  char* end = NULL; double v = strtod(s, &end);
  if (end == s) return aipl_err(aipl_str("invalid float"));
  while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') end++;
  if (*end != 0) return aipl_err(aipl_str("invalid float"));
  return aipl_ok(aipl_float(v));
}

AiplVal aipl_to_int_opt(AiplVal recv) {
  if (recv.kind == AIPL_INT) return aipl_int(recv.i);
  if (recv.kind == AIPL_FLOAT) return aipl_int((int64_t)recv.f);
  if (recv.kind == AIPL_STR) {
    if (recv.extra16 > 0) return aipl_some(aipl_int((int64_t)(recv.extra16 - 1)));
    const char* s = recv.s ? recv.s : "";
    while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++;
    if (*s == 0) return aipl_none();
    char* end = NULL; long long v = strtoll(s, &end, 10);
    if (end == s) return aipl_none();
    while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') end++;
    if (*end != 0) return aipl_none();
    return aipl_some(aipl_int((int64_t)v));
  }
  return aipl_none();
}

AiplVal aipl_to_float_opt(AiplVal recv) {
  if (recv.kind == AIPL_INT) return aipl_float((double)recv.i);
  if (recv.kind == AIPL_FLOAT) return recv;
  if (recv.kind == AIPL_STR) {
    const char* s = recv.s ? recv.s : "";
    while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++;
    if (*s == 0) return aipl_none();
    char* end = NULL; double v = strtod(s, &end);
    if (end == s) return aipl_none();
    while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') end++;
    if (*end != 0) return aipl_none();
    return aipl_some(aipl_float(v));
  }
  return aipl_none();
}

AiplVal aipl_unwrap_at(AiplVal v, int64_t idx) {
  if (v.kind == AIPL_ARRAY && v.ptr) {
    AiplArray* a = (AiplArray*)v.ptr;
    if (idx >= 0 && idx < a->len) return a->data[idx];
    if (idx < 0 && a->len > 0) return a->data[0];
    return aipl_nil();
  }
  if (v.kind == AIPL_STRUCT && v.ptr) {
    AiplStruct* st = (AiplStruct*)v.ptr;
    for (int64_t i = 0; i < st->len; i++) {
      if (st->names[i] && strcmp(st->names[i], "__enum_args__") == 0) {
        if (st->vals[i].kind == AIPL_ARRAY && st->vals[i].ptr) {
          AiplArray* a = (AiplArray*)st->vals[i].ptr;
          int64_t targetIdx = (idx < 0) ? 0 : idx;
          if (targetIdx >= 0 && targetIdx < a->len) return a->data[targetIdx];
          return aipl_nil();
        }
      }
    }
    int64_t targetIdx = (idx < 0) ? 0 : idx;
    if (targetIdx >= 0 && targetIdx < st->len) return st->vals[targetIdx];
    return aipl_nil();
  }
  if ((v.kind == AIPL_RES_OK || v.kind == AIPL_RES_ERR || v.kind == AIPL_OPT_SOME) && v.ptr) {
    AiplVal inner = *(AiplVal*)v.ptr;
    if (idx < 0) return inner;
    if (inner.kind == AIPL_ARRAY && inner.ptr) {
      AiplArray* a = (AiplArray*)inner.ptr; if (idx >= 0 && idx < a->len) return a->data[idx]; return aipl_nil();
    }
    if (idx == 0) return inner;
    return aipl_nil();
  }
  if (idx <= 0) return v; return aipl_nil();
}

AiplVal aipl_match_arm(AiplVal target, const char* pat) {
  if (!pat || strcmp(pat, "_") == 0) return aipl_bool(true);
  if (strchr(pat, '|')) {
    char pbuf[256]; strncpy(pbuf, pat, sizeof(pbuf) - 1); pbuf[sizeof(pbuf) - 1] = 0;
    char* saveptr = NULL; char* token = strtok_r(pbuf, "|", &saveptr);
    while (token) {
      while (*token == ' ') token++;
      char* end = token + strlen(token) - 1;
      while (end > token && *end == ' ') *end-- = 0;
      if (aipl_match_arm(target, token).b) return aipl_bool(true);
      token = strtok_r(NULL, "|", &saveptr);
    }
    return aipl_bool(false);
  }
  if (strncmp(pat, "__prefix__:", 11) == 0) {
    const char* pfx = pat + 11; size_t plen = strlen(pfx);
    if ((pfx[0] == '"' || pfx[0] == '\'') && plen >= 2 && pfx[plen - 1] == pfx[0]) { pfx++; plen -= 2; }
    if (target.kind == AIPL_STR && target.s && strncmp(target.s, pfx, plen) == 0) return aipl_bool(true);
    return aipl_bool(false);
  }
  if (strncmp(pat, "prefix(\"", 8) == 0) {
    const char* start = pat + 8; const char* end = strrchr(start, '\"');
    if (end && target.kind == AIPL_STR && target.s) {
      size_t plen = (size_t)(end - start);
      if (strncmp(target.s, start, plen) == 0) return aipl_bool(true);
    }
    return aipl_bool(false);
  }
  if (strncmp(pat, "__tuple__:", 10) == 0) {
    char tbuf[256]; strncpy(tbuf, pat + 10, sizeof(tbuf) - 1); tbuf[sizeof(tbuf) - 1] = 0;
    int k = 0; char* saveptr = NULL; char* token = strtok_r(tbuf, ",", &saveptr);
    while (token) {
      while (*token == ' ') token++;
      char* end = token + strlen(token) - 1;
      while (end > token && *end == ' ') *end-- = 0;
      AiplVal elem = aipl_index_get(target, aipl_int(k));
      if (!aipl_match_arm(elem, token).b) return aipl_bool(false);
      k++; token = strtok_r(NULL, ",", &saveptr);
    }
    return aipl_bool(true);
  }
  if (pat[0] == '"' || pat[0] == '\'') {
    size_t plen = strlen(pat);
    if (plen >= 2 && pat[plen - 1] == pat[0]) {
      if (target.kind == AIPL_STR && target.s && strlen(target.s) == plen - 2 && strncmp(target.s, pat + 1, plen - 2) == 0) return aipl_bool(true);
      return aipl_bool(false);
    }
  }
  const char* patColon = strstr(pat, "::");
  const char* patAfterColon = patColon ? (patColon + 2) : NULL;
  const char* ts = (target.kind == AIPL_STRUCT && target.ptr) ? ((AiplStruct*)target.ptr)->type_name : ((target.kind == AIPL_STR && target.s) ? target.s : NULL);
  if (ts) {
    if (strcmp(ts, pat) == 0) return aipl_bool(true);
    if (patAfterColon && strcmp(ts, patAfterColon) == 0) return aipl_bool(true);
    const char* targetColon = strstr(ts, "::");
    if (targetColon && strcmp(targetColon + 2, pat) == 0) return aipl_bool(true);
    if (targetColon && patAfterColon && strcmp(targetColon + 2, patAfterColon) == 0) return aipl_bool(true);
    if (targetColon && strcmp(pat, "None") == 0 && target.kind == AIPL_STR) return aipl_bool(true);
  }
  if (strcmp(pat, "true") == 0) return aipl_bool(target.kind == AIPL_BOOL && target.i != 0);
  if (strcmp(pat, "false") == 0) return aipl_bool(target.kind == AIPL_BOOL && target.i == 0);
  if (strcmp(pat, "nil") == 0) return aipl_bool(target.kind == AIPL_NIL || target.kind == AIPL_OPT_NONE);
  if (strcmp(pat, "None") == 0 || strcmp(pat, "Option::None") == 0 || (patAfterColon && strcmp(patAfterColon, "None") == 0)) {
    if (target.kind == AIPL_OPT_NONE || target.kind == AIPL_RES_ERR) return aipl_bool(true);
    if (ts && strstr(ts, "::None")) return aipl_bool(true);
    return aipl_bool(false);
  }
  if (strcmp(pat, "Some") == 0 || strcmp(pat, "Ok") == 0 || (patAfterColon && (strcmp(patAfterColon, "Some") == 0 || strcmp(patAfterColon, "Ok") == 0))) {
    return aipl_bool(target.kind == AIPL_OPT_SOME || target.kind == AIPL_RES_OK);
  }
  if (strcmp(pat, "Err") == 0 || (patAfterColon && strcmp(patAfterColon, "Err") == 0)) {
    return aipl_bool(target.kind == AIPL_RES_ERR || target.kind == AIPL_OPT_NONE);
  }
  if (target.kind == AIPL_STR && target.s && strcmp(target.s, pat) == 0) return aipl_bool(true);
  char* endp = NULL; long long iv = strtoll(pat, &endp, 10);
  if (endp && *endp == 0) return aipl_bool(target.kind == AIPL_INT && target.i == (int64_t)iv);
  return aipl_bool(false);
}

int g_aipl_argc = 0;
char** g_aipl_argv = NULL;
AiplVal aipl_rt_userArgs(void) {
  int start = 1;
  if (start < g_aipl_argc && strcmp(g_aipl_argv[start], "--") == 0) start++;
  int count = g_aipl_argc > start ? (g_aipl_argc - start) : 0;
  AiplVal* items = (AiplVal*)malloc(sizeof(AiplVal) * (count > 0 ? count : 1));
  for (int i = 0; i < count; i++) { items[i] = aipl_str(g_aipl_argv[start + i]); }
  AiplVal res = aipl_array_new(items, count); free(items); return res;
}

AiplVal aipl_rt_getEnv(AiplVal key) {
  const char* k = key.s ? key.s : ""; const char* val = getenv(k);
  if (!val) { return aipl_none(); }
  return aipl_some(aipl_str(val));
}

AiplVal aipl_rt_setEnv(AiplVal key, AiplVal val) {
  const char* k = key.s ? key.s : ""; const char* v = val.s ? val.s : "";
  setenv(k, v, 1); return aipl_nil();
}

AiplVal aipl_rt_cwd(void) {
  char buf[4096];
  if (getcwd(buf, sizeof(buf))) { return aipl_str(buf); }
  return aipl_str(".");
}

AiplVal aipl_rt_homeDir(void) {
  const char* h = getenv("HOME");
  if (h) { return aipl_some(aipl_str(h)); }
  return aipl_none();
}

AiplVal aipl_rt_tempDir(void) { return aipl_str("/tmp"); }

AiplVal aipl_rt_fileExists(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : ""; return aipl_bool(access(p, F_OK) == 0);
}

AiplVal aipl_rt_readFile(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : ""; FILE* f = NULL; int is_stdin = 0;
  if (strcmp(p, "/dev/stdin") == 0 || strcmp(p, "-") == 0) { f = stdin; is_stdin = 1; } else { f = fopen(p, "rb"); }
  if (!f) return aipl_str("");
  if (!is_stdin) {
    struct stat st;
    if (stat(p, &st) == 0 && S_ISDIR(st.st_mode)) { fclose(f); return aipl_str(""); }
  }
  long sz = -1; if (!is_stdin) { if (fseek(f, 0, SEEK_END) == 0) { sz = ftell(f); fseek(f, 0, SEEK_SET); } }
  if (!is_stdin && sz == 0) {
    int ch = fgetc(f);
    if (ch == EOF) { fclose(f); return aipl_str(""); }
    ungetc(ch, f);
  }
  if (sz > 0 && sz < 500000000L) {
    char* b = (char*)malloc((size_t)sz + 1);
    if (b) { size_t nr = fread(b, 1, (size_t)sz, f); b[nr] = 0; fclose(f); AiplVal res = aipl_str(b); free(b); return res; }
  }
  size_t cap = 4096; size_t len = 0; char* b = (char*)malloc(cap); size_t n;
  while ((n = fread(b + len, 1, cap - len - 1, f)) > 0) {
    len += n; if (len + 1 >= cap) { cap *= 2; b = (char*)realloc(b, cap); }
  }
  b[len] = 0; if (!is_stdin) fclose(f); AiplVal res = aipl_str(b); free(b); return res;
}

static int g_aipl_write_seq = 0;
AiplVal aipl_rt_writeFile(AiplVal path_val, AiplVal content_val) {
  const char* p = path_val.s ? path_val.s : ""; const char* c = content_val.s ? content_val.s : "";
  size_t clen = aipl_str_byte_len(content_val);
  if (p[0] != 0 && strncmp(p, "/dev/", 5) != 0 && strlen(p) < 3900) {
    int seq = __sync_fetch_and_add(&g_aipl_write_seq, 1);
    char tmp_p[4096];
    snprintf(tmp_p, sizeof(tmp_p), "%s.tmp.%d.%d", p, (int)getpid(), seq);
    FILE* tf = fopen(tmp_p, "wb");
    if (tf) {
      if (clen > 0) fwrite(c, 1, clen, tf);
      fclose(tf);
      chmod(tmp_p, 0644);
      if (rename(tmp_p, p) == 0) return aipl_bool(true);
      unlink(tmp_p);
    }
  }
  FILE* f = fopen(p, "wb"); if (!f) return aipl_bool(false);
  if (clen > 0) fwrite(c, 1, clen, f);
  fclose(f); chmod(p, 0644); return aipl_bool(true);
}

AiplVal aipl_rt_readBytes(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : "";
  if (strcmp(p, "@self_exe") == 0) p = "/proc/self/exe";
  struct stat st; if (stat(p, &st) == 0 && S_ISDIR(st.st_mode)) return aipl_err(aipl_str("readBytes: path is a directory"));
  FILE* f = fopen(p, "rb"); if (!f) return aipl_err(aipl_str("readBytes: failed to open"));
  long sz = -1; if (fseek(f, 0, SEEK_END) == 0) { sz = ftell(f); fseek(f, 0, SEEK_SET); }
  if (sz == 0) {
    int ch = fgetc(f);
    if (ch == EOF) { fclose(f); return aipl_ok(aipl_bytes_new(0)); }
    ungetc(ch, f);
  }
  if (sz > 0 && sz < 500000000L) {
    AiplVal bv = aipl_bytes_new(sz); AiplBytes* b = (AiplBytes*)bv.ptr;
    if (b) { size_t nr = fread(b->data, 1, (size_t)sz, f); b->len = (int64_t)nr; fclose(f); return aipl_ok(bv); }
  }
  size_t cap = 4096; size_t len = 0; uint8_t* data = (uint8_t*)malloc(cap); size_t n;
  while ((n = fread(data + len, 1, cap - len, f)) > 0) {
    len += n; if (len >= cap) { cap *= 2; data = (uint8_t*)realloc(data, cap); }
  }
  fclose(f); AiplVal bv = aipl_bytes_new((int64_t)len); AiplBytes* b = (AiplBytes*)bv.ptr;
  if (len > 0) memcpy(b->data, data, len);
  free(data); return aipl_ok(bv);
}

AiplVal aipl_rt_writeBytes(AiplVal path_val, AiplVal data_val) {
  const char* p = path_val.s ? path_val.s : "";
  if (data_val.kind != AIPL_BYTES || !data_val.ptr) return aipl_err(aipl_str("writeBytes: invalid bytes"));
  AiplBytes* b = (AiplBytes*)data_val.ptr; FILE* f = fopen(p, "wb");
  if (!f) return aipl_err(aipl_str("writeBytes: failed to open file"));
  if (b->len > 0) fwrite(b->data, 1, b->len, f);
  fclose(f); chmod(p, 0755); return aipl_ok(aipl_bool(true));
}

AiplVal aipl_find_embedded_asset(const char* query_path, AiplArray* list_out) {
  FILE* f = fopen("/proc/self/exe", "rb");
  if (!f) return aipl_err(aipl_str("failed to open /proc/self/exe"));
  fseek(f, 0, SEEK_END); long fsize = ftell(f);
  if (fsize < 32) { fclose(f); return aipl_err(aipl_str("file too small for asset trailer")); }
  fseek(f, fsize - 32, SEEK_SET);
  uint8_t footer[32];
  if (fread(footer, 1, 32, f) == 32 && memcmp(footer + 24, "AIPLSTND", 8) == 0) {
    uint64_t payloadLen = 0, assetLen = 0;
    for (int i = 0; i < 8; i++) {
      payloadLen |= ((uint64_t)footer[i]) << (i * 8);
      assetLen |= ((uint64_t)footer[8 + i]) << (i * 8);
    }
    if (assetLen > 0 && (int64_t)(payloadLen + assetLen + 32) <= (int64_t)fsize) {
      long assetOffset = fsize - 32 - (long)assetLen;
      fseek(f, assetOffset, SEEK_SET);
      uint8_t* abuf = (uint8_t*)malloc(assetLen);
      if (abuf && fread(abuf, 1, assetLen, f) == assetLen && assetLen >= 20 && memcmp(abuf, "AIPLBUND", 8) == 0) {
        uint64_t bcLen = 0;
        for (int i = 0; i < 8; i++) bcLen |= ((uint64_t)abuf[8 + i]) << (i * 8);
        if (16 + bcLen + 4 <= assetLen) {
          uint8_t* ptr = abuf + 16 + bcLen;
          uint32_t count = 0;
          for (int i = 0; i < 4; i++) count |= ((uint32_t)ptr[i]) << (i * 8);
          ptr += 4;
          typedef struct { char path[512]; uint64_t off; uint64_t sz; } TableEntry;
          TableEntry* entries = (TableEntry*)malloc(sizeof(TableEntry) * (count > 0 ? count : 1));
          bool valid = true;
          for (uint32_t k = 0; k < count; k++) {
            if (ptr + 4 > abuf + assetLen) { valid = false; break; }
            uint32_t plen = 0;
            for (int i = 0; i < 4; i++) plen |= ((uint32_t)ptr[i]) << (i * 8);
            ptr += 4;
            if (ptr + plen > abuf + assetLen || plen >= sizeof(entries[k].path)) { valid = false; break; }
            memcpy(entries[k].path, ptr, plen); entries[k].path[plen] = 0; ptr += plen;
            if (ptr + 16 > abuf + assetLen) { valid = false; break; }
            uint64_t a_off = 0, a_sz = 0;
            for (int i = 0; i < 8; i++) a_off |= ((uint64_t)ptr[i]) << (i * 8);
            for (int i = 0; i < 8; i++) a_sz |= ((uint64_t)ptr[8 + i]) << (i * 8);
            ptr += 16;
            if (ptr + 4 > abuf + assetLen) { valid = false; break; }
            uint32_t mlen = 0;
            for (int i = 0; i < 4; i++) mlen |= ((uint32_t)ptr[i]) << (i * 8);
            ptr += 4 + mlen + 4; entries[k].off = a_off; entries[k].sz = a_sz;
          }
          if (valid) {
            uint8_t* rawData = ptr;
            AiplVal foundRes = aipl_nil();
            for (uint32_t k = 0; k < count; k++) {
              if (list_out) { aipl_array_push(aipl_ptr_val(AIPL_ARRAY, list_out), aipl_str(entries[k].path)); }
              if (query_path && strcmp(entries[k].path, query_path) == 0) {
                AiplVal bres = aipl_bytes_new((int64_t)entries[k].sz); AiplBytes* rb = (AiplBytes*)bres.ptr;
                if (entries[k].sz > 0 && rawData + entries[k].off + entries[k].sz <= abuf + assetLen) {
                  memcpy(rb->data, rawData + entries[k].off, entries[k].sz);
                }
                foundRes = aipl_ok(bres);
              }
            }
            free(entries); free(abuf); fclose(f);
            if (query_path) {
              if (foundRes.kind == AIPL_RES_OK) return foundRes;
              return aipl_err(aipl_str("asset not found in AIPLBUND trailer"));
            }
            return aipl_ok(aipl_nil());
          }
          free(entries);
        }
      }
      if (abuf) free(abuf);
    }
  }
  long scan_sz = fsize > 262144 ? 262144 : fsize;
  fseek(f, fsize - scan_sz, SEEK_SET);
  char* scan_buf = (char*)malloc(scan_sz + 1);
  if (!scan_buf) { fclose(f); return aipl_err(aipl_str("out of memory scanning assets")); }
  size_t nr = fread(scan_buf, 1, scan_sz, f); scan_buf[nr] = 0; fclose(f);
  AiplVal foundAsset = aipl_nil();
  const char* cur = scan_buf;
  while (*cur) {
    const char* line_start = cur;
    const char* line_end = strchr(cur, '\n');
    if (!line_end) line_end = cur + strlen(cur);
    if (strncmp(line_start, "ASSET\t", 6) == 0 || strncmp(line_start, "ASSET ", 6) == 0) {
      const char* p1 = line_start + 6;
      const char* tab2 = strchr(p1, '\t');
      if (!tab2 || tab2 > line_end) tab2 = strchr(p1, ' ');
      if (tab2 && tab2 < line_end) {
        size_t path_len = tab2 - p1; char a_path[512];
        if (path_len < sizeof(a_path)) {
          memcpy(a_path, p1, path_len); a_path[path_len] = 0;
          if (list_out) { aipl_array_push(aipl_ptr_val(AIPL_ARRAY, list_out), aipl_str(a_path)); }
          if (query_path && strcmp(a_path, query_path) == 0) {
            const char* hex_data = tab2 + 1; size_t hex_len = line_end - hex_data;
            while (hex_len > 0 && (hex_data[hex_len - 1] == '\r' || hex_data[hex_len - 1] == ' ' || hex_data[hex_len - 1] == '\t')) hex_len--;
            AiplVal h_str = aipl_str_n(hex_data, (int64_t)hex_len); foundAsset = aipl_hex_to_bytes(h_str);
          }
        }
      }
    }
    cur = (*line_end == '\n') ? (line_end + 1) : line_end;
  }
  free(scan_buf);
  if (query_path) {
    if (foundAsset.kind == AIPL_RES_OK) return foundAsset;
    return aipl_err(aipl_str("asset not found in embedded trailer"));
  }
  return aipl_ok(aipl_nil());
}

AiplVal aipl_rt_listAssets(void) {
  AiplVal arr = aipl_array_new(NULL, 0);
  aipl_find_embedded_asset(NULL, (AiplArray*)arr.ptr);
  return arr;
}

AiplVal aipl_rt_removeFile(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : "";
  if (unlink(p) == 0) return aipl_ok(aipl_bool(true));
  return aipl_err(aipl_str("removeFile failed"));
}

int aipl_remove_dir_recursive(const char* path) {
  DIR* d = opendir(path);
  if (!d) return unlink(path) == 0;
  struct dirent* entry; int success = 1;
  while ((entry = readdir(d)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
    char subpath[1024]; snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
    struct stat st;
    if (lstat(subpath, &st) == 0) {
      if (S_ISDIR(st.st_mode)) { if (!aipl_remove_dir_recursive(subpath)) success = 0; }
      else { if (unlink(subpath) != 0) success = 0; }
    }
  }
  closedir(d);
  if (rmdir(path) != 0) success = 0;
  return success;
}

AiplVal aipl_rt_removeDirAll(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : "";
  if (!p[0]) return aipl_err(aipl_str("removeDirAll: empty path"));
  if (aipl_remove_dir_recursive(p) != 0) return aipl_ok(aipl_bool(true));
  return aipl_err(aipl_str("removeDirAll failed"));
}

AiplVal aipl_rt_isDir(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : ""; struct stat st;
  if (stat(p, &st) != 0) { return aipl_bool(false); }
  return aipl_bool(S_ISDIR(st.st_mode));
}

AiplVal aipl_rt_mkdir(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : "";
  if (mkdir(p, 0755) == 0) return aipl_ok(aipl_bool(true));
  return aipl_err(aipl_str("mkdir failed"));
}

int aipl_cmp_str(const void* a, const void* b) {
  return strcmp(*(const char**)a, *(const char**)b);
}

AiplVal aipl_rt_listDir(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : "."; DIR* d = opendir(p);
  if (!d) return aipl_array_new(NULL, 0);
  struct dirent* entry; int64_t count = 0; int64_t cap = 16;
  const char** names = (const char**)malloc(sizeof(const char*) * cap);
  while ((entry = readdir(d)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
    if (count >= cap) { cap *= 2; names = (const char**)realloc((void*)names, sizeof(const char*) * cap); }
    names[count++] = strdup(entry->d_name);
  }
  closedir(d);
  if (count > 1) qsort(names, count, sizeof(const char*), aipl_cmp_str);
  AiplVal* vals = (AiplVal*)malloc(sizeof(AiplVal) * (count > 0 ? count : 1));
  for (int64_t i = 0; i < count; i++) { vals[i] = aipl_str(names[i]); free((void*)names[i]); }
  free(names); AiplVal res = aipl_array_new(vals, count); free(vals); return res;
}

AiplVal aipl_rt_stat(AiplVal p) {
  const char* path = p.s ? p.s : "";
  struct stat st; memset(&st, 0, sizeof(st));
  if (stat(path, &st) == 0) {
    return aipl_ok(aipl_make_file_stat(path, &st));
  }
  return aipl_err(aipl_str("cannot stat file"));
}

AiplVal aipl_rt_readDir(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : "."; DIR* d = opendir(p);
  if (!d) return aipl_err(aipl_str("cannot open directory"));
  struct dirent* entry; int64_t count = 0; int64_t cap = 16;
  const char** names = (const char**)malloc(sizeof(const char*) * cap);
  while ((entry = readdir(d)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
    if (count >= cap) { cap *= 2; names = (const char**)realloc((void*)names, sizeof(const char*) * cap); }
    names[count++] = strdup(entry->d_name);
  }
  closedir(d);
  if (count > 1) qsort(names, count, sizeof(const char*), aipl_cmp_str);
  AiplVal* vals = (AiplVal*)malloc(sizeof(AiplVal) * (count > 0 ? count : 1));
  for (int64_t i = 0; i < count; i++) {
    char fullPath[1024];
    if (strcmp(p, ".") == 0) {
      snprintf(fullPath, sizeof(fullPath), "%s", names[i]);
    } else {
      size_t plen = strlen(p);
      if (plen > 0 && p[plen - 1] == '/') snprintf(fullPath, sizeof(fullPath), "%s%s", p, names[i]);
      else snprintf(fullPath, sizeof(fullPath), "%s/%s", p, names[i]);
    }
    struct stat st; memset(&st, 0, sizeof(st));
    stat(fullPath, &st);
    vals[i] = aipl_make_file_stat(fullPath, &st);
    free((void*)names[i]);
  }
  free(names); AiplVal res = aipl_array_new(vals, count); free(vals); return aipl_ok(res);
}

void aipl_walk_dir_rec(const char* dir_path, AiplVal* arr_val) {
  DIR* d = opendir(dir_path);
  if (!d) return;
  struct dirent* entry; int64_t count = 0; int64_t cap = 16;
  const char** names = (const char**)malloc(sizeof(const char*) * cap);
  while ((entry = readdir(d)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
    if (count >= cap) { cap *= 2; names = (const char**)realloc((void*)names, sizeof(const char*) * cap); }
    names[count++] = strdup(entry->d_name);
  }
  closedir(d);
  if (count > 1) qsort(names, count, sizeof(const char*), aipl_cmp_str);
  for (int64_t i = 0; i < count; i++) {
    char fullPath[1024];
    size_t plen = strlen(dir_path);
    if (plen > 0 && dir_path[plen - 1] == '/') snprintf(fullPath, sizeof(fullPath), "%s%s", dir_path, names[i]);
    else snprintf(fullPath, sizeof(fullPath), "%s/%s", dir_path, names[i]);
    struct stat st; memset(&st, 0, sizeof(st));
    if (stat(fullPath, &st) == 0) {
      aipl_array_push(*arr_val, aipl_make_file_stat(fullPath, &st));
      if (S_ISDIR(st.st_mode)) { aipl_walk_dir_rec(fullPath, arr_val); }
    }
    free((void*)names[i]);
  }
  free(names);
}

AiplVal aipl_rt_walkDir(AiplVal path_val) {
  const char* p = path_val.s ? path_val.s : ".";
  struct stat st; if (stat(p, &st) != 0) return aipl_err(aipl_str("walkDir: directory does not exist"));
  AiplVal arr = aipl_array_new(NULL, 0);
  aipl_walk_dir_rec(p, &arr);
  return aipl_ok(arr);
}

AiplVal aipl_rt_setFileTimes(AiplVal p, AiplVal atimeMs, AiplVal mtimeMs) {
  const char* path = p.s ? p.s : "";
  struct utimbuf ut; ut.actime = (time_t)(atimeMs.i / 1000); ut.modtime = (time_t)(mtimeMs.i / 1000);
  if (utime(path, &ut) == 0) return aipl_ok(aipl_bool(true));
  return aipl_err(aipl_str("setFileTimes failed"));
}

AiplVal aipl_rt_appendFile(AiplVal p, AiplVal c) {
  const char* path = p.s ? p.s : ""; const char* content = c.s ? c.s : "";
  size_t len = aipl_str_byte_len(c); FILE* f = fopen(path, "ab");
  if (!f) return aipl_err(aipl_str("appendFile: cannot open file"));
  if (len > 0) fwrite(content, 1, len, f);
  fclose(f); return aipl_ok(aipl_bool(true));
}

AiplVal aipl_rt_pathJoin(AiplVal a_val, AiplVal b_val) {
  const char* a = a_val.s ? a_val.s : ""; const char* b = b_val.s ? b_val.s : "";
  if (!a[0]) { return b_val; }
  if (!b[0]) { return a_val; }
  if (b[0] == '/') return b_val;
  size_t la = strlen(a); size_t lb = strlen(b); int need_slash = (a[la - 1] != '/');
  char* buf = (char*)malloc(la + lb + 2); memcpy(buf, a, la);
  if (need_slash) { buf[la] = '/'; memcpy(buf + la + 1, b, lb); buf[la + 1 + lb] = 0; }
  else { memcpy(buf + la, b, lb); buf[la + lb] = 0; }
  AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_rt_pathBasename(AiplVal p_val) {
  const char* p = p_val.s ? p_val.s : "";
  const char* last = strrchr(p, '/'); if (!last) last = strrchr(p, '\\');
  if (!last) { return p_val; }
  return aipl_str(last + 1);
}

AiplVal aipl_rt_pathDirname(AiplVal p_val) {
  const char* p = p_val.s ? p_val.s : "";
  const char* last = strrchr(p, '/'); if (!last) last = strrchr(p, '\\');
  if (!last) { return aipl_str("."); }
  if (last == p) { return aipl_str("/"); }
  size_t len = last - p; char* buf = (char*)malloc(len + 1);
  memcpy(buf, p, len); buf[len] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_rt_pathExtname(AiplVal p_val) {
  AiplVal base = aipl_rt_pathBasename(p_val); const char* s = base.s ? base.s : "";
  const char* dot = strrchr(s, '.');
  if (!dot || dot == s) { return aipl_str(""); }
  return aipl_str(dot);
}

AiplVal aipl_rt_pathExtension(AiplVal p_val) {
  AiplVal ext = aipl_rt_pathExtname(p_val);
  if (ext.s && ext.s[0] == '.') { return aipl_str(ext.s + 1); }
  return ext;
}

AiplVal aipl_rt_pathExt(AiplVal p_val) { return aipl_rt_pathExtname(p_val); }

AiplVal aipl_rt_pathStem(AiplVal p_val) {
  AiplVal base = aipl_rt_pathBasename(p_val); const char* s = base.s ? base.s : "";
  const char* dot = strrchr(s, '.'); if (!dot || dot == s) return base;
  size_t n = dot - s; char* b = (char*)malloc(n + 1); memcpy(b, s, n); b[n] = 0;
  AiplVal res = aipl_str(b); free(b); return res;
}

AiplVal aipl_rt_pathIsAbsolute(AiplVal p_val) {
  const char* p = p_val.s ? p_val.s : ""; return aipl_bool(p[0] == '/');
}

AiplVal aipl_rt_realpath(AiplVal path_val) {
  const char* p = (path_val.kind == AIPL_STR && path_val.s) ? path_val.s : "";
  if (!p || !p[0]) return aipl_str("");
#ifdef _WIN32
  if (strcmp(p, "/proc/self/exe") == 0 || strcmp(p, "@self_exe") == 0) {
    char exe_buf[4096];
    DWORD n = GetModuleFileNameA(NULL, exe_buf, sizeof(exe_buf));
    if (n > 0 && n < sizeof(exe_buf)) return aipl_str(exe_buf);
    return aipl_str("");
  }
  char full_buf[4096];
  if (_fullpath(full_buf, p, sizeof(full_buf))) return aipl_str(full_buf);
  return aipl_str("");
#else
  if (strcmp(p, "@self_exe") == 0) p = "/proc/self/exe";
  char resolved[4096];
  if (realpath(p, resolved)) {
    return aipl_str(resolved);
  }
  ssize_t link_len = readlink(p, resolved, sizeof(resolved) - 1);
  if (link_len > 0) {
    resolved[link_len] = 0;
    return aipl_str(resolved);
  }
  return aipl_str("");
#endif
}

AiplVal aipl_rt_pathNormalize(AiplVal p_val) {
  const char* p = p_val.s ? p_val.s : "";
  if (!p[0]) { return aipl_str("."); }
  if (strcmp(p, "/proc/self/exe") == 0 || strcmp(p, "@self_exe") == 0) {
    return aipl_rt_realpath(p_val);
  }
  size_t plen = strlen(p);
  int is_abs = (p[0] == '/');
  char* buf = strdup(p);
  size_t max_segs = (plen / 2) + 4;
  const char** segs = (const char**)malloc(sizeof(const char*) * max_segs);
  size_t count = 0;
  char* tok = strtok(buf, "/\\");
  while (tok) {
    if (strcmp(tok, ".") == 0) {}
    else if (strcmp(tok, "..") == 0) {
      if (count > 0 && strcmp(segs[count - 1], "..") != 0) count--;
      else if (!is_abs && count < max_segs) segs[count++] = tok;
    } else if (count < max_segs) segs[count++] = tok;
    tok = strtok(NULL, "/\\");
  }
  char* out = (char*)malloc(plen + 4);
  size_t pos = 0;
  if (is_abs) out[pos++] = '/';
  for (size_t i = 0; i < count; i++) {
    size_t sl = strlen(segs[i]);
    memcpy(out + pos, segs[i], sl);
    pos += sl;
    if (i + 1 < count) out[pos++] = '/';
  }
  if (pos == 0) out[pos++] = '.';
  out[pos] = 0;
  AiplVal res = aipl_str(out);
  free(out);
  free((void*)segs);
  free(buf);
  return res;
}

