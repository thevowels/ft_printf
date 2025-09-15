/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:36:37 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/14 22:32:27 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list args, char *string, int i, int *count)
{
	char	*base10;
	char	*base16lo;
	char	*base16up;

	base10 = "0123456789";
	base16lo = "0123456789abcdef";
	base16up = "0123456789ABCDEF";
	if (string[i] == 'c')
		ft_putchar_pf(va_arg(args, int), count);
	else if (string[i] == 'd' || string[i] == 'i')
		ft_putnbr_pf(va_arg(args, int), count);
	else if (string[i] == 'u')
		ft_putnbr_pf_base(va_arg(args, unsigned int), base10, count);
	else if (string[i] == 's')
		ft_putstr_pf(va_arg(args, char *), count);
	else if (string[i] == 'x')
		ft_putnbr_pf_base(va_arg(args, unsigned int), base16lo, count);
	else if (string[i] == 'X')
		ft_putnbr_pf_base(va_arg(args, unsigned int), base16up, count);
	else if (string[i] == 'p')
		ft_print_ptr(va_arg(args, unsigned long long), base16lo, count);
	else if (string[i] == '%')
		ft_putchar_pf('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*string;
	int		count;
	int		i;

	string = (char *)format;
	va_start(args, format);
	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			ft_check(args, string, i, &count);
		}
		else
		{
			ft_putchar_pf(string[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}
