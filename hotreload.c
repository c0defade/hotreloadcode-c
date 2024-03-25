#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<dlfcn.h>
#include "typeinfo.h"

#define LOGSYM(sym) printf("Loaded %s at: 0x%x\n", #sym, sym)

void *handle = NULL;
func_add_t add_ld = NULL;
func_version_t version_ld = NULL;

void hot_reload_init() {
   if (handle) {
      // unload if so already loaded.
      dlclose(handle);
   }
   handle = dlopen("libmath.so", RTLD_LAZY);
   if (!handle) {
      printf("Error: %s\n", dlerror());
      exit(1);
   }
   // load symbols
   add_ld = dlsym(handle, "add");
   version_ld = dlsym(handle, "version");
   LOGSYM(add_ld);
   LOGSYM(version_ld);
}

void register_hr_signal(int SIGNAL_CODE ) {
   signal( SIGNAL_CODE, hot_reload_init );
}
