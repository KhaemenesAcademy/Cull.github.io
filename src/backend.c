#include "cull_backend.h"
#include <stdio.h>
cull_status cull_emit_image(cull_target t,const cull_program*p,cull_image*i,cull_diagnostic*d){(void)t;(void)p;(void)i;if(d){d->status=CULL_EUNSUPPORTED;d->offset=0;(void)snprintf(d->message,sizeof(d->message),"direct native image backend is the next certification stage; delegation forbidden");}return CULL_EUNSUPPORTED;}
