/* AIPL C99 runtime - public interface (Phase 18 split modular runtime).
 * Generated programs `#include "aipl_runtime.h"` and link libaipl_rt.a (or
 * libaipl_rt_gui.a when AIPL_ENABLE_GUI_AUDIO is defined before inclusion). */
#ifndef AIPL_RUNTIME_H
#define AIPL_RUNTIME_H
#define AIPL_RUNTIME_VERSION "0.9.0"
#if defined(__x86_64__) || defined(_M_X64)
#define AIPL_TARGET_AVX2_FMA __attribute__((target("avx2,fma")))
#else
#define AIPL_TARGET_AVX2_FMA
#endif
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#if defined(__GNUC__) || defined(__clang__)
#define AIPL_GLOBAL __attribute__((weak))
#else
#define AIPL_GLOBAL static
#endif
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#if defined(__linux__)
#include <sys/syscall.h>
#include <malloc.h>
#endif
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <utime.h>
#include <sys/resource.h>
#include <netdb.h>
#include <pthread.h>
#include <sys/file.h>
#include <fcntl.h>
#include <signal.h>
#if defined(__x86_64__) || defined(_M_X64)
#include <immintrin.h>
#elif defined(__aarch64__)
#include <arm_neon.h>
#endif
#ifndef _WIN32
#include <dlfcn.h>
#endif
typedef enum {
  AIPL_NIL = 0,
  AIPL_INT,
  AIPL_FLOAT,
  AIPL_BOOL,
  AIPL_STR,
  AIPL_BYTES,
  AIPL_ARRAY,
  AIPL_MAP,
  AIPL_STRUCT,
  AIPL_RES_OK,
  AIPL_RES_ERR,
  AIPL_OPT_SOME,
  AIPL_OPT_NONE,
  AIPL_FUNC
} AiplKind;
typedef struct AiplVal {
  uint32_t kind;
  union {
    struct {
      uint8_t b;
      uint8_t _pad;
      uint16_t extra16;
    };
    int32_t extra_i;
  };
  union {
    int64_t i;
    double f;
    const char* s;
    void* ptr;
  };
} AiplVal;
typedef AiplVal Color;
typedef AiplVal Vec2;
typedef AiplVal Vec3;
typedef AiplVal Rect;
void aipl_unpack_color(AiplVal c, uint8_t* r, uint8_t* g, uint8_t* b, uint8_t* a);
typedef struct AiplBytes {
  uint8_t* data;
  int64_t len;
  int64_t cap;
} AiplBytes;
typedef struct AiplArray {
  AiplVal* data;
  int64_t len;
  int64_t cap;
} AiplArray;
typedef struct AiplMap {
  const char** keys;
  AiplVal* vals;
  int64_t len;
  int64_t cap;
  uint32_t* hash_tags;
  int32_t* hash_slots;
  int64_t hash_cap;
} AiplMap;
typedef struct AiplStruct {
  const char* type_name;
  const char** names;
  AiplVal* vals;
  int64_t len;
  int64_t extra_i;
} AiplStruct;
#if defined(__GNUC__) || defined(__clang__)
#define AIPL_HOT_INLINE __attribute__((always_inline)) static inline
#else
#define AIPL_HOT_INLINE static inline
#endif
AIPL_HOT_INLINE AiplVal aipl_nil(void) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_NIL; return v;
}
typedef AiplVal (*AiplFnPtr)(int argc, AiplVal* args);
AiplVal aipl_func(AiplFnPtr fn);
static inline AiplVal aipl_call_val(AiplVal fnVal, int argc, AiplVal* args) {
  if (fnVal.kind == AIPL_FUNC && fnVal.ptr) { return ((AiplFnPtr)fnVal.ptr)(argc, args); }
  return aipl_nil();
}
AIPL_HOT_INLINE AiplVal aipl_int(int64_t val) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_INT; v.i = val; return v;
}
AIPL_HOT_INLINE AiplVal aipl_float(double val) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_FLOAT; v.f = val; return v;
}
AIPL_HOT_INLINE AiplVal aipl_bool(bool val) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_BOOL; v.b = val; v.i = val ? 1 : 0; return v;
}
extern int64_t _aipl_arena_depth;
void* aipl_arena_alloc_raw(int64_t sz);
static inline AiplVal aipl_str(const char* val) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STR;
  if (!val) { v.s = ""; v.extra_i = -1; return v; }
  size_t n = strlen(val);
  if (_aipl_arena_depth > 0) {
    char* d = (char*)aipl_arena_alloc_raw((int64_t)(n + 1));
    memcpy(d, val, n + 1);
    v.s = d;
  } else {
    v.s = strdup(val);
  }
  v.extra_i = (n > 0) ? (int)n : -1;
  return v;
}
static inline AiplVal aipl_str_n(const char* val, int64_t len) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STR;
  if (!val || len <= 0) { v.s = ""; v.extra_i = -1; return v; }
  char* d;
  if (_aipl_arena_depth > 0) {
    d = (char*)aipl_arena_alloc_raw((int64_t)(len + 1));
  } else {
    d = (char*)malloc((size_t)len + 1);
  }
  memcpy(d, val, (size_t)len); d[len] = 0; v.s = d;
  v.extra_i = (len > 0) ? (int)len : -1;
  return v;
}
static inline AiplVal aipl_str_lit(const char* val) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STR;
  v.s = val ? val : "";
  if (val) { size_t n = strlen(val); v.extra_i = (n > 0) ? (int)n : -1; } else { v.extra_i = -1; }
  return v;
}
static inline AiplVal aipl_enum_tag(const char* name, int64_t ord) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STR; v.s = name; v.extra16 = (uint16_t)(ord + 1); return v;
}
static inline size_t aipl_str_byte_len(AiplVal v) {
  if (v.kind != AIPL_STR || !v.s) return 0;
  if (v.extra_i > 0) return (size_t)v.extra_i;
  if (v.extra_i == -1) return 0;
  return strlen(v.s);
}
static inline AiplVal aipl_ok(AiplVal inner) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_RES_OK;
  AiplVal* p = (AiplVal*)malloc(sizeof(AiplVal)); *p = inner; v.ptr = p; return v;
}
static inline AiplVal aipl_err(AiplVal inner) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_RES_ERR;
  AiplVal* p = (AiplVal*)malloc(sizeof(AiplVal)); *p = inner; v.ptr = p; return v;
}
static inline AiplVal aipl_some(AiplVal inner) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_OPT_SOME;
  AiplVal* p = (AiplVal*)malloc(sizeof(AiplVal)); *p = inner; v.ptr = p; return v;
}
static inline AiplVal aipl_none(void) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_OPT_NONE; return v;
}
static inline bool aipl_truthy_slow(AiplVal v) {
  while (v.kind == AIPL_OPT_SOME && v.ptr) v = *(AiplVal*)v.ptr;
  switch (v.kind) {
    case AIPL_NIL: return false;
    case AIPL_BOOL: return v.i != 0;
    case AIPL_INT: return v.i != 0;
    case AIPL_FLOAT: return v.f != 0.0;
    case AIPL_STR: return v.s && v.s[0] != 0;
    case AIPL_BYTES: return v.ptr && ((AiplBytes*)v.ptr)->len > 0;
    case AIPL_ARRAY: return v.ptr && ((AiplArray*)v.ptr)->len > 0;
    case AIPL_MAP: return v.ptr && ((AiplMap*)v.ptr)->len > 0;
    case AIPL_STRUCT: return true;
    case AIPL_RES_OK: return true;
    case AIPL_RES_ERR: return false;
    case AIPL_OPT_SOME: return true;
    case AIPL_OPT_NONE: return false;
    default: return false;
  }
}
AIPL_HOT_INLINE bool aipl_truthy(AiplVal v) {
  if (v.kind == AIPL_BOOL || v.kind == AIPL_INT) return v.i != 0;
  return aipl_truthy_slow(v);
}
extern int64_t _aipl_arena_depth;
extern int64_t _aipl_prof_total_allocs;
extern int64_t _aipl_prof_total_bytes;
void* aipl_arena_alloc_raw(int64_t sz);
static inline void aipl_prof_record_alloc(size_t sz) {
  _aipl_prof_total_allocs++;
  _aipl_prof_total_bytes += (int64_t)sz;
}
static inline AiplVal aipl_bytes_new(int64_t size) {
  int64_t cap = size > 8 ? size : 8;
  aipl_prof_record_alloc(sizeof(AiplBytes) + (size_t)cap);
  AiplBytes* b = (AiplBytes*)malloc(sizeof(AiplBytes));
  b->len = size; b->cap = cap;
  b->data = (uint8_t*)calloc(b->cap, 1);
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_BYTES; v.ptr = b; return v;
}
static inline AiplVal aipl_array_new(const AiplVal* elems, int64_t count) {
  int64_t cap = count > 8 ? count : 8;
  aipl_prof_record_alloc(sizeof(AiplArray) + sizeof(AiplVal) * (size_t)cap);
  AiplArray* arr = (AiplArray*)malloc(sizeof(AiplArray));
  arr->data = (AiplVal*)malloc(sizeof(AiplVal) * cap);
  arr->len = count; arr->cap = cap;
  for (int64_t i = 0; i < count; i++) { arr->data[i] = elems[i]; }
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_ARRAY; v.ptr = arr; return v;
}
static inline AiplVal aipl_bytes_to_string_lossy(AiplVal b_val) {
  if ((b_val.kind == AIPL_RES_OK || b_val.kind == AIPL_OPT_SOME) && b_val.ptr) return aipl_bytes_to_string_lossy(*(AiplVal*)b_val.ptr);
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_str("");
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  if (b->len <= 0) return aipl_str("");
  char* s = (char*)malloc(b->len + 1);
  memcpy(s, b->data, b->len); s[b->len] = 0;
  AiplVal res = aipl_str(s); free(s); return res;
}
static inline AiplVal aipl_ptr_val(AiplKind kind, void* ptr) {
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = kind; v.ptr = ptr; return v;
}
static inline AiplVal aipl_to_str(AiplVal v) {
  char buf[128];
  switch (v.kind) {
    case AIPL_STR: return v;
    case AIPL_INT: snprintf(buf, sizeof(buf), "%lld", (long long)v.i); return aipl_str(buf);
    case AIPL_FLOAT: snprintf(buf, sizeof(buf), "%g", v.f); return aipl_str(buf);
    case AIPL_BOOL: return aipl_str_lit(v.i ? "true" : "false");
    case AIPL_NIL: return aipl_str_lit("nil");
    case AIPL_BYTES: return aipl_bytes_to_string_lossy(v);
    case AIPL_RES_OK:
      return v.ptr ? aipl_to_str(*(AiplVal*)v.ptr) : aipl_str_lit("Ok");
    case AIPL_RES_ERR:
      return v.ptr ? aipl_to_str(*(AiplVal*)v.ptr) : aipl_str_lit("Err");
    case AIPL_OPT_SOME:
      return v.ptr ? aipl_to_str(*(AiplVal*)v.ptr) : aipl_str_lit("Some");
    case AIPL_OPT_NONE: return aipl_str_lit("None");
    case AIPL_STRUCT: {
      AiplStruct* st = (AiplStruct*)v.ptr;
      snprintf(buf, sizeof(buf), "<struct %s>", (st && st->type_name) ? st->type_name : "struct");
      return aipl_str(buf);
    }
    default: return aipl_str_lit("");
  }
}
AiplVal aipl_format_val(AiplVal v, const char* spec);
AIPL_HOT_INLINE AiplVal aipl_to_int(AiplVal v) {
  if (v.kind == AIPL_INT) return v;
  if (v.kind == AIPL_FLOAT) return aipl_int((int64_t)v.f);
  if (v.kind == AIPL_BOOL) return aipl_int(v.i);
  while ((v.kind == AIPL_OPT_SOME || v.kind == AIPL_RES_OK) && v.ptr) v = *(AiplVal*)v.ptr;
  if (v.kind == AIPL_INT) return v;
  if (v.kind == AIPL_FLOAT) return aipl_int((int64_t)v.f);
  if (v.kind == AIPL_BOOL) return aipl_int(v.i);
  if (v.kind == AIPL_STR) {
    if (v.extra16 > 0) return aipl_int((int64_t)(v.extra16 - 1));
    if (v.s) return aipl_int(strtoll(v.s, NULL, 10));
  }
  return aipl_int(0);
}
AIPL_HOT_INLINE AiplVal aipl_to_float(AiplVal v) {
  if (v.kind == AIPL_FLOAT) return v;
  if (v.kind == AIPL_INT) return aipl_float((double)v.i);
  while ((v.kind == AIPL_OPT_SOME || v.kind == AIPL_RES_OK) && v.ptr) v = *(AiplVal*)v.ptr;
  if (v.kind == AIPL_FLOAT) return v;
  if (v.kind == AIPL_INT) return aipl_float((double)v.i);
  if (v.kind == AIPL_STR) {
    if (v.extra16 > 0) return aipl_float((double)(v.extra16 - 1));
    if (v.s) return aipl_float(strtod(v.s, NULL));
  }
  return aipl_float(0.0);
}
AIPL_HOT_INLINE double aipl_as_float(AiplVal v) {
  if (v.kind == AIPL_FLOAT) return v.f;
  if (v.kind == AIPL_INT || v.kind == AIPL_BOOL) return (double)v.i;
  while ((v.kind == AIPL_OPT_SOME || v.kind == AIPL_RES_OK) && v.ptr) v = *(AiplVal*)v.ptr;
  if (v.kind == AIPL_FLOAT) return v.f;
  if (v.kind == AIPL_INT || v.kind == AIPL_BOOL) return (double)v.i;
  if (v.kind == AIPL_STR) {
    if (v.extra16 > 0) return (double)(v.extra16 - 1);
    if (v.s) return strtod(v.s, NULL);
  }
  return 0.0;
}
AIPL_HOT_INLINE int64_t aipl_as_int(AiplVal v) {
  if (v.kind == AIPL_INT) return v.i;
  if (v.kind == AIPL_FLOAT) return (int64_t)v.f;
  if (v.kind == AIPL_BOOL) return v.i;
  while ((v.kind == AIPL_OPT_SOME || v.kind == AIPL_RES_OK) && v.ptr) v = *(AiplVal*)v.ptr;
  if (v.kind == AIPL_INT) return v.i;
  if (v.kind == AIPL_FLOAT) return (int64_t)v.f;
  if (v.kind == AIPL_BOOL) return v.i;
  if (v.kind == AIPL_STR) {
    if (v.extra16 > 0) return (int64_t)(v.extra16 - 1);
    if (v.s) return strtoll(v.s, NULL, 10);
  }
  return 0;
}
#define AIPL_STRUCT_TAG_VEC2 0x56454332LL
#define AIPL_STRUCT_TAG_VEC3 0x56454333LL
static inline int64_t aipl_struct_tag_for_name(const char* type_name) {
  if (type_name && type_name[0] == 'V' && type_name[1] == 'e' && type_name[2] == 'c') {
    if (type_name[3] == '2' && type_name[4] == 0) return AIPL_STRUCT_TAG_VEC2;
    if (type_name[3] == '3' && type_name[4] == 0) return AIPL_STRUCT_TAG_VEC3;
  }
  return 0;
}
static inline AiplVal aipl_struct_new_static(const char* type_name, int64_t len, const char** static_names, const AiplVal* vals) {
  int64_t st_tag = aipl_struct_tag_for_name(type_name);
  int is_aura = (type_name && (strcmp(type_name, "AuraContext") == 0 || strcmp(type_name, "AuraTheme") == 0));
  if (len <= 0) {
    AiplStruct* st;
    if (_aipl_arena_depth > 0 && !is_aura) {
      st = (AiplStruct*)aipl_arena_alloc_raw((int64_t)sizeof(AiplStruct));
    } else {
      aipl_prof_record_alloc(sizeof(AiplStruct));
      st = (AiplStruct*)malloc(sizeof(AiplStruct));
    }
    st->type_name = type_name ? type_name : ""; st->len = 0; st->extra_i = st_tag;
    st->names = NULL; st->vals = NULL;
    AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STRUCT; v.ptr = st; v.extra_i = (int32_t)st_tag; return v;
  }
  size_t total = sizeof(AiplStruct) + sizeof(AiplVal) * (size_t)len;
  char* mem;
  if (_aipl_arena_depth > 0 && !is_aura) {
    mem = (char*)aipl_arena_alloc_raw((int64_t)total);
  } else {
    aipl_prof_record_alloc(total);
    mem = (char*)malloc(total);
  }
  AiplStruct* st = (AiplStruct*)mem;
  st->type_name = type_name ? type_name : ""; st->len = len; st->extra_i = st_tag;
  st->names = static_names;
  st->vals = (AiplVal*)(mem + sizeof(AiplStruct));
  for (int64_t i = 0; i < len; i++) {
    st->vals[i] = vals ? vals[i] : aipl_nil();
  }
  if (is_aura) {
    for (int64_t i = 0; i < len; i++) {
      if (st->vals[i].kind == AIPL_STR && st->vals[i].s) {
        char* cs = strdup(st->vals[i].s);
        AiplVal sv; memset(&sv, 0, sizeof(sv)); sv.kind = AIPL_STR; sv.s = cs; sv.extra_i = st->vals[i].extra_i;
        st->vals[i] = sv;
      }
    }
  }
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STRUCT; v.ptr = st; v.extra_i = (int32_t)st_tag; return v;
}
static inline AiplVal aipl_struct_new(const char* type_name, int64_t len, const char** names, const AiplVal* vals) {
  int64_t st_tag = aipl_struct_tag_for_name(type_name);
  int is_aura = (type_name && (strcmp(type_name, "AuraContext") == 0 || strcmp(type_name, "AuraTheme") == 0));
  if (len <= 0) {
    AiplStruct* st;
    if (_aipl_arena_depth > 0 && !is_aura) {
      st = (AiplStruct*)aipl_arena_alloc_raw((int64_t)sizeof(AiplStruct));
    } else {
      aipl_prof_record_alloc(sizeof(AiplStruct));
      st = (AiplStruct*)malloc(sizeof(AiplStruct));
    }
    st->type_name = type_name ? type_name : ""; st->len = 0; st->extra_i = st_tag;
    st->names = NULL; st->vals = NULL;
    AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STRUCT; v.ptr = st; v.extra_i = (int32_t)st_tag; return v;
  }
  size_t total = sizeof(AiplStruct) + sizeof(const char*) * (size_t)len + sizeof(AiplVal) * (size_t)len;
  char* mem;
  if (_aipl_arena_depth > 0 && !is_aura) {
    mem = (char*)aipl_arena_alloc_raw((int64_t)total);
  } else {
    aipl_prof_record_alloc(total);
    mem = (char*)malloc(total);
  }
  AiplStruct* st = (AiplStruct*)mem;
  st->type_name = type_name ? type_name : ""; st->len = len; st->extra_i = st_tag;
  st->names = (const char**)(mem + sizeof(AiplStruct));
  st->vals = (AiplVal*)(mem + sizeof(AiplStruct) + sizeof(const char*) * (size_t)len);
  for (int64_t i = 0; i < len; i++) {
    st->names[i] = names ? names[i] : "";
    st->vals[i] = vals ? vals[i] : aipl_nil();
  }
  if (is_aura) {
    for (int64_t i = 0; i < len; i++) {
      if (st->vals[i].kind == AIPL_STR && st->vals[i].s) {
        char* cs = strdup(st->vals[i].s);
        AiplVal sv; memset(&sv, 0, sizeof(sv)); sv.kind = AIPL_STR; sv.s = cs; sv.extra_i = st->vals[i].extra_i;
        st->vals[i] = sv;
      }
    }
  }
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_STRUCT; v.ptr = st; v.extra_i = (int32_t)st_tag; return v;
}
static inline AiplVal aipl_vec2(double x, double y) {
  static const char* const _v2_names[] = { "x", "y" };
  return aipl_struct_new_static("Vec2", 2, (const char**)_v2_names, (AiplVal[]){ aipl_float(x), aipl_float(y) });
}
static inline AiplVal aipl_rt_Vec3(AiplVal x, AiplVal y, AiplVal z) {
  static const char* const _v3_names[] = { "x", "y", "z" };
  double dx = (x.kind == AIPL_FLOAT) ? x.f : (double)x.i;
  double dy = (y.kind == AIPL_FLOAT) ? y.f : (double)y.i;
  double dz = (z.kind == AIPL_FLOAT) ? z.f : (double)z.i;
  return aipl_struct_new_static("Vec3", 3, (const char**)_v3_names, (AiplVal[]){ aipl_float(dx), aipl_float(dy), aipl_float(dz) });
}
static inline AiplVal aipl_eq_slow(AiplVal a, AiplVal b) {
  if ((a.kind == AIPL_NIL || a.kind == AIPL_OPT_NONE) && (b.kind == AIPL_NIL || b.kind == AIPL_OPT_NONE)) return aipl_bool(true);
  if (a.kind == AIPL_RES_OK && b.kind == AIPL_BOOL) {
    if (!a.ptr) return aipl_bool(false);
    return aipl_eq_slow(*(AiplVal*)a.ptr, b);
  }
  if (a.kind == AIPL_BOOL && b.kind == AIPL_RES_OK) {
    if (!b.ptr) return aipl_bool(false);
    return aipl_eq_slow(a, *(AiplVal*)b.ptr);
  }
  if (a.kind == AIPL_RES_OK && b.kind == AIPL_STR) {
    if (!a.ptr) return aipl_bool(false);
    return aipl_eq_slow(*(AiplVal*)a.ptr, b);
  }
  if (a.kind == AIPL_STR && b.kind == AIPL_RES_OK) {
    if (!b.ptr) return aipl_bool(false);
    return aipl_eq_slow(a, *(AiplVal*)b.ptr);
  }
  if (a.kind == AIPL_RES_OK && b.kind == AIPL_BYTES) {
    if (!a.ptr) return aipl_bool(false);
    return aipl_eq_slow(*(AiplVal*)a.ptr, b);
  }
  if (a.kind == AIPL_BYTES && b.kind == AIPL_RES_OK) {
    if (!b.ptr) return aipl_bool(false);
    return aipl_eq_slow(a, *(AiplVal*)b.ptr);
  }
  if (a.kind == AIPL_OPT_SOME && b.kind != AIPL_OPT_SOME && b.kind != AIPL_OPT_NONE) {
    if (!a.ptr) return aipl_bool(false);
    return aipl_eq_slow(*(AiplVal*)a.ptr, b);
  }
  if (b.kind == AIPL_OPT_SOME && a.kind != AIPL_OPT_SOME && a.kind != AIPL_OPT_NONE) {
    if (!b.ptr) return aipl_bool(false);
    return aipl_eq_slow(a, *(AiplVal*)b.ptr);
  }
  if (a.extra_i == 0x434F4C52 || b.extra_i == 0x434F4C52) {
    uint8_t ra, ga, ba, aa, rb, gb, bb, ab;
    aipl_unpack_color(a, &ra, &ga, &ba, &aa);
    aipl_unpack_color(b, &rb, &gb, &bb, &ab);
    return aipl_bool(ra == rb && ga == gb && ba == bb && aa == ab);
  }
  if (a.kind == AIPL_STRUCT && b.kind == AIPL_INT && a.ptr && ((AiplStruct*)a.ptr)->type_name && strcmp(((AiplStruct*)a.ptr)->type_name, "Color") == 0) {
    int64_t ai = ((AiplStruct*)a.ptr)->extra_i;
    return aipl_bool(ai == b.i || (ai & 0xFFFFFF) == b.i || ((ai >> 8) & 0xFFFFFF) == b.i);
  }
  if (a.kind == AIPL_INT && b.kind == AIPL_STRUCT && b.ptr && ((AiplStruct*)b.ptr)->type_name && strcmp(((AiplStruct*)b.ptr)->type_name, "Color") == 0) {
    int64_t bi = ((AiplStruct*)b.ptr)->extra_i;
    return aipl_bool(a.i == bi || a.i == (bi & 0xFFFFFF) || a.i == ((bi >> 8) & 0xFFFFFF));
  }
  if (a.kind == AIPL_STRUCT && b.kind == AIPL_STRUCT && a.ptr && b.ptr && ((AiplStruct*)a.ptr)->type_name && ((AiplStruct*)b.ptr)->type_name && strcmp(((AiplStruct*)a.ptr)->type_name, "Color") == 0 && strcmp(((AiplStruct*)b.ptr)->type_name, "Color") == 0) {
    return aipl_bool(((AiplStruct*)a.ptr)->extra_i == ((AiplStruct*)b.ptr)->extra_i);
  }
  if (a.kind == AIPL_STRUCT && b.kind == AIPL_STRUCT && a.ptr && b.ptr) {
    AiplStruct* sa = (AiplStruct*)a.ptr; AiplStruct* sb = (AiplStruct*)b.ptr;
    if (sa->len == sb->len && strcmp(sa->type_name, sb->type_name) == 0) {
      bool eq = true;
      for (int64_t i = 0; i < sa->len; i++) {
        if (!aipl_truthy(aipl_eq_slow(sa->vals[i], sb->vals[i]))) { eq = false; break; }
      }
      if (eq) return aipl_bool(true);
    }
  }
  if (a.kind == AIPL_ARRAY && b.kind == AIPL_ARRAY && a.ptr && b.ptr) {
    AiplArray* aa = (AiplArray*)a.ptr; AiplArray* bb = (AiplArray*)b.ptr;
    if (aa->len != bb->len) return aipl_bool(false);
    for (int64_t i = 0; i < aa->len; i++) {
      if (!aipl_truthy(aipl_eq_slow(aa->data[i], bb->data[i]))) return aipl_bool(false);
    }
    return aipl_bool(true);
  }
  if (a.kind == AIPL_STR || b.kind == AIPL_STR) {
    if (a.kind != AIPL_STR || b.kind != AIPL_STR) {
      if (a.kind == AIPL_STRUCT && b.kind == AIPL_STR && a.ptr && b.s && ((AiplStruct*)a.ptr)->type_name && strcmp(((AiplStruct*)a.ptr)->type_name, b.s) == 0) return aipl_bool(true);
      if (a.kind == AIPL_STR && b.kind == AIPL_STRUCT && a.s && b.ptr && ((AiplStruct*)b.ptr)->type_name && strcmp(a.s, ((AiplStruct*)b.ptr)->type_name) == 0) return aipl_bool(true);
      return aipl_bool(false);
    }
    if (strcmp(a.s ? a.s : "", b.s ? b.s : "") == 0) return aipl_bool(true);
    const char* sa = a.s ? a.s : ""; const char* sb = b.s ? b.s : "";
    const char* ca = strstr(sa, "::"); const char* cb = strstr(sb, "::");
    if (ca && strcmp(ca + 2, sb) == 0) return aipl_bool(true);
    if (cb && strcmp(sa, cb + 2) == 0) return aipl_bool(true);
    return aipl_bool(false);
  }
  if (a.kind == AIPL_BOOL && b.kind == AIPL_BOOL) return aipl_bool((a.i != 0) == (b.i != 0));
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) return aipl_bool(a.i == b.i);
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_bool(fa == fb);
  }
  if (a.kind == AIPL_BYTES && b.kind == AIPL_BYTES) {
    AiplBytes* ba = (AiplBytes*)a.ptr;
    AiplBytes* bb = (AiplBytes*)b.ptr;
    if (!ba || !bb) return aipl_bool(ba == bb);
    if (ba->len != bb->len) return aipl_bool(false);
    return aipl_bool(memcmp(ba->data, bb->data, ba->len) == 0);
  }
  if (a.kind == AIPL_OPT_SOME && b.kind == AIPL_OPT_SOME) {
    if (!a.ptr || !b.ptr) return aipl_bool(a.ptr == b.ptr);
    return aipl_eq_slow(*(AiplVal*)a.ptr, *(AiplVal*)b.ptr);
  }
  if (a.kind == AIPL_RES_OK && b.kind == AIPL_RES_OK) {
    if (!a.ptr || !b.ptr) return aipl_bool(a.ptr == b.ptr);
    return aipl_eq_slow(*(AiplVal*)a.ptr, *(AiplVal*)b.ptr);
  }
  if (a.kind == AIPL_RES_ERR && b.kind == AIPL_RES_ERR) {
    if (!a.ptr || !b.ptr) return aipl_bool(a.ptr == b.ptr);
    return aipl_eq_slow(*(AiplVal*)a.ptr, *(AiplVal*)b.ptr);
  }
  return aipl_bool(a.kind == b.kind && a.ptr == b.ptr && a.i == b.i);
}
AIPL_HOT_INLINE AiplVal aipl_eq(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT && a.extra_i == 0 && b.extra_i == 0) return aipl_bool(a.i == b.i);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_FLOAT) return aipl_bool(a.f == b.f);
  if (a.kind == AIPL_BOOL && b.kind == AIPL_BOOL) return aipl_bool((a.i != 0) == (b.i != 0));
  return aipl_eq_slow(a, b);
}
AIPL_HOT_INLINE AiplVal aipl_neq(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT && a.extra_i == 0 && b.extra_i == 0) return aipl_bool(a.i != b.i);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_FLOAT) return aipl_bool(a.f != b.f);
  return aipl_bool(!aipl_truthy(aipl_eq(a, b)));
}
static inline int aipl_cmp_slow(AiplVal a, AiplVal b) {
  while ((a.kind == AIPL_OPT_SOME || a.kind == AIPL_RES_OK) && a.ptr) a = *(AiplVal*)a.ptr;
  while ((b.kind == AIPL_OPT_SOME || b.kind == AIPL_RES_OK) && b.ptr) b = *(AiplVal*)b.ptr;
  if (a.kind == AIPL_ARRAY && b.kind == AIPL_ARRAY && a.ptr && b.ptr) {
    AiplArray* aa = (AiplArray*)a.ptr;
    AiplArray* bb = (AiplArray*)b.ptr;
    int64_t n = aa->len < bb->len ? aa->len : bb->len;
    for (int64_t i = 0; i < n; i++) {
      int c = aipl_cmp_slow(aa->data[i], bb->data[i]);
      if (c != 0) return c;
    }
    return (aa->len < bb->len) ? -1 : ((aa->len > bb->len) ? 1 : 0);
  }
  if (a.extra16 > 0 && b.extra16 > 0 && (a.kind == AIPL_STR || a.kind == AIPL_STRUCT) && (b.kind == AIPL_STR || b.kind == AIPL_STRUCT)) {
    return (a.extra16 < b.extra16) ? -1 : ((a.extra16 > b.extra16) ? 1 : 0);
  }
  if (a.kind == AIPL_STR && b.kind == AIPL_STR) {
    return strcmp(a.s ? a.s : "", b.s ? b.s : "");
  }
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return (fa < fb) ? -1 : ((fa > fb) ? 1 : 0);
  }
  return (a.i < b.i) ? -1 : ((a.i > b.i) ? 1 : 0);
}
AIPL_HOT_INLINE int aipl_cmp(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) return (a.i < b.i) ? -1 : ((a.i > b.i) ? 1 : 0);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_FLOAT) return (a.f < b.f) ? -1 : ((a.f > b.f) ? 1 : 0);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_INT) { double bf = (double)b.i; return (a.f < bf) ? -1 : ((a.f > bf) ? 1 : 0); }
  if (a.kind == AIPL_INT && b.kind == AIPL_FLOAT) { double af = (double)a.i; return (af < b.f) ? -1 : ((af > b.f) ? 1 : 0); }
  return aipl_cmp_slow(a, b);
}
AIPL_HOT_INLINE AiplVal aipl_lt(AiplVal a, AiplVal b) { return aipl_bool(aipl_cmp(a, b) < 0); }
AIPL_HOT_INLINE AiplVal aipl_le(AiplVal a, AiplVal b) { return aipl_bool(aipl_cmp(a, b) <= 0); }
AIPL_HOT_INLINE AiplVal aipl_gt(AiplVal a, AiplVal b) { return aipl_bool(aipl_cmp(a, b) > 0); }
AIPL_HOT_INLINE AiplVal aipl_ge(AiplVal a, AiplVal b) { return aipl_bool(aipl_cmp(a, b) >= 0); }
AiplVal aipl_str_concat(AiplVal a, AiplVal b);
AIPL_HOT_INLINE bool aipl_is_vec2(AiplVal v) {
  return v.kind == AIPL_STRUCT && v.ptr && ((AiplStruct*)v.ptr)->extra_i == AIPL_STRUCT_TAG_VEC2;
}
AIPL_HOT_INLINE bool aipl_is_vec3(AiplVal v) {
  return v.kind == AIPL_STRUCT && v.ptr && ((AiplStruct*)v.ptr)->extra_i == AIPL_STRUCT_TAG_VEC3;
}
static inline AiplVal aipl_add_slow(AiplVal a, AiplVal b) {
  while ((a.kind == AIPL_RES_OK || a.kind == AIPL_OPT_SOME) && a.ptr) a = *(AiplVal*)a.ptr;
  while ((b.kind == AIPL_RES_OK || b.kind == AIPL_OPT_SOME) && b.ptr) b = *(AiplVal*)b.ptr;
  if (aipl_is_vec2(a)) {
    AiplStruct* sa = (AiplStruct*)a.ptr;
    double ax = (sa->vals[0].kind == AIPL_FLOAT) ? sa->vals[0].f : (double)sa->vals[0].i;
    double ay = (sa->vals[1].kind == AIPL_FLOAT) ? sa->vals[1].f : (double)sa->vals[1].i;
    if (aipl_is_vec2(b)) {
      AiplStruct* sb = (AiplStruct*)b.ptr;
      double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
      double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
      return aipl_vec2(ax + bx, ay + by);
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_vec2(ax + s, ay + s);
  }
  if (aipl_is_vec2(b)) {
    AiplStruct* sb = (AiplStruct*)b.ptr;
    double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
    double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
    double s = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    return aipl_vec2(s + bx, s + by);
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
      return aipl_rt_Vec3(aipl_float(ax + bx), aipl_float(ay + by), aipl_float(az + bz));
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_rt_Vec3(aipl_float(ax + s), aipl_float(ay + s), aipl_float(az + s));
  }
  if (aipl_is_vec3(b)) {
    AiplStruct* sb = (AiplStruct*)b.ptr;
    double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
    double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
    double bz = (sb->vals[2].kind == AIPL_FLOAT) ? sb->vals[2].f : (double)sb->vals[2].i;
    double s = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    return aipl_rt_Vec3(aipl_float(s + bx), aipl_float(s + by), aipl_float(s + bz));
  }
  if (a.kind == AIPL_BYTES && b.kind == AIPL_BYTES) {
    AiplBytes* ba = (AiplBytes*)a.ptr; AiplBytes* bb = (AiplBytes*)b.ptr;
    int64_t n = (ba ? ba->len : 0) + (bb ? bb->len : 0);
    AiplVal res = aipl_bytes_new(n); AiplBytes* r = (AiplBytes*)res.ptr;
    if (ba && ba->len > 0) memcpy(r->data, ba->data, ba->len);
    if (bb && bb->len > 0) memcpy(r->data + (ba ? ba->len : 0), bb->data, bb->len);
    return res;
  }
  if (a.kind == AIPL_ARRAY && b.kind == AIPL_ARRAY) {
    AiplArray* aa = (AiplArray*)a.ptr; AiplArray* ab = (AiplArray*)b.ptr;
    int64_t total = (aa ? aa->len : 0) + (ab ? ab->len : 0);
    AiplVal* data = (AiplVal*)malloc(sizeof(AiplVal) * (total > 0 ? total : 1));
    int64_t idx = 0;
    if (aa) { for (int64_t i = 0; i < aa->len; i++) data[idx++] = aa->data[i]; }
    if (ab) { for (int64_t i = 0; i < ab->len; i++) data[idx++] = ab->data[i]; }
    AiplVal res = aipl_array_new(data, total); free(data); return res;
  }
  if (a.kind == AIPL_STR || b.kind == AIPL_STR) {
    return aipl_str_concat(aipl_to_str(a), aipl_to_str(b));
  }
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_float(fa + fb);
  }
  return aipl_int(a.i + b.i);
}
AIPL_HOT_INLINE AiplVal aipl_add(AiplVal a, AiplVal b) {
  if ((a.kind == AIPL_INT || a.kind == AIPL_BOOL) && (b.kind == AIPL_INT || b.kind == AIPL_BOOL)) return aipl_int(a.i + b.i);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_FLOAT) return aipl_float(a.f + b.f);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_INT) return aipl_float(a.f + (double)b.i);
  if (a.kind == AIPL_INT && b.kind == AIPL_FLOAT) return aipl_float((double)a.i + b.f);
  return aipl_add_slow(a, b);
}
AIPL_HOT_INLINE void aipl_inc_int(AiplVal* v, int64_t delta) {
  if (__builtin_expect(v->kind == AIPL_INT, 1)) { v->extra_i = 0; v->i += delta; return; }
  if (v->kind == AIPL_FLOAT) { v->f += (double)delta; return; }
  *v = aipl_add(*v, aipl_int(delta));
}
static inline AiplVal aipl_sub_slow(AiplVal a, AiplVal b) {
  while ((a.kind == AIPL_RES_OK || a.kind == AIPL_OPT_SOME) && a.ptr) a = *(AiplVal*)a.ptr;
  while ((b.kind == AIPL_RES_OK || b.kind == AIPL_OPT_SOME) && b.ptr) b = *(AiplVal*)b.ptr;
  if (aipl_is_vec2(a)) {
    AiplStruct* sa = (AiplStruct*)a.ptr;
    double ax = (sa->vals[0].kind == AIPL_FLOAT) ? sa->vals[0].f : (double)sa->vals[0].i;
    double ay = (sa->vals[1].kind == AIPL_FLOAT) ? sa->vals[1].f : (double)sa->vals[1].i;
    if (aipl_is_vec2(b)) {
      AiplStruct* sb = (AiplStruct*)b.ptr;
      double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
      double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
      return aipl_vec2(ax - bx, ay - by);
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_vec2(ax - s, ay - s);
  }
  if (aipl_is_vec2(b)) {
    AiplStruct* sb = (AiplStruct*)b.ptr;
    double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
    double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
    double s = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    return aipl_vec2(s - bx, s - by);
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
      return aipl_rt_Vec3(aipl_float(ax - bx), aipl_float(ay - by), aipl_float(az - bz));
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_rt_Vec3(aipl_float(ax - s), aipl_float(ay - s), aipl_float(az - s));
  }
  if (aipl_is_vec3(b)) {
    AiplStruct* sb = (AiplStruct*)b.ptr;
    double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
    double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
    double bz = (sb->vals[2].kind == AIPL_FLOAT) ? sb->vals[2].f : (double)sb->vals[2].i;
    double s = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    return aipl_rt_Vec3(aipl_float(s - bx), aipl_float(s - by), aipl_float(s - bz));
  }
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_float(fa - fb);
  }
  return aipl_int(a.i - b.i);
}
AIPL_HOT_INLINE AiplVal aipl_sub(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) return aipl_int(a.i - b.i);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_FLOAT) return aipl_float(a.f - b.f);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_INT) return aipl_float(a.f - (double)b.i);
  if (a.kind == AIPL_INT && b.kind == AIPL_FLOAT) return aipl_float((double)a.i - b.f);
  return aipl_sub_slow(a, b);
}
static inline AiplVal aipl_mul_slow(AiplVal a, AiplVal b) {
  while ((a.kind == AIPL_RES_OK || a.kind == AIPL_OPT_SOME) && a.ptr) a = *(AiplVal*)a.ptr;
  while ((b.kind == AIPL_RES_OK || b.kind == AIPL_OPT_SOME) && b.ptr) b = *(AiplVal*)b.ptr;
  if (aipl_is_vec2(a)) {
    AiplStruct* sa = (AiplStruct*)a.ptr;
    double ax = (sa->vals[0].kind == AIPL_FLOAT) ? sa->vals[0].f : (double)sa->vals[0].i;
    double ay = (sa->vals[1].kind == AIPL_FLOAT) ? sa->vals[1].f : (double)sa->vals[1].i;
    if (aipl_is_vec2(b)) {
      AiplStruct* sb = (AiplStruct*)b.ptr;
      double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
      double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
      return aipl_vec2(ax * bx, ay * by);
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_vec2(ax * s, ay * s);
  }
  if (aipl_is_vec2(b)) {
    AiplStruct* sb = (AiplStruct*)b.ptr;
    double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
    double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
    double s = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    return aipl_vec2(s * bx, s * by);
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
      return aipl_rt_Vec3(aipl_float(ax * bx), aipl_float(ay * by), aipl_float(az * bz));
    }
    double s = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_rt_Vec3(aipl_float(ax * s), aipl_float(ay * s), aipl_float(az * s));
  }
  if (aipl_is_vec3(b)) {
    AiplStruct* sb = (AiplStruct*)b.ptr;
    double bx = (sb->vals[0].kind == AIPL_FLOAT) ? sb->vals[0].f : (double)sb->vals[0].i;
    double by = (sb->vals[1].kind == AIPL_FLOAT) ? sb->vals[1].f : (double)sb->vals[1].i;
    double bz = (sb->vals[2].kind == AIPL_FLOAT) ? sb->vals[2].f : (double)sb->vals[2].i;
    double s = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    return aipl_rt_Vec3(aipl_float(s * bx), aipl_float(s * by), aipl_float(s * bz));
  }
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_float(fa * fb);
  }
  return aipl_int(a.i * b.i);
}
AIPL_HOT_INLINE AiplVal aipl_mul(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) return aipl_int(a.i * b.i);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_FLOAT) return aipl_float(a.f * b.f);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_INT) return aipl_float(a.f * (double)b.i);
  if (a.kind == AIPL_INT && b.kind == AIPL_FLOAT) return aipl_float((double)a.i * b.f);
  return aipl_mul_slow(a, b);
}
AiplVal aipl_div_slow(AiplVal a, AiplVal b);
AIPL_HOT_INLINE AiplVal aipl_div(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) return aipl_int(b.i != 0 ? a.i / b.i : 0);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_FLOAT) return aipl_float(b.f != 0.0 ? a.f / b.f : 0.0);
  if (a.kind == AIPL_FLOAT && b.kind == AIPL_INT) return aipl_float(b.i != 0 ? a.f / (double)b.i : 0.0);
  if (a.kind == AIPL_INT && b.kind == AIPL_FLOAT) return aipl_float(b.f != 0.0 ? (double)a.i / b.f : 0.0);
  return aipl_div_slow(a, b);
}
AIPL_HOT_INLINE AiplVal aipl_floor_div(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) {
    if (b.i == 0) return aipl_int(0);
    int64_t q = a.i / b.i;
    int64_t r = a.i % b.i;
    if ((r != 0) && ((r < 0) != (b.i < 0))) q--;
    return aipl_int(q);
  }
  double fa = aipl_as_float(a);
  double fb = aipl_as_float(b);
  return aipl_int(fb != 0.0 ? (int64_t)floor(fa / fb) : 0);
}
AIPL_HOT_INLINE AiplVal aipl_mod(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_FLOAT || b.kind == AIPL_FLOAT) {
    double fa = (a.kind == AIPL_FLOAT) ? a.f : (double)a.i;
    double fb = (b.kind == AIPL_FLOAT) ? b.f : (double)b.i;
    return aipl_float(fb != 0.0 ? fmod(fa, fb) : 0.0);
  }
  return aipl_int(b.i != 0 ? a.i % b.i : 0);
}
AiplVal aipl_pow(AiplVal a, AiplVal b);
AiplVal aipl_euclid_mod(AiplVal a, AiplVal b);
AIPL_HOT_INLINE AiplVal aipl_neg(AiplVal a) {
  if (a.kind == AIPL_FLOAT) return aipl_float(-a.f);
  return aipl_int(-a.i);
}
AIPL_HOT_INLINE AiplVal aipl_not(AiplVal a) { return aipl_bool(!aipl_truthy(a)); }
AIPL_HOT_INLINE AiplVal aipl_bitnot(AiplVal a) { return aipl_int(~a.i); }
AIPL_HOT_INLINE AiplVal aipl_shl(AiplVal a, AiplVal b) { return aipl_int(a.i << b.i); }
AIPL_HOT_INLINE AiplVal aipl_shr(AiplVal a, AiplVal b) { return aipl_int(a.i >> b.i); }
AIPL_HOT_INLINE AiplVal aipl_bitand(AiplVal a, AiplVal b) { return aipl_int(a.i & b.i); }
AIPL_HOT_INLINE AiplVal aipl_bitor(AiplVal a, AiplVal b) { return aipl_int(a.i | b.i); }
AIPL_HOT_INLINE AiplVal aipl_bitxor(AiplVal a, AiplVal b) { return aipl_int(a.i ^ b.i); }
static inline void aipl_array_push(AiplVal arr_val, AiplVal item) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return;
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len >= a->cap) {
    a->cap = a->cap == 0 ? 8 : a->cap * 2;
    a->data = (AiplVal*)realloc(a->data, sizeof(AiplVal) * a->cap);
  }
  a->data[a->len++] = item;
}
static inline AiplVal aipl_array_pop(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_nil();
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len == 0) return aipl_nil();
  return a->data[--a->len];
}
static inline AiplVal aipl_array_sum(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_int(0);
  AiplArray* a = (AiplArray*)arr_val.ptr;
  int64_t isum = 0; double fsum = 0.0; bool has_float = false;
  for (int64_t i = 0; i < a->len; i++) {
    AiplVal el = a->data[i];
    if (el.kind == AIPL_FLOAT) { has_float = true; fsum += el.f; }
    else if (el.kind == AIPL_INT) { isum += el.i; fsum += (double)el.i; }
  }
  return has_float ? aipl_float(fsum) : aipl_int(isum);
}
static inline AiplVal aipl_array_min(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_int(0);
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len == 0) return aipl_int(0);
  AiplVal best = a->data[0];
  for (int64_t i = 1; i < a->len; i++) {
    if (aipl_truthy(aipl_lt(a->data[i], best))) best = a->data[i];
  }
  return best;
}
static inline AiplVal aipl_array_max(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_int(0);
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len == 0) return aipl_int(0);
  AiplVal best = a->data[0];
  for (int64_t i = 1; i < a->len; i++) {
    if (aipl_truthy(aipl_gt(a->data[i], best))) best = a->data[i];
  }
  return best;
}
static inline AiplVal aipl_val_ints(AiplVal v) {
  AiplVal res = aipl_array_new(NULL, 0);
  if (v.kind == AIPL_STR && v.s) {
    const char* p = v.s;
    while (*p) {
      while (*p && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n' || *p == ',' || *p == ';')) p++;
      if (!*p) break;
      char* endp = NULL;
      long long iv = strtoll(p, &endp, 10);
      if (endp && endp > p) { aipl_array_push(res, aipl_int((int64_t)iv)); p = endp; }
      else p++;
    }
    return res;
  }
  if (v.kind == AIPL_ARRAY && v.ptr) {
    AiplArray* a = (AiplArray*)v.ptr;
    for (int64_t i = 0; i < a->len; i++) {
      AiplVal el = a->data[i];
      if (el.kind == AIPL_INT) aipl_array_push(res, el);
      else if (el.kind == AIPL_FLOAT) aipl_array_push(res, aipl_int((int64_t)el.f));
      else if (el.kind == AIPL_STR && el.s && el.s[0] != 0) aipl_array_push(res, aipl_int((int64_t)atoll(el.s)));
    }
  }
  return res;
}
static inline AiplVal aipl_val_floats(AiplVal v) {
  AiplVal res = aipl_array_new(NULL, 0);
  if (v.kind == AIPL_STR && v.s) {
    const char* p = v.s;
    while (*p) {
      while (*p && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n' || *p == ',' || *p == ';')) p++;
      if (!*p) break;
      char* endp = NULL;
      double dv = strtod(p, &endp);
      if (endp && endp > p) { aipl_array_push(res, aipl_float(dv)); p = endp; }
      else p++;
    }
    return res;
  }
  if (v.kind == AIPL_ARRAY && v.ptr) {
    AiplArray* a = (AiplArray*)v.ptr;
    for (int64_t i = 0; i < a->len; i++) {
      AiplVal el = a->data[i];
      if (el.kind == AIPL_FLOAT) aipl_array_push(res, el);
      else if (el.kind == AIPL_INT) aipl_array_push(res, aipl_float((double)el.i));
      else if (el.kind == AIPL_STR && el.s && el.s[0] != 0) aipl_array_push(res, aipl_float(atof(el.s)));
    }
  }
  return res;
}
AiplVal aipl_array_slice(AiplVal arr_val, AiplVal start_val, AiplVal end_val);
static inline AiplVal aipl_array_join(AiplVal arr_val, AiplVal sep_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_str_lit("");
  AiplArray* a = (AiplArray*)arr_val.ptr;
  if (a->len <= 0) return aipl_str_lit("");
  const char* sep = sep_val.s ? sep_val.s : "";
  size_t sep_len = aipl_str_byte_len(sep_val); size_t total_len = 0;
  const char* stack_strs[64];
  size_t stack_lens[64];
  const char** strs = (a->len <= 64) ? stack_strs : (const char**)malloc(sizeof(const char*) * (size_t)a->len);
  size_t* lens = (a->len <= 64) ? stack_lens : (size_t*)malloc(sizeof(size_t) * (size_t)a->len);
  for (int64_t i = 0; i < a->len; i++) {
    AiplVal s = (a->data[i].kind == AIPL_STR) ? a->data[i] : aipl_to_str(a->data[i]);
    const char* sp = s.s ? s.s : "";
    size_t sl = (s.kind == AIPL_STR && s.extra_i > 0 && s.extra16 == 0) ? (size_t)s.extra_i : strlen(sp);
    strs[i] = sp; lens[i] = sl;
    total_len += sl;
    if (i + 1 < a->len) total_len += sep_len;
  }
  char* buf;
  if (_aipl_arena_depth > 0) {
    buf = (char*)aipl_arena_alloc_raw((int64_t)(total_len + 1));
  } else {
    aipl_prof_record_alloc(total_len + 1);
    buf = (char*)malloc(total_len + 1);
  }
  char* p = buf;
  for (int64_t i = 0; i < a->len; i++) {
    if (lens[i] > 0) { memcpy(p, strs[i], lens[i]); p += lens[i]; }
    if (sep_len > 0 && i + 1 < a->len) { memcpy(p, sep, sep_len); p += sep_len; }
  }
  *p = 0;
  if (strs != stack_strs) free(strs);
  if (lens != stack_lens) free(lens);
  AiplVal res; memset(&res, 0, sizeof(res));
  res.kind = AIPL_STR; res.s = buf; res.extra_i = (total_len > 0) ? (int)total_len : -1;
  return res;
}
AiplVal aipl_array_contains(AiplVal arr_val, AiplVal item);
AiplVal aipl_array_index_of(AiplVal arr_val, AiplVal item);
static inline AiplVal aipl_bytes_from_array(AiplVal arr_val) {
  if (arr_val.kind != AIPL_ARRAY || !arr_val.ptr) return aipl_bytes_new(0);
  AiplArray* a = (AiplArray*)arr_val.ptr;
  AiplVal b_val = aipl_bytes_new(a->len); AiplBytes* b = (AiplBytes*)b_val.ptr;
  for (int64_t i = 0; i < a->len; i++) { b->data[i] = (uint8_t)a->data[i].i; }
  return b_val;
}
AiplVal aipl_bytes_slice(AiplVal b_val, AiplVal start_val, AiplVal end_val);
static inline AiplVal aipl_bytes_read_u16_le(AiplVal b_val, AiplVal offset_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_int(0);
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = offset_val.i;
  if (off < 0 || off + 2 > b->len) return aipl_int(0);
  uint16_t val = (uint16_t)b->data[off] | ((uint16_t)b->data[off+1] << 8);
  return aipl_int((int64_t)val);
}
static inline AiplVal aipl_bytes_read_u16_be(AiplVal b_val, AiplVal offset_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_int(0);
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = offset_val.i;
  if (off < 0 || off + 2 > b->len) return aipl_int(0);
  uint16_t val = ((uint16_t)b->data[off] << 8) | (uint16_t)b->data[off+1];
  return aipl_int((int64_t)val);
}
static inline AiplVal aipl_bytes_read_u32_be(AiplVal b_val, AiplVal offset_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_int(0);
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = offset_val.i;
  if (off < 0 || off + 4 > b->len) return aipl_int(0);
  uint32_t val = ((uint32_t)b->data[off] << 24) | ((uint32_t)b->data[off+1] << 16) |
                 ((uint32_t)b->data[off+2] << 8) | (uint32_t)b->data[off+3];
  return aipl_int((int64_t)val);
}
static inline AiplVal aipl_bytes_read_u32_le(AiplVal b_val, AiplVal offset_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_int(0);
  AiplBytes* b = (AiplBytes*)b_val.ptr; int64_t off = offset_val.i;
  if (off < 0 || off + 4 > b->len) return aipl_int(0);
  uint32_t val = (uint32_t)b->data[off] | ((uint32_t)b->data[off+1] << 8) |
                 ((uint32_t)b->data[off+2] << 16) | ((uint32_t)b->data[off+3] << 24);
  return aipl_int((int64_t)val);
}
AiplVal aipl_rt_readU16LE(AiplVal b, AiplVal off);
AiplVal aipl_rt_readU16BE(AiplVal b, AiplVal off);
AiplVal aipl_rt_readU32BE(AiplVal b, AiplVal off);
AiplVal aipl_rt_readU32LE(AiplVal b, AiplVal off);
AiplVal aipl_str_to_bytes(AiplVal s_val);
static inline void aipl_bytes_ensure_cap(AiplBytes* b, int64_t extra) {
  if (!b) return;
  if (b->len + extra > b->cap) {
    int64_t new_cap = (b->len + extra) * 2;
    if (new_cap < 16) new_cap = 16;
    b->data = (uint8_t*)realloc(b->data, new_cap);
    b->cap = new_cap;
  }
}
static inline AiplVal aipl_rt_byteBufferAlloc(AiplVal cap) {
  int64_t c = (cap.kind == AIPL_INT || cap.kind == AIPL_FLOAT) ? cap.i : 16;
  if (c < 16) c = 16;
  AiplBytes* b = (AiplBytes*)malloc(sizeof(AiplBytes));
  b->len = 0; b->cap = c;
  b->data = (uint8_t*)calloc(c, 1);
  return aipl_ptr_val(AIPL_BYTES, b);
}
AiplVal aipl_bytes_write_u8(AiplVal b_val, AiplVal val);
AiplVal aipl_bytes_write_u16_be(AiplVal b_val, AiplVal val);
AiplVal aipl_bytes_write_u16_be_at(AiplVal b_val, AiplVal off_val, AiplVal val);
AiplVal aipl_bytes_write_u16_le(AiplVal b_val, AiplVal val);
AiplVal aipl_bytes_write_u16_le_at(AiplVal b_val, AiplVal off_val, AiplVal val);
AiplVal aipl_bytes_write_u32_be(AiplVal b_val, AiplVal val);
AiplVal aipl_bytes_write_u32_be_at(AiplVal b_val, AiplVal off_val, AiplVal val);
AiplVal aipl_bytes_write_u32_le(AiplVal b_val, AiplVal val);
AiplVal aipl_bytes_write_u32_le_at(AiplVal b_val, AiplVal off_val, AiplVal val);
static inline AiplVal aipl_bytes_write_bytes(AiplVal b_val, AiplVal other) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return b_val;
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  if (other.kind == AIPL_BYTES && other.ptr) {
    AiplBytes* ob = (AiplBytes*)other.ptr;
    if (ob->len > 0) {
      aipl_bytes_ensure_cap(b, ob->len);
      memcpy(b->data + b->len, ob->data, ob->len);
      b->len += ob->len;
    }
  } else if (other.kind == AIPL_STR && other.s) {
    size_t slen = strlen(other.s);
    if (slen > 0) {
      aipl_bytes_ensure_cap(b, (int64_t)slen);
      memcpy(b->data + b->len, other.s, slen);
      b->len += (int64_t)slen;
    }
  }
  return b_val;
}
AiplVal aipl_bytes_write_string(AiplVal b_val, AiplVal s_val);
static inline AiplVal aipl_bytes_freeze(AiplVal b_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_bytes_new(0);
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  AiplVal clone_val = aipl_bytes_new(b->len);
  AiplBytes* cb = (AiplBytes*)clone_val.ptr;
  if (b->len > 0) memcpy(cb->data, b->data, b->len);
  return clone_val;
}
static inline AiplVal aipl_bytes_to_bytes(AiplVal v) {
  if (v.kind == AIPL_BYTES) return aipl_bytes_freeze(v);
  if (v.kind == AIPL_STR) return aipl_str_to_bytes(v);
  return aipl_bytes_new(0);
}
AiplVal aipl_bytes_set_byte(AiplVal b_val, AiplVal idx_val, AiplVal val);
AiplVal aipl_bytes_copy_from(AiplVal b_val, AiplVal dstOff_val, AiplVal src_val, AiplVal srcOff_val, AiplVal len_val);
AiplVal aipl_bytes_to_array(AiplVal b_val);
AiplVal aipl_rt_ptrAlloc(AiplVal size);
AiplVal aipl_rt_ptrFree(AiplVal ptr);
AiplVal aipl_rt_ptrReadU8(AiplVal ptr, AiplVal offset);
AiplVal aipl_rt_ptrWriteU8(AiplVal ptr, AiplVal offset, AiplVal val);
AiplVal aipl_rt_ptrReadI64(AiplVal ptr, AiplVal offset);
AiplVal aipl_rt_ptrWriteI64(AiplVal ptr, AiplVal offset, AiplVal val);
AiplVal aipl_rt_sizeofType(AiplVal typeName);
AiplVal aipl_rt_bitcastF64ToI64(AiplVal fval);
AiplVal aipl_rt_bitcastI64ToF64(AiplVal ival);
static inline AiplVal aipl_rt_rawSyscall(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4, AiplVal a5, AiplVal a6) {
#if defined(__linux__)
  return aipl_int((int64_t)syscall((long)nr.i, (long)a1.i, (long)a2.i, (long)a3.i, (long)a4.i, (long)a5.i, (long)a6.i));
#else
  (void)nr; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6;
  return aipl_int(-38);
#endif
}
AiplVal aipl_rt_rawSyscall0(AiplVal nr);
AiplVal aipl_rt_rawSyscall1(AiplVal nr, AiplVal a1);
AiplVal aipl_rt_rawSyscall2(AiplVal nr, AiplVal a1, AiplVal a2);
AiplVal aipl_rt_rawSyscall3(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3);
AiplVal aipl_rt_rawSyscall4(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4);
AiplVal aipl_rt_rawSyscall5(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4, AiplVal a5);
AiplVal aipl_rt_rawSyscall6(AiplVal nr, AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4, AiplVal a5, AiplVal a6);
AiplVal aipl_bytes_index_of_byte(AiplVal b_val, AiplVal val, AiplVal fromIdx_val);
AiplVal aipl_bytes_index_of_bytes(AiplVal b_val, AiplVal needle_val, AiplVal fromIdx_val);
static inline AiplVal aipl_bytes_to_hex(AiplVal b_val) {
  if (b_val.kind != AIPL_BYTES || !b_val.ptr) return aipl_str("");
  AiplBytes* b = (AiplBytes*)b_val.ptr; if (b->len <= 0) return aipl_str("");
  char* hex = (char*)malloc(b->len * 2 + 1);
  static const char hexchars[] = "0123456789abcdef";
  for (int64_t i = 0; i < b->len; i++) {
    hex[i * 2] = hexchars[(b->data[i] >> 4) & 0x0F];
    hex[i * 2 + 1] = hexchars[b->data[i] & 0x0F];
  }
  hex[b->len * 2] = 0; AiplVal res = aipl_str(hex); free(hex); return res;
}
AiplVal aipl_bytes_split_byte(AiplVal b_val, AiplVal delim_val);
bool aipl_is_valid_utf8(const uint8_t* data, int64_t len);
AiplVal aipl_bytes_to_utf8_res(AiplVal b_val);
static inline int aipl_hex_digit(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  return -1;
}
static inline AiplVal aipl_hex_to_bytes(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t slen = strlen(s);
  if (slen % 2 != 0) return aipl_err(aipl_str("invalid hex length"));
  int64_t out_len = (int64_t)(slen / 2);
  AiplVal bv = aipl_bytes_new(out_len); AiplBytes* b = (AiplBytes*)bv.ptr;
  for (size_t i = 0; i < slen; i += 2) {
    int d1 = aipl_hex_digit(s[i]); int d2 = aipl_hex_digit(s[i + 1]);
    if (d1 < 0 || d2 < 0) return aipl_err(aipl_str("invalid hex char"));
    b->data[i / 2] = (uint8_t)((d1 << 4) | d2);
  }
  return aipl_ok(bv);
}
static inline AiplVal aipl_rt_bytesZeroed(AiplVal size) {
  int64_t sz = (size.kind == AIPL_INT || size.kind == AIPL_FLOAT) ? size.i : 0;
  if (sz < 0) sz = 0; return aipl_bytes_new(sz);
}
static inline AiplVal aipl_rt_bytesConcat(AiplVal parts_val) {
  if (parts_val.kind != AIPL_ARRAY || !parts_val.ptr) return aipl_bytes_new(0);
  AiplArray* arr = (AiplArray*)parts_val.ptr;
  int64_t total = 0;
  for (int64_t i = 0; i < arr->len; i++) {
    AiplVal item = arr->data[i];
    if (item.kind == AIPL_BYTES && item.ptr) total += ((AiplBytes*)item.ptr)->len;
    else if (item.kind == AIPL_STR && item.s) total += strlen(item.s);
  }
  AiplVal res = aipl_bytes_new(total); AiplBytes* rb = (AiplBytes*)res.ptr; int64_t off = 0;
  for (int64_t i = 0; i < arr->len; i++) {
    AiplVal item = arr->data[i];
    if (item.kind == AIPL_BYTES && item.ptr) {
      AiplBytes* b = (AiplBytes*)item.ptr;
      if (b->len > 0) { memcpy(rb->data + off, b->data, b->len); off += b->len; }
    } else if (item.kind == AIPL_STR && item.s) {
      size_t sl = strlen(item.s);
      if (sl > 0) { memcpy(rb->data + off, item.s, sl); off += (int64_t)sl; }
    }
  }
  return res;
}
static inline AiplVal aipl_rt_bytesFromHex(AiplVal hex_val) {
  AiplVal res = aipl_hex_to_bytes(hex_val);
  if (res.kind == AIPL_RES_OK && res.ptr) return *(AiplVal*)res.ptr;
  return aipl_bytes_new(0);
}
static inline AiplVal aipl_rt_hexEncode(AiplVal b_val) { return aipl_bytes_to_hex(b_val); }
static inline AiplVal aipl_rt_hexDecode(AiplVal hex_val) { return aipl_rt_bytesFromHex(hex_val); }
static inline uint32_t aipl_fnv1a_hash32(const char* s) {
  uint64_t h = 14695981039346656037ULL;
  if (!s) s = "";
  while (*s) {
    h ^= (uint8_t)(*s);
    h *= 1099511628211ULL;
    s++;
  }
  uint32_t h32 = (uint32_t)(h ^ (h >> 32));
  return h32 == 0 ? 1 : h32;
}
void aipl_map_rh_insert(AiplMap* m, uint32_t tag, int32_t dense_idx);
static const char* aipl_to_cstr(AiplVal v);
static inline void aipl_map_rehash(AiplMap* m, int64_t new_cap) {
  if (new_cap < 16) new_cap = 16;
  int64_t p2 = 16;
  while (p2 < new_cap) p2 *= 2;
  new_cap = p2;
  free(m->hash_tags);
  free(m->hash_slots);
  m->hash_cap = new_cap;
  m->hash_tags = (uint32_t*)calloc((size_t)new_cap, sizeof(uint32_t));
  m->hash_slots = (int32_t*)malloc((size_t)new_cap * sizeof(int32_t));
  for (int64_t i = 0; i < new_cap; i++) m->hash_slots[i] = -1;
  for (int64_t i = 0; i < m->len; i++) {
    if (m->keys[i]) {
      uint32_t tag = aipl_fnv1a_hash32(m->keys[i]);
      aipl_map_rh_insert(m, tag, (int32_t)i);
    }
  }
}
static inline int32_t aipl_map_find_slot(AiplMap* m, const char* key, uint32_t tag) {
  if (!m || m->len == 0) return -1;
  if (m->hash_cap == 0 || !m->hash_tags) {
    aipl_map_rehash(m, m->len > 8 ? m->len * 2 : 16);
  }
  int64_t mask = m->hash_cap - 1;
  int64_t slot = (int64_t)(tag & mask);
  int64_t cur_dist = 0;
  while (true) {
    uint32_t occ_tag = m->hash_tags[slot];
    if (occ_tag == 0) return -1;
    int64_t occ_dist = (slot + m->hash_cap - (occ_tag & mask)) & mask;
    if (cur_dist > occ_dist) return -1;
    if (occ_tag == tag) {
      int32_t di = m->hash_slots[slot];
      if (di >= 0 && di < m->len && m->keys[di] && strcmp(m->keys[di], key) == 0) {
        return di;
      }
    }
    slot = (slot + 1) & mask;
    cur_dist++;
  }
}
static inline AiplVal aipl_map_new(void) {
  aipl_prof_record_alloc(sizeof(AiplMap) + sizeof(const char*) * 8 + sizeof(AiplVal) * 8 + sizeof(uint32_t) * 16 + sizeof(int32_t) * 16);
  AiplMap* m = (AiplMap*)malloc(sizeof(AiplMap));
  m->len = 0; m->cap = 8;
  m->keys = (const char**)malloc(sizeof(const char*) * m->cap);
  m->vals = (AiplVal*)malloc(sizeof(AiplVal) * m->cap);
  m->hash_cap = 16;
  m->hash_tags = (uint32_t*)calloc((size_t)m->hash_cap, sizeof(uint32_t));
  m->hash_slots = (int32_t*)malloc((size_t)m->hash_cap * sizeof(int32_t));
  for (int64_t i = 0; i < m->hash_cap; i++) m->hash_slots[i] = -1;
  AiplVal v; memset(&v, 0, sizeof(v)); v.kind = AIPL_MAP; v.ptr = m; return v;
}
static inline void aipl_map_set(AiplVal map_val, AiplVal key_val, AiplVal val) {
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return;
  AiplMap* m = (AiplMap*)map_val.ptr;
  const char* k = aipl_to_cstr(key_val);
  if (!k) k = "";
  uint32_t tag = aipl_fnv1a_hash32(k);
  int32_t existing_idx = aipl_map_find_slot(m, k, tag);
  if (existing_idx >= 0) { m->vals[existing_idx] = val; return; }
  if ((m->len + 1) * 4 > m->hash_cap * 3 || m->hash_cap == 0) {
    int64_t ncap = m->hash_cap == 0 ? 16 : m->hash_cap * 2;
    aipl_map_rehash(m, ncap);
  }
  if (m->len >= m->cap) {
    m->cap = m->cap == 0 ? 8 : m->cap * 2;
    m->keys = (const char**)realloc((void*)m->keys, sizeof(const char*) * m->cap);
    m->vals = (AiplVal*)realloc(m->vals, sizeof(AiplVal) * m->cap);
  }
  int32_t new_idx = (int32_t)m->len;
  m->keys[new_idx] = strdup(k); m->vals[new_idx] = val; m->len++;
  aipl_map_rh_insert(m, tag, new_idx);
}
static inline AiplVal aipl_map_get(AiplVal map_val, const char* key) {
  if (!key) key = "";
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return aipl_none();
  AiplMap* m = (AiplMap*)map_val.ptr;
  uint32_t tag = aipl_fnv1a_hash32(key);
  int32_t idx = aipl_map_find_slot(m, key, tag);
  if (idx >= 0) return aipl_some(m->vals[idx]);
  return aipl_none();
}
AiplVal aipl_map_get_raw(AiplVal map_val, const char* key);
static inline AiplVal aipl_map_contains_key(AiplVal map_val, AiplVal key_val) {
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return aipl_bool(false);
  AiplMap* m = (AiplMap*)map_val.ptr;
  const char* k = aipl_to_cstr(key_val);
  if (!k) k = "";
  uint32_t tag = aipl_fnv1a_hash32(k);
  return aipl_bool(aipl_map_find_slot(m, k, tag) >= 0);
}
AiplVal aipl_map_has(AiplVal map_val, const char* key);
AiplVal aipl_map_remove(AiplVal map_val, const char* key);
static inline AiplVal aipl_map_keys(AiplVal map_val) {
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return aipl_array_new(NULL, 0);
  AiplMap* m = (AiplMap*)map_val.ptr;
  AiplVal* kvals = (AiplVal*)malloc(sizeof(AiplVal) * (m->len > 0 ? m->len : 1));
  for (int64_t i = 0; i < m->len; i++) { kvals[i] = aipl_str(m->keys[i]); }
  AiplVal res = aipl_array_new(kvals, m->len); free(kvals); return res;
}
typedef struct AiplArenaPage {
  uint8_t* buf;
  int64_t offset;
  int64_t cap;
  int64_t base_offset;
  int64_t saved_offset;
  struct AiplArenaPage* next;
} AiplArenaPage;
extern AiplArenaPage* _aipl_arena_head;
extern AiplArenaPage* _aipl_arena_cur_page;
extern AiplArenaPage* _aipl_arena_free_pages;
extern int64_t _aipl_arena_free_count;
extern AiplArenaPage* _aipl_arena_free_checkpoints;
extern int64_t _aipl_arena_free_checkpoint_count;
extern int64_t _aipl_arena_depth;
extern AiplArenaPage* aipl_current_arena;
extern int64_t _aipl_arena_peak;
extern int64_t _aipl_arena_resets;
extern int64_t _aipl_arena_reused_bytes;
extern int64_t _aipl_prof_total_allocs;
extern int64_t _aipl_prof_total_bytes;
void* aipl_arena_alloc_raw(int64_t sz);
void* aipl_arena_alloc_temp(size_t sz);
char* aipl_arena_strdup_temp(const char* s);
void* aipl_rt_arenaAllocBytes(int64_t sz);
AiplArenaPage* aipl_arena_push(void);
void aipl_arena_pop(AiplArenaPage* saved);
bool aipl_ptr_in_arena_frame(AiplArenaPage* saved, const void* ptr);
AiplVal aipl_evacuate_val(AiplArenaPage* saved, AiplVal v);
AiplVal aipl_arena_pop_evacuate(AiplArenaPage* saved, AiplVal ret);
AiplVal aipl_rt_arenaPopEvacuate(AiplVal mark_val, AiplVal ret);
void aipl_print_profile_report(void);
static inline AiplVal aipl_rt_arenaActiveDepth(void) {
  return aipl_int(_aipl_arena_depth);
}
static inline AiplVal aipl_arena_mark(void) {
  if (!_aipl_arena_cur_page) return aipl_int(0);
  return aipl_int(_aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset);
}
static inline AiplVal aipl_arena_reset(AiplVal mark) {
  int64_t before_off = _aipl_arena_cur_page ? (_aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset) : 0;
  int64_t target = mark.i >= 0 ? mark.i : 0;
  _aipl_arena_resets++;
  AiplArenaPage* p = _aipl_arena_head;
  bool found = false;
  while (p) {
    if (target >= p->base_offset && (p->next == NULL || p->next->base_offset < 0 || target < p->base_offset + p->cap)) {
      p->offset = target - p->base_offset;
      _aipl_arena_cur_page = p;
      found = true;
      AiplArenaPage* q = p->next;
      while (q) {
        q->offset = 0;
        q->base_offset = -1;
        q = q->next;
      }
      break;
    }
    p = p->next;
  }
  if (!found && _aipl_arena_head) {
    _aipl_arena_head->offset = 0;
    _aipl_arena_cur_page = _aipl_arena_head;
    AiplArenaPage* q = _aipl_arena_head->next;
    while (q) {
      q->offset = 0;
      q->base_offset = -1;
      q = q->next;
    }
  }
  int64_t cur = _aipl_arena_cur_page ? _aipl_arena_cur_page->base_offset + _aipl_arena_cur_page->offset : 0;
  if (before_off > cur) _aipl_arena_reused_bytes += (before_off - cur);
#if defined(__linux__)
  if (target == 0) {
    malloc_trim(0);
  }
#endif
  return aipl_int(cur);
}
AiplVal aipl_arena_allocated_bytes(void);
AiplVal aipl_arena_alloc(AiplVal sz);
AiplVal aipl_arena_stats(void);
static inline AiplVal aipl_rt_arenaMark(void) { return aipl_arena_mark(); }
static inline AiplVal aipl_rt_arenaReset(AiplVal mark) { return aipl_arena_reset(mark); }
static inline AiplVal aipl_rt_arenaAllocatedBytes(void) { return aipl_arena_allocated_bytes(); }
static inline AiplVal aipl_rt_arenaAlloc(AiplVal sz) { return aipl_arena_alloc(sz); }
static inline AiplVal aipl_rt_arenaStats(void) { return aipl_arena_stats(); }
static inline AiplVal aipl_rt_withScratchArena(AiplVal fn_val) {
  AiplArenaPage* _saved = aipl_arena_push();
  AiplVal _m = aipl_arena_mark();
  AiplVal _res = aipl_nil();
  if (fn_val.kind == AIPL_FUNC && fn_val.ptr) {
    AiplFnPtr fn = (AiplFnPtr)fn_val.ptr;
    _res = fn(1, &_m);
  } else if (fn_val.kind == AIPL_INT) {
    _res = aipl_arena_alloc(fn_val);
  }
  return aipl_arena_pop_evacuate(_saved, _res);
}
static inline const char* aipl_to_cstr(AiplVal v) {
  if (v.kind == AIPL_STR && v.s) return v.s;
  if (v.kind == AIPL_BOOL) return v.i ? "true" : "false";
  if (v.kind == AIPL_NIL) return "nil";
  if (_aipl_arena_depth > 0) {
    char* sbuf = (char*)aipl_arena_alloc_raw(64);
    if (v.kind == AIPL_INT) {
      snprintf(sbuf, 64, "%lld", (long long)v.i);
      return sbuf;
    }
    if (v.kind == AIPL_FLOAT) {
      snprintf(sbuf, 64, "%g", v.f);
      return sbuf;
    }
  }
  return aipl_to_str(v).s;
}
static inline AiplVal aipl_member_len(AiplVal obj) {
  if (obj.kind == AIPL_RES_OK && obj.ptr) return aipl_member_len(*(AiplVal*)obj.ptr);
  if (obj.kind == AIPL_STR) return aipl_int((int64_t)aipl_str_byte_len(obj));
  if (obj.kind == AIPL_ARRAY && obj.ptr) return aipl_int(((AiplArray*)obj.ptr)->len);
  if (obj.kind == AIPL_BYTES && obj.ptr) return aipl_int(((AiplBytes*)obj.ptr)->len);
  if (obj.kind == AIPL_MAP && obj.ptr) return aipl_int(((AiplMap*)obj.ptr)->len);
  if (obj.kind == AIPL_STRUCT && obj.ptr) return aipl_int(((AiplStruct*)obj.ptr)->len);
  return aipl_int(0);
}
static inline int aipl_color_channel_shift(const char* field) {
  if (!field || !field[0] || field[1]) return -1;
  switch (field[0]) { case 'r': return 0; case 'g': return 8; case 'b': return 16; case 'a': return 24; default: return -1; }
}
static inline int aipl_color_channel_from_val(AiplVal v) {
  double d;
  if (v.kind == AIPL_FLOAT) { d = (v.f >= 0.0 && v.f <= 1.0) ? v.f * 255.0 : v.f; }
  else if (v.kind == AIPL_INT || v.kind == AIPL_BOOL) { d = (double)v.i; }
  else { d = 0.0; }
  if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
  return (int)(d + 0.5);
}
static inline AiplVal aipl_color_channel_get(AiplVal c, int shift) { return aipl_float((double)((c.i >> shift) & 0xFF) / 255.0); }
static inline void aipl_color_channel_set(AiplVal* c, int shift, AiplVal v) {
  uint64_t nv = (uint64_t)aipl_color_channel_from_val(v);
  c->i = (int64_t)(((uint64_t)c->i & ~(0xFFULL << shift)) | (nv << shift));
}
static inline AiplVal aipl_member_get(AiplVal obj, const char* field) {
  while ((obj.kind == AIPL_RES_OK || obj.kind == AIPL_OPT_SOME) && obj.ptr) obj = *(AiplVal*)obj.ptr;
  if (obj.kind == AIPL_STRUCT && obj.ptr && field) {
    AiplStruct* st = (AiplStruct*)obj.ptr;
    if (st->names) {
      char c0 = field[0];
      for (int64_t i = 0; i < st->len; i++) {
        const char* fn = st->names[i];
        if (fn && (fn == field || (fn[0] == c0 && strcmp(fn, field) == 0))) return st->vals[i];
      }
    }
  }
  if (obj.extra_i == 0x434F4C52 && field) {
    int sh = aipl_color_channel_shift(field);
    if (sh >= 0) return aipl_color_channel_get(obj, sh);
  }
  if (field && strchr(field, '.')) {
    const char* dot = strchr(field, '.');
    int64_t headLen = (int64_t)(dot - field);
    char head[32];
    if (headLen < 31) {
      memcpy(head, field, headLen); head[headLen] = 0;
      AiplVal sub = aipl_member_get(obj, head);
      return aipl_member_get(sub, dot + 1);
    }
  }
  if (field && field[0] == 'f' && field[1] == 0 && (obj.kind == AIPL_INT || obj.kind == AIPL_FLOAT)) {
    return aipl_float(aipl_as_float(obj));
  }
  if (field && field[0] == 'i' && field[1] == 0 && (obj.kind == AIPL_INT || obj.kind == AIPL_FLOAT || obj.kind == AIPL_BOOL)) {
    return aipl_int(aipl_as_int(obj));
  }
  if (field && (obj.kind == AIPL_INT || obj.kind == AIPL_FLOAT)) {
    if (strcmp(field, "round") == 0) return aipl_int((int64_t)llround(aipl_as_float(obj)));
    if (strcmp(field, "floor") == 0) return aipl_int((int64_t)floor(aipl_as_float(obj)));
    if (strcmp(field, "ceil") == 0) return aipl_int((int64_t)ceil(aipl_as_float(obj)));
  }
  if (field && (strcmp(field, "len") == 0 || strcmp(field, "length") == 0)) return aipl_member_len(obj);
  if (obj.kind == AIPL_ARRAY && obj.ptr && field) {
    AiplArray* a = (AiplArray*)obj.ptr;
    if (strcmp(field, "last") == 0 || strcmp(field, "peek") == 0) return a->len > 0 ? a->data[a->len - 1] : aipl_int(0);
    if (strcmp(field, "first") == 0) return a->len > 0 ? a->data[0] : aipl_int(0);
    if (strcmp(field, "sum") == 0) return aipl_array_sum(obj);
    if (strcmp(field, "min") == 0) return aipl_array_min(obj);
    if (strcmp(field, "max") == 0) return aipl_array_max(obj);
    if (field[0] >= '0' && field[0] <= '9') {
      int64_t idx = atoll(field);
      if (idx >= 0 && idx < a->len) return a->data[idx];
      return aipl_nil();
    }
  }
  if (obj.kind == AIPL_MAP && obj.ptr) {
    AiplMap* m = (AiplMap*)obj.ptr;
    const char* k = field ? field : "";
    uint32_t tag = aipl_fnv1a_hash32(k);
    int32_t idx = aipl_map_find_slot(m, k, tag);
    if (idx >= 0) return m->vals[idx];
    return aipl_nil();
  }
  return aipl_nil();
}
AIPL_HOT_INLINE AiplVal aipl_member_get_idx(AiplVal obj, int64_t idx, const char* fallback_field) {
  if (obj.kind == AIPL_STRUCT && obj.ptr) {
    AiplStruct* st = (AiplStruct*)obj.ptr;
    if (st->names && idx >= 0 && idx < st->len) {
      const char* fn = st->names[idx];
      if (fn && (fn == fallback_field || (fallback_field && fn[0] == fallback_field[0] && strcmp(fn, fallback_field) == 0))) {
        return st->vals[idx];
      }
    }
  }
  return aipl_member_get(obj, fallback_field);
}
static inline void aipl_member_set_val(AiplVal st, const char* field, AiplVal val) {
  if (st.kind == AIPL_STRUCT && st.ptr) {
    AiplStruct* s = (AiplStruct*)st.ptr;
    if (s->names) {
      char c0 = (field && field[0]) ? field[0] : 0;
      for (int64_t i = 0; i < s->len; i++) {
        const char* fn = s->names[i];
        if (fn && (fn == field || (fn[0] == c0 && strcmp(fn, field) == 0))) { s->vals[i] = val; return; }
      }
    }
    int64_t nl = s->len + 1;
    if (s->names == (const char**)((char*)s + sizeof(AiplStruct)) || s->vals == (AiplVal*)((char*)s + sizeof(AiplStruct))) {
      const char** on = s->names; AiplVal* ov = s->vals;
      s->names = (const char**)malloc(sizeof(const char*) * nl);
      s->vals = (AiplVal*)malloc(sizeof(AiplVal) * nl);
      if (on) {
        for (int64_t i = 0; i < s->len; i++) { s->names[i] = on[i]; s->vals[i] = ov[i]; }
      } else {
        for (int64_t i = 0; i < s->len; i++) { s->names[i] = ""; s->vals[i] = ov ? ov[i] : aipl_nil(); }
      }
    } else {
      s->names = (const char**)realloc((void*)s->names, sizeof(const char*) * nl);
      s->vals = (AiplVal*)realloc(s->vals, sizeof(AiplVal) * nl);
    }
    s->names[s->len] = strdup(field); s->vals[s->len] = val; s->len = nl; return;
  }
  if (st.kind == AIPL_MAP && st.ptr) { aipl_map_set(st, aipl_str(field), val); }
}
AIPL_HOT_INLINE void aipl_member_set_idx(AiplVal st, int64_t idx, const char* fallback_field, AiplVal val) {
  if (st.kind == AIPL_STRUCT && st.ptr) {
    AiplStruct* s = (AiplStruct*)st.ptr;
    if (s->names && idx >= 0 && idx < s->len) {
      const char* fn = s->names[idx];
      if (fn && (fn == fallback_field || (fallback_field && fn[0] == fallback_field[0] && strcmp(fn, fallback_field) == 0))) {
        s->vals[idx] = val;
        return;
      }
    }
  }
  aipl_member_set_val(st, fallback_field, val);
}
static inline void aipl_member_set(AiplVal* obj, const char* field, AiplVal val) {
  if (!obj) return;
  if (obj->extra_i == 0x434F4C52) { int sh = aipl_color_channel_shift(field); if (sh >= 0) { aipl_color_channel_set(obj, sh, val); return; } }
  aipl_member_set_val(*obj, field, val);
}
void aipl_array_member_op_set(AiplVal arr, AiplVal idx, const char* field, AiplVal rhs, int op);
AiplVal aipl_rt_cloneStruct(AiplVal s);
AiplVal aipl_struct_spread(AiplVal base, const char* type_name, int64_t count, const char** names, const AiplVal* vals);
AiplVal aipl_rt_eachLine(AiplVal text_or_path, AiplVal cb);
AIPL_HOT_INLINE AiplVal aipl_index_get(AiplVal obj, AiplVal idx) {
  int64_t i = idx.i;
  while (obj.kind == AIPL_RES_OK && obj.ptr) obj = *(AiplVal*)obj.ptr;
  if (obj.kind == AIPL_ARRAY && obj.ptr) {
    AiplArray* a = (AiplArray*)obj.ptr;
    if (i < 0) i += a->len;
    if ((uint64_t)i < (uint64_t)a->len) return a->data[i];
    return aipl_nil();
  }
  if (obj.kind == AIPL_STR && obj.s) {
    size_t sl = strlen(obj.s);
    if (i < 0) i += (int64_t)sl;
    if (i < 0 || (size_t)i >= sl) return aipl_str("");
    char buf[2] = { obj.s[i], 0 }; return aipl_str_n(buf, 1);
  }
  if (obj.kind == AIPL_BYTES && obj.ptr) {
    AiplBytes* b = (AiplBytes*)obj.ptr;
    if (i < 0) i += b->len;
    if ((uint64_t)i < (uint64_t)b->len) return aipl_int((int64_t)b->data[i]);
    return aipl_int(0);
  }
  if (obj.kind == AIPL_MAP && obj.ptr) {
    const char* k = aipl_to_cstr(idx);
    return aipl_map_get(obj, k);
  }
  if (obj.kind == AIPL_STRUCT && obj.ptr && idx.kind == AIPL_STR && idx.s) {
    AiplVal opts = aipl_member_get(obj, "options");
    if (opts.kind == AIPL_MAP && opts.ptr) return aipl_map_get(opts, idx.s);
    return aipl_member_get(obj, idx.s);
  }
  return aipl_nil();
}
AIPL_HOT_INLINE void aipl_index_set_val(AiplVal arr, AiplVal idx, AiplVal val) {
  int64_t i = idx.i;
  if (arr.kind == AIPL_ARRAY && arr.ptr) {
    AiplArray* a = (AiplArray*)arr.ptr;
    if (i < 0) i += a->len;
    if ((uint64_t)i < (uint64_t)a->len) a->data[i] = val;
    return;
  }
  if (arr.kind == AIPL_BYTES && arr.ptr) {
    AiplBytes* b = (AiplBytes*)arr.ptr;
    if (i < 0) i += b->len;
    if ((uint64_t)i < (uint64_t)b->len) b->data[i] = (uint8_t)val.i;
    return;
  }
  if (arr.kind == AIPL_MAP && arr.ptr) {
    aipl_map_set(arr, idx, val);
  }
}
static inline void aipl_index_set(AiplVal* obj, AiplVal idx, AiplVal val) {
  if (!obj) return;
  aipl_index_set_val(*obj, idx, val);
}
static inline AiplVal aipl_index_2d_get(AiplVal grid, AiplVal r, AiplVal c) {
  if (grid.kind == AIPL_ARRAY) return aipl_index_get(aipl_index_get(grid, r), c);
  if (grid.kind == AIPL_STRUCT) {
    AiplVal w = aipl_member_get(grid, "width");
    if (w.kind == AIPL_NIL) w = aipl_member_get(grid, "cols");
    AiplVal arr = aipl_member_get(grid, "data");
    if (arr.kind == AIPL_NIL) arr = aipl_member_get(grid, "cells");
    return aipl_index_get(arr, aipl_int(r.i * w.i + c.i));
  }
  return aipl_nil();
}
static inline void aipl_index_2d_set(AiplVal grid, AiplVal r, AiplVal c, AiplVal val) {
  if (grid.kind == AIPL_ARRAY) { aipl_index_set_val(aipl_index_get(grid, r), c, val); return; }
  if (grid.kind == AIPL_STRUCT) {
    AiplVal w = aipl_member_get(grid, "width");
    if (w.kind == AIPL_NIL) w = aipl_member_get(grid, "cols");
    AiplVal arr = aipl_member_get(grid, "data");
    if (arr.kind == AIPL_NIL) arr = aipl_member_get(grid, "cells");
    aipl_index_set_val(arr, aipl_int(r.i * w.i + c.i), val); return;
  }
}
AiplVal aipl_vec_repeat(AiplVal val, AiplVal count);
AiplVal aipl_str_slice(AiplVal s_val, AiplVal start_val, AiplVal end_val);
static inline AiplVal aipl_str_split(AiplVal s_val, AiplVal delim_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* delim = delim_val.s ? delim_val.s : "";
  size_t slen = aipl_str_byte_len(s_val); size_t dlen = aipl_str_byte_len(delim_val);
  if (dlen == 0) {
    AiplVal* chars = (AiplVal*)malloc(sizeof(AiplVal) * (slen > 0 ? slen : 1));
    for (size_t i = 0; i < slen; i++) { chars[i] = aipl_str_n(s + i, 1); }
    AiplVal res = aipl_array_new(chars, (int64_t)slen); free(chars); return res;
  }
  int64_t count = 0; int64_t cap = 8;
  AiplVal* parts = (AiplVal*)malloc(sizeof(AiplVal) * cap);
  size_t start = 0;
  for (size_t i = 0; i + dlen <= slen; ) {
    if (memcmp(s + i, delim, dlen) == 0) {
      if (count >= cap) { cap *= 2; parts = (AiplVal*)realloc(parts, sizeof(AiplVal) * cap); }
      parts[count++] = aipl_str_n(s + start, (int64_t)(i - start));
      i += dlen; start = i;
    } else { i++; }
  }
  if (count >= cap) { cap += 1; parts = (AiplVal*)realloc(parts, sizeof(AiplVal) * cap); }
  parts[count++] = aipl_str_n(s + start, (int64_t)(slen - start));
  AiplVal res = aipl_array_new(parts, count); free(parts); return res;
}
AiplVal aipl_str_bytes(AiplVal s_val);
static inline AiplVal aipl_str_lines(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t len = strlen(s);
  if (len == 0) return aipl_array_new(NULL, 0);
  int64_t cap = 16; AiplVal* lns = (AiplVal*)malloc(sizeof(AiplVal) * cap);
  int64_t count = 0; size_t start = 0;
  for (size_t i = 0; i < len; i++) {
    if (s[i] == '\n') {
      size_t line_len = i - start;
      if (line_len > 0 && s[i - 1] == '\r') line_len--;
      if (count >= cap) { cap *= 2; lns = (AiplVal*)realloc(lns, sizeof(AiplVal) * cap); }
      lns[count++] = aipl_str_n(s + start, (int64_t)line_len);
      start = i + 1;
    }
  }
  if (start < len) {
    size_t line_len = len - start;
    if (line_len > 0 && s[len - 1] == '\r') line_len--;
    if (count >= cap) { cap *= 2; lns = (AiplVal*)realloc(lns, sizeof(AiplVal) * cap); }
    lns[count++] = aipl_str_n(s + start, (int64_t)line_len);
  }
  AiplVal res = aipl_array_new(lns, count); free(lns); return res;
}
AiplVal aipl_str_words(AiplVal s_val);
AiplVal aipl_str_skip_fields(AiplVal s_val, AiplVal n_val);
AiplVal aipl_str_split_any(AiplVal s_val, AiplVal delims_val);
AiplVal aipl_str_parse_float_prefix(AiplVal s_val);
AiplVal aipl_str_truncate(AiplVal s_val, AiplVal max_val, AiplVal ell_val);
AiplVal aipl_str_strip_prefix(AiplVal s_val, AiplVal pfx_val);
AiplVal aipl_str_remove_prefixes(AiplVal s_val, AiplVal pfxs_val);
AiplVal aipl_str_strip_suffix(AiplVal s_val, AiplVal suf_val);
AiplVal aipl_str_between(AiplVal s_val, AiplVal open_val, AiplVal close_val);
AiplVal aipl_str_starts_with_offset(AiplVal s_val, AiplVal pfx_val, AiplVal off_val);
AiplVal aipl_str_split_once(AiplVal s_val, AiplVal delim_val);
AiplVal aipl_str_replace_first(AiplVal s_val, AiplVal old_val, AiplVal new_val);
AiplVal aipl_str_replace_nth(AiplVal s_val, AiplVal old_val, AiplVal new_val, AiplVal nth_val);
AiplVal aipl_str_equals_ignore_case(AiplVal a_val, AiplVal b_val);
AiplVal aipl_str_contains_ignore_case(AiplVal s_val, AiplVal sub_val);
AiplVal aipl_str_index_of_ignore_case(AiplVal s_val, AiplVal sub_val);
AiplVal aipl_str_is_digit(AiplVal s_val);
AiplVal aipl_str_is_hex_digit(AiplVal s_val);
AiplVal aipl_str_is_alpha(AiplVal s_val);
AiplVal aipl_str_is_alphanumeric(AiplVal s_val);
AiplVal aipl_str_is_ident_char(AiplVal s_val);
AiplVal aipl_str_is_whitespace(AiplVal s_val);
static inline AiplVal aipl_str_replace(AiplVal s_val, AiplVal old_val, AiplVal new_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* old_s = old_val.s ? old_val.s : ""; const char* new_s = new_val.s ? new_val.s : "";
  size_t slen = aipl_str_byte_len(s_val); size_t old_len = aipl_str_byte_len(old_val); size_t new_len = aipl_str_byte_len(new_val);
  if (old_len == 0) return s_val;
  int occurrences = 0;
  for (size_t i = 0; i + old_len <= slen; ) {
    if (memcmp(s + i, old_s, old_len) == 0) { occurrences++; i += old_len; } else { i++; }
  }
  size_t new_total = slen + (size_t)occurrences * (new_len - old_len);
  char* result = (char*)malloc(new_total + 1); char* dst = result; size_t last = 0;
  for (size_t i = 0; i + old_len <= slen; ) {
    if (memcmp(s + i, old_s, old_len) == 0) {
      size_t n = i - last; memcpy(dst, s + last, n); dst += n; memcpy(dst, new_s, new_len); dst += new_len;
      i += old_len; last = i;
    } else { i++; }
  }
  size_t n = slen - last; memcpy(dst, s + last, n); dst += n; *dst = 0;
  AiplVal res = aipl_str_n(result, (int64_t)new_total); free(result); return res;
}
static inline AiplVal aipl_str_trim(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : "";
  while (*s && (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r')) s++;
  if (!*s) return aipl_str("");
  const char* end = s + strlen(s) - 1;
  while (end > s && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) end--;
  size_t len = end - s + 1; char* buf = (char*)malloc(len + 1);
  memcpy(buf, s, len); buf[len] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
}
static inline AiplVal aipl_str_starts_with(AiplVal s_val, AiplVal prefix_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* p = prefix_val.s ? prefix_val.s : "";
  size_t sl = aipl_str_byte_len(s_val); size_t pl = aipl_str_byte_len(prefix_val);
  if (pl > sl) return aipl_bool(false);
  return aipl_bool(memcmp(s, p, pl) == 0);
}
static inline AiplVal aipl_str_ends_with(AiplVal s_val, AiplVal suffix_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* suf = suffix_val.s ? suffix_val.s : "";
  size_t sl = aipl_str_byte_len(s_val); size_t sufl = aipl_str_byte_len(suffix_val);
  if (sufl > sl) return aipl_bool(false);
  return aipl_bool(memcmp(s + sl - sufl, suf, sufl) == 0);
}
AiplVal aipl_str_contains(AiplVal s_val, AiplVal sub_val);
AiplVal aipl_str_index_of(AiplVal s_val, AiplVal sub_val);
AiplVal aipl_str_last_index_of(AiplVal s_val, AiplVal sub_val);
static inline AiplVal aipl_str_index_of_from(AiplVal s_val, AiplVal sub_val, AiplVal start_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* sub = sub_val.s ? sub_val.s : "";
  size_t sl = aipl_str_byte_len(s_val); size_t subl = aipl_str_byte_len(sub_val);
  int64_t start = start_val.i;
  if (start < 0) start = 0;
  if (subl == 0) return aipl_int(start <= (int64_t)sl ? start : (int64_t)sl);
  if (subl > sl || (size_t)start + subl > sl) return aipl_int(-1);
  const char* found = strstr(s + start, sub);
  return found ? aipl_int((int64_t)(found - s)) : aipl_int(-1);
}
AiplVal aipl_str_chars(AiplVal s_val);
AiplVal aipl_clone(AiplVal v);
AiplVal aipl_set_new(void);
void aipl_set_add(AiplVal s, AiplVal v);
AiplVal aipl_set_from_array(AiplVal arr_val);
AiplVal aipl_to_array(AiplVal v);
void aipl_array_insert(AiplVal arr_val, AiplVal idx_val, AiplVal item);
void aipl_container_insert(AiplVal coll, AiplVal a, AiplVal b);
void aipl_container_add(AiplVal coll, AiplVal a);
static inline void aipl_container_set(AiplVal coll, AiplVal k, AiplVal v) {
  if (coll.kind == AIPL_MAP) { aipl_map_set(coll, k, v); }
  else if (coll.kind == AIPL_ARRAY || coll.kind == AIPL_BYTES) { aipl_index_set_val(coll, k, v); }
}
static inline AiplVal aipl_container_get(AiplVal coll, AiplVal key) {
  if (coll.kind == AIPL_MAP && coll.ptr) {
    const char* k = aipl_to_cstr(key);
    return aipl_map_get(coll, k);
  }
  if (coll.kind == AIPL_ARRAY && coll.ptr) {
    AiplArray* a = (AiplArray*)coll.ptr; int64_t i = key.i;
    if (i >= 0 && i < a->len) return aipl_some(a->data[i]);
    return aipl_none();
  }
  if (coll.kind == AIPL_BYTES && coll.ptr) {
    AiplBytes* b = (AiplBytes*)coll.ptr; int64_t i = key.i;
    if (i >= 0 && i < b->len) return aipl_some(aipl_int((int64_t)b->data[i]));
    return aipl_none();
  }
  return aipl_none();
}
AiplVal aipl_get_or(AiplVal coll, AiplVal key, AiplVal def);
AiplVal aipl_map_get_or_insert(AiplVal map_val, AiplVal key, AiplVal def);
void aipl_map_group_by_append(AiplVal map_val, AiplVal key_val, AiplVal elem_val);
AiplVal aipl_array_first(AiplVal arr_val);
AiplVal aipl_array_last(AiplVal arr_val);
AiplVal aipl_array_head(AiplVal arr_val, AiplVal n_val);
AiplVal aipl_array_tail(AiplVal arr_val);
AiplVal aipl_array_tail_n(AiplVal arr_val, AiplVal n_val);
AiplVal aipl_array_chunks(AiplVal arr_val, AiplVal size_val);
AiplVal aipl_array_windows(AiplVal arr_val, AiplVal size_val);
AiplVal aipl_array_shift(AiplVal arr_val);
AiplVal aipl_array_unshift(AiplVal arr_val, AiplVal item);
AiplVal aipl_array_swap_remove(AiplVal arr_val, AiplVal idx_val);
AiplVal aipl_array_extend(AiplVal arr_val, AiplVal other_val);
AiplVal aipl_array_or_str_reverse(AiplVal v);
AiplVal aipl_array_or_str_reversed(AiplVal v);
AiplVal aipl_array_copy_within(AiplVal arr_val, AiplVal target_val, AiplVal start_val, AiplVal end_val);
AiplVal aipl_array_unique(AiplVal arr_val);
AiplVal aipl_array_sort(AiplVal arr_val);
AiplVal aipl_rt_roundTo(AiplVal x, AiplVal n);
AiplVal aipl_rt_remEuclid(AiplVal a, AiplVal b);
AiplVal aipl_rt_popcnt(AiplVal x);
AiplVal aipl_rt_ctz(AiplVal x);
AiplVal aipl_rt_clz(AiplVal x);
AiplVal aipl_rt_charFromCode(AiplVal x);
static inline AiplVal aipl_str_char_code_at(AiplVal s_val, AiplVal idx_val) {
  const char* s = s_val.s ? s_val.s : ""; int64_t i = idx_val.i; size_t slen = aipl_str_byte_len(s_val);
  if (i < 0 || (size_t)i >= slen) return aipl_int(0);
  return aipl_int((uint8_t)s[i]);
}
static inline AiplVal aipl_str_to_lower(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t len = strlen(s);
  char* buf = (char*)malloc(len + 1);
  for (size_t i = 0; i < len; i++) { buf[i] = (char)tolower((unsigned char)s[i]); }
  buf[len] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
}
AiplVal aipl_str_to_upper(AiplVal s_val);
static inline AiplVal aipl_slice(AiplVal v, AiplVal start, AiplVal end) {
  if (end.i < 0) {
    if (v.kind == AIPL_STR) end = aipl_int((int64_t)aipl_str_byte_len(v));
    else if (v.kind == AIPL_ARRAY && v.ptr) end = aipl_int(((AiplArray*)v.ptr)->len);
    else if (v.kind == AIPL_BYTES && v.ptr) end = aipl_int(((AiplBytes*)v.ptr)->len);
  }
  if (v.kind == AIPL_STR) return aipl_str_slice(v, start, end);
  if (v.kind == AIPL_ARRAY) return aipl_array_slice(v, start, end);
  if (v.kind == AIPL_BYTES) return aipl_bytes_slice(v, start, end);
  return aipl_nil();
}
static inline AiplVal aipl_contains(AiplVal v, AiplVal item) {
  if (v.kind == AIPL_STR) return aipl_str_contains(v, item);
  if (v.kind == AIPL_ARRAY) return aipl_array_contains(v, item);
  if (v.kind == AIPL_MAP) return aipl_map_contains_key(v, item);
  return aipl_bool(false);
}
static inline AiplVal aipl_index_of(AiplVal v, AiplVal item) {
  if (v.kind == AIPL_STR) return aipl_str_index_of(v, item);
  if (v.kind == AIPL_ARRAY) return aipl_array_index_of(v, item);
  return aipl_int(-1);
}
static inline AiplVal aipl_opt_is_some(AiplVal v) {
  if (v.kind == AIPL_OPT_SOME) return aipl_bool(1);
  if (v.kind == AIPL_OPT_NONE) return aipl_bool(0);
  if (v.kind == AIPL_STRUCT && v.ptr) {
    const char* tn = ((AiplStruct*)v.ptr)->type_name;
    if (tn && (strcmp(tn, "Some") == 0 || strstr(tn, "::Some"))) return aipl_bool(1);
    if (tn && (strcmp(tn, "None") == 0 || strstr(tn, "::None"))) return aipl_bool(0);
    AiplVal has_v = aipl_member_get(v, "has_value");
    if (has_v.kind != AIPL_NIL) return aipl_bool(aipl_truthy(has_v));
    AiplVal is_s = aipl_member_get(v, "is_some");
    if (is_s.kind != AIPL_NIL) return aipl_bool(aipl_truthy(is_s));
  }
  return aipl_bool(v.kind != AIPL_NIL);
}
static inline AiplVal aipl_opt_is_none(AiplVal v) {
  if (v.kind == AIPL_OPT_NONE) return aipl_bool(1);
  if (v.kind == AIPL_OPT_SOME) return aipl_bool(0);
  if (v.kind == AIPL_STRUCT && v.ptr) {
    const char* tn = ((AiplStruct*)v.ptr)->type_name;
    if (tn && (strcmp(tn, "None") == 0 || strstr(tn, "::None"))) return aipl_bool(1);
    if (tn && (strcmp(tn, "Some") == 0 || strstr(tn, "::Some"))) return aipl_bool(0);
    AiplVal has_v = aipl_member_get(v, "has_value");
    if (has_v.kind != AIPL_NIL) return aipl_bool(!aipl_truthy(has_v));
    AiplVal is_s = aipl_member_get(v, "is_some");
    if (is_s.kind != AIPL_NIL) return aipl_bool(!aipl_truthy(is_s));
  }
  return aipl_bool(v.kind == AIPL_NIL);
}
static inline AiplVal aipl_res_is_ok(AiplVal v) {
  if (v.kind == AIPL_RES_OK) return aipl_bool(1);
  if (v.kind == AIPL_RES_ERR) return aipl_bool(0);
  if (v.kind == AIPL_STRUCT && v.ptr) {
    const char* tn = ((AiplStruct*)v.ptr)->type_name;
    if (tn && (strcmp(tn, "Ok") == 0 || strstr(tn, "::Ok"))) return aipl_bool(1);
    if (tn && (strcmp(tn, "Err") == 0 || strstr(tn, "::Err"))) return aipl_bool(0);
    AiplVal is_ok = aipl_member_get(v, "is_ok");
    if (is_ok.kind != AIPL_NIL) return aipl_bool(aipl_truthy(is_ok));
  }
  return aipl_bool(v.kind != AIPL_RES_ERR && v.kind != AIPL_NIL);
}
static inline AiplVal aipl_res_is_err(AiplVal v) {
  if (v.kind == AIPL_RES_ERR) return aipl_bool(1);
  if (v.kind == AIPL_RES_OK) return aipl_bool(0);
  if (v.kind == AIPL_STRUCT && v.ptr) {
    const char* tn = ((AiplStruct*)v.ptr)->type_name;
    if (tn && (strcmp(tn, "Err") == 0 || strstr(tn, "::Err"))) return aipl_bool(1);
    if (tn && (strcmp(tn, "Ok") == 0 || strstr(tn, "::Ok"))) return aipl_bool(0);
    AiplVal is_ok = aipl_member_get(v, "is_ok");
    if (is_ok.kind != AIPL_NIL) return aipl_bool(!aipl_truthy(is_ok));
  }
  return aipl_bool(0);
}
#define aipl_is_some aipl_opt_is_some
#define aipl_is_none aipl_opt_is_none
#define aipl_is_ok aipl_res_is_ok
#define aipl_is_err aipl_res_is_err
static inline AiplVal aipl_unwrap(AiplVal v) {
  if ((v.kind == AIPL_RES_OK || v.kind == AIPL_OPT_SOME) && v.ptr) return *(AiplVal*)v.ptr;
  if (v.kind == AIPL_STRUCT && v.ptr) {
    AiplVal inner = aipl_member_get(v, "value");
    if (inner.kind != AIPL_NIL) return inner;
    AiplVal data = aipl_member_get(v, "data");
    if (data.kind != AIPL_NIL) return data;
    AiplVal ok_v = aipl_member_get(v, "ok");
    if (ok_v.kind != AIPL_NIL) return ok_v;
    return v;
  }
  if (v.kind != AIPL_RES_ERR && v.kind != AIPL_OPT_NONE && v.kind != AIPL_NIL) return v;
  fprintf(stderr, "Runtime Error: unwrap() called on non-Ok/non-Some\n"); exit(1);
}
static inline AiplVal aipl_unwrap_err(AiplVal v) {
  if (v.kind == AIPL_RES_ERR && v.ptr) return *(AiplVal*)v.ptr;
  return v;
}
AiplVal aipl_opt_unwrap_or(AiplVal v, AiplVal def);
#define aipl_unwrap_or aipl_opt_unwrap_or
AiplVal aipl_expect(AiplVal v, AiplVal msg);
AiplVal aipl_enum_name(AiplVal v);
AiplVal aipl_parse_int_res(AiplVal sVal);
AiplVal aipl_parse_float_res(AiplVal sVal);
AiplVal aipl_to_int_opt(AiplVal recv);
AiplVal aipl_to_float_opt(AiplVal recv);
static inline AiplVal aipl_enum_variant(const char* name, int64_t argc, const AiplVal* args) {
  if (argc == 0) return aipl_str(name ? name : "");
  AiplVal argsArr = aipl_array_new(args, argc);
  const char** names = (const char**)malloc(sizeof(const char*) * (argc + 1));
  AiplVal* vals = (AiplVal*)malloc(sizeof(AiplVal) * (argc + 1));
  names[0] = "__enum_args__"; vals[0] = argsArr;
  for (int64_t i = 0; i < argc; i++) {
    char buf[32]; snprintf(buf, sizeof(buf), "_%lld", (long long)i);
    names[i + 1] = strdup(buf); vals[i + 1] = args ? args[i] : aipl_nil();
  }
  AiplVal res = aipl_struct_new(name, argc + 1, names, vals);
  free(names); free(vals); return res;
}
AiplVal aipl_unwrap_at(AiplVal v, int64_t idx);
AiplVal aipl_match_arm(AiplVal target, const char* pat);
static inline AiplVal aipl_print(AiplVal v) {
  AiplVal s = aipl_to_str(v); printf("%s", s.s ? s.s : ""); fflush(stdout); return aipl_nil();
}
static inline AiplVal aipl_println(AiplVal v) {
  AiplVal s = aipl_to_str(v); printf("%s\n", s.s ? s.s : ""); fflush(stdout); return aipl_nil();
}
static inline AiplVal aipl_rt_assert(AiplVal cond, const char* msg) {
  if (!aipl_truthy(cond)) {
    fprintf(stderr, "Assertion failed%s%s\n", (msg && msg[0]) ? ": " : "", msg ? msg : "");
    exit(1);
  }
  return aipl_nil();
}
extern int g_aipl_argc;
extern char** g_aipl_argv;
AiplVal aipl_rt_userArgs(void);
AiplVal aipl_rt_getEnv(AiplVal key);
AiplVal aipl_rt_setEnv(AiplVal key, AiplVal val);
AiplVal aipl_rt_cwd(void);
AiplVal aipl_rt_homeDir(void);
AiplVal aipl_rt_tempDir(void);
AiplVal aipl_rt_fileExists(AiplVal path_val);
AiplVal aipl_rt_realpath(AiplVal path_val);
AiplVal aipl_rt_readFile(AiplVal path_val);
AiplVal aipl_rt_writeFile(AiplVal path_val, AiplVal content_val);
AiplVal aipl_rt_readBytes(AiplVal path_val);
AiplVal aipl_rt_writeBytes(AiplVal path_val, AiplVal data_val);
AiplVal aipl_find_embedded_asset(const char* query_path, AiplArray* list_out);
static inline AiplVal aipl_rt_loadAsset(AiplVal path) {
  const char* p = path.s ? path.s : "";
  AiplVal emb = aipl_find_embedded_asset(p, NULL);
  if (emb.kind == AIPL_RES_OK) return emb;
  if (aipl_rt_fileExists(path).b) { return aipl_rt_readBytes(path); }
  return aipl_err(aipl_str("asset not found"));
}
static inline AiplVal aipl_rt_assetExists(AiplVal path) {
  AiplVal res = aipl_rt_loadAsset(path); return aipl_bool(res.kind == AIPL_RES_OK);
}
AiplVal aipl_rt_listAssets(void);
AiplVal aipl_rt_removeFile(AiplVal path_val);
int aipl_remove_dir_recursive(const char* path);
AiplVal aipl_rt_removeDirAll(AiplVal path_val);
AiplVal aipl_rt_isDir(AiplVal path_val);
AiplVal aipl_rt_mkdir(AiplVal path_val);
int aipl_cmp_str(const void* a, const void* b);
AiplVal aipl_rt_listDir(AiplVal path_val);
static inline AiplVal aipl_make_file_stat(const char* path, const struct stat* st) {
  const char* p = path ? path : "";
  const char* lastSlash = strrchr(p, '/');
  const char* name = lastSlash ? (lastSlash + 1) : p;
  const char* names[10] = {
    "path", "name", "size", "isDir", "isFile", "isSymlink", "mode", "mtimeMs", "atimeMs", "ctimeMs"
  };
  AiplVal vals[10];
  vals[0] = aipl_str(p);
  vals[1] = aipl_str(name);
  vals[2] = aipl_int((int64_t)st->st_size);
  vals[3] = aipl_bool(S_ISDIR(st->st_mode));
  vals[4] = aipl_bool(S_ISREG(st->st_mode));
  vals[5] = aipl_bool(S_ISLNK(st->st_mode));
  vals[6] = aipl_int((int64_t)st->st_mode);
  vals[7] = aipl_int((int64_t)st->st_mtime * 1000);
  vals[8] = aipl_int((int64_t)st->st_atime * 1000);
  vals[9] = aipl_int((int64_t)st->st_ctime * 1000);
  return aipl_struct_new("FileStat", 10, names, vals);
}
AiplVal aipl_rt_stat(AiplVal p);
AiplVal aipl_rt_readDir(AiplVal path_val);
void aipl_walk_dir_rec(const char* dir_path, AiplVal* arr_val);
AiplVal aipl_rt_walkDir(AiplVal path_val);
AiplVal aipl_rt_setFileTimes(AiplVal p, AiplVal atimeMs, AiplVal mtimeMs);
AiplVal aipl_rt_appendFile(AiplVal p, AiplVal c);
AiplVal aipl_rt_pathJoin(AiplVal a_val, AiplVal b_val);
AiplVal aipl_rt_pathBasename(AiplVal p_val);
AiplVal aipl_rt_pathDirname(AiplVal p_val);
AiplVal aipl_rt_pathExtname(AiplVal p_val);
AiplVal aipl_rt_pathExtension(AiplVal p_val);
AiplVal aipl_rt_pathExt(AiplVal p_val);
AiplVal aipl_rt_pathStem(AiplVal p_val);
AiplVal aipl_rt_pathIsAbsolute(AiplVal p_val);
AiplVal aipl_rt_pathNormalize(AiplVal p_val);
extern int g_aipl_cmd_seq;
AiplVal aipl_rt_execCommand(AiplVal cmd_val, AiplVal args_val);
AiplVal aipl_rt_exit(AiplVal code);
AiplVal aipl_rt_panic(AiplVal msg);
AiplVal aipl_rt_hardware_concurrency(void);
AiplVal aipl_rt_exec_parallel(AiplVal cmds_val, AiplVal max_jobs_val);
AiplVal aipl_rt_nowMs(void);
AiplVal aipl_rt_nowUnixMs(void);
AiplVal aipl_rt_nowMonoNs(void);
AiplVal aipl_rt_sleepMs(AiplVal ms_val);
#define AIPL_ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define AIPL_CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define AIPL_MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define AIPL_SIG0(x) (AIPL_ROTR(x, 2) ^ AIPL_ROTR(x, 13) ^ AIPL_ROTR(x, 22))
#define AIPL_SIG1(x) (AIPL_ROTR(x, 6) ^ AIPL_ROTR(x, 11) ^ AIPL_ROTR(x, 25))
#define AIPL_sig0(x) (AIPL_ROTR(x, 7) ^ AIPL_ROTR(x, 18) ^ ((x) >> 3))
#define AIPL_sig1(x) (AIPL_ROTR(x, 17) ^ AIPL_ROTR(x, 19) ^ ((x) >> 10))
void aipl_sha256_raw(const uint8_t* data, size_t len, uint8_t out[32]);
AiplVal aipl_rt_sha256(AiplVal data_val);
AiplVal aipl_rt_sha256Bytes(AiplVal data_val);
AiplVal aipl_rt_crc32(AiplVal data_val);
#define AIPL_ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define AIPL_MD5_F(x,y,z) (((x) & (y)) | ((~x) & (z)))
#define AIPL_MD5_G(x,y,z) (((x) & (z)) | ((y) & (~z)))
#define AIPL_MD5_H(x,y,z) ((x) ^ (y) ^ (z))
#define AIPL_MD5_I(x,y,z) ((y) ^ ((x) | (~z)))
void aipl_md5_calc(const uint8_t* data, size_t len, char out[33]);
AiplVal aipl_rt_md5(AiplVal data_val);
void aipl_sha1_calc(const uint8_t* data, size_t len, char out[41]);
AiplVal aipl_rt_sha1(AiplVal data_val);
void aipl_hmac_sha256_raw(const uint8_t* key, size_t key_len, const uint8_t* data, size_t data_len, uint8_t out[32]);
AiplVal aipl_rt_hmacSha256(AiplVal key_val, AiplVal msg_val);
AiplVal aipl_rt_hmacSha256Hex(AiplVal key_val, AiplVal msg_val);
AiplVal aipl_rt_constantTimeEq(AiplVal a_val, AiplVal b_val);
void aipl_pbkdf2_hmac_sha256(const uint8_t* pass, size_t pass_len, const uint8_t* salt, size_t salt_len, size_t iterations, size_t out_len, uint8_t* out);
AiplVal aipl_rt_pbkdf2HmacSha256(AiplVal pass_val, AiplVal salt_val, AiplVal iter_val, AiplVal outlen_val);
uint8_t* aipl_deflate_raw(const uint8_t* data, size_t len, size_t* out_len);
AiplVal aipl_rt_deflateRaw(AiplVal data_val);
uint8_t* aipl_inflate_raw(const uint8_t* data, size_t len, size_t* out_len, int* ok);
AiplVal aipl_rt_inflateRaw(AiplVal data_val);
uint32_t aipl_adler32(const uint8_t* data, size_t len);
uint8_t* aipl_zlib_compress(const uint8_t* data, size_t len, size_t* out_len);
AiplVal aipl_rt_zlibCompress(AiplVal data_val);
uint8_t* aipl_zlib_decompress(const uint8_t* data, size_t len, size_t* out_len, int* ok);
AiplVal aipl_rt_zlibDecompress(AiplVal data_val);
AiplVal aipl_rt_bytesNew(AiplVal size);
AiplVal aipl_rt_bytesFromArray(AiplVal arr);
AiplVal aipl_rt_Ok(AiplVal v);
AiplVal aipl_rt_Err(AiplVal v);
AiplVal aipl_rt_Some(AiplVal v);
AiplVal aipl_rt_None(void);
double aipl_to_c_double(AiplVal v);
AiplVal aipl_str_char_at(AiplVal s_val, AiplVal idx_val);
AiplVal aipl_str_repeat(AiplVal s_val, AiplVal count_val);
AiplVal aipl_str_trim_start(AiplVal s_val);
AiplVal aipl_str_trim_end(AiplVal s_val);
AiplVal aipl_str_pad_start(AiplVal s_val, AiplVal len_val, AiplVal pad_val);
AiplVal aipl_str_pad_end(AiplVal s_val, AiplVal len_val, AiplVal pad_val);
AiplVal aipl_container_clear(AiplVal c);
AiplVal aipl_container_remove(AiplVal c, AiplVal key_or_val);
AiplVal aipl_map_values(AiplVal map_val);
AiplVal aipl_rt_args(void);
AiplVal aipl_rt_env(AiplVal key);
AiplVal aipl_rt_eprint(AiplVal v);
AiplVal aipl_rt_eprintln(AiplVal v);
AiplVal aipl_rt_printInline(AiplVal v);
AiplVal aipl_rt_flushStdout(void);
AiplVal aipl_rt_readStdin(void);
AiplVal aipl_rt_readLine(void);
AiplVal aipl_rt_chr(AiplVal n);
AiplVal aipl_rt_fromCharCode(AiplVal n);
AiplVal aipl_rt_ord(AiplVal s);
AiplVal aipl_rt_charCode(AiplVal s);
AiplVal aipl_rt_parseInt(AiplVal s);
AiplVal aipl_rt_parseFloat(AiplVal s);
AiplVal aipl_rt_toString(AiplVal v);
AiplVal aipl_rt_formatFloat(AiplVal v, AiplVal decimals);
AiplVal aipl_rt_toHex(AiplVal n);
AiplVal aipl_rt_mkdirAll(AiplVal p);
AiplVal aipl_rt_deleteFile(AiplVal p);
AiplVal aipl_rt_fileSize(AiplVal p);
AiplVal aipl_rt_isFile(AiplVal p);
AiplVal aipl_rt_copyFile(AiplVal src_val, AiplVal dst_val);
AiplVal aipl_rt_renameFile(AiplVal old_p, AiplVal new_p);
AiplVal aipl_rt_tcpListen(AiplVal host, AiplVal port);
AiplVal aipl_rt_tcpLocalPort(AiplVal sock);
AiplVal aipl_rt_tcpConnect(AiplVal host, AiplVal port, AiplVal timeoutMs);
AiplVal aipl_rt_tcpAccept(AiplVal listener);
AiplVal aipl_rt_tcpRead(AiplVal sock, AiplVal maxBytes);
AiplVal aipl_rt_tcpWrite(AiplVal sock, AiplVal data);
AiplVal aipl_rt_tcpClose(AiplVal sock);
AiplVal aipl_rt_udpBind(AiplVal host, AiplVal port);
AiplVal aipl_rt_udpSendTo(AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4);
AiplVal aipl_rt_udpRecvFrom(AiplVal sock, AiplVal maxBytes);
AiplVal aipl_rt_udpClose(AiplVal sock);
AiplVal aipl_rt_pi(void);
AiplVal aipl_rt_sin(AiplVal v);
AiplVal aipl_rt_cos(AiplVal v);
AiplVal aipl_rt_tan(AiplVal v);
AiplVal aipl_rt_asin(AiplVal v);
AiplVal aipl_rt_acos(AiplVal v);
AiplVal aipl_rt_atan(AiplVal v);
AiplVal aipl_rt_atan2(AiplVal y, AiplVal x);
AiplVal aipl_rt_sqrt(AiplVal v);
AiplVal aipl_rt_pow(AiplVal b, AiplVal e);
AiplVal aipl_rt_floor(AiplVal v);
AiplVal aipl_rt_ceil(AiplVal v);
AiplVal aipl_rt_round(AiplVal v);
AiplVal aipl_rt_abs(AiplVal v);
AiplVal aipl_rt_absInt(AiplVal v);
AiplVal aipl_rt_absFloat(AiplVal v);
AiplVal aipl_rt_min(AiplVal a, AiplVal b);
AiplVal aipl_rt_max(AiplVal a, AiplVal b);
AiplVal aipl_rt_minInt(AiplVal a, AiplVal b);
AiplVal aipl_rt_maxInt(AiplVal a, AiplVal b);
AiplVal aipl_rt_minFloat(AiplVal a, AiplVal b);
AiplVal aipl_rt_maxFloat(AiplVal a, AiplVal b);
AiplVal aipl_rt_clamp(AiplVal v, AiplVal lo, AiplVal hi);
AiplVal aipl_rt_clampInt(AiplVal v, AiplVal lo, AiplVal hi);
AiplVal aipl_rt_clampFloat(AiplVal v, AiplVal lo, AiplVal hi);
AiplVal aipl_rt_lerp(AiplVal a, AiplVal b, AiplVal t);
AiplVal aipl_rt_limitVal(AiplVal v, AiplVal lo, AiplVal hi);
AiplVal aipl_rt_mixVal(AiplVal a, AiplVal b, AiplVal t);
AiplVal aipl_rt_log(AiplVal v);
AiplVal aipl_rt_log2(AiplVal v);
AiplVal aipl_rt_log10(AiplVal v);
AiplVal aipl_rt_exp(AiplVal v);
AiplVal aipl_rt_randomInt(AiplVal min_val, AiplVal max_val);
AiplVal aipl_rt_randInt(AiplVal min_val, AiplVal max_val);
AiplVal aipl_rt_randomIntRange(AiplVal min_val, AiplVal max_val);
AiplVal aipl_rt_randomFloat(void);
AiplVal aipl_rt_randFloat(void);
typedef struct { char* data; size_t len; size_t cap; } AiplJsonBuf;
void aipl_jbuf_init(AiplJsonBuf* b);
void aipl_jbuf_append(AiplJsonBuf* b, const char* s);
void aipl_jbuf_append_char(AiplJsonBuf* b, char c);
void aipl_jbuf_append_str_lit(AiplJsonBuf* b, const char* s);
void aipl_json_stringify_val(AiplJsonBuf* b, AiplVal v);
AiplVal aipl_rt_jsonStringify(AiplVal v);
AiplVal aipl_val_to_json(AiplVal v);
const char* aipl_json_skip_ws(const char* p);
AiplVal aipl_json_parse_val(const char** pp);
AiplVal aipl_json_parse_str(const char** pp);
AiplVal aipl_json_parse_num(const char** pp);
AiplVal aipl_json_parse_arr(const char** pp);
AiplVal aipl_json_parse_obj(const char** pp);
AiplVal aipl_json_parse_val(const char** pp);
AiplVal aipl_rt_jsonParse(AiplVal s_val);
AiplVal aipl_rt_jsonGet(AiplVal jsonVal, AiplVal keyVal);
extern void** _aipl_ffi_handles;
extern int _aipl_ffi_cap;
extern int _aipl_ffi_count;
AiplVal aipl_rt_ffiOpen(AiplVal libPath);
AiplVal aipl_rt_ffiHasSymbol(AiplVal hVal, AiplVal symVal);
AiplVal aipl_rt_ffiCallInt(AiplVal hVal, AiplVal symVal, AiplVal argsVal);
AiplVal aipl_rt_ffiCallFloat(AiplVal hVal, AiplVal symVal, AiplVal argsVal);
AiplVal aipl_rt_ffiCallStr(AiplVal hVal, AiplVal symVal, AiplVal argVal);
AiplVal aipl_rt_ffiClose(AiplVal hVal);
AiplVal aipl_rt_getCompositionText(void);
AiplVal aipl_rt_getCompositionCursor(void);
AiplVal aipl_rt_getClipboardText(void);
AiplVal aipl_rt_setClipboardText(AiplVal text);
AiplVal aipl_rt_isGpuAccelerated(void);
AiplVal aipl_rt_getGraphicsBackendName(void);
AiplVal aipl_rt_setSoftwareRasterizer(AiplVal force);
AiplVal aipl_rt_setWindowMode(AiplVal mode);
AiplVal aipl_rt_getWindowMode(void);
void aipl_unpack_color(AiplVal c, uint8_t* r, uint8_t* g, uint8_t* b, uint8_t* a);
#ifdef AIPL_ENABLE_GUI_AUDIO
extern uint8_t* _aipl_canvas_fb;
extern uint32_t* _aipl_x11_bgra;
extern int _aipl_canvas_w;
extern int _aipl_canvas_h;
extern int _aipl_window_backend;
extern int _aipl_requested_window_mode;
extern int _aipl_cli_window_mode_override;
extern char _aipl_window_mode_name[16];
extern int _aipl_ipc_telemetry_active;
extern int _aipl_multi_seat_active;
extern int _aipl_window_resized;
extern int _aipl_window_min_w;
extern int _aipl_window_min_h;
void _aipl_audio_mix_samples(int16_t* out_stereo, int frames);
extern int _aipl_audio_thread_active;
void _aipl_init_audio(void);
void _aipl_stop_and_cleanup_audio(void);
extern int _aipl_video_recording;
AiplVal aipl_rt_recordVideoFrame(void);
AiplVal aipl_rt_stopVideoRecording(void);
AiplVal aipl_rt_startVideoRecording(AiplVal path, AiplVal fps);
AiplVal aipl_rt_saveScreenshot(AiplVal path);
extern char _aipl_win_title[256];
extern int _aipl_ipc_record_frames_remaining;
extern char _aipl_ipc_ack_path[256];
extern int _aipl_single_instance_mode;
extern int _aipl_instance_lock_fd;
extern int _aipl_atexit_registered;
extern char (*_aipl_font_paths)[512];
extern char (*_aipl_image_paths)[512];
extern void* _aipl_x11_lib;
extern void* _aipl_x11_dpy;
extern unsigned long _aipl_x11_win;
extern void* _aipl_x11_gc;
extern void* _aipl_x11_img;
extern void* _aipl_xext_lib;
extern int _aipl_xshm_available;
extern int _aipl_xshm_active;
extern int _aipl_xshm_attached;
extern void* _aipl_gl_lib;
extern void* _aipl_glx_ctx;
extern uint64_t _aipl_gl_frame_hash;
void _aipl_alloc_x11_image_and_fb(int w, int h);
void _aipl_destroy_x11_image_and_fb(void);
void _aipl_sync_gl_to_fb(void);
extern unsigned long _aipl_wm_delete;
extern int _aipl_window_closed;
extern int _aipl_frames;
extern int _aipl_events_pumped_this_frame;
extern int _aipl_target_fps;
extern double _aipl_frame_dt;
extern int64_t _aipl_last_frame_ns;
extern int _aipl_benchmark_window_fps;
extern int _aipl_unlocked_fps;
extern int _aipl_window_pos_manual;
extern int _aipl_win_x;
extern int _aipl_win_y;
extern int _aipl_depth_test_enabled;
extern int _aipl_ui_tracking_enabled;
extern int _aipl_cur_blend_mode;
extern int _aipl_cli_max_fps_override;
extern int _aipl_fps_cli_checked;
extern int64_t _aipl_bench_start_ns;
extern double _aipl_current_fps;
extern double _aipl_frame_time_ms;
void _aipl_check_fps_cli_flags(void);
extern uint8_t _aipl_key_down[512];
extern uint8_t _aipl_key_pressed[512];
extern uint8_t _aipl_key_released[512];
extern int _aipl_last_key_pressed;
extern int _aipl_mouse_x;
extern int _aipl_mouse_y;
extern uint8_t _aipl_mouse_down[8];
extern uint8_t _aipl_mouse_pressed[8];
extern uint8_t _aipl_mouse_released[8];
extern double _aipl_mouse_wheel;
extern char* _aipl_text_input_buf;
extern size_t _aipl_text_input_cap;
void _aipl_text_input_clear(void);
void _aipl_text_input_append(const char* s, size_t n);
extern int _aipl_bot_active_click_frame;
extern int _aipl_bot_active_key_slot;
extern int _aipl_bot_active_key_frame[512];
extern int _aipl_bot_active_mouse_frame[8];
extern int _aipl_shot_taken;
extern int _aipl_max_frames_checked;
extern int _aipl_max_frames_limit;
int _aipl_get_max_frames_limit(void);
#ifndef _WIN32
typedef struct { int type; unsigned long serial; int send_event; void* display; unsigned long window; unsigned long root; unsigned long subwindow; unsigned long time; int x, y; int x_root, y_root; unsigned int state; unsigned int keycode; int same_screen; } AiplXKeyEvent;
typedef struct { int type; unsigned long serial; int send_event; void* display; unsigned long window; unsigned long root; unsigned long subwindow; unsigned long time; int x, y; int x_root, y_root; unsigned int state; unsigned int button; int same_screen; } AiplXButtonEvent;
typedef struct { int type; unsigned long serial; int send_event; void* display; unsigned long window; unsigned long root; unsigned long subwindow; unsigned long time; int x, y; int x_root, y_root; unsigned int state; char is_hint; int same_screen; } AiplXMotionEvent;
typedef struct { int type; unsigned long serial; int send_event; void* display; unsigned long event; unsigned long window; int x, y; int width, height; int border_width; unsigned long above; int override_redirect; } AiplXConfigureEvent;
typedef struct { int type; unsigned long serial; int send_event; void* display; unsigned long window; int x, y; int width, height; int count; } AiplXExposeEvent;
typedef struct { int type; unsigned long serial; int send_event; void* display; unsigned long window; unsigned long message_type; int format; union { char b[20]; short s[10]; long l[5]; } data; } AiplXClientMessageEvent;
typedef union { int type; AiplXKeyEvent xkey; AiplXButtonEvent xbutton; AiplXMotionEvent xmotion; AiplXConfigureEvent xconfigure; AiplXExposeEvent xexpose; AiplXClientMessageEvent xclient; long pad[24]; } AiplXEvent;
extern void* (*_aipl_X11_XOpenDisplay)(const char*);
extern int (*_aipl_X11_XCloseDisplay)(void*);
extern int (*_aipl_X11_XFlush)(void*);
extern int (*_aipl_X11_XPending)(void*);
extern int (*_aipl_X11_XNextEvent)(void*, void*);
extern int (*_aipl_X11_XPeekEvent)(void*, void*);
extern int (*_aipl_X11_XDefaultScreen)(void*);
extern unsigned long (*_aipl_X11_XRootWindow)(void*, int);
extern void* (*_aipl_X11_XDefaultVisual)(void*, int);
extern int (*_aipl_X11_XDefaultDepth)(void*, int);
extern unsigned long (*_aipl_X11_XBlackPixel)(void*, int);
extern unsigned long (*_aipl_X11_XCreateSimpleWindow)(void*, unsigned long, int, int, unsigned int, unsigned int, unsigned int, unsigned long, unsigned long);
extern int (*_aipl_X11_XMapWindow)(void*, unsigned long);
extern int (*_aipl_X11_XDestroyWindow)(void*, unsigned long);
extern int (*_aipl_X11_XStoreName)(void*, unsigned long, const char*);
extern int (*_aipl_X11_XSelectInput)(void*, unsigned long, long);
extern unsigned long (*_aipl_X11_XInternAtom)(void*, const char*, int);
extern int (*_aipl_X11_XSetWMProtocols)(void*, unsigned long, unsigned long*, int);
extern void* (*_aipl_X11_XCreateGC)(void*, unsigned long, unsigned long, void*);
extern int (*_aipl_X11_XFreeGC)(void*, void*);
extern void* (*_aipl_X11_XCreateImage)(void*, void*, unsigned int, int, int, char*, unsigned int, unsigned int, int, int);
extern int (*_aipl_X11_XPutImage)(void*, unsigned long, void*, void*, int, int, int, int, unsigned int, unsigned int);
extern int (*_aipl_X11_XResizeWindow)(void*, unsigned long, unsigned int, unsigned int);
extern int (*_aipl_X11_XMoveWindow)(void*, unsigned long, int, int);
extern unsigned long (*_aipl_X11_XLookupKeysym)(void*, int);
extern int (*_aipl_X11_XSync)(void*, int);
extern int (*_aipl_X11_XFree)(void*);
typedef struct { unsigned long shmseg; int shmid; char* shmaddr; int readOnly; } _AiplXShmSegmentInfo;
extern _AiplXShmSegmentInfo _aipl_xshm_info;
extern int (*_aipl_XShmQueryExtension)(void*);
extern void* (*_aipl_XShmCreateImage)(void*, void*, unsigned int, int, char*, _AiplXShmSegmentInfo*, unsigned int, unsigned int);
extern int (*_aipl_XShmAttach)(void*, _AiplXShmSegmentInfo*);
extern int (*_aipl_XShmDetach)(void*, _AiplXShmSegmentInfo*);
extern int (*_aipl_XShmPutImage)(void*, unsigned long, void*, void*, int, int, int, int, unsigned int, unsigned int, int);
extern void* (*_aipl_glXChooseVisual)(void*, int, int*);
extern void* (*_aipl_glXCreateContext)(void*, void*, void*, int);
extern int (*_aipl_glXMakeCurrent)(void*, unsigned long, void*);
extern void (*_aipl_glXSwapBuffers)(void*, unsigned long);
extern void (*_aipl_glXDestroyContext)(void*, void*);
extern void* (*_aipl_glXGetProcAddress)(const unsigned char*);
extern void (*_aipl_glXSwapIntervalEXT)(void*, unsigned long, int);
extern int (*_aipl_glXSwapIntervalMESA)(unsigned int);
extern int (*_aipl_glXSwapIntervalSGI)(int);
extern void (*_aipl_glViewport)(int, int, int, int);
extern void (*_aipl_glMatrixMode)(unsigned int);
extern void (*_aipl_glLoadIdentity)(void);
extern void (*_aipl_glOrtho)(double, double, double, double, double, double);
extern void (*_aipl_glClearColor)(float, float, float, float);
extern void (*_aipl_glClear)(unsigned int);
extern void (*_aipl_glEnable)(unsigned int);
extern void (*_aipl_glDisable)(unsigned int);
extern void (*_aipl_glBlendFunc)(unsigned int, unsigned int);
extern void (*_aipl_glScissor)(int, int, int, int);
extern void (*_aipl_glVertexPointer)(int, unsigned int, int, const void*);
extern void (*_aipl_glColorPointer)(int, unsigned int, int, const void*);
extern void (*_aipl_glTexCoordPointer)(int, unsigned int, int, const void*);
extern void (*_aipl_glEnableClientState)(unsigned int);
extern void (*_aipl_glDisableClientState)(unsigned int);
extern void (*_aipl_glDrawArrays)(unsigned int, int, int);
extern void (*_aipl_glReadPixels)(int, int, int, int, unsigned int, unsigned int, void*);
extern void (*_aipl_glDepthFunc)(unsigned int);
extern void (*_aipl_glDepthMask)(unsigned char);
extern void (*_aipl_glClearDepth)(double);
extern void (*_aipl_glColorMask)(unsigned char, unsigned char, unsigned char, unsigned char);
extern void (*_aipl_glShadeModel)(unsigned int);
extern void (*_aipl_glGenTextures)(int, unsigned int*);
extern void (*_aipl_glDeleteTextures)(int, const unsigned int*);
extern void (*_aipl_glBindTexture)(unsigned int, unsigned int);
extern void (*_aipl_glTexImage2D)(unsigned int, int, int, int, int, int, unsigned int, unsigned int, const void*);
extern void (*_aipl_glTexParameteri)(unsigned int, unsigned int, int);
extern void (*_aipl_glAlphaFunc)(unsigned int, float);
#endif
int _aipl_x11_keysym_to_slot(unsigned long ks);
int _aipl_key_val_to_slot(AiplVal k);
void _aipl_resize_framebuffer(int w, int h);
void _aipl_execute_bot_action(const char* act, const char* param);
void _aipl_parse_bot_script(const char* bot_script);
void _aipl_pump_events(void);
extern char _aipl_pending_ipc_script[4096];
typedef struct { int x, y, w, h, active; } AiplScissorRect;
extern AiplScissorRect _aipl_scissor_stack[8];
extern int _aipl_scissor_sp;
extern int _aipl_scissor_x;
extern int _aipl_scissor_y;
extern int _aipl_scissor_w;
extern int _aipl_scissor_h;
extern int _aipl_scissor_active;
void aipl_ensure_canvas_fb(void);
void aipl_canvas_set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void _aipl_cleanup_window_registry(void);
void _aipl_write_window_info(void);
void _aipl_compute_initial_window_pos(int w, int h, int screenW, int screenH, int* out_x, int* out_y);
void _aipl_sg_reset_frame(void);
void _aipl_sg_record_rect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, int is_rounded);
void _aipl_sg_record_circle(int cx, int cy, int rad, uint8_t r, uint8_t g, uint8_t b);
void _aipl_sg_record_text(const char* s, int x, int y, double sz, uint8_t r, uint8_t g, uint8_t b);
void _aipl_write_window_state_json(void);
int _aipl_resolve_window_target(const char* target, int* out_pid);
AiplVal aipl_rt_setSingleInstance(AiplVal enabled);
AiplVal aipl_rt_isSingleInstance(void);
AiplVal aipl_rt_setWindowPosition(AiplVal x_val, AiplVal y_val);
AiplVal aipl_rt_targetWindowScreenshot(AiplVal target_v, AiplVal outPath_v);
AiplVal aipl_rt_targetWindowRecord(AiplVal target_v, AiplVal outPath_v, AiplVal frames_v, AiplVal fps_v);
AiplVal aipl_rt_targetWindowAction(AiplVal target_v, AiplVal script_v);
AiplVal aipl_rt_targetWindowSeatAction(AiplVal target_v, AiplVal seat_v, AiplVal script_v);
AiplVal aipl_rt_publishBotState(AiplVal key_v, AiplVal jsonVal_v);
AiplVal aipl_rt_publishTurnState(AiplVal activeSeat_v, AiplVal phase_v, AiplVal winnerSeat_v);
AiplVal aipl_rt_listRunningWindows(void);
#endif // AIPL_ENABLE_GUI_AUDIO
#ifndef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_targetWindowSeatAction(AiplVal target_v, AiplVal seat_v, AiplVal script_v);
AiplVal aipl_rt_publishBotState(AiplVal key_v, AiplVal jsonVal_v);
AiplVal aipl_rt_publishTurnState(AiplVal activeSeat_v, AiplVal phase_v, AiplVal winnerSeat_v);
#endif
#ifdef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_closeWindow(void);
AiplVal aipl_rt_initWindow(AiplVal w, AiplVal h, AiplVal title);
AiplVal aipl_rt_initCanvas(AiplVal w, AiplVal h);
AiplVal aipl_rt_closeWindow(void);
AiplVal aipl_rt_canvasBackendName(void);
AiplVal aipl_rt_isHeadlessMode(void);
AiplVal aipl_rt_setTargetFps(AiplVal fps);
AiplVal aipl_rt_setMaxFps(AiplVal fps);
AiplVal aipl_rt_getMaxFps(void);
AiplVal aipl_rt_getCurrentFps(void);
AiplVal aipl_rt_getFrameTimeMs(void);
AiplVal aipl_rt_setWindowTitle(AiplVal title);
AiplVal aipl_rt_setWindowSize(AiplVal w, AiplVal h);
AiplVal aipl_rt_isWindowResized(void);
AiplVal aipl_rt_setWindowMinSize(AiplVal w, AiplVal h);
AiplVal aipl_rt_getContentScale(void);
AiplVal aipl_rt_windowShouldClose(void);
AiplVal aipl_rt_getScreenWidth(void);
AiplVal aipl_rt_getScreenHeight(void);
AiplVal aipl_rt_getFrameTime(void);
AiplVal aipl_rt_getScaleFactor(void);
AiplVal aipl_rt_beginDrawing(void);
int _aipl_save_fb_to_ppm(const char* ppm_path);
AiplVal aipl_rt_endDrawing(void);
AiplVal aipl_rt_beginFrame(void);
AiplVal aipl_rt_endFrame(void);
AiplVal aipl_rt_getPixel(AiplVal x_v, AiplVal y_v);
AiplVal aipl_rt_gameLoop(AiplVal fn_val);
AiplVal aipl_rt_clearScreen(AiplVal c);
AiplVal aipl_rt_clearBackground(AiplVal c);
AiplVal aipl_rt_clearCanvas(AiplVal c);
AiplVal aipl_rt_rgba(AiplVal r, AiplVal g, AiplVal b, AiplVal a);
AiplVal aipl_rt_rgb(AiplVal r, AiplVal g, AiplVal b);
AiplVal aipl_rt_drawRect(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c);
AiplVal _aipl_rt_drawRect_va(int argc, const AiplVal* args);
AiplVal aipl_rt_drawRectAlpha(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c, AiplVal alpha_v);
AiplVal aipl_rt_drawRect8(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal r, AiplVal g, AiplVal b, AiplVal a);
AiplVal aipl_rt_drawRectOutline(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c);
AiplVal aipl_rt_drawRectOutline6(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal th, AiplVal c);
AiplVal aipl_rt_drawRectLines(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c);
AiplVal aipl_rt_drawRectLines6(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal th, AiplVal c);
#define _aipl_draw_rect_outline_GET(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define _aipl_draw_rect_outline_var(...) _aipl_draw_rect_outline_GET(__VA_ARGS__, aipl_rt_drawRectOutline6, aipl_rt_drawRectOutline)(__VA_ARGS__)
int _aipl_is_likely_color(AiplVal v);
AiplVal _aipl_rt_drawRoundedRect_va(int argc, const AiplVal* args);
AiplVal _aipl_rt_drawRoundedRectOutline_va(int argc, const AiplVal* args);
#define aipl_rt_drawRoundedRect(...) _aipl_rt_drawRoundedRect_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawRoundedRectOutline(...) _aipl_rt_drawRoundedRectOutline_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
AiplVal aipl_rt_drawCircle(AiplVal cx_v, AiplVal cy_v, AiplVal r_v, AiplVal c);
AiplVal _aipl_rt_drawCircle_va(int argc, const AiplVal* args);
AiplVal _aipl_rt_drawCircleOutline_va(int argc, const AiplVal* args);
#define aipl_rt_drawCircleOutline(...) _aipl_rt_drawCircleOutline_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawCircleLines(...) _aipl_rt_drawCircleOutline_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
AiplVal aipl_rt_drawLine6(AiplVal x1_v, AiplVal y1_v, AiplVal x2_v, AiplVal y2_v, AiplVal c, AiplVal th_v);
AiplVal aipl_rt_drawLine(AiplVal x1_v, AiplVal y1_v, AiplVal x2_v, AiplVal y2_v, AiplVal c);
AiplVal _aipl_rt_drawLine_va(int argc, const AiplVal* args);
AiplVal _aipl_rt_drawTriangle_va(int argc, const AiplVal* args);
AiplVal _aipl_rt_drawTriangleLines_va(int argc, const AiplVal* args);
#define aipl_rt_drawTriangle(...) _aipl_rt_drawTriangle_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawTriangleOutline(...) _aipl_rt_drawTriangleLines_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawTriangleLines(...) _aipl_rt_drawTriangleLines_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
typedef struct {
  double x_bearing;
  double y_bearing;
  double width;
  double height;
  double x_advance;
  double y_advance;
} _AiplCairoTextExtents;
extern void* _aipl_cairo_lib;
extern void* _aipl_ft_lib;
extern void* _aipl_ft_handle;
extern void** _aipl_font_faces;
extern int _aipl_font_faces_cap;
void _aipl_ensure_font_slot(int slot);
extern int _aipl_active_font_id;
extern void* _aipl_scratch_surface;
extern void* _aipl_scratch_cr;
extern unsigned char* _aipl_scratch_data;
extern int _aipl_scratch_stride;
#define _AIPL_SCRATCH_W 1024
#define _AIPL_SCRATCH_H 160
extern void* (*_aipl_cairo_image_surface_create)(int, int, int);
extern void (*_aipl_cairo_surface_destroy)(void*);
extern void (*_aipl_cairo_surface_flush)(void*);
extern unsigned char* (*_aipl_cairo_image_surface_get_data)(void*);
extern int (*_aipl_cairo_image_surface_get_stride)(void*);
extern void* (*_aipl_cairo_create)(void*);
extern void (*_aipl_cairo_destroy)(void*);
extern void (*_aipl_cairo_select_font_face)(void*, const char*, int, int);
extern void (*_aipl_cairo_set_font_face)(void*, void*);
extern void (*_aipl_cairo_set_font_size)(void*, double);
extern void (*_aipl_cairo_set_source_rgba)(void*, double, double, double, double);
extern void (*_aipl_cairo_move_to)(void*, double, double);
extern void (*_aipl_cairo_show_text)(void*, const char*);
extern void (*_aipl_cairo_text_extents)(void*, const char*, _AiplCairoTextExtents*);
extern void* (*_aipl_cairo_ft_font_face_create_for_ft_face)(void*, int);
extern void (*_aipl_cairo_paint)(void*);
extern void (*_aipl_cairo_set_operator)(void*, int);
extern int (*_aipl_FT_Init_FreeType)(void**);
extern int (*_aipl_FT_New_Face)(void*, const char*, long, void**);
int _aipl_load_font_face_into_slot(int slot, const char* path);
extern int _aipl_ttf_initialized;
void _aipl_init_ttf(void);
double _aipl_ttf_pixel_size(double sz);
void _aipl_sanitize_utf8(const char* src, char* dst, size_t dst_size);
int _aipl_font_scale_from_size(double sz);
void _aipl_measure_ttf(const char* s, double sz, double* out_w, double* out_h);
void _aipl_draw_text_raw(const char* s, int x, int y, double sz, AiplVal col);
AiplVal _aipl_rt_drawText_va(int argc, const AiplVal* args);
AiplVal _aipl_rt_drawTextCentered_va(int argc, const AiplVal* args);
AiplVal _aipl_rt_drawTextMiddle_va(int argc, const AiplVal* args);
AiplVal _aipl_rt_drawTextFont_va(int argc, const AiplVal* args);
#define aipl_rt_drawText(...) _aipl_rt_drawText_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawTextCentered(...) _aipl_rt_drawTextCentered_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawTextMiddle(...) _aipl_rt_drawTextMiddle_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawTextAligned(...) _aipl_rt_drawText_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawTextFont(...) _aipl_rt_drawTextFont_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_drawLabel(...) _aipl_rt_drawText_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
AiplVal aipl_rt_measureText(AiplVal text_val, AiplVal size_val);
AiplVal aipl_rt_measureTextFont(AiplVal font_val, AiplVal text_val, AiplVal size_val);
AiplVal aipl_rt_measureLabel(AiplVal font_val, AiplVal text_val, AiplVal size_val);
AiplVal aipl_rt_measureTextWidth(AiplVal text_val, AiplVal size_val);
AiplVal aipl_rt_measureTextHeight(AiplVal text_val, AiplVal size_val);
AiplVal aipl_rt_measureTextSubstr(AiplVal text_val, AiplVal start_val, AiplVal len_val, AiplVal sz_val);
#endif // AIPL_ENABLE_GUI_AUDIO
#ifdef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_drawArc(AiplVal cx_v, AiplVal cy_v, AiplVal r_v, AiplVal a1_v, AiplVal a2_v, AiplVal thick_v, AiplVal c);
AiplVal aipl_rt_drawEllipse(AiplVal cx_v, AiplVal cy_v, AiplVal rx_v, AiplVal ry_v, AiplVal c);
AiplVal aipl_rt_drawPolygon(AiplVal pts_v, AiplVal c);
AiplVal aipl_rt_drawRegularPolygon(AiplVal cx_v, AiplVal cy_v, AiplVal r_v, AiplVal sides_v, AiplVal c);
AiplVal aipl_rt_drawPixel(AiplVal x, AiplVal y, AiplVal c);
AiplVal aipl_rt_readCanvasPixel(AiplVal x_v, AiplVal y_v);
AiplVal aipl_rt_readPixels(void);
AiplVal aipl_rt_saveCanvasSnapshot(AiplVal p_val);
AiplVal aipl_rt_drawPolyline(AiplVal pts_val, AiplVal c, AiplVal thick);
AiplVal aipl_rt_drawLineStrip(AiplVal pts_val, AiplVal c);
AiplVal aipl_rt_drawLineLoop(AiplVal pts_val, AiplVal c);
AiplVal aipl_rt_drawRectGradientH(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v, AiplVal c1, AiplVal c2);
AiplVal aipl_rt_drawRectGradientV(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v, AiplVal c1, AiplVal c2);
AiplVal aipl_rt_drawLinearGradient(AiplVal x1, AiplVal y1, AiplVal x2, AiplVal y2, AiplVal c1, AiplVal c2);
AiplVal aipl_rt_drawGridTiles(AiplVal cols_v, AiplVal rows_v, AiplVal tw_v, AiplVal th_v, AiplVal tiles_v, AiplVal pal_v);
AiplVal aipl_rt_drawCellGrid(AiplVal sx_v, AiplVal sy_v, AiplVal cw_v, AiplVal ch_v, AiplVal grid_v, AiplVal colormap_v);
AiplVal aipl_rt_drawRectBatch(AiplVal rects_v);
AiplVal aipl_rt_drawPixelBuffer(AiplVal pixels_v, AiplVal gw_v, AiplVal gh_v, AiplVal dx_v, AiplVal dy_v, AiplVal dw_v, AiplVal dh_v);
AiplVal aipl_rt_drawCirclesSoA(AiplVal xs_v, AiplVal ys_v, AiplVal r_v, AiplVal c_v, AiplVal cnt_v);
AiplVal aipl_rt_drawRectsSoA(AiplVal xs_v, AiplVal ys_v, AiplVal ws_v, AiplVal hs_v, AiplVal c_v, AiplVal cnt_v);
AiplVal aipl_rt_drawCharGrid(AiplVal sx_v, AiplVal sy_v, AiplVal cw_v, AiplVal ch_v, AiplVal lines_v, AiplVal c);
AiplVal aipl_rt_pushScissor(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v);
AiplVal aipl_rt_popScissor(void);
AiplVal aipl_rt_withViewport(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v, AiplVal fn_v);
AiplVal aipl_rt_createImageFromPixels(AiplVal w, AiplVal h, AiplVal px);
AiplVal aipl_rt_pushMatrix(void);
AiplVal aipl_rt_popMatrix(void);
AiplVal aipl_rt_translate2D(AiplVal x, AiplVal y);
AiplVal aipl_rt_rotate2D(AiplVal rad);
AiplVal aipl_rt_scale2D(AiplVal sx, AiplVal sy);
AiplVal aipl_rt_shear2D(AiplVal shx, AiplVal shy);
AiplVal _aipl_rt_begin3D_va(int argc, const AiplVal* args);
#define aipl_rt_begin3D(...) _aipl_rt_begin3D_va((int)(sizeof((AiplVal[]){ aipl_nil(), ##__VA_ARGS__ }) / sizeof(AiplVal) - 1), ((const AiplVal[]){ aipl_nil(), ##__VA_ARGS__ } + 1))
AiplVal aipl_rt_end3D(void);
AiplVal aipl_rt_setDepthTest(AiplVal enabled_v);
AiplVal aipl_rt_clearDepth(void);
AiplVal aipl_rt_beginWorldPass(void);
AiplVal aipl_rt_endWorldPass(void);
AiplVal aipl_rt_setUiTracking(AiplVal enabled_v);
AiplVal aipl_rt_drawTriangleGouraud(AiplVal x1_v, AiplVal y1_v, AiplVal x2_v, AiplVal y2_v, AiplVal x3_v, AiplVal y3_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v);
AiplVal aipl_rt_drawTriangle3DGouraud(AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v);
AiplVal aipl_rt_drawQuad3DGouraud(AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal x4_v, AiplVal y4_v, AiplVal z4_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v, AiplVal c4_v);
AiplVal aipl_rt_drawTriangle3DTextured(AiplVal texId_v, AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal u1_v, AiplVal v1_v, AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal u2_v, AiplVal v2_v, AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal u3_v, AiplVal v3_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v);
AiplVal aipl_rt_drawQuad3DTextured(AiplVal texId_v, AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal u1_v, AiplVal v1_v, AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal u2_v, AiplVal v2_v, AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal u3_v, AiplVal v3_v, AiplVal x4_v, AiplVal y4_v, AiplVal z4_v, AiplVal u4_v, AiplVal v4_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v, AiplVal c4_v);
AiplVal aipl_rt_createTextureFromRgba(AiplVal w_v, AiplVal h_v, AiplVal px_v);
AiplVal aipl_rt_createProceduralTexture(AiplVal kind_v, AiplVal w_v, AiplVal h_v, AiplVal seed_v);
AiplVal aipl_rt_saveTextureToPpm(AiplVal texId_v, AiplVal path_v);
AiplVal aipl_rt_createIsometricSpriteSheet(AiplVal arch_v, AiplVal fw_v, AiplVal fh_v, AiplVal dirs_v, AiplVal fpd_v, AiplVal seed_v);
AiplVal aipl_rt_setBlendMode(AiplVal mode_v);
AiplVal aipl_rt_getBlendMode(void);
AiplVal aipl_rt_blendModeAlpha(void);
AiplVal aipl_rt_blendModeAdditive(void);
AiplVal aipl_rt_blendModeMultiplied(void);
AiplVal aipl_rt_blendModeScreen(void);
AiplVal aipl_rt_drawTriangleDepth(AiplVal x1, AiplVal y1, AiplVal x2, AiplVal y2, AiplVal x3, AiplVal y3, AiplVal depth, AiplVal c);
AiplVal _aipl_rt_drawCubeMesh_va(int argc, const AiplVal* args);
#define aipl_rt_drawCubeMesh(...) _aipl_rt_drawCubeMesh_va((int)(sizeof((AiplVal[]){ aipl_nil(), ##__VA_ARGS__ }) / sizeof(AiplVal) - 1), ((const AiplVal[]){ aipl_nil(), ##__VA_ARGS__ } + 1))
#define aipl_rt_renderCube(...) _aipl_rt_drawCubeMesh_va((int)(sizeof((AiplVal[]){ aipl_nil(), ##__VA_ARGS__ }) / sizeof(AiplVal) - 1), ((const AiplVal[]){ aipl_nil(), ##__VA_ARGS__ } + 1))
AiplVal aipl_rt_isKeyPressed(AiplVal k);
AiplVal aipl_rt_isKeyDown(AiplVal k);
AiplVal aipl_rt_isKeyHeld(AiplVal k);
AiplVal aipl_rt_isKeyReleased(AiplVal k);
AiplVal aipl_rt_getKeyPressed(void);
AiplVal aipl_rt_isMouseButtonPressed(AiplVal b);
AiplVal aipl_rt_isMouseButtonDown(AiplVal b);
AiplVal aipl_rt_isMouseButtonReleased(AiplVal b);
AiplVal aipl_rt_isMouseRightClicked(void);
AiplVal aipl_rt_isMouseDoubleClicked(void);
AiplVal aipl_rt_getMouseX(void);
AiplVal aipl_rt_getMouseY(void);
AiplVal aipl_rt_getMouseWheelMove(void);
AiplVal aipl_rt_mouseWheelX(void);
AiplVal aipl_rt_isMouseInRect(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v);
extern FILE* _aipl_video_pipe;
extern int _aipl_video_fps;
extern int _aipl_video_w;
extern int _aipl_video_h;
AiplVal aipl_rt_stopVideoRecording(void);
AiplVal aipl_rt_startVideoRecording(AiplVal path, AiplVal fps);
AiplVal aipl_rt_recordVideoFrame(void);
AiplVal aipl_rt_isRecordingVideo(void);
AiplVal aipl_rt_saveScreenshot(AiplVal path);
typedef struct {
  int active;
  int w;
  int h;
  uint8_t* pixels;
  unsigned int gl_tex_id;
  int gl_dirty;
} _AiplImageSlot;
extern _AiplImageSlot* _aipl_images;
extern int _aipl_images_cap;
void _aipl_ensure_image_slot(int slot);
int _aipl_alloc_image_slot(int w, int h);
void _aipl_free_image_slot(int id);
int _aipl_load_ppm_file(const char* filepath);
AiplVal aipl_rt_loadImage(AiplVal p);
AiplVal aipl_rt_decodeImage(AiplVal d);
AiplVal aipl_rt_getImageWidth(AiplVal id);
AiplVal aipl_rt_imageWidth(AiplVal id);
AiplVal aipl_rt_getImageHeight(AiplVal id);
AiplVal aipl_rt_imageHeight(AiplVal id);
AiplVal aipl_rt_saveImage(AiplVal id_v, AiplVal path_v);
AiplVal aipl_rt_drawImageSub(AiplVal id_v, AiplVal sx_v, AiplVal sy_v, AiplVal sw_v, AiplVal sh_v, AiplVal dx_v, AiplVal dy_v, AiplVal dw_v, AiplVal dh_v, AiplVal tint_v);
AiplVal aipl_rt_drawImageScaled(AiplVal id_v, AiplVal dx_v, AiplVal dy_v, AiplVal dw_v, AiplVal dh_v, AiplVal tint_v);
AiplVal aipl_rt_drawImage(AiplVal id_v, AiplVal x_v, AiplVal y_v, AiplVal tint_v);
AiplVal aipl_rt_drawSubImage(AiplVal id, AiplVal sx, AiplVal sy, AiplVal sw, AiplVal sh, AiplVal dx, AiplVal dy, AiplVal dw, AiplVal dh);
AiplVal aipl_rt_drawImageEx(AiplVal id, AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal rot, AiplVal ox, AiplVal oy, AiplVal tint, AiplVal flipX, AiplVal flipY);
typedef struct { int active; char path[512]; int16_t* pcm; int64_t len; double rate; int channels; } _AiplWavAsset;
extern _AiplWavAsset* _aipl_loaded_wavs;
extern int _aipl_loaded_wavs_cap;
void _aipl_ensure_wav_slot(int slot);
#define _aipl_wav_slots _aipl_loaded_wavs
AiplVal aipl_rt_loadSound(AiplVal p);
AiplVal aipl_rt_decodeSound(AiplVal d);
AiplVal aipl_rt_getSoundDuration(AiplVal id);
AiplVal aipl_rt_loadFont(AiplVal p);
AiplVal aipl_rt_decodeFont(AiplVal d);
AiplVal aipl_rt_decodePngHeader(AiplVal d);
AiplVal aipl_rt_decodeWavHeader(AiplVal d);
AiplVal aipl_rt_decodeFontMetrics(AiplVal d);
AiplVal aipl_rt_cacheFont(AiplVal mgr, AiplVal p, AiplVal id);
AiplVal aipl_rt_cacheImage(AiplVal mgr, AiplVal p, AiplVal id);
AiplVal aipl_rt_cacheSound(AiplVal mgr, AiplVal p, AiplVal id);
AiplVal aipl_rt_getCachedFont(AiplVal mgr, AiplVal p);
AiplVal aipl_rt_getCachedImage(AiplVal mgr, AiplVal p);
AiplVal aipl_rt_getCachedSound(AiplVal mgr, AiplVal p);
AiplVal aipl_rt_createAssetManager(void);
AiplVal aipl_rt_createSpriteSheet(AiplVal imgId, AiplVal fw, AiplVal fh, AiplVal cols, AiplVal tot);
AiplVal aipl_rt_createAnimationClip(AiplVal start, AiplVal count, AiplVal fps, AiplVal loop);
AiplVal aipl_rt_sampleAnimationFrame(AiplVal clip, AiplVal elapsed);
AiplVal aipl_rt_drawSpriteFrame(AiplVal sheet, AiplVal frame, AiplVal dx, AiplVal dy, AiplVal dw, AiplVal dh);
AiplVal aipl_rt_drawAnimatedSprite(AiplVal sheet, AiplVal clip, AiplVal elapsed, AiplVal dx, AiplVal dy, AiplVal dw, AiplVal dh);
typedef struct {
  int active;
  int voice_id;
  int wave_type;
  double freq;
  double freq_target;
  double freq_step;
  double phase;
  double volume;
  double pan;
  int loop;
  double attack_time;
  double decay_time;
  double sustain_level;
  double release_time;
  double age;
  double duration;
  int state;
  int16_t* pcm_data;
  int64_t pcm_len;
  double pcm_pos;
  double pcm_speed;
  double lpf_state;
  double chorus_phase;
} _AiplAudioVoice;
extern _AiplAudioVoice* _aipl_voices;
extern int _aipl_voices_cap;
void _aipl_ensure_voices_cap(int min_cap);
extern int _aipl_next_voice_id;
extern pthread_mutex_t _aipl_audio_mutex;
extern pthread_t _aipl_audio_thread;
extern volatile int _aipl_audio_thread_running;
extern double _aipl_audio_master_volume;
extern double _aipl_audio_current_energy;
extern double _aipl_audio_spectrum[16];
extern double _aipl_audio_time_sec;
extern int16_t* _aipl_wav_buffer;
extern size_t _aipl_wav_cap;
extern size_t _aipl_wav_len;
void _aipl_audio_mix_samples(int16_t* out_stereo, int frames);
void _aipl_stop_and_cleanup_audio(void);
#endif // AIPL_ENABLE_GUI_AUDIO
#ifdef AIPL_ENABLE_GUI_AUDIO
void* _aipl_audio_worker(void* arg);
void _aipl_init_audio(void);
int _aipl_alloc_voice(void);
AiplVal _aipl_playTone_impl(double freq, double dur_ms, double vol, const char* wave_str);
AiplVal _aipl_playTone_2(AiplVal freq_v, AiplVal dur_v);
AiplVal _aipl_playTone_3(AiplVal freq_v, AiplVal dur_v, AiplVal vol_v);
#define _aipl_playTone_sel(_1, _2, _3, NAME, ...) NAME
#define aipl_rt_playTone(...) _aipl_playTone_sel(__VA_ARGS__, _aipl_playTone_3, _aipl_playTone_2)(__VA_ARGS__)
AiplVal aipl_rt_playToneEx(AiplVal freq_v, AiplVal dur_v, AiplVal vol_v, AiplVal wave_v);
AiplVal aipl_rt_playToneSweep(AiplVal start_freq_v, AiplVal end_freq_v, AiplVal dur_v);
AiplVal _aipl_rt_playPcmBuffer_va(int argc, const AiplVal* args);
#define aipl_rt_playPcmBuffer(...) _aipl_rt_playPcmBuffer_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
AiplVal _aipl_rt_playSoundEx_va(int argc, const AiplVal* args);
#define aipl_rt_playSoundEx(...) _aipl_rt_playSoundEx_va((int)(sizeof((AiplVal[]){ __VA_ARGS__ }) / sizeof(AiplVal)), (AiplVal[]){ __VA_ARGS__ })
#define aipl_rt_playSound(id) _aipl_rt_playSoundEx_va(1, (AiplVal[]){ id })
AiplVal aipl_rt_setMasterVolume(AiplVal vol_v);
AiplVal aipl_rt_stopAllSounds(void);
AiplVal aipl_rt_audioTime(void);
AiplVal aipl_rt_getAudioEnergy(void);
AiplVal aipl_rt_getAudioBand(AiplVal band_v);
AiplVal aipl_rt_getVoicePosition(AiplVal voiceId_v);
AiplVal aipl_rt_FontHandle(AiplVal id, AiplVal path);
AiplVal aipl_rt_ImageHandle(AiplVal id, AiplVal w, AiplVal h, AiplVal p);
AiplVal aipl_rt_SoundHandle(AiplVal id, AiplVal dur, AiplVal p);
AiplVal aipl_rt_decodeImageHandle(AiplVal d, AiplVal label);
AiplVal aipl_rt_decodeSoundHandle(AiplVal d, AiplVal label);
AiplVal aipl_rt_decodeFontHandle(AiplVal d, AiplVal label);
#endif // AIPL_ENABLE_GUI_AUDIO
#ifndef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_rgba(AiplVal r, AiplVal g, AiplVal b, AiplVal a);
#endif
AiplVal aipl_rt_Vec2(AiplVal x, AiplVal y);
AiplVal aipl_rt_Color(AiplVal r, AiplVal g, AiplVal b, AiplVal a);
AiplVal aipl_rt_color3(AiplVal r, AiplVal g, AiplVal b);
AiplVal aipl_rt_color4(AiplVal r, AiplVal g, AiplVal b, AiplVal a);
AiplVal aipl_rt_Rect(AiplVal x, AiplVal y, AiplVal w, AiplVal h);
AiplVal aipl_rt_colorHex(AiplVal hex);
AiplVal aipl_rt_hypot(AiplVal dx, AiplVal dy);
AiplVal aipl_rt_dist(AiplVal x1, AiplVal y1, AiplVal x2, AiplVal y2);
AiplVal aipl_rt_modFloat(AiplVal x, AiplVal y);
AiplVal aipl_rt_randomRange(AiplVal minVal, AiplVal maxVal);
AiplVal aipl_rt_randomBytes(AiplVal n);
AiplVal aipl_rt_dayOfWeek(AiplVal y, AiplVal m, AiplVal d);
AiplVal aipl_rt_unixToCivil(AiplVal ts);
AiplVal aipl_rt_padLeft(AiplVal s, AiplVal n, AiplVal ch);
AiplVal aipl_rt_padRight(AiplVal s, AiplVal n, AiplVal ch);
AiplVal aipl_rt_truncateText(AiplVal t, AiplVal maxW, AiplVal sz);
int aipl_rt_grid_dims(AiplVal g, int64_t* w, int64_t* h);
AiplVal aipl_rt_gridInBounds(AiplVal g, AiplVal x, AiplVal y);
AiplVal aipl_rt_gridGet(AiplVal g, AiplVal x, AiplVal y);
AiplVal aipl_rt_grid_neighbors(AiplVal g, AiplVal x, AiplVal y, int diag);
AiplVal aipl_rt_gridNeighbors4(AiplVal g, AiplVal x, AiplVal y);
AiplVal aipl_rt_gridNeighbors8(AiplVal g, AiplVal x, AiplVal y);
AiplVal aipl_rt_gridFloodFill(AiplVal g, AiplVal x, AiplVal y, AiplVal val);
#ifdef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_drawTextBox(AiplVal t, AiplVal x, AiplVal y, AiplVal w, AiplVal sz, AiplVal c);
AiplVal aipl_rt_drawTextRight(AiplVal t, AiplVal x, AiplVal y, AiplVal sz, AiplVal c);
AiplVal aipl_rt_getTextInput(void);
AiplVal aipl_rt_isRectClicked(AiplVal x, AiplVal y, AiplVal w, AiplVal h);
AiplVal aipl_rt_mouseWheelY(void);
AiplVal aipl_rt_pollKeyEvents(void);
AiplVal aipl_rt_isKeyJustPressed(AiplVal k);
AiplVal aipl_rt_getPressedKey(void);
AiplVal aipl_rt_isAnyKeyPressed(void);
AiplVal aipl_rt_pollFileDropEvents(void);
#endif // AIPL_ENABLE_GUI_AUDIO
int64_t aipl_fast_int_op(int64_t a, int64_t b, char op);
int64_t aipl_vec_get_int_fast(AiplVal arr, int64_t idx);
void aipl_vec_set_int_fast(AiplVal arr, int64_t idx, int64_t val);
double aipl_vec_get_float_fast(AiplVal arr, int64_t idx);
void aipl_vec_set_float_fast(AiplVal arr, int64_t idx, double val);
AiplVal aipl_rt_intBufferNew(AiplVal lenVal);
AiplVal aipl_rt_intBufferGet(AiplVal buf, AiplVal idx);
AiplVal aipl_rt_intBufferSet(AiplVal buf, AiplVal idx, AiplVal val);
AiplVal aipl_rt_intBufferLen(AiplVal buf);
AiplVal aipl_rt_floatBufferNew(AiplVal lenVal);
AiplVal aipl_rt_floatBufferGet(AiplVal buf, AiplVal idx);
AiplVal aipl_rt_floatBufferSet(AiplVal buf, AiplVal idx, AiplVal val);
AiplVal aipl_rt_floatBufferLen(AiplVal buf);
AiplVal aipl_rt_sumIntsFast(AiplVal arr);
AiplVal aipl_rt_sumFloatsFast(AiplVal arr);
AiplVal aipl_rt_dotProductFloats(AiplVal a_val, AiplVal b_val);
AiplVal aipl_rt_axpyFloats(AiplVal alpha, AiplVal x_val, AiplVal y_val);
AIPL_TARGET_AVX2_FMA
AiplVal aipl_rt_tensor_dot(AiplVal a_val, AiplVal b_val);
typedef struct {
  const double* A;
  const double* B_T;
  double* C;
  int64_t row_start;
  int64_t row_end;
  int64_t n;
  int64_t k;
} AiplMatmulWorkerArg;
#if defined(__x86_64__) || defined(_M_X64)
__attribute__((target("avx2,fma")))
void aipl_simd_matmul_kernel(const double* A, const double* B_T, double* C, int64_t row_start, int64_t row_end, int64_t n, int64_t k);
#endif
void aipl_scalar_matmul_kernel(const double* A, const double* B_T, double* C, int64_t row_start, int64_t row_end, int64_t n, int64_t k);
void* aipl_matmul_worker(void* param);
AiplVal aipl_rt_tensor_matmul(AiplVal a_val, AiplVal b_val, AiplVal m_val, AiplVal n_val, AiplVal k_val);
typedef struct {
  const int64_t* A;
  const int64_t* B_T;
  int64_t* C;
  int64_t row_start;
  int64_t row_end;
  int64_t n;
  int64_t k;
} AiplMatmulIntWorkerArg;
void* aipl_matmul_int_worker(void* param);
AiplVal aipl_rt_parallel_matmul_int(AiplVal a_val, AiplVal b_val, AiplVal m_val, AiplVal n_val, AiplVal k_val, AiplVal threads_val);
typedef struct {
  const uint32_t* ret_pc;
  int64_t* prev_fp;
  uint32_t rd;
} AiplRegCallFrame;
int64_t aipl_reg_vm_run_raw(const uint32_t* __restrict__ code, int64_t code_len, int64_t r0_init);
AiplVal aipl_rt_reg_vm_exec(AiplVal code_arr, AiplVal r0_init);
AiplVal aipl_rt_reg_vm_fib(AiplVal n_val);
AiplVal aipl_rt_compile_c_single(AiplVal v_cSource, AiplVal v_outputPath, AiplVal v_optFlag, AiplVal v_debugInfo, AiplVal v_includeDir, AiplVal v_archive);
typedef struct {
  const char* start;
  size_t len;
  int original_idx;
} AiplFnSlice;
int aipl_rt_fn_slice_cmp_desc(const void* a, const void* b);
const char* aipl_next_fn_marker(const char* p);
AiplVal aipl_rt_compile_c_parallel(AiplVal v_cSource, AiplVal v_outputPath, AiplVal v_optFlag, AiplVal v_debugInfo, AiplVal v_includeDir, AiplVal v_archive);
void aipl_val_write_bin(FILE* fp, AiplVal v);
AiplVal aipl_val_read_bin(FILE* fp);
AiplVal aipl_merge_arenas(AiplVal v_rootModName, AiplVal v_arenasArr, AiplVal v_lineOffsetsArr);
AiplVal aipl_rt_parallel_frontend(AiplVal v_chunks, AiplVal v_lineOffsets, AiplVal v_rootModName, AiplVal (*fn_parse_chunk)(AiplVal, AiplVal));
AiplVal aipl_rt_parallel_optimize_hir(AiplVal v_hir, AiplVal (*fn_opt_stride)(AiplVal, AiplVal, AiplVal));
AiplVal aipl_rt_parallel_typecheck(AiplVal v_hir, AiplVal v_fnTypes, AiplVal v_funcs, AiplVal v_diags, AiplVal (*fn_tc_stride)(AiplVal, AiplVal, AiplVal, AiplVal));
AiplVal aipl_rt_parallel_smt(AiplVal v_arena, AiplVal v_hir, AiplVal v_contractTable, AiplVal v_funcs, AiplVal v_violations, AiplVal (*fn_smt_stride)(AiplVal, AiplVal, AiplVal));
AiplVal aipl_rt_parallel_test_prepare(AiplVal v_files, AiplVal v_tmpCs, AiplVal v_cpus, AiplVal (*fn_prep_one)(AiplVal, AiplVal));
#endif /* AIPL_RUNTIME_H */
