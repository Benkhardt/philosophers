/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:43:06 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/06 13:39:41 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst[2];

	if (!lst || !f)
		return (NULL);
	new_lst[1] = ft_lstnew(f(lst->content));
	if (!new_lst[1])
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst[0] = new_lst[1];
	lst = lst->next;
	while (lst)
	{
		new_lst[1] = ft_lstnew(f(lst->content));
		if (!new_lst[1])
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst[0], del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst[0], new_lst[1]);
	}
	return (new_lst[0]);
}
