/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:08:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/29 11:28:13 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ptr = malloc(len + 1);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your version
char	*ft_strdup(const char *s);

void	compare_strdup(const char *input)
{
	char	*sys;
	char	*mine;
	int		same;

	sys = NULL;
	mine = NULL;
	printf("Input: %s\n", input ? input : "NULL");
	// System strdup
	if (input)
		sys = strdup(input);
	else
		printf("  system strdup -> SEGFAULT (undefined)\n");
	// Your ft_strdup
	if (input)
		mine = ft_strdup(input);
	else
		printf("  ft_strdup -> SEGFAULT (undefined)\n");
	if (input)
	{
		if (sys && mine)
		{
			same = strcmp(sys, mine) == 0;
			printf("  system: \"%s\"\n", sys);
			printf("  mine:   \"%s\"\n", mine);
			printf("  Equal? %s\n", same ? "YES ✅" : "NO ❌");
		}
		else
		{
			printf("  Allocation failed in one of them ❌\n");
		}
	}
	free(sys);
	free(mine);
	printf("--------------------------------------------------\n");
}

int	main(void)
{
	char	long_str[10000];

	// 1. Basic strings
	compare_strdup("Hello");
	compare_strdup("World!");
	// 2. Empty string
	compare_strdup("");
	// 3. Special characters
	compare_strdup("Line1\nLine2\tTabbed");
	// 4. Single char
	compare_strdup("A");
	// 5. Long string
	memset(long_str, 'x', 9999);
	long_str[9999] = '\0';
	compare_strdup(long_str);
	// 6. NULL pointer (both undefined, likely segfault)
	// compare_strdup(NULL);
	return (0);
}
*/