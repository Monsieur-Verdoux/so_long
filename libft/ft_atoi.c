/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:11:26 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:14:19 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The atoi() function converts the initial portion of the string
       pointed to by nptr to int.
RETURN VALUE
       The converted value or 0 on error.*/

#include "libft.h"

static int	atoi_putnbr(const char *str, int sign, int i)
{
	long	result;

	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= LONG_MAX / 10 && (result > LONG_MAX / 10 \
		|| (str[i] - '0') > LONG_MAX % 10))
		{
			if (sign == 1)
				return (-1);
			else if (sign == -1)
				return (0);
		}
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * (int)result);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	return (atoi_putnbr(str, sign, i));
}
