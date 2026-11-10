/* AIPL C99 runtime module: rt_crypto_data.c (Phase 18 split modular runtime). */
#include "aipl_runtime.h"

int g_aipl_cmd_seq = 0;
static const uint32_t aipl_sha256_k[64] = {
  0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
  0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
  0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
  0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
  0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
  0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
  0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
  0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};
void aipl_sha256_raw(const uint8_t* data, size_t len, uint8_t out[32]) {
  uint32_t h[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
  size_t new_len = ((((len + 8) / 64) + 1) * 64);
  uint8_t* msg = (uint8_t*)calloc(new_len, 1);
  if (len > 0) memcpy(msg, data, len);
  msg[len] = 0x80; uint64_t bits = (uint64_t)len * 8;
  for (int i = 0; i < 8; i++) { msg[new_len - 1 - i] = (uint8_t)((bits >> (i * 8)) & 0xFF); }
  for (size_t chunk = 0; chunk < new_len; chunk += 64) {
    uint32_t w[64];
    for (int i = 0; i < 16; i++) {
      size_t o = chunk + i * 4;
      w[i] = ((uint32_t)msg[o] << 24) | ((uint32_t)msg[o + 1] << 16) | ((uint32_t)msg[o + 2] << 8) | (uint32_t)msg[o + 3];
    }
    for (int i = 16; i < 64; i++) { w[i] = w[i - 16] + AIPL_sig0(w[i - 15]) + w[i - 7] + AIPL_sig1(w[i - 2]); }
    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h_val = h[7];
    for (int i = 0; i < 64; i++) {
      uint32_t t1 = h_val + AIPL_SIG1(e) + AIPL_CH(e, f, g) + aipl_sha256_k[i] + w[i];
      uint32_t t2 = AIPL_SIG0(a) + AIPL_MAJ(a, b, c);
      h_val = g; g = f; f = e; e = d + t1; d = c; c = b; b = a; a = t1 + t2;
    }
    h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e; h[5] += f; h[6] += g; h[7] += h_val;
  }
  free(msg);
  for (int i = 0; i < 8; i++) {
    out[i * 4] = (uint8_t)((h[i] >> 24) & 0xFF);
    out[i * 4 + 1] = (uint8_t)((h[i] >> 16) & 0xFF);
    out[i * 4 + 2] = (uint8_t)((h[i] >> 8) & 0xFF);
    out[i * 4 + 3] = (uint8_t)(h[i] & 0xFF);
  }
}

AiplVal aipl_rt_sha256(AiplVal data_val) {
  const uint8_t* data = NULL; size_t len = 0;
  if (data_val.kind == AIPL_BYTES && data_val.ptr) {
    AiplBytes* b = (AiplBytes*)data_val.ptr; data = b->data; len = (size_t)b->len;
  } else if (data_val.kind == AIPL_STR) {
    data = (const uint8_t*)(data_val.s ? data_val.s : ""); len = aipl_str_byte_len(data_val);
  } else {
    AiplVal s = aipl_to_str(data_val); data = (const uint8_t*)(s.s ? s.s : ""); len = aipl_str_byte_len(s);
  }
  uint8_t raw[32]; aipl_sha256_raw(data, len, raw);
  char outHex[65];
  for (int i = 0; i < 32; i++) { sprintf(outHex + i * 2, "%02x", raw[i]); }
  outHex[64] = 0; return aipl_str(outHex);
}

AiplVal aipl_rt_sha256Bytes(AiplVal data_val) {
  if (data_val.kind == AIPL_STR) {
    return aipl_rt_sha256(data_val);
  }
  const uint8_t* data = NULL; size_t len = 0;
  if (data_val.kind == AIPL_BYTES && data_val.ptr) {
    AiplBytes* b = (AiplBytes*)data_val.ptr; data = b->data; len = (size_t)b->len;
  } else {
    AiplVal s = aipl_to_str(data_val); data = (const uint8_t*)(s.s ? s.s : ""); len = aipl_str_byte_len(s);
  }
  AiplVal res = aipl_bytes_new(32); AiplBytes* rb = (AiplBytes*)res.ptr;
  aipl_sha256_raw(data, len, rb->data); return res;
}

AiplVal aipl_rt_crc32(AiplVal data_val) {
  const uint8_t* p = NULL; size_t len = 0;
  if (data_val.kind == AIPL_BYTES && data_val.ptr) {
    AiplBytes* b = (AiplBytes*)data_val.ptr; p = b->data; len = (size_t)b->len;
  } else if (data_val.kind == AIPL_STR) {
    p = (const uint8_t*)(data_val.s ? data_val.s : ""); len = aipl_str_byte_len(data_val);
  } else {
    AiplVal s = aipl_to_str(data_val); p = (const uint8_t*)(s.s ? s.s : ""); len = aipl_str_byte_len(s);
  }
  uint32_t crc = 0xFFFFFFFFu;
  for (size_t i = 0; i < len; i++) {
    crc ^= p[i];
    for (int j = 0; j < 8; j++) { if (crc & 1) crc = (crc >> 1) ^ 0xEDB88320u; else crc = crc >> 1; }
  }
  crc ^= 0xFFFFFFFFu; return aipl_int((int64_t)crc);
}

static const uint32_t aipl_md5_k[64] = {
  0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
  0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
  0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
  0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
  0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
  0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
  0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
  0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};
static const uint32_t aipl_md5_s[64] = {
  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};
void aipl_md5_calc(const uint8_t* data, size_t len, char out[33]) {
  uint32_t h0 = 0x67452301, h1 = 0xefcdab89, h2 = 0x98badcfe, h3 = 0x10325476;
  size_t new_len = ((((len + 8) / 64) + 1) * 64);
  uint8_t* msg = (uint8_t*)calloc(new_len, 1);
  if (len > 0) memcpy(msg, data, len);
  msg[len] = 0x80; uint64_t bits = (uint64_t)len * 8;
  for (int i = 0; i < 8; i++) msg[new_len - 8 + i] = (uint8_t)((bits >> (i * 8)) & 0xFF);
  for (size_t chunk = 0; chunk < new_len; chunk += 64) {
    uint32_t m[16];
    for (int i = 0; i < 16; i++) {
      size_t o = chunk + i * 4;
      m[i] = (uint32_t)msg[o] | ((uint32_t)msg[o + 1] << 8) | ((uint32_t)msg[o + 2] << 16) | ((uint32_t)msg[o + 3] << 24);
    }
    uint32_t a = h0, b = h1, c = h2, d = h3;
    for (int i = 0; i < 64; i++) {
      uint32_t f, g;
      if (i < 16) { f = AIPL_MD5_F(b, c, d); g = i; }
      else if (i < 32) { f = AIPL_MD5_G(b, c, d); g = (5 * i + 1) % 16; }
      else if (i < 48) { f = AIPL_MD5_H(b, c, d); g = (3 * i + 5) % 16; }
      else { f = AIPL_MD5_I(b, c, d); g = (7 * i) % 16; }
      uint32_t temp = d; d = c; c = b;
      b = b + AIPL_ROTL((a + f + aipl_md5_k[i] + m[g]), aipl_md5_s[i]); a = temp;
    }
    h0 += a; h1 += b; h2 += c; h3 += d;
  }
  free(msg); uint8_t digest[16];
  for (int i = 0; i < 4; i++) {
    digest[i] = (uint8_t)((h0 >> (i * 8)) & 0xFF);
    digest[i + 4] = (uint8_t)((h1 >> (i * 8)) & 0xFF);
    digest[i + 8] = (uint8_t)((h2 >> (i * 8)) & 0xFF);
    digest[i + 12] = (uint8_t)((h3 >> (i * 8)) & 0xFF);
  }
  for (int i = 0; i < 16; i++) sprintf(out + i * 2, "%02x", digest[i]);
  out[32] = 0;
}

AiplVal aipl_rt_md5(AiplVal data_val) {
  const uint8_t* p = (data_val.kind == AIPL_BYTES && data_val.ptr) ? ((AiplBytes*)data_val.ptr)->data : (const uint8_t*)(data_val.s ? data_val.s : "");
  size_t len = (data_val.kind == AIPL_BYTES && data_val.ptr) ? (size_t)((AiplBytes*)data_val.ptr)->len : aipl_str_byte_len(data_val);
  char outHex[33]; aipl_md5_calc(p, len, outHex); return aipl_str(outHex);
}

void aipl_sha1_calc(const uint8_t* data, size_t len, char out[41]) {
  uint32_t h[5] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };
  size_t new_len = ((((len + 8) / 64) + 1) * 64);
  uint8_t* msg = (uint8_t*)calloc(new_len, 1);
  if (len > 0) memcpy(msg, data, len);
  msg[len] = 0x80; uint64_t bits = (uint64_t)len * 8;
  for (int i = 0; i < 8; i++) msg[new_len - 1 - i] = (uint8_t)((bits >> (i * 8)) & 0xFF);
  for (size_t chunk = 0; chunk < new_len; chunk += 64) {
    uint32_t w[80];
    for (int i = 0; i < 16; i++) {
      size_t o = chunk + i * 4;
      w[i] = ((uint32_t)msg[o] << 24) | ((uint32_t)msg[o + 1] << 16) | ((uint32_t)msg[o + 2] << 8) | (uint32_t)msg[o + 3];
    }
    for (int i = 16; i < 80; i++) w[i] = AIPL_ROTL(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];
    for (int i = 0; i < 80; i++) {
      uint32_t f, k;
      if (i < 20) { f = (b & c) | ((~b) & d); k = 0x5A827999; }
      else if (i < 40) { f = b ^ c ^ d; k = 0x6ED9EBA1; }
      else if (i < 60) { f = (b & c) | (b & d) | (c & d); k = 0x8F1BBCDC; }
      else { f = b ^ c ^ d; k = 0xCA62C1D6; }
      uint32_t temp = AIPL_ROTL(a, 5) + f + e + k + w[i];
      e = d; d = c; c = AIPL_ROTL(b, 30); b = a; a = temp;
    }
    h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e;
  }
  free(msg);
  for (int i = 0; i < 5; i++) sprintf(out + i * 8, "%08x", h[i]);
  out[40] = 0;
}

