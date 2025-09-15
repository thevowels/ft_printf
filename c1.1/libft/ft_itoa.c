/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:13:37 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/29 19:02:35 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlength(long n)
{
	int	count;

	count = (n <= 0);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		length;

	nbr = (long)n;
	length = ft_getlength(nbr);
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--length] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int		x;
	char	*c;

	x = 0;
	c = ft_itoa(x);
	printf("Result :%s\n", c);
}
*/