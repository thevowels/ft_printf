/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:48:43 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/29 23:53:52 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		ch;

	ch = c;
	src = s;
	while (n-- > 0)
	{
		if (*src++ == ch)
			return ((void *)(src - 1));
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "bonjour";
	char c = 'b';
	char *str;

	str = ft_memchr(s, c, 4);

	printf("Result :%s:\n", str);

	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("%s", (char *)memchr(tab, -1, 7));

}
*/