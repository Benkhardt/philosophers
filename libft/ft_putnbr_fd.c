/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:32:13 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/07/19 14:03:24 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd);

static int	ft_checkneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static void	ft_putnbr(long int n, int fd)
{
	int	neg;

	neg = ft_checkneg(n);
	if (neg)
	{
		n = n * (-1);
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;

	tmp = (long int) n;
	ft_putnbr(tmp, fd);
}
