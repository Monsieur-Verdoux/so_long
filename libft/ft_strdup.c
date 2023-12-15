/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:46:33 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/08 12:22:47 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The strdup() function returns a pointer to a new string which is
       a duplicate of the string s.  Memory for the new string is
       obtained with malloc(3), and can be freed with free(3).

RETURN VALUE
       On success, the strdup() function returns a pointer to the
       duplicated string.  It returns NULL if insufficient memory was
       available, with errno set to indicate the error.*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i <= len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	return (ptr);
}
