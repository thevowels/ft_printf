/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:41:43 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/28 22:24:20 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*src1 == *src2 && --n != 0)
	{
		if (*src1 == 0 || *src2 == 0)
			break ;
		src1++;
		src2++;
	}
	if (n == 0 || src1 == 0 || src2 == 0)
		return (0);
	return (*src1 - *src2);
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	int	libc;
	int	mine;

	libc = strncmp("test\200", "test\0", 6);
	mine = ft_strncmp("test\200", "test\0", 6);
	printf("Libc is %i and mine is %i\n", libc, mine);
}
*/