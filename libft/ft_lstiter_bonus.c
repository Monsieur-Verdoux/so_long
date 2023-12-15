/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:47:45 by akovalev          #+#    #+#             */
/*   Updated: 2023/11/09 11:32:48 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function name ft_lstiter
Prototype void ft_lstiter(t_list *lst, void (*f)(void *));
Parameters lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
Return value None
External functs. None
Description Iterates the list ’lst’ and applies the function
’f’ on the content of each node.*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
