#ifndef STOS_CULL_H
#define STOS_CULL_H
#include <stddef.h>
#include <stdint.h>
#define CULL_VERSION "0.1.0-alpha1"
#define CULL_DIAG_CAP 256u
typedef enum { CULL_OK=0,CULL_EINVAL,CULL_EPARSE,CULL_EUNSUPPORTED,CULL_EOVERFLOW,CULL_EBACKEND } cull_status;
typedef enum { CULL_TARGET_NONE=0,CULL_TARGET_X86_64_MACHO,CULL_TARGET_X86_64_ELF,CULL_TARGET_AARCH64_MACHO,CULL_TARGET_AARCH64_ELF,CULL_TARGET_X86_64_PE,CULL_TARGET_AARCH64_PE } cull_target;
typedef struct { cull_status status; size_t offset; char message[CULL_DIAG_CAP]; } cull_diagnostic;
typedef struct { int64_t main_return_value; } cull_program;
cull_status cull_parse_translation_unit(const char*,size_t,cull_program*,cull_diagnostic*);
const char *cull_status_name(cull_status);
const char *cull_target_name(cull_target);
#endif
