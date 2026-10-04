#ifndef STOS_CULL_SHA256_H
#define STOS_CULL_SHA256_H
#include <stddef.h>
#include <stdint.h>
typedef struct { uint32_t h[8]; uint64_t total; uint8_t block[64]; size_t used; } cull_sha256_ctx;
void cull_sha256_init(cull_sha256_ctx*);
void cull_sha256_update(cull_sha256_ctx*,const void*,size_t);
void cull_sha256_final(cull_sha256_ctx*,uint8_t[32]);
void cull_sha256_hex(const void*,size_t,char[65]);
#endif
