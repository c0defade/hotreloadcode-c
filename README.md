# Hot Code Reloading in C

Checkout blogpost: [`codefade`](https://blog.codefade.com/posts/94386_hot_code_reloading_in_c/)

## TL;DR
1. Branch `master`
  This branch has a simple code example showing the usage of dynamic shared library in C.

      #### BUILD steps
  ```
  $ ./build_libmath.sh && ./build_main.sh && ./run_main.sh
  ```
2. Branch `hotreload`
   In this branch, the code in `master` has been converted to use dynamically loaded library.
   
      #### BUILD steps
  ```
  $ ./build_libmath.sh && ./build_libhotreload.sh && ./build_main.sh && ./run_main.sh
  ```
3. Branch `non_hotreload`
   In this branch, the code in `hotreload` has been converted to use dynamic shared library by
   removing the directive `HOTRELOAD` and changing the compilation steps in `build_main.sh`

      #### BUILD steps
  ```
  $ ./build_libmath.sh && ./build_main.sh && ./run_main.sh
  ```
