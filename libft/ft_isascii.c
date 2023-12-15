/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:33:56 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 12:58:36 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       isascii()
              checks whether c is a 7-bit unsigned char value that fits
              into the ASCII character set.
RETURN VALUE
       The values returned are nonzero if the character c falls into the
       tested class, and zero if not.*/

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
