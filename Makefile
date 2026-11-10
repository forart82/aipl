# ==============================================================================
# AIPL (AI-Programming Language) Root Makefile
# ==============================================================================
PREFIX ?= $(HOME)/.local
BINDIR ?= $(PREFIX)/bin
AIPL_BIN := bin/aipl

.PHONY: all bootstrap test install clean

all: $(AIPL_BIN)

$(AIPL_BIN): compiler/bootstrap/build.sh runtime/aipl_runtime.h runtime/rt_core.c runtime/rt_crypto_data.c runtime/rt_sys.c runtime/rt_gui_audio.c
	@bash compiler/bootstrap/build.sh $(AIPL_BIN)

bootstrap: $(AIPL_BIN)
	@./$(AIPL_BIN) bootstrap

test: $(AIPL_BIN)
	@./$(AIPL_BIN) test

install: $(AIPL_BIN)
	@mkdir -p "$(BINDIR)"
	@cp "$(AIPL_BIN)" "$(BINDIR)/aipl"
	@chmod +x "$(BINDIR)/aipl"
	@echo "Installed aipl to $(BINDIR)/aipl"

clean:
	@rm -rf .aipl/cache compiler/bootstrap/aipl_bootstrap