AiplVal aipl_rt_sha1(AiplVal data_val) {
  const uint8_t* p = (data_val.kind == AIPL_BYTES && data_val.ptr) ? ((AiplBytes*)data_val.ptr)->data : (const uint8_t*)(data_val.s ? data_val.s : "");
  size_t len = (data_val.kind == AIPL_BYTES && data_val.ptr) ? (size_t)((AiplBytes*)data_val.ptr)->len : aipl_str_byte_len(data_val);
  char outHex[41]; aipl_sha1_calc(p, len, outHex); return aipl_str(outHex);
}

void aipl_hmac_sha256_raw(const uint8_t* key, size_t key_len, const uint8_t* data, size_t data_len, uint8_t out[32]) {
  uint8_t k[64]; memset(k, 0, 64);
  if (key_len > 64) { aipl_sha256_raw(key, key_len, k); }
  else if (key_len > 0) { memcpy(k, key, key_len); }
  size_t ipad_len = 64 + data_len; uint8_t* ipad = (uint8_t*)malloc(ipad_len);
  for (int i = 0; i < 64; i++) ipad[i] = k[i] ^ 0x36;
  if (data_len > 0) memcpy(ipad + 64, data, data_len);
  uint8_t inner[32]; aipl_sha256_raw(ipad, ipad_len, inner); free(ipad);
  uint8_t opad[96];
  for (int i = 0; i < 64; i++) opad[i] = k[i] ^ 0x5c;
  memcpy(opad + 64, inner, 32);
  aipl_sha256_raw(opad, 96, out);
}

AiplVal aipl_rt_hmacSha256(AiplVal key_val, AiplVal msg_val) {
  const uint8_t* k = (key_val.kind == AIPL_BYTES && key_val.ptr) ? ((AiplBytes*)key_val.ptr)->data : (const uint8_t*)(key_val.s ? key_val.s : "");
  size_t klen = (key_val.kind == AIPL_BYTES && key_val.ptr) ? (size_t)((AiplBytes*)key_val.ptr)->len : aipl_str_byte_len(key_val);
  const uint8_t* m = (msg_val.kind == AIPL_BYTES && msg_val.ptr) ? ((AiplBytes*)msg_val.ptr)->data : (const uint8_t*)(msg_val.s ? msg_val.s : "");
  size_t mlen = (msg_val.kind == AIPL_BYTES && msg_val.ptr) ? (size_t)((AiplBytes*)msg_val.ptr)->len : aipl_str_byte_len(msg_val);
  uint8_t mac[32]; aipl_hmac_sha256_raw(k, klen, m, mlen, mac);
  AiplVal res = aipl_bytes_new(32); AiplBytes* rb = (AiplBytes*)res.ptr;
  memcpy(rb->data, mac, 32); return res;
}

AiplVal aipl_rt_hmacSha256Hex(AiplVal key_val, AiplVal msg_val) {
  const uint8_t* k = (key_val.kind == AIPL_BYTES && key_val.ptr) ? ((AiplBytes*)key_val.ptr)->data : (const uint8_t*)(key_val.s ? key_val.s : "");
  size_t klen = (key_val.kind == AIPL_BYTES && key_val.ptr) ? (size_t)((AiplBytes*)key_val.ptr)->len : aipl_str_byte_len(key_val);
  const uint8_t* m = (msg_val.kind == AIPL_BYTES && msg_val.ptr) ? ((AiplBytes*)msg_val.ptr)->data : (const uint8_t*)(msg_val.s ? msg_val.s : "");
  size_t mlen = (msg_val.kind == AIPL_BYTES && msg_val.ptr) ? (size_t)((AiplBytes*)msg_val.ptr)->len : aipl_str_byte_len(msg_val);
  uint8_t mac[32]; aipl_hmac_sha256_raw(k, klen, m, mlen, mac);
  char outHex[65]; for (int i = 0; i < 32; i++) sprintf(outHex + i * 2, "%02x", mac[i]);
  outHex[64] = 0; return aipl_str(outHex);
}

AiplVal aipl_rt_constantTimeEq(AiplVal a_val, AiplVal b_val) {
  const uint8_t* pa = (a_val.kind == AIPL_BYTES && a_val.ptr) ? ((AiplBytes*)a_val.ptr)->data : (const uint8_t*)(a_val.s ? a_val.s : "");
  size_t la = (a_val.kind == AIPL_BYTES && a_val.ptr) ? (size_t)((AiplBytes*)a_val.ptr)->len : aipl_str_byte_len(a_val);
  const uint8_t* pb = (b_val.kind == AIPL_BYTES && b_val.ptr) ? ((AiplBytes*)b_val.ptr)->data : (const uint8_t*)(b_val.s ? b_val.s : "");
  size_t lb = (b_val.kind == AIPL_BYTES && b_val.ptr) ? (size_t)((AiplBytes*)b_val.ptr)->len : aipl_str_byte_len(b_val);
  if (la != lb) return aipl_bool(false);
  uint8_t diff = 0; for (size_t i = 0; i < la; i++) diff |= (pa[i] ^ pb[i]); return aipl_bool(diff == 0);
}

void aipl_pbkdf2_hmac_sha256(const uint8_t* pass, size_t pass_len, const uint8_t* salt, size_t salt_len, size_t iterations, size_t out_len, uint8_t* out) {
  size_t iters = iterations > 0 ? iterations : 1; size_t blocks = (out_len + 31) / 32;
  uint8_t* salt_block = (uint8_t*)malloc(salt_len + 4); memcpy(salt_block, salt, salt_len);
  size_t offset = 0;
  for (uint32_t block_idx = 1; block_idx <= (uint32_t)blocks; block_idx++) {
    salt_block[salt_len] = (uint8_t)((block_idx >> 24) & 0xFF);
    salt_block[salt_len + 1] = (uint8_t)((block_idx >> 16) & 0xFF);
    salt_block[salt_len + 2] = (uint8_t)((block_idx >> 8) & 0xFF);
    salt_block[salt_len + 3] = (uint8_t)(block_idx & 0xFF);
    uint8_t u[32], t[32];
    aipl_hmac_sha256_raw(pass, pass_len, salt_block, salt_len + 4, u); memcpy(t, u, 32);
    for (size_t c = 1; c < iters; c++) {
      aipl_hmac_sha256_raw(pass, pass_len, u, 32, u);
      for (int i = 0; i < 32; i++) t[i] ^= u[i];
    }
    size_t to_copy = (out_len - offset) < 32 ? (out_len - offset) : 32;
    memcpy(out + offset, t, to_copy); offset += to_copy;
  }
  free(salt_block);
}

