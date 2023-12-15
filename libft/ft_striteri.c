/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:06:31 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:31:50 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_striteri
Prototype void ft_striteri(char *s, void (*f)(unsigned int,
char*));
Parameters s: The string on which to iterate.
f: The function to apply to each character.
Return value None
External functs. None
Description Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by address to ’f’ 
to be modified if necessary*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	if (s == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len && s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
