/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:57:53 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/28 22:48:22 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	char	*bbig;

	llen = ft_strlen(little);
	bbig = (char *)big;
	if (!llen)
		return (bbig);
	while (*bbig && ((size_t)(llen + bbig - big) <= len))
	{
		if (!ft_strncmp(bbig, little, llen))
			return (bbig);
		bbig++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*ptr;
	char	*ptr1;

	ptr = ft_strnstr("lorem ipsum dolor sit amet", "lo", 1);
	ptr1 = strnstr("lorem ipsum dolor sit amet", "lo", 1);
	printf("My   Result is %s\n", ptr);
	printf("Libc Result is %s\n", ptr1);
	ptr = ft_strnstr("lorem ipsum dolor sit amet", "lo", 2);
	ptr1 = strnstr("lorem ipsum dolor sit amet", "lo", 2);
	printf("My   Result is %s\n", ptr);
	printf("Libc Result is %s\n", ptr1);
	ptr = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	ptr1 = strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	printf("My   Result is %s\n", ptr);
	printf("Libc Result is %s\n", ptr1);
	ptr = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 18);
	ptr1 = strnstr("lorem ipsum dolor sit amet", "dolor", 18);
	printf("My   Result is %s\n", ptr);
	printf("Libc Result is %s\n", ptr1);
}
*/