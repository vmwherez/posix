#### debugging `ex15` segmentation fault in `lldb`

```
(lldb) run
Process 6341 launched: '/Users/mvm/Desktop/posix/lcthw/ex15/build/ex' (x86_64)
Process 6341 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x40)
    frame #0: 0x00007fff6a6ebe52 libsystem_platform.dylib`_platform_strlen + 18
libsystem_platform.dylib`_platform_strlen:
->  0x7fff6a6ebe52 <+18>: pcmpeqb (%rdi), %xmm0
    0x7fff6a6ebe56 <+22>: pmovmskb %xmm0, %esi
    0x7fff6a6ebe5a <+26>: andq   $0xf, %rcx
    0x7fff6a6ebe5e <+30>: orq    $-0x1, %rax
Target 0: (ex) stopped.
(lldb) bt
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x40)
  * frame #0: 0x00007fff6a6ebe52 libsystem_platform.dylib`_platform_strlen + 18
    frame #1: 0x00007fff6a587891 libsystem_c.dylib`__vfprintf + 5379
    frame #2: 0x00007fff6a5adad3 libsystem_c.dylib`__v2printf + 475
    frame #3: 0x00007fff6a5862b2 libsystem_c.dylib`vfprintf_l + 54
    frame #4: 0x00007fff6a58441e libsystem_c.dylib`printf + 174
    frame #5: 0x0000000100003da1 ex`main + 145
    frame #6: 0x00007fff6a4f5cc9 libdyld.dylib`start + 1
```