AiplVal aipl_rt_pbkdf2HmacSha256(AiplVal pass_val, AiplVal salt_val, AiplVal iter_val, AiplVal outlen_val) {
  const uint8_t* p = (pass_val.kind == AIPL_BYTES && pass_val.ptr) ? ((AiplBytes*)pass_val.ptr)->data : (const uint8_t*)(pass_val.s ? pass_val.s : "");
  size_t plen = (pass_val.kind == AIPL_BYTES && pass_val.ptr) ? (size_t)((AiplBytes*)pass_val.ptr)->len : aipl_str_byte_len(pass_val);
  const uint8_t* s = (salt_val.kind == AIPL_BYTES && salt_val.ptr) ? ((AiplBytes*)salt_val.ptr)->data : (const uint8_t*)(salt_val.s ? salt_val.s : "");
  size_t slen = (salt_val.kind == AIPL_BYTES && salt_val.ptr) ? (size_t)((AiplBytes*)salt_val.ptr)->len : aipl_str_byte_len(salt_val);
  size_t iters = iter_val.i > 0 ? (size_t)iter_val.i : 1;
  size_t out_len = outlen_val.i > 0 ? (size_t)outlen_val.i : 32;
  AiplVal res = aipl_bytes_new(out_len); AiplBytes* rb = (AiplBytes*)res.ptr;
  aipl_pbkdf2_hmac_sha256(p, plen, s, slen, iters, out_len, rb->data); return res;
}

uint8_t* aipl_deflate_raw(const uint8_t* data, size_t len, size_t* out_len) {
  size_t max_block = 65535; size_t num_blocks = len == 0 ? 1 : ((len + max_block - 1) / max_block);
  size_t total_size = len + num_blocks * 5; uint8_t* out = (uint8_t*)malloc(total_size);
  size_t in_pos = 0, out_pos = 0;
  for (size_t b = 0; b < num_blocks; b++) {
    size_t blk_len = (len - in_pos) > max_block ? max_block : (len - in_pos);
    int is_final = (b == num_blocks - 1) ? 1 : 0;
    out[out_pos++] = (uint8_t)is_final;
    out[out_pos++] = (uint8_t)(blk_len & 0xFF); out[out_pos++] = (uint8_t)((blk_len >> 8) & 0xFF);
    uint16_t nlen = (uint16_t)(~((uint16_t)blk_len));
    out[out_pos++] = (uint8_t)(nlen & 0xFF); out[out_pos++] = (uint8_t)((nlen >> 8) & 0xFF);
    if (blk_len > 0) { memcpy(out + out_pos, data + in_pos, blk_len); in_pos += blk_len; out_pos += blk_len; }
  }
  *out_len = out_pos; return out;
}

AiplVal aipl_rt_deflateRaw(AiplVal data_val) {
  const uint8_t* p = (data_val.kind == AIPL_BYTES && data_val.ptr) ? ((AiplBytes*)data_val.ptr)->data : (const uint8_t*)(data_val.s ? data_val.s : "");
  size_t len = (data_val.kind == AIPL_BYTES && data_val.ptr) ? (size_t)((AiplBytes*)data_val.ptr)->len : aipl_str_byte_len(data_val);
  size_t out_sz = 0; uint8_t* out = aipl_deflate_raw(p, len, &out_sz);
  AiplVal res = aipl_bytes_new(out_sz); AiplBytes* rb = (AiplBytes*)res.ptr;
  if (out && out_sz > 0) memcpy(rb->data, out, out_sz);
  if (out) free(out); return res;
}

uint8_t* aipl_inflate_raw(const uint8_t* data, size_t len, size_t* out_len, int* ok) {
  size_t cap = len > 0 ? len : 32; size_t out_pos = 0; uint8_t* out = (uint8_t*)malloc(cap);
  size_t in_pos = 0; *ok = 1;
  while (in_pos < len) {
    uint8_t header = data[in_pos++]; int bfinal = header & 1; int btype = (header >> 1) & 3;
    if (btype != 0) { *ok = 0; free(out); return NULL; }
    if (in_pos + 4 > len) { *ok = 0; free(out); return NULL; }
    uint16_t blk_len = (uint16_t)data[in_pos] | ((uint16_t)data[in_pos + 1] << 8);
    uint16_t nlen = (uint16_t)data[in_pos + 2] | ((uint16_t)data[in_pos + 3] << 8);
    in_pos += 4;
    if (blk_len != (uint16_t)(~nlen)) { *ok = 0; free(out); return NULL; }
    if (in_pos + blk_len > len) { *ok = 0; free(out); return NULL; }
    while (out_pos + blk_len > cap) { cap *= 2; out = (uint8_t*)realloc(out, cap); }
    if (blk_len > 0) { memcpy(out + out_pos, data + in_pos, blk_len); in_pos += blk_len; out_pos += blk_len; }
    if (bfinal) break;
  }
  *out_len = out_pos; return out;
}

AiplVal aipl_rt_inflateRaw(AiplVal data_val) {
  const uint8_t* p = (data_val.kind == AIPL_BYTES && data_val.ptr) ? ((AiplBytes*)data_val.ptr)->data : (const uint8_t*)(data_val.s ? data_val.s : "");
  size_t len = (data_val.kind == AIPL_BYTES && data_val.ptr) ? (size_t)((AiplBytes*)data_val.ptr)->len : aipl_str_byte_len(data_val);
  size_t out_sz = 0; int ok = 0; uint8_t* out = aipl_inflate_raw(p, len, &out_sz, &ok);
  if (!ok || !out) { if (out) free(out); return aipl_err(aipl_str("inflateRaw: decompression failed")); }
  AiplVal bv = aipl_bytes_new(out_sz); AiplBytes* rb = (AiplBytes*)bv.ptr;
  if (out_sz > 0) memcpy(rb->data, out, out_sz); free(out); return aipl_ok(bv);
}

uint32_t aipl_adler32(const uint8_t* data, size_t len) {
  uint32_t a = 1, b = 0;
  for (size_t i = 0; i < len; i++) { a = (a + data[i]) % 65521; b = (b + a) % 65521; }
  return (b << 16) | a;
}

uint8_t* aipl_zlib_compress(const uint8_t* data, size_t len, size_t* out_len) {
  size_t def_len = 0; uint8_t* def = aipl_deflate_raw(data, len, &def_len);
  uint32_t adler = aipl_adler32(data, len);
  size_t total = 2 + def_len + 4; uint8_t* out = (uint8_t*)malloc(total);
  out[0] = 0x78; out[1] = 0x01; memcpy(out + 2, def, def_len); free(def);
  out[2 + def_len] = (uint8_t)((adler >> 24) & 0xFF);
  out[2 + def_len + 1] = (uint8_t)((adler >> 16) & 0xFF);
  out[2 + def_len + 2] = (uint8_t)((adler >> 8) & 0xFF);
  out[2 + def_len + 3] = (uint8_t)(adler & 0xFF);
  *out_len = total; return out;
}

AiplVal aipl_rt_zlibCompress(AiplVal data_val) {
  const uint8_t* p = (data_val.kind == AIPL_BYTES && data_val.ptr) ? ((AiplBytes*)data_val.ptr)->data : (const uint8_t*)(data_val.s ? data_val.s : "");
  size_t len = (data_val.kind == AIPL_BYTES && data_val.ptr) ? (size_t)((AiplBytes*)data_val.ptr)->len : aipl_str_byte_len(data_val);
  size_t out_sz = 0; uint8_t* out = aipl_zlib_compress(p, len, &out_sz);
  AiplVal res = aipl_bytes_new(out_sz); AiplBytes* rb = (AiplBytes*)res.ptr;
  if (out && out_sz > 0) memcpy(rb->data, out, out_sz);
  if (out) free(out); return res;
}

uint8_t* aipl_zlib_decompress(const uint8_t* data, size_t len, size_t* out_len, int* ok) {
  if (len < 6) { *ok = 0; return NULL; }
  uint8_t cmf = data[0], flg = data[1];
  if (((cmf * 256 + flg) % 31) != 0 || (cmf & 0x0F) != 8) { *ok = 0; return NULL; }
  size_t def_len = len - 6; uint8_t* out = aipl_inflate_raw(data + 2, def_len, out_len, ok);
  if (!*ok) return NULL;
  uint32_t expected_adler = ((uint32_t)data[len - 4] << 24) | ((uint32_t)data[len - 3] << 16) | ((uint32_t)data[len - 2] << 8) | (uint32_t)data[len - 1];
  uint32_t actual_adler = aipl_adler32(out, *out_len);
  if (expected_adler != actual_adler) { *ok = 0; free(out); return NULL; }
  return out;
}

