/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:52 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/08 14:38:12 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
		void *calloc(size_t nelem, size_t elsize);
       The calloc() function shall allocate unused space for an array of
       nelem elements each of whose size in bytes is elsize.  The space
       shall be initialized to all bits 0.
       
RETURN VALUE
       Upon successful completion with both nelem and elsize non-zero,
       calloc() shall return a pointer to the allocated space. If either
       nelem or elsize is 0, then either:

        *  A null pointer shall be returned and errno may be set to an
           implementation-defined value, or

        *  A pointer to the allocated space shall be returned. The
           application shall ensure that the pointer is not used to
           access an object.

       Otherwise, it shall return a null pointer and set errno to
       indicate the error.*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	max;

	max = 4611686014132420608;
	if (count != 0 && max / count < size)
		return (NULL);
	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		*(ptr + i) = '\0';
		i++;
	}
	return (ptr);
}
