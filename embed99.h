/* SPDX-License-Identifier: 0BSD */
/*
 * embed99.h — a simple single-header library under 200 lines for embedding
 * files into your C/C++ binary.
 */
/* TODO: MSVC? */

#ifndef EMBED_H_
#define EMBED_H_

#include <stddef.h>
#include <stdint.h>

#ifndef EMBED_SECTION
#define EMBED_SECTION ".rodata"
#endif

#ifndef EMBED_ALIGN
#define EMBED_ALIGN ".p2align 3"
#endif

#ifndef EMBED_EXTERN
#define EMBED_EXTERN extern
#endif

#ifndef EMBED_STATIC
#define EMBED_STATIC static
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * er — embedded resource handle
 * @d: pointer to data
 * @e: pointer to end of data
 */
typedef struct {
  const void *d;
  const void *e;
} er;

/**
 * embed(name,path) — embed binary file into .rodata (8-byte aligned)
 *
 * paths in `embed()` are resolved by the assembler relative to its working
 * directory or include path.
 *
 * embed(foo, "assets/foo.bin");
 *   // -> extern const er foo;
 *   //    edata(&foo), elen(&foo)
 */
#define e99_embed(name, path)                                                  \
  EMBED_EXTERN const uint8_t _b_##name##_s[];                                  \
  EMBED_EXTERN const uint8_t _b_##name##_e[];                                  \
  __asm__(".section " EMBED_SECTION "\n\t" EMBED_ALIGN "\n\t"                  \
          ".global _b_" #name "_s\n\t"                                         \
          "_b_" #name "_s:\n\t"                                                \
          ".incbin \"" path "\"\n\t"                                           \
          ".global _b_" #name "_e\n\t"                                         \
          "_b_" #name "_e:\n\t"                                                \
          ".previous\n");                                                      \
  EMBED_STATIC const er name = {.d = _b_##name##_s, .e = _b_##name##_e};

/**
 * embedsec(name,path,sec) — embed file into custom section
 *
 * sec must be a quoted section name, e.g. ".mysec".
 */
#define e99_embedsec(name, path, sec)                                          \
  EMBED_EXTERN const uint8_t _b_##name##_s[];                                  \
  EMBED_EXTERN const uint8_t _b_##name##_e[];                                  \
  __asm__(".section " sec "\n\t" EMBED_ALIGN "\n\t"                            \
          ".global _b_" #name "_s\n\t"                                         \
          "_b_" #name "_s:\n\t"                                                \
          ".incbin \"" path "\"\n\t"                                           \
          ".global _b_" #name "_e\n\t"                                         \
          "_b_" #name "_e:\n\t"                                                \
          ".previous\n");                                                      \
  EMBED_STATIC const er name = {.d = _b_##name##_s, .e = _b_##name##_e};

/**
 * edata(r) — get pointer to embedded data
 * elen(r)  — get length in bytes
 */
static inline const void *e99_edata(const er *r) { return r->d; }
static inline size_t e99_elen(const er *r) {
  const uint8_t *s = (const uint8_t *)r->d;
  const uint8_t *e = (const uint8_t *)r->e;
  return (size_t)(e - s);
}

#ifdef __cplusplus
}
#endif

#endif /* EMBED_H */