AiplVal aipl_rt_zlibDecompress(AiplVal data_val) {
  const uint8_t* p = (data_val.kind == AIPL_BYTES && data_val.ptr) ? ((AiplBytes*)data_val.ptr)->data : (const uint8_t*)(data_val.s ? data_val.s : "");
  size_t len = (data_val.kind == AIPL_BYTES && data_val.ptr) ? (size_t)((AiplBytes*)data_val.ptr)->len : aipl_str_byte_len(data_val);
  size_t out_sz = 0; int ok = 0; uint8_t* out = aipl_zlib_decompress(p, len, &out_sz, &ok);
  if (!ok || !out) { if (out) free(out); return aipl_err(aipl_str("zlibDecompress: decompression failed")); }
  AiplVal bv = aipl_bytes_new(out_sz); AiplBytes* rb = (AiplBytes*)bv.ptr;
  if (out_sz > 0) memcpy(rb->data, out, out_sz); free(out); return aipl_ok(bv);
}

AiplVal aipl_rt_bytesNew(AiplVal size) { return aipl_bytes_new(size.i); }

AiplVal aipl_rt_bytesFromArray(AiplVal arr) { return aipl_bytes_from_array(arr); }

AiplVal aipl_rt_Ok(AiplVal v) { return aipl_ok(v); }

AiplVal aipl_rt_Err(AiplVal v) { return aipl_err(v); }

AiplVal aipl_rt_Some(AiplVal v) { return aipl_some(v); }

AiplVal aipl_rt_None(void) { return aipl_none(); }

double aipl_to_c_double(AiplVal v) {
  if (v.kind == AIPL_FLOAT) return v.f;
  return (double)v.i;
}

AiplVal aipl_str_char_at(AiplVal s_val, AiplVal idx_val) {
  const char* s = s_val.s ? s_val.s : ""; int64_t i = idx_val.i;
  size_t len = strlen(s);
  if (i < 0 || (size_t)i >= len) return aipl_str("");
  char buf[2] = { s[i], 0 }; return aipl_str(buf);
}

