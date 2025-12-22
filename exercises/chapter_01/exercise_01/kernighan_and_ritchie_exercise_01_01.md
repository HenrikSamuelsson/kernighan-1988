# K&R Exercise 1.1

Solution to Exercise 1.1 from Kernighan and Ritchie (1988).

## Instruction

Compile and run a minimal "Hello world!" program written in C. After the program
successfully runs, intentionally introduce errors and observe the resulting
compiler diagnostics.

## Solution

There is an example program in the book but I implemented my own version of the program, using a slightly more modern style than the example shown in the book.

### Baseline Implementation

This version compiles and runs as expected.

<https://github.com/HenrikSamuelsson/kernighan-and-ritchie-1988/blob/ec1e313902b5303929351a99f11583ecbf938f28/exercises/chapter_01/exercise_01/main.c#L1-L8>

```powershell
> gcc -std=c11 -Wall -Wextra -Wpedantic main.c
PS C:\dev\kernighan-and-ritchie-1988\exercises\chapter_01\exercise_01> ./a.exe
Hello, world!
```

### Fault Injection: Missing Include

Intentionally left out the line `#include <stdio.h>` to see what error messages this causes when compiling.

<https://github.com/HenrikSamuelsson/kernighan-and-ritchie-1988/blob/ec1e313902b5303929351a99f11583ecbf938f28/exercises/chapter_01/exercise_01/main_missing_include.c#L1-L7>

```powershell
> gcc -std=c11 -Wall -Wextra -Wpedantic .\main_missing_include.c 
.\main_missing_include.c: In function 'main':
.\main_missing_include.c:5:5: error: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    5 |     printf("Hello, world!\n");
      |     ^~~~~~
.\main_missing_include.c:2:1: note: include '<stdio.h>' or provide a declaration of 'printf'
    1 | #include <stdlib.h>
  +++ |+#include <stdio.h>
    2 |
.\main_missing_include.c:5:5: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
    5 |     printf("Hello, world!\n");
      |     ^~~~~~
.\main_missing_include.c:5:5: note: include '<stdio.h>' or provide a declaration of 'printf'
```

### Fault Injection: Missing Semicolon

Intentionally left out a semicolon to see what error messages this causes when compiling.

<https://github.com/HenrikSamuelsson/kernighan-and-ritchie-1988/blob/ec1e313902b5303929351a99f11583ecbf938f28/exercises/chapter_01/exercise_01/main_missing_semicolon.c#L1-L8>

```powershell
> gcc -std=c11 -Wall -Wextra -Wpedantic .\main_missing_semicolon.c
.\main_missing_semicolon.c: In function 'main':
.\main_missing_semicolon.c:8:1: error: expected ';' before '}' token
    8 | }
      | ^
```

## Answer

The exercise demonstrates the basic structure of a minimal C program and how
common syntax and declaration errors are reported by the compiler. It also
serves as a practical introduction to compiling and running a C program from
the command line using GCC on Windows.

## References

Kernighan, B. W., & Ritchie, D. M. (1988). *The C programming language* (2nd ed.). Prentice Hall.
