/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:36:03 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/08/26 16:43:16 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief : Checks wheter the input is alphabet or not
 * @param c : int to check
 * @return int : 1 if input is alphabet: 0 if input is not an alphabet.
 */
int	ft_isalpha(int c)
{
	return (((unsigned)c | 32) - 'a' < 26);
}
