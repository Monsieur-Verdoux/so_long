/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:50:57 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 13:17:54 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The memmove() function copies n bytes from memory area src to
       memory area dest.  The memory areas may overlap: copying takes
       place as though the bytes in src are first copied into a
       temporary array that does not overlap src or dest, and the bytes
       are then copied from the temporary array to dest.
RETURN VALUE
       The memmove() function returns a pointer to dest.*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	unsigned char		*last_dst;
	const unsigned char	*last_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (pdst < psrc)
		while (len--)
			*pdst++ = *psrc++;
	else
	{
		last_dst = (unsigned char *)dst + (len - 1);
		last_src = (unsigned char *)src + (len - 1);
		while (len--)
			*last_dst-- = *last_src--;
	}
	return (dst);
}
