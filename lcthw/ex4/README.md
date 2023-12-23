# Learn C The Hard Way Exercise 4: debugging
Skipping 3 about `printf` and escape sequences.
Also, couldn't find the companion video. 
He mentions a newer tool AddressSanitizer which I have been meaning to play with. 

Note to maybe review all of these in Busybox (iSH) where I have GEF installed. 

So for now I will make my own exercise.

https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer

https://clang.llvm.org/docs/AddressSanitizer.html

```
Shadow bytes around the buggy address:
  0x1c27ffffffb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1c27ffffffc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1c27ffffffd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1c27ffffffe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1c27fffffff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x1c2800000000: fa fa fa fa fa fa fa fa[fd]fd fd fd fd fd fd fd
  0x1c2800000010: fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd
  0x1c2800000020: fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd
  0x1c2800000030: fd fd fd fd fd fd fd fd fd fd fa fa fa fa fa fa
  0x1c2800000040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x1c2800000050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
```

TODO: GDB 





