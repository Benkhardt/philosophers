/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:10:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/06/27 15:22:24 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*rtn;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	rtn = (char *)malloc(sizeof(char) * size + 2);
	while (s1[j])
	{
		rtn[i] = s1[j++];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		rtn[i] = s2[j++];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
