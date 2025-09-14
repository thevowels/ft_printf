/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:22:56 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/14 19:52:29 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ptr(unsigned long long ptr, char *base, int *count)
{
	if (ptr < 16)
		ft_putchar_pf(base[ptr], count);
	if (ptr >= 16)
	{
		ft_putnbr_ptr(ptr / 16, base, count);
		ft_putnbr_ptr(ptr % 16, base, count);
	}
}

void	ft_print_ptr(unsigned long long ptr, char *base, int *count)
{
	if (ptr == 0)
		ft_putstr_pf("(nil)", count);
	else
	{
		ft_putstr_pf("0x", count);
		ft_putnbr_ptr(ptr, base, count);
	}
}
