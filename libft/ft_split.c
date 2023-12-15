/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:03 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:31:58 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_split
Prototype char **ft_split(char const *s, char c);
Parameters s: The string to be split.
c: The delimiter character.
Return value The array of new strings resulting from the split.
NULL if the allocation fails.
External functs. malloc, free
Description Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/

#include "libft.h"

static void	skip_sep(char const **s, char sep)
{
	while (**s && **s == sep)
		(*s)++;
}

static int	count_subs(char const *s, char sep)
{
	int		count;

	if (s == NULL)
		return (0);
	count = 0;
	while (*s)
	{
		skip_sep(&s, sep);
		if (*s)
		{
			count++;
			while (*s && *s != sep)
				s++;
		}
	}
	return (count);
}

static char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**result;
	int		i;

	if (s == NULL)
		return (NULL);
	result = ft_calloc((count_subs(s, c) + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		skip_sep(&s, c);
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			result[i] = ft_substr(s, 0, len);
			if (result[i++] == NULL)
				return (free_all(result));
			s = s + len;
		}
	}
	return (result);
}
