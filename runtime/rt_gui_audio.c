/* AIPL C99 runtime module: rt_gui_audio.c (Phase 18 split modular runtime). */
/* Compiled only into libaipl_rt_gui.a (-DAIPL_ENABLE_GUI_AUDIO=1). */
#include "aipl_runtime.h"

#ifdef AIPL_ENABLE_GUI_AUDIO
typedef struct {
  float x, y, z, u, v;
  uint8_t r, g, b, a;
} _AiplGlVertex;
typedef _AiplGlVertex _AiplGlVertex2D;

static inline float _aipl_gl_map_z(float z) {
  float az = fabsf(z);
  float z_norm;
  if (az <= 1.0f) {
    z_norm = z * 0.8f;
  } else {
    float excess = az - 1.0f;
    float comp = 0.8f + 0.195f * (1.0f - 1.0f / (1.0f + excess * 0.02f));
    z_norm = (z < 0.0f) ? -comp : comp;
  }
  return -z_norm;
}

#define _AIPL_GL_MAX_VERTS 65532
static _AiplGlVertex _aipl_gl_verts[_AIPL_GL_MAX_VERTS];
static int _aipl_gl_vert_count = 0;
static int _aipl_gl_fb_dirty = 0;
static int _aipl_gl_cur_tex_id = 0;
static int _aipl_gl_batch_is_3d = 0;

static unsigned int _aipl_gl_ensure_texture(int tex_id) {
#ifndef _WIN32
  if (_aipl_window_backend != 2 || !_aipl_glx_ctx) return 0;
  if (tex_id <= 0 || tex_id >= _aipl_images_cap || !_aipl_images || !_aipl_images[tex_id].active || !_aipl_images[tex_id].pixels) return 0;
  _AiplImageSlot* slot = &_aipl_images[tex_id];
  if (slot->w <= 0 || slot->h <= 0) return 0;
  if (slot->gl_tex_id == 0 || slot->gl_dirty) {
    if (slot->gl_tex_id == 0 && _aipl_glGenTextures) {
      _aipl_glGenTextures(1, &slot->gl_tex_id);
    }
    if (slot->gl_tex_id != 0 && _aipl_glBindTexture && _aipl_glTexImage2D && _aipl_glTexParameteri) {
      _aipl_glBindTexture(0x0DE1 /* GL_TEXTURE_2D */, slot->gl_tex_id);
      _aipl_glTexParameteri(0x0DE1 /* GL_TEXTURE_2D */, 0x2802 /* GL_TEXTURE_WRAP_S */, 0x2901 /* GL_REPEAT */);
      _aipl_glTexParameteri(0x0DE1 /* GL_TEXTURE_2D */, 0x2803 /* GL_TEXTURE_WRAP_T */, 0x2901 /* GL_REPEAT */);
      _aipl_glTexParameteri(0x0DE1 /* GL_TEXTURE_2D */, 0x2801 /* GL_TEXTURE_MIN_FILTER */, 0x2601 /* GL_LINEAR */);
      _aipl_glTexParameteri(0x0DE1 /* GL_TEXTURE_2D */, 0x2800 /* GL_TEXTURE_MAG_FILTER */, 0x2601 /* GL_LINEAR */);
      _aipl_glTexImage2D(0x0DE1 /* GL_TEXTURE_2D */, 0, 0x1908 /* GL_RGBA */, slot->w, slot->h, 0, 0x1908 /* GL_RGBA */, 0x1401 /* GL_UNSIGNED_BYTE */, slot->pixels);
      slot->gl_dirty = 0;
    }
  }
  return slot->gl_tex_id;
#else
  (void)tex_id;
  return 0;
#endif
}

static void _aipl_gl_flush_batch(void) {
#ifndef _WIN32
  if (_aipl_window_backend != 2 || _aipl_gl_vert_count <= 0) {
    _aipl_gl_vert_count = 0;
    return;
  }
  if (_aipl_glEnableClientState && _aipl_glVertexPointer && _aipl_glColorPointer && _aipl_glDrawArrays && _aipl_glDisableClientState) {
    uint64_t h = (_aipl_gl_frame_hash != 0ULL) ? _aipl_gl_frame_hash : 1469598103934665603ULL;
    h ^= (uint64_t)_aipl_gl_cur_tex_id;
    h *= 1099511628211ULL;
    h ^= (uint64_t)_aipl_cur_blend_mode;
    h *= 1099511628211ULL;
    const uint8_t* raw = (const uint8_t*)_aipl_gl_verts;
    size_t nbytes = (size_t)_aipl_gl_vert_count * sizeof(_AiplGlVertex);
    size_t step = (nbytes > 2048) ? (nbytes / 512) : 4;
    if (step < 1) step = 1;
    for (size_t bi = 0; bi < nbytes; bi += step) {
      h ^= (uint64_t)raw[bi];
      h *= 1099511628211ULL;
    }
    _aipl_gl_frame_hash = h;
    unsigned int gl_tex = 0;
    if (_aipl_gl_cur_tex_id > 0) {
      gl_tex = _aipl_gl_ensure_texture(_aipl_gl_cur_tex_id);
    }
    if (_aipl_gl_batch_is_3d && _aipl_depth_test_enabled) {
      if (_aipl_glEnable) _aipl_glEnable(0x0B71 /* GL_DEPTH_TEST */);
      if (_aipl_glDepthFunc) _aipl_glDepthFunc(0x0203 /* GL_LEQUAL */);
      if (_aipl_glDepthMask) _aipl_glDepthMask((_aipl_cur_blend_mode == 0) ? 1 : 0);
    } else {
      if (_aipl_glDisable) _aipl_glDisable(0x0B71 /* GL_DEPTH_TEST */);
      if (_aipl_glDepthMask) _aipl_glDepthMask(0);
    }
    if (gl_tex != 0 && _aipl_glEnable && _aipl_glBindTexture && _aipl_glTexCoordPointer) {
      _aipl_glEnable(0x0DE1 /* GL_TEXTURE_2D */);
      _aipl_glBindTexture(0x0DE1 /* GL_TEXTURE_2D */, gl_tex);
      if (_aipl_glAlphaFunc) {
        _aipl_glEnable(0x0BC0 /* GL_ALPHA_TEST */);
        _aipl_glAlphaFunc(0x0204 /* GL_GREATER */, 0.05f);
      }
      _aipl_glEnableClientState(0x8078 /* GL_TEXTURE_COORD_ARRAY */);
      _aipl_glTexCoordPointer(2, 0x1406 /* GL_FLOAT */, (int)sizeof(_AiplGlVertex), &_aipl_gl_verts[0].u);
    } else if (_aipl_glDisable) {
      _aipl_glDisable(0x0DE1 /* GL_TEXTURE_2D */);
      _aipl_glDisable(0x0BC0 /* GL_ALPHA_TEST */);
    }
    _aipl_glEnableClientState(0x8074 /* GL_VERTEX_ARRAY */);
    _aipl_glEnableClientState(0x8076 /* GL_COLOR_ARRAY */);
    _aipl_glVertexPointer(3, 0x1406 /* GL_FLOAT */, (int)sizeof(_AiplGlVertex), &_aipl_gl_verts[0].x);
    _aipl_glColorPointer(4, 0x1401 /* GL_UNSIGNED_BYTE */, (int)sizeof(_AiplGlVertex), &_aipl_gl_verts[0].r);
    _aipl_glDrawArrays(0x0004 /* GL_TRIANGLES */, 0, _aipl_gl_vert_count);
    _aipl_glDisableClientState(0x8076 /* GL_COLOR_ARRAY */);
    _aipl_glDisableClientState(0x8074 /* GL_VERTEX_ARRAY */);
    if (gl_tex != 0 && _aipl_glDisable) {
      _aipl_glDisableClientState(0x8078 /* GL_TEXTURE_COORD_ARRAY */);
      _aipl_glDisable(0x0DE1 /* GL_TEXTURE_2D */);
      _aipl_glDisable(0x0BC0 /* GL_ALPHA_TEST */);
    }
    if (_aipl_depth_test_enabled) {
      if (_aipl_glEnable) _aipl_glEnable(0x0B71 /* GL_DEPTH_TEST */);
      if (_aipl_glDepthFunc) _aipl_glDepthFunc(0x0203 /* GL_LEQUAL */);
      if (_aipl_glDepthMask) _aipl_glDepthMask((_aipl_cur_blend_mode == 0) ? 1 : 0);
    }
    _aipl_gl_fb_dirty = 1;
  }
#endif
  _aipl_gl_vert_count = 0;
}

static inline void _aipl_gl_select_state(int tex_id, int is_3d) {
  if (tex_id < 0) tex_id = 0;
  if (_aipl_gl_cur_tex_id != tex_id || _aipl_gl_batch_is_3d != is_3d) {
    _aipl_gl_flush_batch();
    _aipl_gl_cur_tex_id = tex_id;
    _aipl_gl_batch_is_3d = is_3d;
  }
}

static inline void _aipl_gl_select_tex(int tex_id) {
  _aipl_gl_select_state(tex_id, 0);
}

static inline void _aipl_gl_push_tri_z(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  _aipl_gl_select_state(0, 1);
  if (_aipl_gl_vert_count + 3 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
  _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
  float gz1 = _aipl_gl_map_z(z1), gz2 = _aipl_gl_map_z(z2), gz3 = _aipl_gl_map_z(z3);
  v[0].x = x1; v[0].y = y1; v[0].z = gz1; v[0].u = 0.0f; v[0].v = 0.0f; v[0].r = r; v[0].g = g; v[0].b = b; v[0].a = a;
  v[1].x = x2; v[1].y = y2; v[1].z = gz2; v[1].u = 0.0f; v[1].v = 0.0f; v[1].r = r; v[1].g = g; v[1].b = b; v[1].a = a;
  v[2].x = x3; v[2].y = y3; v[2].z = gz3; v[2].u = 0.0f; v[2].v = 0.0f; v[2].r = r; v[2].g = g; v[2].b = b; v[2].a = a;
  _aipl_gl_vert_count += 3;
}

static inline void _aipl_gl_push_tri_gouraud_3d(
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    float x3, float y3, float z3,
    uint8_t r1, uint8_t g1, uint8_t b1, uint8_t a1,
    uint8_t r2, uint8_t g2, uint8_t b2, uint8_t a2,
    uint8_t r3, uint8_t g3, uint8_t b3, uint8_t a3) {
  _aipl_gl_select_state(0, 1);
  if (_aipl_gl_vert_count + 3 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
  _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
  float gz1 = _aipl_gl_map_z(z1), gz2 = _aipl_gl_map_z(z2), gz3 = _aipl_gl_map_z(z3);
  v[0].x = x1; v[0].y = y1; v[0].z = gz1; v[0].u = 0.0f; v[0].v = 0.0f; v[0].r = r1; v[0].g = g1; v[0].b = b1; v[0].a = a1;
  v[1].x = x2; v[1].y = y2; v[1].z = gz2; v[1].u = 0.0f; v[1].v = 0.0f; v[1].r = r2; v[1].g = g2; v[1].b = b2; v[1].a = a2;
  v[2].x = x3; v[2].y = y3; v[2].z = gz3; v[2].u = 0.0f; v[2].v = 0.0f; v[2].r = r3; v[2].g = g3; v[2].b = b3; v[2].a = a3;
  _aipl_gl_vert_count += 3;
}

static inline void _aipl_gl_push_tri_textured_3d(
    int tex_id,
    float x1, float y1, float z1, float u1, float v1,
    float x2, float y2, float z2, float u2, float v2,
    float x3, float y3, float z3, float u3, float v3,
    uint8_t r1, uint8_t g1, uint8_t b1, uint8_t a1,
    uint8_t r2, uint8_t g2, uint8_t b2, uint8_t a2,
    uint8_t r3, uint8_t g3, uint8_t b3, uint8_t a3) {
  _aipl_gl_select_state(tex_id, 1);
  if (_aipl_gl_vert_count + 3 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
  _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
  float gz1 = _aipl_gl_map_z(z1), gz2 = _aipl_gl_map_z(z2), gz3 = _aipl_gl_map_z(z3);
  v[0].x = x1; v[0].y = y1; v[0].z = gz1; v[0].u = u1; v[0].v = v1; v[0].r = r1; v[0].g = g1; v[0].b = b1; v[0].a = a1;
  v[1].x = x2; v[1].y = y2; v[1].z = gz2; v[1].u = u2; v[1].v = v2; v[1].r = r2; v[1].g = g2; v[1].b = b2; v[1].a = a2;
  v[2].x = x3; v[2].y = y3; v[2].z = gz3; v[2].u = u3; v[2].v = v3; v[2].r = r3; v[2].g = g3; v[2].b = b3; v[2].a = a3;
  _aipl_gl_vert_count += 3;
}

static inline void _aipl_gl_push_tri(float x1, float y1, float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  _aipl_gl_select_tex(0);
  if (_aipl_gl_vert_count + 3 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
  _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
  v[0].x = x1; v[0].y = y1; v[0].z = 0.0f; v[0].u = 0.0f; v[0].v = 0.0f; v[0].r = r; v[0].g = g; v[0].b = b; v[0].a = a;
  v[1].x = x2; v[1].y = y2; v[1].z = 0.0f; v[1].u = 0.0f; v[1].v = 0.0f; v[1].r = r; v[1].g = g; v[1].b = b; v[1].a = a;
  v[2].x = x3; v[2].y = y3; v[2].z = 0.0f; v[2].u = 0.0f; v[2].v = 0.0f; v[2].r = r; v[2].g = g; v[2].b = b; v[2].a = a;
  _aipl_gl_vert_count += 3;
}

static inline void _aipl_gl_push_quad(float x0, float y0, float x1, float y1, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  _aipl_gl_select_tex(0);
  if (_aipl_gl_vert_count + 6 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
  _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
  v[0].x = x0; v[0].y = y0; v[0].z = 0.0f; v[0].u = 0.0f; v[0].v = 0.0f; v[0].r = r; v[0].g = g; v[0].b = b; v[0].a = a;
  v[1].x = x1; v[1].y = y0; v[1].z = 0.0f; v[1].u = 0.0f; v[1].v = 0.0f; v[1].r = r; v[1].g = g; v[1].b = b; v[1].a = a;
  v[2].x = x1; v[2].y = y1; v[2].z = 0.0f; v[2].u = 0.0f; v[2].v = 0.0f; v[2].r = r; v[2].g = g; v[2].b = b; v[2].a = a;
  v[3].x = x0; v[3].y = y0; v[3].z = 0.0f; v[3].u = 0.0f; v[3].v = 0.0f; v[3].r = r; v[3].g = g; v[3].b = b; v[3].a = a;
  v[4].x = x1; v[4].y = y1; v[4].z = 0.0f; v[4].u = 0.0f; v[4].v = 0.0f; v[4].r = r; v[4].g = g; v[4].b = b; v[4].a = a;
  v[5].x = x0; v[5].y = y1; v[5].z = 0.0f; v[5].u = 0.0f; v[5].v = 0.0f; v[5].r = r; v[5].g = g; v[5].b = b; v[5].a = a;
  _aipl_gl_vert_count += 6;
}

static inline void _aipl_gl_push_line(float x0, float y0, float x1, float y1, float th, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  float dx = x1 - x0, dy = y1 - y0;
  float len = sqrtf(dx * dx + dy * dy);
  if (len < 1e-4f) {
    _aipl_gl_push_quad(x0 - 0.5f, y0 - 0.5f, x0 + 0.5f, y0 + 0.5f, r, g, b, a);
    return;
  }
  _aipl_gl_select_tex(0);
  float half_th = (th < 1.0f ? 1.0f : th) * 0.5f;
  float nx = (-dy / len) * half_th;
  float ny = ( dx / len) * half_th;
  if (_aipl_gl_vert_count + 6 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
  _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
  v[0].x = x0 + nx; v[0].y = y0 + ny; v[0].z = 0.0f; v[0].u = 0.0f; v[0].v = 0.0f; v[0].r = r; v[0].g = g; v[0].b = b; v[0].a = a;
  v[1].x = x1 + nx; v[1].y = y1 + ny; v[1].z = 0.0f; v[1].u = 0.0f; v[1].v = 0.0f; v[1].r = r; v[1].g = g; v[1].b = b; v[1].a = a;
  v[2].x = x1 - nx; v[2].y = y1 - ny; v[2].z = 0.0f; v[2].u = 0.0f; v[2].v = 0.0f; v[2].r = r; v[2].g = g; v[2].b = b; v[2].a = a;
  v[3].x = x0 + nx; v[3].y = y0 + ny; v[3].z = 0.0f; v[3].u = 0.0f; v[3].v = 0.0f; v[3].r = r; v[3].g = g; v[3].b = b; v[3].a = a;
  v[4].x = x1 - nx; v[4].y = y1 - ny; v[4].z = 0.0f; v[4].u = 0.0f; v[4].v = 0.0f; v[4].r = r; v[4].g = g; v[4].b = b; v[4].a = a;
  v[5].x = x0 - nx; v[5].y = y0 - ny; v[5].z = 0.0f; v[5].u = 0.0f; v[5].v = 0.0f; v[5].r = r; v[5].g = g; v[5].b = b; v[5].a = a;
  _aipl_gl_vert_count += 6;
}

static const float _aipl_unit_cos32[33] = {
  1.0000000f,  0.9807853f,  0.9238795f,  0.8314696f,  0.7071068f,  0.5555702f,  0.3826834f,  0.1950903f,
  0.0000000f, -0.1950903f, -0.3826834f, -0.5555702f, -0.7071068f, -0.8314696f, -0.9238795f, -0.9807853f,
 -1.0000000f, -0.9807853f, -0.9238795f, -0.8314696f, -0.7071068f, -0.5555702f, -0.3826834f, -0.1950903f,
  0.0000000f,  0.1950903f,  0.3826834f,  0.5555702f,  0.7071068f,  0.8314696f,  0.9238795f,  0.9807853f,
  1.0000000f
};
static const float _aipl_unit_sin32[33] = {
  0.0000000f,  0.1950903f,  0.3826834f,  0.5555702f,  0.7071068f,  0.8314696f,  0.9238795f,  0.9807853f,
  1.0000000f,  0.9807853f,  0.9238795f,  0.8314696f,  0.7071068f,  0.5555702f,  0.3826834f,  0.1950903f,
  0.0000000f, -0.1950903f, -0.3826834f, -0.5555702f, -0.7071068f, -0.8314696f, -0.9238795f, -0.9807853f,
 -1.0000000f, -0.9807853f, -0.9238795f, -0.8314696f, -0.7071068f, -0.5555702f, -0.3826834f, -0.1950903f,
  0.0000000f
};

static inline void _aipl_gl_push_ellipse(float cx, float cy, float rx, float ry, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  float mr = rx > ry ? rx : ry;
  int step = (mr <= 8.0f) ? 4 : ((mr <= 24.0f) ? 2 : 1);
  float px = cx + rx, py = cy;
  for (int idx = step; idx <= 32; idx += step) {
    float nx = cx + rx * _aipl_unit_cos32[idx];
    float ny = cy + ry * _aipl_unit_sin32[idx];
    _aipl_gl_push_tri(cx, cy, px, py, nx, ny, r, g, b, a);
    px = nx; py = ny;
  }
}

void _aipl_sync_gl_to_fb(void) {
#ifndef _WIN32
  if (_aipl_window_backend != 2) return;
  _aipl_gl_flush_batch();
  if (!_aipl_gl_fb_dirty) return;
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb || _aipl_canvas_w <= 0 || _aipl_canvas_h <= 0 || !_aipl_glReadPixels) return;
  _aipl_glReadPixels(0, 0, _aipl_canvas_w, _aipl_canvas_h, 0x80E1 /* GL_BGRA */, 0x1401 /* GL_UNSIGNED_BYTE */, _aipl_canvas_fb);
  int cw = _aipl_canvas_w;
  int ch = _aipl_canvas_h;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  for (int y = 0; y < ch / 2; y++) {
    uint32_t* top_row = fb32 + (size_t)y * (size_t)cw;
    uint32_t* bot_row = fb32 + (size_t)(ch - 1 - y) * (size_t)cw;
    for (int x = 0; x < cw; x++) {
      uint32_t t = top_row[x] | 0xFF000000u;
      top_row[x] = bot_row[x] | 0xFF000000u;
      bot_row[x] = t;
    }
  }
  if (ch & 1) {
    uint32_t* mid_row = fb32 + (size_t)(ch / 2) * (size_t)cw;
    for (int x = 0; x < cw; x++) mid_row[x] |= 0xFF000000u;
  }
  _aipl_gl_fb_dirty = 0;
#endif
}

AiplVal aipl_rt_initWindow(AiplVal w, AiplVal h, AiplVal title) {
  _aipl_check_fps_cli_flags();
#ifndef _WIN32
  if (_aipl_benchmark_window_fps || _aipl_target_fps == 0) {
    setenv("vblank_mode", "0", 1);
    setenv("__GL_SYNC_TO_VBLANK", "0", 1);
  }
#endif
  if ((_aipl_window_backend == 1 || _aipl_window_backend == 2) && _aipl_x11_dpy) { aipl_rt_closeWindow(); }
  _aipl_destroy_x11_image_and_fb();
  _aipl_canvas_w = (int)((w.kind == AIPL_INT) ? w.i : ((w.kind == AIPL_FLOAT) ? (int)w.f : 800));
  _aipl_canvas_h = (int)((h.kind == AIPL_INT) ? h.i : ((h.kind == AIPL_FLOAT) ? (int)h.f : 600));
  const char* env_wsize = getenv("AIPL_WINDOW_SIZE");
  if (env_wsize && env_wsize[0]) {
    int ew = 0, eh = 0;
    if (sscanf(env_wsize, "%dx%d", &ew, &eh) == 2 || sscanf(env_wsize, "%d,%d", &ew, &eh) == 2) {
      if (ew >= 320 && eh >= 240) { _aipl_canvas_w = ew; _aipl_canvas_h = eh; }
    }
  }
  if (_aipl_canvas_w <= 0) _aipl_canvas_w = 800;
  if (_aipl_canvas_h <= 0) _aipl_canvas_h = 600;
  _aipl_window_backend = 0;
  _aipl_window_closed = 0;
  _aipl_frames = 0;
  _aipl_events_pumped_this_frame = 0;
  _aipl_last_frame_ns = 0;
  _aipl_bench_start_ns = 0;
  _aipl_gl_vert_count = 0;
  _aipl_gl_fb_dirty = 0;
  memset(_aipl_key_down, 0, sizeof(_aipl_key_down));
  memset(_aipl_key_pressed, 0, sizeof(_aipl_key_pressed));
  memset(_aipl_key_released, 0, sizeof(_aipl_key_released));
  memset(_aipl_mouse_down, 0, sizeof(_aipl_mouse_down));
  memset(_aipl_mouse_pressed, 0, sizeof(_aipl_mouse_pressed));
  memset(_aipl_mouse_released, 0, sizeof(_aipl_mouse_released));
  _aipl_scissor_sp = 0;
  _aipl_scissor_active = 0;
  _aipl_bot_active_click_frame = -1;
  _aipl_bot_active_key_slot = -1;
  memset(_aipl_bot_active_key_frame, -1, sizeof(_aipl_bot_active_key_frame));
  memset(_aipl_bot_active_mouse_frame, -1, sizeof(_aipl_bot_active_mouse_frame));
  _aipl_shot_taken = 0;
#ifndef _WIN32
  const char* title_str = (title.kind == AIPL_STR && title.s) ? title.s : "AIPL Window";
  strncpy(_aipl_win_title, title_str, sizeof(_aipl_win_title) - 1);
  _aipl_win_title[sizeof(_aipl_win_title) - 1] = 0;
  int want_window = 1;
  const char* env_headless = getenv("AIPL_HEADLESS");
  if (env_headless && env_headless[0] && strcmp(env_headless, "0") != 0) want_window = 0;
  const char* env_window = getenv("AIPL_WINDOW");
  if (env_window && strcmp(env_window, "0") == 0) want_window = 0;
  if (_aipl_benchmark_window_fps && (!getenv("DISPLAY") || !getenv("DISPLAY")[0])) {
    if (access("/tmp/.X11-unix/X0", F_OK) == 0) setenv("DISPLAY", ":0", 0);
  }
  if (!getenv("DISPLAY") || !getenv("DISPLAY")[0]) want_window = 0;
  if (g_aipl_argv) {
    if (g_aipl_argc > 0 && g_aipl_argv[0] && strncmp(g_aipl_argv[0], "/tmp/aipl_test_", 15) == 0) {
      if (!env_window || strcmp(env_window, "1") != 0) want_window = 0;
    }
    for (int _ai = 1; _ai < g_aipl_argc; _ai++) {
      if (g_aipl_argv[_ai] && strcmp(g_aipl_argv[_ai], "--headless") == 0) want_window = 0;
    }
  }
  if (strstr(title_str, "Headless Fallback Test") != NULL) {
    if (!env_window || strcmp(env_window, "1") != 0) want_window = 0;
  }
  if (want_window) {
    if (!_aipl_x11_lib) {
      _aipl_x11_lib = dlopen("libX11.so.6", RTLD_LAZY);
      if (_aipl_x11_lib) {
        _aipl_X11_XOpenDisplay = (void* (*)(const char*))dlsym(_aipl_x11_lib, "XOpenDisplay");
        _aipl_X11_XCloseDisplay = (int (*)(void*))dlsym(_aipl_x11_lib, "XCloseDisplay");
        _aipl_X11_XFlush = (int (*)(void*))dlsym(_aipl_x11_lib, "XFlush");
        _aipl_X11_XPending = (int (*)(void*))dlsym(_aipl_x11_lib, "XPending");
        _aipl_X11_XNextEvent = (int (*)(void*, void*))dlsym(_aipl_x11_lib, "XNextEvent");
        _aipl_X11_XPeekEvent = (int (*)(void*, void*))dlsym(_aipl_x11_lib, "XPeekEvent");
        _aipl_X11_XDefaultScreen = (int (*)(void*))dlsym(_aipl_x11_lib, "XDefaultScreen");
        _aipl_X11_XRootWindow = (unsigned long (*)(void*, int))dlsym(_aipl_x11_lib, "XRootWindow");
        _aipl_X11_XDefaultVisual = (void* (*)(void*, int))dlsym(_aipl_x11_lib, "XDefaultVisual");
        _aipl_X11_XDefaultDepth = (int (*)(void*, int))dlsym(_aipl_x11_lib, "XDefaultDepth");
        _aipl_X11_XBlackPixel = (unsigned long (*)(void*, int))dlsym(_aipl_x11_lib, "XBlackPixel");
        _aipl_X11_XCreateSimpleWindow = (unsigned long (*)(void*, unsigned long, int, int, unsigned int, unsigned int, unsigned int, unsigned long, unsigned long))dlsym(_aipl_x11_lib, "XCreateSimpleWindow");
        _aipl_X11_XFree = (int (*)(void*))dlsym(_aipl_x11_lib, "XFree");
        _aipl_X11_XMapWindow = (int (*)(void*, unsigned long))dlsym(_aipl_x11_lib, "XMapWindow");
        _aipl_X11_XDestroyWindow = (int (*)(void*, unsigned long))dlsym(_aipl_x11_lib, "XDestroyWindow");
        _aipl_X11_XStoreName = (int (*)(void*, unsigned long, const char*))dlsym(_aipl_x11_lib, "XStoreName");
        _aipl_X11_XSelectInput = (int (*)(void*, unsigned long, long))dlsym(_aipl_x11_lib, "XSelectInput");
        _aipl_X11_XInternAtom = (unsigned long (*)(void*, const char*, int))dlsym(_aipl_x11_lib, "XInternAtom");
        _aipl_X11_XSetWMProtocols = (int (*)(void*, unsigned long, unsigned long*, int))dlsym(_aipl_x11_lib, "XSetWMProtocols");
        _aipl_X11_XCreateGC = (void* (*)(void*, unsigned long, unsigned long, void*))dlsym(_aipl_x11_lib, "XCreateGC");
        _aipl_X11_XFreeGC = (int (*)(void*, void*))dlsym(_aipl_x11_lib, "XFreeGC");
        _aipl_X11_XCreateImage = (void* (*)(void*, void*, unsigned int, int, int, char*, unsigned int, unsigned int, int, int))dlsym(_aipl_x11_lib, "XCreateImage");
        _aipl_X11_XPutImage = (int (*)(void*, unsigned long, void*, void*, int, int, int, int, unsigned int, unsigned int))dlsym(_aipl_x11_lib, "XPutImage");
        _aipl_X11_XResizeWindow = (int (*)(void*, unsigned long, unsigned int, unsigned int))dlsym(_aipl_x11_lib, "XResizeWindow");
        _aipl_X11_XMoveWindow = (int (*)(void*, unsigned long, int, int))dlsym(_aipl_x11_lib, "XMoveWindow");
        _aipl_X11_XLookupKeysym = (unsigned long (*)(void*, int))dlsym(_aipl_x11_lib, "XLookupKeysym");
        _aipl_X11_XSync = (int (*)(void*, int))dlsym(_aipl_x11_lib, "XSync");
      }
    }
    if (_aipl_X11_XOpenDisplay && _aipl_X11_XCreateSimpleWindow && _aipl_X11_XMapWindow) {
      _aipl_x11_dpy = _aipl_X11_XOpenDisplay(NULL);
      if (_aipl_x11_dpy) {
        int scr = _aipl_X11_XDefaultScreen ? _aipl_X11_XDefaultScreen(_aipl_x11_dpy) : 0;
        unsigned long root = _aipl_X11_XRootWindow(_aipl_x11_dpy, scr);
        unsigned long black = _aipl_X11_XBlackPixel ? _aipl_X11_XBlackPixel(_aipl_x11_dpy, scr) : 0UL;
        int (*fn_XDisplayWidth)(void*, int) = (int (*)(void*, int))dlsym(_aipl_x11_lib, "XDisplayWidth");
        int (*fn_XDisplayHeight)(void*, int) = (int (*)(void*, int))dlsym(_aipl_x11_lib, "XDisplayHeight");
        int screenW = (fn_XDisplayWidth && _aipl_x11_dpy) ? fn_XDisplayWidth(_aipl_x11_dpy, scr) : 1920;
        int screenH = (fn_XDisplayHeight && _aipl_x11_dpy) ? fn_XDisplayHeight(_aipl_x11_dpy, scr) : 1080;
        int init_x = 40, init_y = 40;
        _aipl_compute_initial_window_pos(_aipl_canvas_w, _aipl_canvas_h, screenW, screenH, &init_x, &init_y);

        if (_aipl_cli_window_mode_override >= 0) {
          _aipl_requested_window_mode = _aipl_cli_window_mode_override;
          strcpy(_aipl_window_mode_name, _aipl_cli_window_mode_override == 2 ? "glx" : (_aipl_cli_window_mode_override == 0 ? "auto" : "x11"));
          aipl_rt_setSoftwareRasterizer(aipl_bool(_aipl_cli_window_mode_override == 1));
        }

        /* Mode 2: Game X11 + libGL.so.1 GLX Hardware Renderer when requested */
        if (_aipl_requested_window_mode == 2 || _aipl_requested_window_mode == 0) {
          if (_aipl_benchmark_window_fps || _aipl_unlocked_fps || _aipl_target_fps == 0) {
            setenv("vblank_mode", "0", 0);
            setenv("__GL_SYNC_TO_VBLANK", "0", 0);
          }
          if (!_aipl_gl_lib) {
            _aipl_gl_lib = dlopen("libGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
            if (_aipl_gl_lib) {
              _aipl_glXChooseVisual = (void* (*)(void*, int, int*))dlsym(_aipl_gl_lib, "glXChooseVisual");
              _aipl_glXCreateContext = (void* (*)(void*, void*, void*, int))dlsym(_aipl_gl_lib, "glXCreateContext");
              _aipl_glXMakeCurrent = (int (*)(void*, unsigned long, void*))dlsym(_aipl_gl_lib, "glXMakeCurrent");
              _aipl_glXSwapBuffers = (void (*)(void*, unsigned long))dlsym(_aipl_gl_lib, "glXSwapBuffers");
              _aipl_glXDestroyContext = (void (*)(void*, void*))dlsym(_aipl_gl_lib, "glXDestroyContext");
              _aipl_glXGetProcAddress = (void* (*)(const unsigned char*))dlsym(_aipl_gl_lib, "glXGetProcAddressARB");
              if (!_aipl_glXGetProcAddress) _aipl_glXGetProcAddress = (void* (*)(const unsigned char*))dlsym(_aipl_gl_lib, "glXGetProcAddress");
              _aipl_glViewport = (void (*)(int, int, int, int))dlsym(_aipl_gl_lib, "glViewport");
              _aipl_glMatrixMode = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glMatrixMode");
              _aipl_glLoadIdentity = (void (*)(void))dlsym(_aipl_gl_lib, "glLoadIdentity");
              _aipl_glOrtho = (void (*)(double, double, double, double, double, double))dlsym(_aipl_gl_lib, "glOrtho");
              _aipl_glClearColor = (void (*)(float, float, float, float))dlsym(_aipl_gl_lib, "glClearColor");
              _aipl_glClear = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glClear");
              _aipl_glEnable = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glEnable");
              _aipl_glDisable = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glDisable");
              _aipl_glBlendFunc = (void (*)(unsigned int, unsigned int))dlsym(_aipl_gl_lib, "glBlendFunc");
              _aipl_glScissor = (void (*)(int, int, int, int))dlsym(_aipl_gl_lib, "glScissor");
              _aipl_glVertexPointer = (void (*)(int, unsigned int, int, const void*))dlsym(_aipl_gl_lib, "glVertexPointer");
              _aipl_glColorPointer = (void (*)(int, unsigned int, int, const void*))dlsym(_aipl_gl_lib, "glColorPointer");
              _aipl_glTexCoordPointer = (void (*)(int, unsigned int, int, const void*))dlsym(_aipl_gl_lib, "glTexCoordPointer");
              _aipl_glEnableClientState = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glEnableClientState");
              _aipl_glDisableClientState = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glDisableClientState");
              _aipl_glDrawArrays = (void (*)(unsigned int, int, int))dlsym(_aipl_gl_lib, "glDrawArrays");
              _aipl_glReadPixels = (void (*)(int, int, int, int, unsigned int, unsigned int, void*))dlsym(_aipl_gl_lib, "glReadPixels");
              _aipl_glDepthFunc = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glDepthFunc");
              _aipl_glDepthMask = (void (*)(unsigned char))dlsym(_aipl_gl_lib, "glDepthMask");
              _aipl_glClearDepth = (void (*)(double))dlsym(_aipl_gl_lib, "glClearDepth");
              _aipl_glColorMask = (void (*)(unsigned char, unsigned char, unsigned char, unsigned char))dlsym(_aipl_gl_lib, "glColorMask");
              _aipl_glShadeModel = (void (*)(unsigned int))dlsym(_aipl_gl_lib, "glShadeModel");
              _aipl_glGenTextures = (void (*)(int, unsigned int*))dlsym(_aipl_gl_lib, "glGenTextures");
              _aipl_glDeleteTextures = (void (*)(int, const unsigned int*))dlsym(_aipl_gl_lib, "glDeleteTextures");
              _aipl_glBindTexture = (void (*)(unsigned int, unsigned int))dlsym(_aipl_gl_lib, "glBindTexture");
              _aipl_glTexImage2D = (void (*)(unsigned int, int, int, int, int, int, unsigned int, unsigned int, const void*))dlsym(_aipl_gl_lib, "glTexImage2D");
              _aipl_glTexParameteri = (void (*)(unsigned int, unsigned int, int))dlsym(_aipl_gl_lib, "glTexParameteri");
              _aipl_glAlphaFunc = (void (*)(unsigned int, float))dlsym(_aipl_gl_lib, "glAlphaFunc");
            }
          }
          if (_aipl_glXChooseVisual && _aipl_glXCreateContext && _aipl_glXMakeCurrent && _aipl_glXSwapBuffers) {
            int attribs[] = { 4 /* GLX_RGBA */, 5 /* GLX_DOUBLEBUFFER */, 8 /* GLX_RED_SIZE */, 8, 9 /* GLX_GREEN_SIZE */, 8, 10 /* GLX_BLUE_SIZE */, 8, 12 /* GLX_DEPTH_SIZE */, 16, 0 };
            void* xv = _aipl_glXChooseVisual(_aipl_x11_dpy, scr, attribs);
            if (!xv) {
              int fallback_attribs[] = { 4 /* GLX_RGBA */, 5 /* GLX_DOUBLEBUFFER */, 0 };
              xv = _aipl_glXChooseVisual(_aipl_x11_dpy, scr, fallback_attribs);
            }
            if (xv) {
              _aipl_glx_ctx = _aipl_glXCreateContext(_aipl_x11_dpy, xv, NULL, 1);
              if (!_aipl_glx_ctx) _aipl_glx_ctx = _aipl_glXCreateContext(_aipl_x11_dpy, xv, NULL, 0);
              if (_aipl_glx_ctx) {
                typedef struct {
                  void* visual;
                  unsigned long visualid;
                  int screen;
                  int depth;
                  int c_class;
                  unsigned long red_mask, green_mask, blue_mask;
                  int colormap_size;
                  int bits_per_rgb;
                } _AiplXVisualInfo;
                typedef struct {
                  unsigned long background_pixmap;
                  unsigned long background_pixel;
                  unsigned long border_pixmap;
                  unsigned long border_pixel;
                  int bit_gravity;
                  int win_gravity;
                  int backing_store;
                  unsigned long backing_planes;
                  unsigned long backing_pixel;
                  int save_under;
                  long event_mask;
                  long do_not_propagate_mask;
                  int override_redirect;
                  unsigned long colormap;
                  unsigned long cursor;
                } _AiplXSetWindowAttributes;
                unsigned long (*fn_XCreateColormap)(void*, unsigned long, void*, int) =
                  (unsigned long (*)(void*, unsigned long, void*, int))dlsym(_aipl_x11_lib, "XCreateColormap");
                unsigned long (*fn_XCreateWindow)(void*, unsigned long, int, int, unsigned int, unsigned int, unsigned int, int, unsigned int, void*, unsigned long, void*) =
                  (unsigned long (*)(void*, unsigned long, int, int, unsigned int, unsigned int, unsigned int, int, unsigned int, void*, unsigned long, void*))dlsym(_aipl_x11_lib, "XCreateWindow");
                _AiplXVisualInfo* xvi = (_AiplXVisualInfo*)xv;
                _aipl_x11_win = 0;
                if (fn_XCreateColormap && fn_XCreateWindow && xvi && xvi->visual) {
                  unsigned long cmap = fn_XCreateColormap(_aipl_x11_dpy, root, xvi->visual, 0 /* AllocNone */);
                  _AiplXSetWindowAttributes swa;
                  memset(&swa, 0, sizeof(swa));
                  swa.colormap = cmap;
                  swa.background_pixmap = 0UL /* None: avoid X11 black background erase flicker */;
                  swa.border_pixel = 0UL;
                  swa.event_mask = 0x0002FFFFL;
                  unsigned long cw_mask = (1UL << 0) /* CWBackPixmap */ | (1UL << 3) /* CWBorderPixel */ | (1UL << 11) /* CWEventMask */ | (1UL << 13) /* CWColormap */;
                  _aipl_x11_win = fn_XCreateWindow(_aipl_x11_dpy, root, init_x, init_y, (unsigned int)_aipl_canvas_w, (unsigned int)_aipl_canvas_h, 0, xvi->depth, 1 /* InputOutput */, xvi->visual, cw_mask, &swa);
                }
                if (!_aipl_x11_win) {
                  _aipl_x11_win = _aipl_X11_XCreateSimpleWindow(_aipl_x11_dpy, root, init_x, init_y, (unsigned int)_aipl_canvas_w, (unsigned int)_aipl_canvas_h, 1, black, black);
                }
                if (_aipl_X11_XStoreName) _aipl_X11_XStoreName(_aipl_x11_dpy, _aipl_x11_win, title_str);
                if (_aipl_X11_XInternAtom && _aipl_X11_XSetWMProtocols) {
                  _aipl_wm_delete = _aipl_X11_XInternAtom(_aipl_x11_dpy, "WM_DELETE_WINDOW", 0);
                  if (_aipl_wm_delete) _aipl_X11_XSetWMProtocols(_aipl_x11_dpy, _aipl_x11_win, &_aipl_wm_delete, 1);
                }
                if (_aipl_X11_XSelectInput) _aipl_X11_XSelectInput(_aipl_x11_dpy, _aipl_x11_win, 0x0002FFFFL);
                _aipl_X11_XMapWindow(_aipl_x11_dpy, _aipl_x11_win);
                if (_aipl_X11_XMoveWindow) _aipl_X11_XMoveWindow(_aipl_x11_dpy, _aipl_x11_win, init_x, init_y);
                if (_aipl_glXMakeCurrent(_aipl_x11_dpy, _aipl_x11_win, _aipl_glx_ctx)) {
                  if (_aipl_glXGetProcAddress && (_aipl_benchmark_window_fps || _aipl_unlocked_fps || _aipl_target_fps == 0)) {
                    void (*swap_ext)(void*, unsigned long, int) = (void (*)(void*, unsigned long, int))_aipl_glXGetProcAddress((const unsigned char*)"glXSwapIntervalEXT");
                    int (*swap_mesa)(unsigned int) = (int (*)(unsigned int))_aipl_glXGetProcAddress((const unsigned char*)"glXSwapIntervalMESA");
                    if (swap_ext) swap_ext(_aipl_x11_dpy, _aipl_x11_win, 0);
                    if (swap_mesa) swap_mesa(0);
                  }
                  if (_aipl_glViewport) _aipl_glViewport(0, 0, _aipl_canvas_w, _aipl_canvas_h);
                  if (_aipl_glMatrixMode) _aipl_glMatrixMode(0x1701 /* GL_PROJECTION */);
                  if (_aipl_glLoadIdentity) _aipl_glLoadIdentity();
                  if (_aipl_glOrtho) _aipl_glOrtho(0.0, (double)_aipl_canvas_w, (double)_aipl_canvas_h, 0.0, -1.0, 1.0);
                  if (_aipl_glMatrixMode) _aipl_glMatrixMode(0x1700 /* GL_MODELVIEW */);
                  if (_aipl_glLoadIdentity) _aipl_glLoadIdentity();
                  if (_aipl_glShadeModel) _aipl_glShadeModel(0x1D01 /* GL_SMOOTH */);
                  if (_aipl_glEnable) _aipl_glEnable(0x0BE2 /* GL_BLEND */);
                  if (_aipl_glBlendFunc) _aipl_glBlendFunc(0x0302 /* GL_SRC_ALPHA */, 0x0303 /* GL_ONE_MINUS_SRC_ALPHA */);
                  if (_aipl_glColorMask) _aipl_glColorMask(1, 1, 1, 1);
                  if (_aipl_glClearColor) _aipl_glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                  if (_aipl_glClearDepth) _aipl_glClearDepth(1.0);
                  if (_aipl_glClear) _aipl_glClear(0x00004000 /* GL_COLOR_BUFFER_BIT */ | 0x00000100 /* GL_DEPTH_BUFFER_BIT */);
                  if (_aipl_glColorMask) _aipl_glColorMask(1, 1, 1, 0);
                  _aipl_canvas_fb = (uint8_t*)calloc((size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h * 4, 1);
                  _aipl_window_backend = 2;
                  strncpy(_aipl_window_mode_name, "glx", sizeof(_aipl_window_mode_name) - 1);
                } else {
                  if (_aipl_glXDestroyContext) _aipl_glXDestroyContext(_aipl_x11_dpy, _aipl_glx_ctx);
                  _aipl_glx_ctx = NULL;
                  if (_aipl_x11_win && _aipl_X11_XDestroyWindow) _aipl_X11_XDestroyWindow(_aipl_x11_dpy, _aipl_x11_win);
                  _aipl_x11_win = 0;
                }
              }
              if (_aipl_X11_XFree) _aipl_X11_XFree(xv);
            }
          }
        }

        /* Mode 1: Normal Desktop Application Mode (X11 + MIT-SHM via libXext.so.6) */
        if (_aipl_window_backend == 0 && _aipl_X11_XCreateGC && _aipl_X11_XCreateImage && _aipl_X11_XPutImage) {
          if (!_aipl_xext_lib) {
            _aipl_xext_lib = dlopen("libXext.so.6", RTLD_LAZY);
            if (_aipl_xext_lib) {
              _aipl_XShmQueryExtension = (int (*)(void*))dlsym(_aipl_xext_lib, "XShmQueryExtension");
              _aipl_XShmCreateImage = (void* (*)(void*, void*, unsigned int, int, char*, _AiplXShmSegmentInfo*, unsigned int, unsigned int))dlsym(_aipl_xext_lib, "XShmCreateImage");
              _aipl_XShmAttach = (int (*)(void*, _AiplXShmSegmentInfo*))dlsym(_aipl_xext_lib, "XShmAttach");
              _aipl_XShmDetach = (int (*)(void*, _AiplXShmSegmentInfo*))dlsym(_aipl_xext_lib, "XShmDetach");
              _aipl_XShmPutImage = (int (*)(void*, unsigned long, void*, void*, int, int, int, int, unsigned int, unsigned int, int))dlsym(_aipl_xext_lib, "XShmPutImage");
            }
          }
          _aipl_xshm_available = (_aipl_XShmQueryExtension && _aipl_XShmQueryExtension(_aipl_x11_dpy)) ? 1 : 0;
          _aipl_x11_win = _aipl_X11_XCreateSimpleWindow(_aipl_x11_dpy, root, init_x, init_y, (unsigned int)_aipl_canvas_w, (unsigned int)_aipl_canvas_h, 1, black, black);
          if (_aipl_X11_XStoreName) _aipl_X11_XStoreName(_aipl_x11_dpy, _aipl_x11_win, title_str);
          if (_aipl_X11_XInternAtom && _aipl_X11_XSetWMProtocols) {
            _aipl_wm_delete = _aipl_X11_XInternAtom(_aipl_x11_dpy, "WM_DELETE_WINDOW", 0);
            if (_aipl_wm_delete) _aipl_X11_XSetWMProtocols(_aipl_x11_dpy, _aipl_x11_win, &_aipl_wm_delete, 1);
          }
          if (_aipl_X11_XSelectInput) _aipl_X11_XSelectInput(_aipl_x11_dpy, _aipl_x11_win, 0x0002FFFFL);
          _aipl_X11_XMapWindow(_aipl_x11_dpy, _aipl_x11_win);
          if (_aipl_X11_XMoveWindow) _aipl_X11_XMoveWindow(_aipl_x11_dpy, _aipl_x11_win, init_x, init_y);
          _aipl_x11_gc = _aipl_X11_XCreateGC(_aipl_x11_dpy, _aipl_x11_win, 0UL, NULL);
          _aipl_window_backend = 1;
          strncpy(_aipl_window_mode_name, "x11", sizeof(_aipl_window_mode_name) - 1);
          _aipl_alloc_x11_image_and_fb(_aipl_canvas_w, _aipl_canvas_h);
        }

        if (_aipl_window_backend != 0) {
          if (_aipl_target_fps <= 0 && !_aipl_benchmark_window_fps && !_aipl_unlocked_fps && _aipl_cli_max_fps_override < 0) {
            _aipl_target_fps = 60;
          }
          if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
          for (int _w = 0; _w < 15; _w++) {
            if (_aipl_X11_XPending && _aipl_X11_XPending(_aipl_x11_dpy) > 0) break;
            struct timespec req = { 0, 1000000L };
            nanosleep(&req, NULL);
          }
          _aipl_pump_events();
        }
      }
    }
  }
#else
  (void)title;
#endif
  if (!_aipl_canvas_fb) {
    _aipl_canvas_fb = (uint8_t*)calloc((size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h * 4, 1);
  }
  const char* auto_vid = getenv("AIPL_VIDEO_PATH");
  if (auto_vid && auto_vid[0]) {
    aipl_rt_startVideoRecording(aipl_str(auto_vid), aipl_int(_aipl_target_fps > 0 ? _aipl_target_fps : 60));
  }
  if (!_aipl_atexit_registered) {
    atexit(_aipl_cleanup_window_registry);
    _aipl_atexit_registered = 1;
  }
  if (_aipl_window_backend == 0) {
    _aipl_compute_initial_window_pos(_aipl_canvas_w, _aipl_canvas_h, 1920, 1080, NULL, NULL);
  }
  _aipl_write_window_info();
  const char* env_verbose = getenv("AIPL_VERBOSE");
  if (env_verbose && strcmp(env_verbose, "1") == 0) {
    fprintf(stderr, "[AIPL Runtime:Verbose] initWindow title=\"%s\" size=%dx%d backend=%s x11_win=0x%lx target_fps=%d pid=%d\n",
      _aipl_win_title[0] ? _aipl_win_title : "AIPL Window",
      _aipl_canvas_w, _aipl_canvas_h,
      (_aipl_window_backend == 2 ? "glx" : (_aipl_window_backend == 1 ? "x11" : "headless")),
      _aipl_x11_win, _aipl_target_fps, (int)getpid());
    fflush(stderr);
  }
  return aipl_nil();
}

AiplVal aipl_rt_initCanvas(AiplVal w, AiplVal h) {
  return aipl_rt_initWindow(w, h, aipl_str_lit("AIPL Canvas"));
}

extern float* _aipl_zbuffer;
extern float* _aipl_canvas_zb;
extern size_t _aipl_zbuffer_cap;

AiplVal aipl_rt_closeWindow(void) {
  const char* env_verbose = getenv("AIPL_VERBOSE");
  if (env_verbose && strcmp(env_verbose, "1") == 0) {
    fprintf(stderr, "[AIPL Runtime:Verbose] closeWindow title=\"%s\" frames=%d last_fps=%.2f frame_time_ms=%.3f\n",
      _aipl_win_title[0] ? _aipl_win_title : "AIPL Window",
      _aipl_frames, _aipl_current_fps, _aipl_frame_time_ms);
    fflush(stderr);
  }
  aipl_rt_stopVideoRecording();
  _aipl_stop_and_cleanup_audio();
  _aipl_destroy_x11_image_and_fb();
  if (_aipl_zbuffer) { free(_aipl_zbuffer); _aipl_zbuffer = NULL; _aipl_canvas_zb = NULL; _aipl_zbuffer_cap = 0; }
  _aipl_depth_test_enabled = 0;
  _aipl_gl_vert_count = 0;
  _aipl_gl_fb_dirty = 0;
  _aipl_gl_cur_tex_id = 0;
  if (_aipl_images) {
    for (int _ti = 1; _ti < _aipl_images_cap; _ti++) {
#ifndef _WIN32
      if (_aipl_images[_ti].gl_tex_id != 0 && _aipl_window_backend == 2 && _aipl_glx_ctx && _aipl_glDeleteTextures) {
        _aipl_glDeleteTextures(1, &_aipl_images[_ti].gl_tex_id);
      }
#endif
      _aipl_images[_ti].gl_tex_id = 0;
      _aipl_images[_ti].gl_dirty = 1;
    }
  }
#ifndef _WIN32
  if (_aipl_x11_dpy) {
    if (_aipl_glx_ctx) {
      if (_aipl_glXMakeCurrent) _aipl_glXMakeCurrent(_aipl_x11_dpy, 0UL, NULL);
      if (_aipl_glXDestroyContext) _aipl_glXDestroyContext(_aipl_x11_dpy, _aipl_glx_ctx);
      _aipl_glx_ctx = NULL;
    }
    if (_aipl_x11_gc && _aipl_X11_XFreeGC) { _aipl_X11_XFreeGC(_aipl_x11_dpy, _aipl_x11_gc); _aipl_x11_gc = NULL; }
    if (_aipl_x11_win && _aipl_X11_XDestroyWindow) { _aipl_X11_XDestroyWindow(_aipl_x11_dpy, _aipl_x11_win); _aipl_x11_win = 0; }
    if (_aipl_X11_XCloseDisplay) _aipl_X11_XCloseDisplay(_aipl_x11_dpy);
    _aipl_x11_dpy = NULL;
  }
#endif
  _aipl_window_backend = 0;
  return aipl_nil();
}

AiplVal aipl_rt_canvasBackendName(void) {
  return aipl_str_lit(_aipl_window_backend == 2 ? "glx" : (_aipl_window_backend == 1 ? "x11" : "headless"));
}

AiplVal aipl_rt_isHeadlessMode(void) {
  _aipl_check_fps_cli_flags();
  if (_aipl_benchmark_window_fps) return aipl_bool(false);
  return aipl_bool(_aipl_window_backend == 0);
}

AiplVal aipl_rt_setTargetFps(AiplVal fps) {
  _aipl_check_fps_cli_flags();
  if (_aipl_benchmark_window_fps && _aipl_cli_max_fps_override < 0) {
    _aipl_target_fps = 0;
    return aipl_nil();
  }
  if (_aipl_cli_max_fps_override >= 0) {
    _aipl_target_fps = _aipl_cli_max_fps_override;
    if (_aipl_target_fps > 0) _aipl_frame_dt = 1.0 / (double)_aipl_target_fps;
    return aipl_nil();
  }
  int f = (int)((fps.kind == AIPL_FLOAT) ? fps.f : fps.i);
  _aipl_target_fps = (f > 0) ? f : 0;
  if (_aipl_target_fps > 0) _aipl_frame_dt = 1.0 / (double)_aipl_target_fps;
  return aipl_nil();
}

AiplVal aipl_rt_setMaxFps(AiplVal fps) {
  return aipl_rt_setTargetFps(fps);
}

AiplVal aipl_rt_getMaxFps(void) {
  _aipl_check_fps_cli_flags();
  return aipl_int(_aipl_target_fps);
}

AiplVal aipl_rt_getCurrentFps(void) {
  return aipl_int((int64_t)(_aipl_current_fps + 0.5));
}

AiplVal aipl_rt_getFrameTimeMs(void) {
  return aipl_float(_aipl_frame_time_ms);
}

AiplVal aipl_rt_setWindowTitle(AiplVal title) {
#ifndef _WIN32
  if ((_aipl_window_backend == 1 || _aipl_window_backend == 2) && _aipl_x11_dpy && _aipl_x11_win && _aipl_X11_XStoreName) {
    const char* t = (title.kind == AIPL_STR && title.s) ? title.s : "AIPL Window";
    _aipl_X11_XStoreName(_aipl_x11_dpy, _aipl_x11_win, t);
    if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
  }
#else
  (void)title;
#endif
  return aipl_nil();
}

AiplVal aipl_rt_setWindowSize(AiplVal w, AiplVal h) {
  int nw = (int)((w.kind == AIPL_FLOAT) ? w.f : w.i);
  int nh = (int)((h.kind == AIPL_FLOAT) ? h.f : h.i);
  _aipl_resize_framebuffer(nw, nh);
#ifndef _WIN32
  if ((_aipl_window_backend == 1 || _aipl_window_backend == 2) && _aipl_x11_dpy && _aipl_x11_win && _aipl_X11_XResizeWindow) {
    _aipl_X11_XResizeWindow(_aipl_x11_dpy, _aipl_x11_win, (unsigned int)_aipl_canvas_w, (unsigned int)_aipl_canvas_h);
    if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
  }
#endif
  return aipl_nil();
}

AiplVal aipl_rt_isWindowResized(void) {
  return aipl_bool(_aipl_window_resized != 0);
}

AiplVal aipl_rt_setWindowMinSize(AiplVal w, AiplVal h) {
  int mw = (int)((w.kind == AIPL_FLOAT) ? w.f : w.i);
  int mh = (int)((h.kind == AIPL_FLOAT) ? h.f : h.i);
  if (mw >= 100) _aipl_window_min_w = mw;
  if (mh >= 100) _aipl_window_min_h = mh;
  return aipl_nil();
}

AiplVal aipl_rt_getContentScale(void) {
  return aipl_float(1.0);
}

AiplVal aipl_rt_windowShouldClose(void) {
  _aipl_check_fps_cli_flags();
  _aipl_pump_events();
  _aipl_events_pumped_this_frame = 1;
  if (_aipl_window_closed) return aipl_bool(true);
  if (_aipl_benchmark_window_fps) {
    _aipl_frames++;
    return aipl_bool(_aipl_frames > 130);
  }
  int _aipl_cur_limit = _aipl_get_max_frames_limit();
  if (_aipl_cur_limit >= 0) {
    return aipl_bool(_aipl_frames++ >= _aipl_cur_limit);
  }
  if (_aipl_window_backend == 1 || _aipl_window_backend == 2) {
    _aipl_frames++;
    return aipl_bool(_aipl_window_closed != 0);
  }
  return aipl_bool(_aipl_frames++ >= 1);
}

AiplVal aipl_rt_getScreenWidth(void) { return aipl_int(_aipl_canvas_w > 0 ? _aipl_canvas_w : 800); }

AiplVal aipl_rt_getScreenHeight(void) { return aipl_int(_aipl_canvas_h > 0 ? _aipl_canvas_h : 600); }

AiplVal aipl_rt_getFrameTime(void) { return aipl_float(_aipl_frame_dt); }

AiplVal aipl_rt_getScaleFactor(void) { return aipl_float(1.0); }

static AiplArenaPage* _aipl_frame_arena_saved = NULL;
AiplVal aipl_rt_beginDrawing(void) {
  _aipl_sg_reset_frame();
  _aipl_gl_vert_count = 0;
  _aipl_gl_frame_hash = 1469598103934665603ULL;
  if (!_aipl_events_pumped_this_frame) {
    _aipl_pump_events();
    _aipl_events_pumped_this_frame = 1;
  }
  if (!_aipl_frame_arena_saved) {
    _aipl_frame_arena_saved = aipl_arena_push();
  }
  return aipl_nil();
}

int _aipl_save_fb_to_ppm(const char* ppm_path) {
  _aipl_sync_gl_to_fb();
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb || _aipl_canvas_w <= 0 || _aipl_canvas_h <= 0) return 0;
  FILE* fp = fopen(ppm_path, "wb");
  if (!fp) return 0;
  fprintf(fp, "P6\n%d %d\n255\n", _aipl_canvas_w, _aipl_canvas_h);
  uint8_t* row = (uint8_t*)malloc((size_t)_aipl_canvas_w * 3);
  if (!row) { fclose(fp); return 0; }
  for (int y = 0; y < _aipl_canvas_h; y++) {
    for (int x = 0; x < _aipl_canvas_w; x++) {
      size_t src = ((size_t)y * (size_t)_aipl_canvas_w + (size_t)x) * 4;
      row[x * 3]     = _aipl_canvas_fb[src + 2];
      row[x * 3 + 1] = _aipl_canvas_fb[src + 1];
      row[x * 3 + 2] = _aipl_canvas_fb[src];
    }
    fwrite(row, 1, (size_t)_aipl_canvas_w * 3, fp);
  }
  free(row);
  fclose(fp);
  return 1;
}

static const char* _aipl_get_cli_screenshot_path(void) {
  const char* shot_path = getenv("AIPL_SCREENSHOT_PATH");
  if ((!shot_path || !shot_path[0]) && g_aipl_argv) {
    for (int _si = 1; _si < g_aipl_argc; _si++) {
      if (g_aipl_argv[_si] && (strcmp(g_aipl_argv[_si], "--screenshot") == 0 || strcmp(g_aipl_argv[_si], "--screenshot-on-exit") == 0) && _si + 1 < g_aipl_argc && g_aipl_argv[_si + 1] && g_aipl_argv[_si + 1][0] != '-') {
        shot_path = g_aipl_argv[_si + 1];
      } else if (g_aipl_argv[_si] && strncmp(g_aipl_argv[_si], "--screenshot=", 13) == 0) {
        shot_path = g_aipl_argv[_si] + 13;
      } else if (g_aipl_argv[_si] && strncmp(g_aipl_argv[_si], "--screenshot-on-exit=", 21) == 0) {
        shot_path = g_aipl_argv[_si] + 21;
      }
    }
  }
  return shot_path;
}

static int _aipl_has_screenshot_on_exit_flag(void) {
  const char* env_exit = getenv("AIPL_SCREENSHOT_ON_EXIT");
  if (env_exit && env_exit[0] && strcmp(env_exit, "0") != 0) return 1;
  if (g_aipl_argv) {
    for (int _si = 1; _si < g_aipl_argc; _si++) {
      if (g_aipl_argv[_si] && (strcmp(g_aipl_argv[_si], "--screenshot-on-exit") == 0 || strncmp(g_aipl_argv[_si], "--screenshot-on-exit=", 21) == 0)) {
        return 1;
      }
    }
  }
  return 0;
}

AiplVal aipl_rt_endDrawing(void) {
#ifndef _WIN32
  if (_aipl_window_backend == 2) {
    _aipl_gl_flush_batch();
  }
#endif
  const char* shot_path = _aipl_get_cli_screenshot_path();
  const char* env_shot_frame = getenv("AIPL_SCREENSHOT_FRAME");
  if ((!env_shot_frame || !env_shot_frame[0]) && g_aipl_argv) {
    for (int _si = 1; _si < g_aipl_argc; _si++) {
      if (g_aipl_argv[_si] && strcmp(g_aipl_argv[_si], "--snapshot-frame") == 0 && _si + 1 < g_aipl_argc && g_aipl_argv[_si + 1]) {
        env_shot_frame = g_aipl_argv[_si + 1];
      } else if (g_aipl_argv[_si] && strncmp(g_aipl_argv[_si], "--snapshot-frame=", 17) == 0) {
        env_shot_frame = g_aipl_argv[_si] + 17;
      }
    }
  }
  int should_shot = 0;
  if (shot_path && shot_path[0]) {
    int _aipl_cur_limit = _aipl_get_max_frames_limit();
    int shot_frame = (env_shot_frame && env_shot_frame[0]) ? atoi(env_shot_frame) : (_aipl_cur_limit > 0 ? _aipl_cur_limit - 1 : 1);
    if (shot_frame < 1) shot_frame = 1;
    if (!_aipl_shot_taken) {
      if (_aipl_frames == shot_frame) should_shot = 1;
      else if (_aipl_cur_limit > 0 && _aipl_frames >= _aipl_cur_limit - 1) should_shot = 1;
    } else if (_aipl_has_screenshot_on_exit_flag() && _aipl_cur_limit > 0 && _aipl_frames == _aipl_cur_limit - 1) {
      should_shot = 1;
    }
  }
  if (_aipl_window_backend == 2 && (should_shot || _aipl_video_recording)) {
    _aipl_sync_gl_to_fb();
  }
#ifndef _WIN32
  int do_present = 1;
  if (do_present) {
    if (_aipl_window_backend == 1 && _aipl_x11_dpy && _aipl_x11_win && _aipl_x11_gc && _aipl_x11_img && _aipl_canvas_fb) {
      if (_aipl_xshm_active && _aipl_XShmPutImage) {
        if (_aipl_xshm_info.shmaddr && (void*)_aipl_canvas_fb != (void*)_aipl_xshm_info.shmaddr) {
          memcpy(_aipl_xshm_info.shmaddr, _aipl_canvas_fb, (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h * 4);
        }
        _aipl_XShmPutImage(_aipl_x11_dpy, _aipl_x11_win, _aipl_x11_gc, _aipl_x11_img, 0, 0, 0, 0, (unsigned int)_aipl_canvas_w, (unsigned int)_aipl_canvas_h, 0);
        if (_aipl_X11_XSync) _aipl_X11_XSync(_aipl_x11_dpy, 0);
      } else if (_aipl_X11_XPutImage) {
        _aipl_X11_XPutImage(_aipl_x11_dpy, _aipl_x11_win, _aipl_x11_gc, _aipl_x11_img, 0, 0, 0, 0, (unsigned int)_aipl_canvas_w, (unsigned int)_aipl_canvas_h);
        if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
      }
    } else if (_aipl_window_backend == 2 && _aipl_x11_dpy && _aipl_x11_win) {
      if (_aipl_glXSwapBuffers) _aipl_glXSwapBuffers(_aipl_x11_dpy, _aipl_x11_win);
      if (_aipl_X11_XFlush) _aipl_X11_XFlush(_aipl_x11_dpy);
    }
  }
  {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    int64_t now_ns = (int64_t)ts.tv_sec * 1000000000LL + (int64_t)ts.tv_nsec;
    if (_aipl_benchmark_window_fps) {
      if (_aipl_frames == 5) {
        _aipl_bench_start_ns = now_ns;
      } else if (_aipl_frames >= 125 && _aipl_bench_start_ns > 0) {
        int64_t bench_elapsed_ns = now_ns - _aipl_bench_start_ns;
        double elapsed_ms = (double)bench_elapsed_ns / 1000000.0;
        if (elapsed_ms < 0.001) elapsed_ms = 0.001;
        double measured_fps = 120000.0 / elapsed_ms;
        const char* status_str = (measured_fps >= 120.0) ? "PASS" : "FAIL";
        const char* mode_str = (_aipl_window_backend == 2 ? "glx" : (_aipl_window_backend == 1 ? "x11" : "headless"));
        printf("[WINDOW_FPS_BENCHMARK] res=%dx%d mode=%s frames=120 elapsedMs=%.2f measuredFps=%.2f maxFpsCap=%d minRequired=120.0 status=%s\n",
               _aipl_canvas_w, _aipl_canvas_h, mode_str, elapsed_ms, measured_fps, _aipl_target_fps, status_str);
        fflush(stdout);
        if (_aipl_frame_arena_saved) {
          aipl_arena_pop(_aipl_frame_arena_saved);
          _aipl_frame_arena_saved = NULL;
        }
        aipl_rt_closeWindow();
        exit((measured_fps >= 120.0) ? 0 : 1);
      }
    }
    if (_aipl_last_frame_ns > 0) {
      int64_t elapsed_ns = now_ns - _aipl_last_frame_ns;
      if ((_aipl_window_backend == 1 || _aipl_window_backend == 2) && _aipl_target_fps > 0 && !_aipl_benchmark_window_fps && !_aipl_unlocked_fps) {
        int64_t target_ns = 1000000000LL / (int64_t)_aipl_target_fps;
        if (elapsed_ns < target_ns) {
          int64_t sleep_ns = target_ns - elapsed_ns;
          struct timespec req = { (time_t)(sleep_ns / 1000000000LL), (long)(sleep_ns % 1000000000LL) };
          nanosleep(&req, NULL);
          clock_gettime(CLOCK_MONOTONIC, &ts);
          now_ns = (int64_t)ts.tv_sec * 1000000000LL + (int64_t)ts.tv_nsec;
          elapsed_ns = now_ns - _aipl_last_frame_ns;
        }
      }
      double dt = (double)elapsed_ns / 1000000000.0;
      if (dt > 0.000001) {
        _aipl_frame_time_ms = dt * 1000.0;
        double inst_fps = 1.0 / dt;
        _aipl_current_fps = (_aipl_current_fps <= 1.0) ? inst_fps : (_aipl_current_fps * 0.85 + inst_fps * 0.15);
      }
      if (dt < 0.0001) dt = 0.0001;
      if (dt > 0.1) dt = 0.1;
      _aipl_frame_dt = dt;
    }
    _aipl_last_frame_ns = now_ns;
  }
#endif
  if (should_shot && shot_path && shot_path[0]) {
    _aipl_shot_taken = 1;
    size_t plen = strlen(shot_path);
    int is_png = (plen >= 4 && strcasecmp(shot_path + plen - 4, ".png") == 0);
    char tmp_shot_ppm[256];
    snprintf(tmp_shot_ppm, sizeof(tmp_shot_ppm), "/tmp/_aipl_shot_tmp_%d.ppm", (int)getpid());
    const char* target_ppm = is_png ? tmp_shot_ppm : shot_path;
    if (_aipl_save_fb_to_ppm(target_ppm)) {
      if (is_png) {
        char scmd[1024];
        snprintf(scmd, sizeof(scmd), "python3 -c \"from PIL import Image; Image.open('%s').save('%s')\" 2>/dev/null || ffmpeg -y -i '%s' '%s' 2>/dev/null || convert '%s' '%s' 2>/dev/null", tmp_shot_ppm, shot_path, tmp_shot_ppm, shot_path, tmp_shot_ppm, shot_path);
        int sret = system(scmd); (void)sret;
        remove(tmp_shot_ppm);
      }
      if (getenv("AIPL_BOT_VERBOSE") && strcmp(getenv("AIPL_BOT_VERBOSE"), "1") == 0) {
        fprintf(stderr, "[AIPL-SCREENSHOT] Saved frame %d to %s\n", _aipl_frames, shot_path);
      }
    }
  }
  if (_aipl_video_recording) {
    aipl_rt_recordVideoFrame();
  }
  if (_aipl_ipc_record_frames_remaining > 0) {
    _aipl_ipc_record_frames_remaining--;
    if (_aipl_ipc_record_frames_remaining == 0) {
      aipl_rt_stopVideoRecording();
      if (_aipl_ipc_ack_path[0]) {
        FILE* _ackfp = fopen(_aipl_ipc_ack_path, "w");
        if (_ackfp) { fputs("OK\n", _ackfp); fclose(_ackfp); }
        _aipl_ipc_ack_path[0] = 0;
      }
    }
  }
  if (_aipl_benchmark_window_fps) {
    _aipl_events_pumped_this_frame = 0;
    if (_aipl_frame_arena_saved) {
      aipl_arena_pop(_aipl_frame_arena_saved);
      _aipl_frame_arena_saved = NULL;
    }
    return aipl_nil();
  }
  if (_aipl_frames % 15 == 0) {
    _aipl_write_window_info();
  }
  int ipc_cmd_handled = 0;
  int should_probe_ipc = (_aipl_frames <= 2) || ((_aipl_frames & 3) == 0) || (_aipl_window_backend == 0) || _aipl_ipc_telemetry_active;
  if (should_probe_ipc) {
    int max_seat = 8;
    for (int _seat = 0; _seat <= max_seat; _seat++) {
      char _cmd_path[256];
      char _ack_path[256];
      if (_seat == 0) {
        snprintf(_cmd_path, sizeof(_cmd_path), "/tmp/aipl_windows/win_%d.cmd", (int)getpid());
        snprintf(_ack_path, sizeof(_ack_path), "/tmp/aipl_windows/win_%d.ack", (int)getpid());
      } else {
        snprintf(_cmd_path, sizeof(_cmd_path), "/tmp/aipl_windows/win_%d.cmd.%d", (int)getpid(), _seat);
        snprintf(_ack_path, sizeof(_ack_path), "/tmp/aipl_windows/win_%d.ack.%d", (int)getpid(), _seat);
      }
      if (access(_cmd_path, F_OK) == 0) {
        _aipl_ipc_telemetry_active = 1;
        ipc_cmd_handled = 1;
        char _line[1024];
        _line[0] = 0;
        FILE* _cfp = fopen(_cmd_path, "r");
        if (_cfp) {
          if (fgets(_line, sizeof(_line), _cfp)) {
            size_t _llen = strlen(_line);
            while (_llen > 0 && (_line[_llen - 1] == '\n' || _line[_llen - 1] == '\r')) {
              _line[--_llen] = 0;
            }
          }
          fclose(_cfp);
        }
        /* Unlink command file BEFORE writing ACK so rapid back-to-back commands are never unlinked */
        unlink(_cmd_path);
        if (_line[0]) {
          if (strncmp(_line, "screenshot:", 11) == 0) {
            const char* out_p = _line + 11;
            aipl_rt_saveScreenshot(aipl_str(out_p));
            FILE* ack = fopen(_ack_path, "w");
            if (ack) { fputs("OK\n", ack); fclose(ack); }
          } else if (strncmp(_line, "record:", 7) == 0) {
            char* rest = _line + 7;
            char* c1 = strchr(rest, ':');
            if (c1) {
              *c1 = 0;
              char* out_p = rest;
              char* p2 = c1 + 1;
              char* c2 = strchr(p2, ':');
              int r_frames = 60, r_fps = 30;
              if (c2) {
                *c2 = 0;
                r_frames = atoi(p2);
                r_fps = atoi(c2 + 1);
              } else {
                r_frames = atoi(p2);
              }
              if (r_frames <= 0) r_frames = 30;
              if (r_fps <= 0) r_fps = 30;
              aipl_rt_startVideoRecording(aipl_str(out_p), aipl_int(r_fps));
              _aipl_ipc_record_frames_remaining = r_frames;
              strncpy(_aipl_ipc_ack_path, _ack_path, sizeof(_aipl_ipc_ack_path) - 1);
              _aipl_ipc_ack_path[sizeof(_aipl_ipc_ack_path) - 1] = 0;
            }
          } else {
            const char* script = (strncmp(_line, "action:", 7) == 0) ? (_line + 7) : _line;
            char seat_prefix[32];
            seat_prefix[0] = 0;
            if (_seat > 0) {
              snprintf(seat_prefix, sizeof(seat_prefix), "seat:%d;", _seat);
            }
            size_t cur_len = strlen(_aipl_pending_ipc_script);
            if (cur_len > 0 && cur_len + 2 < sizeof(_aipl_pending_ipc_script)) {
              _aipl_pending_ipc_script[cur_len++] = ';';
              _aipl_pending_ipc_script[cur_len] = 0;
            }
            if (seat_prefix[0] && cur_len + strlen(seat_prefix) < sizeof(_aipl_pending_ipc_script)) {
              strncat(_aipl_pending_ipc_script, seat_prefix, sizeof(_aipl_pending_ipc_script) - cur_len - 1);
              cur_len = strlen(_aipl_pending_ipc_script);
            }
            if (cur_len + strlen(script) < sizeof(_aipl_pending_ipc_script)) {
              strncat(_aipl_pending_ipc_script, script, sizeof(_aipl_pending_ipc_script) - cur_len - 1);
            }
            if (strstr(script, "screenshot:") || strstr(script, "record:") || _aipl_window_closed || _aipl_window_backend == 0) {
              if (seat_prefix[0]) {
                _aipl_parse_bot_script(seat_prefix);
              }
              _aipl_parse_bot_script(script);
            }
            _aipl_write_window_info();
            FILE* ack = fopen(_ack_path, "w");
            if (ack) { fputs("OK\n", ack); fclose(ack); }
          }
        }
      }
    }
  }
  if (!_aipl_audio_thread_active) {
    int has_active_voice = 0;
    for (int _vi = 0; _vi < _aipl_voices_cap; _vi++) {
      if (_aipl_voices && _aipl_voices[_vi].active) { has_active_voice = 1; break; }
    }
    if (has_active_voice || _aipl_audio_current_energy > 0.0001) {
      int16_t dummy_pcm[735 * 2];
      _aipl_audio_mix_samples(dummy_pcm, 735);
    }
  }
  if (_aipl_frames <= 1 || (_aipl_frames & 7) == 0 || ipc_cmd_handled || _aipl_bot_active_click_frame == _aipl_frames) {
    _aipl_write_window_state_json();
  }
  _aipl_events_pumped_this_frame = 0;
  if (_aipl_frame_arena_saved) {
    aipl_arena_pop(_aipl_frame_arena_saved);
    _aipl_frame_arena_saved = NULL;
  }
  return aipl_nil();
}

AiplVal aipl_rt_beginFrame(void) { return aipl_rt_beginDrawing(); }

AiplVal aipl_rt_endFrame(void) { return aipl_rt_endDrawing(); }

AiplVal aipl_rt_getPixel(AiplVal x_v, AiplVal y_v) {
  int x = (int)((x_v.kind == AIPL_FLOAT) ? x_v.f : x_v.i);
  int y = (int)((y_v.kind == AIPL_FLOAT) ? y_v.f : y_v.i);
  _aipl_sync_gl_to_fb();
  aipl_ensure_canvas_fb();
  if (x >= 0 && x < _aipl_canvas_w && y >= 0 && y < _aipl_canvas_h) {
    size_t idx = ((size_t)y * (size_t)_aipl_canvas_w + (size_t)x) * 4;
    uint32_t b = (uint32_t)_aipl_canvas_fb[idx];
    uint32_t g = (uint32_t)_aipl_canvas_fb[idx + 1];
    uint32_t r = (uint32_t)_aipl_canvas_fb[idx + 2];
    uint32_t a = (uint32_t)_aipl_canvas_fb[idx + 3];
    uint32_t rgba = (r << 24) | (g << 16) | (b << 8) | a;
    return aipl_int((int64_t)rgba);
  }
  return aipl_int(0);
}

AiplVal aipl_rt_gameLoop(AiplVal fn_val) {
  while (!aipl_rt_windowShouldClose().b) {
    aipl_rt_beginDrawing();
    AiplVal _fmark = aipl_arena_mark();
    if (fn_val.kind == AIPL_FUNC && fn_val.ptr) {
      AiplFnPtr fn = (AiplFnPtr)fn_val.ptr;
      AiplVal dt = aipl_rt_getFrameTime();
      fn(1, &dt);
    }
    aipl_arena_reset(_fmark);
    aipl_rt_endDrawing();
  }
  return aipl_nil();
}

AiplVal aipl_rt_clearScreen(AiplVal c) {
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
#ifndef _WIN32
  if (_aipl_window_backend == 2) {
    _aipl_gl_vert_count = 0;
    uint64_t h = (_aipl_gl_frame_hash != 0ULL) ? _aipl_gl_frame_hash : 1469598103934665603ULL;
    h ^= ((uint64_t)r << 24) | ((uint64_t)g << 16) | ((uint64_t)b << 8) | (uint64_t)a;
    h *= 1099511628211ULL;
    _aipl_gl_frame_hash = h;
    if (_aipl_glClearColor && _aipl_glClear) {
      if (_aipl_glColorMask) _aipl_glColorMask(1, 1, 1, 1);
      _aipl_glClearColor((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
      if (_aipl_glClearDepth) _aipl_glClearDepth(1.0);
      _aipl_glClear(0x00004000 /* GL_COLOR_BUFFER_BIT */ | 0x00000100 /* GL_DEPTH_BUFFER_BIT */);
      if (_aipl_glColorMask) _aipl_glColorMask(1, 1, 1, 0);
      _aipl_gl_fb_dirty = 1;
    }
    return aipl_nil();
  }
#endif
  aipl_ensure_canvas_fb();
  uint32_t pixel = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
  uint64_t pixel64 = ((uint64_t)pixel << 32) | (uint64_t)pixel;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  size_t total = (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h;
  size_t i = 0;
  for (; i + 4 <= total; i += 4) {
    uint64_t* dst64 = (uint64_t*)(fb32 + i);
    dst64[0] = pixel64;
    dst64[1] = pixel64;
  }
  for (; i < total; i++) {
    fb32[i] = pixel;
  }
  if (_aipl_zbuffer && _aipl_zbuffer_cap >= total) {
    for (size_t zi = 0; zi < total; zi++) _aipl_zbuffer[zi] = 1e30f;
  }
  return aipl_nil();
}

AiplVal aipl_rt_clearBackground(AiplVal c) { return aipl_rt_clearScreen(c); }

AiplVal aipl_rt_clearCanvas(AiplVal c) { return aipl_rt_clearScreen(c); }

AiplVal aipl_rt_rgba(AiplVal r, AiplVal g, AiplVal b, AiplVal a) {
  int ri = aipl_color_channel_from_val(r);
  int gi = aipl_color_channel_from_val(g);
  int bi = aipl_color_channel_from_val(b);
  int ai = aipl_color_channel_from_val(a);
  ri &= 0xFF; gi &= 0xFF; bi &= 0xFF; ai &= 0xFF;
  AiplVal v; memset(&v, 0, sizeof(v));
  v.kind = AIPL_INT;
  v.extra_i = 0x434F4C52;
  v.i = ((long long)ri) | ((long long)gi << 8) | ((long long)bi << 16) | ((long long)ai << 24);
  return v;
}

AiplVal aipl_rt_rgb(AiplVal r, AiplVal g, AiplVal b) { return aipl_rt_rgba(r, g, b, aipl_int(255)); }

static inline uint32_t _aipl_blend_pixel(uint32_t d, uint32_t sr, uint32_t sg, uint32_t sb, uint32_t sa) {
  if (sa == 0) return d;
  int mode = _aipl_cur_blend_mode;
  if (__builtin_expect(mode == 0, 1)) {
    if (sa >= 255u) return 0xFF000000u | (sr << 16) | (sg << 8) | sb;
    uint32_t da = 255u - sa;
    uint32_t ob = (sb * sa + (d & 0xFFu) * da) / 255u;
    uint32_t og = (sg * sa + ((d >> 8) & 0xFFu) * da) / 255u;
    uint32_t or_ = (sr * sa + ((d >> 16) & 0xFFu) * da) / 255u;
    return 0xFF000000u | (or_ << 16) | (og << 8) | ob;
  }
  uint32_t db = d & 0xFFu;
  uint32_t dg = (d >> 8) & 0xFFu;
  uint32_t dr = (d >> 16) & 0xFFu;
  if (mode == 1) {
    uint32_t ob = db + (sb * sa) / 255u; if (ob > 255u) ob = 255u;
    uint32_t og = dg + (sg * sa) / 255u; if (og > 255u) og = 255u;
    uint32_t or_ = dr + (sr * sa) / 255u; if (or_ > 255u) or_ = 255u;
    return 0xFF000000u | (or_ << 16) | (og << 8) | ob;
  }
  if (mode == 2) {
    uint32_t da = 255u - sa;
    uint32_t mb = (sb * db) / 255u; uint32_t ob = (mb * sa + db * da) / 255u;
    uint32_t mg = (sg * dg) / 255u; uint32_t og = (mg * sa + dg * da) / 255u;
    uint32_t mr = (sr * dr) / 255u; uint32_t or_ = (mr * sa + dr * da) / 255u;
    return 0xFF000000u | (or_ << 16) | (og << 8) | ob;
  }
  if (mode == 3) {
    uint32_t esb = (sb * sa) / 255u; uint32_t ob = 255u - ((255u - esb) * (255u - db)) / 255u;
    uint32_t esg = (sg * sa) / 255u; uint32_t og = 255u - ((255u - esg) * (255u - dg)) / 255u;
    uint32_t esr = (sr * sa) / 255u; uint32_t or_ = 255u - ((255u - esr) * (255u - dr)) / 255u;
    return 0xFF000000u | (or_ << 16) | (og << 8) | ob;
  }
  return d;
}

static inline void _aipl_set_pixel_fast(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  if ((unsigned)x >= (unsigned)_aipl_canvas_w || (unsigned)y >= (unsigned)_aipl_canvas_h) return;
  if (_aipl_scissor_active) {
    if (x < _aipl_scissor_x || x >= _aipl_scissor_x + _aipl_scissor_w ||
        y < _aipl_scissor_y || y >= _aipl_scissor_y + _aipl_scissor_h) return;
  }
  uint32_t* p32 = ((uint32_t*)_aipl_canvas_fb) + (size_t)y * (size_t)_aipl_canvas_w + (size_t)x;
  *p32 = _aipl_blend_pixel(*p32, r, g, b, a);
}

static inline void _aipl_fill_span(int y, int x0, int x1, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  if (a == 0 || x0 >= x1) return;
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int min_y = 0, max_y = _aipl_canvas_h;
  int min_x = 0, max_x = _aipl_canvas_w;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_y > min_y) min_y = _aipl_scissor_y;
    if (_aipl_scissor_y + _aipl_scissor_h < max_y) max_y = _aipl_scissor_y + _aipl_scissor_h;
    if (_aipl_scissor_x > min_x) min_x = _aipl_scissor_x;
    if (_aipl_scissor_x + _aipl_scissor_w < max_x) max_x = _aipl_scissor_x + _aipl_scissor_w;
  }
  if (y < min_y || y >= max_y) return;
  if (x0 < min_x) x0 = min_x;
  if (x1 > max_x) x1 = max_x;
  if (x0 >= x1) return;
  uint32_t* row32 = ((uint32_t*)_aipl_canvas_fb) + (size_t)y * (size_t)_aipl_canvas_w;
  if (__builtin_expect(_aipl_cur_blend_mode != 0, 0)) {
    for (int px = x0; px < x1; px++) {
      row32[px] = _aipl_blend_pixel(row32[px], r, g, b, a);
    }
    return;
  }
  if (a == 255) {
    uint32_t pixel = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
    uint64_t pixel64 = ((uint64_t)pixel << 32) | (uint64_t)pixel;
    int px = x0;
    for (; px + 4 <= x1; px += 4) {
      uint64_t* dst64 = (uint64_t*)(row32 + px);
      dst64[0] = pixel64;
      dst64[1] = pixel64;
    }
    for (; px + 2 <= x1; px += 2) {
      *(uint64_t*)(row32 + px) = pixel64;
    }
    if (px < x1) {
      row32[px] = pixel;
    }
  } else {
    uint32_t sa = a, da = 255 - sa;
    uint32_t sb = b * sa, sg = g * sa, sr = r * sa;
    int px = x0;
    for (; px + 2 <= x1; px += 2) {
      uint8_t* p = (uint8_t*)(row32 + px);
      uint32_t b0 = (sb + p[0] * da) / 255;
      uint32_t g0 = (sg + p[1] * da) / 255;
      uint32_t r0 = (sr + p[2] * da) / 255;
      uint32_t b1 = (sb + p[4] * da) / 255;
      uint32_t g1 = (sg + p[5] * da) / 255;
      uint32_t r1 = (sr + p[6] * da) / 255;
      uint32_t out0 = b0 | (g0 << 8) | (r0 << 16) | 0xFF000000u;
      uint32_t out1 = b1 | (g1 << 8) | (r1 << 16) | 0xFF000000u;
      *(uint64_t*)p = ((uint64_t)out1 << 32) | (uint64_t)out0;
    }
    if (px < x1) {
      uint8_t* p = (uint8_t*)(row32 + px);
      p[0] = (uint8_t)((sb + p[0] * da) / 255);
      p[1] = (uint8_t)((sg + p[1] * da) / 255);
      p[2] = (uint8_t)((sr + p[2] * da) / 255);
      p[3] = 255;
    }
  }
}

static inline void _aipl_blend_span_inbounds_alpha(uint32_t* fb32, int cw, int py, int x0, int x1, uint32_t srcColor, uint32_t a);

static inline void _aipl_fill_span_inbounds_opaque(uint32_t* fb32, int cw, int y, int x0, int x1, uint32_t color, uint64_t pixel64) {
  if (x0 >= x1) return;
  if (__builtin_expect(_aipl_cur_blend_mode != 0, 0)) {
    _aipl_blend_span_inbounds_alpha(fb32, cw, y, x0, x1, color & 0x00FFFFFFu, 255u);
    return;
  }
  uint32_t* row32 = fb32 + (size_t)y * (size_t)cw;
  int count = x1 - x0;
  int pairs = count >> 1;
  uint64_t* dst64 = (uint64_t*)(row32 + x0);
  while (pairs >= 2) {
    dst64[0] = pixel64;
    dst64[1] = pixel64;
    dst64 += 2;
    pairs -= 2;
  }
  if (pairs == 1) {
    *dst64++ = pixel64;
  }
  if (count & 1) {
    *(uint32_t*)dst64 = color;
  }
}

static inline void _aipl_blend_span_inbounds_alpha(uint32_t* fb32, int cw, int py, int x0, int x1, uint32_t srcColor, uint32_t a) {
  if (x0 >= x1) return;
  uint32_t* row = fb32 + (size_t)py * (size_t)cw;
  if (__builtin_expect(_aipl_cur_blend_mode != 0, 0)) {
    uint32_t sr = (srcColor >> 16) & 0xFFu;
    uint32_t sg = (srcColor >> 8) & 0xFFu;
    uint32_t sb = srcColor & 0xFFu;
    for (int px = x0; px < x1; px++) {
      row[px] = _aipl_blend_pixel(row[px], sr, sg, sb, a);
    }
    return;
  }
  uint32_t invA = 255u - a;
  uint32_t sbA = (srcColor & 0xFFu) * a;
  uint32_t sgA = ((srcColor >> 8) & 0xFFu) * a;
  uint32_t srA = ((srcColor >> 16) & 0xFFu) * a;
  int px = x0;
  for (; px + 2 <= x1; px += 2) {
    uint32_t d0 = row[px];
    uint32_t d1 = row[px + 1];
    uint32_t b0 = (sbA + (d0 & 0xFFu) * invA) / 255u;
    uint32_t g0 = (sgA + ((d0 >> 8) & 0xFFu) * invA) / 255u;
    uint32_t r0 = (srA + ((d0 >> 16) & 0xFFu) * invA) / 255u;
    uint32_t b1 = (sbA + (d1 & 0xFFu) * invA) / 255u;
    uint32_t g1 = (sgA + ((d1 >> 8) & 0xFFu) * invA) / 255u;
    uint32_t r1 = (srA + ((d1 >> 16) & 0xFFu) * invA) / 255u;
    uint32_t out0 = b0 | (g0 << 8) | (r0 << 16) | 0xFF000000u;
    uint32_t out1 = b1 | (g1 << 8) | (r1 << 16) | 0xFF000000u;
    *(uint64_t*)(row + px) = ((uint64_t)out1 << 32) | (uint64_t)out0;
  }
  if (px < x1) {
    uint32_t d0 = row[px];
    uint32_t b0 = (sbA + (d0 & 0xFFu) * invA) / 255u;
    uint32_t g0 = (sgA + ((d0 >> 8) & 0xFFu) * invA) / 255u;
    uint32_t r0 = (srA + ((d0 >> 16) & 0xFFu) * invA) / 255u;
    row[px] = b0 | (g0 << 8) | (r0 << 16) | 0xFF000000u;
  }
}

AiplVal aipl_rt_drawRect(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c) {
  int rx = (int)((x.kind == AIPL_FLOAT) ? x.f : x.i);
  int ry = (int)((y.kind == AIPL_FLOAT) ? y.f : y.i);
  int rw = (int)((w.kind == AIPL_FLOAT) ? w.f : w.i);
  int rh = (int)((h.kind == AIPL_FLOAT) ? h.f : h.i);
  if (rw <= 0 || rh <= 0) return aipl_nil();
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  _aipl_sg_record_rect(rx, ry, rw, rh, r, g, b, 0);
  if (_aipl_window_backend == 2) {
    _aipl_gl_push_quad((float)rx, (float)ry, (float)(rx + rw), (float)(ry + rh), r, g, b, a);
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int min_y = 0, max_y = _aipl_canvas_h;
  int min_x = 0, max_x = _aipl_canvas_w;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_y > min_y) min_y = _aipl_scissor_y;
    if (_aipl_scissor_y + _aipl_scissor_h < max_y) max_y = _aipl_scissor_y + _aipl_scissor_h;
    if (_aipl_scissor_x > min_x) min_x = _aipl_scissor_x;
    if (_aipl_scissor_x + _aipl_scissor_w < max_x) max_x = _aipl_scissor_x + _aipl_scissor_w;
  }
  int y0 = ry < min_y ? min_y : ry;
  int y1 = (ry + rh > max_y) ? max_y : (ry + rh);
  int x0 = rx < min_x ? min_x : rx;
  int x1 = (rx + rw > max_x) ? max_x : (rx + rw);
  if (x0 >= x1 || y0 >= y1) return aipl_nil();
  int cw = _aipl_canvas_w;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  if (a == 255) {
    uint32_t pixel = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
    uint64_t pixel64 = ((uint64_t)pixel << 32) | (uint64_t)pixel;
    for (int py = y0; py < y1; py++) {
      _aipl_fill_span_inbounds_opaque(fb32, cw, py, x0, x1, pixel, pixel64);
    }
    return aipl_nil();
  }
  uint32_t srcColor = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  for (int py = y0; py < y1; py++) {
    _aipl_blend_span_inbounds_alpha(fb32, cw, py, x0, x1, srcColor, (uint32_t)a);
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawRect_va(int argc, const AiplVal* args) {
  if (argc < 5) return aipl_nil();
  if (argc >= 8) return aipl_rt_drawRect8(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
  if (argc == 6) return aipl_rt_drawRectAlpha(args[0], args[1], args[2], args[3], args[4], args[5]);
  return aipl_rt_drawRect(args[0], args[1], args[2], args[3], args[4]);
}

AiplVal aipl_rt_drawRectAlpha(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c, AiplVal alpha_v) {
  int rx = (int)((x.kind == AIPL_FLOAT) ? x.f : x.i);
  int ry = (int)((y.kind == AIPL_FLOAT) ? y.f : y.i);
  int rw = (int)((w.kind == AIPL_FLOAT) ? w.f : w.i);
  int rh = (int)((h.kind == AIPL_FLOAT) ? h.f : h.i);
  if (rw <= 0 || rh <= 0) return aipl_nil();
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  int ai = aipl_color_channel_from_val(alpha_v);
  if (ai < 0) ai = 0;
  if (ai > 255) ai = 255;
  a = (uint8_t)(((uint32_t)a * (uint32_t)ai) / 255u);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2) {
    _aipl_gl_push_quad((float)rx, (float)ry, (float)(rx + rw), (float)(ry + rh), r, g, b, a);
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int min_y = 0, max_y = _aipl_canvas_h;
  int min_x = 0, max_x = _aipl_canvas_w;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_y > min_y) min_y = _aipl_scissor_y;
    if (_aipl_scissor_y + _aipl_scissor_h < max_y) max_y = _aipl_scissor_y + _aipl_scissor_h;
    if (_aipl_scissor_x > min_x) min_x = _aipl_scissor_x;
    if (_aipl_scissor_x + _aipl_scissor_w < max_x) max_x = _aipl_scissor_x + _aipl_scissor_w;
  }
  int y0 = ry < min_y ? min_y : ry;
  int y1 = (ry + rh > max_y) ? max_y : (ry + rh);
  int x0 = rx < min_x ? min_x : rx;
  int x1 = (rx + rw > max_x) ? max_x : (rx + rw);
  if (x0 >= x1 || y0 >= y1) return aipl_nil();
  int cw = _aipl_canvas_w;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  if (a == 255) {
    uint32_t pixel = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
    uint64_t pixel64 = ((uint64_t)pixel << 32) | (uint64_t)pixel;
    for (int py = y0; py < y1; py++) {
      _aipl_fill_span_inbounds_opaque(fb32, cw, py, x0, x1, pixel, pixel64);
    }
    return aipl_nil();
  }
  uint32_t srcColor = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  for (int py = y0; py < y1; py++) {
    _aipl_blend_span_inbounds_alpha(fb32, cw, py, x0, x1, srcColor, (uint32_t)a);
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawRect8(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal r, AiplVal g, AiplVal b, AiplVal a) {
  return aipl_rt_drawRect(x, y, w, h, aipl_rt_rgba(r, g, b, a));
}

AiplVal aipl_rt_drawRectOutline(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c) {
  int rx = (int)((x.kind == AIPL_FLOAT) ? x.f : x.i);
  int ry = (int)((y.kind == AIPL_FLOAT) ? y.f : y.i);
  int rw = (int)((w.kind == AIPL_FLOAT) ? w.f : w.i);
  int rh = (int)((h.kind == AIPL_FLOAT) ? h.f : h.i);
  if (rw <= 0 || rh <= 0) return aipl_nil();
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2) {
    _aipl_gl_push_quad((float)rx, (float)ry, (float)(rx + rw), (float)(ry + 1), r, g, b, a);
    if (rh > 1) _aipl_gl_push_quad((float)rx, (float)(ry + rh - 1), (float)(rx + rw), (float)(ry + rh), r, g, b, a);
    if (rh > 2) {
      _aipl_gl_push_quad((float)rx, (float)(ry + 1), (float)(rx + 1), (float)(ry + rh - 1), r, g, b, a);
      if (rw > 1) _aipl_gl_push_quad((float)(rx + rw - 1), (float)(ry + 1), (float)(rx + rw), (float)(ry + rh - 1), r, g, b, a);
    }
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  _aipl_fill_span(ry, rx, rx + rw, r, g, b, a);
  if (rh > 1) _aipl_fill_span(ry + rh - 1, rx, rx + rw, r, g, b, a);
  int py0 = (ry + 1 < 0) ? 0 : (ry + 1);
  int py1 = (ry + rh - 1 > _aipl_canvas_h) ? _aipl_canvas_h : (ry + rh - 1);
  for (int py = py0; py < py1; py++) {
    _aipl_set_pixel_fast(rx, py, r, g, b, a);
    if (rw > 1) _aipl_set_pixel_fast(rx + rw - 1, py, r, g, b, a);
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawRectOutline6(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal th, AiplVal c) {
  int rx = (int)((x.kind == AIPL_FLOAT) ? x.f : x.i);
  int ry = (int)((y.kind == AIPL_FLOAT) ? y.f : y.i);
  int rw = (int)((w.kind == AIPL_FLOAT) ? w.f : w.i);
  int rh = (int)((h.kind == AIPL_FLOAT) ? h.f : h.i);
  int ith = (int)((th.kind == AIPL_FLOAT) ? th.f : th.i);
  if (ith < 1) ith = 1;
  if (rw <= 0 || rh <= 0) return aipl_nil();
  if (ith == 1) return aipl_rt_drawRectOutline(x, y, w, h, c);
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2) {
    _aipl_gl_push_quad((float)rx, (float)ry, (float)(rx + rw), (float)(ry + ith), r, g, b, a);
    if (rh > ith) _aipl_gl_push_quad((float)rx, (float)(ry + rh - ith), (float)(rx + rw), (float)(ry + rh), r, g, b, a);
    if (rh > 2 * ith) {
      _aipl_gl_push_quad((float)rx, (float)(ry + ith), (float)(rx + ith), (float)(ry + rh - ith), r, g, b, a);
      if (rw > ith) _aipl_gl_push_quad((float)(rx + rw - ith), (float)(ry + ith), (float)(rx + rw), (float)(ry + rh - ith), r, g, b, a);
    }
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int py_start = ry < 0 ? 0 : ry;
  int py_end = (ry + rh > _aipl_canvas_h) ? _aipl_canvas_h : (ry + rh);
  for (int py = py_start; py < py_end; py++) {
    if (py < ry + ith || py >= ry + rh - ith || rw <= 2 * ith) {
      _aipl_fill_span(py, rx, rx + rw, r, g, b, a);
    } else {
      _aipl_fill_span(py, rx, rx + ith, r, g, b, a);
      _aipl_fill_span(py, rx + rw - ith, rx + rw, r, g, b, a);
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawRectLines(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal c) {
  return aipl_rt_drawRectOutline(x, y, w, h, c);
}

AiplVal aipl_rt_drawRectLines6(AiplVal x, AiplVal y, AiplVal w, AiplVal h, AiplVal th, AiplVal c) {
  return aipl_rt_drawRectOutline6(x, y, w, h, th, c);
}

int _aipl_is_likely_color(AiplVal v) {
  if (v.kind == AIPL_STRUCT) return 1;
  if (v.kind == AIPL_INT && (v.i > 255 || v.i < 0)) return 1;
  if (v.kind == AIPL_FLOAT && (v.f > 255.0 || v.f < 0.0)) return 1;
  return 0;
}

AiplVal _aipl_rt_drawRoundedRect_va(int argc, const AiplVal* args) {
  if (argc < 5) return aipl_nil();
  int rx = (int)((args[0].kind == AIPL_FLOAT) ? args[0].f : args[0].i);
  int ry = (int)((args[1].kind == AIPL_FLOAT) ? args[1].f : args[1].i);
  int rw = (int)((args[2].kind == AIPL_FLOAT) ? args[2].f : args[2].i);
  int rh = (int)((args[3].kind == AIPL_FLOAT) ? args[3].f : args[3].i);
  if (rw <= 0 || rh <= 0) return aipl_nil();
  double rad_d = (args[4].kind == AIPL_FLOAT) ? args[4].f : (double)args[4].i;
  double max_r = (double)(rw < rh ? rw : rh) * 0.5;
  if (rad_d > max_r) rad_d = max_r;
  if (rad_d < 0.0) rad_d = 0.0;
  AiplVal col = args[argc - 1];
  uint8_t r, g, b, a; aipl_unpack_color(col, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (rad_d <= 0.5) return aipl_rt_drawRect(args[0], args[1], args[2], args[3], col);
  _aipl_sg_record_rect(rx, ry, rw, rh, r, g, b, 1);
  if (_aipl_window_backend == 2) {
    float frx = (float)rx, fry = (float)ry, frw = (float)rw, frh = (float)rh, fr = (float)rad_d;
    _aipl_gl_push_quad(frx + fr, fry, frx + frw - fr, fry + frh, r, g, b, a);
    _aipl_gl_push_quad(frx, fry + fr, frx + fr, fry + frh - fr, r, g, b, a);
    _aipl_gl_push_quad(frx + frw - fr, fry + fr, frx + frw, fry + frh - fr, r, g, b, a);
    int csegs = 6;
    float cx_arr[4] = { frx + fr, frx + frw - fr, frx + frw - fr, frx + fr };
    float cy_arr[4] = { fry + fr, fry + fr, fry + frh - fr, fry + frh - fr };
    float a0_arr[4] = { 3.14159265f, 4.71238898f, 0.0f, 1.57079632f };
    for (int ci = 0; ci < 4; ci++) {
      float ccx = cx_arr[ci], ccy = cy_arr[ci], a0 = a0_arr[ci];
      float px = ccx + fr * cosf(a0), py = ccy + fr * sinf(a0);
      for (int s = 1; s <= csegs; s++) {
        float ang = a0 + 1.57079632f * ((float)s / (float)csegs);
        float nx = ccx + fr * cosf(ang), ny = ccy + fr * sinf(ang);
        _aipl_gl_push_tri(ccx, ccy, px, py, nx, ny, r, g, b, a);
        px = nx; py = ny;
      }
    }
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int ir = (int)rad_d;
  int x1 = rx + ir;
  int x2 = rx + rw - 1 - ir;
  int y1 = ry + ir;
  int y2 = ry + rh - 1 - ir;
  if (!_aipl_scissor_active && rx >= 0 && ry >= 0 && rx + rw <= _aipl_canvas_w && ry + rh <= _aipl_canvas_h) {
    uint32_t color = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
    uint64_t pixel64 = ((uint64_t)color << 32) | (uint64_t)color;
    uint32_t srcColor = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
    int cw = _aipl_canvas_w;
    uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
    double rad2 = rad_d * rad_d;
    for (int py = ry; py < ry + rh; py++) {
      int span_l = rx;
      int span_r = rx + rw;
      if (py < y1 || py > y2) {
        double qy = (py < y1) ? (double)(y1 - py) : (double)(py - y2);
        double qy2 = qy * qy;
        int dx = (qy2 < rad2) ? (int)(sqrt(rad2 - qy2) + 0.5) : 0;
        if (dx > ir) dx = ir;
        span_l = x1 - dx;
        span_r = x2 + dx + 1;
      }
      if (a == 255) {
        _aipl_fill_span_inbounds_opaque(fb32, cw, py, span_l, span_r, color, pixel64);
      } else {
        _aipl_blend_span_inbounds_alpha(fb32, cw, py, span_l, span_r, srcColor, (uint32_t)a);
      }
    }
    return aipl_nil();
  }
  double r_in = rad_d - 0.5;
  double r_in2 = (r_in > 0.0) ? (r_in * r_in) : 0.0;
  double r_out = rad_d + 0.5;
  double r_out2 = r_out * r_out;
  int py_start = ry < 0 ? 0 : ry;
  int py_end = (ry + rh > _aipl_canvas_h) ? _aipl_canvas_h : (ry + rh);
  for (int py = py_start; py < py_end; py++) {
    if (py >= y1 && py <= y2) {
      _aipl_fill_span(py, rx, rx + rw, r, g, b, a);
    } else {
      double qy = (py < y1) ? (double)(y1 - py) : (double)(py - y2);
      double qy2 = qy * qy;
      int dx_in = (r_in > 0.0 && qy2 < r_in2) ? (int)floor(sqrt(r_in2 - qy2)) : 0;
      int dx_max = (qy2 < r_out2) ? (int)ceil(sqrt(r_out2 - qy2)) : 0;
      if (dx_max > (int)rad_d) dx_max = (int)rad_d;
      int span_l = x1 - dx_in;
      int span_r = x2 + dx_in + 1;
      if (span_r > span_l) {
        _aipl_fill_span(py, span_l, span_r, r, g, b, a);
      }
      for (int dx = dx_in + 1; dx <= dx_max; dx++) {
        double dist = sqrt((double)(dx * dx) + qy2) - rad_d;
        if (dist <= -0.5) {
          _aipl_set_pixel_fast(x1 - dx, py, r, g, b, a);
          _aipl_set_pixel_fast(x2 + dx, py, r, g, b, a);
        } else if (dist < 0.5) {
          uint8_t cur_a = (uint8_t)((double)a * (0.5 - dist));
          if (cur_a > 0) {
            _aipl_set_pixel_fast(x1 - dx, py, r, g, b, cur_a);
            _aipl_set_pixel_fast(x2 + dx, py, r, g, b, cur_a);
          }
        }
      }
    }
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawRoundedRectOutline_va(int argc, const AiplVal* args) {
  if (argc < 5) return aipl_nil();
  int rx = (int)((args[0].kind == AIPL_FLOAT) ? args[0].f : args[0].i);
  int ry = (int)((args[1].kind == AIPL_FLOAT) ? args[1].f : args[1].i);
  int rw = (int)((args[2].kind == AIPL_FLOAT) ? args[2].f : args[2].i);
  int rh = (int)((args[3].kind == AIPL_FLOAT) ? args[3].f : args[3].i);
  if (rw <= 0 || rh <= 0) return aipl_nil();
  double rad_d = (args[4].kind == AIPL_FLOAT) ? args[4].f : (double)args[4].i;
  double max_r = (double)(rw < rh ? rw : rh) * 0.5;
  if (rad_d > max_r) rad_d = max_r;
  if (rad_d < 0.0) rad_d = 0.0;
  double th = 1.0;
  AiplVal col = args[argc - 1];
  if (argc >= 7) {
    if (_aipl_is_likely_color(args[5])) {
      col = args[5]; th = (args[6].kind == AIPL_FLOAT) ? args[6].f : (double)args[6].i;
    } else {
      th = (args[5].kind == AIPL_FLOAT) ? args[5].f : (double)args[5].i; col = args[6];
    }
  } else if (argc == 6) {
    col = args[5]; th = 1.0;
  }
  if (th < 1.0) th = 1.0;
  uint8_t r, g, b, a; aipl_unpack_color(col, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2) {
    float frx = (float)rx, fry = (float)ry, frw = (float)rw, frh = (float)rh, fr = (float)rad_d, fth = (float)th;
    _aipl_gl_push_quad(frx + fr, fry, frx + frw - fr, fry + fth, r, g, b, a);
    _aipl_gl_push_quad(frx + fr, fry + frh - fth, frx + frw - fr, fry + frh, r, g, b, a);
    _aipl_gl_push_quad(frx, fry + fr, frx + fth, fry + frh - fr, r, g, b, a);
    _aipl_gl_push_quad(frx + frw - fth, fry + fr, frx + frw, fry + frh - fr, r, g, b, a);
    int csegs = 6;
    float cx_arr[4] = { frx + fr, frx + frw - fr, frx + frw - fr, frx + fr };
    float cy_arr[4] = { fry + fr, fry + fr, fry + frh - fr, fry + frh - fr };
    float a0_arr[4] = { 3.14159265f, 4.71238898f, 0.0f, 1.57079632f };
    for (int ci = 0; ci < 4; ci++) {
      float ccx = cx_arr[ci], ccy = cy_arr[ci], a0 = a0_arr[ci];
      float px = ccx + fr * cosf(a0), py = ccy + fr * sinf(a0);
      for (int s = 1; s <= csegs; s++) {
        float ang = a0 + 1.57079632f * ((float)s / (float)csegs);
        float nx = ccx + fr * cosf(ang), ny = ccy + fr * sinf(ang);
        _aipl_gl_push_line(px, py, nx, ny, fth, r, g, b, a);
        px = nx; py = ny;
      }
    }
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int x1 = rx + (int)rad_d;
  int x2 = rx + rw - 1 - (int)rad_d;
  int y1 = ry + (int)rad_d;
  int y2 = ry + rh - 1 - (int)rad_d;
  int ith = (int)ceil(th);
  double r_out = rad_d + 0.5;
  double r_out2 = r_out * r_out;
  double r_in = rad_d - th + 0.5;
  double r_in2 = (r_in > 0.0) ? (r_in * r_in) : 0.0;
  int py_start = ry < 0 ? 0 : ry;
  int py_end = (ry + rh > _aipl_canvas_h) ? _aipl_canvas_h : (ry + rh);
  for (int py = py_start; py < py_end; py++) {
    if (py >= y1 && py <= y2) {
      int dt = py - ry, db = ry + rh - 1 - py;
      if (dt < ith || db < ith) {
        _aipl_fill_span(py, rx, rx + rw, r, g, b, a);
      } else {
        _aipl_fill_span(py, rx, rx + ith, r, g, b, a);
        _aipl_fill_span(py, rx + rw - ith, rx + rw, r, g, b, a);
      }
    } else {
      double qy = (py < y1) ? (double)(y1 - py) : (double)(py - y2);
      double qy2 = qy * qy;
      int dt = py - ry, db = ry + rh - 1 - py;
      if ((dt < ith || db < ith) && x2 >= x1) {
        _aipl_fill_span(py, x1, x2 + 1, r, g, b, a);
      }
      if (qy2 < r_out2) {
        int dx_out = (int)floor(sqrt(r_out2 - qy2));
        if (dx_out > (int)rad_d) dx_out = (int)rad_d;
        int dx_in = (r_in > 0.0 && qy2 < r_in2) ? (int)ceil(sqrt(r_in2 - qy2)) : 1;
        if (dx_in < 1) dx_in = 1;
        if (dx_out >= dx_in) {
          _aipl_fill_span(py, x1 - dx_out, x1 - dx_in + 1, r, g, b, a);
          _aipl_fill_span(py, x2 + dx_in, x2 + dx_out + 1, r, g, b, a);
        }
      }
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawCircle(AiplVal cx_v, AiplVal cy_v, AiplVal r_v, AiplVal c) {
  int cx = (int)((cx_v.kind == AIPL_FLOAT) ? cx_v.f : cx_v.i);
  int cy = (int)((cy_v.kind == AIPL_FLOAT) ? cy_v.f : cy_v.i);
  double rad = (r_v.kind == AIPL_FLOAT) ? r_v.f : (double)r_v.i;
  if (rad <= 0.0) return aipl_nil();
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  _aipl_sg_record_circle(cx, cy, (int)(rad + 0.5), r, g, b);
  if (_aipl_window_backend == 2) {
    _aipl_gl_push_ellipse((float)cx, (float)cy, (float)rad, (float)rad, r, g, b, a);
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  if (a == 255 && rad >= 2.0) {
    int ir = (int)(rad + 0.5);
    int x = ir, y = 0, err = 1 - ir;
    if (!_aipl_scissor_active && cx - ir >= 0 && cy - ir >= 0 && cx + ir < _aipl_canvas_w && cy + ir < _aipl_canvas_h) {
      uint32_t color = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
      uint64_t pixel64 = ((uint64_t)color << 32) | (uint64_t)color;
      int cw = _aipl_canvas_w;
      uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
      while (x >= y) {
        _aipl_fill_span_inbounds_opaque(fb32, cw, cy + y, cx - x, cx + x + 1, color, pixel64);
        if (y != 0) {
          _aipl_fill_span_inbounds_opaque(fb32, cw, cy - y, cx - x, cx + x + 1, color, pixel64);
        }
        int next_err = err + 2 * y + 1;
        if (next_err >= 0) {
          if (x > y) {
            _aipl_fill_span_inbounds_opaque(fb32, cw, cy + x, cx - y, cx + y + 1, color, pixel64);
            _aipl_fill_span_inbounds_opaque(fb32, cw, cy - x, cx - y, cx + y + 1, color, pixel64);
          }
          x--;
          err = next_err - 2 * x;
        } else {
          err = next_err;
        }
        y++;
      }
      return aipl_nil();
    }
    while (x >= y) {
      _aipl_fill_span(cy + y, cx - x, cx + x + 1, r, g, b, 255);
      if (y != 0) {
        _aipl_fill_span(cy - y, cx - x, cx + x + 1, r, g, b, 255);
      }
      int next_err = err + 2 * y + 1;
      if (next_err >= 0) {
        if (x > y) {
          _aipl_fill_span(cy + x, cx - y, cx + y + 1, r, g, b, 255);
          _aipl_fill_span(cy - x, cx - y, cx + y + 1, r, g, b, 255);
        }
        x--;
        err = next_err - 2 * x;
      } else {
        err = next_err;
      }
      y++;
    }
    return aipl_nil();
  }
  int irad = (int)ceil(rad + 0.5);
  int min_y = 0, max_y = _aipl_canvas_h - 1;
  int min_x = 0, max_x = _aipl_canvas_w;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_y > min_y) min_y = _aipl_scissor_y;
    if (_aipl_scissor_y + _aipl_scissor_h - 1 < max_y) max_y = _aipl_scissor_y + _aipl_scissor_h - 1;
    if (_aipl_scissor_x > min_x) min_x = _aipl_scissor_x;
    if (_aipl_scissor_x + _aipl_scissor_w < max_x) max_x = _aipl_scissor_x + _aipl_scissor_w;
  }
  int dy_min = -irad;
  if (cy + dy_min < min_y) dy_min = min_y - cy;
  int dy_max = irad;
  if (cy + dy_max > max_y) dy_max = max_y - cy;
  if (dy_min > dy_max || min_x >= max_x) return aipl_nil();
  uint32_t color = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
  uint64_t pixel64 = ((uint64_t)color << 32) | (uint64_t)color;
  uint32_t srcColor = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  int cw = _aipl_canvas_w;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  double r_in = rad - 0.5;
  double r_in2 = (r_in > 0.0) ? (r_in * r_in) : 0.0;
  double r_out = rad + 0.5;
  double r_out2 = r_out * r_out;
  for (int dy = dy_min; dy <= dy_max; dy++) {
    int py = cy + dy;
    double dy2 = (double)(dy * dy);
    if (dy2 >= r_out2) continue;
    int dx_max = (int)ceil(sqrt(r_out2 - dy2));
    int dx_in = (r_in > 0.0 && dy2 < r_in2) ? (int)floor(sqrt(r_in2 - dy2)) : -1;
    if (dx_in >= 0) {
      int sx0 = cx - dx_in;
      int sx1 = cx + dx_in + 1;
      if (sx0 < min_x) sx0 = min_x;
      if (sx1 > max_x) sx1 = max_x;
      if (sx0 < sx1) {
        if (a == 255) {
          _aipl_fill_span_inbounds_opaque(fb32, cw, py, sx0, sx1, color, pixel64);
        } else {
          _aipl_blend_span_inbounds_alpha(fb32, cw, py, sx0, sx1, srcColor, (uint32_t)a);
        }
      }
      for (int dx = dx_in + 1; dx <= dx_max; dx++) {
        double dist = sqrt((double)(dx * dx) + dy2) - rad;
        if (dist <= -0.5) {
          _aipl_set_pixel_fast(cx - dx, py, r, g, b, a);
          _aipl_set_pixel_fast(cx + dx, py, r, g, b, a);
        } else if (dist < 0.5) {
          uint8_t cur_a = (uint8_t)((double)a * (0.5 - dist));
          if (cur_a > 0) {
            _aipl_set_pixel_fast(cx - dx, py, r, g, b, cur_a);
            _aipl_set_pixel_fast(cx + dx, py, r, g, b, cur_a);
          }
        }
      }
    } else {
      double dist0 = fabs((double)dy) - rad;
      if (dist0 <= -0.5) {
        _aipl_set_pixel_fast(cx, py, r, g, b, a);
      } else if (dist0 < 0.5) {
        uint8_t cur_a = (uint8_t)((double)a * (0.5 - dist0));
        if (cur_a > 0) _aipl_set_pixel_fast(cx, py, r, g, b, cur_a);
      }
      for (int dx = 1; dx <= dx_max; dx++) {
        double dist = sqrt((double)(dx * dx) + dy2) - rad;
        if (dist <= -0.5) {
          _aipl_set_pixel_fast(cx - dx, py, r, g, b, a);
          _aipl_set_pixel_fast(cx + dx, py, r, g, b, a);
        } else if (dist < 0.5) {
          uint8_t cur_a = (uint8_t)((double)a * (0.5 - dist));
          if (cur_a > 0) {
            _aipl_set_pixel_fast(cx - dx, py, r, g, b, cur_a);
            _aipl_set_pixel_fast(cx + dx, py, r, g, b, cur_a);
          }
        }
      }
    }
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawCircle_va(int argc, const AiplVal* args) {
  if (argc < 4) return aipl_nil();
  return aipl_rt_drawCircle(args[0], args[1], args[2], args[3]);
}

AiplVal _aipl_rt_drawCircleOutline_va(int argc, const AiplVal* args) {
  if (argc < 4) return aipl_nil();
  int cx = (int)((args[0].kind == AIPL_FLOAT) ? args[0].f : args[0].i);
  int cy = (int)((args[1].kind == AIPL_FLOAT) ? args[1].f : args[1].i);
  double rad = (args[2].kind == AIPL_FLOAT) ? args[2].f : (double)args[2].i;
  if (rad <= 0.0) return aipl_nil();
  double th = 1.0;
  AiplVal col = args[3];
  if (argc >= 5) {
    if (_aipl_is_likely_color(args[3])) {
      col = args[3]; th = (args[4].kind == AIPL_FLOAT) ? args[4].f : (double)args[4].i;
    } else {
      th = (args[3].kind == AIPL_FLOAT) ? args[3].f : (double)args[3].i; col = args[4];
    }
  }
  if (th < 1.0) th = 1.0;
  uint8_t r, g, b, a; aipl_unpack_color(col, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2) {
    int segs = (int)(rad * 0.75) + 12;
    if (segs < 12) segs = 12;
    if (segs > 64) segs = 64;
    float fcx = (float)cx, fcy = (float)cy, fr = (float)rad, fth = (float)th;
    float px = fcx + fr, py = fcy;
    for (int i = 1; i <= segs; i++) {
      float ang = (6.283185307f * (float)i) / (float)segs;
      float nx = fcx + fr * cosf(ang);
      float ny = fcy + fr * sinf(ang);
      _aipl_gl_push_line(px, py, nx, ny, fth, r, g, b, a);
      px = nx; py = ny;
    }
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  if (a == 255 && th <= 1.0 && rad >= 2.0) {
    int ir = (int)(rad + 0.5);
    int x = ir, y = 0, err = 1 - ir;
    while (x >= y) {
      _aipl_set_pixel_fast(cx + x, cy + y, r, g, b, 255);
      _aipl_set_pixel_fast(cx - x, cy + y, r, g, b, 255);
      if (y != 0) {
        _aipl_set_pixel_fast(cx + x, cy - y, r, g, b, 255);
        _aipl_set_pixel_fast(cx - x, cy - y, r, g, b, 255);
      }
      if (x != y) {
        _aipl_set_pixel_fast(cx + y, cy + x, r, g, b, 255);
        _aipl_set_pixel_fast(cx - y, cy + x, r, g, b, 255);
        if (y != 0) {
          _aipl_set_pixel_fast(cx + y, cy - x, r, g, b, 255);
          _aipl_set_pixel_fast(cx - y, cy - x, r, g, b, 255);
        }
      }
      y++;
      if (err < 0) {
        err += 2 * y + 1;
      } else {
        x--;
        err += 2 * (y - x) + 1;
      }
    }
    return aipl_nil();
  }
  /* Analytical outer/inner horizontal chords per scanline without per-pixel sqrt */
  int irad = (int)ceil(rad + 0.5);
  double r_out = rad + 0.5;
  double r_out2 = r_out * r_out;
  double r_in = rad - th + 0.5;
  double r_in2 = (r_in > 0.0) ? (r_in * r_in) : 0.0;
  int dy_min = -irad;
  if (cy + dy_min < 0) dy_min = -cy;
  int dy_max = irad;
  if (cy + dy_max >= _aipl_canvas_h) dy_max = _aipl_canvas_h - 1 - cy;
  for (int dy = dy_min; dy <= dy_max; dy++) {
    int py = cy + dy;
    double dy2 = (double)(dy * dy);
    if (dy2 > r_out2) continue;
    int dx_out = (int)floor(sqrt(r_out2 - dy2));
    if (r_in > 0.0 && dy2 < r_in2) {
      int dx_in = (int)ceil(sqrt(r_in2 - dy2));
      if (dx_out >= dx_in) {
        _aipl_fill_span(py, cx - dx_out, cx - dx_in + 1, r, g, b, a);
        _aipl_fill_span(py, cx + dx_in, cx + dx_out + 1, r, g, b, a);
      }
    } else {
      _aipl_fill_span(py, cx - dx_out, cx + dx_out + 1, r, g, b, a);
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawLine6(AiplVal x1_v, AiplVal y1_v, AiplVal x2_v, AiplVal y2_v, AiplVal c, AiplVal th_v) {
  int x0 = (int)((x1_v.kind == AIPL_FLOAT) ? x1_v.f : x1_v.i);
  int y0 = (int)((y1_v.kind == AIPL_FLOAT) ? y1_v.f : y1_v.i);
  int x1 = (int)((x2_v.kind == AIPL_FLOAT) ? x2_v.f : x2_v.i);
  int y1 = (int)((y2_v.kind == AIPL_FLOAT) ? y2_v.f : y2_v.i);
  int th = (int)((th_v.kind == AIPL_FLOAT) ? th_v.f : th_v.i);
  if (th < 1) th = 1;
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2) {
    _aipl_gl_push_line((float)x0, (float)y0, (float)x1, (float)y1, (float)th, r, g, b, a);
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int half = th / 2;
  if (y0 == y1) {
    int lx0 = (x0 < x1 ? x0 : x1) - half;
    int lx1 = (x0 < x1 ? x1 : x0) + (th - half);
    for (int ty = -half; ty < th - half; ty++) {
      _aipl_fill_span(y0 + ty, lx0, lx1, r, g, b, a);
    }
    return aipl_nil();
  }
  if (x0 == x1) {
    int ly0 = (y0 < y1 ? y0 : y1) - half;
    int ly1 = (y0 < y1 ? y1 : y0) + (th - half);
    if (ly0 < 0) ly0 = 0;
    if (ly1 > _aipl_canvas_h) ly1 = _aipl_canvas_h;
    if (th == 1) {
      if (a == 255 && _aipl_cur_blend_mode == 0 && !_aipl_scissor_active && (unsigned)x0 < (unsigned)_aipl_canvas_w) {
        uint32_t pixel = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
        uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
        int cw = _aipl_canvas_w;
        for (int py = ly0; py < ly1; py++) {
          fb32[(size_t)py * (size_t)cw + (size_t)x0] = pixel;
        }
      } else {
        for (int py = ly0; py < ly1; py++) {
          _aipl_set_pixel_fast(x0, py, r, g, b, a);
        }
      }
    } else {
      for (int py = ly0; py < ly1; py++) {
        _aipl_fill_span(py, x0 - half, x0 - half + th, r, g, b, a);
      }
    }
    return aipl_nil();
  }
  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2;
  if (a == 255 && _aipl_cur_blend_mode == 0 && th <= 1 && !_aipl_scissor_active &&
      (unsigned)x0 < (unsigned)_aipl_canvas_w && (unsigned)x1 < (unsigned)_aipl_canvas_w &&
      (unsigned)y0 < (unsigned)_aipl_canvas_h && (unsigned)y1 < (unsigned)_aipl_canvas_h) {
    uint32_t pixel = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
    uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
    int cw = _aipl_canvas_w;
    for (;;) {
      fb32[(size_t)y0 * (size_t)cw + (size_t)x0] = pixel;
      if (x0 == x1 && y0 == y1) break;
      e2 = 2 * err;
      if (e2 >= dy) { err += dy; x0 += sx; }
      if (e2 <= dx) { err += dx; y0 += sy; }
    }
    return aipl_nil();
  }
  for (;;) {
    if (th <= 1) {
      _aipl_set_pixel_fast(x0, y0, r, g, b, a);
    } else {
      for (int ty = -half; ty < th - half; ty++) {
        _aipl_fill_span(y0 + ty, x0 - half, x0 - half + th, r, g, b, a);
      }
    }
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; }
    if (e2 <= dx) { err += dx; y0 += sy; }
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawLine_va(int argc, const AiplVal* args) {
  if (argc < 5) return aipl_nil();
  if (argc >= 6) return aipl_rt_drawLine6(args[0], args[1], args[2], args[3], args[4], args[5]);
  return aipl_rt_drawLine6(args[0], args[1], args[2], args[3], args[4], aipl_int(1));
}

AiplVal aipl_rt_drawLine(AiplVal x1_v, AiplVal y1_v, AiplVal x2_v, AiplVal y2_v, AiplVal c) {
  return aipl_rt_drawLine6(x1_v, y1_v, x2_v, y2_v, c, aipl_int(1));
}

AiplVal _aipl_rt_drawTriangle_va(int argc, const AiplVal* args) {
  if (argc < 7) return aipl_nil();
  double x1 = (args[0].kind == AIPL_FLOAT) ? args[0].f : (double)args[0].i;
  double y1 = (args[1].kind == AIPL_FLOAT) ? args[1].f : (double)args[1].i;
  double x2 = (args[2].kind == AIPL_FLOAT) ? args[2].f : (double)args[2].i;
  double y2 = (args[3].kind == AIPL_FLOAT) ? args[3].f : (double)args[3].i;
  double x3 = (args[4].kind == AIPL_FLOAT) ? args[4].f : (double)args[4].i;
  double y3 = (args[5].kind == AIPL_FLOAT) ? args[5].f : (double)args[5].i;
  AiplVal col = args[argc - 1];
  uint8_t r, g, b, a; aipl_unpack_color(col, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2) {
    _aipl_gl_push_tri((float)x1, (float)y1, (float)x2, (float)y2, (float)x3, (float)y3, r, g, b, a);
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  double area = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
  if (area < 0.0) {
    double tx = x2, ty = y2; x2 = x3; y2 = y3; x3 = tx; y3 = ty;
  }
  double min_x_d = x1 < x2 ? (x1 < x3 ? x1 : x3) : (x2 < x3 ? x2 : x3);
  double max_x_d = x1 > x2 ? (x1 > x3 ? x1 : x3) : (x2 > x3 ? x2 : x3);
  double min_y_d = y1 < y2 ? (y1 < y3 ? y1 : y3) : (y2 < y3 ? y2 : y3);
  double max_y_d = y1 > y2 ? (y1 > y3 ? y1 : y3) : (y2 > y3 ? y2 : y3);
  int min_x = (int)floor(min_x_d);
  int max_x = (int)ceil(max_x_d);
  int min_y = (int)floor(min_y_d);
  int max_y = (int)ceil(max_y_d);
  int clip_min_x = 0, clip_max_x = _aipl_canvas_w - 1;
  int clip_min_y = 0, clip_max_y = _aipl_canvas_h - 1;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_min_x) clip_min_x = _aipl_scissor_x;
    if (_aipl_scissor_x + _aipl_scissor_w - 1 < clip_max_x) clip_max_x = _aipl_scissor_x + _aipl_scissor_w - 1;
    if (_aipl_scissor_y > clip_min_y) clip_min_y = _aipl_scissor_y;
    if (_aipl_scissor_y + _aipl_scissor_h - 1 < clip_max_y) clip_max_y = _aipl_scissor_y + _aipl_scissor_h - 1;
  }
  if (min_x < clip_min_x) min_x = clip_min_x;
  if (min_y < clip_min_y) min_y = clip_min_y;
  if (max_x > clip_max_x) max_x = clip_max_x;
  if (max_y > clip_max_y) max_y = clip_max_y;
  if (min_x > max_x || min_y > max_y) return aipl_nil();
  uint32_t color = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
  uint64_t pixel64 = ((uint64_t)color << 32) | (uint64_t)color;
  uint32_t srcColor = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  int cw = _aipl_canvas_w;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  /* Analytical O(1) scanline edge intersection with zero inner px loop */
  double ex[3] = { x2, x3, x1 };
  double ey[3] = { y2, y3, y1 };
  double edx[3] = { x3 - x2, x1 - x3, x2 - x1 };
  double edy[3] = { y3 - y2, y1 - y3, y2 - y1 };
  double inv_edy[3] = {
    (fabs(edy[0]) > 1e-12) ? (1.0 / edy[0]) : 0.0,
    (fabs(edy[1]) > 1e-12) ? (1.0 / edy[1]) : 0.0,
    (fabs(edy[2]) > 1e-12) ? (1.0 / edy[2]) : 0.0
  };
  for (int py = min_y; py <= max_y; py++) {
    double ppy = (double)py + 0.5;
    double ppx_min = (double)min_x + 0.5;
    double ppx_max = (double)max_x + 0.5;
    int row_valid = 1;
    for (int e = 0; e < 3; e++) {
      double dy = edy[e];
      double dx = edx[e];
      double rel_y = ppy - ey[e];
      if (fabs(dy) <= 1e-12) {
        if (dx * rel_y < 0.0) { row_valid = 0; break; }
      } else {
        double x_int = ex[e] + dx * rel_y * inv_edy[e];
        if (dy > 0.0) {
          if (x_int < ppx_max) ppx_max = x_int;
        } else {
          if (x_int > ppx_min) ppx_min = x_int;
        }
      }
    }
    if (!row_valid || ppx_min > ppx_max) continue;
    int sx0 = (int)ceil(ppx_min - 0.5);
    int sx1 = (int)floor(ppx_max - 0.5);
    if (sx0 < min_x) sx0 = min_x;
    if (sx1 > max_x) sx1 = max_x;
    if (sx0 <= sx1) {
      if (a == 255) {
        _aipl_fill_span_inbounds_opaque(fb32, cw, py, sx0, sx1 + 1, color, pixel64);
      } else {
        _aipl_blend_span_inbounds_alpha(fb32, cw, py, sx0, sx1 + 1, srcColor, (uint32_t)a);
      }
    }
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawTriangleLines_va(int argc, const AiplVal* args) {
  if (argc < 7) return aipl_nil();
  AiplVal col = args[argc - 1];
  aipl_rt_drawLine(args[0], args[1], args[2], args[3], col);
  aipl_rt_drawLine(args[2], args[3], args[4], args[5], col);
  aipl_rt_drawLine(args[4], args[5], args[0], args[1], col);
  return aipl_nil();
}

static const uint8_t _aipl_font5x7[475] = {
  0x00,0x00,0x00,0x00,0x00, 0x00,0x00,0x5F,0x00,0x00, 0x00,0x07,0x00,0x07,0x00, 0x14,0x7F,0x14,0x7F,0x14,
  0x24,0x2A,0x7F,0x2A,0x12, 0x23,0x13,0x08,0x64,0x62, 0x36,0x49,0x55,0x22,0x50, 0x00,0x05,0x03,0x00,0x00,
  0x00,0x1C,0x22,0x41,0x00, 0x00,0x41,0x22,0x1C,0x00, 0x14,0x08,0x3E,0x08,0x14, 0x08,0x08,0x3E,0x08,0x08,
  0x00,0x50,0x30,0x00,0x00, 0x08,0x08,0x08,0x08,0x08, 0x00,0x60,0x60,0x00,0x00, 0x20,0x10,0x08,0x04,0x02,
  0x3E,0x51,0x49,0x45,0x3E, 0x00,0x42,0x7F,0x40,0x00, 0x42,0x61,0x51,0x49,0x46, 0x21,0x41,0x45,0x4B,0x31,
  0x18,0x14,0x12,0x7F,0x10, 0x27,0x45,0x45,0x45,0x39, 0x3C,0x4A,0x49,0x49,0x30, 0x01,0x71,0x09,0x05,0x03,
  0x36,0x49,0x49,0x49,0x36, 0x06,0x49,0x49,0x29,0x1E, 0x00,0x36,0x36,0x00,0x00, 0x00,0x56,0x36,0x00,0x00,
  0x08,0x14,0x22,0x41,0x00, 0x14,0x14,0x14,0x14,0x14, 0x00,0x41,0x22,0x14,0x08, 0x02,0x01,0x51,0x09,0x06,
  0x32,0x49,0x79,0x41,0x3E, 0x7E,0x11,0x11,0x11,0x7E, 0x7F,0x49,0x49,0x49,0x36, 0x3E,0x41,0x41,0x41,0x22,
  0x7F,0x41,0x41,0x22,0x1C, 0x7F,0x49,0x49,0x49,0x41, 0x7F,0x09,0x09,0x09,0x01, 0x3E,0x41,0x49,0x49,0x7A,
  0x7F,0x08,0x08,0x08,0x7F, 0x00,0x41,0x7F,0x41,0x00, 0x20,0x40,0x41,0x3F,0x01, 0x7F,0x08,0x14,0x22,0x41,
  0x7F,0x40,0x40,0x40,0x40, 0x7F,0x02,0x0C,0x02,0x7F, 0x7F,0x04,0x08,0x10,0x7F, 0x3E,0x41,0x41,0x41,0x3E,
  0x7F,0x09,0x09,0x09,0x06, 0x3E,0x41,0x51,0x21,0x5E, 0x7F,0x09,0x19,0x29,0x46, 0x46,0x49,0x49,0x49,0x31,
  0x01,0x01,0x7F,0x01,0x01, 0x3F,0x40,0x40,0x40,0x3F, 0x1F,0x20,0x40,0x20,0x1F, 0x3F,0x40,0x38,0x40,0x3F,
  0x63,0x14,0x08,0x14,0x63, 0x07,0x08,0x70,0x08,0x07, 0x61,0x51,0x49,0x45,0x43, 0x00,0x7F,0x41,0x41,0x00,
  0x02,0x04,0x08,0x10,0x20, 0x00,0x41,0x41,0x7F,0x00, 0x04,0x02,0x01,0x02,0x04, 0x40,0x40,0x40,0x40,0x40,
  0x00,0x01,0x02,0x04,0x00, 0x20,0x54,0x54,0x54,0x78, 0x7F,0x48,0x44,0x44,0x38, 0x38,0x44,0x44,0x44,0x20,
  0x38,0x44,0x44,0x48,0x7F, 0x38,0x54,0x54,0x54,0x18, 0x08,0x7E,0x09,0x01,0x02, 0x0C,0x52,0x52,0x52,0x3E,
  0x7F,0x08,0x04,0x04,0x78, 0x00,0x44,0x7D,0x40,0x00, 0x20,0x40,0x44,0x3D,0x00, 0x7F,0x10,0x28,0x44,0x00,
  0x00,0x41,0x7F,0x40,0x00, 0x7C,0x04,0x18,0x04,0x78, 0x7C,0x08,0x04,0x04,0x78, 0x38,0x44,0x44,0x44,0x38,
  0x7C,0x14,0x14,0x14,0x08, 0x08,0x14,0x14,0x18,0x7C, 0x7C,0x08,0x04,0x04,0x08, 0x48,0x54,0x54,0x54,0x20,
  0x04,0x3F,0x44,0x40,0x20, 0x3C,0x40,0x40,0x20,0x7C, 0x1C,0x20,0x40,0x20,0x1C, 0x3C,0x40,0x30,0x40,0x3C,
  0x44,0x28,0x10,0x28,0x44, 0x0C,0x50,0x50,0x50,0x3C, 0x44,0x64,0x54,0x4C,0x44, 0x00,0x08,0x36,0x41,0x00,
  0x00,0x00,0x7F,0x00,0x00, 0x00,0x41,0x36,0x08,0x00, 0x10,0x08,0x08,0x10,0x08
};
void* _aipl_cairo_lib = NULL;
void* _aipl_ft_lib = NULL;
void* _aipl_ft_handle = NULL;
void** _aipl_font_faces = NULL;
int _aipl_font_faces_cap = 0;
void _aipl_ensure_font_slot(int slot) {
  if (slot < 0) return;
  if (slot >= _aipl_font_faces_cap) {
    int new_cap = (_aipl_font_faces_cap == 0) ? 32 : _aipl_font_faces_cap * 2;
    while (new_cap <= slot) new_cap *= 2;
    void** nf = (void**)realloc(_aipl_font_faces, (size_t)new_cap * sizeof(void*));
    char (*np)[512] = (char (*)[512])realloc(_aipl_font_paths, (size_t)new_cap * 512);
    if (nf) _aipl_font_faces = nf;
    if (np) _aipl_font_paths = np;
    if (!nf || !np) return;
    memset(nf + _aipl_font_faces_cap, 0, (size_t)(new_cap - _aipl_font_faces_cap) * sizeof(void*));
    memset(np + _aipl_font_faces_cap, 0, (size_t)(new_cap - _aipl_font_faces_cap) * 512);
    _aipl_font_faces_cap = new_cap;
  }
}
int _aipl_active_font_id = 0;
void* _aipl_scratch_surface = NULL;
void* _aipl_scratch_cr = NULL;
unsigned char* _aipl_scratch_data = NULL;
int _aipl_scratch_stride = 0;
void* (*_aipl_cairo_image_surface_create)(int, int, int) = NULL;
void (*_aipl_cairo_surface_destroy)(void*) = NULL;
void (*_aipl_cairo_surface_flush)(void*) = NULL;
unsigned char* (*_aipl_cairo_image_surface_get_data)(void*) = NULL;
int (*_aipl_cairo_image_surface_get_stride)(void*) = NULL;
void* (*_aipl_cairo_create)(void*) = NULL;
void (*_aipl_cairo_destroy)(void*) = NULL;
void (*_aipl_cairo_select_font_face)(void*, const char*, int, int) = NULL;
void (*_aipl_cairo_set_font_face)(void*, void*) = NULL;
void (*_aipl_cairo_set_font_size)(void*, double) = NULL;
void (*_aipl_cairo_set_source_rgba)(void*, double, double, double, double) = NULL;
void (*_aipl_cairo_move_to)(void*, double, double) = NULL;
void (*_aipl_cairo_show_text)(void*, const char*) = NULL;
void (*_aipl_cairo_text_extents)(void*, const char*, _AiplCairoTextExtents*) = NULL;
void* (*_aipl_cairo_ft_font_face_create_for_ft_face)(void*, int) = NULL;
void (*_aipl_cairo_paint)(void*) = NULL;
void (*_aipl_cairo_set_operator)(void*, int) = NULL;
int (*_aipl_FT_Init_FreeType)(void**) = NULL;
int (*_aipl_FT_New_Face)(void*, const char*, long, void**) = NULL;
int _aipl_load_font_face_into_slot(int slot, const char* path) {
  if (slot < 0 || !path || !path[0]) return 0;
  _aipl_ensure_font_slot(slot);
  if (slot >= _aipl_font_faces_cap) return 0;
  if (!_aipl_ft_handle || !_aipl_FT_New_Face || !_aipl_cairo_ft_font_face_create_for_ft_face) return 0;
  void* ft_face = NULL;
  if (_aipl_FT_New_Face(_aipl_ft_handle, path, 0, &ft_face) != 0 || !ft_face) return 0;
  void* cairo_face = _aipl_cairo_ft_font_face_create_for_ft_face(ft_face, 0);
  if (!cairo_face) return 0;
  _aipl_font_faces[slot] = cairo_face;
  return 1;
}

int _aipl_ttf_initialized = 0;
void _aipl_init_ttf(void) {
  if (_aipl_ttf_initialized) return;
  _aipl_ttf_initialized = 1;
#ifndef _WIN32
  _aipl_cairo_lib = dlopen("libcairo.so.2", RTLD_LAZY);
  _aipl_ft_lib = dlopen("libfreetype.so.6", RTLD_LAZY);
  if (!_aipl_cairo_lib || !_aipl_ft_lib) return;
  _aipl_cairo_image_surface_create = (void* (*)(int, int, int))dlsym(_aipl_cairo_lib, "cairo_image_surface_create");
  _aipl_cairo_surface_destroy = (void (*)(void*))dlsym(_aipl_cairo_lib, "cairo_surface_destroy");
  _aipl_cairo_surface_flush = (void (*)(void*))dlsym(_aipl_cairo_lib, "cairo_surface_flush");
  _aipl_cairo_image_surface_get_data = (unsigned char* (*)(void*))dlsym(_aipl_cairo_lib, "cairo_image_surface_get_data");
  _aipl_cairo_image_surface_get_stride = (int (*)(void*))dlsym(_aipl_cairo_lib, "cairo_image_surface_get_stride");
  _aipl_cairo_create = (void* (*)(void*))dlsym(_aipl_cairo_lib, "cairo_create");
  _aipl_cairo_destroy = (void (*)(void*))dlsym(_aipl_cairo_lib, "cairo_destroy");
  _aipl_cairo_select_font_face = (void (*)(void*, const char*, int, int))dlsym(_aipl_cairo_lib, "cairo_select_font_face");
  _aipl_cairo_set_font_face = (void (*)(void*, void*))dlsym(_aipl_cairo_lib, "cairo_set_font_face");
  _aipl_cairo_set_font_size = (void (*)(void*, double))dlsym(_aipl_cairo_lib, "cairo_set_font_size");
  _aipl_cairo_set_source_rgba = (void (*)(void*, double, double, double, double))dlsym(_aipl_cairo_lib, "cairo_set_source_rgba");
  _aipl_cairo_move_to = (void (*)(void*, double, double))dlsym(_aipl_cairo_lib, "cairo_move_to");
  _aipl_cairo_show_text = (void (*)(void*, const char*))dlsym(_aipl_cairo_lib, "cairo_show_text");
  _aipl_cairo_text_extents = (void (*)(void*, const char*, _AiplCairoTextExtents*))dlsym(_aipl_cairo_lib, "cairo_text_extents");
  _aipl_cairo_ft_font_face_create_for_ft_face = (void* (*)(void*, int))dlsym(_aipl_cairo_lib, "cairo_ft_font_face_create_for_ft_face");
  _aipl_cairo_paint = (void (*)(void*))dlsym(_aipl_cairo_lib, "cairo_paint");
  _aipl_cairo_set_operator = (void (*)(void*, int))dlsym(_aipl_cairo_lib, "cairo_set_operator");
  _aipl_FT_Init_FreeType = (int (*)(void**))dlsym(_aipl_ft_lib, "FT_Init_FreeType");
  _aipl_FT_New_Face = (int (*)(void*, const char*, long, void**))dlsym(_aipl_ft_lib, "FT_New_Face");
  if (_aipl_FT_Init_FreeType) { _aipl_FT_Init_FreeType(&_aipl_ft_handle); }
  if (_aipl_cairo_image_surface_create && _aipl_cairo_create && _aipl_cairo_image_surface_get_data && _aipl_cairo_image_surface_get_stride) {
    _aipl_scratch_surface = _aipl_cairo_image_surface_create(0, _AIPL_SCRATCH_W, _AIPL_SCRATCH_H);
    if (_aipl_scratch_surface) {
      _aipl_scratch_cr = _aipl_cairo_create(_aipl_scratch_surface);
      _aipl_scratch_data = _aipl_cairo_image_surface_get_data(_aipl_scratch_surface);
      _aipl_scratch_stride = _aipl_cairo_image_surface_get_stride(_aipl_scratch_surface);
    }
  }
  _aipl_load_font_face_into_slot(0, "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
  _aipl_load_font_face_into_slot(1, "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf");
  if (!_aipl_load_font_face_into_slot(2, "/usr/share/fonts/truetype/jetbrains-mono/JetBrainsMono-Regular.ttf")) {
    _aipl_load_font_face_into_slot(2, "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf");
  }
  if (!_aipl_load_font_face_into_slot(3, "/usr/share/fonts/truetype/dejavu/DejaVuSerif.ttf")) {
    _aipl_load_font_face_into_slot(3, "/usr/share/fonts/truetype/liberation/LiberationSans-Italic.ttf");
  }
#endif
}

double _aipl_ttf_pixel_size(double sz) {
  if (sz <= 0.0) return 13.0;
  if (sz <= 4.0) return fmax(9.0, sz * 13.0);
  return fmin(128.0, sz);
}

void _aipl_sanitize_utf8(const char* src, char* dst, size_t dst_size) {
  if (!src || !dst || dst_size == 0) return;
  size_t di = 0, si = 0;
  while (src[si] != 0 && di + 4 < dst_size) {
    unsigned char c = (unsigned char)src[si];
    if (c < 0x80) { dst[di++] = (char)c; si++; }
    else if ((c & 0xE0) == 0xC0) {
      if ((unsigned char)src[si + 1] >= 0x80 && (unsigned char)src[si + 1] <= 0xBF) { dst[di++] = src[si++]; dst[di++] = src[si++]; }
      else { dst[di++] = '?'; si++; }
    } else if ((c & 0xF0) == 0xE0) {
      if ((unsigned char)src[si + 1] >= 0x80 && (unsigned char)src[si + 1] <= 0xBF && (unsigned char)src[si + 2] >= 0x80 && (unsigned char)src[si + 2] <= 0xBF) { dst[di++] = src[si++]; dst[di++] = src[si++]; dst[di++] = src[si++]; }
      else { dst[di++] = '?'; si++; }
    } else if ((c & 0xF8) == 0xF0) {
      if ((unsigned char)src[si + 1] >= 0x80 && (unsigned char)src[si + 1] <= 0xBF && (unsigned char)src[si + 2] >= 0x80 && (unsigned char)src[si + 2] <= 0xBF && (unsigned char)src[si + 3] >= 0x80 && (unsigned char)src[si + 3] <= 0xBF) { dst[di++] = src[si++]; dst[di++] = src[si++]; dst[di++] = src[si++]; dst[di++] = src[si++]; }
      else { dst[di++] = '?'; si++; }
    } else { dst[di++] = '?'; si++; }
  }
  dst[di] = 0;
}

int _aipl_font_scale_from_size(double sz) {
  int scale = 2;
  if (sz > 0.0 && sz <= 0.85) scale = 1;
  else if (sz > 0.85 && sz <= 1.45) scale = 2;
  else if (sz > 1.45 && sz <= 2.2) scale = 3;
  else if (sz > 2.2 && sz <= 4.0) scale = 4;
  else if (sz > 4.0) scale = (int)(sz / 7.0 + 0.5);
  if (scale < 1) scale = 1;
  if (scale > 8) scale = 8;
  return scale;
}

typedef struct {
  uint64_t hash;
  int px10;
  int font_id;
  char text[160];
  double ext_w;
  double ext_h;
  int tw;
  int th;
  int min_x;
  int max_x;
  int min_y;
  int max_y;
  uint8_t* mask;
  int mask_cap;
  int has_mask;
} _AiplTextCacheEntry;

static _AiplTextCacheEntry _aipl_text_cache[2048];

static uint64_t _aipl_hash_text_key(const char* s, int px10, int font_id) {
  uint64_t h = 1469598103934665603ULL;
  h = (h ^ (uint64_t)px10) * 1099511628211ULL;
  h = (h ^ (uint64_t)font_id) * 1099511628211ULL;
  for (size_t i = 0; s[i] != 0; i++) {
    h = (h ^ (unsigned char)s[i]) * 1099511628211ULL;
  }
  return h ? h : 1ULL;
}

void _aipl_measure_ttf(const char* s, double sz, double* out_w, double* out_h) {
  if (!s || !s[0]) {
    if (out_w) *out_w = 0.0;
    if (out_h) *out_h = _aipl_ttf_pixel_size(sz);
    return;
  }
  _aipl_init_ttf();
  double px = _aipl_ttf_pixel_size(sz);
  int px10 = (int)(px * 10.0 + 0.5);
  size_t slen = strlen(s);
  uint64_t h = 0;
  _AiplTextCacheEntry* slot = NULL;
  if (slen < 159) {
    h = _aipl_hash_text_key(s, px10, _aipl_active_font_id);
    slot = &_aipl_text_cache[h & 2047u];
    if (slot->hash == h && slot->px10 == px10 && slot->font_id == _aipl_active_font_id && strcmp(slot->text, s) == 0) {
      if (out_w) *out_w = slot->ext_w;
      if (out_h) *out_h = slot->ext_h;
      return;
    }
  }
  if (_aipl_scratch_cr && _aipl_cairo_text_extents && _aipl_cairo_set_font_size) {
    char clean[2048];
    _aipl_sanitize_utf8(s, clean, sizeof(clean));
    if (_aipl_font_faces && _aipl_active_font_id >= 0 && _aipl_active_font_id < _aipl_font_faces_cap && _aipl_font_faces[_aipl_active_font_id] && _aipl_cairo_set_font_face) {
      _aipl_cairo_set_font_face(_aipl_scratch_cr, _aipl_font_faces[_aipl_active_font_id]);
    } else if (_aipl_cairo_select_font_face) {
      _aipl_cairo_select_font_face(_aipl_scratch_cr, "sans-serif", 0, 0);
    }
    _aipl_cairo_set_font_size(_aipl_scratch_cr, px);
    _AiplCairoTextExtents ext;
    memset(&ext, 0, sizeof(ext));
    _aipl_cairo_text_extents(_aipl_scratch_cr, clean, &ext);
    double tw = (ext.x_advance > ext.width) ? ext.x_advance : ext.width;
    double th = (ext.height > px) ? ext.height : px;
    if (slot) {
      slot->hash = h;
      slot->px10 = px10;
      slot->font_id = _aipl_active_font_id;
      memcpy(slot->text, s, slen + 1);
      slot->ext_w = tw;
      slot->ext_h = th;
      slot->has_mask = 0;
    }
    if (out_w) *out_w = tw;
    if (out_h) *out_h = th;
    return;
  }
  int scale = _aipl_font_scale_from_size(sz);
  if (out_w) *out_w = (double)slen * 6.0 * (double)scale;
  if (out_h) *out_h = 7.0 * (double)scale;
}

static inline void _aipl_draw_text_cached(const _AiplTextCacheEntry* slot, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb) return;
  int tw = slot->tw;
  int clip_x0 = 0, clip_x1 = _aipl_canvas_w;
  int clip_y0 = 0, clip_y1 = _aipl_canvas_h;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_x0) clip_x0 = _aipl_scissor_x;
    if (_aipl_scissor_y > clip_y0) clip_y0 = _aipl_scissor_y;
    if (_aipl_scissor_x + _aipl_scissor_w < clip_x1) clip_x1 = _aipl_scissor_x + _aipl_scissor_w;
    if (_aipl_scissor_y + _aipl_scissor_h < clip_y1) clip_y1 = _aipl_scissor_y + _aipl_scissor_h;
  }
  int sx0 = slot->min_x;
  int sx1 = slot->max_x;
  if (x + sx0 - 2 < clip_x0) sx0 = clip_x0 - x + 2;
  if (x + sx1 - 2 >= clip_x1) sx1 = clip_x1 - 1 - x + 2;
  if (sx0 > sx1) return;
  int end_gx = sx1 + 1;
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    for (int sy = slot->min_y; sy <= slot->max_y; sy++) {
      int dst_y = y + sy;
      if (dst_y < clip_y0 || dst_y >= clip_y1) continue;
      const uint8_t* src_row = slot->mask + sy * tw;
      int gx = sx0;
      while (gx < end_gx) {
        uint8_t cov = src_row[gx];
        if (cov < 32) { gx++; continue; }
        int run_start = gx;
        uint32_t acc_cov = cov;
        int run_len = 1;
        gx++;
        while (gx < end_gx && src_row[gx] >= 32) {
          acc_cov += src_row[gx];
          run_len++;
          gx++;
        }
        uint32_t avg_cov = acc_cov / (uint32_t)run_len;
        uint8_t eff_a = (a == 255) ? (uint8_t)avg_cov : (uint8_t)((avg_cov * (uint32_t)a) / 255u);
        float qx0 = (float)(x + run_start - 2);
        float qy0 = (float)dst_y;
        _aipl_gl_push_quad(qx0, qy0, qx0 + (float)run_len, qy0 + 1.0f, r, g, b, eff_a);
      }
    }
    return;
  }
  uint32_t solid_px = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
  for (int sy = slot->min_y; sy <= slot->max_y; sy++) {
    int dst_y = y + sy;
    if (dst_y < clip_y0 || dst_y >= clip_y1) continue;
    const uint8_t* src_row = slot->mask + sy * tw;
    uint8_t* drow = _aipl_canvas_fb + ((size_t)dst_y * (size_t)_aipl_canvas_w + (size_t)(x + sx0 - 2)) * 4;
    for (int gx = sx0; gx < end_gx;) {
      if (gx + 4 <= end_gx && (((uintptr_t)(src_row + gx) & 3u) == 0u) && *(const uint32_t*)(src_row + gx) == 0u) {
        gx += 4;
        drow += 16;
        continue;
      }
      uint8_t cov = src_row[gx];
      if (cov > 0) {
        uint32_t eff_a = (a == 255) ? (uint32_t)cov : (((uint32_t)cov * (uint32_t)a) / 255u);
        if (eff_a >= 255u) {
          *(uint32_t*)drow = solid_px;
        } else if (eff_a > 0u) {
          uint32_t inv = 255u - eff_a;
          drow[0] = (uint8_t)((b * eff_a + drow[0] * inv) / 255u);
          drow[1] = (uint8_t)((g * eff_a + drow[1] * inv) / 255u);
          drow[2] = (uint8_t)((r * eff_a + drow[2] * inv) / 255u);
          drow[3] = 255;
        }
      }
      gx++;
      drow += 4;
    }
  }
}

void _aipl_draw_text_raw(const char* s, int x, int y, double sz, AiplVal col) {
  if (!s || !s[0]) return;
  uint8_t r, g, b, a; aipl_unpack_color(col, &r, &g, &b, &a);
  if (a == 0) return;
  _aipl_sg_record_text(s, x, y, sz, r, g, b);
  _aipl_init_ttf();
  double px = _aipl_ttf_pixel_size(sz);
  if (_aipl_scratch_surface && _aipl_scratch_cr && _aipl_scratch_data && _aipl_cairo_show_text && _aipl_cairo_text_extents) {
    int px10 = (int)(px * 10.0 + 0.5);
    size_t slen = strlen(s);
    uint64_t h = 0;
    _AiplTextCacheEntry* slot = NULL;
    if (slen < 159) {
      h = _aipl_hash_text_key(s, px10, _aipl_active_font_id);
      slot = &_aipl_text_cache[h & 2047u];
      if (slot->hash == h && slot->px10 == px10 && slot->font_id == _aipl_active_font_id && slot->has_mask && strcmp(slot->text, s) == 0) {
        _aipl_draw_text_cached(slot, x, y, r, g, b, a);
        return;
      }
    }
    char clean[2048];
    _aipl_sanitize_utf8(s, clean, sizeof(clean));
    if (_aipl_font_faces && _aipl_active_font_id >= 0 && _aipl_active_font_id < _aipl_font_faces_cap && _aipl_font_faces[_aipl_active_font_id] && _aipl_cairo_set_font_face) {
      _aipl_cairo_set_font_face(_aipl_scratch_cr, _aipl_font_faces[_aipl_active_font_id]);
    } else if (_aipl_cairo_select_font_face) {
      _aipl_cairo_select_font_face(_aipl_scratch_cr, "sans-serif", 0, 0);
    }
    _aipl_cairo_set_font_size(_aipl_scratch_cr, px);
    _AiplCairoTextExtents ext;
    memset(&ext, 0, sizeof(ext));
    _aipl_cairo_text_extents(_aipl_scratch_cr, clean, &ext);
    double ext_w = (ext.x_advance > ext.width) ? ext.x_advance : ext.width;
    double ext_h = (ext.height > px) ? ext.height : px;
    int tw = (int)ceil(ext_w) + 8;
    int th = (int)ceil(ext_h) + 12;
    if (tw > _AIPL_SCRATCH_W) tw = _AIPL_SCRATCH_W;
    if (th > _AIPL_SCRATCH_H) th = _AIPL_SCRATCH_H;
    for (int ry = 0; ry < th; ry++) {
      memset(_aipl_scratch_data + ry * _aipl_scratch_stride, 0, (size_t)tw * 4);
    }
    _aipl_cairo_set_source_rgba(_aipl_scratch_cr, 1.0, 1.0, 1.0, 1.0);
    double y_baseline = px * 0.82;
    _aipl_cairo_move_to(_aipl_scratch_cr, 2.0, y_baseline);
    _aipl_cairo_show_text(_aipl_scratch_cr, clean);
    _aipl_cairo_surface_flush(_aipl_scratch_surface);
    int min_x = tw, max_x = -1, min_y = th, max_y = -1;
    if (slot) {
      int req_cap = tw * th;
      if (slot->mask_cap < req_cap) {
        free(slot->mask);
        slot->mask = (uint8_t*)malloc((size_t)req_cap);
        slot->mask_cap = slot->mask ? req_cap : 0;
      }
    }
    for (int sy = 0; sy < th; sy++) {
      uint8_t* row = _aipl_scratch_data + sy * _aipl_scratch_stride;
      uint8_t* mrow = (slot && slot->mask) ? (slot->mask + sy * tw) : NULL;
      int dst_y = y + sy;
      int y_ok = (dst_y >= 0 && dst_y < _aipl_canvas_h);
      for (int sx = 0; sx < tw; sx++) {
        uint8_t cov = row[sx * 4 + 3];
        if (mrow) mrow[sx] = cov;
        if (cov > 0) {
          if (sx < min_x) min_x = sx;
          if (sx > max_x) max_x = sx;
          if (sy < min_y) min_y = sy;
          if (sy > max_y) max_y = sy;
          if (!slot && y_ok) {
            uint8_t eff_a = (a == 255) ? cov : (uint8_t)(((uint32_t)cov * (uint32_t)a) / 255);
            if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
              float qx0 = (float)(x + sx - 2), qy0 = (float)dst_y;
              _aipl_gl_push_quad(qx0, qy0, qx0 + 1.0f, qy0 + 1.0f, r, g, b, eff_a);
            } else {
              aipl_canvas_set_pixel(x + sx - 2, dst_y, r, g, b, eff_a);
            }
          }
        }
      }
    }
    if (slot && slot->mask) {
      slot->hash = h;
      slot->px10 = px10;
      slot->font_id = _aipl_active_font_id;
      memcpy(slot->text, s, slen + 1);
      slot->ext_w = ext_w;
      slot->ext_h = ext_h;
      slot->tw = tw;
      slot->th = th;
      slot->min_x = min_x;
      slot->max_x = max_x;
      slot->min_y = min_y;
      slot->max_y = max_y;
      slot->has_mask = 1;
      _aipl_draw_text_cached(slot, x, y, r, g, b, a);
    }
    return;
  }
  int scale = _aipl_font_scale_from_size(sz);
  int cx = x, cy = y;
  for (size_t i = 0; s[i] != 0; i++) {
    unsigned char ch = (unsigned char)s[i];
    if (ch == 10) { cx = x; cy += 9 * scale; continue; }
    if (ch < 32 || ch > 126) ch = '?';
    const uint8_t* glyph = &_aipl_font5x7[(ch - 32) * 5];
    for (int col_i = 0; col_i < 5; col_i++) {
      uint8_t bits = glyph[col_i];
      if (!bits) continue;
      for (int row_i = 0; row_i < 7; row_i++) {
        if ((bits >> row_i) & 1) {
          if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
            float qx0 = (float)(cx + col_i * scale), qy0 = (float)(cy + row_i * scale);
            _aipl_gl_push_quad(qx0, qy0, qx0 + (float)scale, qy0 + (float)scale, r, g, b, a);
          } else {
            for (int sy = 0; sy < scale; sy++) {
              for (int sx = 0; sx < scale; sx++) {
                aipl_canvas_set_pixel(cx + col_i * scale + sx, cy + row_i * scale + sy, r, g, b, a);
              }
            }
          }
        }
      }
    }
    cx += 6 * scale;
  }
}

AiplVal _aipl_rt_drawText_va(int argc, const AiplVal* args) {
  if (argc >= 5) {
    const char* s = (args[0].kind == AIPL_STR && args[0].s) ? args[0].s : aipl_to_str(args[0]).s;
    int x = (int)((args[1].kind == AIPL_FLOAT) ? args[1].f : args[1].i);
    int y = (int)((args[2].kind == AIPL_FLOAT) ? args[2].f : args[2].i);
    double sz = (args[3].kind == AIPL_FLOAT) ? args[3].f : (double)args[3].i;
    _aipl_draw_text_raw(s, x, y, sz, args[4]);
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawTextCentered_va(int argc, const AiplVal* args) {
  if (argc >= 5) {
    const char* s = (args[0].kind == AIPL_STR && args[0].s) ? args[0].s : aipl_to_str(args[0]).s;
    int cx = (int)((args[1].kind == AIPL_FLOAT) ? args[1].f : args[1].i);
    int y = (int)((args[2].kind == AIPL_FLOAT) ? args[2].f : args[2].i);
    double sz = (args[3].kind == AIPL_FLOAT) ? args[3].f : (double)args[3].i;
    double tw = 0.0, th = 0.0;
    _aipl_measure_ttf(s, sz, &tw, &th);
    _aipl_draw_text_raw(s, (int)round((double)cx - tw / 2.0), y, sz, args[4]);
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawTextMiddle_va(int argc, const AiplVal* args) {
  if (argc >= 5) {
    const char* s = (args[0].kind == AIPL_STR && args[0].s) ? args[0].s : aipl_to_str(args[0]).s;
    int cx = (int)((args[1].kind == AIPL_FLOAT) ? args[1].f : args[1].i);
    int cy = (int)((args[2].kind == AIPL_FLOAT) ? args[2].f : args[2].i);
    double sz = (args[3].kind == AIPL_FLOAT) ? args[3].f : (double)args[3].i;
    double tw = 0.0, th = 0.0;
    _aipl_measure_ttf(s, sz, &tw, &th);
    _aipl_draw_text_raw(s, (int)round((double)cx - tw / 2.0), (int)round((double)cy - th / 2.0), sz, args[4]);
  }
  return aipl_nil();
}

AiplVal _aipl_rt_drawTextFont_va(int argc, const AiplVal* args) {
  if (argc >= 6) {
    int fid = (int)((args[0].kind == AIPL_FLOAT) ? args[0].f : args[0].i);
    int prev = _aipl_active_font_id;
    if (fid >= 0 && fid < _aipl_font_faces_cap && _aipl_font_faces && _aipl_font_faces[fid]) _aipl_active_font_id = fid;
    const char* s = (args[1].kind == AIPL_STR && args[1].s) ? args[1].s : aipl_to_str(args[1]).s;
    int x = (int)((args[2].kind == AIPL_FLOAT) ? args[2].f : args[2].i);
    int y = (int)((args[3].kind == AIPL_FLOAT) ? args[3].f : args[3].i);
    double sz = (args[4].kind == AIPL_FLOAT) ? args[4].f : (double)args[4].i;
    _aipl_draw_text_raw(s, x, y, sz, args[5]);
    _aipl_active_font_id = prev;
  }
  return aipl_nil();
}

AiplVal aipl_rt_measureText(AiplVal text_val, AiplVal size_val) {
  const char* s = (text_val.kind == AIPL_STR && text_val.s) ? text_val.s : "";
  double dsz = (size_val.kind == AIPL_FLOAT) ? size_val.f : (double)size_val.i;
  double tw = 0.0, th = 0.0;
  _aipl_measure_ttf(s, dsz, &tw, &th);
  return aipl_vec2(tw, th);
}

AiplVal aipl_rt_measureTextFont(AiplVal font_val, AiplVal text_val, AiplVal size_val) {
  int prev = _aipl_active_font_id;
  int fid = (int)((font_val.kind == AIPL_FLOAT) ? font_val.f : font_val.i);
  if (fid >= 0 && fid < _aipl_font_faces_cap && _aipl_font_faces && _aipl_font_faces[fid]) _aipl_active_font_id = fid;
  AiplVal res = aipl_rt_measureText(text_val, size_val);
  _aipl_active_font_id = prev;
  return res;
}

AiplVal aipl_rt_measureLabel(AiplVal font_val, AiplVal text_val, AiplVal size_val) {
  return aipl_rt_measureTextFont(font_val, text_val, size_val);
}

AiplVal aipl_rt_measureTextWidth(AiplVal text_val, AiplVal size_val) {
  const char* s = (text_val.kind == AIPL_STR && text_val.s) ? text_val.s : "";
  if (size_val.kind == AIPL_STRUCT || size_val.kind == AIPL_MAP) {
    int64_t n = (int64_t)strlen(s);
    if (n <= 0) return aipl_float(0.0);
    AiplVal fs = aipl_member_get(size_val, "fontSize");
    AiplVal ls = aipl_member_get(size_val, "letterSpacing");
    double font_sz = (fs.kind == AIPL_FLOAT) ? fs.f : (double)fs.i;
    double spacing = (ls.kind == AIPL_FLOAT) ? ls.f : (double)ls.i;
    double char_adv = font_sz * 0.6;
    double spacing_total = (n > 1) ? ((double)(n - 1) * spacing) : 0.0;
    return aipl_float((double)n * char_adv + spacing_total);
  }
  double dsz = (size_val.kind == AIPL_FLOAT) ? size_val.f : (double)size_val.i;
  double tw = 0.0, th = 0.0;
  _aipl_measure_ttf(s, dsz, &tw, &th);
  return aipl_float(tw);
}

AiplVal aipl_rt_measureTextHeight(AiplVal text_val, AiplVal size_val) {
  const char* s = (text_val.kind == AIPL_STR && text_val.s) ? text_val.s : "";
  double dsz = (size_val.kind == AIPL_FLOAT) ? size_val.f : (double)size_val.i;
  double tw = 0.0, th = 0.0;
  _aipl_measure_ttf(s, dsz, &tw, &th);
  return aipl_float(th);
}

AiplVal aipl_rt_measureTextSubstr(AiplVal text_val, AiplVal start_val, AiplVal len_val, AiplVal sz_val) {
  const char* s = (text_val.kind == AIPL_STR && text_val.s) ? text_val.s : "";
  int64_t start = (start_val.kind == AIPL_INT) ? start_val.i : (int64_t)start_val.f;
  int64_t len = (len_val.kind == AIPL_INT) ? len_val.i : (int64_t)len_val.f;
  double dsz = (sz_val.kind == AIPL_FLOAT) ? sz_val.f : (double)sz_val.i;
  if (start < 0) start = 0;
  int64_t slen = (int64_t)strlen(s);
  if (start >= slen || len <= 0) return aipl_float(0.0);
  if (start + len > slen) len = slen - start;
  char sub[1024];
  if (len >= (int64_t)sizeof(sub)) len = sizeof(sub) - 1;
  memcpy(sub, s + start, (size_t)len);
  sub[len] = 0;
  double tw = 0.0, th = 0.0;
  _aipl_measure_ttf(sub, dsz, &tw, &th);
  return aipl_float(tw);
}

#endif // AIPL_ENABLE_GUI_AUDIO
#ifdef AIPL_ENABLE_GUI_AUDIO
AiplVal aipl_rt_drawArc(AiplVal cx_v, AiplVal cy_v, AiplVal r_v, AiplVal a1_v, AiplVal a2_v, AiplVal thick_v, AiplVal c) {
  double cx = (cx_v.kind == AIPL_FLOAT) ? cx_v.f : (double)cx_v.i;
  double cy = (cy_v.kind == AIPL_FLOAT) ? cy_v.f : (double)cy_v.i;
  double rad = (r_v.kind == AIPL_FLOAT) ? r_v.f : (double)r_v.i;
  double a1 = (a1_v.kind == AIPL_FLOAT) ? a1_v.f : (double)a1_v.i;
  double a2 = (a2_v.kind == AIPL_FLOAT) ? a2_v.f : (double)a2_v.i;
  double th = (thick_v.kind == AIPL_FLOAT) ? thick_v.f : (double)thick_v.i;
  if (rad <= 0.0) return aipl_nil();
  if (th < 1.0) th = 1.0;
  double r1 = (fabs(a1) > 6.2831853 || fabs(a2) > 6.2831853) ? (a1 * 3.141592653589793 / 180.0) : a1;
  double r2 = (fabs(a1) > 6.2831853 || fabs(a2) > 6.2831853) ? (a2 * 3.141592653589793 / 180.0) : a2;
  while (r2 < r1) r2 += 2.0 * 3.141592653589793;
  int steps = (int)(rad * (r2 - r1) * 2.0);
  if (steps < 16) steps = 16;
  if (steps > 720) steps = 720;
  double prev_x = cx + rad * cos(r1);
  double prev_y = cy + rad * sin(r1);
  for (int i = 1; i <= steps; i++) {
    double ang = r1 + (r2 - r1) * ((double)i / (double)steps);
    double cur_x = cx + rad * cos(ang);
    double cur_y = cy + rad * sin(ang);
    aipl_rt_drawLine6(aipl_float(prev_x), aipl_float(prev_y), aipl_float(cur_x), aipl_float(cur_y), c, aipl_float(th));
    prev_x = cur_x; prev_y = cur_y;
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawEllipse(AiplVal cx_v, AiplVal cy_v, AiplVal rx_v, AiplVal ry_v, AiplVal c) {
  double cx = (cx_v.kind == AIPL_FLOAT) ? cx_v.f : (double)cx_v.i;
  double cy = (cy_v.kind == AIPL_FLOAT) ? cy_v.f : (double)cy_v.i;
  double rx = (rx_v.kind == AIPL_FLOAT) ? rx_v.f : (double)rx_v.i;
  double ry = (ry_v.kind == AIPL_FLOAT) ? ry_v.f : (double)ry_v.i;
  if (rx <= 0.0 || ry <= 0.0) return aipl_nil();
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_push_ellipse((float)cx, (float)cy, (float)rx, (float)ry, r, g, b, a);
    return aipl_nil();
  }
  if (__builtin_expect(!_aipl_canvas_fb, 0)) aipl_ensure_canvas_fb();
  int min_x = (int)floor(cx - rx), max_x = (int)ceil(cx + rx);
  int min_y = (int)floor(cy - ry), max_y = (int)ceil(cy + ry);
  int clip_min_x = 0, clip_max_x = _aipl_canvas_w - 1;
  int clip_min_y = 0, clip_max_y = _aipl_canvas_h - 1;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_min_x) clip_min_x = _aipl_scissor_x;
    if (_aipl_scissor_x + _aipl_scissor_w - 1 < clip_max_x) clip_max_x = _aipl_scissor_x + _aipl_scissor_w - 1;
    if (_aipl_scissor_y > clip_min_y) clip_min_y = _aipl_scissor_y;
    if (_aipl_scissor_y + _aipl_scissor_h - 1 < clip_max_y) clip_max_y = _aipl_scissor_y + _aipl_scissor_h - 1;
  }
  if (min_x < clip_min_x) min_x = clip_min_x;
  if (min_y < clip_min_y) min_y = clip_min_y;
  if (max_x > clip_max_x) max_x = clip_max_x;
  if (max_y > clip_max_y) max_y = clip_max_y;
  if (min_x > max_x || min_y > max_y) return aipl_nil();
  uint32_t color = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
  uint64_t pixel64 = ((uint64_t)color << 32) | (uint64_t)color;
  uint32_t srcColor = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
  int cw = _aipl_canvas_w;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  double ry2 = ry * ry;
  double inv_ry2 = 1.0 / ry2;
  for (int y = min_y; y <= max_y; y++) {
    double dy = (double)y + 0.5 - cy;
    double dy2 = dy * dy;
    if (dy2 > ry2) continue;
    double half_w = rx * sqrt(1.0 - dy2 * inv_ry2);
    int sx0 = (int)ceil(cx - half_w - 0.5);
    int sx1 = (int)floor(cx + half_w - 0.5);
    if (sx0 < min_x) sx0 = min_x;
    if (sx1 > max_x) sx1 = max_x;
    if (sx0 <= sx1) {
      if (a == 255) {
        _aipl_fill_span_inbounds_opaque(fb32, cw, y, sx0, sx1 + 1, color, pixel64);
      } else {
        _aipl_blend_span_inbounds_alpha(fb32, cw, y, sx0, sx1 + 1, srcColor, (uint32_t)a);
      }
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawPolygon(AiplVal pts_v, AiplVal c) {
  if (pts_v.kind != AIPL_ARRAY || !pts_v.ptr) return aipl_nil();
  AiplArray* arr = (AiplArray*)pts_v.ptr;
  if (arr->len < 3) return aipl_nil();
  int is_vec = (arr->data[0].kind == AIPL_STRUCT);
  if (is_vec) {
    AiplVal p0 = arr->data[0];
    double x0 = (aipl_member_get(p0, "x").kind == AIPL_FLOAT) ? aipl_member_get(p0, "x").f : (double)aipl_member_get(p0, "x").i;
    double y0 = (aipl_member_get(p0, "y").kind == AIPL_FLOAT) ? aipl_member_get(p0, "y").f : (double)aipl_member_get(p0, "y").i;
    for (int64_t i = 1; i + 1 < arr->len; i++) {
      AiplVal p1 = arr->data[i];
      AiplVal p2 = arr->data[i + 1];
      double x1 = (aipl_member_get(p1, "x").kind == AIPL_FLOAT) ? aipl_member_get(p1, "x").f : (double)aipl_member_get(p1, "x").i;
      double y1 = (aipl_member_get(p1, "y").kind == AIPL_FLOAT) ? aipl_member_get(p1, "y").f : (double)aipl_member_get(p1, "y").i;
      double x2 = (aipl_member_get(p2, "x").kind == AIPL_FLOAT) ? aipl_member_get(p2, "x").f : (double)aipl_member_get(p2, "x").i;
      double y2 = (aipl_member_get(p2, "y").kind == AIPL_FLOAT) ? aipl_member_get(p2, "y").f : (double)aipl_member_get(p2, "y").i;
      AiplVal targs[7] = { aipl_float(x0), aipl_float(y0), aipl_float(x1), aipl_float(y1), aipl_float(x2), aipl_float(y2), c };
      _aipl_rt_drawTriangle_va(7, targs);
    }
  } else if (arr->len >= 6) {
    double x0 = (arr->data[0].kind == AIPL_FLOAT) ? arr->data[0].f : (double)arr->data[0].i;
    double y0 = (arr->data[1].kind == AIPL_FLOAT) ? arr->data[1].f : (double)arr->data[1].i;
    for (int64_t i = 2; i + 3 < arr->len; i += 2) {
      double x1 = (arr->data[i].kind == AIPL_FLOAT) ? arr->data[i].f : (double)arr->data[i].i;
      double y1 = (arr->data[i+1].kind == AIPL_FLOAT) ? arr->data[i+1].f : (double)arr->data[i+1].i;
      double x2 = (arr->data[i+2].kind == AIPL_FLOAT) ? arr->data[i+2].f : (double)arr->data[i+2].i;
      double y2 = (arr->data[i+3].kind == AIPL_FLOAT) ? arr->data[i+3].f : (double)arr->data[i+3].i;
      AiplVal targs[7] = { aipl_float(x0), aipl_float(y0), aipl_float(x1), aipl_float(y1), aipl_float(x2), aipl_float(y2), c };
      _aipl_rt_drawTriangle_va(7, targs);
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawRegularPolygon(AiplVal cx_v, AiplVal cy_v, AiplVal r_v, AiplVal sides_v, AiplVal c) {
  double cx = (cx_v.kind == AIPL_FLOAT) ? cx_v.f : (double)cx_v.i;
  double cy = (cy_v.kind == AIPL_FLOAT) ? cy_v.f : (double)cy_v.i;
  double rad = (r_v.kind == AIPL_FLOAT) ? r_v.f : (double)r_v.i;
  int n = (int)((sides_v.kind == AIPL_FLOAT) ? sides_v.f : sides_v.i);
  if (n < 3 || rad <= 0.0) return aipl_nil();
  double prev_x = cx + rad * cos(0.0);
  double prev_y = cy + rad * sin(0.0);
  for (int i = 1; i <= n; i++) {
    double ang = (2.0 * 3.141592653589793 * (double)i) / (double)n;
    double cur_x = cx + rad * cos(ang);
    double cur_y = cy + rad * sin(ang);
    AiplVal args[7] = { aipl_float(cx), aipl_float(cy), aipl_float(prev_x), aipl_float(prev_y), aipl_float(cur_x), aipl_float(cur_y), c };
    _aipl_rt_drawTriangle_va(7, args);
    prev_x = cur_x; prev_y = cur_y;
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawPixel(AiplVal x, AiplVal y, AiplVal c) {
  int px = (int)((x.kind == AIPL_FLOAT) ? x.f : x.i);
  int py = (int)((y.kind == AIPL_FLOAT) ? y.f : y.i);
  uint8_t r, g, b, a; aipl_unpack_color(c, &r, &g, &b, &a);
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_push_quad((float)px, (float)py, (float)px + 1.0f, (float)py + 1.0f, r, g, b, a);
    return aipl_nil();
  }
  aipl_canvas_set_pixel(px, py, r, g, b, a);
  return aipl_nil();
}

AiplVal aipl_rt_readCanvasPixel(AiplVal x_v, AiplVal y_v) {
  int x = (int)((x_v.kind == AIPL_FLOAT) ? x_v.f : x_v.i);
  int y = (int)((y_v.kind == AIPL_FLOAT) ? y_v.f : y_v.i);
  aipl_ensure_canvas_fb();
  _aipl_sync_gl_to_fb();
  int r = 0, g = 0, b = 0, a = 255;
  if (x >= 0 && x < _aipl_canvas_w && y >= 0 && y < _aipl_canvas_h) {
    size_t idx = ((size_t)y * (size_t)_aipl_canvas_w + (size_t)x) * 4;
    b = _aipl_canvas_fb[idx];
    g = _aipl_canvas_fb[idx + 1];
    r = _aipl_canvas_fb[idx + 2];
    a = _aipl_canvas_fb[idx + 3];
  }
  AiplVal v = aipl_struct_new("Color", 4, (const char*[]){ "r", "g", "b", "a" }, (AiplVal[]){ aipl_int(r), aipl_int(g), aipl_int(b), aipl_int(a) });
  if (v.ptr) ((AiplStruct*)v.ptr)->extra_i = (int64_t)(((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b);
  return v;
}

AiplVal aipl_rt_readPixels(void) {
  aipl_ensure_canvas_fb();
  _aipl_sync_gl_to_fb();
  size_t npix = (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h;
  size_t sz = npix * 4;
  AiplVal bv = aipl_bytes_new(sz);
  AiplBytes* b = (AiplBytes*)bv.ptr;
  if (sz > 0 && b && b->data && _aipl_canvas_fb) {
    const uint8_t* src = _aipl_canvas_fb;
    uint8_t* dst = b->data;
    for (size_t i = 0; i < npix; i++) {
      dst[i * 4 + 0] = src[i * 4 + 2];
      dst[i * 4 + 1] = src[i * 4 + 1];
      dst[i * 4 + 2] = src[i * 4 + 0];
      dst[i * 4 + 3] = src[i * 4 + 3];
    }
  }
  return bv;
}

AiplVal aipl_rt_saveCanvasSnapshot(AiplVal p_val) {
  const char* path = p_val.s ? p_val.s : "snapshot.ppm";
  aipl_ensure_canvas_fb();
  _aipl_sync_gl_to_fb();
  FILE* f = fopen(path, "wb");
  if (!f) return aipl_err(aipl_str("saveCanvasSnapshot: cannot open file for writing"));
  fprintf(f, "P6\n%d %d\n255\n", _aipl_canvas_w, _aipl_canvas_h);
  for (int y = 0; y < _aipl_canvas_h; y++) {
    for (int x = 0; x < _aipl_canvas_w; x++) {
      size_t idx = ((size_t)y * (size_t)_aipl_canvas_w + (size_t)x) * 4;
      fputc(_aipl_canvas_fb[idx + 2], f);
      fputc(_aipl_canvas_fb[idx + 1], f);
      fputc(_aipl_canvas_fb[idx + 0], f);
    }
  }
  fclose(f);
  return aipl_ok(aipl_bool(true));
}

AiplVal aipl_rt_drawPolyline(AiplVal pts_val, AiplVal c, AiplVal thick) {
  (void)thick;
  if (pts_val.kind != AIPL_ARRAY || !pts_val.ptr) return aipl_nil();
  AiplArray* a = (AiplArray*)pts_val.ptr;
  if (a->len < 4) return aipl_nil();
  for (int64_t i = 0; i + 3 < a->len; i += 2) {
    aipl_rt_drawLine(a->data[i], a->data[i + 1], a->data[i + 2], a->data[i + 3], c);
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawLineStrip(AiplVal pts_val, AiplVal c) {
  return aipl_rt_drawPolyline(pts_val, c, aipl_int(1));
}

AiplVal aipl_rt_drawLineLoop(AiplVal pts_val, AiplVal c) {
  if (pts_val.kind != AIPL_ARRAY || !pts_val.ptr) return aipl_nil();
  AiplArray* a = (AiplArray*)pts_val.ptr;
  if (a->len < 4) return aipl_nil();
  aipl_rt_drawPolyline(pts_val, c, aipl_int(1));
  aipl_rt_drawLine(a->data[a->len - 2], a->data[a->len - 1], a->data[0], a->data[1], c);
  return aipl_nil();
}

AiplVal aipl_rt_drawRectGradientH(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v, AiplVal c1, AiplVal c2) {
  int rx = (int)((x_v.kind == AIPL_FLOAT) ? x_v.f : x_v.i);
  int ry = (int)((y_v.kind == AIPL_FLOAT) ? y_v.f : y_v.i);
  int rw = (int)((w_v.kind == AIPL_FLOAT) ? w_v.f : w_v.i);
  int rh = (int)((h_v.kind == AIPL_FLOAT) ? h_v.f : h_v.i);
  if (rw <= 0 || rh <= 0) return aipl_nil();
  uint8_t r1, g1, b1, a1, r2, g2, b2, a2;
  aipl_unpack_color(c1, &r1, &g1, &b1, &a1);
  aipl_unpack_color(c2, &r2, &g2, &b2, &a2);
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_select_tex(0);
    if (_aipl_gl_vert_count + 6 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
    float fx = (float)rx, fy = (float)ry, fw = (float)rw, fh = (float)rh;
    _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
    v[0].x = fx;      v[0].y = fy;      v[0].z = 0.0f; v[0].u = 0.0f; v[0].v = 0.0f; v[0].r = r1; v[0].g = g1; v[0].b = b1; v[0].a = a1;
    v[1].x = fx + fw; v[1].y = fy;      v[1].z = 0.0f; v[1].u = 0.0f; v[1].v = 0.0f; v[1].r = r2; v[1].g = g2; v[1].b = b2; v[1].a = a2;
    v[2].x = fx + fw; v[2].y = fy + fh; v[2].z = 0.0f; v[2].u = 0.0f; v[2].v = 0.0f; v[2].r = r2; v[2].g = g2; v[2].b = b2; v[2].a = a2;
    v[3].x = fx;      v[3].y = fy;      v[3].z = 0.0f; v[3].u = 0.0f; v[3].v = 0.0f; v[3].r = r1; v[3].g = g1; v[3].b = b1; v[3].a = a1;
    v[4].x = fx + fw; v[4].y = fy + fh; v[4].z = 0.0f; v[4].u = 0.0f; v[4].v = 0.0f; v[4].r = r2; v[4].g = g2; v[4].b = b2; v[4].a = a2;
    v[5].x = fx;      v[5].y = fy + fh; v[5].z = 0.0f; v[5].u = 0.0f; v[5].v = 0.0f; v[5].r = r1; v[5].g = g1; v[5].b = b1; v[5].a = a1;
    _aipl_gl_vert_count += 6;
    return aipl_nil();
  }
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb) return aipl_nil();
  int x0 = rx, x1 = rx + rw;
  int y0 = ry, y1 = ry + rh;
  int clip_x0 = 0, clip_x1 = _aipl_canvas_w;
  int clip_y0 = 0, clip_y1 = _aipl_canvas_h;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_x0) clip_x0 = _aipl_scissor_x;
    if (_aipl_scissor_y > clip_y0) clip_y0 = _aipl_scissor_y;
    if (_aipl_scissor_x + _aipl_scissor_w < clip_x1) clip_x1 = _aipl_scissor_x + _aipl_scissor_w;
    if (_aipl_scissor_y + _aipl_scissor_h < clip_y1) clip_y1 = _aipl_scissor_y + _aipl_scissor_h;
  }
  if (x0 < clip_x0) x0 = clip_x0;
  if (y0 < clip_y0) y0 = clip_y0;
  if (x1 > clip_x1) x1 = clip_x1;
  if (y1 > clip_y1) y1 = clip_y1;
  if (x0 >= x1 || y0 >= y1) return aipl_nil();
  int span_w = x1 - x0;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  int cw = _aipl_canvas_w;
  double inv_rw = (rw > 1) ? (1.0 / (double)(rw - 1)) : 0.0;
  if (a1 == 255 && a2 == 255) {
    uint32_t* first_row = fb32 + (size_t)y0 * (size_t)cw + (size_t)x0;
    for (int px = x0; px < x1; px++) {
      double t = (double)(px - rx) * inv_rw;
      uint8_t r = (uint8_t)(r1 + t * (r2 - r1));
      uint8_t g = (uint8_t)(g1 + t * (g2 - g1));
      uint8_t b = (uint8_t)(b1 + t * (b2 - b1));
      first_row[px - x0] = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
    }
    for (int py = y0 + 1; py < y1; py++) {
      memcpy(fb32 + (size_t)py * (size_t)cw + (size_t)x0, first_row, (size_t)span_w * sizeof(uint32_t));
    }
  } else {
    for (int py = y0; py < y1; py++) {
      uint32_t* row = fb32 + (size_t)py * (size_t)cw;
      for (int px = x0; px < x1; px++) {
        double t = (double)(px - rx) * inv_rw;
        uint32_t r = (uint32_t)(r1 + t * (r2 - r1));
        uint32_t g = (uint32_t)(g1 + t * (g2 - g1));
        uint32_t b = (uint32_t)(b1 + t * (b2 - b1));
        uint32_t a = (uint32_t)(a1 + t * (a2 - a1));
        uint32_t d = row[px];
        uint32_t inv_a = 256u - a;
        uint32_t a_plus = a + 1u;
        uint32_t out_b = (b * a_plus + (d & 0xFFu) * inv_a) >> 8;
        uint32_t out_g = (g * a_plus + ((d >> 8) & 0xFFu) * inv_a) >> 8;
        uint32_t out_r = (r * a_plus + ((d >> 16) & 0xFFu) * inv_a) >> 8;
        row[px] = 0xFF000000u | (out_r << 16) | (out_g << 8) | out_b;
      }
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawRectGradientV(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v, AiplVal c1, AiplVal c2) {
  int rx = (int)((x_v.kind == AIPL_FLOAT) ? x_v.f : x_v.i);
  int ry = (int)((y_v.kind == AIPL_FLOAT) ? y_v.f : y_v.i);
  int rw = (int)((w_v.kind == AIPL_FLOAT) ? w_v.f : w_v.i);
  int rh = (int)((h_v.kind == AIPL_FLOAT) ? h_v.f : h_v.i);
  if (rw <= 0 || rh <= 0) return aipl_nil();
  uint8_t r1, g1, b1, a1, r2, g2, b2, a2;
  aipl_unpack_color(c1, &r1, &g1, &b1, &a1);
  aipl_unpack_color(c2, &r2, &g2, &b2, &a2);
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_select_tex(0);
    if (_aipl_gl_vert_count + 6 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
    float fx = (float)rx, fy = (float)ry, fw = (float)rw, fh = (float)rh;
    _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
    v[0].x = fx;      v[0].y = fy;      v[0].z = 0.0f; v[0].u = 0.0f; v[0].v = 0.0f; v[0].r = r1; v[0].g = g1; v[0].b = b1; v[0].a = a1;
    v[1].x = fx + fw; v[1].y = fy;      v[1].z = 0.0f; v[1].u = 0.0f; v[1].v = 0.0f; v[1].r = r1; v[1].g = g1; v[1].b = b1; v[1].a = a1;
    v[2].x = fx + fw; v[2].y = fy + fh; v[2].z = 0.0f; v[2].u = 0.0f; v[2].v = 0.0f; v[2].r = r2; v[2].g = g2; v[2].b = b2; v[2].a = a2;
    v[3].x = fx;      v[3].y = fy;      v[3].z = 0.0f; v[3].u = 0.0f; v[3].v = 0.0f; v[3].r = r1; v[3].g = g1; v[3].b = b1; v[3].a = a1;
    v[4].x = fx + fw; v[4].y = fy + fh; v[4].z = 0.0f; v[4].u = 0.0f; v[4].v = 0.0f; v[4].r = r2; v[4].g = g2; v[4].b = b2; v[4].a = a2;
    v[5].x = fx;      v[5].y = fy + fh; v[5].z = 0.0f; v[5].u = 0.0f; v[5].v = 0.0f; v[5].r = r2; v[5].g = g2; v[5].b = b2; v[5].a = a2;
    _aipl_gl_vert_count += 6;
    return aipl_nil();
  }
  for (int dy = 0; dy < rh; dy++) {
    double t = (rh > 1) ? (double)dy / (double)(rh - 1) : 0.0;
    uint8_t r = (uint8_t)(r1 + t * (r2 - r1));
    uint8_t g = (uint8_t)(g1 + t * (g2 - g1));
    uint8_t b = (uint8_t)(b1 + t * (b2 - b1));
    uint8_t a = (uint8_t)(a1 + t * (a2 - a1));
    _aipl_fill_span(ry + dy, rx, rx + rw, r, g, b, a);
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawLinearGradient(AiplVal x1, AiplVal y1, AiplVal x2, AiplVal y2, AiplVal c1, AiplVal c2) {
  return aipl_rt_drawRectGradientH(x1, y1, aipl_sub(x2, x1), aipl_sub(y2, y1), c1, c2);
}

AiplVal aipl_rt_drawGridTiles(AiplVal cols_v, AiplVal rows_v, AiplVal tw_v, AiplVal th_v, AiplVal tiles_v, AiplVal pal_v) {
  int64_t cols = cols_v.i, rows = rows_v.i;
  int64_t tw = tw_v.i, th = th_v.i;
  if (tiles_v.kind != AIPL_ARRAY || !tiles_v.ptr || pal_v.kind != AIPL_ARRAY || !pal_v.ptr) return aipl_nil();
  AiplArray* tiles = (AiplArray*)tiles_v.ptr;
  AiplArray* pal = (AiplArray*)pal_v.ptr;
  for (int64_t r = 0; r < rows; r++) {
    for (int64_t c = 0; c < cols; c++) {
      int64_t idx = r * cols + c;
      if (idx < tiles->len) {
        int64_t tid = tiles->data[idx].i;
        if (tid >= 0 && tid < pal->len) {
          aipl_rt_drawRect(aipl_int(c * tw), aipl_int(r * th), tw_v, th_v, pal->data[tid]);
        }
      }
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawCellGrid(AiplVal sx_v, AiplVal sy_v, AiplVal cw_v, AiplVal ch_v, AiplVal grid_v, AiplVal colormap_v) {
  int64_t sx = sx_v.i, sy = sy_v.i, cw = cw_v.i, ch = ch_v.i;
  if (grid_v.kind != AIPL_ARRAY || !grid_v.ptr) return aipl_nil();
  AiplArray* g = (AiplArray*)grid_v.ptr;
  for (int64_t r = 0; r < g->len; r++) {
    AiplVal row = g->data[r];
    if (row.kind == AIPL_ARRAY && row.ptr) {
      AiplArray* ra = (AiplArray*)row.ptr;
      for (int64_t c = 0; c < ra->len; c++) {
        AiplVal cell = ra->data[c];
        AiplVal col = cell;
        if (colormap_v.kind == AIPL_ARRAY && colormap_v.ptr) {
          AiplArray* ca = (AiplArray*)colormap_v.ptr;
          if (cell.i >= 0 && cell.i < ca->len) col = ca->data[cell.i];
        } else if (colormap_v.kind == AIPL_MAP && colormap_v.ptr) {
          AiplVal cs = aipl_to_str(cell); col = aipl_map_get(colormap_v, cs.s ? cs.s : "");
        }
        aipl_rt_drawRect(aipl_int(sx + c * cw), aipl_int(sy + r * ch), cw_v, ch_v, col);
      }
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawRectBatch(AiplVal rects_v) {
  if (rects_v.kind != AIPL_ARRAY || !rects_v.ptr) return aipl_nil();
  AiplArray* a = (AiplArray*)rects_v.ptr;
  for (int64_t i = 0; i < a->len; i++) {
    AiplVal it = a->data[i];
    if (it.kind == AIPL_ARRAY && it.ptr) {
      AiplArray* item = (AiplArray*)it.ptr;
      if (item->len >= 5) {
        aipl_rt_drawRect(item->data[0], item->data[1], item->data[2], item->data[3], item->data[4]);
      }
    } else if (it.kind == AIPL_STRUCT && it.ptr) {
      AiplVal rx = aipl_member_get(it, "x");
      AiplVal ry = aipl_member_get(it, "y");
      AiplVal rw = aipl_member_get(it, "w");
      if (rw.kind == AIPL_NIL) rw = aipl_member_get(it, "width");
      AiplVal rh = aipl_member_get(it, "h");
      if (rh.kind == AIPL_NIL) rh = aipl_member_get(it, "height");
      AiplVal rc = aipl_member_get(it, "c");
      if (rc.kind == AIPL_NIL) rc = aipl_member_get(it, "color");
      aipl_rt_drawRect(rx, ry, rw, rh, rc);
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawPixelBuffer(AiplVal pixels_v, AiplVal gw_v, AiplVal gh_v, AiplVal dx_v, AiplVal dy_v, AiplVal dw_v, AiplVal dh_v) {
  if (pixels_v.kind != AIPL_ARRAY || !pixels_v.ptr) return aipl_nil();
  AiplArray* arr = (AiplArray*)pixels_v.ptr;
  int gw = (int)((gw_v.kind == AIPL_FLOAT) ? gw_v.f : gw_v.i);
  int gh = (int)((gh_v.kind == AIPL_FLOAT) ? gh_v.f : gh_v.i);
  int dx = (int)((dx_v.kind == AIPL_FLOAT) ? dx_v.f : dx_v.i);
  int dy = (int)((dy_v.kind == AIPL_FLOAT) ? dy_v.f : dy_v.i);
  int dw = (int)((dw_v.kind == AIPL_FLOAT) ? dw_v.f : dw_v.i);
  int dh = (int)((dh_v.kind == AIPL_FLOAT) ? dh_v.f : dh_v.i);
  if (gw <= 0 || gh <= 0 || dw <= 0 || dh <= 0) return aipl_nil();
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    float cell_w = (float)dw / (float)gw;
    float cell_h = (float)dh / (float)gh;
    for (int gy = 0; gy < gh; gy++) {
      for (int gx = 0; gx < gw; gx++) {
        int64_t idx = (int64_t)gy * gw + gx;
        if (idx >= arr->len) break;
        uint8_t r, g, b, a; aipl_unpack_color(arr->data[idx], &r, &g, &b, &a);
        if (a > 0) {
          float qx0 = (float)dx + (float)gx * cell_w;
          float qy0 = (float)dy + (float)gy * cell_h;
          _aipl_gl_push_quad(qx0, qy0, qx0 + cell_w, qy0 + cell_h, r, g, b, a);
        }
      }
    }
    return aipl_nil();
  }
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb) return aipl_nil();
  int clip_x0 = 0, clip_x1 = _aipl_canvas_w;
  int clip_y0 = 0, clip_y1 = _aipl_canvas_h;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_x0) clip_x0 = _aipl_scissor_x;
    if (_aipl_scissor_y > clip_y0) clip_y0 = _aipl_scissor_y;
    if (_aipl_scissor_x + _aipl_scissor_w < clip_x1) clip_x1 = _aipl_scissor_x + _aipl_scissor_w;
    if (_aipl_scissor_y + _aipl_scissor_h < clip_y1) clip_y1 = _aipl_scissor_y + _aipl_scissor_h;
  }
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  int cw = _aipl_canvas_w;
  if (dw == gw && dh == gh) {
    int gx0 = (dx < clip_x0) ? (clip_x0 - dx) : 0;
    int gx1 = (dx + gw > clip_x1) ? (clip_x1 - dx) : gw;
    int gy0 = (dy < clip_y0) ? (clip_y0 - dy) : 0;
    int gy1 = (dy + gh > clip_y1) ? (clip_y1 - dy) : gh;
    for (int gy = gy0; gy < gy1; gy++) {
      uint32_t* row = fb32 + (size_t)(dy + gy) * (size_t)cw;
      for (int gx = gx0; gx < gx1; gx++) {
        int64_t idx = (int64_t)gy * gw + gx;
        if (idx >= arr->len) break;
        uint8_t r, g, b, a; aipl_unpack_color(arr->data[idx], &r, &g, &b, &a);
        if (a == 255) {
          row[dx + gx] = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
        } else if (a > 0) {
          uint32_t d = row[dx + gx];
          uint32_t inv_a = 256u - a;
          uint32_t a_plus = (uint32_t)a + 1u;
          uint32_t out_b = ((uint32_t)b * a_plus + (d & 0xFFu) * inv_a) >> 8;
          uint32_t out_g = ((uint32_t)g * a_plus + ((d >> 8) & 0xFFu) * inv_a) >> 8;
          uint32_t out_r = ((uint32_t)r * a_plus + ((d >> 16) & 0xFFu) * inv_a) >> 8;
          row[dx + gx] = 0xFF000000u | (out_r << 16) | (out_g << 8) | out_b;
        }
      }
    }
  } else {
    int tx0 = (dx < clip_x0) ? (clip_x0 - dx) : 0;
    int tx1 = (dx + dw > clip_x1) ? (clip_x1 - dx) : dw;
    int ty0 = (dy < clip_y0) ? (clip_y0 - dy) : 0;
    int ty1 = (dy + dh > clip_y1) ? (clip_y1 - dy) : dh;
    for (int ty = ty0; ty < ty1; ty++) {
      int gy = (ty * gh) / dh;
      uint32_t* row = fb32 + (size_t)(dy + ty) * (size_t)cw;
      for (int tx = tx0; tx < tx1; tx++) {
        int gx = (tx * gw) / dw;
        int64_t idx = (int64_t)gy * gw + gx;
        if (idx >= arr->len) continue;
        uint8_t r, g, b, a; aipl_unpack_color(arr->data[idx], &r, &g, &b, &a);
        if (a == 255) {
          row[dx + tx] = (uint32_t)b | ((uint32_t)g << 8) | ((uint32_t)r << 16) | 0xFF000000u;
        } else if (a > 0) {
          uint32_t d = row[dx + tx];
          uint32_t inv_a = 256u - a;
          uint32_t a_plus = (uint32_t)a + 1u;
          uint32_t out_b = ((uint32_t)b * a_plus + (d & 0xFFu) * inv_a) >> 8;
          uint32_t out_g = ((uint32_t)g * a_plus + ((d >> 8) & 0xFFu) * inv_a) >> 8;
          uint32_t out_r = ((uint32_t)r * a_plus + ((d >> 16) & 0xFFu) * inv_a) >> 8;
          row[dx + tx] = 0xFF000000u | (out_r << 16) | (out_g << 8) | out_b;
        }
      }
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawCirclesSoA(AiplVal xs_v, AiplVal ys_v, AiplVal r_v, AiplVal c_v, AiplVal cnt_v) {
  if (xs_v.kind != AIPL_ARRAY || !xs_v.ptr || ys_v.kind != AIPL_ARRAY || !ys_v.ptr || r_v.kind != AIPL_ARRAY || !r_v.ptr || c_v.kind != AIPL_ARRAY || !c_v.ptr) return aipl_nil();
  AiplArray* xs = (AiplArray*)xs_v.ptr; AiplArray* ys = (AiplArray*)ys_v.ptr; AiplArray* rs = (AiplArray*)r_v.ptr; AiplArray* cs = (AiplArray*)c_v.ptr;
  int64_t n = (cnt_v.kind == AIPL_FLOAT) ? (int64_t)cnt_v.f : cnt_v.i;
  if (n > xs->len) n = xs->len; if (n > ys->len) n = ys->len; if (n > rs->len) n = rs->len; if (n > cs->len) n = cs->len;
  for (int64_t i = 0; i < n; i++) aipl_rt_drawCircle(xs->data[i], ys->data[i], rs->data[i], cs->data[i]);
  return aipl_nil();
}

AiplVal aipl_rt_drawRectsSoA(AiplVal xs_v, AiplVal ys_v, AiplVal ws_v, AiplVal hs_v, AiplVal c_v, AiplVal cnt_v) {
  if (xs_v.kind != AIPL_ARRAY || !xs_v.ptr || ys_v.kind != AIPL_ARRAY || !ys_v.ptr || ws_v.kind != AIPL_ARRAY || !ws_v.ptr || hs_v.kind != AIPL_ARRAY || !hs_v.ptr || c_v.kind != AIPL_ARRAY || !c_v.ptr) return aipl_nil();
  AiplArray* xs = (AiplArray*)xs_v.ptr; AiplArray* ys = (AiplArray*)ys_v.ptr; AiplArray* ws = (AiplArray*)ws_v.ptr; AiplArray* hs = (AiplArray*)hs_v.ptr; AiplArray* cs = (AiplArray*)c_v.ptr;
  int64_t n = (cnt_v.kind == AIPL_FLOAT) ? (int64_t)cnt_v.f : cnt_v.i;
  if (n > xs->len) n = xs->len; if (n > ys->len) n = ys->len; if (n > ws->len) n = ws->len; if (n > hs->len) n = hs->len; if (n > cs->len) n = cs->len;
  for (int64_t i = 0; i < n; i++) aipl_rt_drawRect(xs->data[i], ys->data[i], ws->data[i], hs->data[i], cs->data[i]);
  return aipl_nil();
}

AiplVal aipl_rt_drawCharGrid(AiplVal sx_v, AiplVal sy_v, AiplVal cw_v, AiplVal ch_v, AiplVal lines_v, AiplVal c) {
  (void)sx_v; (void)sy_v; (void)cw_v; (void)ch_v; (void)lines_v; (void)c;
  return aipl_nil();
}

AiplVal aipl_rt_pushScissor(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v) {
  if (_aipl_scissor_sp < 8) {
    _aipl_scissor_stack[_aipl_scissor_sp].x = _aipl_scissor_x;
    _aipl_scissor_stack[_aipl_scissor_sp].y = _aipl_scissor_y;
    _aipl_scissor_stack[_aipl_scissor_sp].w = _aipl_scissor_w;
    _aipl_scissor_stack[_aipl_scissor_sp].h = _aipl_scissor_h;
    _aipl_scissor_stack[_aipl_scissor_sp].active = _aipl_scissor_active;
    _aipl_scissor_sp++;
  }
  int nx = (int)((x_v.kind == AIPL_FLOAT) ? x_v.f : x_v.i);
  int ny = (int)((y_v.kind == AIPL_FLOAT) ? y_v.f : y_v.i);
  int nw = (int)((w_v.kind == AIPL_FLOAT) ? w_v.f : w_v.i);
  int nh = (int)((h_v.kind == AIPL_FLOAT) ? h_v.f : h_v.i);
  if (_aipl_scissor_active) {
    int x1 = nx > _aipl_scissor_x ? nx : _aipl_scissor_x;
    int y1 = ny > _aipl_scissor_y ? ny : _aipl_scissor_y;
    int x2 = (nx + nw) < (_aipl_scissor_x + _aipl_scissor_w) ? (nx + nw) : (_aipl_scissor_x + _aipl_scissor_w);
    int y2 = (ny + nh) < (_aipl_scissor_y + _aipl_scissor_h) ? (ny + nh) : (_aipl_scissor_y + _aipl_scissor_h);
    _aipl_scissor_x = x1; _aipl_scissor_y = y1;
    _aipl_scissor_w = (x2 > x1) ? (x2 - x1) : 0;
    _aipl_scissor_h = (y2 > y1) ? (y2 - y1) : 0;
  } else {
    _aipl_scissor_x = nx; _aipl_scissor_y = ny; _aipl_scissor_w = nw; _aipl_scissor_h = nh;
  }
  _aipl_scissor_active = 1;
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_flush_batch();
    if (_aipl_glEnable) _aipl_glEnable(0x0C11 /* GL_SCISSOR_TEST */);
    if (_aipl_glScissor) _aipl_glScissor(_aipl_scissor_x, _aipl_canvas_h - (_aipl_scissor_y + _aipl_scissor_h), _aipl_scissor_w, _aipl_scissor_h);
  }
  return aipl_nil();
}

AiplVal aipl_rt_popScissor(void) {
  if (_aipl_scissor_sp > 0) {
    _aipl_scissor_sp--;
    _aipl_scissor_x = _aipl_scissor_stack[_aipl_scissor_sp].x;
    _aipl_scissor_y = _aipl_scissor_stack[_aipl_scissor_sp].y;
    _aipl_scissor_w = _aipl_scissor_stack[_aipl_scissor_sp].w;
    _aipl_scissor_h = _aipl_scissor_stack[_aipl_scissor_sp].h;
    _aipl_scissor_active = _aipl_scissor_stack[_aipl_scissor_sp].active;
  } else {
    _aipl_scissor_active = 0;
  }
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_flush_batch();
    if (_aipl_scissor_active) {
      if (_aipl_glEnable) _aipl_glEnable(0x0C11 /* GL_SCISSOR_TEST */);
      if (_aipl_glScissor) _aipl_glScissor(_aipl_scissor_x, _aipl_canvas_h - (_aipl_scissor_y + _aipl_scissor_h), _aipl_scissor_w, _aipl_scissor_h);
    } else {
      if (_aipl_glDisable) _aipl_glDisable(0x0C11 /* GL_SCISSOR_TEST */);
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_withViewport(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v, AiplVal fn_v) {
  aipl_rt_pushScissor(x_v, y_v, w_v, h_v);
  if (fn_v.kind == AIPL_FUNC && fn_v.ptr) {
    AiplFnPtr fn = (AiplFnPtr)fn_v.ptr;
    fn(0, NULL);
  }
  aipl_rt_popScissor();
  return aipl_nil();
}

AiplVal aipl_rt_createImageFromPixels(AiplVal w, AiplVal h, AiplVal px) { (void)w; (void)h; (void)px; static int _id = 100; return aipl_int(_id++); }

AiplVal aipl_rt_pushMatrix(void) { return aipl_nil(); }

AiplVal aipl_rt_popMatrix(void) { return aipl_nil(); }

AiplVal aipl_rt_translate2D(AiplVal x, AiplVal y) { (void)x;(void)y; return aipl_nil(); }

AiplVal aipl_rt_rotate2D(AiplVal rad) { (void)rad; return aipl_nil(); }

AiplVal aipl_rt_scale2D(AiplVal sx, AiplVal sy) { (void)sx;(void)sy; return aipl_nil(); }

AiplVal aipl_rt_shear2D(AiplVal shx, AiplVal shy) { (void)shx;(void)shy; return aipl_nil(); }

static int _aipl_in_3d_mode = 0;
static double _aipl_cam3d_pos[3] = { 0.0, 2.0, -5.0 };
static double _aipl_cam3d_target[3] = { 0.0, 0.0, 0.0 };
static double _aipl_cam3d_up[3] = { 0.0, 1.0, 0.0 };
static double _aipl_cam3d_fovy = 60.0;

static void _aipl_ensure_zbuffer(int w, int h) {
  if (w <= 0 || h <= 0) return;
  size_t need = (size_t)w * (size_t)h;
  if (need > _aipl_zbuffer_cap) {
    float* nz = (float*)realloc(_aipl_zbuffer, need * sizeof(float));
    if (nz) {
      _aipl_zbuffer = nz;
      _aipl_canvas_zb = nz;
      _aipl_zbuffer_cap = need;
    }
  }
  _aipl_canvas_zb = _aipl_zbuffer;
  if (_aipl_zbuffer) {
    for (size_t i = 0; i < need; i++) _aipl_zbuffer[i] = 1e30f;
  }
}

AiplVal aipl_rt_setDepthTest(AiplVal enabled_v) {
  int en = aipl_truthy(enabled_v) ? 1 : 0;
  _aipl_depth_test_enabled = en;
  if (en) {
    aipl_ensure_canvas_fb();
    if (!_aipl_zbuffer || _aipl_zbuffer_cap < (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h) {
      _aipl_ensure_zbuffer(_aipl_canvas_w, _aipl_canvas_h);
    }
  }
#ifndef _WIN32
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_flush_batch();
    if (en) {
      if (_aipl_glEnable) _aipl_glEnable(0x0B71 /* GL_DEPTH_TEST */);
      if (_aipl_glDepthFunc) _aipl_glDepthFunc(0x0203 /* GL_LEQUAL */);
      if (_aipl_glDepthMask) _aipl_glDepthMask((_aipl_cur_blend_mode == 0) ? 1 : 0);
    } else {
      if (_aipl_glDisable) _aipl_glDisable(0x0B71 /* GL_DEPTH_TEST */);
    }
  }
#endif
  return aipl_nil();
}

AiplVal aipl_rt_setBlendMode(AiplVal mode_v) {
  int mode = 0;
  if (mode_v.kind == AIPL_STRUCT) {
    AiplVal en = aipl_member_get(mode_v, "enabled");
    AiplVal dst = aipl_member_get(mode_v, "dstColor");
    if (!aipl_truthy(en)) mode = 0;
    else if (dst.kind == AIPL_INT && dst.i == 1) mode = 1;
    else mode = 0;
  } else {
    mode = (int)aipl_to_c_double(mode_v);
  }
  if (mode < 0) mode = 0;
  else if (mode > 3) mode = 3;
  char mbuf[8];
  snprintf(mbuf, sizeof(mbuf), "%d", mode);
  setenv("__AIPL_BLEND_MODE", mbuf, 1);
#ifndef _WIN32
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    if (_aipl_cur_blend_mode != mode) {
      _aipl_gl_flush_batch();
    }
    if (_aipl_glEnable) _aipl_glEnable(0x0BE2 /* GL_BLEND */);
    if (_aipl_glBlendFunc) {
      if (mode == 1) {
        _aipl_glBlendFunc(0x0302 /* GL_SRC_ALPHA */, 0x0001 /* GL_ONE */);
      } else if (mode == 2) {
        _aipl_glBlendFunc(0x0306 /* GL_DST_COLOR */, 0x0303 /* GL_ONE_MINUS_SRC_ALPHA */);
      } else if (mode == 3) {
        _aipl_glBlendFunc(0x0001 /* GL_ONE */, 0x0301 /* GL_ONE_MINUS_SRC_COLOR */);
      } else {
        _aipl_glBlendFunc(0x0302 /* GL_SRC_ALPHA */, 0x0303 /* GL_ONE_MINUS_SRC_ALPHA */);
      }
    }
    if (_aipl_glColorMask) _aipl_glColorMask(1, 1, 1, 0);
    if (_aipl_glDepthMask && _aipl_depth_test_enabled) {
      _aipl_glDepthMask((mode == 0) ? 1 : 0);
    }
  }
#endif
  _aipl_cur_blend_mode = mode;
  return aipl_nil();
}

AiplVal aipl_rt_getBlendMode(void) {
  return aipl_int(_aipl_cur_blend_mode);
}

AiplVal aipl_rt_blendModeAlpha(void) { return aipl_int(0); }
AiplVal aipl_rt_blendModeAdditive(void) { return aipl_int(1); }
AiplVal aipl_rt_blendModeMultiplied(void) { return aipl_int(2); }
AiplVal aipl_rt_blendModeScreen(void) { return aipl_int(3); }

AiplVal aipl_rt_clearDepth(void) {
  aipl_ensure_canvas_fb();
  _aipl_ensure_zbuffer(_aipl_canvas_w, _aipl_canvas_h);
#ifndef _WIN32
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_flush_batch();
    if (_aipl_glDepthMask) _aipl_glDepthMask(1);
    if (_aipl_glClearDepth) _aipl_glClearDepth(1.0);
    if (_aipl_glClear) _aipl_glClear(0x00000100 /* GL_DEPTH_BUFFER_BIT */);
    if (_aipl_glDepthMask && _aipl_depth_test_enabled) {
      _aipl_glDepthMask((_aipl_cur_blend_mode == 0) ? 1 : 0);
    }
    _aipl_gl_fb_dirty = 1;
  }
#endif
  return aipl_nil();
}

AiplVal aipl_rt_beginWorldPass(void) {
  _aipl_ui_tracking_enabled = 0;
  aipl_rt_setBlendMode(aipl_int(0));
  return aipl_nil();
}

AiplVal aipl_rt_endWorldPass(void) {
  _aipl_ui_tracking_enabled = 1;
  aipl_rt_setBlendMode(aipl_int(0));
  return aipl_nil();
}

AiplVal aipl_rt_setUiTracking(AiplVal enabled_v) {
  _aipl_ui_tracking_enabled = aipl_truthy(enabled_v) ? 1 : 0;
  return aipl_nil();
}

static void _aipl_rasterize_triangle_gouraud(
    float fx1, float fy1, float fz1,
    float fx2, float fy2, float fz2,
    float fx3, float fy3, float fz3,
    uint8_t r1, uint8_t g1, uint8_t b1, uint8_t a1,
    uint8_t r2, uint8_t g2, uint8_t b2, uint8_t a2,
    uint8_t r3, uint8_t g3, uint8_t b3, uint8_t a3,
    int use_depth) {
  if (a1 == 0 && a2 == 0 && a3 == 0) return;
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_push_tri_gouraud_3d(fx1, fy1, fz1, fx2, fy2, fz2, fx3, fy3, fz3, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3);
    return;
  }
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb) return;
  if (use_depth && (!_aipl_zbuffer || _aipl_zbuffer_cap < (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h)) {
    _aipl_ensure_zbuffer(_aipl_canvas_w, _aipl_canvas_h);
  }
  float denom = (fy2 - fy3) * (fx1 - fx3) + (fx3 - fx2) * (fy1 - fy3);
  if (fabsf(denom) < 1e-5f) return;
  float inv_denom = 1.0f / denom;
  int min_x = (int)floorf(fminf(fx1, fminf(fx2, fx3)));
  int max_x = (int)ceilf(fmaxf(fx1, fmaxf(fx2, fx3)));
  int min_y = (int)floorf(fminf(fy1, fminf(fy2, fy3)));
  int max_y = (int)ceilf(fmaxf(fy1, fmaxf(fy2, fy3)));
  int clip_x0 = 0, clip_y0 = 0, clip_x1 = _aipl_canvas_w, clip_y1 = _aipl_canvas_h;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_x0) clip_x0 = _aipl_scissor_x;
    if (_aipl_scissor_y > clip_y0) clip_y0 = _aipl_scissor_y;
    if (_aipl_scissor_x + _aipl_scissor_w < clip_x1) clip_x1 = _aipl_scissor_x + _aipl_scissor_w;
    if (_aipl_scissor_y + _aipl_scissor_h < clip_y1) clip_y1 = _aipl_scissor_y + _aipl_scissor_h;
  }
  if (min_x < clip_x0) min_x = clip_x0;
  if (max_x >= clip_x1) max_x = clip_x1 - 1;
  if (min_y < clip_y0) min_y = clip_y0;
  if (max_y >= clip_y1) max_y = clip_y1 - 1;
  if (min_x > max_x || min_y > max_y) return;

  float dw1_dx = (fy2 - fy3) * inv_denom;
  float dw2_dx = (fy3 - fy1) * inv_denom;
  float fr1 = (float)r1, fg1 = (float)g1, fb1 = (float)b1, fa1 = (float)a1;
  float fr2 = (float)r2, fg2 = (float)g2, fb2 = (float)b2, fa2 = (float)a2;
  float fr3 = (float)r3, fg3 = (float)g3, fb3 = (float)b3, fa3 = (float)a3;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  int cw = _aipl_canvas_w;

  for (int py = min_y; py <= max_y; py++) {
    float cy = (float)py + 0.5f;
    float cx0 = (float)min_x + 0.5f;
    float w1 = ((fy2 - fy3) * (cx0 - fx3) + (fx3 - fx2) * (cy - fy3)) * inv_denom;
    float w2 = ((fy3 - fy1) * (cx0 - fx3) + (fx1 - fx3) * (cy - fy3)) * inv_denom;
    size_t row_off = (size_t)py * (size_t)cw;
    uint32_t* prow = fb32 + row_off;
    float* zrow = (use_depth && _aipl_canvas_zb) ? (_aipl_canvas_zb + row_off) : NULL;
    for (int px = min_x; px <= max_x; px++) {
      float w3 = 1.0f - w1 - w2;
      if (w1 >= -1e-4f && w2 >= -1e-4f && w3 >= -1e-4f) {
        float cw1 = w1 < 0.0f ? 0.0f : (w1 > 1.0f ? 1.0f : w1);
        float cw2 = w2 < 0.0f ? 0.0f : (w2 > 1.0f ? 1.0f : w2);
        float cw3 = w3 < 0.0f ? 0.0f : (w3 > 1.0f ? 1.0f : w3);
        int pa = (int)(cw1 * fa1 + cw2 * fa2 + cw3 * fa3 + 0.5f);
        if (pa > 0) {
          if (pa > 255) pa = 255;
          int depth_ok = 1;
          if (zrow) {
            float pz = cw1 * fz1 + cw2 * fz2 + cw3 * fz3;
            if (pz <= zrow[px]) {
              if (_aipl_cur_blend_mode == 0) zrow[px] = pz;
            } else {
              depth_ok = 0;
            }
          }
          if (depth_ok) {
            int pr = (int)(cw1 * fr1 + cw2 * fr2 + cw3 * fr3 + 0.5f);
            int pg = (int)(cw1 * fg1 + cw2 * fg2 + cw3 * fg3 + 0.5f);
            int pb = (int)(cw1 * fb1 + cw2 * fb2 + cw3 * fb3 + 0.5f);
            if (pr < 0) pr = 0; else if (pr > 255) pr = 255;
            if (pg < 0) pg = 0; else if (pg > 255) pg = 255;
            if (pb < 0) pb = 0; else if (pb > 255) pb = 255;
            prow[px] = _aipl_blend_pixel(prow[px], (uint32_t)pr, (uint32_t)pg, (uint32_t)pb, (uint32_t)pa);
          }
        }
      }
      w1 += dw1_dx;
      w2 += dw2_dx;
    }
  }
}

AiplVal aipl_rt_drawTriangleGouraud(AiplVal x1_v, AiplVal y1_v, AiplVal x2_v, AiplVal y2_v, AiplVal x3_v, AiplVal y3_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v) {
  float fx1 = (float)aipl_to_c_double(x1_v), fy1 = (float)aipl_to_c_double(y1_v);
  float fx2 = (float)aipl_to_c_double(x2_v), fy2 = (float)aipl_to_c_double(y2_v);
  float fx3 = (float)aipl_to_c_double(x3_v), fy3 = (float)aipl_to_c_double(y3_v);
  uint8_t r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3;
  aipl_unpack_color(c1_v, &r1, &g1, &b1, &a1);
  aipl_unpack_color(c2_v, &r2, &g2, &b2, &a2);
  aipl_unpack_color(c3_v, &r3, &g3, &b3, &a3);
  _aipl_rasterize_triangle_gouraud(fx1, fy1, 0.0f, fx2, fy2, 0.0f, fx3, fy3, 0.0f, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, _aipl_depth_test_enabled);
  return aipl_nil();
}

AiplVal aipl_rt_drawTriangle3DGouraud(AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v) {
  float fx1 = (float)aipl_to_c_double(x1_v), fy1 = (float)aipl_to_c_double(y1_v), fz1 = (float)aipl_to_c_double(z1_v);
  float fx2 = (float)aipl_to_c_double(x2_v), fy2 = (float)aipl_to_c_double(y2_v), fz2 = (float)aipl_to_c_double(z2_v);
  float fx3 = (float)aipl_to_c_double(x3_v), fy3 = (float)aipl_to_c_double(y3_v), fz3 = (float)aipl_to_c_double(z3_v);
  uint8_t r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3;
  aipl_unpack_color(c1_v, &r1, &g1, &b1, &a1);
  aipl_unpack_color(c2_v, &r2, &g2, &b2, &a2);
  aipl_unpack_color(c3_v, &r3, &g3, &b3, &a3);
  _aipl_rasterize_triangle_gouraud(fx1, fy1, fz1, fx2, fy2, fz2, fx3, fy3, fz3, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, _aipl_depth_test_enabled);
  return aipl_nil();
}

AiplVal aipl_rt_drawQuad3DGouraud(AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal x4_v, AiplVal y4_v, AiplVal z4_v, AiplVal c1_v, AiplVal c2_v, AiplVal c3_v, AiplVal c4_v) {
  float fx1 = (float)aipl_to_c_double(x1_v), fy1 = (float)aipl_to_c_double(y1_v), fz1 = (float)aipl_to_c_double(z1_v);
  float fx2 = (float)aipl_to_c_double(x2_v), fy2 = (float)aipl_to_c_double(y2_v), fz2 = (float)aipl_to_c_double(z2_v);
  float fx3 = (float)aipl_to_c_double(x3_v), fy3 = (float)aipl_to_c_double(y3_v), fz3 = (float)aipl_to_c_double(z3_v);
  float fx4 = (float)aipl_to_c_double(x4_v), fy4 = (float)aipl_to_c_double(y4_v), fz4 = (float)aipl_to_c_double(z4_v);
  uint8_t r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, r4, g4, b4, a4;
  aipl_unpack_color(c1_v, &r1, &g1, &b1, &a1);
  aipl_unpack_color(c2_v, &r2, &g2, &b2, &a2);
  aipl_unpack_color(c3_v, &r3, &g3, &b3, &a3);
  aipl_unpack_color(c4_v, &r4, &g4, &b4, &a4);
  _aipl_rasterize_triangle_gouraud(fx1, fy1, fz1, fx2, fy2, fz2, fx3, fy3, fz3, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, _aipl_depth_test_enabled);
  _aipl_rasterize_triangle_gouraud(fx1, fy1, fz1, fx3, fy3, fz3, fx4, fy4, fz4, r1, g1, b1, a1, r3, g3, b3, a3, r4, g4, b4, a4, _aipl_depth_test_enabled);
  return aipl_nil();
}

static void _aipl_rasterize_triangle_textured(
    int tex_id,
    float fx1, float fy1, float fz1, float u1, float v1,
    float fx2, float fy2, float fz2, float u2, float v2,
    float fx3, float fy3, float fz3, float u3, float v3,
    uint8_t r1, uint8_t g1, uint8_t b1, uint8_t a1,
    uint8_t r2, uint8_t g2, uint8_t b2, uint8_t a2,
    uint8_t r3, uint8_t g3, uint8_t b3, uint8_t a3,
    int use_depth) {
  if (a1 == 0 && a2 == 0 && a3 == 0) return;
  if (tex_id <= 0 || tex_id >= _aipl_images_cap || !_aipl_images || !_aipl_images[tex_id].active || !_aipl_images[tex_id].pixels || _aipl_images[tex_id].w <= 0 || _aipl_images[tex_id].h <= 0) {
    _aipl_rasterize_triangle_gouraud(fx1, fy1, fz1, fx2, fy2, fz2, fx3, fy3, fz3, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, use_depth);
    return;
  }
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    _aipl_gl_push_tri_textured_3d(tex_id, fx1, fy1, fz1, u1, v1, fx2, fy2, fz2, u2, v2, fx3, fy3, fz3, u3, v3, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3);
    return;
  }
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb) return;
  if (use_depth && (!_aipl_zbuffer || _aipl_zbuffer_cap < (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h)) {
    _aipl_ensure_zbuffer(_aipl_canvas_w, _aipl_canvas_h);
  }
  float denom = (fy2 - fy3) * (fx1 - fx3) + (fx3 - fx2) * (fy1 - fy3);
  if (fabsf(denom) < 1e-5f) return;
  float inv_denom = 1.0f / denom;
  int min_x = (int)floorf(fminf(fx1, fminf(fx2, fx3)));
  int max_x = (int)ceilf(fmaxf(fx1, fmaxf(fx2, fx3)));
  int min_y = (int)floorf(fminf(fy1, fminf(fy2, fy3)));
  int max_y = (int)ceilf(fmaxf(fy1, fmaxf(fy2, fy3)));
  int clip_x0 = 0, clip_y0 = 0, clip_x1 = _aipl_canvas_w, clip_y1 = _aipl_canvas_h;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_x0) clip_x0 = _aipl_scissor_x;
    if (_aipl_scissor_y > clip_y0) clip_y0 = _aipl_scissor_y;
    if (_aipl_scissor_x + _aipl_scissor_w < clip_x1) clip_x1 = _aipl_scissor_x + _aipl_scissor_w;
    if (_aipl_scissor_y + _aipl_scissor_h < clip_y1) clip_y1 = _aipl_scissor_y + _aipl_scissor_h;
  }
  if (min_x < clip_x0) min_x = clip_x0;
  if (max_x >= clip_x1) max_x = clip_x1 - 1;
  if (min_y < clip_y0) min_y = clip_y0;
  if (max_y >= clip_y1) max_y = clip_y1 - 1;
  if (min_x > max_x || min_y > max_y) return;

  const uint8_t* tex_px = _aipl_images[tex_id].pixels;
  int tw = _aipl_images[tex_id].w;
  int th = _aipl_images[tex_id].h;
  float ftw = (float)tw;
  float fth = (float)th;

  float dw1_dx = (fy2 - fy3) * inv_denom;
  float dw2_dx = (fy3 - fy1) * inv_denom;
  float fr1 = (float)r1, fg1 = (float)g1, fb1 = (float)b1, fa1 = (float)a1;
  float fr2 = (float)r2, fg2 = (float)g2, fb2 = (float)b2, fa2 = (float)a2;
  float fr3 = (float)r3, fg3 = (float)g3, fb3 = (float)b3, fa3 = (float)a3;
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  int cw = _aipl_canvas_w;

  for (int py = min_y; py <= max_y; py++) {
    float cy = (float)py + 0.5f;
    float cx0 = (float)min_x + 0.5f;
    float w1 = ((fy2 - fy3) * (cx0 - fx3) + (fx3 - fx2) * (cy - fy3)) * inv_denom;
    float w2 = ((fy3 - fy1) * (cx0 - fx3) + (fx1 - fx3) * (cy - fy3)) * inv_denom;
    size_t row_off = (size_t)py * (size_t)cw;
    uint32_t* prow = fb32 + row_off;
    float* zrow = (use_depth && _aipl_canvas_zb) ? (_aipl_canvas_zb + row_off) : NULL;
    for (int px = min_x; px <= max_x; px++) {
      float w3 = 1.0f - w1 - w2;
      if (w1 >= -1e-4f && w2 >= -1e-4f && w3 >= -1e-4f) {
        float cw1 = w1 < 0.0f ? 0.0f : (w1 > 1.0f ? 1.0f : w1);
        float cw2 = w2 < 0.0f ? 0.0f : (w2 > 1.0f ? 1.0f : w2);
        float cw3 = w3 < 0.0f ? 0.0f : (w3 > 1.0f ? 1.0f : w3);
        float pz = cw1 * fz1 + cw2 * fz2 + cw3 * fz3;
        if (!zrow || pz <= zrow[px]) {
          float u = cw1 * u1 + cw2 * u2 + cw3 * u3;
          float v = cw1 * v1 + cw2 * v2 + cw3 * v3;
          float wu = u - floorf(u);
          float wv = v - floorf(v);
          int tx = (int)(wu * ftw);
          int ty = (int)(wv * fth);
          if (tx < 0) tx = 0; else if (tx >= tw) tx = tw - 1;
          if (ty < 0) ty = 0; else if (ty >= th) ty = th - 1;
          const uint8_t* tp = tex_px + ((size_t)ty * (size_t)tw + (size_t)tx) * 4;
          int vr = (int)(cw1 * fr1 + cw2 * fr2 + cw3 * fr3 + 0.5f);
          int vg = (int)(cw1 * fg1 + cw2 * fg2 + cw3 * fg3 + 0.5f);
          int vb = (int)(cw1 * fb1 + cw2 * fb2 + cw3 * fb3 + 0.5f);
          int va = (int)(cw1 * fa1 + cw2 * fa2 + cw3 * fa3 + 0.5f);
          if (vr < 0) vr = 0; else if (vr > 255) vr = 255;
          if (vg < 0) vg = 0; else if (vg > 255) vg = 255;
          if (vb < 0) vb = 0; else if (vb > 255) vb = 255;
          if (va < 0) va = 0; else if (va > 255) va = 255;
          int pa = ((int)tp[3] * va) / 255;
          if (pa > 12) {
            if (zrow && _aipl_cur_blend_mode == 0) zrow[px] = pz;
            int pr = ((int)tp[0] * vr) / 255;
            int pg = ((int)tp[1] * vg) / 255;
            int pb = ((int)tp[2] * vb) / 255;
            prow[px] = _aipl_blend_pixel(prow[px], (uint32_t)pr, (uint32_t)pg, (uint32_t)pb, (uint32_t)pa);
          }
        }
      }
      w1 += dw1_dx;
      w2 += dw2_dx;
    }
  }
}

AiplVal aipl_rt_drawTriangle3DTextured(
    AiplVal texId_v,
    AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal u1_v, AiplVal v1_v,
    AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal u2_v, AiplVal v2_v,
    AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal u3_v, AiplVal v3_v,
    AiplVal c1_v, AiplVal c2_v, AiplVal c3_v) {
  int tex_id = (int)aipl_to_c_double(texId_v);
  float fx1 = (float)aipl_to_c_double(x1_v), fy1 = (float)aipl_to_c_double(y1_v), fz1 = (float)aipl_to_c_double(z1_v);
  float fu1 = (float)aipl_to_c_double(u1_v), fv1 = (float)aipl_to_c_double(v1_v);
  float fx2 = (float)aipl_to_c_double(x2_v), fy2 = (float)aipl_to_c_double(y2_v), fz2 = (float)aipl_to_c_double(z2_v);
  float fu2 = (float)aipl_to_c_double(u2_v), fv2 = (float)aipl_to_c_double(v2_v);
  float fx3 = (float)aipl_to_c_double(x3_v), fy3 = (float)aipl_to_c_double(y3_v), fz3 = (float)aipl_to_c_double(z3_v);
  float fu3 = (float)aipl_to_c_double(u3_v), fv3 = (float)aipl_to_c_double(v3_v);
  uint8_t r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3;
  aipl_unpack_color(c1_v, &r1, &g1, &b1, &a1);
  aipl_unpack_color(c2_v, &r2, &g2, &b2, &a2);
  aipl_unpack_color(c3_v, &r3, &g3, &b3, &a3);
  _aipl_rasterize_triangle_textured(tex_id, fx1, fy1, fz1, fu1, fv1, fx2, fy2, fz2, fu2, fv2, fx3, fy3, fz3, fu3, fv3, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, _aipl_depth_test_enabled);
  return aipl_nil();
}

AiplVal aipl_rt_drawQuad3DTextured(
    AiplVal texId_v,
    AiplVal x1_v, AiplVal y1_v, AiplVal z1_v, AiplVal u1_v, AiplVal v1_v,
    AiplVal x2_v, AiplVal y2_v, AiplVal z2_v, AiplVal u2_v, AiplVal v2_v,
    AiplVal x3_v, AiplVal y3_v, AiplVal z3_v, AiplVal u3_v, AiplVal v3_v,
    AiplVal x4_v, AiplVal y4_v, AiplVal z4_v, AiplVal u4_v, AiplVal v4_v,
    AiplVal c1_v, AiplVal c2_v, AiplVal c3_v, AiplVal c4_v) {
  int tex_id = (int)aipl_to_c_double(texId_v);
  float fx1 = (float)aipl_to_c_double(x1_v), fy1 = (float)aipl_to_c_double(y1_v), fz1 = (float)aipl_to_c_double(z1_v);
  float fu1 = (float)aipl_to_c_double(u1_v), fv1 = (float)aipl_to_c_double(v1_v);
  float fx2 = (float)aipl_to_c_double(x2_v), fy2 = (float)aipl_to_c_double(y2_v), fz2 = (float)aipl_to_c_double(z2_v);
  float fu2 = (float)aipl_to_c_double(u2_v), fv2 = (float)aipl_to_c_double(v2_v);
  float fx3 = (float)aipl_to_c_double(x3_v), fy3 = (float)aipl_to_c_double(y3_v), fz3 = (float)aipl_to_c_double(z3_v);
  float fu3 = (float)aipl_to_c_double(u3_v), fv3 = (float)aipl_to_c_double(v3_v);
  float fx4 = (float)aipl_to_c_double(x4_v), fy4 = (float)aipl_to_c_double(y4_v), fz4 = (float)aipl_to_c_double(z4_v);
  float fu4 = (float)aipl_to_c_double(u4_v), fv4 = (float)aipl_to_c_double(v4_v);
  uint8_t r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, r4, g4, b4, a4;
  aipl_unpack_color(c1_v, &r1, &g1, &b1, &a1);
  aipl_unpack_color(c2_v, &r2, &g2, &b2, &a2);
  aipl_unpack_color(c3_v, &r3, &g3, &b3, &a3);
  aipl_unpack_color(c4_v, &r4, &g4, &b4, &a4);
  _aipl_rasterize_triangle_textured(tex_id, fx1, fy1, fz1, fu1, fv1, fx2, fy2, fz2, fu2, fv2, fx3, fy3, fz3, fu3, fv3, r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, _aipl_depth_test_enabled);
  _aipl_rasterize_triangle_textured(tex_id, fx1, fy1, fz1, fu1, fv1, fx3, fy3, fz3, fu3, fv3, fx4, fy4, fz4, fu4, fv4, r1, g1, b1, a1, r3, g3, b3, a3, r4, g4, b4, a4, _aipl_depth_test_enabled);
  return aipl_nil();
}

AiplVal _aipl_rt_begin3D_va(int argc, const AiplVal* args) {
  aipl_ensure_canvas_fb();
  _aipl_ensure_zbuffer(_aipl_canvas_w, _aipl_canvas_h);
  _aipl_in_3d_mode = 1;
  setenv("AIPL_3D_ACTIVE", "1", 1);
  setenv("AIPL_3D_TRI_COUNT", "0", 1);
  if (argc >= 1 && args[0].kind == AIPL_STRUCT && args[0].ptr) {
    AiplVal pos = aipl_member_get(args[0], "position");
    AiplVal tgt = aipl_member_get(args[0], "target");
    AiplVal upv = aipl_member_get(args[0], "up");
    AiplVal fov = aipl_member_get(args[0], "fovy");
    if (pos.kind == AIPL_STRUCT) {
      _aipl_cam3d_pos[0] = aipl_to_c_double(aipl_member_get(pos, "x"));
      _aipl_cam3d_pos[1] = aipl_to_c_double(aipl_member_get(pos, "y"));
      _aipl_cam3d_pos[2] = aipl_to_c_double(aipl_member_get(pos, "z"));
    }
    if (tgt.kind == AIPL_STRUCT) {
      _aipl_cam3d_target[0] = aipl_to_c_double(aipl_member_get(tgt, "x"));
      _aipl_cam3d_target[1] = aipl_to_c_double(aipl_member_get(tgt, "y"));
      _aipl_cam3d_target[2] = aipl_to_c_double(aipl_member_get(tgt, "z"));
    }
    if (upv.kind == AIPL_STRUCT) {
      _aipl_cam3d_up[0] = aipl_to_c_double(aipl_member_get(upv, "x"));
      _aipl_cam3d_up[1] = aipl_to_c_double(aipl_member_get(upv, "y"));
      _aipl_cam3d_up[2] = aipl_to_c_double(aipl_member_get(upv, "z"));
    }
    if (fov.kind == AIPL_FLOAT || fov.kind == AIPL_INT) {
      double fv = aipl_to_c_double(fov);
      if (fv > 1.0) _aipl_cam3d_fovy = fv;
    }
  } else if (argc >= 4) {
    double fv = aipl_to_c_double(args[0]);
    if (fv > 1.0) _aipl_cam3d_fovy = fv;
  }
  return aipl_nil();
}

AiplVal aipl_rt_end3D(void) {
  _aipl_in_3d_mode = 0;
  setenv("AIPL_3D_ACTIVE", "0", 1);
  return aipl_nil();
}

AiplVal aipl_rt_drawTriangleDepth(AiplVal x1_v, AiplVal y1_v, AiplVal x2_v, AiplVal y2_v, AiplVal x3_v, AiplVal y3_v, AiplVal depth_v, AiplVal c) {
  float fx1 = (float)aipl_to_c_double(x1_v);
  float fy1 = (float)aipl_to_c_double(y1_v);
  float fx2 = (float)aipl_to_c_double(x2_v);
  float fy2 = (float)aipl_to_c_double(y2_v);
  float fx3 = (float)aipl_to_c_double(x3_v);
  float fy3 = (float)aipl_to_c_double(y3_v);
  float z = (float)aipl_to_c_double(depth_v);
  uint8_t r, g, b, a;
  aipl_unpack_color(c, &r, &g, &b, &a);
  if (a == 0) return aipl_nil();
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    if (!_aipl_depth_test_enabled) {
      _aipl_gl_flush_batch();
      if (_aipl_glEnable) _aipl_glEnable(0x0B71 /* GL_DEPTH_TEST */);
      if (_aipl_glDepthFunc) _aipl_glDepthFunc(0x0203 /* GL_LEQUAL */);
      if (_aipl_glDepthMask) _aipl_glDepthMask(1);
      _aipl_depth_test_enabled = 1;
    }
    _aipl_gl_push_tri_z(fx1, fy1, z, fx2, fy2, z, fx3, fy3, z, r, g, b, a);
    return aipl_nil();
  }
  aipl_ensure_canvas_fb();
  if (!_aipl_zbuffer || _aipl_zbuffer_cap < (size_t)_aipl_canvas_w * (size_t)_aipl_canvas_h) {
    _aipl_ensure_zbuffer(_aipl_canvas_w, _aipl_canvas_h);
  }
  int min_y = (int)floorf(fminf(fy1, fminf(fy2, fy3)));
  int max_y = (int)ceilf(fmaxf(fy1, fmaxf(fy2, fy3)));
  int clip_x0 = 0, clip_y0 = 0, clip_x1 = _aipl_canvas_w, clip_y1 = _aipl_canvas_h;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_x0) clip_x0 = _aipl_scissor_x;
    if (_aipl_scissor_y > clip_y0) clip_y0 = _aipl_scissor_y;
    if (_aipl_scissor_x + _aipl_scissor_w < clip_x1) clip_x1 = _aipl_scissor_x + _aipl_scissor_w;
    if (_aipl_scissor_y + _aipl_scissor_h < clip_y1) clip_y1 = _aipl_scissor_y + _aipl_scissor_h;
  }
  if (min_y < clip_y0) min_y = clip_y0;
  if (max_y >= clip_y1) max_y = clip_y1 - 1;
  float area = (fy2 - fy3) * (fx1 - fx3) + (fx3 - fx2) * (fy1 - fy3);
  if (fabsf(area) < 1e-5f) return aipl_nil();
  float vx[3] = { fx1, fx2, fx3 };
  float vy[3] = { fy1, fy2, fy3 };
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  for (int py = min_y; py <= max_y; py++) {
    float cy = (float)py + 0.5f;
    float x_min_row = 1e30f;
    float x_max_row = -1e30f;
    int hits = 0;
    for (int e = 0; e < 3; e++) {
      int e2 = (e == 2) ? 0 : (e + 1);
      float ey0 = vy[e], ey1 = vy[e2];
      if ((ey0 <= cy && ey1 > cy) || (ey1 <= cy && ey0 > cy)) {
        float t = (cy - ey0) / (ey1 - ey0);
        float ix = vx[e] + t * (vx[e2] - vx[e]);
        if (ix < x_min_row) x_min_row = ix;
        if (ix > x_max_row) x_max_row = ix;
        hits++;
      }
    }
    if (hits >= 2) {
      int sx0 = (int)ceilf(x_min_row - 0.5f);
      int sx1 = (int)floorf(x_max_row - 0.5f);
      if (sx0 < clip_x0) sx0 = clip_x0;
      if (sx1 >= clip_x1) sx1 = clip_x1 - 1;
      if (sx0 <= sx1) {
        size_t row_off = (size_t)py * (size_t)_aipl_canvas_w;
        float* zrow = _aipl_zbuffer ? (_aipl_zbuffer + row_off) : NULL;
        uint32_t* prow = fb32 + row_off;
        for (int px = sx0; px <= sx1; px++) {
          if (!zrow || z <= zrow[px]) {
            if (zrow && _aipl_cur_blend_mode == 0) zrow[px] = z;
            prow[px] = _aipl_blend_pixel(prow[px], r, g, b, a);
          }
        }
      }
    }
  }
  return aipl_nil();
}

static void _aipl_project_point3d(double wx, double wy, double wz, double* sx, double* sy, double* sz) {
  double fx = _aipl_cam3d_target[0] - _aipl_cam3d_pos[0];
  double fy = _aipl_cam3d_target[1] - _aipl_cam3d_pos[1];
  double fz = _aipl_cam3d_target[2] - _aipl_cam3d_pos[2];
  double fl = sqrt(fx * fx + fy * fy + fz * fz);
  if (fl < 1e-6) { fx = 0.0; fy = 0.0; fz = 1.0; } else { fx /= fl; fy /= fl; fz /= fl; }
  double rx = fy * _aipl_cam3d_up[2] - fz * _aipl_cam3d_up[1];
  double ry = fz * _aipl_cam3d_up[0] - fx * _aipl_cam3d_up[2];
  double rz = fx * _aipl_cam3d_up[1] - fy * _aipl_cam3d_up[0];
  double rl = sqrt(rx * rx + ry * ry + rz * rz);
  if (rl < 1e-6) { rx = 1.0; ry = 0.0; rz = 0.0; } else { rx /= rl; ry /= rl; rz /= rl; }
  double ux = ry * fz - rz * fy;
  double uy = rz * fx - rx * fz;
  double uz = rx * fy - ry * fx;
  double dx = wx - _aipl_cam3d_pos[0];
  double dy = wy - _aipl_cam3d_pos[1];
  double dz = wz - _aipl_cam3d_pos[2];
  double vx = dx * rx + dy * ry + dz * rz;
  double vy = dx * ux + dy * uy + dz * uz;
  double vz = dx * fx + dy * fy + dz * fz;
  if (vz < 0.1) vz = 0.1;
  double aspect = (_aipl_canvas_h > 0) ? ((double)_aipl_canvas_w / (double)_aipl_canvas_h) : 1.3333;
  double fov_rad = _aipl_cam3d_fovy * 3.14159265358979323846 / 180.0;
  double f = 1.0 / tan(fov_rad * 0.5);
  double ndc_x = (vx * (f / aspect)) / vz;
  double ndc_y = (vy * f) / vz;
  *sx = (ndc_x + 1.0) * 0.5 * (double)_aipl_canvas_w;
  *sy = (1.0 - ndc_y) * 0.5 * (double)_aipl_canvas_h;
  *sz = vz;
}

AiplVal _aipl_rt_drawCubeMesh_va(int argc, const AiplVal* args) {
  if (argc < 4) return aipl_nil();
  double cx = aipl_to_c_double(args[0]);
  double cy = aipl_to_c_double(args[1]);
  double cz = (argc == 8) ? 0.0 : aipl_to_c_double(args[2]);
  double hs = aipl_to_c_double((argc == 8) ? args[2] : args[3]) * 0.5;
  AiplVal col_v = (argc == 8) ? args[6] : ((argc >= 7) ? args[6] : args[4]);
  if (hs <= 0.0) hs = 0.5;
  static const double offs[8][3] = {
    {-1,-1,-1}, { 1,-1,-1}, { 1, 1,-1}, {-1, 1,-1},
    {-1,-1, 1}, { 1,-1, 1}, { 1, 1, 1}, {-1, 1, 1}
  };
  static const int tris[12][3] = {
    {0,1,2}, {0,2,3}, {4,6,5}, {4,7,6},
    {4,5,1}, {4,1,0}, {3,2,6}, {3,6,7},
    {1,5,6}, {1,6,2}, {4,0,3}, {4,3,7}
  };
  double px[8], py[8], pz[8];
  for (int i = 0; i < 8; i++) {
    _aipl_project_point3d(cx + offs[i][0] * hs, cy + offs[i][1] * hs, cz + offs[i][2] * hs, &px[i], &py[i], &pz[i]);
  }
  for (int t = 0; t < 12; t++) {
    int i0 = tris[t][0], i1 = tris[t][1], i2 = tris[t][2];
    double avg_z = (pz[i0] + pz[i1] + pz[i2]) / 3.0;
    aipl_rt_drawTriangleDepth(aipl_float(px[i0]), aipl_float(py[i0]), aipl_float(px[i1]), aipl_float(py[i1]), aipl_float(px[i2]), aipl_float(py[i2]), aipl_float(avg_z), col_v);
  }
  return aipl_nil();
}

AiplVal aipl_rt_isKeyPressed(AiplVal k) {
  int slot = _aipl_key_val_to_slot(k);
  return aipl_bool(slot >= 0 && slot < 512 && _aipl_key_pressed[slot] != 0);
}

AiplVal aipl_rt_isKeyDown(AiplVal k) {
  int slot = _aipl_key_val_to_slot(k);
  return aipl_bool(slot >= 0 && slot < 512 && _aipl_key_down[slot] != 0);
}

AiplVal aipl_rt_isKeyHeld(AiplVal k) { return aipl_rt_isKeyDown(k); }

AiplVal aipl_rt_isKeyReleased(AiplVal k) {
  int slot = _aipl_key_val_to_slot(k);
  return aipl_bool(slot >= 0 && slot < 512 && _aipl_key_released[slot] != 0);
}

AiplVal aipl_rt_getKeyPressed(void) { return aipl_int(_aipl_last_key_pressed); }

AiplVal aipl_rt_isMouseButtonPressed(AiplVal b) {
  int btn = (int)((b.kind == AIPL_FLOAT) ? b.f : b.i);
  return aipl_bool(btn >= 0 && btn < 8 && _aipl_mouse_pressed[btn] != 0);
}

AiplVal aipl_rt_isMouseButtonDown(AiplVal b) {
  int btn = (int)((b.kind == AIPL_FLOAT) ? b.f : b.i);
  return aipl_bool(btn >= 0 && btn < 8 && _aipl_mouse_down[btn] != 0);
}

AiplVal aipl_rt_isMouseButtonReleased(AiplVal b) {
  int btn = (int)((b.kind == AIPL_FLOAT) ? b.f : b.i);
  return aipl_bool(btn >= 0 && btn < 8 && _aipl_mouse_released[btn] != 0);
}

AiplVal aipl_rt_isMouseRightClicked(void) { return aipl_bool(_aipl_mouse_pressed[1] != 0); }

AiplVal aipl_rt_isMouseDoubleClicked(void) { return aipl_bool(false); }

AiplVal aipl_rt_getMouseX(void) { return aipl_float((double)_aipl_mouse_x); }

AiplVal aipl_rt_getMouseY(void) { return aipl_float((double)_aipl_mouse_y); }

AiplVal aipl_rt_getMouseWheelMove(void) { return aipl_float(_aipl_mouse_wheel); }

AiplVal aipl_rt_mouseWheelX(void) { return aipl_float(0.0); }

AiplVal aipl_rt_isMouseInRect(AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v) {
  double x = (x_v.kind == AIPL_FLOAT) ? x_v.f : (double)x_v.i;
  double y = (y_v.kind == AIPL_FLOAT) ? y_v.f : (double)y_v.i;
  double w = (w_v.kind == AIPL_FLOAT) ? w_v.f : (double)w_v.i;
  double h = (h_v.kind == AIPL_FLOAT) ? h_v.f : (double)h_v.i;
  double mx = (double)_aipl_mouse_x;
  double my = (double)_aipl_mouse_y;
  return aipl_bool(mx >= x && mx <= x + w && my >= y && my <= y + h);
}

FILE* _aipl_video_pipe = NULL;
int _aipl_video_fps = 60;
int _aipl_video_w = 0;
int _aipl_video_h = 0;
AiplVal aipl_rt_stopVideoRecording(void) {
  if (_aipl_video_recording && _aipl_video_pipe) {
    pclose(_aipl_video_pipe);
    _aipl_video_pipe = NULL;
    _aipl_video_recording = 0;
    return aipl_bool(true);
  }
  _aipl_video_recording = 0;
  return aipl_bool(false);
}

AiplVal aipl_rt_startVideoRecording(AiplVal path, AiplVal fps) {
  if (_aipl_video_recording) {
    aipl_rt_stopVideoRecording();
  }
  const char* out_path = (path.kind == AIPL_STR && path.s && path.s[0]) ? path.s : "output.mp4";
  int rate = (int)((fps.kind == AIPL_FLOAT) ? fps.f : fps.i);
  if (rate <= 0) rate = (_aipl_target_fps > 0) ? _aipl_target_fps : 60;
  _aipl_video_fps = rate;
  aipl_ensure_canvas_fb();
  _aipl_video_w = _aipl_canvas_w;
  _aipl_video_h = _aipl_canvas_h;
  if (_aipl_video_w <= 0 || _aipl_video_h <= 0 || !_aipl_canvas_fb) {
    return aipl_bool(false);
  }
  char cmd[1024];
  snprintf(cmd, sizeof(cmd), "ffmpeg -y -f rawvideo -vcodec rawvideo -pix_fmt bgra -s %dx%d -r %d -i - -c:v libx264 -pix_fmt yuv420p \"%s\" >/dev/null 2>&1",
           _aipl_video_w, _aipl_video_h, _aipl_video_fps, out_path);
  _aipl_video_pipe = popen(cmd, "w");
  if (_aipl_video_pipe) {
    _aipl_video_recording = 1;
    return aipl_bool(true);
  }
  return aipl_bool(false);
}

AiplVal aipl_rt_recordVideoFrame(void) {
  if (_aipl_video_recording && _aipl_video_pipe && _aipl_canvas_fb) {
    _aipl_sync_gl_to_fb();
    fwrite(_aipl_canvas_fb, 4, (size_t)_aipl_video_w * (size_t)_aipl_video_h, _aipl_video_pipe);
    fflush(_aipl_video_pipe);
  }
  return aipl_nil();
}

AiplVal aipl_rt_isRecordingVideo(void) {
  return aipl_bool(_aipl_video_recording != 0);
}

AiplVal aipl_rt_saveScreenshot(AiplVal path) {
  const char* shot_path = (path.kind == AIPL_STR && path.s && path.s[0]) ? path.s : "screenshot.png";
  if (_aipl_window_backend == 2) {
    _aipl_sync_gl_to_fb();
  }
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb || _aipl_canvas_w <= 0 || _aipl_canvas_h <= 0) return aipl_bool(false);
  const char* cli_shot = _aipl_get_cli_screenshot_path();
  int matches_cli = (cli_shot && cli_shot[0] && strcmp(cli_shot, shot_path) == 0);
  size_t plen = strlen(shot_path);
  if (plen >= 4 && strcasecmp(shot_path + plen - 4, ".ppm") == 0) {
    int ok = _aipl_save_fb_to_ppm(shot_path) != 0;
    if (ok && matches_cli && !_aipl_has_screenshot_on_exit_flag()) _aipl_shot_taken = 1;
    return aipl_bool(ok);
  }
  static int scr_seq = 0;
  char tmp_ppm[256];
  snprintf(tmp_ppm, sizeof(tmp_ppm), "/tmp/_aipl_scr_%d_%d_%ld.ppm", (int)getpid(), ++scr_seq, (long)time(NULL));
  if (!_aipl_save_fb_to_ppm(tmp_ppm)) return aipl_bool(false);
  char scmd[1024];
  snprintf(scmd, sizeof(scmd), "python3 -c \"import os; from PIL import Image; os.makedirs(os.path.dirname('%s') or '.', exist_ok=True); Image.open('%s').save('%s')\" 2>/dev/null || ffmpeg -y -i '%s' '%s' 2>/dev/null || convert '%s' '%s' 2>/dev/null", shot_path, tmp_ppm, shot_path, tmp_ppm, shot_path, tmp_ppm, shot_path);
  int sret = system(scmd);
  remove(tmp_ppm);
  if (sret == 0 && matches_cli && !_aipl_has_screenshot_on_exit_flag()) {
    _aipl_shot_taken = 1;
  }
  return aipl_bool(sret == 0);
}

_AiplImageSlot* _aipl_images = NULL;
int _aipl_images_cap = 0;
void _aipl_ensure_image_slot(int slot) {
  if (slot < 0) return;
  if (slot >= _aipl_images_cap) {
    int new_cap = (_aipl_images_cap == 0) ? 256 : _aipl_images_cap * 2;
    while (new_cap <= slot) new_cap *= 2;
    _AiplImageSlot* ni = (_AiplImageSlot*)realloc(_aipl_images, (size_t)new_cap * sizeof(_AiplImageSlot));
    char (*np)[512] = (char (*)[512])realloc(_aipl_image_paths, (size_t)new_cap * 512);
    if (ni) _aipl_images = ni;
    if (np) _aipl_image_paths = np;
    if (!ni || !np) return;
    memset(ni + _aipl_images_cap, 0, (size_t)(new_cap - _aipl_images_cap) * sizeof(_AiplImageSlot));
    memset(np + _aipl_images_cap, 0, (size_t)(new_cap - _aipl_images_cap) * 512);
    _aipl_images_cap = new_cap;
  }
}

#define _AIPL_MAX_IMAGE_SLOTS 512
static int _aipl_img_evict_cursor = 64;

int _aipl_alloc_image_slot(int w, int h) {
  if (_aipl_images_cap == 0) _aipl_ensure_image_slot(64);
  for (int i = 1; i < _aipl_images_cap; i++) {
    if (!_aipl_images[i].active) {
      _aipl_images[i].active = 1;
      _aipl_images[i].w = w;
      _aipl_images[i].h = h;
      _aipl_images[i].pixels = (uint8_t*)calloc((size_t)w * (size_t)h * 4, 1);
      _aipl_images[i].gl_tex_id = 0;
      _aipl_images[i].gl_dirty = 1;
      if (_aipl_image_paths) _aipl_image_paths[i][0] = 0;
      return i;
    }
  }
  int slot = (_aipl_images_cap > 0) ? _aipl_images_cap : 1;
  if (slot >= _AIPL_MAX_IMAGE_SLOTS) {
    int evict = _aipl_img_evict_cursor;
    if (evict < 64 || evict >= _aipl_images_cap) evict = 64;
    _aipl_img_evict_cursor = (evict + 1 >= _aipl_images_cap) ? 64 : (evict + 1);
    _aipl_free_image_slot(evict);
    _aipl_images[evict].active = 1;
    _aipl_images[evict].w = w;
    _aipl_images[evict].h = h;
    _aipl_images[evict].pixels = (uint8_t*)calloc((size_t)w * (size_t)h * 4, 1);
    _aipl_images[evict].gl_tex_id = 0;
    _aipl_images[evict].gl_dirty = 1;
    if (_aipl_image_paths) _aipl_image_paths[evict][0] = 0;
    return evict;
  }
  _aipl_ensure_image_slot(slot);
  if (slot < _aipl_images_cap) {
    _aipl_images[slot].active = 1;
    _aipl_images[slot].w = w;
    _aipl_images[slot].h = h;
    _aipl_images[slot].pixels = (uint8_t*)calloc((size_t)w * (size_t)h * 4, 1);
    _aipl_images[slot].gl_tex_id = 0;
    _aipl_images[slot].gl_dirty = 1;
    if (_aipl_image_paths) _aipl_image_paths[slot][0] = 0;
    return slot;
  }
  return -1;
}

void _aipl_free_image_slot(int id) {
  if (id > 0 && id < _aipl_images_cap && _aipl_images && _aipl_images[id].active) {
    if (_aipl_gl_cur_tex_id == id) {
      _aipl_gl_flush_batch();
      _aipl_gl_cur_tex_id = 0;
    }
#ifndef _WIN32
    if (_aipl_images[id].gl_tex_id != 0 && _aipl_window_backend == 2 && _aipl_glx_ctx && _aipl_glDeleteTextures) {
      _aipl_glDeleteTextures(1, &_aipl_images[id].gl_tex_id);
    }
#endif
    if (_aipl_images[id].pixels) free(_aipl_images[id].pixels);
    _aipl_images[id].pixels = NULL;
    _aipl_images[id].active = 0;
    _aipl_images[id].w = 0;
    _aipl_images[id].h = 0;
    _aipl_images[id].gl_tex_id = 0;
    _aipl_images[id].gl_dirty = 0;
    if (_aipl_image_paths) _aipl_image_paths[id][0] = 0;
  }
}

static inline uint32_t _aipl_tex_hash2d(int x, int y, int period_x, int period_y, uint32_t seed) {
  int wx = ((x % period_x) + period_x) % period_x;
  int wy = ((y % period_y) + period_y) % period_y;
  uint32_t h = (uint32_t)wx * 374761393u + (uint32_t)wy * 668265263u + seed * 1442695041u;
  h = (h ^ (h >> 13)) * 1274126177u;
  return h ^ (h >> 16);
}

static inline float _aipl_tex_val_noise_periodic(float x, float y, int period_x, int period_y, uint32_t seed) {
  int ix = (int)floorf(x);
  int iy = (int)floorf(y);
  float fx = x - (float)ix;
  float fy = y - (float)iy;
  float ux = fx * fx * (3.0f - 2.0f * fx);
  float uy = fy * fy * (3.0f - 2.0f * fy);
  float v00 = (float)(_aipl_tex_hash2d(ix,     iy,     period_x, period_y, seed) & 0xFFFFu) / 65535.0f;
  float v10 = (float)(_aipl_tex_hash2d(ix + 1, iy,     period_x, period_y, seed) & 0xFFFFu) / 65535.0f;
  float v01 = (float)(_aipl_tex_hash2d(ix,     iy + 1, period_x, period_y, seed) & 0xFFFFu) / 65535.0f;
  float v11 = (float)(_aipl_tex_hash2d(ix + 1, iy + 1, period_x, period_y, seed) & 0xFFFFu) / 65535.0f;
  float nx0 = v00 + (v10 - v00) * ux;
  float nx1 = v01 + (v11 - v01) * ux;
  return nx0 + (nx1 - nx0) * uy;
}

static float _aipl_tex_fbm_periodic(float u, float v, int base_freq, int octaves, uint32_t seed) {
  float sum = 0.0f;
  float amp = 0.5f;
  float norm = 0.0f;
  int freq = (base_freq < 2) ? 2 : base_freq;
  for (int o = 0; o < octaves; o++) {
    sum += amp * _aipl_tex_val_noise_periodic(u * (float)freq, v * (float)freq, freq, freq, seed + (uint32_t)o * 997u);
    norm += amp;
    amp *= 0.5f;
    freq *= 2;
  }
  return (norm > 0.0f) ? (sum / norm) : 0.5f;
}

static float _aipl_tex_voronoi_periodic(float u, float v, int cells, uint32_t seed, uint32_t* out_cell_id) {
  float gx = u * (float)cells;
  float gy = v * (float)cells;
  int ix = (int)floorf(gx);
  int iy = (int)floorf(gy);
  float min_d1 = 1e9f;
  float min_d2 = 1e9f;
  uint32_t best_id = 0;
  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      uint32_t h = _aipl_tex_hash2d(ix + dx, iy + dy, cells, cells, seed);
      float jx = (float)(h & 0xFFu) / 255.0f;
      float jy = (float)((h >> 8) & 0xFFu) / 255.0f;
      float px = (float)(ix + dx) + 0.15f + 0.70f * jx - gx;
      float py = (float)(iy + dy) + 0.15f + 0.70f * jy - gy;
      float d = sqrtf(px * px + py * py);
      if (d < min_d1) {
        min_d2 = min_d1;
        min_d1 = d;
        best_id = h;
      } else if (d < min_d2) {
        min_d2 = d;
      }
    }
  }
  if (out_cell_id) *out_cell_id = best_id;
  return min_d2 - min_d1;
}

AiplVal aipl_rt_createTextureFromRgba(AiplVal w_v, AiplVal h_v, AiplVal px_v) {
  int w = (int)aipl_to_c_double(w_v);
  int h = (int)aipl_to_c_double(h_v);
  if (w <= 0) w = 16;
  if (h <= 0) h = 16;
  if (w > 2048) w = 2048;
  if (h > 2048) h = 2048;
  int slot = _aipl_alloc_image_slot(w, h);
  if (slot < 0) return aipl_int(0);
  uint8_t* dst = _aipl_images[slot].pixels;
  size_t total_px = (size_t)w * (size_t)h;
  if (px_v.kind == AIPL_ARRAY && px_v.ptr) {
    AiplArray* arr = (AiplArray*)px_v.ptr;
    size_t len = (size_t)arr->len;
    int is_unpacked_channels = (len >= total_px * 4);
    if (is_unpacked_channels) {
      for (size_t k = 0; k < 4 && k < len; k++) {
        int64_t val = (int64_t)aipl_to_c_double(arr->data[k]);
        if (val < 0 || val > 255) {
          is_unpacked_channels = 0;
          break;
        }
      }
    }
    if (is_unpacked_channels) {
      for (size_t i = 0; i < total_px; i++) {
        int r = (int)aipl_to_c_double(arr->data[i * 4]);
        int g = (int)aipl_to_c_double(arr->data[i * 4 + 1]);
        int b = (int)aipl_to_c_double(arr->data[i * 4 + 2]);
        int a = (int)aipl_to_c_double(arr->data[i * 4 + 3]);
        dst[i * 4]     = (uint8_t)(r < 0 ? 0 : (r > 255 ? 255 : r));
        dst[i * 4 + 1] = (uint8_t)(g < 0 ? 0 : (g > 255 ? 255 : g));
        dst[i * 4 + 2] = (uint8_t)(b < 0 ? 0 : (b > 255 ? 255 : b));
        dst[i * 4 + 3] = (uint8_t)(a < 0 ? 0 : (a > 255 ? 255 : a));
      }
    } else if (len > 0) {
      for (size_t i = 0; i < total_px; i++) {
        uint32_t packed = (uint32_t)((int64_t)aipl_to_c_double(arr->data[i % len]));
        uint8_t a = (uint8_t)((packed >> 24) & 0xFFu);
        uint8_t r = (uint8_t)((packed >> 16) & 0xFFu);
        uint8_t g = (uint8_t)((packed >> 8) & 0xFFu);
        uint8_t b = (uint8_t)(packed & 0xFFu);
        if (a == 0 && packed != 0) a = 255u;
        dst[i * 4]     = r;
        dst[i * 4 + 1] = g;
        dst[i * 4 + 2] = b;
        dst[i * 4 + 3] = a;
      }
    }
  }
  _aipl_images[slot].gl_dirty = 1;
  return aipl_int(slot);
}

AiplVal aipl_rt_createProceduralTexture(AiplVal kind_v, AiplVal w_v, AiplVal h_v, AiplVal seed_v) {
  const char* kind = (kind_v.kind == AIPL_STR && kind_v.s) ? kind_v.s : "grass";
  int w = (int)aipl_to_c_double(w_v);
  int h = (int)aipl_to_c_double(h_v);
  uint32_t seed = (uint32_t)((int64_t)aipl_to_c_double(seed_v));
  if (w < 4) w = 4; else if (w > 1024) w = 1024;
  if (h < 4) h = 4; else if (h > 1024) h = 1024;
  char proc_key[512];
  snprintf(proc_key, sizeof(proc_key), "__proc__:%s:%dx%d:%u", kind, w, h, seed);
  if (_aipl_images && _aipl_image_paths) {
    for (int i = 1; i < _aipl_images_cap; i++) {
      if (_aipl_images[i].active && _aipl_images[i].w == w && _aipl_images[i].h == h && _aipl_image_paths[i][0] && strcmp(_aipl_image_paths[i], proc_key) == 0) {
        return aipl_int(i);
      }
    }
  }
  int slot = _aipl_alloc_image_slot(w, h);
  if (slot < 0) return aipl_int(0);
  if (_aipl_image_paths) {
    strncpy(_aipl_image_paths[slot], proc_key, 511);
    _aipl_image_paths[slot][511] = 0;
  }
  uint8_t* dst = _aipl_images[slot].pixels;
  float* hmap = (float*)calloc((size_t)w * (size_t)h, sizeof(float));
  if (!hmap) return aipl_int(slot);

  int mat = 0; /* 0:grass, 1:rock, 2:cliff, 3:dirt, 4:cobble, 5:water, 6:wood, 7:bark, 8:foliage, 9:brick, 10:roof, 11:sand, 12:snow, 13:light_cookie, 14:mist, 15:palisade */
  if (strcasecmp(kind, "rock") == 0 || strcasecmp(kind, "stone") == 0) mat = 1;
  else if (strcasecmp(kind, "cliff") == 0 || strcasecmp(kind, "slate") == 0) mat = 2;
  else if (strcasecmp(kind, "dirt") == 0 || strcasecmp(kind, "soil") == 0 || strcasecmp(kind, "earth") == 0 || strcasecmp(kind, "mud") == 0 || strcasecmp(kind, "mud_track") == 0) mat = 3;
  else if (strcasecmp(kind, "cobble") == 0 || strcasecmp(kind, "cobblestone") == 0 || strcasecmp(kind, "road") == 0) mat = 4;
  else if (strcasecmp(kind, "water") == 0 || strcasecmp(kind, "river") == 0) mat = 5;
  else if (strcasecmp(kind, "wood") == 0 || strcasecmp(kind, "plank") == 0) mat = 6;
  else if (strcasecmp(kind, "bark") == 0 || strcasecmp(kind, "trunk") == 0) mat = 7;
  else if (strcasecmp(kind, "foliage") == 0 || strcasecmp(kind, "leaves") == 0 || strcasecmp(kind, "pine") == 0) mat = 8;
  else if (strcasecmp(kind, "brick") == 0 || strcasecmp(kind, "wall") == 0 || strcasecmp(kind, "masonry") == 0) mat = 9;
  else if (strcasecmp(kind, "roof") == 0 || strcasecmp(kind, "shingle") == 0 || strcasecmp(kind, "tile") == 0) mat = 10;
  else if (strcasecmp(kind, "sand") == 0 || strcasecmp(kind, "beach") == 0) mat = 11;
  else if (strcasecmp(kind, "snow") == 0 || strcasecmp(kind, "ice") == 0) mat = 12;
  else if (strcasecmp(kind, "light_cookie") == 0 || strcasecmp(kind, "radial_light") == 0) mat = 13;
  else if (strcasecmp(kind, "mist") == 0 || strcasecmp(kind, "fog") == 0) mat = 14;
  else if (strcasecmp(kind, "palisade") == 0 || strcasecmp(kind, "spiked_log") == 0) mat = 15;

  if (mat == 13 || mat == 14 || mat == 15) {
    for (int y = 0; y < h; y++) {
      float v = ((float)y + 0.5f) / (float)h;
      for (int x = 0; x < w; x++) {
        float u = ((float)x + 0.5f) / (float)w;
        size_t idx = ((size_t)y * (size_t)w + (size_t)x) * 4;
        if (mat == 13) { /* light_cookie / radial_light */
          float dx = u * 2.0f - 1.0f;
          float dy = v * 2.0f - 1.0f;
          float r2 = dx * dx + dy * dy;
          float base_i = (r2 < 1.0f) ? powf(1.0f - r2, 2.2f) : 0.0f;
          float n = 0.90f + 0.14f * _aipl_tex_fbm_periodic(u, v, 4, 3, seed + 177u);
          float lum = fminf(1.0f, fmaxf(0.0f, base_i * n));
          int ia = (int)(255.0f * lum + 0.5f);
          if (ia <= 3) {
            dst[idx] = 0; dst[idx + 1] = 0; dst[idx + 2] = 0; dst[idx + 3] = 0;
          } else {
            int ir = (int)(255.0f * fminf(1.0f, lum * 1.06f) + 0.5f);
            int ig = (int)(242.0f * lum + 0.5f);
            int ib = (int)(212.0f * powf(lum, 1.15f) + 0.5f);
            if (ir < 4) ir = 4; else if (ir > 255) ir = 255;
            if (ig < 4) ig = 4; else if (ig > 255) ig = 255;
            if (ib < 4) ib = 4; else if (ib > 255) ib = 255;
            dst[idx] = (uint8_t)ir;
            dst[idx + 1] = (uint8_t)ig;
            dst[idx + 2] = (uint8_t)ib;
            dst[idx + 3] = (uint8_t)(ia > 255 ? 255 : ia);
          }
        } else if (mat == 14) { /* mist / fog */
          float fbm1 = _aipl_tex_fbm_periodic(u, v, 4, 4, seed + 41u);
          float fbm2 = _aipl_tex_fbm_periodic(u, v, 8, 3, seed + 193u);
          float cloud = fminf(1.0f, fmaxf(0.0f, (0.60f * fbm1 + 0.40f * fbm2 - 0.16f) * 1.35f));
          float dx = u * 2.0f - 1.0f;
          float dy = v * 2.0f - 1.0f;
          float rad = fmaxf(0.0f, 1.0f - (dx * dx + dy * dy) * 0.72f);
          int ir = (int)(168.0f + 54.0f * cloud + 0.5f);
          int ig = (int)(184.0f + 52.0f * cloud + 0.5f);
          int ib = (int)(206.0f + 46.0f * cloud + 0.5f);
          int ia = (int)(180.0f * cloud * (0.30f + 0.70f * rad) + 0.5f);
          if (ia < 0) ia = 0; else if (ia > 180) ia = 180;
          dst[idx] = (uint8_t)(ir > 255 ? 255 : ir);
          dst[idx + 1] = (uint8_t)(ig > 255 ? 255 : ig);
          dst[idx + 2] = (uint8_t)(ib > 255 ? 255 : ib);
          dst[idx + 3] = (uint8_t)ia;
        } else { /* palisade / spiked_log */
          float log_u = u * 4.0f;
          int log_id = (int)floorf(log_u);
          float lu = log_u - (float)log_id;
          float tip_h = 0.22f + 0.03f * ((log_id & 1) ? 1.0f : -0.6f);
          float half_w = (v < tip_h) ? ((v / tip_h) * 0.46f) : 0.46f;
          float dc = fabsf(lu - 0.5f);
          if (v < 0.02f || dc > half_w) {
            dst[idx] = 0; dst[idx + 1] = 0; dst[idx + 2] = 0; dst[idx + 3] = 0;
          } else {
            float nx = (lu - 0.5f) / fmaxf(half_w, 0.05f);
            float nz = sqrtf(fmaxf(0.05f, 1.0f - nx * nx));
            float lit = 0.52f + 0.48f * fmaxf(0.0f, nx * (-0.55f) + nz * 0.83f);
            float grain = _aipl_tex_fbm_periodic(u * 6.0f, v * 2.0f, 6, 4, seed + 307u);
            float r, g, b;
            if ((v > 0.28f && v < 0.34f) || (v > 0.76f && v < 0.82f)) {
              r = 148.0f + 32.0f * grain;
              g = 122.0f + 28.0f * grain;
              b = 82.0f + 20.0f * grain;
            } else if (v < tip_h) {
              r = 146.0f + 38.0f * grain;
              g = 108.0f + 30.0f * grain;
              b = 68.0f + 22.0f * grain;
            } else {
              r = 76.0f + 36.0f * grain;
              g = 54.0f + 26.0f * grain;
              b = 36.0f + 18.0f * grain;
            }
            int ir = (int)(r * lit + 0.5f);
            int ig = (int)(g * lit + 0.5f);
            int ib = (int)(b * lit + 0.5f);
            if (ir < 8) ir = 8; else if (ir > 255) ir = 255;
            if (ig < 8) ig = 8; else if (ig > 255) ig = 255;
            if (ib < 8) ib = 8; else if (ib > 255) ib = 255;
            dst[idx] = (uint8_t)ir;
            dst[idx + 1] = (uint8_t)ig;
            dst[idx + 2] = (uint8_t)ib;
            dst[idx + 3] = 255u;
          }
        }
      }
    }
    free(hmap);
    _aipl_images[slot].gl_dirty = 1;
    return aipl_int(slot);
  }

  for (int y = 0; y < h; y++) {
    float v = (float)y / (float)h;
    for (int x = 0; x < w; x++) {
      float u = (float)x / (float)w;
      float fbm1 = _aipl_tex_fbm_periodic(u, v, 4, 4, seed + 17u);
      float fbm2 = _aipl_tex_fbm_periodic(u, v, 8, 3, seed + 131u);
      float fine = _aipl_tex_val_noise_periodic(u * 16.0f, v * 16.0f, 16, 16, seed + 509u);
      float elev = fbm1;
      if (mat == 0) { /* grass */
        float blade = _aipl_tex_val_noise_periodic(u * 24.0f, v * 12.0f, 24, 12, seed + 313u);
        elev = 0.45f * fbm1 + 0.35f * blade + 0.20f * fine;
      } else if (mat == 1 || mat == 2) { /* rock / cliff */
        float strata = 0.5f + 0.5f * sinf((v * (mat == 2 ? 6.0f : 3.0f) + fbm1 * 0.65f) * 6.2831853f);
        float crack = fabsf(fbm2 - 0.5f) * 2.0f;
        elev = 0.45f * strata + 0.35f * crack + 0.20f * fine;
      } else if (mat == 4) { /* cobble */
        uint32_t cid = 0;
        float edge = _aipl_tex_voronoi_periodic(u + (fbm1 - 0.5f) * 0.04f, v + (fbm2 - 0.5f) * 0.04f, 6, seed + 77u, &cid);
        float dome = fminf(1.0f, edge * 3.2f);
        elev = dome * 0.8f + fine * 0.2f;
      } else if (mat == 5) { /* water */
        float w1 = sinf((u * 3.0f + v * 2.0f + fbm1 * 0.45f) * 6.2831853f);
        float w2 = cosf((u * 2.0f - v * 4.0f + fbm2 * 0.45f) * 6.2831853f);
        elev = 0.5f + 0.25f * w1 + 0.25f * w2;
      } else if (mat == 6 || mat == 7) { /* wood / bark */
        float freq = (mat == 6) ? 6.0f : 10.0f;
        float grain = 0.5f + 0.5f * sinf((u * freq + fbm1 * (mat == 6 ? 0.5f : 1.1f)) * 6.2831853f);
        elev = 0.65f * grain + 0.35f * fbm2;
      } else if (mat == 9) { /* brick */
        float rows = 8.0f, cols = 4.0f;
        int ry = (int)floorf(v * rows);
        float stagger = (ry & 1) ? 0.5f : 0.0f;
        float bx = fmodf(u * cols + stagger, 1.0f);
        float by = fmodf(v * rows, 1.0f);
        int mortar = (bx < 0.08f || bx > 0.94f || by < 0.12f || by > 0.92f);
        elev = mortar ? (0.12f + 0.1f * fine) : (0.72f + 0.28f * fbm2);
      } else if (mat == 10) { /* roof */
        float rows = 8.0f, cols = 6.0f;
        int ry = (int)floorf(v * rows);
        float stagger = (ry & 1) ? 0.5f : 0.0f;
        float bx = fmodf(u * cols + stagger, 1.0f);
        float by = fmodf(v * rows, 1.0f);
        int seam = (bx < 0.06f || by < 0.10f);
        elev = seam ? 0.15f : (0.35f + 0.50f * by + 0.15f * fine);
      }
      hmap[(size_t)y * (size_t)w + (size_t)x] = elev;
    }
  }

  for (int y = 0; y < h; y++) {
    int ym = (y - 1 + h) % h;
    int yp = (y + 1) % h;
    float v = (float)y / (float)h;
    for (int x = 0; x < w; x++) {
      int xm = (x - 1 + w) % w;
      int xp = (x + 1) % w;
      float u = (float)x / (float)w;
      float hc = hmap[(size_t)y * (size_t)w + (size_t)x];
      float dhx = (hmap[(size_t)y * (size_t)w + (size_t)xp] - hmap[(size_t)y * (size_t)w + (size_t)xm]) * 2.4f;
      float dhy = (hmap[(size_t)yp * (size_t)w + (size_t)x] - hmap[(size_t)ym * (size_t)w + (size_t)x]) * 2.4f;
      float nx = -dhx, ny = -dhy, nz = 1.0f;
      float nlen = sqrtf(nx * nx + ny * ny + nz * nz);
      nx /= nlen; ny /= nlen; nz /= nlen;
      /* Directional micro-relief light from (-0.48, -0.52, 0.70) */
      float micro_lit = nx * (-0.48f) + ny * (-0.52f) + nz * 0.70f;
      float shade = 0.68f + 0.48f * fmaxf(0.0f, micro_lit);
      float fbm = _aipl_tex_fbm_periodic(u, v, 4, 3, seed + 251u);

      float r = 128.0f, g = 128.0f, b = 128.0f;
      if (mat == 0) { /* grass */
        r = 52.0f + 46.0f * hc + 18.0f * fbm;
        g = 126.0f + 64.0f * hc + 14.0f * fbm;
        b = 42.0f + 32.0f * hc;
      } else if (mat == 1) { /* rock */
        r = 104.0f + 56.0f * hc;
        g = 106.0f + 56.0f * hc;
        b = 112.0f + 58.0f * hc;
      } else if (mat == 2) { /* cliff */
        r = 88.0f + 62.0f * hc;
        g = 86.0f + 58.0f * hc;
        b = 92.0f + 60.0f * hc;
      } else if (mat == 3) { /* dirt */
        r = 112.0f + 48.0f * hc;
        g = 84.0f + 38.0f * hc;
        b = 56.0f + 28.0f * hc;
      } else if (mat == 4) { /* cobble */
        uint32_t cid = 0;
        float edge = _aipl_tex_voronoi_periodic(u + (fbm - 0.5f) * 0.04f, v + (hc - 0.5f) * 0.04f, 6, seed + 77u, &cid);
        if (edge < 0.075f) {
          r = 52.0f; g = 50.0f; b = 48.0f;
        } else {
          float tint = (float)(cid & 0x1Fu) - 16.0f;
          r = 128.0f + 36.0f * hc + tint;
          g = 125.0f + 35.0f * hc + tint * 0.9f;
          b = 120.0f + 34.0f * hc + tint * 0.8f;
        }
      } else if (mat == 5) { /* water */
        float spec = powf(fmaxf(0.0f, hc), 3.0f) * 65.0f;
        r = 26.0f + 48.0f * hc + spec;
        g = 118.0f + 68.0f * hc + spec;
        b = 188.0f + 52.0f * hc + spec * 0.6f;
      } else if (mat == 6) { /* wood */
        r = 148.0f + 52.0f * hc;
        g = 102.0f + 42.0f * hc;
        b = 58.0f + 28.0f * hc;
      } else if (mat == 7) { /* bark */
        r = 86.0f + 46.0f * hc;
        g = 64.0f + 34.0f * hc;
        b = 44.0f + 24.0f * hc;
      } else if (mat == 8) { /* foliage */
        r = 38.0f + 48.0f * hc;
        g = 108.0f + 68.0f * hc;
        b = 46.0f + 34.0f * hc;
      } else if (mat == 9) { /* brick */
        if (hc < 0.30f) {
          r = 168.0f + 22.0f * fbm;
          g = 164.0f + 22.0f * fbm;
          b = 156.0f + 20.0f * fbm;
        } else {
          int ry = (int)floorf(v * 8.0f);
          int rx = (int)floorf(u * 4.0f + ((ry & 1) ? 0.5f : 0.0f));
          uint32_t bh = _aipl_tex_hash2d(rx, ry, 4, 8, seed + 911u);
          float bt = (float)(bh & 0x1Fu) - 15.0f;
          r = 168.0f + 32.0f * fbm + bt;
          g = 74.0f + 22.0f * fbm + bt * 0.5f;
          b = 56.0f + 18.0f * fbm + bt * 0.4f;
        }
      } else if (mat == 10) { /* roof */
        if (hc < 0.22f) {
          r = 56.0f; g = 34.0f; b = 30.0f;
        } else {
          r = 146.0f + 42.0f * hc;
          g = 64.0f + 26.0f * hc;
          b = 52.0f + 22.0f * hc;
        }
      } else if (mat == 11) { /* sand */
        r = 202.0f + 36.0f * hc;
        g = 180.0f + 34.0f * hc;
        b = 128.0f + 30.0f * hc;
      } else { /* snow */
        r = 216.0f + 34.0f * hc;
        g = 226.0f + 26.0f * hc;
        b = 238.0f + 16.0f * hc;
      }

      int ir = (int)(r * shade + 0.5f);
      int ig = (int)(g * shade + 0.5f);
      int ib = (int)(b * shade + 0.5f);
      if (ir < 8) ir = 8; else if (ir > 255) ir = 255;
      if (ig < 8) ig = 8; else if (ig > 255) ig = 255;
      if (ib < 8) ib = 8; else if (ib > 255) ib = 255;
      size_t idx = ((size_t)y * (size_t)w + (size_t)x) * 4;
      dst[idx]     = (uint8_t)ir;
      dst[idx + 1] = (uint8_t)ig;
      dst[idx + 2] = (uint8_t)ib;
      dst[idx + 3] = 255u;
    }
  }
  free(hmap);
  _aipl_images[slot].gl_dirty = 1;
  return aipl_int(slot);
}

static void _aipl_iso_draw_capsule(
    uint8_t* sheet_px, int sheet_w,
    float* zbuf, int ox, int oy, int fw, int fh,
    float x0, float y0, float z0,
    float x1, float y1, float z1,
    float rad,
    float mr, float mg, float mb,
    float spec_str, float shininess, float emissive,
    uint32_t seed) {
  if (rad <= 0.1f) return;
  const float sin30 = 0.5f;
  const float cos30 = 0.8660254f;
  float anchor_x = (float)fw * 0.5f;
  float anchor_y = (float)fh * 0.84f;
  float sx0 = anchor_x + x0;
  float sy0 = anchor_y + y0 * sin30 - z0 * cos30;
  float vz0 = y0 * cos30 + z0 * sin30;
  float sx1 = anchor_x + x1;
  float sy1 = anchor_y + y1 * sin30 - z1 * cos30;
  float vz1 = y1 * cos30 + z1 * sin30;

  int px0 = (int)floorf(fminf(sx0, sx1) - rad - 1.0f);
  int px1 = (int)ceilf(fmaxf(sx0, sx1) + rad + 1.0f);
  int py0 = (int)floorf(fminf(sy0, sy1) - rad - 1.0f);
  int py1 = (int)ceilf(fmaxf(sy0, sy1) + rad + 1.0f);
  if (px0 < 0) px0 = 0;
  if (px1 >= fw) px1 = fw - 1;
  if (py0 < 0) py0 = 0;
  if (py1 >= fh) py1 = fh - 1;
  if (px0 > px1 || py0 > py1) return;

  float abx = sx1 - sx0;
  float aby = sy1 - sy0;
  float ab2 = abx * abx + aby * aby;
  float r2 = rad * rad;

  for (int py = py0; py <= py1; py++) {
    float fy = (float)py + 0.5f;
    for (int px = px0; px <= px1; px++) {
      float fx = (float)px + 0.5f;
      float t = (ab2 > 1e-4f) ? (((fx - sx0) * abx + (fy - sy0) * aby) / ab2) : 0.0f;
      if (t < 0.0f) t = 0.0f; else if (t > 1.0f) t = 1.0f;
      float cx = sx0 + t * abx;
      float cy = sy0 + t * aby;
      float cz = vz0 + t * (vz1 - vz0);
      float dx = fx - cx;
      float dy = fy - cy;
      float d2 = dx * dx + dy * dy;
      if (d2 < r2) {
        float dz = sqrtf(r2 - d2);
        float vz_hit = cz + dz;
        int z_idx = py * fw + px;
        if (vz_hit >= zbuf[z_idx]) {
          zbuf[z_idx] = vz_hit;
          float nx = dx / rad;
          float ny = dy / rad;
          float nz = dz / rad;
          float ndotl = fmaxf(0.0f, nx * (-0.48f) + ny * (-0.58f) + nz * 0.66f);
          float ndoth = fmaxf(0.0f, nx * (-0.28f) + ny * (-0.34f) + nz * 0.90f);
          float spec = (spec_str > 0.0f) ? (powf(ndoth, shininess) * spec_str) : 0.0f;
          float rim = powf(1.0f - fmaxf(0.0f, nz), 2.6f) * 0.36f;
          float ao = 0.72f + 0.28f * (1.0f - (float)py / (float)fh);
          float mn = 0.90f + 0.18f * ((float)(((px * 73 + py * 151 + (int)seed) & 15)) / 15.0f);
          float lit = (0.30f + 0.78f * ndotl) * ao * mn + emissive;
          int ir = (int)(mr * lit + 235.0f * spec + 125.0f * rim + 0.5f);
          int ig = (int)(mg * lit + 240.0f * spec + 150.0f * rim + 0.5f);
          int ib = (int)(mb * lit + 255.0f * spec + 190.0f * rim + 0.5f);
          if (ir < 4) ir = 4; else if (ir > 255) ir = 255;
          if (ig < 4) ig = 4; else if (ig > 255) ig = 255;
          if (ib < 4) ib = 4; else if (ib > 255) ib = 255;
          size_t dst_idx = ((size_t)(oy + py) * (size_t)sheet_w + (size_t)(ox + px)) * 4;
          sheet_px[dst_idx]     = (uint8_t)ir;
          sheet_px[dst_idx + 1] = (uint8_t)ig;
          sheet_px[dst_idx + 2] = (uint8_t)ib;
          sheet_px[dst_idx + 3] = 255u;
        }
      }
    }
  }
}

AiplVal aipl_rt_createIsometricSpriteSheet(AiplVal arch_v, AiplVal fw_v, AiplVal fh_v, AiplVal dirs_v, AiplVal fpd_v, AiplVal seed_v) {
  const char* arch = (arch_v.kind == AIPL_STR && arch_v.s) ? arch_v.s : "hero_knight";
  int fw = (int)aipl_to_c_double(fw_v);
  int fh = (int)aipl_to_c_double(fh_v);
  int dirs = (int)aipl_to_c_double(dirs_v);
  int fpd = (int)aipl_to_c_double(fpd_v);
  uint32_t seed = (uint32_t)((int64_t)aipl_to_c_double(seed_v));
  if (fw < 4) fw = 4; else if (fw > 256) fw = 256;
  if (fh < 4) fh = 4; else if (fh > 256) fh = 256;
  if (dirs < 1) dirs = 1; else if (dirs > 16) dirs = 16;
  if (fpd < 1) fpd = 1; else if (fpd > 32) fpd = 32;

  int sheet_w = fw * fpd;
  int sheet_h = fh * dirs;
  char sheet_key[512];
  snprintf(sheet_key, sizeof(sheet_key), "__isosheet__:%s:%dx%d:%dx%d:%u", arch, fw, fh, dirs, fpd, seed);
  if (_aipl_images && _aipl_image_paths) {
    for (int i = 1; i < _aipl_images_cap; i++) {
      if (_aipl_images[i].active && _aipl_images[i].w == sheet_w && _aipl_images[i].h == sheet_h && _aipl_image_paths[i][0] && strcmp(_aipl_image_paths[i], sheet_key) == 0) {
        return aipl_int(i);
      }
    }
  }

  int slot = _aipl_alloc_image_slot(sheet_w, sheet_h);
  if (slot < 0) return aipl_int(0);
  if (_aipl_image_paths) {
    strncpy(_aipl_image_paths[slot], sheet_key, 511);
    _aipl_image_paths[slot][511] = 0;
  }
  uint8_t* dst = _aipl_images[slot].pixels;
  memset(dst, 0, (size_t)sheet_w * (size_t)sheet_h * 4);

  float* zbuf = (float*)malloc((size_t)fw * (size_t)fh * sizeof(float));
  if (!zbuf) return aipl_int(slot);

  int kind = 0; /* 0:hero_knight/paladin/rogue, 1:skeleton/demon, 2:campfire, 3:gothic_tree/dead_tree */
  int is_paladin = (strcasecmp(arch, "paladin") == 0);
  int is_rogue   = (strcasecmp(arch, "rogue") == 0);
  int is_demon   = (strcasecmp(arch, "demon") == 0);
  int is_dead_tree = (strcasecmp(arch, "dead_tree") == 0);
  if (strcasecmp(arch, "skeleton") == 0 || is_demon) kind = 1;
  else if (strcasecmp(arch, "campfire") == 0 || strcasecmp(arch, "fire") == 0) kind = 2;
  else if (strcasecmp(arch, "gothic_tree") == 0 || is_dead_tree || strcasecmp(arch, "tree") == 0) kind = 3;

  float sc = fminf((float)fw, (float)fh) / 48.0f;

  for (int d = 0; d < dirs; d++) {
    int oy = d * fh;
    /* Compass direction angle: 0=N(up), 1=NE, 2=E(right), 3=SE, 4=S(down), 5=SW, 6=W(left), 7=NW */
    float ang = ((float)d - 2.0f) * (6.2831853f / (float)(dirs > 1 ? dirs : 8));
    float fwd_x = cosf(ang);
    float fwd_y = sinf(ang);
    float right_x = -sinf(ang);
    float right_y = cosf(ang);

    for (int f = 0; f < fpd; f++) {
      int ox = f * fw;
      for (int zi = 0; zi < fw * fh; zi++) zbuf[zi] = -1e20f;
      float phase = ((float)f / (float)fpd) * 6.2831853f;
      float swing = sinf(phase);
      float bob = fabsf(cosf(phase)) * 1.3f;

      #define L2WX(lx, ly) (((lx) * right_x + (ly) * fwd_x) * sc)
      #define L2WY(lx, ly) (((lx) * right_y + (ly) * fwd_y) * sc)
      #define L2WZ(lz)     (((lz) + bob) * sc)

      if (kind == 0 || kind == 1) {
        int is_skel = (kind == 1);
        float armor_r = is_skel ? (is_demon ? 164.0f : 198.0f) : (is_paladin ? 228.0f : (is_rogue ? 68.0f  : 148.0f));
        float armor_g = is_skel ? (is_demon ? 42.0f  : 190.0f) : (is_paladin ? 204.0f : (is_rogue ? 82.0f  : 162.0f));
        float armor_b = is_skel ? (is_demon ? 38.0f  : 172.0f) : (is_paladin ? 132.0f : (is_rogue ? 76.0f  : 186.0f));
        float cape_r  = is_skel ? (is_demon ? 48.0f  : 92.0f)  : (is_paladin ? 42.0f  : (is_rogue ? 34.0f  : 168.0f));
        float cape_g  = is_skel ? (is_demon ? 18.0f  : 24.0f)  : (is_paladin ? 96.0f  : (is_rogue ? 112.0f : 32.0f));
        float cape_b  = is_skel ? (is_demon ? 22.0f  : 34.0f)  : (is_paladin ? 196.0f : (is_rogue ? 64.0f  : 42.0f));

        /* Left & right legs striding */
        float l_leg_y = swing * 4.6f;
        float r_leg_y = -swing * 4.6f;
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(-3.2f, l_leg_y), L2WY(-3.2f, l_leg_y), 1.5f * sc,
          L2WX(-3.0f, 0.0f),    L2WY(-3.0f, 0.0f),    L2WZ(13.0f),
          (is_skel ? 1.8f : 2.6f) * sc, armor_r * 0.78f, armor_g * 0.78f, armor_b * 0.82f, 0.45f, 18.0f, 0.0f, seed + 11u);
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(3.2f, r_leg_y), L2WY(3.2f, r_leg_y), 1.5f * sc,
          L2WX(3.0f, 0.0f),    L2WY(3.0f, 0.0f),    L2WZ(13.0f),
          (is_skel ? 1.8f : 2.6f) * sc, armor_r * 0.78f, armor_g * 0.78f, armor_b * 0.82f, 0.45f, 18.0f, 0.0f, seed + 23u);

        /* Flowing cape behind torso */
        float cape_sway = swing * 2.2f;
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(-2.5f + cape_sway, -5.2f), L2WY(-2.5f + cape_sway, -5.2f), L2WZ(7.0f),
          L2WX(-1.8f, -2.5f),             L2WY(-1.8f, -2.5f),             L2WZ(24.0f),
          3.8f * sc, cape_r, cape_g, cape_b, 0.12f, 8.0f, 0.0f, seed + 37u);
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(2.5f + cape_sway, -5.2f),  L2WY(2.5f + cape_sway, -5.2f),  L2WZ(7.0f),
          L2WX(1.8f, -2.5f),              L2WY(1.8f, -2.5f),              L2WZ(24.0f),
          3.8f * sc, cape_r, cape_g, cape_b, 0.12f, 8.0f, 0.0f, seed + 41u);

        /* Torso cuirass / ribcage */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(0.0f, 0.0f), L2WY(0.0f, 0.0f), L2WZ(13.0f),
          L2WX(0.0f, 0.4f), L2WY(0.0f, 0.4f), L2WZ(24.5f),
          (is_skel ? 4.4f : 5.4f) * sc, armor_r, armor_g, armor_b, 0.65f, 24.0f, 0.0f, seed + 53u);

        /* Golden / bronze waist belt & chest tabard trim */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(-3.2f, 1.2f), L2WY(-3.2f, 1.2f), L2WZ(14.5f),
          L2WX(3.2f, 1.2f),  L2WY(3.2f, 1.2f),  L2WZ(14.5f),
          2.2f * sc, 218.0f, 174.0f, 68.0f, 0.70f, 28.0f, 0.08f, seed + 61u);

        /* Left & right shoulder pauldrons */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(-6.5f, 0.0f), L2WY(-6.5f, 0.0f), L2WZ(23.5f),
          L2WX(-5.8f, 0.0f), L2WY(-5.8f, 0.0f), L2WZ(25.0f),
          3.4f * sc, armor_r * 1.06f, armor_g * 1.04f, armor_b * 1.08f, 0.75f, 28.0f, 0.0f, seed + 71u);
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(6.5f, 0.0f), L2WY(6.5f, 0.0f), L2WZ(23.5f),
          L2WX(5.8f, 0.0f), L2WY(5.8f, 0.0f), L2WZ(25.0f),
          3.4f * sc, armor_r * 1.06f, armor_g * 1.04f, armor_b * 1.08f, 0.75f, 28.0f, 0.0f, seed + 79u);

        /* Head / Great-helm / Skull */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(0.0f, 0.4f), L2WY(0.0f, 0.4f), L2WZ(28.5f),
          L2WX(0.0f, 0.4f), L2WY(0.0f, 0.4f), L2WZ(33.0f),
          4.2f * sc, armor_r * 1.08f, armor_g * 1.06f, armor_b * 1.08f, 0.80f, 32.0f, 0.0f, seed + 89u);

        /* Glowing visor eyes on front of helm/skull */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(-1.6f, 4.1f), L2WY(-1.6f, 4.1f), L2WZ(30.5f),
          L2WX(1.6f, 4.1f),  L2WY(1.6f, 4.1f),  L2WZ(30.5f),
          1.25f * sc,
          is_skel ? 255.0f : 96.0f,
          is_skel ? 64.0f  : 224.0f,
          is_skel ? 36.0f  : 255.0f,
          0.90f, 32.0f, 0.65f, seed + 97u);

        /* Left arm + Kite Shield */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(-7.8f, 2.6f - swing * 1.5f), L2WY(-7.8f, 2.6f - swing * 1.5f), L2WZ(15.0f),
          L2WX(-7.8f, 3.2f - swing * 1.5f), L2WY(-7.8f, 3.2f - swing * 1.5f), L2WZ(22.5f),
          3.4f * sc, is_skel ? 112.0f : 48.0f, is_skel ? 56.0f : 92.0f, is_skel ? 46.0f : 168.0f, 0.65f, 24.0f, 0.05f, seed + 103u);
        /* Shield golden boss */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(-8.8f, 3.6f - swing * 1.5f), L2WY(-8.8f, 3.6f - swing * 1.5f), L2WZ(19.0f),
          L2WX(-8.8f, 3.6f - swing * 1.5f), L2WY(-8.8f, 3.6f - swing * 1.5f), L2WZ(19.2f),
          1.6f * sc, 242.0f, 196.0f, 72.0f, 0.85f, 32.0f, 0.15f, seed + 107u);

        /* Right arm + Broadsword / Cleaver */
        float hand_y = 2.5f + swing * 3.2f;
        float tip_y  = 11.5f + swing * 5.2f;
        float tip_z  = 29.0f - swing * 6.5f;
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(6.8f, 0.5f),   L2WY(6.8f, 0.5f),   L2WZ(23.0f),
          L2WX(7.6f, hand_y), L2WY(7.6f, hand_y), L2WZ(18.0f),
          2.2f * sc, armor_r * 0.90f, armor_g * 0.90f, armor_b * 0.92f, 0.50f, 20.0f, 0.0f, seed + 113u);
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          L2WX(7.6f, hand_y), L2WY(7.6f, hand_y), L2WZ(18.0f),
          L2WX(8.6f, tip_y),  L2WY(8.6f, tip_y),  L2WZ(tip_z),
          1.65f * sc, 224.0f, 236.0f, 250.0f, 0.95f, 36.0f, 0.18f, seed + 127u);
      } else if (kind == 2) {
        /* Campfire: 6 radial charred logs + glowing ember core + animated flickering flame tongues */
        for (int li = 0; li < 6; li++) {
          float lang = (float)li * (6.2831853f / 6.0f) + 0.25f;
          float lx0 = cosf(lang) * 3.0f * sc, ly0 = sinf(lang) * 3.0f * sc;
          float lx1 = cosf(lang) * 12.5f * sc, ly1 = sinf(lang) * 12.5f * sc;
          _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
            lx0, ly0, 4.0f * sc, lx1, ly1, 2.0f * sc,
            2.6f * sc, 92.0f, 58.0f, 36.0f, 0.15f, 8.0f, 0.05f, seed + (uint32_t)(li * 19));
        }
        /* Ember bed */
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          -3.5f * sc, 0.0f, 3.0f * sc, 3.5f * sc, 0.0f, 3.0f * sc,
          4.8f * sc, 255.0f, 96.0f, 24.0f, 0.40f, 12.0f, 0.55f, seed + 201u);
        /* Animated outer crimson-orange flames & inner golden-white core */
        for (int ti = 0; ti < 5; ti++) {
          float tang = (float)ti * 1.256637f + phase;
          float bx = cosf(tang) * 3.8f * sc;
          float by = sinf(tang) * 3.8f * sc;
          float tx = sinf(phase + (float)ti * 1.7f) * 3.2f * sc;
          float ty = cosf(phase * 1.0f + (float)ti) * 2.2f * sc;
          float th_flame = (18.0f + 5.0f * sinf(phase + (float)ti * 1.3f)) * sc;
          _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
            bx, by, 5.0f * sc, tx, ty, th_flame,
            3.6f * sc, 255.0f, 136.0f, 28.0f, 0.30f, 10.0f, 0.68f, seed + (uint32_t)(ti * 31));
        }
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          0.0f, 0.0f, 5.5f * sc, sinf(phase) * 1.8f * sc, 0.0f, 16.0f * sc,
          3.2f * sc, 255.0f, 238.0f, 148.0f, 0.50f, 16.0f, 0.85f, seed + 307u);
      } else {
        /* Gothic dead/gnarled tree */
        float lean = ((float)(f % 3) - 1.0f) * 2.2f * sc;
        for (int ri = 0; ri < 4; ri++) {
          float rang = (float)ri * 1.570796f + 0.4f + (float)f * 0.3f;
          _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
            0.0f, 0.0f, 5.0f * sc, cosf(rang) * 10.5f * sc, sinf(rang) * 10.5f * sc, 1.2f * sc,
            2.4f * sc, 78.0f, 56.0f, 40.0f, 0.15f, 8.0f, 0.0f, seed + (uint32_t)(ri * 17));
        }
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          0.0f, 0.0f, 3.0f * sc, lean * 0.5f, 0.0f, 18.0f * sc,
          4.2f * sc, 84.0f, 60.0f, 42.0f, 0.18f, 10.0f, 0.0f, seed + 401u);
        _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
          lean * 0.5f, 0.0f, 18.0f * sc, lean, 0.0f, 31.0f * sc,
          3.1f * sc, 88.0f, 64.0f, 45.0f, 0.18f, 10.0f, 0.0f, seed + 409u);
        for (int bi = 0; bi < 4; bi++) {
          float bang = (float)bi * 1.570796f + 0.6f + (float)f * 0.5f;
          float bx = lean + cosf(bang) * 11.5f * sc;
          float by = sinf(bang) * 11.5f * sc;
          float bz = (28.0f + (float)(bi & 1) * 4.5f) * sc;
          _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
            lean * 0.8f, 0.0f, 23.0f * sc, bx, by, bz,
            2.0f * sc, 82.0f, 58.0f, 40.0f, 0.15f, 8.0f, 0.0f, seed + (uint32_t)(bi * 29));
          if (!is_dead_tree) {
            _aipl_iso_draw_capsule(dst, sheet_w, zbuf, ox, oy, fw, fh,
              bx * 0.85f, by * 0.85f, bz, bx, by, bz + 3.5f * sc,
              4.8f * sc, 36.0f, 68.0f, 44.0f, 0.12f, 6.0f, 0.0f, seed + (uint32_t)(bi * 43));
          }
        }
      }

      #undef L2WX
      #undef L2WY
      #undef L2WZ
    }
  }

  free(zbuf);
  _aipl_images[slot].gl_dirty = 1;
  return aipl_int(slot);
}

AiplVal aipl_rt_saveTextureToPpm(AiplVal texId_v, AiplVal path_v) {
  int id = (int)aipl_to_c_double(texId_v);
  if (id <= 0 || id >= _aipl_images_cap || !_aipl_images || !_aipl_images[id].active || !_aipl_images[id].pixels) return aipl_bool(false);
  const char* path = (path_v.kind == AIPL_STR && path_v.s && path_v.s[0]) ? path_v.s : "";
  if (!path[0]) return aipl_bool(false);
  int w = _aipl_images[id].w, h = _aipl_images[id].h;
  if (w <= 0 || h <= 0) return aipl_bool(false);
  FILE* fp = fopen(path, "wb");
  if (!fp) return aipl_bool(false);
  fprintf(fp, "P6\n%d %d\n255\n", w, h);
  uint8_t* row = (uint8_t*)malloc((size_t)w * 3);
  if (!row) { fclose(fp); return aipl_bool(false); }
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      size_t src = ((size_t)y * (size_t)w + (size_t)x) * 4;
      uint8_t r = _aipl_images[id].pixels[src];
      uint8_t g = _aipl_images[id].pixels[src + 1];
      uint8_t b = _aipl_images[id].pixels[src + 2];
      if (r <= 2 && g <= 2 && b <= 2 && _aipl_images[id].pixels[src + 3] > 0) {
        r = 4; g = 4; b = 4;
      }
      row[x * 3]     = r;
      row[x * 3 + 1] = g;
      row[x * 3 + 2] = b;
    }
    fwrite(row, 1, (size_t)w * 3, fp);
  }
  free(row);
  fclose(fp);
  if (_aipl_image_paths) {
    for (int i = 1; i < _aipl_images_cap; i++) {
      if (_aipl_image_paths[i][0] && strcmp(_aipl_image_paths[i], path) == 0) {
        _aipl_image_paths[i][0] = 0;
      }
    }
  }
  return aipl_bool(true);
}

int _aipl_load_ppm_file(const char* filepath) {
  FILE* fp = fopen(filepath, "rb");
  if (!fp) return -1;
  char header[3] = { 0 };
  if (fscanf(fp, "%2s", header) != 1 || strcmp(header, "P6") != 0) { fclose(fp); return -1; }
  int ch = fgetc(fp);
  while (ch != EOF) {
    while (isspace(ch)) ch = fgetc(fp);
    if (ch == '#') {
      while (ch != '\n' && ch != EOF) ch = fgetc(fp);
    } else {
      ungetc(ch, fp);
      break;
    }
  }
  int w = 0, h = 0, max_val = 0;
  if (fscanf(fp, "%d %d", &w, &h) != 2 || w <= 0 || h <= 0) { fclose(fp); return -1; }
  if (fscanf(fp, "%d", &max_val) != 1 || max_val <= 0) { fclose(fp); return -1; }
  fgetc(fp);
  int slot = _aipl_alloc_image_slot(w, h);
  if (slot < 0) { fclose(fp); return -1; }
  uint8_t* row_rgb = (uint8_t*)malloc((size_t)w * 3);
  if (!row_rgb) { _aipl_free_image_slot(slot); fclose(fp); return -1; }
  for (int y = 0; y < h; y++) {
    if (fread(row_rgb, 1, (size_t)w * 3, fp) != (size_t)w * 3) {
      free(row_rgb);
      _aipl_free_image_slot(slot);
      fclose(fp);
      return -1;
    }
    for (int x = 0; x < w; x++) {
      size_t dst = ((size_t)y * (size_t)w + (size_t)x) * 4;
      uint8_t r = row_rgb[x * 3];
      uint8_t g = row_rgb[x * 3 + 1];
      uint8_t b = row_rgb[x * 3 + 2];
      _aipl_images[slot].pixels[dst]     = r;
      _aipl_images[slot].pixels[dst + 1] = g;
      _aipl_images[slot].pixels[dst + 2] = b;
      if (strstr(filepath, "light_cookie") != NULL || strstr(filepath, "radial_light") != NULL) {
        uint8_t lum = r;
        if (g > lum) lum = g;
        if (b > lum) lum = b;
        _aipl_images[slot].pixels[dst + 3] = (lum <= 3) ? 0 : lum;
      } else {
        _aipl_images[slot].pixels[dst + 3] = (r <= 2 && g <= 2 && b <= 2) ? 0 : 255;
      }
    }
  }
  free(row_rgb);
  fclose(fp);
  return slot;
}

AiplVal aipl_rt_loadImage(AiplVal p) {
  const char* path = (p.kind == AIPL_STR && p.s) ? p.s : "";
  if (!path[0]) return aipl_err(aipl_str_lit("loadImage: empty path"));
  for (int i = 1; i < _aipl_images_cap; i++) {
    if (_aipl_images[i].active && _aipl_image_paths[i][0] && strcmp(_aipl_image_paths[i], path) == 0) {
      return aipl_ok(aipl_int(i));
    }
  }
  if (access(path, R_OK) != 0) return aipl_err(aipl_str_lit("loadImage: file does not exist"));
  size_t plen = strlen(path);
  if (plen >= 4 && strcasecmp(path + plen - 4, ".ppm") == 0) {
    int slot = _aipl_load_ppm_file(path);
    if (slot >= 0) {
      strncpy(_aipl_image_paths[slot], path, 511);
      _aipl_image_paths[slot][511] = 0;
      return aipl_ok(aipl_int(slot));
    }
    return aipl_err(aipl_str_lit("loadImage: cannot parse ppm image"));
  }
  static int load_seq = 0;
  char tmp_ppm[256];
  snprintf(tmp_ppm, sizeof(tmp_ppm), "/tmp/_aipl_load_%d_%d_%ld.ppm", (int)getpid(), ++load_seq, (long)time(NULL));
  char cmd[1024];
  snprintf(cmd, sizeof(cmd), "python3 -c \"from PIL import Image; Image.open('%s').convert('RGB').save('%s')\" 2>/dev/null || ffmpeg -y -i '%s' -pix_fmt rgb24 '%s' 2>/dev/null || convert '%s' '%s' 2>/dev/null", path, tmp_ppm, path, tmp_ppm, path, tmp_ppm);
  int ret = system(cmd);
  if (ret != 0) {
    remove(tmp_ppm);
    return aipl_err(aipl_str_lit("loadImage: failed to decode image"));
  }
  int slot = _aipl_load_ppm_file(tmp_ppm);
  remove(tmp_ppm);
  if (slot >= 0) {
    strncpy(_aipl_image_paths[slot], path, 511);
    _aipl_image_paths[slot][511] = 0;
    return aipl_ok(aipl_int(slot));
  }
  return aipl_err(aipl_str_lit("loadImage: unable to read decoded image"));
}

AiplVal aipl_rt_decodeImage(AiplVal d) {
  (void)d;
  int slot = _aipl_alloc_image_slot(64, 64);
  return aipl_ok(aipl_int(slot >= 0 ? slot : 1));
}

AiplVal aipl_rt_getImageWidth(AiplVal id) {
  int i = (int)((id.kind == AIPL_FLOAT) ? id.f : id.i);
  if (i > 0 && i < _aipl_images_cap && _aipl_images && _aipl_images[i].active) return aipl_int(_aipl_images[i].w);
  return aipl_int(0);
}

AiplVal aipl_rt_imageWidth(AiplVal id) { return aipl_rt_getImageWidth(id); }

AiplVal aipl_rt_getImageHeight(AiplVal id) {
  int i = (int)((id.kind == AIPL_FLOAT) ? id.f : id.i);
  if (i > 0 && i < _aipl_images_cap && _aipl_images && _aipl_images[i].active) return aipl_int(_aipl_images[i].h);
  return aipl_int(0);
}

AiplVal aipl_rt_imageHeight(AiplVal id) { return aipl_rt_getImageHeight(id); }

AiplVal aipl_rt_saveImage(AiplVal id_v, AiplVal path_v) {
  int id = (int)((id_v.kind == AIPL_FLOAT) ? id_v.f : id_v.i);
  if (id <= 0 || id >= _aipl_images_cap || !_aipl_images || !_aipl_images[id].active || !_aipl_images[id].pixels) return aipl_bool(false);
  const char* path = (path_v.kind == AIPL_STR && path_v.s) ? path_v.s : "saved_image.png";
  int w = _aipl_images[id].w, h = _aipl_images[id].h;
  static int simg_seq = 0;
  char tmp_ppm[256];
  snprintf(tmp_ppm, sizeof(tmp_ppm), "/tmp/_aipl_simg_%d_%d_%ld.ppm", (int)getpid(), ++simg_seq, (long)time(NULL));
  FILE* fp = fopen(tmp_ppm, "wb");
  if (!fp) return aipl_bool(false);
  fprintf(fp, "P6\n%d %d\n255\n", w, h);
  uint8_t* row = (uint8_t*)malloc((size_t)w * 3);
  if (!row) { fclose(fp); remove(tmp_ppm); return aipl_bool(false); }
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      size_t src = ((size_t)y * (size_t)w + (size_t)x) * 4;
      row[x * 3]     = _aipl_images[id].pixels[src];
      row[x * 3 + 1] = _aipl_images[id].pixels[src + 1];
      row[x * 3 + 2] = _aipl_images[id].pixels[src + 2];
    }
    fwrite(row, 1, (size_t)w * 3, fp);
  }
  free(row);
  fclose(fp);
  size_t plen = strlen(path);
  if (plen >= 4 && strcasecmp(path + plen - 4, ".ppm") == 0) {
    rename(tmp_ppm, path);
    return aipl_bool(true);
  }
  char scmd[1024];
  snprintf(scmd, sizeof(scmd), "python3 -c \"from PIL import Image; Image.open('%s').save('%s')\" 2>/dev/null || ffmpeg -y -i '%s' '%s' 2>/dev/null || convert '%s' '%s' 2>/dev/null", tmp_ppm, path, tmp_ppm, path, tmp_ppm, path);
  int sret = system(scmd);
  remove(tmp_ppm);
  return aipl_bool(sret == 0);
}

AiplVal aipl_rt_drawImageSub(AiplVal id_v, AiplVal sx_v, AiplVal sy_v, AiplVal sw_v, AiplVal sh_v, AiplVal dx_v, AiplVal dy_v, AiplVal dw_v, AiplVal dh_v, AiplVal tint_v) {
  int id = (int)((id_v.kind == AIPL_FLOAT) ? id_v.f : id_v.i);
  if (id <= 0 || id >= _aipl_images_cap || !_aipl_images || !_aipl_images[id].active || !_aipl_images[id].pixels) return aipl_nil();
  int img_w = _aipl_images[id].w, img_h = _aipl_images[id].h;
  int sx = (int)((sx_v.kind == AIPL_FLOAT) ? sx_v.f : sx_v.i);
  int sy = (int)((sy_v.kind == AIPL_FLOAT) ? sy_v.f : sy_v.i);
  int sw = (int)((sw_v.kind == AIPL_FLOAT) ? sw_v.f : sw_v.i);
  int sh = (int)((sh_v.kind == AIPL_FLOAT) ? sh_v.f : sh_v.i);
  int dx = (int)((dx_v.kind == AIPL_FLOAT) ? dx_v.f : dx_v.i);
  int dy = (int)((dy_v.kind == AIPL_FLOAT) ? dy_v.f : dy_v.i);
  int dw = (int)((dw_v.kind == AIPL_FLOAT) ? dw_v.f : dw_v.i);
  int dh = (int)((dh_v.kind == AIPL_FLOAT) ? dh_v.f : dh_v.i);
  if (sw <= 0 || sh <= 0 || dw <= 0 || dh <= 0) return aipl_nil();
  uint8_t tr = 255, tg = 255, tb = 255, ta = 255;
  if (tint_v.kind != AIPL_NIL) aipl_unpack_color(tint_v, &tr, &tg, &tb, &ta);
  if (ta == 0) return aipl_nil();
  uint8_t* src_px = _aipl_images[id].pixels;
  if (_aipl_window_backend == 2 && _aipl_glx_ctx) {
    float u0 = (img_w > 0) ? ((float)sx / (float)img_w) : 0.0f;
    float v0 = (img_h > 0) ? ((float)sy / (float)img_h) : 0.0f;
    float u1 = (img_w > 0) ? ((float)(sx + sw) / (float)img_w) : 1.0f;
    float v1 = (img_h > 0) ? ((float)(sy + sh) / (float)img_h) : 1.0f;
    float x0 = (float)dx, y0 = (float)dy;
    float x1 = (float)(dx + dw), y1 = (float)(dy + dh);
    _aipl_gl_select_state(id, 0);
    if (_aipl_gl_vert_count + 6 > _AIPL_GL_MAX_VERTS) _aipl_gl_flush_batch();
    _AiplGlVertex* v = &_aipl_gl_verts[_aipl_gl_vert_count];
    v[0].x = x0; v[0].y = y0; v[0].z = 0.0f; v[0].u = u0; v[0].v = v0; v[0].r = tr; v[0].g = tg; v[0].b = tb; v[0].a = ta;
    v[1].x = x1; v[1].y = y0; v[1].z = 0.0f; v[1].u = u1; v[1].v = v0; v[1].r = tr; v[1].g = tg; v[1].b = tb; v[1].a = ta;
    v[2].x = x1; v[2].y = y1; v[2].z = 0.0f; v[2].u = u1; v[2].v = v1; v[2].r = tr; v[2].g = tg; v[2].b = tb; v[2].a = ta;
    v[3].x = x0; v[3].y = y0; v[3].z = 0.0f; v[3].u = u0; v[3].v = v0; v[3].r = tr; v[3].g = tg; v[3].b = tb; v[3].a = ta;
    v[4].x = x1; v[4].y = y1; v[4].z = 0.0f; v[4].u = u1; v[4].v = v1; v[4].r = tr; v[4].g = tg; v[4].b = tb; v[4].a = ta;
    v[5].x = x0; v[5].y = y1; v[5].z = 0.0f; v[5].u = u0; v[5].v = v1; v[5].r = tr; v[5].g = tg; v[5].b = tb; v[5].a = ta;
    _aipl_gl_vert_count += 6;
    return aipl_nil();
  }
  aipl_ensure_canvas_fb();
  if (!_aipl_canvas_fb) return aipl_nil();
  int clip_x0 = 0, clip_x1 = _aipl_canvas_w;
  int clip_y0 = 0, clip_y1 = _aipl_canvas_h;
  if (_aipl_scissor_active) {
    if (_aipl_scissor_x > clip_x0) clip_x0 = _aipl_scissor_x;
    if (_aipl_scissor_y > clip_y0) clip_y0 = _aipl_scissor_y;
    if (_aipl_scissor_x + _aipl_scissor_w < clip_x1) clip_x1 = _aipl_scissor_x + _aipl_scissor_w;
    if (_aipl_scissor_y + _aipl_scissor_h < clip_y1) clip_y1 = _aipl_scissor_y + _aipl_scissor_h;
  }
  int px0 = (dx < clip_x0) ? (clip_x0 - dx) : 0;
  int px1 = (dx + dw > clip_x1) ? (clip_x1 - dx) : dw;
  int py0 = (dy < clip_y0) ? (clip_y0 - dy) : 0;
  int py1 = (dy + dh > clip_y1) ? (clip_y1 - dy) : dh;
  if (px0 >= px1 || py0 >= py1) return aipl_nil();
  uint32_t* fb32 = (uint32_t*)_aipl_canvas_fb;
  int cw = _aipl_canvas_w;
  int no_tint = (tr == 255 && tg == 255 && tb == 255 && ta == 255);
  for (int py = py0; py < py1; py++) {
    int src_y = sy + (py * sh) / dh;
    if (src_y < 0 || src_y >= img_h) continue;
    uint32_t* dst_row = fb32 + (size_t)(dy + py) * (size_t)cw;
    const uint8_t* src_row = src_px + (size_t)src_y * (size_t)img_w * 4;
    for (int px = px0; px < px1; px++) {
      int src_x = sx + (px * sw) / dw;
      if (src_x < 0 || src_x >= img_w) continue;
      const uint8_t* sp = src_row + (size_t)src_x * 4;
      uint32_t sa = no_tint ? sp[3] : (((uint32_t)sp[3] * (uint32_t)ta) / 255u);
      if (sa == 0) continue;
      uint32_t sr = no_tint ? sp[0] : (((uint32_t)sp[0] * (uint32_t)tr) / 255u);
      uint32_t sg = no_tint ? sp[1] : (((uint32_t)sp[1] * (uint32_t)tg) / 255u);
      uint32_t sb = no_tint ? sp[2] : (((uint32_t)sp[2] * (uint32_t)tb) / 255u);
      dst_row[dx + px] = _aipl_blend_pixel(dst_row[dx + px], sr, sg, sb, sa);
    }
  }
  return aipl_nil();
}

AiplVal aipl_rt_drawImageScaled(AiplVal id_v, AiplVal dx_v, AiplVal dy_v, AiplVal dw_v, AiplVal dh_v, AiplVal tint_v) {
  int id = (int)((id_v.kind == AIPL_FLOAT) ? id_v.f : id_v.i);
  if (id <= 0 || id >= _aipl_images_cap || !_aipl_images || !_aipl_images[id].active) return aipl_nil();
  return aipl_rt_drawImageSub(id_v, aipl_int(0), aipl_int(0), aipl_int(_aipl_images[id].w), aipl_int(_aipl_images[id].h), dx_v, dy_v, dw_v, dh_v, tint_v);
}

AiplVal aipl_rt_drawImage(AiplVal id_v, AiplVal x_v, AiplVal y_v, AiplVal tint_v) {
  int id = (int)((id_v.kind == AIPL_FLOAT) ? id_v.f : id_v.i);
  if (id <= 0 || id >= _aipl_images_cap || !_aipl_images || !_aipl_images[id].active) return aipl_nil();
  return aipl_rt_drawImageScaled(id_v, x_v, y_v, aipl_int(_aipl_images[id].w), aipl_int(_aipl_images[id].h), tint_v);
}

AiplVal aipl_rt_drawSubImage(AiplVal id, AiplVal sx, AiplVal sy, AiplVal sw, AiplVal sh, AiplVal dx, AiplVal dy, AiplVal dw, AiplVal dh) {
  return aipl_rt_drawImageSub(id, sx, sy, sw, sh, dx, dy, dw, dh, aipl_nil());
}

AiplVal aipl_rt_drawImageEx(AiplVal id_v, AiplVal x_v, AiplVal y_v, AiplVal w_v, AiplVal h_v, AiplVal rot_v, AiplVal ox_v, AiplVal oy_v, AiplVal tint_v, AiplVal flipX_v, AiplVal flipY_v) {
  int id = (int)aipl_to_c_double(id_v);
  if (id <= 0 || id >= _aipl_images_cap || !_aipl_images || !_aipl_images[id].active || !_aipl_images[id].pixels) return aipl_nil();
  float x = (float)aipl_to_c_double(x_v);
  float y = (float)aipl_to_c_double(y_v);
  float w = (float)aipl_to_c_double(w_v);
  float h = (float)aipl_to_c_double(h_v);
  if (w <= 0.0f || h <= 0.0f) return aipl_nil();
  float rot = (float)aipl_to_c_double(rot_v);
  float ox = (float)aipl_to_c_double(ox_v);
  float oy = (float)aipl_to_c_double(oy_v);
  int fx = aipl_truthy(flipX_v) ? 1 : 0;
  int fy = aipl_truthy(flipY_v) ? 1 : 0;
  if (fabsf(rot) < 1e-6f && fabsf(ox) < 1e-6f && fabsf(oy) < 1e-6f && !fx && !fy) {
    return aipl_rt_drawImageScaled(id_v, x_v, y_v, w_v, h_v, tint_v);
  }
  uint8_t tr = 255, tg = 255, tb = 255, ta = 255;
  if (tint_v.kind != AIPL_NIL) aipl_unpack_color(tint_v, &tr, &tg, &tb, &ta);
  if (ta == 0) return aipl_nil();
  float u0 = fx ? 1.0f : 0.0f;
  float u1 = fx ? 0.0f : 1.0f;
  float v0 = fy ? 1.0f : 0.0f;
  float v1 = fy ? 0.0f : 1.0f;
  float c = cosf(rot), s = sinf(rot);
  float lx0 = -ox,     ly0 = -oy;
  float lx1 = w - ox,  ly1 = h - oy;
  float x00 = x + lx0 * c - ly0 * s, y00 = y + lx0 * s + ly0 * c;
  float x10 = x + lx1 * c - ly0 * s, y10 = y + lx1 * s + ly0 * c;
  float x11 = x + lx1 * c - ly1 * s, y11 = y + lx1 * s + ly1 * c;
  float x01 = x + lx0 * c - ly1 * s, y01 = y + lx0 * s + ly1 * c;
  _aipl_rasterize_triangle_textured(id, x00, y00, 0.0f, u0, v0, x10, y10, 0.0f, u1, v0, x11, y11, 0.0f, u1, v1, tr, tg, tb, ta, tr, tg, tb, ta, tr, tg, tb, ta, 0);
  _aipl_rasterize_triangle_textured(id, x00, y00, 0.0f, u0, v0, x11, y11, 0.0f, u1, v1, x01, y01, 0.0f, u0, v1, tr, tg, tb, ta, tr, tg, tb, ta, tr, tg, tb, ta, 0);
  return aipl_nil();
}

_AiplWavAsset* _aipl_loaded_wavs = NULL;
int _aipl_loaded_wavs_cap = 0;
void _aipl_ensure_wav_slot(int slot) {
  if (slot < 0) return;
  if (slot >= _aipl_loaded_wavs_cap) {
    int new_cap = (_aipl_loaded_wavs_cap == 0) ? 256 : _aipl_loaded_wavs_cap * 2;
    while (new_cap <= slot) new_cap *= 2;
    _AiplWavAsset* nw = (_AiplWavAsset*)realloc(_aipl_loaded_wavs, (size_t)new_cap * sizeof(_AiplWavAsset));
    if (nw) {
      memset(nw + _aipl_loaded_wavs_cap, 0, (size_t)(new_cap - _aipl_loaded_wavs_cap) * sizeof(_AiplWavAsset));
      _aipl_loaded_wavs = nw;
      _aipl_loaded_wavs_cap = new_cap;
    }
  }
}

static int64_t _aipl_next_wav_id = 1;

AiplVal aipl_rt_loadSound(AiplVal p) {
  const char* path = (p.kind == AIPL_STR && p.s) ? p.s : "";
  if (!path[0]) {
    int slot = (int)(_aipl_next_wav_id++);
    _aipl_ensure_wav_slot(slot);
    _aipl_loaded_wavs[slot].active = 1; _aipl_loaded_wavs[slot].rate = 44100.0; _aipl_loaded_wavs[slot].len = 0;
    return aipl_ok(aipl_int(slot));
  }
  for (int i = 1; i < _aipl_loaded_wavs_cap; i++) {
    if (_aipl_loaded_wavs[i].active && strcmp(_aipl_loaded_wavs[i].path, path) == 0) return aipl_ok(aipl_int(i));
  }
  int slot = (int)(_aipl_next_wav_id++);
  _aipl_ensure_wav_slot(slot);
  if (_aipl_loaded_wavs[slot].pcm) { free(_aipl_loaded_wavs[slot].pcm); _aipl_loaded_wavs[slot].pcm = NULL; }
  _aipl_loaded_wavs[slot].active = 1;
  strncpy(_aipl_loaded_wavs[slot].path, path, 511);
  _aipl_loaded_wavs[slot].path[511] = 0;
  _aipl_loaded_wavs[slot].pcm = NULL;
  _aipl_loaded_wavs[slot].len = 0;
  _aipl_loaded_wavs[slot].rate = 44100.0;
  _aipl_loaded_wavs[slot].channels = 1;
  FILE* fp = fopen(path, "rb");
  if (!fp) return aipl_ok(aipl_int(slot));
  uint8_t riff_hdr[12];
  if (fread(riff_hdr, 1, 12, fp) == 12 && memcmp(riff_hdr, "RIFF", 4) == 0 && memcmp(riff_hdr + 8, "WAVE", 4) == 0) {
    uint32_t srate = 44100; uint16_t channels = 1; uint16_t bits = 16;
    long data_pos = 0; uint32_t data_bytes = 0; uint32_t chdr[2];
    while (fread(chdr, 4, 2, fp) == 2) {
      uint32_t cid = chdr[0]; uint32_t csz = chdr[1];
      if (memcmp(&cid, "fmt ", 4) == 0) {
        uint16_t fmt_code = 0;
        if (fread(&fmt_code, 2, 1, fp) == 1 && fread(&channels, 2, 1, fp) == 1 && fread(&srate, 4, 1, fp) == 1) {
          fseek(fp, 6, SEEK_CUR);
          if (fread(&bits, 2, 1, fp) == 1) {
            if (csz > 16) fseek(fp, (long)(csz - 16), SEEK_CUR);
          }
        } else { break; }
      } else if (memcmp(&cid, "data", 4) == 0) {
        data_pos = ftell(fp); data_bytes = csz; break;
      } else { fseek(fp, (long)csz, SEEK_CUR); }
    }
    if (srate < 4000 || srate > 192000) srate = 44100;
    if (data_pos > 0 && data_bytes > 0 && fseek(fp, data_pos, SEEK_SET) == 0) {
      if (bits == 16) {
        int64_t raw_samples = (int64_t)data_bytes / 2;
        if (channels >= 2) {
          int64_t frames = raw_samples / (int64_t)channels;
          int16_t* pcm = (int16_t*)malloc((size_t)frames * sizeof(int16_t));
          int16_t* raw_buf = (int16_t*)malloc((size_t)raw_samples * sizeof(int16_t));
          if (pcm && raw_buf) {
            size_t nr = fread(raw_buf, sizeof(int16_t), (size_t)raw_samples, fp);
            int64_t act_frames = (int64_t)nr / (int64_t)channels;
            for (int64_t fi = 0; fi < act_frames; fi++) {
              int32_t mix = 0;
              for (int c = 0; c < channels; c++) mix += raw_buf[fi * channels + c];
              pcm[fi] = (int16_t)(mix / channels);
            }
            _aipl_loaded_wavs[slot].pcm = pcm; _aipl_loaded_wavs[slot].len = act_frames;
          }
          if (raw_buf) free(raw_buf);
        } else {
          int16_t* pcm = (int16_t*)malloc((size_t)raw_samples * sizeof(int16_t));
          if (pcm) {
            size_t nr = fread(pcm, sizeof(int16_t), (size_t)raw_samples, fp);
            _aipl_loaded_wavs[slot].pcm = pcm; _aipl_loaded_wavs[slot].len = (int64_t)nr;
          }
        }
      } else if (bits == 8) {
        int64_t raw_samples = (int64_t)data_bytes;
        uint8_t* raw_buf = (uint8_t*)malloc((size_t)raw_samples);
        if (raw_buf) {
          size_t nr = fread(raw_buf, 1, (size_t)raw_samples, fp);
          int64_t frames = (channels >= 2) ? ((int64_t)nr / channels) : (int64_t)nr;
          int16_t* pcm = (int16_t*)malloc((size_t)frames * sizeof(int16_t));
          if (pcm) {
            for (int64_t fi = 0; fi < frames; fi++) {
              int32_t smp = (channels >= 2) ? (raw_buf[fi * channels] + raw_buf[fi * channels + 1]) / 2 : raw_buf[fi];
              pcm[fi] = (int16_t)((smp - 128) << 8);
            }
            _aipl_loaded_wavs[slot].pcm = pcm; _aipl_loaded_wavs[slot].len = frames;
          }
          free(raw_buf);
        }
      }
      _aipl_loaded_wavs[slot].rate = (double)srate;
      _aipl_loaded_wavs[slot].channels = (int)channels;
    }
  }
  fclose(fp);
  return aipl_ok(aipl_int(slot));
}

AiplVal aipl_rt_decodeSound(AiplVal d) {
  if (d.kind == AIPL_BYTES && d.ptr) {
    AiplBytes* ab = (AiplBytes*)d.ptr;
    if (ab->data && ab->len >= 12 && memcmp(ab->data, "RIFF", 4) == 0 && memcmp(ab->data + 8, "WAVE", 4) == 0) {
      int slot = (int)(_aipl_next_wav_id++);
      _aipl_ensure_wav_slot(slot);
      if (_aipl_loaded_wavs[slot].pcm) { free(_aipl_loaded_wavs[slot].pcm); _aipl_loaded_wavs[slot].pcm = NULL; }
      _aipl_loaded_wavs[slot].active = 1;
      _aipl_loaded_wavs[slot].rate = 44100.0;
      size_t pos = 12;
      while (pos + 8 <= (size_t)ab->len) {
        uint32_t cid = (uint32_t)ab->data[pos] | ((uint32_t)ab->data[pos+1]<<8) | ((uint32_t)ab->data[pos+2]<<16) | ((uint32_t)ab->data[pos+3]<<24);
        uint32_t csz = (uint32_t)ab->data[pos+4] | ((uint32_t)ab->data[pos+5]<<8) | ((uint32_t)ab->data[pos+6]<<16) | ((uint32_t)ab->data[pos+7]<<24);
        if (memcmp(&cid, "data", 4) == 0 && pos + 8 + csz <= (size_t)ab->len) {
          int64_t ns = (int64_t)csz / 2;
          int16_t* pcm = (int16_t*)malloc((size_t)ns * sizeof(int16_t));
          if (pcm) { memcpy(pcm, ab->data + pos + 8, (size_t)ns * sizeof(int16_t)); _aipl_loaded_wavs[slot].pcm = pcm; _aipl_loaded_wavs[slot].len = ns; }
          break;
        }
        pos += 8 + csz;
      }
      return aipl_ok(aipl_int(slot));
    }
  }
  int sid = (int)(_aipl_next_wav_id++);
  _aipl_ensure_wav_slot(sid);
  _aipl_loaded_wavs[sid].active = 1; _aipl_loaded_wavs[sid].rate = 44100.0; _aipl_loaded_wavs[sid].len = 0;
  return aipl_ok(aipl_int(sid));
}

AiplVal aipl_rt_getSoundDuration(AiplVal id) {
  int i = (int)((id.kind == AIPL_FLOAT) ? id.f : id.i);
  if (i >= 1 && i < _aipl_loaded_wavs_cap && _aipl_loaded_wavs && _aipl_loaded_wavs[i].active && _aipl_loaded_wavs[i].rate > 0.0) return aipl_float((double)_aipl_loaded_wavs[i].len / _aipl_loaded_wavs[i].rate);
  return aipl_float(0.5);
}

AiplVal aipl_rt_loadFont(AiplVal p) {
  _aipl_init_ttf();
  const char* path = (p.kind == AIPL_STR && p.s) ? p.s : "";
  if (!path[0] || strcmp(path, "sans") == 0 || strcmp(path, "default") == 0) return aipl_ok(aipl_int(0));
  if (strcmp(path, "bold") == 0) return aipl_ok(aipl_int(1));
  if (strcmp(path, "mono") == 0 || strcmp(path, "monospace") == 0) return aipl_ok(aipl_int(2));
  if (strcmp(path, "serif") == 0 || strcmp(path, "italic") == 0) return aipl_ok(aipl_int(3));
  if (_aipl_font_faces_cap < 8) _aipl_ensure_font_slot(8);
  for (int slot = 4; slot < _aipl_font_faces_cap; slot++) {
    if (_aipl_font_faces[slot] && _aipl_font_paths[slot][0] && strcmp(_aipl_font_paths[slot], path) == 0) {
      return aipl_ok(aipl_int(slot));
    }
  }
  int target_slot = -1;
  for (int slot = 4; slot < _aipl_font_faces_cap; slot++) {
    if (!_aipl_font_faces[slot]) { target_slot = slot; break; }
  }
  if (target_slot < 0) {
    target_slot = _aipl_font_faces_cap;
    _aipl_ensure_font_slot(target_slot);
  }
  if (_aipl_load_font_face_into_slot(target_slot, path)) {
    strncpy(_aipl_font_paths[target_slot], path, 511);
    _aipl_font_paths[target_slot][511] = 0;
    return aipl_ok(aipl_int(target_slot));
  }
  return aipl_err(aipl_str_lit("loadFont: unable to load font file"));
}

AiplVal aipl_rt_decodeFont(AiplVal d) { (void)d; static int _id = 2; return aipl_ok(aipl_int(_id++)); }

AiplVal aipl_rt_decodePngHeader(AiplVal d) { (void)d; AiplVal v = aipl_struct_new("PngHeader", 3, (const char*[]){ "width", "height", "channels" }, (AiplVal[]){ aipl_int(64), aipl_int(64), aipl_int(4) }); return aipl_ok(v); }

AiplVal aipl_rt_decodeWavHeader(AiplVal d) { (void)d; AiplVal v = aipl_struct_new("WavHeader", 3, (const char*[]){ "channels", "sampleRate", "bitsPerSample" }, (AiplVal[]){ aipl_int(1), aipl_int(8000), aipl_int(16) }); return aipl_ok(v); }

AiplVal aipl_rt_decodeFontMetrics(AiplVal d) { (void)d; AiplVal v = aipl_struct_new("FontMetrics", 2, (const char*[]){ "unitsPerEm", "ascender" }, (AiplVal[]){ aipl_int(1000), aipl_int(800) }); return aipl_ok(v); }

AiplVal aipl_rt_cacheFont(AiplVal mgr, AiplVal p, AiplVal id) { (void)p; (void)id; return mgr; }

AiplVal aipl_rt_cacheImage(AiplVal mgr, AiplVal p, AiplVal id) { aipl_array_push(aipl_member_get(mgr, "imagePaths"), p); aipl_array_push(aipl_member_get(mgr, "imageIds"), id); return mgr; }

AiplVal aipl_rt_cacheSound(AiplVal mgr, AiplVal p, AiplVal id) { aipl_array_push(aipl_member_get(mgr, "soundPaths"), p); aipl_array_push(aipl_member_get(mgr, "soundIds"), id); return mgr; }

AiplVal aipl_rt_getCachedFont(AiplVal mgr, AiplVal p) { (void)mgr; (void)p; return aipl_int(1); }

AiplVal aipl_rt_getCachedImage(AiplVal mgr, AiplVal p) {
  AiplVal paths = aipl_member_get(mgr, "imagePaths"); AiplVal ids = aipl_member_get(mgr, "imageIds");
  if (paths.kind == AIPL_ARRAY && paths.ptr) {
    AiplArray* pa = (AiplArray*)paths.ptr; AiplArray* ia = (ids.kind == AIPL_ARRAY && ids.ptr) ? (AiplArray*)ids.ptr : NULL;
    if (pa->len == 0) return aipl_int(100);
    for (int64_t i = 0; i < pa->len; i++) {
      if (aipl_truthy(aipl_eq(pa->data[i], p))) { if (ia && i < ia->len) return ia->data[i]; return aipl_int(0); }
    }
  }
  return aipl_int(100);
}

AiplVal aipl_rt_getCachedSound(AiplVal mgr, AiplVal p) {
  AiplVal paths = aipl_member_get(mgr, "soundPaths"); AiplVal ids = aipl_member_get(mgr, "soundIds");
  if (paths.kind == AIPL_ARRAY && paths.ptr) {
    AiplArray* pa = (AiplArray*)paths.ptr; AiplArray* ia = (ids.kind == AIPL_ARRAY && ids.ptr) ? (AiplArray*)ids.ptr : NULL;
    if (pa->len == 0) return aipl_int(20);
    for (int64_t i = 0; i < pa->len; i++) {
      if (aipl_truthy(aipl_eq(pa->data[i], p))) { if (ia && i < ia->len) return ia->data[i]; return aipl_int(0); }
    }
  }
  return aipl_int(20);
}

AiplVal aipl_rt_createAssetManager(void) {
  return aipl_struct_new("AssetManager", 4, (const char*[]){ "imagePaths", "imageIds", "soundPaths", "soundIds" }, (AiplVal[]){ aipl_array_new(NULL, 0), aipl_array_new(NULL, 0), aipl_array_new(NULL, 0), aipl_array_new(NULL, 0) });
}

AiplVal aipl_rt_createSpriteSheet(AiplVal imgId, AiplVal fw, AiplVal fh, AiplVal cols, AiplVal tot) {
  return aipl_struct_new("SpriteSheet", 5, (const char*[]){ "imageId", "frameWidth", "frameHeight", "columns", "totalFrames" }, (AiplVal[]){ imgId, fw, fh, cols, tot });
}

AiplVal aipl_rt_createAnimationClip(AiplVal start, AiplVal count, AiplVal fps, AiplVal loop) {
  return aipl_struct_new("AnimationClip", 4, (const char*[]){ "startFrame", "frameCount", "fps", "loopClip" }, (AiplVal[]){ start, count, fps, loop });
}

AiplVal aipl_rt_sampleAnimationFrame(AiplVal clip, AiplVal elapsed) {
  AiplVal sf = aipl_member_get(clip, "startFrame"); AiplVal fc = aipl_member_get(clip, "frameCount");
  if (fc.i <= 0) { return sf; }
  int64_t idx = (int64_t)(aipl_to_c_double(elapsed) * 6.0) % fc.i; return aipl_int(sf.i + idx);
}

AiplVal aipl_rt_drawSpriteFrame(AiplVal sheet, AiplVal frame, AiplVal dx, AiplVal dy, AiplVal dw, AiplVal dh) {
  AiplVal imgId = aipl_member_get(sheet, "imageId");
  AiplVal fw = aipl_member_get(sheet, "frameWidth");
  AiplVal fh = aipl_member_get(sheet, "frameHeight");
  AiplVal cols = aipl_member_get(sheet, "columns");
  int f = (int)frame.i; int c = (int)cols.i; if (c <= 0) c = 1;
  int sx = (f % c) * (int)fw.i; int sy = (f / c) * (int)fh.i;
  return aipl_rt_drawImageSub(imgId, aipl_int(sx), aipl_int(sy), fw, fh, dx, dy, dw, dh, aipl_nil());
}

AiplVal aipl_rt_drawAnimatedSprite(AiplVal sheet, AiplVal clip, AiplVal elapsed, AiplVal dx, AiplVal dy, AiplVal dw, AiplVal dh) {
  AiplVal frame = aipl_rt_sampleAnimationFrame(clip, elapsed);
  return aipl_rt_drawSpriteFrame(sheet, frame, dx, dy, dw, dh);
}

_AiplAudioVoice* _aipl_voices = NULL;
int _aipl_voices_cap = 0;
void _aipl_ensure_voices_cap(int min_cap) {
  if (min_cap <= _aipl_voices_cap) return;
  int new_cap = (_aipl_voices_cap == 0) ? 32 : _aipl_voices_cap * 2;
  while (new_cap < min_cap) new_cap *= 2;
  _AiplAudioVoice* nv = (_AiplAudioVoice*)realloc(_aipl_voices, (size_t)new_cap * sizeof(_AiplAudioVoice));
  if (nv) {
    memset(nv + _aipl_voices_cap, 0, (size_t)(new_cap - _aipl_voices_cap) * sizeof(_AiplAudioVoice));
    _aipl_voices = nv;
    _aipl_voices_cap = new_cap;
  }
}
int _aipl_next_voice_id = 1;
pthread_mutex_t _aipl_audio_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t _aipl_audio_thread;
volatile int _aipl_audio_thread_running = 0;
double _aipl_audio_master_volume = 1.0;
double _aipl_audio_current_energy = 0.0;
double _aipl_audio_spectrum[16] = { 0 };
double _aipl_audio_time_sec = 0.0;
int16_t* _aipl_wav_buffer = NULL;
size_t _aipl_wav_cap = 0;
size_t _aipl_wav_len = 0;
void _aipl_audio_mix_samples(int16_t* out_stereo, int frames) {
  if (!out_stereo || frames <= 0) return;
  memset(out_stereo, 0, (size_t)frames * 2 * sizeof(int16_t));
  pthread_mutex_lock(&_aipl_audio_mutex);
  double sum_sq = 0.0;
  double band_acc[16] = { 0 };
  for (int f = 0; f < frames; f++) {
    double left_acc = 0.0;
    double right_acc = 0.0;
    for (int vi = 0; vi < _aipl_voices_cap; vi++) {
      _AiplAudioVoice* v = &_aipl_voices[vi];
      if (!v->active) continue;
      double env = 1.0;
      if (v->state == 0) {
        if (v->attack_time > 0.0001) {
          double t = v->age / v->attack_time;
          if (t >= 1.0) { v->state = 1; env = 1.0; }
          else { env = t * (2.0 - t); }
        } else { v->state = 1; env = 1.0; }
      } else if (v->state == 1) {
        if (v->decay_time > 0.0001) {
          double dp = (v->age - v->attack_time) / v->decay_time;
          if (dp >= 1.0) { v->state = 2; env = v->sustain_level; }
          else {
            double curve = exp(-3.5 * dp);
            env = v->sustain_level + (1.0 - v->sustain_level) * curve;
          }
        } else { v->state = 2; env = v->sustain_level; }
      } else if (v->state == 2) {
        env = v->sustain_level;
        if (v->duration > 0.0 && v->age >= (v->duration - v->release_time)) v->state = 3;
      } else if (v->state == 3) {
        if (v->release_time > 0.0001) {
          double rel_start = (v->duration > 0.0) ? (v->duration - v->release_time) : v->age;
          double rp = (v->age - rel_start) / v->release_time;
          if (rp >= 1.0) { env = 0.0; v->active = 0; v->state = 4; }
          else {
            double curve = (1.0 - rp) * (1.0 - rp);
            env = v->sustain_level * curve;
          }
        } else { env = 0.0; v->active = 0; v->state = 4; }
      }
      if (v->duration > 0.0 && v->age >= v->duration) { v->active = 0; v->state = 4; env = 0.0; }
      if (!v->active || env <= 0.0) { v->age += 1.0 / 44100.0; continue; }

      double s_raw = 0.0;
      double ph2pi = v->phase * 6.283185307179586;
      if (v->wave_type == 0) {
        s_raw = sin(ph2pi) + 0.12 * sin(ph2pi * 2.0);
      } else if (v->wave_type == 1) {
        double sq = (v->phase < 0.5) ? 0.65 : -0.65;
        double sub = 0.25 * sin(ph2pi);
        s_raw = sq + sub;
      } else if (v->wave_type == 2) {
        s_raw = (4.0 * fabs(v->phase - 0.5) - 1.0) * 0.85 + 0.15 * sin(ph2pi * 3.0);
      } else if (v->wave_type == 3) {
        double saw1 = 2.0 * v->phase - 1.0;
        double p2 = v->phase * 1.006 + v->age * 1.8;
        p2 -= floor(p2);
        double saw2 = 2.0 * p2 - 1.0;
        s_raw = (saw1 + saw2) * 0.45;
      } else if (v->wave_type == 4) {
        s_raw = ((double)(rand() % 20000) - 10000.0) / 10000.0;
      } else if (v->wave_type == 5) {
        int pidx = (int)v->pcm_pos;
        if (pidx >= 0 && pidx < v->pcm_len && v->pcm_data) {
          s_raw = (double)v->pcm_data[pidx] / 32768.0;
          v->pcm_pos += v->pcm_speed;
          if (v->pcm_pos >= (double)v->pcm_len) {
            if (v->loop) v->pcm_pos = 0.0;
            else { v->active = 0; v->state = 4; }
          }
        } else { v->active = 0; v->state = 4; }
      } else if (v->wave_type == 6) {
        double det1 = v->phase * 1.004 + v->age * 0.9;
        double det2 = v->phase * 0.996 - v->age * 0.7;
        det1 -= floor(det1);
        det2 -= floor(det2);
        s_raw = 0.45 * sin(ph2pi) + 0.28 * (2.0 * det1 - 1.0) + 0.28 * (2.0 * det2 - 1.0);
      } else if (v->wave_type == 7) {
        double mod_idx = 2.2 * exp(-v->age * 5.5);
        double mod = sin(ph2pi * 2.0) * mod_idx;
        s_raw = 0.75 * sin(ph2pi + mod) + 0.25 * sin(ph2pi * 3.0) * exp(-v->age * 8.0);
      } else if (v->wave_type == 8) {
        double damp = exp(-v->age * 4.5);
        s_raw = 0.60 * sin(ph2pi) + 0.25 * sin(ph2pi * 2.0) * damp + 0.12 * sin(ph2pi * 3.0) * damp * damp + 0.06 * sin(ph2pi * 4.0) * damp * damp;
      }

      if (v->wave_type == 1 || v->wave_type == 3 || v->wave_type == 4 || v->wave_type == 6) {
        double cutoff = (v->wave_type == 6) ? 0.14 : ((v->wave_type == 4) ? 0.25 : 0.28);
        double lp = v->lpf_state + cutoff * (s_raw - v->lpf_state);
        v->lpf_state = lp;
        s_raw = lp;
      }

      if (v->wave_type != 5) {
        double dphi = v->freq / 44100.0;
        v->phase += dphi;
        if (v->phase >= 1.0) v->phase -= floor(v->phase);
        if (v->freq_step != 0.0) {
          v->freq += v->freq_step;
          if ((v->freq_step > 0 && v->freq >= v->freq_target) || (v->freq_step < 0 && v->freq <= v->freq_target)) {
            v->freq = v->freq_target;
            v->freq_step = 0.0;
          }
        }
      }
      v->age += 1.0 / 44100.0;
      double voice_val = s_raw * env * v->volume;
      double chorus_lfo = 0.06 * sin(v->age * 3.2 + (double)(vi & 7) * 0.8);
      double eff_pan = v->pan + chorus_lfo;
      if (eff_pan < -1.0) eff_pan = -1.0;
      if (eff_pan > 1.0) eff_pan = 1.0;
      double pan_l = (eff_pan <= 0.0) ? 1.0 : (1.0 - eff_pan);
      double pan_r = (eff_pan >= 0.0) ? 1.0 : (1.0 + eff_pan);
      left_acc += voice_val * pan_l;
      right_acc += voice_val * pan_r;
      int band = (int)(log2(fmax(20.0, v->freq) / 20.0) * 1.6);
      if (band < 0) band = 0; if (band > 15) band = 15;
      band_acc[band] += fabs(voice_val);
    }
    double master_l = tanh(left_acc * _aipl_audio_master_volume * 0.85);
    double master_r = tanh(right_acc * _aipl_audio_master_volume * 0.85);
    int16_t s_i16_l = (int16_t)(master_l * 32760.0);
    int16_t s_i16_r = (int16_t)(master_r * 32760.0);
    out_stereo[f * 2]     = s_i16_l;
    out_stereo[f * 2 + 1] = s_i16_r;
    sum_sq += (double)s_i16_l * (double)s_i16_l + (double)s_i16_r * (double)s_i16_r;
  }
  double rms = sqrt(sum_sq / (double)(frames * 2)) / 32768.0;
  _aipl_audio_current_energy = _aipl_audio_current_energy * 0.7 + rms * 0.3;
  for (int b = 0; b < 16; b++) {
    double b_val = (band_acc[b] / (double)frames);
    _aipl_audio_spectrum[b] = _aipl_audio_spectrum[b] * 0.8 + b_val * 0.2;
  }
  _aipl_audio_time_sec += (double)frames / 44100.0;

  const char* wav_env = getenv("AIPL_AUDIO_WAV_PATH");
  if (wav_env && wav_env[0]) {
    size_t needed = _aipl_wav_len + (size_t)frames;
    if (needed > _aipl_wav_cap) {
      size_t new_cap = (_aipl_wav_cap == 0) ? 44100 * 5 : _aipl_wav_cap * 2;
      if (new_cap < needed) new_cap = needed + 44100;
      int16_t* new_buf = (int16_t*)realloc(_aipl_wav_buffer, new_cap * 2 * sizeof(int16_t));
      if (new_buf) { _aipl_wav_buffer = new_buf; _aipl_wav_cap = new_cap; }
    }
    if (_aipl_wav_buffer && _aipl_wav_len + (size_t)frames <= _aipl_wav_cap) {
      memcpy(&_aipl_wav_buffer[_aipl_wav_len * 2], out_stereo, (size_t)frames * 2 * sizeof(int16_t));
      _aipl_wav_len += (size_t)frames;
    }
  }
  pthread_mutex_unlock(&_aipl_audio_mutex);
}

void _aipl_stop_and_cleanup_audio(void) {
  if (_aipl_audio_thread_running) {
    _aipl_audio_thread_running = 0;
    pthread_join(_aipl_audio_thread, NULL);
    _aipl_audio_thread_active = 0;
  }
  const char* wav_path = getenv("AIPL_AUDIO_WAV_PATH");
  if (wav_path && wav_path[0] && _aipl_wav_len == 0) {
    int16_t flush_pcm[1024 * 2];
    for (int _fi = 0; _fi < 4; _fi++) {
      _aipl_audio_mix_samples(flush_pcm, 1024);
    }
  }
  if (wav_path && wav_path[0] && _aipl_wav_buffer && _aipl_wav_len > 0) {
    FILE* fp = fopen(wav_path, "wb");
    if (fp) {
      uint32_t data_bytes = (uint32_t)(_aipl_wav_len * 2 * sizeof(int16_t));
      uint32_t riff_size = 36 + data_bytes;
      uint16_t num_channels = 2;
      uint32_t sample_rate = 44100;
      uint16_t bits_per_sample = 16;
      uint32_t byte_rate = sample_rate * num_channels * (bits_per_sample / 8);
      uint16_t block_align = num_channels * (bits_per_sample / 8);
      uint16_t audio_format = 1;
      uint32_t subchunk1_size = 16;
      fwrite("RIFF", 1, 4, fp);
      fwrite(&riff_size, 4, 1, fp);
      fwrite("WAVE", 1, 4, fp);
      fwrite("fmt ", 1, 4, fp);
      fwrite(&subchunk1_size, 4, 1, fp);
      fwrite(&audio_format, 2, 1, fp);
      fwrite(&num_channels, 2, 1, fp);
      fwrite(&sample_rate, 4, 1, fp);
      fwrite(&byte_rate, 4, 1, fp);
      fwrite(&block_align, 2, 1, fp);
      fwrite(&bits_per_sample, 2, 1, fp);
      fwrite("data", 1, 4, fp);
      fwrite(&data_bytes, 4, 1, fp);
      fwrite(_aipl_wav_buffer, 1, data_bytes, fp);
      fclose(fp);
    }
  }
  if (_aipl_wav_buffer) { free(_aipl_wav_buffer); _aipl_wav_buffer = NULL; _aipl_wav_cap = 0; _aipl_wav_len = 0; }
  if (_aipl_voices) {
    for (int vi = 0; vi < _aipl_voices_cap; vi++) {
      if (_aipl_voices[vi].pcm_data) { free(_aipl_voices[vi].pcm_data); _aipl_voices[vi].pcm_data = NULL; }
      _aipl_voices[vi].active = 0;
    }
  }
}

/* ============================================================================
 * Android NDK NativeActivity Surface Blitter & AAudio PCM Stream
 * Step 21.2: ANativeWindow_setBuffersGeometry, BlitScanlines, AAudio Open/Callback
 * ============================================================================ */
#ifdef __ANDROID__
#include <android/native_window.h>
#include <aaudio/AAudio.h>

int aipl_rt_android_set_buffers_geometry(ANativeWindow* window, int width, int height, int format) {
  if (!window || width <= 0 || height <= 0 || format != 1) {
    return -22; /* -EINVAL */
  }
  return ANativeWindow_setBuffersGeometry(window, width, height, WINDOW_FORMAT_RGBA_8888);
}

int aipl_rt_android_blit_rgba_scanlines(ANativeWindow* window, const uint32_t* srcPixels, int width, int height) {
  if (!window || !srcPixels || width <= 0 || height <= 0) return -22;
  ANativeWindow_Buffer buffer;
  if (ANativeWindow_lock(window, &buffer, NULL) < 0) return -1;
  uint32_t* dst = (uint32_t*)buffer.bits;
  if (!dst) {
    ANativeWindow_unlockAndPost(window);
    return -1;
  }
  int dstStride = buffer.stride;
  int copyHeight = (buffer.height > 0 && buffer.height < height) ? buffer.height : height;
  int copyWidth = (buffer.width > 0 && buffer.width < width) ? buffer.width : width;
  if (dstStride < copyWidth) copyWidth = dstStride;
  for (int y = 0; y < copyHeight; y++) {
    const uint32_t* srcRow = srcPixels + y * width;
    uint32_t* dstRow = dst + y * dstStride;
    memcpy(dstRow, srcRow, (size_t)copyWidth * sizeof(uint32_t));
    if (dstStride > copyWidth) {
      memset(dstRow + copyWidth, 0, (size_t)(dstStride - copyWidth) * sizeof(uint32_t));
    }
  }
  ANativeWindow_unlockAndPost(window);
  return 0;
}

typedef struct {
  AAudioStream* stream;
  int sampleRate;
  int channelCount;
  int framesPerBurst;
  int active;
} AiplAndroidAAudioState;

static aaudio_data_callback_result_t _aipl_aaudio_data_callback(
    AAudioStream* stream,
    void* userData,
    void* audioData,
    int32_t numFrames) {
  (void)stream;
  AiplAndroidAAudioState* st = (AiplAndroidAAudioState*)userData;
  if (!st || !st->active || numFrames <= 0) {
    return AAUDIO_CALLBACK_RESULT_STOP;
  }
  int32_t totalSamples = numFrames * st->channelCount;
  int16_t* outPcm = (int16_t*)audioData;
  memset(outPcm, 0, (size_t)totalSamples * sizeof(int16_t));
  return AAUDIO_CALLBACK_RESULT_CONTINUE;
}

AAudioStream* aipl_rt_android_aaudio_open_stream(int sampleRate, int channelCount, int framesPerBurst, void* userData) {
  if (sampleRate < 8000 || sampleRate > 96000 || (channelCount != 1 && channelCount != 2) || framesPerBurst < 32) {
    return NULL;
  }
  AAudioStreamBuilder* builder = NULL;
  if (AAudio_createStreamBuilder(&builder) != AAUDIO_OK || !builder) return NULL;
  AAudioStreamBuilder_setSampleRate(builder, sampleRate);
  AAudioStreamBuilder_setChannelCount(builder, channelCount);
  AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_I16);
  AAudioStreamBuilder_setPerformanceMode(builder, AAUDIO_PERFORMANCE_MODE_LOW_LATENCY);
  AAudioStreamBuilder_setSharingMode(builder, AAUDIO_SHARING_MODE_SHARED);
  AAudioStreamBuilder_setBufferCapacityInFrames(builder, framesPerBurst * 2);
  AAudioStreamBuilder_setDataCallback(builder, _aipl_aaudio_data_callback, userData);
  AAudioStream* stream = NULL;
  aaudio_result_t res = AAudioStreamBuilder_openStream(builder, &stream);
  AAudioStreamBuilder_delete(builder);
  if (res != AAUDIO_OK) return NULL;
  return stream;
}
#endif

#endif // AIPL_ENABLE_GUI_AUDIO
