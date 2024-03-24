#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

#define LOGSYM(sym) printf("Loaded %s at: 0x%x\n", #sym, sym);

void *handle = NULL;
// load symbols into function pointers
int (*add)(int,int);
char* (*version)();

void load_symbols() {
   handle = dlopen("libmath.so", RTLD_LAZY);
   if (!handle) {
      printf("Error: %s\n", dlerror());
      exit(1);
   }
   add = dlsym(handle, "add");
   version = dlsym(handle, "version");
   LOGSYM(add);
   LOGSYM(version);
}

int main() {
   // load symbols from the shared library.
   load_symbols();

   printf("Version: %s\n", (*version)());
   printf("Add 1+2: %d\n", (*add)(1,2));
   return 0;
}
