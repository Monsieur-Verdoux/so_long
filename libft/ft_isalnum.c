/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:33:19 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/07 15:15:34 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION         
     isalnum() checks for an alphanumeric character; it is equivalent to
              (isalpha(c) || isdigit(c)).
RETURN VALUE         
       The isalnum() and isalnum_l() functions shall return non-zero if
       c is an alphanumeric character; otherwise, they shall return 0.*/

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9'))
		return (1);
	return (0);
}
