/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:22:48 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/06/22 09:58:34 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] != '\t')
			{
				if (str[i] != '\n')
				{
					if (str[i] != '\v')
					{
						if (str[i] != '\f')
						{
							if (str[i] != '\r')
								return (i);
						}
					}
				}
			}
		}
		i = i + 1;
	}
	return (i);
}

static int	ft_checkneg(char c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (2);
	else
		return (0);
}

static int	ft_transform(const char *str, int i)
{
	int	rtn;

	rtn = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			rtn = rtn * 10;
			rtn = rtn + (str[i] - '0');
		}
		else
			return (rtn);
		i = i + 1;
	}
	return (rtn);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;
	int	check;

	i = ft_checkspace(str);
	neg = 0;
	check = 0;
	while (str[i] && ft_checkneg(str[i]))
	{
		neg = neg + ft_checkneg(str[i]);
		i = i + 1;
		check++;
	}
	if (check > 1)
		return (0);
	res = ft_transform(str, i);
	if (neg % 2)
		return (-res);
	else
		return (res);
}
