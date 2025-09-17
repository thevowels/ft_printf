# ft_printf  

This subfolder contains one of my implementations of the `ft_printf` function. The goal of this project is to replicate the behavior of the standard `printf` function in C, while adhering to specific constraints, such as clamping the code to a single file.  

## Features  
- Handles basic format specifiers: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.  
- Supports variable argument lists using `stdarg.h`.  
- Optimized for simplicity and readability within a single file.  

## Usage  
To use this implementation, include the `ft_printf.c` file in your project and compile it along with your code.  

```bash  
gcc ft_printf.c your_program.c -o your_program  
./your_program  
```  

## Reference Links  
- [printf (man page)](https://man7.org/linux/man-pages/man3/printf.3.html)  
- [Variadic Functions in C](https://en.wikipedia.org/wiki/Variadic_function)  
- [ft_printf Project Description (42)](https://github.com/42Paris/42cursus)  

## Notes  
This implementation is designed for educational purposes and may not cover all edge cases or extended format specifiers.  
