/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:47:04 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/30 15:05:18 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(u_int64_t nbr, int fd)
{
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd('0' + (nbr % 10), fd);
	}
	if (nbr < 10)
		ft_putchar_fd('0' + nbr, fd);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char const *str)
{
	int	i;
	int	is_neg;
	int	res;

	if (!str)
		return (0);
	i = 0;
	is_neg = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			is_neg = is_neg + 2;
		else if (str[i] == '-')
			is_neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (is_neg % 2)
		return (res * (-1));
	return (res);
}

t_time	get_dtime(void)
{
	static struct timeval	tv;
	static t_time			dt;	

	gettimeofday(&tv, NULL);
	tv.tv_sec += 7200;
	dt.t_min = tv.tv_sec / 60;
	dt.tl_sec = tv.tv_sec % 60;
	dt.t_hour = dt.t_min / 60;
	dt.tl_min = dt.t_min % 60;
	dt.t_day = dt.t_hour / 24;
	dt.tl_hour = dt.t_hour % 24;
	dt.u_secs = tv.tv_usec / 1000;
	return (dt);
}

void	ft_puttime_fd(t_time ttime, int fd)
{
	ft_putnbr_fd(ttime.tl_hour, fd);
	ft_putchar_fd(':', fd);
	ft_putnbr_fd(ttime.tl_min, fd);
	ft_putchar_fd(':', fd);
	ft_putnbr_fd(ttime.tl_sec, fd);
	ft_putchar_fd(':', fd);
	ft_putnbr_fd(ttime.u_secs, fd);
}

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}
