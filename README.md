Requirements
============

* gcc with c++11
* STL
* cmake

Installation
============

```
$ mkdir debug
$ cd debug
$ cmake ..
$ make
$ cd ..
```

Running
=======

```
$ ./debug/asm input.asm
```

A simple input file may contain something like this:

mov ax,42
print ax
