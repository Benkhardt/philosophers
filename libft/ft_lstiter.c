/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:37:36 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/07 00:53:12 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst == NULL)
		return ;
	tmp1 = lst;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		(*f)(tmp1->content);
		tmp1 = tmp2;
	}
}
