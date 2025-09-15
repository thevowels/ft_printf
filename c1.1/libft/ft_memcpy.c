/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:01:55 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/28 21:36:54 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n != 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "Geeks";
	char	str2[6] = "";

	// Copies contents of str2 to str1
	memcpy(str2, str1, sizeof(str1));
	printf("str2 after memcpy:");
	printf("%s\n",str2);
	ft_memcpy(str1+2, str1, sizeof(str1));
	printf("ft_str after ft_memcpy:");
	printf("%s\n",str1);
	return (0);
}
*/