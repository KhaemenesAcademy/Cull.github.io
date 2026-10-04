#include "cull.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
typedef struct{const char*s;size_t n,p;} cur;
static void ws(cur*c){while(c->p<c->n&&isspace((unsigned char)c->s[c->p]))c->p++;}
static int lit(cur*c,const char*x){size_t m=strlen(x);ws(c);if(m>c->n-c->p||memcmp(c->s+c->p,x,m))return 0;c->p+=m;return 1;}
static void dg(cull_diagnostic*d,cull_status s,size_t p,const char*m){if(!d)return;d->status=s;d->offset=p;(void)snprintf(d->message,sizeof(d->message),"%s",m);}
static int num(cur*c,int64_t*out){uint64_t v=0;int neg=0,any=0;ws(c);if(c->p<c->n&&c->s[c->p]=='-'){neg=1;c->p++;}while(c->p<c->n&&isdigit((unsigned char)c->s[c->p])){unsigned d=(unsigned)(c->s[c->p++]-'0');if(v>(UINT64_MAX-d)/10u)return 0;v=v*10u+d;any=1;}if(!any)return 0;if(!neg){if(v>(uint64_t)INT64_MAX)return 0;*out=(int64_t)v;}else{if(v>(uint64_t)INT64_MAX+1u)return 0;*out=v==(uint64_t)INT64_MAX+1u?INT64_MIN:-(int64_t)v;}return 1;}
cull_status cull_parse_translation_unit(const char*s,size_t n,cull_program*out,cull_diagnostic*d){cur c;int64_t r;if(!s||!out){dg(d,CULL_EINVAL,0,"null input");return CULL_EINVAL;}c.s=s;c.n=n;c.p=0;if(!lit(&c,"int")||!lit(&c,"main")||!lit(&c,"(")||!lit(&c,"void")||!lit(&c,")")||!lit(&c,"{")||!lit(&c,"return")||!num(&c,&r)||!lit(&c,";")||!lit(&c,"}")){dg(d,CULL_EUNSUPPORTED,c.p,"alpha1 accepts only int main(void){return INTEGER;}");return CULL_EUNSUPPORTED;}ws(&c);if(c.p!=c.n){dg(d,CULL_EUNSUPPORTED,c.p,"trailing unsupported source");return CULL_EUNSUPPORTED;}out->main_return_value=r;dg(d,CULL_OK,c.p,"accepted");return CULL_OK;}
