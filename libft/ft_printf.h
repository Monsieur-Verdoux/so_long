/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:46:22 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/14 17:00:34 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_pf(char c, int *count);
int	ft_putstr_pf(char *str, int *count);
int	ft_putnbr_pf(int n, int *count);
int	ft_unsigned_pf(unsigned int n, int *count);
int	ft_hex_pf(unsigned int num, int *count, char c);
int	ft_ptr_pf(unsigned long int p, int *count);

#endif