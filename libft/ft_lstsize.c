/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:00:44 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/06 11:05:00 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		rtn;

	tmp1 = lst;
	rtn = 0;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		rtn++;
		tmp1 = tmp2;
	}
	return (rtn);
}
