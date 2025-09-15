/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:26:05 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/16 05:55:47 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

/*
	flag:
	1	base 10
	2	base 16 Lower case
	3	base 16 Upper case
*/
int	ft_fpf_printbase(int base, int upper, long nb)
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

int	ft_fpf_printstr(char *str)
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

int	ft_fpf_printnbr(int i)
{
	int		length;
	long	nb;
	char	c;

	length = 0;
	nb = (long)i;
	if (nb < 0)
	{
		nb *= -1;
		length += write(1, "-", 1);
	}
	if (nb < 10)
	{
		c = nb + '0';
		length += write(1, &c, 1);
	}
	if (nb >= 10)
	{
		length += ft_fpf_printnbr(nb / 10);
		length += ft_fpf_printnbr(nb % 10);
	}
	return (length);
}

void	ft_formats(va_list args, const char format, int *length,
		unsigned long long ptr)
{
	if (format == 's')
		(*length) += ft_fpf_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		(*length) += ft_fpf_printbase(10, 0, va_arg(args, int));
	else if (format == 'u' || format == 'x' || format == 'X')
		(*length) += ft_fpf_printbase(16, format, va_arg(args, unsigned int));
	else if (format == '%')
		(*length) += write(1, "%", 1);
	else if (format == 'p')
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
}

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
				ft_formats(args, *str, &length, ptr);
		}
		else
			length += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (length);
}
