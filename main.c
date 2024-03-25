#include<stdio.h>
#define HOTRELOAD 1

#ifdef HOTRELOAD
#include "hotreload.h"
#else
#include "math.h"
#endif

int main() {
   // load symbols from the shared library.

#ifdef HOTRELOAD
   hot_reload_init();
   register_hr_signal(SIGINT);
#endif
   char c;
   while(1) {
      printf("Version: %s\n", version());
      printf("Add 1+2: %d\n", add(1,2));
      scanf("%c", &c);
   }
   return 0;
}
