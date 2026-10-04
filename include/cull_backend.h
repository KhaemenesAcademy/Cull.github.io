#ifndef STOS_CULL_BACKEND_H
#define STOS_CULL_BACKEND_H
#include "cull.h"
typedef struct { unsigned char *bytes; size_t capacity,used; } cull_image;
cull_status cull_emit_image(cull_target,const cull_program*,cull_image*,cull_diagnostic*);
#endif
