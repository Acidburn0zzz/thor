/*
Copyright (c) 2015, Cisco Systems
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* -*- mode: c; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2; -*- */

#ifndef _V256_INTRINSICS_H
#define _V256_INTRINSICS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "v256_intrinsics_c.h"
#include "v128_intrinsics.h"
#include "v64_intrinsics.h"

/* Fallback to plain, unoptimised C. */

typedef c_v256 v256;

SIMD_INLINE uint32_t v256_low_u32(v256 a) { return c_v256_low_u32(a); }
SIMD_INLINE v64 v256_low_v64(v256 a) { return c_v256_low_v64(a); }
SIMD_INLINE uint64_t v256_low_u64(v256 a) { return c_v256_low_u64(a); }
SIMD_INLINE v128 v256_low_v128(v256 a) { return c_v256_low_v128(a); }
SIMD_INLINE v128 v256_high_v128(v256 a) { return c_v256_high_v128(a); }
SIMD_INLINE v256 v256_from_v128(v128 hi, v128 lo) {
  return c_v256_from_v128(hi, lo);
}
SIMD_INLINE v256 v256_from_64(uint64_t a, uint64_t b, uint64_t c, uint64_t d) {
  return c_v256_from_64(a, b, c, d);
}
SIMD_INLINE v256 v256_from_v64(v64 a, v64 b, v64 c, v64 d) {
  return c_v256_from_v64(a, b, c, d);
}

SIMD_INLINE v256 v256_load_unaligned(const void *p) {
  return c_v256_load_unaligned(p);
}
SIMD_INLINE v256 v256_load_aligned(const void *p) {
  return c_v256_load_aligned(p);
}

SIMD_INLINE void v256_store_unaligned(void *p, v256 a) {
  c_v256_store_unaligned(p, a);
}
SIMD_INLINE void v256_store_aligned(void *p, v256 a) {
  c_v256_store_aligned(p, a);
}

SIMD_INLINE v256 v256_align(v256 a, v256 b, const unsigned int c) {
  return c_v256_align(a, b, c);
}

SIMD_INLINE v256 v256_zero() { return c_v256_zero(); }
SIMD_INLINE v256 v256_dup_8(uint8_t x) { return c_v256_dup_8(x); }
SIMD_INLINE v256 v256_dup_16(uint16_t x) { return c_v256_dup_16(x); }
SIMD_INLINE v256 v256_dup_32(uint32_t x) { return c_v256_dup_32(x); }
SIMD_INLINE v256 v256_dup_64(uint32_t x) { return c_v256_dup_64(x); }

typedef uint32_t sad256_internal;
SIMD_INLINE sad256_internal v256_sad_u8_init() { return c_v256_sad_u8_init(); }
SIMD_INLINE sad256_internal v256_sad_u8(sad256_internal s, v256 a, v256 b) {
  return c_v256_sad_u8(s, a, b);
}
SIMD_INLINE uint32_t v256_sad_u8_sum(sad256_internal s) {
  return c_v256_sad_u8_sum(s);
}
typedef uint32_t ssd256_internal;
SIMD_INLINE ssd256_internal v256_ssd_u8_init() { return c_v256_ssd_u8_init(); }
SIMD_INLINE ssd256_internal v256_ssd_u8(ssd256_internal s, v256 a, v256 b) {
  return c_v256_ssd_u8(s, a, b);
}
SIMD_INLINE uint32_t v256_ssd_u8_sum(ssd256_internal s) {
  return c_v256_ssd_u8_sum(s);
}

typedef uint32_t ssd256_internal_u16;
SIMD_INLINE ssd256_internal_u16 v256_ssd_u16_init() { return c_v256_ssd_u16_init(); }
SIMD_INLINE ssd256_internal_u16 v256_ssd_u16(ssd256_internal_u16 s, v256 a, v256 b) {
  return c_v256_ssd_u16(s, a, b);
}
SIMD_INLINE uint32_t v256_ssd_u16_sum(ssd256_internal_u16 s) {
  return c_v256_ssd_u16_sum(s);
}
SIMD_INLINE int64_t v256_dotp_s16(v256 a, v256 b) {
  return c_v256_dotp_s16(a, b);
}
SIMD_INLINE int64_t v256_dotp_s32(v256 a, v256 b) {
  return c_v256_dotp_s32(a, b);
}
SIMD_INLINE uint64_t v256_hadd_u8(v256 a) { return c_v256_hadd_u8(a); }

