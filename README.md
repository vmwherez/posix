# posix
C and POSIX things.
Whereas I have a Starlette app (`peregrine`, currently private) with a Preact front lending itself toward Data Science and AI, 
  ...which also involves some orchestration things, containers, databases...
Whereas I have a C/C++/Python DSP effort, lending itself toward audio application development,
  ...which moves toward CMake and a proper IDE...

This repo will be collecting my work in C and will use `zsh`, `vim`, and `make`. 
Hopefully I can have a bunch of little examples without need for something like `cmake`. 

Much of this work should be prerequisite to [sine](http://github.com/vmwherez).
It is also notable that my Obsidian notes connect these worlds of all active projects.

## info 

```
man info
info man
man 3 printf
```

## books

I've kind of been flirting with all of these for some time now.

- Learn C The Hard Way - Zed Shaw
- ThinkOS - Alan Downey
- Beej's Guide to Network Concepts (Python)
- Beej’s Guide to C Programming 
- Beej’s Guide to Interprocess Communication
- Computer Science from the Bottom Up - Ian Wienand
- The Linux Programmer’s Guide - Sven Goldt et al 

A Programmer’s Introduction to Mathematics - Jeremy Kun (Python)
> Even though it doesn't quite seem to fit... something about this book with its little examples also sort of feels like it belongs here.
> This is a little strange because I don't really intend to get into Dynamic Programming or Competitive Programming whatever other Discrete Math or Algorithms here.
> That would sort of belong in another thing, maybe. Maybe it should expand here. *If you are a recruiter or otherwise inspecting me, please note I passed Google FooBar in 2018.*

## a note about Rust, etc

I spent some time earlier this year going through Rustlings and outlining some of the other available books. I actually thought I would learn Rust *first* for some reason... or along side... but no. I'm heavily into C/C++ now for more than one reason. 

That said, a touchpoint which comes to mind is the kernel- a place where realtime audio and memory safety come together. And after all, Rust is now in the Linux kernel.

So, maybe I'll include Rust things here as secondary or tertiary goal. I had been trying to compare Go, Rust and C. Go is the only thing I've actually used at work. And then there is Mojo and the GIL stuff in Python...

#### Rust in the Linux Kernel

-   Linus's commit: [https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=8aebac82933ff1a7c8eede18cab11e1115e2062b](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=8aebac82933ff1a7c8eede18cab11e1115e2062b)
-   [The Case for Writing a Kernel in Rust](https://www.cs.virginia.edu/~bjc8c/papers/levy17rustkernel.pdf)
-   [https://www.memorysafety.org/blog/rust-in-linux-just-the-beginning/](https://www.memorysafety.org/blog/rust-in-linux-just-the-beginning/)

## tooling

I have a bunch of notes from the last several years on `i3` and `vim` and `zsh` and so on which I kind of want to put in here right away... but this current approach already feels more organized so maybe I will leave space instead.

> *dotfiles?*

### zsh

#### fzf

#### tmux

### vim

#### gdb

*What was the issue with this on MacOS?* 

##### GEF

*Don't forget this is working in iSH (Busybox).* All of these kinds of toy examples should work in that environment.

#### lldb

#### r2

## links 

- https://stackoverflow.com/questions/1780599/what-is-the-meaning-of-posix
