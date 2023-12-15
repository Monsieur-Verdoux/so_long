/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:50:35 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 13:31:30 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION

	   The strncmp() function shall compare not more than n bytes (bytes
       that follow a NUL character are not compared) from the array
       pointed to by s1 to the array pointed to by s2.

       The sign of a non-zero return value is determined by the sign of
       the difference between the values of the first pair of bytes
       (both interpreted as type unsigned char) that differ in the
       strings being compared.
RETURN VALUE
       Upon successful completion, strncmp() shall return an integer
       greater than, equal to, or less than 0, if the possibly null-
       terminated array pointed to by s1 is greater than, equal to, or
       less than the possibly null-terminated array pointed to by s2
       respectively.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			j = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (j);
		}
	}
	return (j);
}
