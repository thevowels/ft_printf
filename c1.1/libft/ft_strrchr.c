/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:31:54 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/30 00:37:08 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	while (*src)
	{
		src++;
	}
	if (c == 0)
		return (src);
	while (src > s && *(--src))
	{
		if (*src == (char)c)
			return (src);
	}
	return (NULL);
}
