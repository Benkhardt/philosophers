/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:26:38 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/07/27 16:47:40 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			length;

	if (!s || !f || !*s)
		return ;
	length = ft_strlen((const char *)s);
	i = 0;
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}