SIMD_INLINE v256 v256_or(v256 a, v256 b) { return c_v256_or(a, b); }
SIMD_INLINE v256 v256_xor(v256 a, v256 b) { return c_v256_xor(a, b); }
SIMD_INLINE v256 v256_and(v256 a, v256 b) { return c_v256_and(a, b); }
SIMD_INLINE v256 v256_andn(v256 a, v256 b) { return c_v256_andn(a, b); }

SIMD_INLINE v256 v256_add_8(v256 a, v256 b) { return c_v256_add_8(a, b); }
SIMD_INLINE v256 v256_add_16(v256 a, v256 b) { return c_v256_add_16(a, b); }
SIMD_INLINE v256 v256_sadd_s16(v256 a, v256 b) { return c_v256_sadd_s16(a, b); }
SIMD_INLINE v256 v256_add_32(v256 a, v256 b) { return c_v256_add_32(a, b); }
SIMD_INLINE v256 v256_padd_s16(v256 a) { return c_v256_padd_s16(a); }
SIMD_INLINE v256 v256_sub_8(v256 a, v256 b) { return c_v256_sub_8(a, b); }
SIMD_INLINE v256 v256_ssub_u8(v256 a, v256 b) { return c_v256_ssub_u8(a, b); }
SIMD_INLINE v256 v256_ssub_s8(v256 a, v256 b) { return c_v256_ssub_s8(a, b); }
SIMD_INLINE v256 v256_sub_16(v256 a, v256 b) { return c_v256_sub_16(a, b); }
SIMD_INLINE v256 v256_ssub_s16(v256 a, v256 b) { return c_v256_ssub_s16(a, b); }
SIMD_INLINE v256 v256_sub_32(v256 a, v256 b) { return c_v256_sub_32(a, b); }
SIMD_INLINE v256 v256_abs_s16(v256 a) { return c_v256_abs_s16(a); }

SIMD_INLINE v256 v256_mul_s16(v128 a, v128 b) { return c_v256_mul_s16(a, b); }
SIMD_INLINE v256 v256_mullo_s16(v256 a, v256 b) {
  return c_v256_mullo_s16(a, b);
}
SIMD_INLINE v256 v256_mulhi_s16(v256 a, v256 b) {
  return c_v256_mulhi_s16(a, b);
}
SIMD_INLINE v256 v256_mullo_s32(v256 a, v256 b) {
  return c_v256_mullo_s32(a, b);
}
SIMD_INLINE v256 v256_madd_s16(v256 a, v256 b) { return c_v256_madd_s16(a, b); }
SIMD_INLINE v256 v256_madd_us8(v256 a, v256 b) { return c_v256_madd_us8(a, b); }

SIMD_INLINE v256 v256_avg_u8(v256 a, v256 b) { return c_v256_avg_u8(a, b); }
SIMD_INLINE v256 v256_rdavg_u8(v256 a, v256 b) { return c_v256_rdavg_u8(a, b); }
SIMD_INLINE v256 v256_rdavg_u16(v256 a, v256 b) { return c_v256_rdavg_u16(a, b); }
SIMD_INLINE v256 v256_avg_u16(v256 a, v256 b) { return c_v256_avg_u16(a, b); }
SIMD_INLINE v256 v256_min_u8(v256 a, v256 b) { return c_v256_min_u8(a, b); }
SIMD_INLINE v256 v256_max_u8(v256 a, v256 b) { return c_v256_max_u8(a, b); }
SIMD_INLINE v256 v256_min_s8(v256 a, v256 b) { return c_v256_min_s8(a, b); }
SIMD_INLINE v256 v256_max_s8(v256 a, v256 b) { return c_v256_max_s8(a, b); }
SIMD_INLINE v256 v256_min_s16(v256 a, v256 b) { return c_v256_min_s16(a, b); }
SIMD_INLINE v256 v256_max_s16(v256 a, v256 b) { return c_v256_max_s16(a, b); }

