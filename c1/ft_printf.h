/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:36:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/09/14 19:54:25 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// main
int		ft_printf(const char *, ...);
void	ft_check(va_list args, char *string, int i, int *count);

// Utils
void	ft_putchar_pf(char c, int *count);
int		ft_strlen(char *base);
void	ft_putstr_pf(char *str, int *count);
void	ft_putnbr_pf(int nbr, int *count);
void	ft_putnbr_pf_base(unsigned int nbr, char *base, int *count);

// ptr
void	ft_putnbr_ptr(unsigned long long ptr, char *base, int *count);
void	ft_print_ptr(unsigned long long ptr, char *base, int *count);
#endif
