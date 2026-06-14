*This activity has been created as part of the 42 curriculum by hsilin.*

# Libft

## Description

Libft is a 42 curriculum project whose goal is to recreate a small C standard-style library from scratch. The project builds a static library named `libft.a` containing utility functions for character checks, string handling, memory manipulation, number conversion, file descriptor output, and linked list operations.

The activity is designed to strengthen core C skills: pointer manipulation, memory allocation, header organization, Makefile usage, and careful reproduction of well-known libc behavior.

## Instructions

Compile the library from the repository root:

```sh
make
```

This creates:

```text
libft.a
```

Clean object files:

```sh
make clean
```

Remove object files and the compiled library:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

To use the library in another C file, include the header:

```c
#include "libft.h"
```

Then compile with `libft.a`, for example:

```sh
cc -Wall -Wextra -Werror main.c libft.a
```

## Library Details

The library is declared in `libft.h` and compiled into the static archive `libft.a`.

### Character Functions

These functions inspect or convert single characters:

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

### Memory Functions

These functions work directly with raw memory:

- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

### String Functions

These functions measure, search, compare, copy, duplicate, join, trim, split, and transform C strings:

- `ft_strlen`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_strmapi`
- `ft_striteri`

### Conversion Functions

These functions convert between strings and integers:

- `ft_atoi`
- `ft_itoa`

### File Descriptor Output

These functions write characters, strings, lines, or integers to a given file descriptor:

- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Linked List Functions

The bonus linked list functions use the `t_list` structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

Available linked list helpers:

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Resources

Classic references used for this topic:

- `man strlen`, `man memcpy`, `man calloc`, `man atoi`, and other libc manual pages
- The C reference for standard library behavior: <https://en.cppreference.com/w/c>
- GNU C Library manual: <https://www.gnu.org/software/libc/manual/>
- 42 Libft subject PDF and project instructions

AI was used as a learning assistant during this activity. It helped explain C concepts, review function prototypes, point out edge cases, check small implementation snippets, synchronize project files, and draft this README. The actual library implementation and final responsibility for correctness remain with the student.
