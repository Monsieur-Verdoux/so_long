/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:43 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 13:27:25 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice
       versa.
RETURN VALUE
       The value returned is that of the converted letter, or c if the
       conversion was not possible.*/

int	ft_tolower(int c)
{
	if (c >= 0 && c <= 255)
	{
		if (65 <= c && c <= 90)
			c = c + 32;
	}
	return (c);
}