SIMD_INLINE v256 v256_ziplo_8(v256 a, v256 b) { return c_v256_ziplo_8(a, b); }
SIMD_INLINE v256 v256_ziphi_8(v256 a, v256 b) { return c_v256_ziphi_8(a, b); }
SIMD_INLINE v256 v256_ziplo_16(v256 a, v256 b) { return c_v256_ziplo_16(a, b); }
SIMD_INLINE v256 v256_ziphi_16(v256 a, v256 b) { return c_v256_ziphi_16(a, b); }
SIMD_INLINE v256 v256_ziplo_32(v256 a, v256 b) { return c_v256_ziplo_32(a, b); }
SIMD_INLINE v256 v256_ziphi_32(v256 a, v256 b) { return c_v256_ziphi_32(a, b); }
SIMD_INLINE v256 v256_ziplo_64(v256 a, v256 b) { return c_v256_ziplo_64(a, b); }
SIMD_INLINE v256 v256_ziphi_64(v256 a, v256 b) { return c_v256_ziphi_64(a, b); }
SIMD_INLINE v256 v256_ziplo_128(v256 a, v256 b) {
  return c_v256_ziplo_128(a, b);
}
SIMD_INLINE v256 v256_ziphi_128(v256 a, v256 b) {
  return c_v256_ziphi_128(a, b);
}
SIMD_INLINE v256 v256_zip_8(v128 a, v128 b) { return c_v256_zip_8(a, b); }
SIMD_INLINE v256 v256_zip_16(v128 a, v128 b) { return c_v256_zip_16(a, b); }
SIMD_INLINE v256 v256_zip_32(v128 a, v128 b) { return c_v256_zip_32(a, b); }
SIMD_INLINE v256 v256_unziplo_8(v256 a, v256 b) {
  return c_v256_unziplo_8(a, b);
}
SIMD_INLINE v256 v256_unziphi_8(v256 a, v256 b) {
  return c_v256_unziphi_8(a, b);
}
SIMD_INLINE v256 v256_unziplo_16(v256 a, v256 b) {
  return c_v256_unziplo_16(a, b);
}
SIMD_INLINE v256 v256_unziphi_16(v256 a, v256 b) {
  return c_v256_unziphi_16(a, b);
}
SIMD_INLINE v256 v256_unziplo_32(v256 a, v256 b) {
  return c_v256_unziplo_32(a, b);
}
SIMD_INLINE v256 v256_unziphi_32(v256 a, v256 b) {
  return c_v256_unziphi_32(a, b);
}
SIMD_INLINE v256 v256_unpack_u8_s16(v128 a) { return c_v256_unpack_u8_s16(a); }
SIMD_INLINE v256 v256_unpacklo_u8_s16(v256 a) {
  return c_v256_unpacklo_u8_s16(a);
}
SIMD_INLINE v256 v256_unpackhi_u8_s16(v256 a) {
  return c_v256_unpackhi_u8_s16(a);
}
SIMD_INLINE v256 v256_pack_s32_s16(v256 a, v256 b) {
  return c_v256_pack_s32_s16(a, b);
}
SIMD_INLINE v256 v256_pack_s32_u16(v256 a, v256 b) {
  return c_v256_pack_s32_u16(a, b);
}
SIMD_INLINE v256 v256_pack_s16_u8(v256 a, v256 b) {
  return c_v256_pack_s16_u8(a, b);
}
SIMD_INLINE v256 v256_pack_s16_s8(v256 a, v256 b) {
  return c_v256_pack_s16_s8(a, b);
}
SIMD_INLINE v256 v256_unpack_u16_s32(v128 a) {
  return c_v256_unpack_u16_s32(a);
}
SIMD_INLINE v256 v256_unpack_s16_s32(v128 a) {
  return c_v256_unpack_s16_s32(a);
}
SIMD_INLINE v256 v256_unpacklo_u16_s32(v256 a) {
  return c_v256_unpacklo_u16_s32(a);
}
SIMD_INLINE v256 v256_unpacklo_s16_s32(v256 a) {
  return c_v256_unpacklo_s16_s32(a);
}
SIMD_INLINE v256 v256_unpackhi_u16_s32(v256 a) {
  return c_v256_unpackhi_u16_s32(a);
}
SIMD_INLINE v256 v256_unpackhi_s16_s32(v256 a) {
  return c_v256_unpackhi_s16_s32(a);
}
SIMD_INLINE v256 v256_shuffle_8(v256 a, v256 pattern) {
  return c_v256_shuffle_8(a, pattern);
}
SIMD_INLINE v256 v256_pshuffle_8(v256 a, v256 pattern) {
  return c_v256_pshuffle_8(a, pattern);
}

