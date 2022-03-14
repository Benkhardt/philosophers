/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:05:55 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/07 09:24:30 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp1;

	if (lst == NULL)
		return (NULL);
	tmp1 = lst;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	return (tmp1);
}
