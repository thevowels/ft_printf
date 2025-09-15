/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 00:43:15 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/28 15:53:01 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	length = ft_strlen(dest);
	if (length >= size)
		return (size + ft_strlen(src));
	return (length + ft_strlcpy(dest + length, src, size - length));
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void) {
	char buffer[15] = "rrrrrr";

	size_t result = ft_strlcat(buffer, "World", 15);

	printf("Buffer: '%s'\n", buffer);   // "HelloWor"
	printf("Tried length: %zu\n", result); // 10 (5 + 5)

	char bb[15] = "rrrrrr";

	size_t rr = strlcat(bb, "World", 15);

	printf("Buffer: '%s'\n", bb);   // "HelloWor"
	printf("Tried length: %zu\n", rr); // 10 (5 + 5)
	return (0);
}
*/