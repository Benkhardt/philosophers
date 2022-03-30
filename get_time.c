/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:14:02 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/30 16:14:42 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
