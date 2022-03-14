/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:40:46 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/06 13:48:42 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst == NULL || del == NULL)
		return ;
	tmp1 = lst[0];
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		del(tmp1->content);
		free(tmp1);
		tmp1 = tmp2;
	}	
	lst[0] = NULL;
}
