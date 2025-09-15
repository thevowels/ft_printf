/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:39:01 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/29 11:16:06 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char	*addr = src;
	size_t		n;

	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			*dest++ = *src++;
			if (*(dest - 1) == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*dest = '\0';
		while (*src++)
			;
	}
	return (src - addr - 1);
}

/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*s1;
	char	s2[40];
	size_t	c;

	s1 = "Hello !";
	c = ft_strlcpy(s2,s1,30);
	printf("%s\n", s2);
	printf("Reuslt : %lo \n", c);
}
*/