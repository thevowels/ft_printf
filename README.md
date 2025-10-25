# ft_printf
## Overview

`ft_printf` is a custom implementation of the standard `printf` function in C. This project demonstrates a deep understanding of formatted output handling, variadic functions, and low-level string manipulation.


## Features

- Zero external dependencies beyond standard C library
- Memory-efficient implementation
- Cross-platform compatibility
- Extensive error handling and validation

## Variadic Functions

This implementation heavily utilizes C's variadic function capabilities using `stdarg.h`:
- `va_list` - Type for holding variable argument information
- `va_start()` - Initialize variable argument processing
- `va_arg()` - Retrieve next argument from the list
- `va_end()` - Clean up variable argument processing

For detailed documentation on variadic functions, refer to:
- [C Standard Library Documentation](https://en.cppreference.com/w/c/variadic)
- [GNU C Manual - Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

## Getting Started

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello, %s! Number: %d\n", "World", 42);
	return (0);
}
```

## Building

```bash
make
```