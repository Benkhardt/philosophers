/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:27:33 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/08/02 23:02:55 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char		*ptr;
	size_t			i;
	unsigned long	conv;

	ptr = (const char *) str;
	i = 0;
	conv = (unsigned long) c;
	while (i < n)
	{
		if (ptr[i] == (char) conv)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
