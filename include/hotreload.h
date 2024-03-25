#ifndef INCLUDE_HOTRELOAD_H
#define INCLUDE_HOTRELOAD_H

#include<signal.h>
#include "typeinfo.h"
void hot_reload_init();
void register_hr_signal(int);

extern func_add_t add_ld;
extern func_version_t version_ld;

#define add (*add_ld)
#define version (*version_ld)

#endif // INCLUDE_HOTRELOAD_H

