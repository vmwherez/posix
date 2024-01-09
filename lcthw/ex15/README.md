#### debugging the segmentation fault in `ex15` using `lldb`

```bash
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

#### debugging the segentation fault in `ex15` using `gdb` / `GEF`

`next lay` is cool but the layout was breaking in GEF in `iSH`.

```bash
$ gdb ./build/ex
(gdb) break main
(gdb) run 
... [ breaks at function main ] ...
(gdb) next
... [ step through each line of C, nexti steps through assembly ] ...
... [ it will stop on the SIGSEGV (segfault) ] ...

$eax   : 0x41      
$ebx   : 0xf7ffaf88  →  0x00095ec8
$ecx   : 0x0       
$edx   : 0x7fffffff
$esp   : 0xffffd920  →  0xf7ffaf88  →  0x00095ec8
$ebp   : 0xffffffff
$esi   : 0x7fffffff
$edi   : 0x41      
$eip   : 0xf7fb5bc7  →  <memchr+24> movzx ebx, BYTE PTR [eax]
$eflags: [zero carry parity adjust sign TRAP interrupt direction overflow resume virtualx86 identification]
$cs: 0x00 $ss: 0x00 $ds: 0x00 $es: 0x00 $fs: 0x00 $gs: 0x00 
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── stack ────
0xffffd920│+0x0000: 0xf7ffaf88  →  0x00095ec8    ← $esp
0xffffd924│+0x0004: 0x7fffffff
0xffffd928│+0x0008: 0x00000041
0xffffd92c│+0x000c: 0xf7fb675c  →  <strnlen+32> add esp, 0x10
0xffffd930│+0x0010: 0x00000041
0xffffd934│+0x0014: 0x00000000
0xffffd938│+0x0018: 0x7fffffff
0xffffd93c│+0x001c: 0x7fffffff
───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── code:x86:32 ────
   0xf7fb5bc1 <memchr+18>      je     0xf7fb5bd2 <memchr+35>
   0xf7fb5bc3 <memchr+20>      test   edx, edx
   0xf7fb5bc5 <memchr+22>      je     0xf7fb5c16 <memchr+103>
 → 0xf7fb5bc7 <memchr+24>      movzx  ebx, BYTE PTR [eax]
   0xf7fb5bca <memchr+27>      cmp    ebx, ecx
   0xf7fb5bcc <memchr+29>      je     0xf7fb5be8 <memchr+57>
   0xf7fb5bce <memchr+31>      inc    eax
   0xf7fb5bcf <memchr+32>      dec    edx
   0xf7fb5bd0 <memchr+33>      jmp    0xf7fb5bbf <memchr+16>
───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── threads ────
[#0] Id 1, stopped 0xf7fb5bc7 in memchr (), reason: SIGSEGV
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── trace ────
[#0] 0xf7fb5bc7 → memchr()
[#1] 0xf7fb675c → strnlen()

──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
gef➤  backtrace
#0  0xf7fb5bc7 in memchr () from /lib/ld-musl-i386.so.1
#1  0xf7fb675c in strnlen () from /lib/ld-musl-i386.so.1
#2  0x7fffffff in ?? ()
#3  0xf7ffaf88 in ?? () from /lib/ld-musl-i386.so.1
Backtrace stopped: Cannot access memory at address 0x3


```

#### strlen() ?

```bash

ex15.c:19:39: warning: format specifies type 'char *' but the argument has type 'char' [-Wformat]
                printf("%s has %d years alive. \n", names[i], ages[i]);
                        ~~                          ^~~~~~~~
```


#### checking Zed Shaw's resources for errata

Where I was at was pretty far from what the fix was. Zed's version has a change which resolves all of the warnings:

```
int *cur_age = (int *)names
```

I wasn't completely off but I was tracking lines higher up, I was aware of some kind of type or init error around names. 
Still, good progress with debugging (`gdb` and `lldb`).
