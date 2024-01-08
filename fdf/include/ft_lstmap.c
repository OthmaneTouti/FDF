/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:57:09 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/28 22:40:25 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include "libft.h"

static t_list	*cleanup_on_error(t_list *new_lst, void (*del)(void *))
{
	ft_lstclear(&new_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_nbr;

	new_lst = NULL;
	while (lst)
	{
		new_nbr = f(lst->content);
		if (!new_nbr)
			return (cleanup_on_error(new_lst, del));
		new_node = ft_lstnew(new_nbr);
		if (!new_node)
		{
			del(new_nbr);
			return (cleanup_on_error(new_lst, del));
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
