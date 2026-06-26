*This activity has been created as part of the 42 curriculum by hsilin.*

## Description
`get_next_line` is a function designed in C to read text from a file descriptor line by line. Whether reading from a standard text file or standard input, each successive call to this function returns the next line available (including the terminating `\n`). It returns `NULL` when the end of the file (EOF) is reached or if an error occurs.

---

## Instructions
### Compilation 
To use `get_next_line` in your C projects:
1. Include the header in your source file:
```C
#include "get_next_line.h"
```

2. Compile your program by linking the library:
- The project requires the buffer size to be dynamically defined at compilation using the `-D BUFFER_SIZE=n` flag. It compiles with various buffer values (n= 1, 42, 4096, or 9999 ...). For example:
```Bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

3. Run the compiled binary directly to execute the test suite:
```bash
./gnl_test
```

## Resources & AI Usage Statement
References
- Static Variables in C (GeeksforGeeks)
- Linux File Descriptors Explained
- [42 School Get_Next_Line Subject Requirements]

This project utilized an AI assistant during development for the following purposes:
- Concept Clarification: Gained insight into the persistence and local scope of static variables, and explored the impact of Stack vs. Heap allocation on extreme BUFFER_SIZE values.
- Code Review & Debugging: Assisted in preventing memory leaks by optimizing the cleanup sequence.
- Test Design: Followed recommendations to build a `main` to test cases, including missing files and standard input. 