/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:31:39 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:31:01 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_substr
Prototype char *ft_substr(char const *s, unsigned int start,
size_t len);
Parameters s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.
Return value The substring.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	rem_len;

	if (s == NULL || start >= ft_strlen(s) || len == 0)
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	rem_len = ft_strlen(s) - start;
	if (len > rem_len)
		len = rem_len;
	sub = malloc((len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (len > i && s[start] != '\0')
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
