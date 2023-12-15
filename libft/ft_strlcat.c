/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:37:53 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 13:24:28 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  DESCRIPTION
		strlcpy(3bsd)
       strlcat(3bsd)
              These functions copy and catenate the input string into a
              destination string.  If the destination buffer, limited by
              its size, isn't large enough to hold the copy, the
              resulting string is truncated (but it is guaranteed to be
              null-terminated).  They return the length of the total
              string they tried to create.  These functions force a
              SIGSEGV if the src pointer is not a string.

			  strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in prac-
     tice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).
	RETURN VALUE
			   The following functions return the length of the total string
       that they tried to create (as if truncation didn't occur).*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;

	dstlen = 0;
	i = 0;
	while (dstlen < dstsize && dst[dstlen] != '\0')
		dstlen++;
	if (dstlen == dstsize)
		return (dstsize + ft_strlen(src));
	while (src[i] != '\0' && dstlen + 1 < dstsize)
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	while (src[i] != '\0')
	{
		dstlen++;
		i++;
	}
	return (dstlen);
}
