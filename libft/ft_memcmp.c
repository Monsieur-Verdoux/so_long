/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:46:35 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 13:34:51 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The memcmp() function compares the first n bytes (each
       interpreted as unsigned char) of the memory areas s1 and s2.
RETURN VALUE
       The memcmp() function returns an integer less than, equal to, or
       greater than zero if the first n bytes of s1 is found,
       respectively, to be less than, to match, or be greater than the
       first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign of
       the difference between the first pair of bytes (interpreted as
       unsigned char) that differ in s1 and s2.

       If n is zero, the return value is zero.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;
	size_t			i;
	int				j;

	if (n == 0)
		return (0);
	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	j = 0;
	i = 0;
	while (i < n - 1 && s1ptr[i] == s2ptr[i])
		i++;
	j = s1ptr[i] - s2ptr[i];
	return (j);
}
