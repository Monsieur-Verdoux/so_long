/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:02:38 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:33:04 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_lstadd_front
Prototype void ft_lstadd_front(t_list **lst, t_list *new);
Parameters lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
Return value None
External functs. None
Description Adds the node ’new’ at the beginning of the list.*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
