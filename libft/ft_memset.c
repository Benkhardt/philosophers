/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:09:42 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/07/19 13:30:14 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*ptr_str;

	i = 0;
	ptr_str = (char *)str;
	while (i < len)
	{
		ptr_str[i] = c;
		i++;
	}
	return (str);
}
