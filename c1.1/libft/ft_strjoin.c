/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:06:19 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/29 15:26:05 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc(l1 + l2 + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, l1 + 1);
	ft_strlcpy(ptr + l1, s2, l2 + 1);
	ptr[l1 + l2] = 0;
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "lorem ipsum";
	char s2[] = "dolor sit amet";

	printf("%s\n", ft_strjoin(s1, s2));
}*/