AiplVal aipl_str_repeat(AiplVal s_val, AiplVal count_val) {
  const char* s = s_val.s ? s_val.s : ""; int64_t n = count_val.i;
  if (n <= 0) return aipl_str("");
  size_t len = strlen(s); if (len == 0) return aipl_str("");
  char* buf = (char*)malloc(len * (size_t)n + 1);
  for (int64_t i = 0; i < n; i++) { memcpy(buf + i * len, s, len); }
  buf[len * (size_t)n] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_str_trim_start(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : "";
  while (*s && (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r')) s++;
  return aipl_str(s);
}

AiplVal aipl_str_trim_end(AiplVal s_val) {
  const char* s = s_val.s ? s_val.s : ""; size_t len = strlen(s);
  while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n' || s[len - 1] == '\r')) len--;
  char* buf = (char*)malloc(len + 1); memcpy(buf, s, len); buf[len] = 0;
  AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_str_pad_start(AiplVal s_val, AiplVal len_val, AiplVal pad_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* pad = (pad_val.s && pad_val.s[0]) ? pad_val.s : " ";
  int64_t target_len = len_val.i; size_t cur_len = strlen(s);
  if ((size_t)target_len <= cur_len) return s_val;
  size_t pad_needed = (size_t)target_len - cur_len; size_t pad_len = strlen(pad);
  char* buf = (char*)malloc((size_t)target_len + 1); size_t filled = 0;
  while (filled < pad_needed) {
    size_t copy_len = pad_len; if (filled + copy_len > pad_needed) copy_len = pad_needed - filled;
    memcpy(buf + filled, pad, copy_len); filled += copy_len;
  }
  memcpy(buf + pad_needed, s, cur_len); buf[target_len] = 0;
  AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_str_pad_end(AiplVal s_val, AiplVal len_val, AiplVal pad_val) {
  const char* s = s_val.s ? s_val.s : ""; const char* pad = (pad_val.s && pad_val.s[0]) ? pad_val.s : " ";
  int64_t target_len = len_val.i; size_t cur_len = strlen(s);
  if ((size_t)target_len <= cur_len) return s_val;
  size_t pad_needed = (size_t)target_len - cur_len; size_t pad_len = strlen(pad);
  char* buf = (char*)malloc((size_t)target_len + 1); memcpy(buf, s, cur_len); size_t filled = cur_len;
  while (filled < (size_t)target_len) {
    size_t copy_len = pad_len; if (filled + copy_len > (size_t)target_len) copy_len = (size_t)target_len - filled;
    memcpy(buf + filled, pad, copy_len); filled += copy_len;
  }
  buf[target_len] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_container_clear(AiplVal c) {
  if (c.kind == AIPL_ARRAY && c.ptr) { ((AiplArray*)c.ptr)->len = 0; }
  else if (c.kind == AIPL_MAP && c.ptr) {
    AiplMap* m = (AiplMap*)c.ptr;
    m->len = 0;
    if (m->hash_slots) {
      for (int64_t i = 0; i < m->hash_cap; i++) m->hash_slots[i] = -1;
    }
  }
  return aipl_nil();
}

AiplVal aipl_container_remove(AiplVal c, AiplVal key_or_val) {
  if (c.kind == AIPL_MAP && c.ptr) {
    AiplMap* m = (AiplMap*)c.ptr;
    const char* k = aipl_to_cstr(key_or_val);
    if (!k) k = "";
    for (int64_t i = 0; i < m->len; i++) {
      if (m->keys[i] && strcmp(m->keys[i], k) == 0) {
        free((void*)m->keys[i]);
        for (int64_t j = i; j < m->len - 1; j++) { m->keys[j] = m->keys[j + 1]; m->vals[j] = m->vals[j + 1]; }
        m->len--;
        if (m->hash_cap > 0) aipl_map_rehash(m, m->hash_cap);
        return aipl_bool(true);
      }
    }
    return aipl_bool(false);
  } else if (c.kind == AIPL_ARRAY && c.ptr) {
    AiplArray* a = (AiplArray*)c.ptr; int64_t idx = key_or_val.i;
    if (idx >= 0 && idx < a->len) {
      for (int64_t j = idx; j < a->len - 1; j++) { a->data[j] = a->data[j + 1]; }
      a->len--; return aipl_bool(true);
    }
    return aipl_bool(false);
  }
  return aipl_nil();
}

AiplVal aipl_map_values(AiplVal map_val) {
  if (map_val.kind != AIPL_MAP || !map_val.ptr) return aipl_array_new(NULL, 0);
  AiplMap* m = (AiplMap*)map_val.ptr;
  AiplVal* vals = (AiplVal*)malloc(sizeof(AiplVal) * (m->len > 0 ? m->len : 1));
  for (int64_t i = 0; i < m->len; i++) { vals[i] = m->vals[i]; }
  AiplVal res = aipl_array_new(vals, m->len); free(vals); return res;
}

AiplVal aipl_rt_args(void) { return aipl_rt_userArgs(); }

AiplVal aipl_rt_env(AiplVal key) {
  const char* k = key.s ? key.s : ""; const char* val = getenv(k); return aipl_str(val ? val : "");
}

AiplVal aipl_rt_eprint(AiplVal v) {
  AiplVal s = aipl_to_str(v); fprintf(stderr, "%s", s.s ? s.s : ""); fflush(stderr); return aipl_nil();
}

AiplVal aipl_rt_eprintln(AiplVal v) {
  AiplVal s = aipl_to_str(v); fprintf(stderr, "%s\n", s.s ? s.s : ""); fflush(stderr); return aipl_nil();
}

AiplVal aipl_rt_printInline(AiplVal v) {
  AiplVal s = aipl_to_str(v); const char* str_val = s.s ? s.s : "";
  fwrite(str_val, 1, strlen(str_val), stdout); fflush(stdout); return aipl_nil();
}

AiplVal aipl_rt_flushStdout(void) { fflush(stdout); return aipl_nil(); }

AiplVal aipl_rt_readStdin(void) {
  size_t cap = 4096; size_t len = 0; char* buf = (char*)malloc(cap); int c;
  while ((c = fgetc(stdin)) != EOF) {
    if (len + 1 >= cap) { cap *= 2; buf = (char*)realloc(buf, cap); }
    buf[len++] = (char)c;
  }
  buf[len] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_rt_readLine(void) {
  char line_buf[4096];
  if (!fgets(line_buf, sizeof(line_buf), stdin)) {
    return aipl_none();
  }
  if (strncasecmp(line_buf, "Content-Length:", 15) == 0) {
    long content_len = atol(line_buf + 15);
    while (fgets(line_buf, sizeof(line_buf), stdin)) {
      if (strcmp(line_buf, "\r\n") == 0 || strcmp(line_buf, "\n") == 0) break;
    }
    if (content_len < 0) content_len = 0;
    char* body = (char*)malloc(content_len + 1);
    size_t nr = fread(body, 1, (size_t)content_len, stdin);
    body[nr] = 0;
    AiplVal res = aipl_some(aipl_str_n(body, (int64_t)nr));
    free(body);
    return res;
  }
  size_t len = strlen(line_buf);
  while (len > 0 && (line_buf[len - 1] == '\n' || line_buf[len - 1] == '\r')) {
    line_buf[--len] = 0;
  }
  return aipl_some(aipl_str(line_buf));
}

AiplVal aipl_rt_chr(AiplVal n) { char buf[2] = { (char)n.i, 0 }; return aipl_str_n(buf, 1); }

AiplVal aipl_rt_fromCharCode(AiplVal n) { return aipl_rt_chr(n); }

AiplVal aipl_rt_ord(AiplVal s) { const char* p = s.s ? s.s : ""; return aipl_int((uint8_t)p[0]); }

AiplVal aipl_rt_charCode(AiplVal s) { return aipl_rt_ord(s); }

AiplVal aipl_rt_parseInt(AiplVal s) { return aipl_to_int(s); }

AiplVal aipl_rt_parseFloat(AiplVal s) { return aipl_to_float(s); }

AiplVal aipl_rt_toString(AiplVal v) { return aipl_to_str(v); }

AiplVal aipl_rt_formatFloat(AiplVal v, AiplVal decimals) {
  double val = aipl_to_c_double(v); int d = (int)decimals.i; if (d < 0) d = 0; if (d > 20) d = 20;
  char buf[64]; snprintf(buf, sizeof(buf), "%.*f", d, val); return aipl_str(buf);
}

AiplVal aipl_rt_toHex(AiplVal n) {
  char buf[32]; snprintf(buf, sizeof(buf), "%llx", (unsigned long long)n.i); return aipl_str(buf);
}

AiplVal aipl_rt_mkdirAll(AiplVal p) {
  const char* path = p.s ? p.s : ""; char tmp[1024]; size_t len = strlen(path);
  if (len == 0 || len >= sizeof(tmp)) return aipl_err(aipl_str("mkdirAll: invalid path"));
  memcpy(tmp, path, len + 1);
  for (char* s = tmp + 1; *s; s++) {
    if (*s == '/' || *s == '\\') { char c = *s; *s = 0; mkdir(tmp, 0755); *s = c; }
  }
  if (mkdir(tmp, 0755) == 0 || access(tmp, F_OK) == 0) return aipl_ok(aipl_bool(true));
  return aipl_err(aipl_str("mkdirAll failed"));
}

AiplVal aipl_rt_deleteFile(AiplVal p) { return aipl_rt_removeFile(p); }

AiplVal aipl_rt_fileSize(AiplVal p) {
  const char* path = p.s ? p.s : ""; struct stat st;
  if (stat(path, &st) == 0) return aipl_int((int64_t)st.st_size);
  return aipl_int(-1);
}

AiplVal aipl_rt_isFile(AiplVal p) {
  const char* path = p.s ? p.s : ""; struct stat st;
  if (stat(path, &st) == 0) return aipl_bool(S_ISREG(st.st_mode));
  return aipl_bool(false);
}

AiplVal aipl_rt_copyFile(AiplVal src_val, AiplVal dst_val) {
  AiplVal data = aipl_rt_readBytes(src_val);
  if (data.kind == AIPL_RES_OK && data.ptr) {
    AiplVal bytesVal = *(AiplVal*)data.ptr;
    AiplVal writeRes = aipl_rt_writeBytes(dst_val, bytesVal);
    if (writeRes.kind == AIPL_RES_OK) {
      int64_t bLen = (bytesVal.kind == AIPL_BYTES && bytesVal.ptr) ? ((AiplBytes*)bytesVal.ptr)->len : 0;
      return aipl_ok(aipl_int(bLen));
    }
    return writeRes;
  }
  return aipl_err(aipl_str("copyFile: failed to read source file"));
}

AiplVal aipl_rt_renameFile(AiplVal old_p, AiplVal new_p) {
  const char* o = old_p.s ? old_p.s : ""; const char* n = new_p.s ? new_p.s : "";
  if (rename(o, n) == 0) return aipl_ok(aipl_bool(true));
  return aipl_err(aipl_str("renameFile failed"));
}

AiplVal aipl_rt_tcpListen(AiplVal host, AiplVal port) {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) return aipl_err(aipl_str("tcpListen: cannot create socket"));
  int opt = 1; setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  struct sockaddr_in addr; memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET; addr.sin_port = htons((uint16_t)port.i);
  const char* h = (host.kind == AIPL_STR && host.s && host.s[0]) ? host.s : "0.0.0.0";
  if (inet_pton(AF_INET, h, &addr.sin_addr) <= 0) { addr.sin_addr.s_addr = INADDR_ANY; }
  if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) { close(fd); return aipl_err(aipl_str("tcpListen: bind failed")); }
  if (listen(fd, 128) < 0) { close(fd); return aipl_err(aipl_str("tcpListen: listen failed")); }
  return aipl_ok(aipl_int(fd));
}

AiplVal aipl_rt_tcpLocalPort(AiplVal sock) {
  int fd = (int)sock.i; struct sockaddr_in addr; socklen_t len = sizeof(addr);
  if (getsockname(fd, (struct sockaddr*)&addr, &len) == 0) { return aipl_ok(aipl_int(ntohs(addr.sin_port))); }
  return aipl_err(aipl_str("tcpLocalPort: getsockname failed"));
}

AiplVal aipl_rt_tcpConnect(AiplVal host, AiplVal port, AiplVal timeoutMs) {
  const char* h = (host.kind == AIPL_STR && host.s && host.s[0]) ? host.s : "127.0.0.1";
  char port_str[32]; snprintf(port_str, sizeof(port_str), "%d", (int)port.i);
  struct sockaddr_in addr; memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET; addr.sin_port = htons((uint16_t)port.i);
  if (inet_pton(AF_INET, h, &addr.sin_addr) > 0) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd >= 0) {
      if (timeoutMs.i > 0) {
        struct timeval tv; tv.tv_sec = timeoutMs.i / 1000; tv.tv_usec = (timeoutMs.i % 1000) * 1000;
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)); setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
      }
      if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == 0) return aipl_ok(aipl_int(fd));
      close(fd);
    }
  } else {
    struct addrinfo hints, *res = NULL, *rp = NULL; memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(h, port_str, &hints, &res) == 0 && res) {
      for (rp = res; rp != NULL; rp = rp->ai_next) {
        int fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (fd < 0) continue;
        if (timeoutMs.i > 0) {
          struct timeval tv; tv.tv_sec = timeoutMs.i / 1000; tv.tv_usec = (timeoutMs.i % 1000) * 1000;
          setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)); setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
        }
        if (connect(fd, rp->ai_addr, rp->ai_addrlen) == 0) { freeaddrinfo(res); return aipl_ok(aipl_int(fd)); }
        close(fd);
      }
      freeaddrinfo(res);
    }
  }
  return aipl_err(aipl_str("Connection refused (os error 111)"));
}

AiplVal aipl_rt_tcpAccept(AiplVal listener) {
  int lfd = (int)listener.i; struct sockaddr_in clientAddr; socklen_t clientLen = sizeof(clientAddr);
  int cfd = accept(lfd, (struct sockaddr*)&clientAddr, &clientLen);
  if (cfd < 0) return aipl_err(aipl_str("tcpAccept failed"));
  return aipl_ok(aipl_int(cfd));
}

AiplVal aipl_rt_tcpRead(AiplVal sock, AiplVal maxBytes) {
  int fd = (int)sock.i; int64_t n = (maxBytes.i > 0) ? maxBytes.i : 4096;
  AiplVal b_val = aipl_bytes_new(n); AiplBytes* b = (AiplBytes*)b_val.ptr;
  ssize_t rd = read(fd, b->data, (size_t)n);
  if (rd < 0) return aipl_err(aipl_str("tcpRead failed"));
  b->len = rd; return aipl_ok(b_val);
}