SIMD_INLINE v256 v256_cmpgt_s8(v256 a, v256 b) { return c_v256_cmpgt_s8(a, b); }
SIMD_INLINE v256 v256_cmplt_s8(v256 a, v256 b) { return c_v256_cmplt_s8(a, b); }
SIMD_INLINE v256 v256_cmpeq_8(v256 a, v256 b) { return c_v256_cmpeq_8(a, b); }
SIMD_INLINE v256 v256_cmpgt_s16(v256 a, v256 b) {
  return c_v256_cmpgt_s16(a, b);
}
SIMD_INLINE v256 v256_cmplt_s16(v256 a, v256 b) {
  return c_v256_cmplt_s16(a, b);
}
SIMD_INLINE v256 v256_cmpeq_16(v256 a, v256 b) { return c_v256_cmpeq_16(a, b); }

SIMD_INLINE v256 v256_shl_8(v256 a, unsigned int c) {
  return c_v256_shl_8(a, c);
}
SIMD_INLINE v256 v256_shr_u8(v256 a, unsigned int c) {
  return c_v256_shr_u8(a, c);
}
SIMD_INLINE v256 v256_shr_s8(v256 a, unsigned int c) {
  return c_v256_shr_s8(a, c);
}
SIMD_INLINE v256 v256_shl_16(v256 a, unsigned int c) {
  return c_v256_shl_16(a, c);
}
SIMD_INLINE v256 v256_shr_u16(v256 a, unsigned int c) {
  return c_v256_shr_u16(a, c);
}
SIMD_INLINE v256 v256_shr_s16(v256 a, unsigned int c) {
  return c_v256_shr_s16(a, c);
}
SIMD_INLINE v256 v256_shl_32(v256 a, unsigned int c) {
  return c_v256_shl_32(a, c);
}
SIMD_INLINE v256 v256_shr_u32(v256 a, unsigned int c) {
  return c_v256_shr_u32(a, c);
}
SIMD_INLINE v256 v256_shr_s32(v256 a, unsigned int c) {
  return c_v256_shr_s32(a, c);
}

SIMD_INLINE v256 v256_shr_n_byte(v256 a, const unsigned int n) {
  return c_v256_shr_n_byte(a, n);
}
SIMD_INLINE v256 v256_shl_n_byte(v256 a, const unsigned int n) {
  return c_v256_shl_n_byte(a, n);
}
SIMD_INLINE v256 v256_shl_n_8(v256 a, const unsigned int n) {
  return c_v256_shl_n_8(a, n);
}
SIMD_INLINE v256 v256_shl_n_16(v256 a, const unsigned int n) {
  return c_v256_shl_n_16(a, n);
}
SIMD_INLINE v256 v256_shl_n_32(v256 a, const unsigned int n) {
  return c_v256_shl_n_32(a, n);
}
SIMD_INLINE v256 v256_shr_n_u8(v256 a, const unsigned int n) {
  return c_v256_shr_n_u8(a, n);
}
SIMD_INLINE v256 v256_shr_n_u16(v256 a, const unsigned int n) {
  return c_v256_shr_n_u16(a, n);
}
SIMD_INLINE v256 v256_shr_n_u32(v256 a, const unsigned int n) {
  return c_v256_shr_n_u32(a, n);
}
SIMD_INLINE v256 v256_shr_n_s8(v256 a, const unsigned int n) {
  return c_v256_shr_n_s8(a, n);
}
SIMD_INLINE v256 v256_shr_n_s16(v256 a, const unsigned int n) {
  return c_v256_shr_n_s16(a, n);
}
SIMD_INLINE v256 v256_shr_n_s32(v256 a, const unsigned int n) {
  return c_v256_shr_n_s32(a, n);
}

typedef uint32_t sad256_internal_u16;
SIMD_INLINE sad256_internal_u16 v256_sad_u16_init() { return c_v256_sad_u16_init(); }
SIMD_INLINE sad256_internal_u16 v256_sad_u16(sad256_internal_u16 s, v256 a, v256 b) {
  return c_v256_sad_u16(s, a, b);
}
SIMD_INLINE uint32_t v256_sad_u16_sum(sad256_internal_u16 s) {
  return c_v256_sad_u16_sum(s);
}

SIMD_INLINE v256 v256_shr_n_word(v256 a, const unsigned int n) { return c_v256_shr_n_word(a, n); }
SIMD_INLINE v256 v256_shl_n_word(v256 a, const unsigned int n) { return c_v256_shl_n_word(a, n); }


#endif /* _V256_INTRINSICS_H */
