/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:12:07 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:32:28 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_lstsize
Prototype int ft_lstsize(t_list *lst);
Parameters lst: The beginning of the list.
Return value The length of the list
External functs. None
Description Counts the number of nodes in a list.*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