AiplVal aipl_rt_tcpWrite(AiplVal sock, AiplVal data) {
  int fd = (int)sock.i; const uint8_t* p = NULL; size_t len = 0;
  if (data.kind == AIPL_BYTES && data.ptr) {
    p = ((AiplBytes*)data.ptr)->data; len = (size_t)((AiplBytes*)data.ptr)->len;
  } else if (data.kind == AIPL_STR) {
    p = (const uint8_t*)(data.s ? data.s : ""); len = aipl_str_byte_len(data);
  }
  if (len == 0) return aipl_ok(aipl_int(0));
  ssize_t wr = write(fd, p, len);
  if (wr < 0) return aipl_err(aipl_str("tcpWrite failed"));
  return aipl_ok(aipl_int(wr));
}

AiplVal aipl_rt_tcpClose(AiplVal sock) {
  int fd = (int)sock.i; if (fd >= 0) close(fd); return aipl_nil();
}

AiplVal aipl_rt_udpBind(AiplVal host, AiplVal port) {
  int fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (fd < 0) return aipl_err(aipl_str_lit("udpBind: cannot create socket"));
  int opt = 1; setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  struct sockaddr_in addr; memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  int p = (int)aipl_to_int(port).i;
  addr.sin_port = htons((uint16_t)p);
  const char* h = (host.kind == AIPL_STR && host.s && host.s[0]) ? host.s : "0.0.0.0";
  if (inet_pton(AF_INET, h, &addr.sin_addr) <= 0) addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    close(fd); return aipl_err(aipl_str_lit("udpBind: bind failed"));
  }
  return aipl_ok(aipl_int(fd));
}

AiplVal aipl_rt_udpSendTo(AiplVal a1, AiplVal a2, AiplVal a3, AiplVal a4) {
  if (a1.kind == AIPL_INT || (a1.kind == AIPL_FLOAT && a2.kind == AIPL_STR)) {
    int fd = (int)aipl_to_int(a1).i;
    const char* host = (a2.kind == AIPL_STR && a2.s) ? a2.s : "127.0.0.1";
    int port = (int)aipl_to_int(a3).i;
    struct sockaddr_in dest; memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons((uint16_t)port);
    if (inet_pton(AF_INET, host, &dest.sin_addr) <= 0) {
      struct hostent* he = gethostbyname(host);
      if (he && he->h_addr_list[0]) {
        memcpy(&dest.sin_addr, he->h_addr_list[0], (size_t)he->h_length);
      } else {
        return aipl_err(aipl_str_lit("udpSendTo: invalid host"));
      }
    }
    const uint8_t* p = NULL; size_t len = 0;
    if (a4.kind == AIPL_BYTES && a4.ptr) {
      p = ((AiplBytes*)a4.ptr)->data; len = (size_t)((AiplBytes*)a4.ptr)->len;
    } else if (a4.kind == AIPL_STR) {
      p = (const uint8_t*)(a4.s ? a4.s : ""); len = (size_t)aipl_str_byte_len(a4);
    }
    ssize_t sent = sendto(fd, p, len, 0, (struct sockaddr*)&dest, sizeof(dest));
    if (sent < 0) return aipl_err(aipl_str_lit("udpSendTo: sendto failed"));
    return aipl_ok(aipl_int(sent));
  } else {
    const char* host = (a1.kind == AIPL_STR && a1.s) ? a1.s : "127.0.0.1";
    int port = (int)aipl_to_int(a2).i;
    int timeoutMs = (int)aipl_to_int(a4).i;
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) return aipl_err(aipl_str_lit("udpSendTo: socket creation failed"));
    struct sockaddr_in dest; memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons((uint16_t)port);
    if (inet_pton(AF_INET, host, &dest.sin_addr) <= 0) {
      struct hostent* he = gethostbyname(host);
      if (he && he->h_addr_list[0]) {
        memcpy(&dest.sin_addr, he->h_addr_list[0], (size_t)he->h_length);
      } else {
        close(fd); return aipl_err(aipl_str_lit("udpSendTo: invalid host"));
      }
    }
    const uint8_t* p = NULL; size_t len = 0;
    if (a3.kind == AIPL_BYTES && a3.ptr) {
      p = ((AiplBytes*)a3.ptr)->data; len = (size_t)((AiplBytes*)a3.ptr)->len;
    } else if (a3.kind == AIPL_STR) {
      p = (const uint8_t*)(a3.s ? a3.s : ""); len = (size_t)aipl_str_byte_len(a3);
    }
    ssize_t sent = sendto(fd, p, len, 0, (struct sockaddr*)&dest, sizeof(dest));
    if (sent < 0) { close(fd); return aipl_err(aipl_str_lit("udpSendTo: sendto failed")); }
    if (timeoutMs > 0) {
      struct timeval tv; tv.tv_sec = timeoutMs / 1000; tv.tv_usec = (timeoutMs % 1000) * 1000;
      setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
      AiplVal rep_val = aipl_bytes_new(65535);
      AiplBytes* rep = (AiplBytes*)rep_val.ptr;
      struct sockaddr_in reply_addr; socklen_t rlen = sizeof(reply_addr);
      ssize_t rd = recvfrom(fd, rep->data, 65535, 0, (struct sockaddr*)&reply_addr, &rlen);
      close(fd);
      if (rd < 0) return aipl_err(aipl_str_lit("udpSendTo: timeout waiting for reply"));
      rep->len = rd;
      return aipl_ok(rep_val);
    }
    close(fd);
    return aipl_ok(aipl_int(sent));
  }
}

AiplVal aipl_rt_udpRecvFrom(AiplVal sock, AiplVal maxBytes) {
  int fd = (int)aipl_to_int(sock).i;
  int64_t n = aipl_to_int(maxBytes).i;
  if (n <= 0) n = 65535;
  AiplVal b_val = aipl_bytes_new(n);
  AiplBytes* b = (AiplBytes*)b_val.ptr;
  struct sockaddr_in src; socklen_t srclen = sizeof(src);
  ssize_t rd = recvfrom(fd, b->data, (size_t)n, 0, (struct sockaddr*)&src, &srclen);
  if (rd < 0) return aipl_err(aipl_str_lit("udpRecvFrom failed"));
  b->len = rd;
  return aipl_ok(b_val);
}

AiplVal aipl_rt_udpClose(AiplVal sock) {
  int fd = (int)aipl_to_int(sock).i;
  if (fd >= 0) close(fd);
  return aipl_nil();
}

AiplVal aipl_rt_pi(void) { return aipl_float(3.14159265358979323846); }

AiplVal aipl_rt_sin(AiplVal v) { return aipl_float(sin(aipl_to_c_double(v))); }

AiplVal aipl_rt_cos(AiplVal v) { return aipl_float(cos(aipl_to_c_double(v))); }

AiplVal aipl_rt_tan(AiplVal v) { return aipl_float(tan(aipl_to_c_double(v))); }

AiplVal aipl_rt_asin(AiplVal v) { return aipl_float(asin(aipl_to_c_double(v))); }

AiplVal aipl_rt_acos(AiplVal v) { return aipl_float(acos(aipl_to_c_double(v))); }

AiplVal aipl_rt_atan(AiplVal v) { return aipl_float(atan(aipl_to_c_double(v))); }

AiplVal aipl_rt_atan2(AiplVal y, AiplVal x) { return aipl_float(atan2(aipl_to_c_double(y), aipl_to_c_double(x))); }

AiplVal aipl_rt_sqrt(AiplVal v) { return aipl_float(sqrt(aipl_to_c_double(v))); }

AiplVal aipl_rt_pow(AiplVal b, AiplVal e) {
  if (b.kind == AIPL_INT && e.kind == AIPL_INT && e.i >= 0) {
    int64_t base = b.i; int64_t exp = e.i; int64_t res = 1;
    while (exp > 0) { if (exp & 1) res *= base; base *= base; exp >>= 1; }
    return aipl_int(res);
  }
  return aipl_float(pow(aipl_to_c_double(b), aipl_to_c_double(e)));
}

AiplVal aipl_rt_floor(AiplVal v) { return aipl_float(floor(aipl_to_c_double(v))); }

AiplVal aipl_rt_ceil(AiplVal v) { return aipl_float(ceil(aipl_to_c_double(v))); }

AiplVal aipl_rt_round(AiplVal v) { return aipl_float(round(aipl_to_c_double(v))); }

AiplVal aipl_rt_abs(AiplVal v) {
  if (v.kind == AIPL_INT) return aipl_int(v.i < 0 ? -v.i : v.i);
  return aipl_float(fabs(aipl_to_c_double(v)));
}

