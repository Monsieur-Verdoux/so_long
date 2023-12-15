/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:59:15 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:33:15 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_itoa
Prototype char *ft_itoa(int n);
Parameters n: the integer to convert.
Return value The string representing the integer.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.*/

#include "libft.h"

static char	*handle_string(char *str, int len, int is_negative, int n)
{
	str = malloc(len + is_negative + 1);
	if (str == NULL)
		return (NULL);
	str[len + is_negative] = '\0';
	if (is_negative)
		str[0] = '-';
	while (len > 0)
	{
		str[len + is_negative - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

static char	*handle_minimum(void)
{
	char	*str;

	str = malloc(12);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;
	int		temp_n;

	len = 1;
	is_negative = 0;
	if (n == -2147483648)
		return (handle_minimum());
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	temp_n = n;
	while (temp_n >= 10)
	{
		temp_n = temp_n / 10;
		len++;
	}
	str = NULL;
	return (handle_string(str, len, is_negative, n));
}
