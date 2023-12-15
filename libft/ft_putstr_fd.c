/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:09:55 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:32:04 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_putstr_fd
Prototype void ft_putstr_fd(char *s, int fd);
Parameters s: The string to output.
fd: The file descriptor on which to write.
Return value None
External functs. write
Description Outputs the string ’s’ to the given file
descriptor.*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return ;
}
