/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:10:43 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/08/02 23:20:08 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	control;
	size_t	length;

	i = 0;
	length = ft_strlen(str);
	control = (char) c;
	while (i <= length)
	{
		if (str[i] == control)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
