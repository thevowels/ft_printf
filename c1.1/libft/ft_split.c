/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:44:02 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/29 18:23:24 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getcount(char const *s, char c)
{
	size_t	count;
	char	flag;

	flag = 1;
	count = 0;
	while (*s)
	{
		if (flag && *s != c)
		{
			flag = 0;
			count += 1;
		}
		else if (!flag && *s == c)
			flag = 1;
		s++;
	}
	return (count);
}

static size_t	ft_getlength(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		length += 1;
		s++;
	}
	return (length);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	i = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[len] = 0;
	return (ptr);
}

static void	ft_clean(char **ptr, size_t i)
{
	while (i > 0)
	{
		free(ptr[--i]);
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	count;
	size_t	i;
	size_t	i_len;

	i = 0;
	count = ft_getcount(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	while (i < count)
	{
		while (*s == c)
			s++;
		i_len = ft_getlength(s, c);
		arr[i++] = ft_strndup(s, i_len);
		if (arr[i - 1] == NULL)
		{
			ft_clean(arr, i);
			return (NULL);
		}
		s += i_len + 1;
	}
	return (arr);
}

/*
#include <stdio.h>

void	print_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
	{
		printf("NULL\n");
		return ;
	}
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);
		i++;
	}
	printf("[NULL]\n");
}

int	main(void)
{
	char	delims[] = {' ', ',', ',', ',', ',', ',', ',', ':', ' ', ':'};
	char	**res;

	char	*tests[] = {"hello world 42", "a,,b,,,c", ",42,school",
			"split,test,", ",,,,", "", "nodivider", "a:b:c:d",
			"   spaced   out   ", "abc:def:ghi:jkl:mno:pqr:stu:vwx:yz"};
	for (int i = 0; i < 10; i++)
	{
		printf("Test %d: \"%s\" with delim '%c'\n", i + 1, tests[i], delims[i]);
		res = ft_split(tests[i], delims[i]);
		print_split(res);
		// free memory if your ft_split allocates
	}
}
*/
/*
	1. count the number  to create the array.
	2. create the char ** pointer of size (count + 1);
	3. set the last counter to NULL
	4. duplicate each value with strndup and add to array.
		4.1 get the length of item to copy
		4.2 get the value with strndup
*/