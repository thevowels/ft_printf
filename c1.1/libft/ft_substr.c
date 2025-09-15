/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:29:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/30 01:40:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*ptr;

	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > slen)
	{
		return (ft_strdup(""));
	}
	if (len > slen - start)
		len = slen - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	ptr[len] = 0;
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*dest;

	str = "lorem ipsum dolor sit amet";
	dest = ft_substr(str, 0,10);
	printf("%s\n", dest);
}
	*/
