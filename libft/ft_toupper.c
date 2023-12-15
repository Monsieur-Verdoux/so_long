/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:04:03 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 13:27:24 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice
       versa.
RETURN VALUE 
       The value returned is that of the converted letter, or c if the
       conversion was not possible.*/

int	ft_toupper(int c)
{
	if (c >= 0 && c <= 255)
	{
		if (97 <= c && c <= 122)
			c = c - 32;
	}
	return (c);
}