AiplVal aipl_rt_absInt(AiplVal v) { return aipl_int(v.i < 0 ? -v.i : v.i); }

AiplVal aipl_rt_absFloat(AiplVal v) { return aipl_float(fabs(aipl_to_c_double(v))); }

AiplVal aipl_rt_min(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) return aipl_int(a.i < b.i ? a.i : b.i);
  return aipl_float(aipl_to_c_double(a) < aipl_to_c_double(b) ? aipl_to_c_double(a) : aipl_to_c_double(b));
}

AiplVal aipl_rt_max(AiplVal a, AiplVal b) {
  if (a.kind == AIPL_INT && b.kind == AIPL_INT) return aipl_int(a.i > b.i ? a.i : b.i);
  return aipl_float(aipl_to_c_double(a) > aipl_to_c_double(b) ? aipl_to_c_double(a) : aipl_to_c_double(b));
}

AiplVal aipl_rt_minInt(AiplVal a, AiplVal b) { return aipl_int(a.i < b.i ? a.i : b.i); }

AiplVal aipl_rt_maxInt(AiplVal a, AiplVal b) { return aipl_int(a.i > b.i ? a.i : b.i); }

AiplVal aipl_rt_minFloat(AiplVal a, AiplVal b) { return aipl_float(fmin(aipl_to_c_double(a), aipl_to_c_double(b))); }

AiplVal aipl_rt_maxFloat(AiplVal a, AiplVal b) { return aipl_float(fmax(aipl_to_c_double(a), aipl_to_c_double(b))); }

AiplVal aipl_rt_clamp(AiplVal v, AiplVal lo, AiplVal hi) {
  if (v.kind == AIPL_INT && lo.kind == AIPL_INT && hi.kind == AIPL_INT) {
    int64_t x = v.i; if (x < lo.i) { x = lo.i; } if (x > hi.i) { x = hi.i; } return aipl_int(x);
  }
  double d = aipl_to_c_double(v); double l = aipl_to_c_double(lo); double h = aipl_to_c_double(hi);
  if (d < l) { d = l; } if (d > h) { d = h; } return aipl_float(d);
}

AiplVal aipl_rt_clampInt(AiplVal v, AiplVal lo, AiplVal hi) {
  int64_t x = v.i; if (x < lo.i) { x = lo.i; } if (x > hi.i) { x = hi.i; } return aipl_int(x);
}

AiplVal aipl_rt_clampFloat(AiplVal v, AiplVal lo, AiplVal hi) {
  double d = aipl_to_c_double(v); double l = aipl_to_c_double(lo); double h = aipl_to_c_double(hi);
  if (d < l) { d = l; } if (d > h) { d = h; } return aipl_float(d);
}

AiplVal aipl_rt_lerp(AiplVal a, AiplVal b, AiplVal t) {
  double da = aipl_to_c_double(a); double db = aipl_to_c_double(b); double dt = aipl_to_c_double(t);
  return aipl_float(da + (db - da) * dt);
}

AiplVal aipl_rt_limitVal(AiplVal v, AiplVal lo, AiplVal hi) { return aipl_rt_clamp(v, lo, hi); }

AiplVal aipl_rt_mixVal(AiplVal a, AiplVal b, AiplVal t) { return aipl_rt_lerp(a, b, t); }

AiplVal aipl_rt_log(AiplVal v) { return aipl_float(log(aipl_to_c_double(v))); }

AiplVal aipl_rt_log2(AiplVal v) { return aipl_float(log2(aipl_to_c_double(v))); }

AiplVal aipl_rt_log10(AiplVal v) { return aipl_float(log10(aipl_to_c_double(v))); }

AiplVal aipl_rt_exp(AiplVal v) { return aipl_float(exp(aipl_to_c_double(v))); }

AiplVal aipl_rt_randomInt(AiplVal min_val, AiplVal max_val) {
  static bool _rand_inited = false; if (!_rand_inited) { srand((unsigned)time(NULL)); _rand_inited = true; }
  int64_t mn = min_val.i; int64_t mx = max_val.i; if (mx <= mn) return min_val;
  return aipl_int(mn + (rand() % (mx - mn + 1)));
}

AiplVal aipl_rt_randInt(AiplVal min_val, AiplVal max_val) { return aipl_rt_randomInt(min_val, max_val); }

AiplVal aipl_rt_randomIntRange(AiplVal min_val, AiplVal max_val) { return aipl_rt_randomInt(min_val, max_val); }

AiplVal aipl_rt_randomFloat(void) {
  static bool _rand_inited = false; if (!_rand_inited) { srand((unsigned)time(NULL)); _rand_inited = true; }
  return aipl_float((double)rand() / (double)RAND_MAX);
}

AiplVal aipl_rt_randFloat(void) { return aipl_rt_randomFloat(); }

void aipl_jbuf_init(AiplJsonBuf* b) { b->cap = 128; b->len = 0; b->data = (char*)malloc(b->cap); b->data[0] = 0; }

void aipl_jbuf_append(AiplJsonBuf* b, const char* s) {
  size_t sl = strlen(s);
  while (b->len + sl + 1 >= b->cap) { b->cap *= 2; b->data = (char*)realloc(b->data, b->cap); }
  memcpy(b->data + b->len, s, sl); b->len += sl; b->data[b->len] = 0;
}

void aipl_jbuf_append_char(AiplJsonBuf* b, char c) { char ch[2] = { c, 0 }; aipl_jbuf_append(b, ch); }

void aipl_jbuf_append_str_lit(AiplJsonBuf* b, const char* s) {
  aipl_jbuf_append(b, "\"");
  for (const char* p = s; *p; p++) {
    if (*p == '"') { aipl_jbuf_append_char(b, '\\'); aipl_jbuf_append_char(b, '"'); }
    else if (*p == '\\') { aipl_jbuf_append_char(b, '\\'); aipl_jbuf_append_char(b, '\\'); }
    else if (*p == '\n') { aipl_jbuf_append_char(b, '\\'); aipl_jbuf_append_char(b, 'n'); }
    else if (*p == '\r') { aipl_jbuf_append_char(b, '\\'); aipl_jbuf_append_char(b, 'r'); }
    else if (*p == '\t') { aipl_jbuf_append_char(b, '\\'); aipl_jbuf_append_char(b, 't'); }
    else { aipl_jbuf_append_char(b, *p); }
  }
  aipl_jbuf_append(b, "\"");
}

void aipl_json_stringify_val(AiplJsonBuf* b, AiplVal v) {
  char buf[64];
  if (v.kind == AIPL_NIL || v.kind == AIPL_OPT_NONE) { aipl_jbuf_append(b, "null"); }
  else if (v.kind == AIPL_BOOL) { aipl_jbuf_append(b, v.i ? "true" : "false"); }
  else if (v.kind == AIPL_INT) { snprintf(buf, sizeof(buf), "%lld", (long long)v.i); aipl_jbuf_append(b, buf); }
  else if (v.kind == AIPL_FLOAT) {
    snprintf(buf, sizeof(buf), "%.15g", v.f);
    if (!strchr(buf, '.') && !strchr(buf, 'e') && !strchr(buf, 'E')) strcat(buf, ".0");
    aipl_jbuf_append(b, buf);
  } else if (v.kind == AIPL_STR) {
    aipl_jbuf_append_str_lit(b, v.s ? v.s : "");
  } else if (v.kind == AIPL_ARRAY && v.ptr) {
    AiplArray* a = (AiplArray*)v.ptr; aipl_jbuf_append(b, "[");
    for (int64_t i = 0; i < a->len; i++) {
      if (i > 0) aipl_jbuf_append(b, ",");
      aipl_json_stringify_val(b, a->data[i]);
    }
    aipl_jbuf_append(b, "]");
  } else if (v.kind == AIPL_MAP && v.ptr) {
    AiplMap* m = (AiplMap*)v.ptr; aipl_jbuf_append(b, "{");
    for (int64_t i = 0; i < m->len; i++) {
      if (i > 0) aipl_jbuf_append(b, ",");
      aipl_jbuf_append_str_lit(b, m->keys[i] ? m->keys[i] : "");
      aipl_jbuf_append(b, ":");
      aipl_json_stringify_val(b, m->vals[i]);
    }
    aipl_jbuf_append(b, "}");
  } else if (v.kind == AIPL_STRUCT && v.ptr) {
    AiplStruct* st = (AiplStruct*)v.ptr;
    if (st->len > 0 && st->names && st->names[0] && strcmp(st->names[0], "__enum_args__") == 0) {
      aipl_jbuf_append(b, "{\"variant\":");
      aipl_jbuf_append_str_lit(b, st->type_name ? st->type_name : "");
      aipl_jbuf_append(b, ",\"value\":");
      if (st->len == 2) { aipl_json_stringify_val(b, st->vals[1]); }
      else { aipl_json_stringify_val(b, st->vals[0]); }
      aipl_jbuf_append(b, "}");
    } else {
      aipl_jbuf_append(b, "{");
      for (int64_t i = 0; i < st->len; i++) {
        if (i > 0) aipl_jbuf_append(b, ",");
        aipl_jbuf_append_str_lit(b, st->names[i] ? st->names[i] : "");
        aipl_jbuf_append(b, ":");
        aipl_json_stringify_val(b, st->vals[i]);
      }
      aipl_jbuf_append(b, "}");
    }
  } else if ((v.kind == AIPL_RES_OK || v.kind == AIPL_OPT_SOME) && v.ptr) {
    aipl_json_stringify_val(b, *(AiplVal*)v.ptr);
  } else { aipl_jbuf_append(b, "null"); }
}

