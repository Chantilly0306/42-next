*This activity has been created as part of the 42 curriculum by hsilin.*

## Description
The goal of this project is to recode the famous C library function `printf()`. The implemented library, `libftprintf.a`, mimics the behavior of the original `printf()` regarding the basic format conversions without incorporating the complex buffer management of the standard libc version. 

### Supported Conversions
The function handles the following standard conversions:
* `%c` - Prints a single character.
* `%s` - Prints a string (handles NULL pointers safely by printing `(null)`).
* `%p` - Prints a void pointer argument in hexadecimal format (prefixed with `0x`, handles NULL by printing `(nil)`).
* `%d` / `%i` - Prints a signed base 10 decimal number (handles `INT_MIN` cleanly).
* `%u` - Prints an unsigned base 10 decimal number.
* `%x` - Prints a number in lowercase hexadecimal format (base 16).
* `%X` - Prints a number in uppercase hexadecimal format (base 16).
* `%%` - Prints a single percent sign.

---

## Instructions

### Compilation
The library is compiled using the provided `Makefile`. It includes the mandatory rules: `all`, `clean`, `fclean`, and `re`. To build the library, simply run:

```bash
make
```
This will compile the source files with -Wall -Wextra -Werror flags using cc and generate the static library libftprintf.a at the root of the repository.

### Usage
To use `ft_printf` in your own C projects:
1. Include the header in your source file:
```C
#include "ft_printf.h"
```
2. Compile your program by linking the library:
```Bash
cc main.c libftprintf.a
```

## Resources & AI Usage Statement
References
- C Variadic Functions Documentation
- [42 School Printf Subject Requirements]

AI Usage & Control Practices
In alignment with the 42 foundational phase guidelines regarding AI assistance, AI tools were utilized with strict control and critical evaluation. No direct code generation or copy-pasting shortcuts were utilized for the core formatting algorithms. Every logic pathway suggested or discussed with the AI tool was thoroughly cross-examined through edge-case unit testing (e.g., verifying precise return values, INT_MIN boundaries, and memory pointer stability against the standard libc printf).