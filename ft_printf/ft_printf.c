/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:26:05 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/18 02:09:45 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

/**
 * @brief Prints a numeric value in a specified base.
 * 
 * This function prints a number in the specified base (10 or 16) and handles
 * formatting for signed integers, unsigned integers, and hexadecimal values.
 * It also supports uppercase and lowercase formatting for hexadecimal numbers.
 * 
 * @param base 
 *      The base to use for printing the number. Typically 10 (decimal) or 16 
 *		(hexadecimal).
 * @param upper 
 *      Determines the formatting for hexadecimal numbers:
 *      - 'u': Sets the base to 10 (decimal).
 *      - 'x': Uses lowercase letters for hexadecimal (e.g., "abcdef").
 *      - 'X': Uses uppercase letters for hexadecimal (e.g., "ABCDEF").
 * @param nb 
 *      The number to print. Can be a signed or unsigned integer.
 * @return int 
 *      The total number of characters written to the output.
 */
static int	ft_fpf_printbase(int base, int upper, long nb)
{
	char	*str_base[2];
	int		length;

	str_base[0] = "0123456789abcdef";
	str_base[1] = "0123456789ABCDEF";
	length = 0;
	if (upper == 'u')
		base = 10;
	if (upper == 'X')
		upper = 1;
	else if (upper == 'x' || upper == 'u')
		upper = 0;
	if (nb < 0)
	{
		nb *= -1;
		length += write(1, "-", 1);
	}
	if (nb < base)
		length += write(1, &str_base[upper][nb], 1);
	if (nb >= base)
	{
		length += ft_fpf_printbase(base, upper, (nb / base));
		length += write(1, &str_base[upper][nb % base], 1);
	}
	return (length);
}

/**
 * @brief Prints a string to the standard output.
 * 
 * This function writes the given string to the standard output. If the string
 * is NULL, it prints "(null)" instead. The function returns the total number
 * of characters written.
 * 
 * @param str 
 *      The string to print. If NULL, "(null)" is printed.
 * @return int 
 *      The total number of characters written to the output.
 */
static int	ft_fpf_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_fpf_printstr("(null)"));
	while (*str)
	{
		write(1, (str++), 1);
		i++;
	}
	return (i);
}

/**
 * @brief Handles formatting and printing for various specifiers.
 * 
 * This function processes format specifiers and prints the corresponding
 * arguments. It supports the following specifiers:
 * - 's': Prints a string.
 * - 'd' or 'i': Prints a signed integer in decimal format.
 * - 'u': Prints an unsigned integer in decimal format.
 * - 'x': Prints an unsigned integer in lowercase hexadecimal format.
 * - 'X': Prints an unsigned integer in uppercase hexadecimal format.
 * - 'p': Prints a pointer address in hexadecimal format.
 * - '%%': Prints a literal '%' character.
 * 
 * If an invalid specifier is encountered, the function writes the character
 * preceding the specifier and the specifier itself to the output.
 * 
 * @param args 
 *      The list of arguments passed to the function.
 * @param f 
 *      The current format specifier being processed.
 * @param length 
 *      A pointer to the total length of characters written so far.
 * @param ptr 
 *      A temporary variable used for pointer formatting.
 * 
 * @note The line `(*length) += write(1, (f - 1), (1 + (*f != '%')));` handles
 *       invalid specifiers or literal '%' characters. It writes the character
 *       preceding the current format specifier or the '%' itself to the output.
 *       - If `*f` is not '%', it writes two characters: the preceding character
 *         and the current one.
 *       - If `*f` is '%', it writes only the '%' character.
 */
static void	ft_formats(va_list args, const char *f, int *length,
		unsigned long long ptr)
{
	if (*f == 's')
		(*length) += ft_fpf_printstr(va_arg(args, char *));
	else if (*f == 'd' || *f == 'i')
		(*length) += ft_fpf_printbase(10, 0, va_arg(args, int));
	else if (*f == 'u' || *f == 'x' || *f == 'X')
		(*length) += ft_fpf_printbase(16, *f, va_arg(args, unsigned int));
	else if (*f == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		if (!ptr)
			(*length) += ft_fpf_printstr("(nil)");
		else
		{
			(*length) += ft_fpf_printstr("0x");
			if (ptr >= 16)
			{
				(*length) += ft_fpf_printbase(16, 'x', ptr / 16);
				ptr = ptr % 16;
			}
			(*length) += ft_fpf_printbase(16, 'x', ptr);
		}
	}
	else
		(*length) += write(1, (f - 1), (1 + (*f != '%')));
}

/**
 * @brief A simplified implementation of printf.
 * 
 * This function mimics the behavior of the standard printf function. It
 * processes a format string and prints the corresponding arguments to the
 * standard output. Supported format specifiers include:
 * - 'c': Prints a single character.
 * - 's': Prints a string.
 * - 'd' or 'i': Prints a signed integer in decimal format.
 * - 'u': Prints an unsigned integer in decimal format.
 * - 'x': Prints an unsigned integer in lowercase hexadecimal format.
 * - 'X': Prints an unsigned integer in uppercase hexadecimal format.
 * - 'p': Prints a pointer address in hexadecimal format.
 * - '%%': Prints a literal '%' character.
 * 
 * @param str 
 *      The format string containing text and format specifiers.
 * @param ... 
 *      The variable arguments to be formatted and printed.
 * @return int 
 *      The total number of characters written to the output.
 */
int	ft_printf(const char *str, ...)
{
	va_list				args;
	int					length;
	unsigned long long	ptr;

	length = 0;
	va_start(args, str);
	while (*str)
	{
		ptr = 0;
		if (*str == '%')
		{
			if (*(++str) == 'c')
			{
				ptr = va_arg(args, int);
				length += write(1, &ptr, 1);
			}
			else
				ft_formats(args, str, &length, ptr);
		}
		else
			length += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (length);
}
