/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:19:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/14 12:34:54 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	i;

	i = 42;
	printf("Character 		%%c 	: %c\n", '*');
	printf("String    		%%s 	: %s\n", "1337");
	printf("Pointer   		%%p 	: %p\n", &i);
	printf("Pointer   		%%p 	: %p\n", NULL);
	printf("Decimal   		%%d 	: %d\n", i);
	printf("Integer   		%%i 	: %i\n", i);
	printf("Hex Upper 		%%X 	: %X\n", i);
	printf("Hex Lower		%%x 	: %x\n", i);
	printf("Percent 		%%%%	: %%\n");
}
