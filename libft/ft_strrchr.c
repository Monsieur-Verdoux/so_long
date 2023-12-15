/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:32:22 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/14 15:10:13 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION

       The strrchr() function returns a pointer to the last occurrence
       of the character c in the string s.

       Here "character" means "byte"; these functions do not work with
       wide or multibyte characters.
RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the
       matched character or NULL if the character is not found.  The
       terminating null byte is considered part of the string, so that
       if c is specified as '\0', these functions return a pointer to
       the terminator.*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_end;

	if (!s)
		return (NULL);
	s_end = s + ft_strlen(s);
	while (s_end >= s)
	{
		if (*s_end == (char)c)
			return ((char *)(s_end));
		s_end--;
	}
	return (NULL);
}
