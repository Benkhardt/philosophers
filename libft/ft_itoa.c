/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:20:40 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/07/14 13:02:25 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_end(long int n)
{
	long int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_checkneg(long int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char		*rtn;
	long int	i;
	long int	tmp;

	tmp = (long int) n;
	i = ft_checkneg(tmp);
	if (ft_checkneg(tmp))
		tmp = tmp * -1;
	i = i + ft_end(tmp);
	rtn = (char *)malloc(sizeof(char) * i + 2);
	if (!rtn)
		return (NULL);
	rtn[i + 1] = '\0';
	while (tmp > 9)
	{
		rtn[i--] = (tmp % 10) + '0';
		tmp = tmp / 10;
	}
	rtn[i] = (tmp % 10) + '0';
	if (i > 0)
		rtn[0] = '-';
	return (rtn);
}
