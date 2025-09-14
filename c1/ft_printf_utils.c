/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:44:33 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/14 14:18:29 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

int ft_strlen(char *base)
{
	int i;
	i = 0;
	while (base[i])
		i++;
	return(i);
	
}
void	ft_putstr_pf(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_pf("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putchar_pf(str[i], count);
		i++;
	}
}

void	ft_putnbr_pf(int nbr, int *count)
{
	long	nb;

	nb = (long)nbr;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_pf('-', count);
	}
	if (nb < 10)
		ft_putchar_pf(nb + '0', count);
	if (nb >= 10)
	{
		ft_putnbr_pf(nb / 10, count);
		ft_putnbr_pf(nb % 10, count);
	}
}

void	ft_putnbr_pf_base(unsigned int nbr, char *base, int *count)
{
	long	nb;
	int		length;

	length = ft_strlen(base);
	if(length < 10)
		return;
	nb = nbr;
	if(nb < 0)
	{
		nb *= -1;
		ft_putchar_pf('-', count);
	}
	if(nb < length)
		ft_putchar_pf(base[nb], count);
	if(nb >= length)
	{
		ft_putnbr_pf_base(nb / length, base, count);
		ft_putnbr_pf_base(nb % length, base, count);
	}
}