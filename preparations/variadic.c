/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:41:45 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/14 10:35:17 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
	int i;
	int total;

	va_list args;
	va_start(args, count);
	
	i = 0;
	total = 0;
	while( i < count)
	{
		total += va_arg(args, int);
		i++;
	}
	return (total);
}

int main(void)
{
	printf("Result: %i\n", sum(5,1,2,3,4,7));
	
	return (0);
}