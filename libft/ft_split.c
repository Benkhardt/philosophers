/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:39:39 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/07/19 16:54:44 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_elements(const char *s, char c)
{
	int	ctr;
	int	i;
	int	elem;

	ctr = 1;
	i = 0;
	elem = 0;
	while (s[i])
	{
		if (s[i] != c && ctr == 1)
		{
			ctr = 0;
			elem++;
		}
		if (s[i++] == c && ctr == 0)
			ctr = 1;
	}
	return (elem);
}

static char	*ft_sub(const char *s, const char c, int i)
{
	char	*rtn;
	int		j;
	int		length;

	length = 0;
	while (s[i] != c && s[i])
	{
		length++;
		i++;
	}
	i = i - length;
	rtn = (char *)malloc(sizeof(char) * (length + 1));
	j = 0;
	while (s[i] && s[i] != c)
		rtn[j++] = s[i++];
	rtn[j] = '\0';
	return (rtn);
}

char	**ft_split(const char *s, const char c)
{
	int		i;
	int		x;
	char	**rtn;

	i = 0;
	x = -1;
	if (!s)
	{
		return (0);
	}
	rtn = (char **)malloc(sizeof(char *) * (ft_elements(s, c) + 1));
	if (!rtn)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			x++;
			rtn[x] = ft_sub(s, c, i);
			i = i + ft_strlen(rtn[x]) - 1;
		}
		i++;
	}
	rtn[++x] = 0;
	return (rtn);
}
