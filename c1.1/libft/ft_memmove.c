/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:28:07 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/27 11:52:41 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	if (d == s)
		return (d);
	if (d < s)
	{
		return (ft_memcpy(dest, src, n));
	}
	else
	{
		d += n -1;
		s += n -1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	csrc[100] = "Geeksfor";
	char	src[100] = "Geeksfor";

	char * dest;
	char * cdest;
	dest = src +1;
	cdest = csrc+1;
	memmove(src, dest, 8);
	printf("Memmove %s.\n", src);
	ft_memmove(csrc, cdest, 8);
	printf("Ft_memmove %s.\n", csrc);
	return (0);
}
*/