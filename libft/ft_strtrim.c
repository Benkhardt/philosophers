/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:12:41 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/07/27 16:47:26 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start])
	{
		if (!ft_check(s1[start], set))
			return (start);
		start++;
	}
	return (start);
}

static int	ft_end(char const *s1, char const *set)
{
	int	end;

	end = (int)ft_strlen(s1) - 1;
	while (s1[end] && end > ft_start(s1, set))
	{
		if (!ft_check(s1[end], set))
			return (end);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		spc;
	char	*rtn;

	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	spc = end - start + 2;
	if (end < start)
		spc = 1;
	rtn = (char *)malloc(sizeof(char) * spc);
	while (start <= end)
	{
		rtn[i] = (char)s1[start];
		i++;
		start++;
	}
	rtn[i] = '\0';
	return (rtn);
}