AiplVal aipl_rt_jsonStringify(AiplVal v) {
  AiplJsonBuf b; aipl_jbuf_init(&b);
  aipl_json_stringify_val(&b, v);
  AiplVal res = aipl_str(b.data); free(b.data); return res;
}

AiplVal aipl_val_to_json(AiplVal v) {
  return aipl_rt_jsonStringify(v);
}

const char* aipl_json_skip_ws(const char* p) {
  while (*p && (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')) p++;
  return p;
}

AiplVal aipl_json_parse_str(const char** pp) {
  const char* p = *pp; if (*p != '"') return aipl_nil();
  p++; size_t cap = 32; size_t len = 0; char* buf = (char*)malloc(cap);
  while (*p && *p != '"') {
    char ch = *p++;
    if (ch == '\\' && *p) {
      char esc = *p++;
      if (esc == 'n') ch = '\n';
      else if (esc == 'r') ch = '\r';
      else if (esc == 't') ch = '\t';
      else if (esc == '"') ch = '"';
      else if (esc == '\\') ch = '\\';
      else ch = esc;
    }
    if (len + 1 >= cap) { cap *= 2; buf = (char*)realloc(buf, cap); }
    buf[len++] = ch;
  }
  if (*p == '"') p++;
  buf[len] = 0; *pp = p; AiplVal res = aipl_str(buf); free(buf); return res;
}

AiplVal aipl_json_parse_num(const char** pp) {
  const char* p = *pp; char* endp = NULL; int is_float = 0;
  for (const char* t = p; *t && (*t == '-' || *t == '+' || (*t >= '0' && *t <= '9') || *t == '.' || *t == 'e' || *t == 'E'); t++) {
    if (*t == '.' || *t == 'e' || *t == 'E') is_float = 1;
  }
  if (is_float) { double d = strtod(p, &endp); *pp = endp; return aipl_float(d); }
  else { long long iv = strtoll(p, &endp, 10); *pp = endp; return aipl_int((int64_t)iv); }
}

AiplVal aipl_json_parse_arr(const char** pp) {
  const char* p = *pp; if (*p != '[') return aipl_nil();
  p++; int64_t cap = 8; int64_t len = 0; AiplVal* items = (AiplVal*)malloc(sizeof(AiplVal) * cap);
  p = aipl_json_skip_ws(p);
  if (*p == ']') { p++; *pp = p; AiplVal res = aipl_array_new(items, 0); free(items); return res; }
  while (*p) {
    p = aipl_json_skip_ws(p); AiplVal item = aipl_json_parse_val(&p);
    if (len >= cap) { cap *= 2; items = (AiplVal*)realloc(items, sizeof(AiplVal) * cap); }
    items[len++] = item; p = aipl_json_skip_ws(p);
    if (*p == ',') { p++; continue; }
    if (*p == ']') { p++; break; }
    break;
  }
  *pp = p; AiplVal res = aipl_array_new(items, len); free(items); return res;
}

AiplVal aipl_json_parse_obj(const char** pp) {
  const char* p = *pp; if (*p != '{') return aipl_nil();
  p++; AiplVal mapVal = aipl_map_new(); p = aipl_json_skip_ws(p);
  if (*p == '}') { p++; *pp = p; return mapVal; }
  while (*p) {
    p = aipl_json_skip_ws(p); if (*p != '"') break;
    AiplVal key = aipl_json_parse_str(&p); p = aipl_json_skip_ws(p);
    if (*p == ':') p++;
    p = aipl_json_skip_ws(p); AiplVal val = aipl_json_parse_val(&p);
    aipl_map_set(mapVal, key, val); p = aipl_json_skip_ws(p);
    if (*p == ',') { p++; continue; }
    if (*p == '}') { p++; break; }
    break;
  }
  *pp = p; return mapVal;
}

AiplVal aipl_json_parse_val(const char** pp) {
  const char* p = aipl_json_skip_ws(*pp);
  if (!*p) return aipl_nil();
  if (*p == '"') return aipl_json_parse_str(pp);
  if (*p == '{') return aipl_json_parse_obj(pp);
  if (*p == '[') return aipl_json_parse_arr(pp);
  if (strncmp(p, "true", 4) == 0) { *pp = p + 4; return aipl_bool(true); }
  if (strncmp(p, "false", 5) == 0) { *pp = p + 5; return aipl_bool(false); }
  if (strncmp(p, "null", 4) == 0) { *pp = p + 4; return aipl_nil(); }
  if (*p == '-' || *p == '+' || (*p >= '0' && *p <= '9')) return aipl_json_parse_num(pp);
  (*pp)++; return aipl_nil();
}

AiplVal aipl_rt_jsonParse(AiplVal s_val) {
  const char* p = s_val.s ? s_val.s : ""; return aipl_json_parse_val(&p);
}

AiplVal aipl_rt_jsonGet(AiplVal jsonVal, AiplVal keyVal) {
  const char* json = jsonVal.s ? jsonVal.s : "";
  const char* key = keyVal.s ? keyVal.s : "";
  if (!json || !*json || !key || !*key) return aipl_str("");
  size_t klen = strlen(key);
  char* needle = (char*)malloc(klen + 3);
  needle[0] = '"'; memcpy(needle + 1, key, klen); needle[klen + 1] = '"'; needle[klen + 2] = 0;
  const char* p = strstr(json, needle); free(needle);
  if (!p) return aipl_str("");
  p += klen + 2;
  while (*p && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) p++;
  if (*p == ':') p++;
  while (*p && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) p++;
  if (!*p) return aipl_str("");
  if (*p == '"') {
    p++; size_t cap = 32; size_t len = 0; char* buf = (char*)malloc(cap);
    while (*p && *p != '"') {
      char ch = *p++;
      if (ch == '\\' && *p) {
        char esc = *p++;
        if (esc == 'n') ch = '\n';
        else if (esc == 'r') ch = '\r';
        else if (esc == 't') ch = '\t';
        else if (esc == '"') ch = '"';
        else if (esc == '\\') ch = '\\';
        else ch = esc;
      }
      if (len + 1 >= cap) { cap *= 2; buf = (char*)realloc(buf, cap); }
      buf[len++] = ch;
    }
    buf[len] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
  } else if (*p == 123 || *p == 91) {
    char openCh = *p; char closeCh = (openCh == 123) ? 125 : 93; int depth = 0;
    const char* start = p; bool inStr = false;
    while (*p) {
      if (*p == '"' && (p == start || *(p - 1) != '\\')) { inStr = !inStr; }
      else if (!inStr) {
        if (*p == openCh) depth++;
        else if (*p == closeCh) { depth--; if (depth == 0) { p++; break; } }
      }
      p++;
    }
    size_t slen = (size_t)(p - start); char* buf = (char*)malloc(slen + 1);
    memcpy(buf, start, slen); buf[slen] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
  } else {
    const char* start = p;
    while (*p && *p != ',' && *p != '}' && *p != ']' && *p != ' ' && *p != '\t' && *p != '\r' && *p != '\n') p++;
    size_t slen = (size_t)(p - start); char* buf = (char*)malloc(slen + 1);
    memcpy(buf, start, slen); buf[slen] = 0; AiplVal res = aipl_str(buf); free(buf); return res;
  }
}

