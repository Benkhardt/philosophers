/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:21:55 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/07/19 14:49:55 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compare(unsigned char c, unsigned char d)
{
	if (c != d)
		return (c - d);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < size)
	{
		if (ft_compare((unsigned char) s1[i], (unsigned char) s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < size)
		return (ft_compare((unsigned char) s1[i], (unsigned char) s2[i]));
	return (0);
}
