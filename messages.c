/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:16:44 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/30 16:16:52 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	*get_message(int type)
{
	if (type == TYPE_EAT)
		return (" is eating\n");
	else if (type == TYPE_SLEEP)
		return (" is sleeping\n");
	else if (type == TYPE_FORK)
		return (" has taken a fork\n");
	else if (type == TYPE_THINK)
		return (" is thinking\n");
	else if (type == TYPE_OVER)
		return ("must eat count reached\n");
	return (" died\n");
}

void	display_message(t_philo *philo, int type)
{
	static int	done;

	done = 0;
	pthread_mutex_lock(&philo->state->write_m);
	if (!done)
	{
		philo->ttime = get_dtime();
		ft_puttime_fd(philo->ttime, 1);
		ft_putchar_fd(' ', 1);
		ft_putchar_fd('(', 1);
		ft_putnbr_fd(get_time() - philo->state->start, 1);
		ft_putchar_fd(')', 1);
		write(1, "\t", 1);
		if (type != TYPE_OVER)
			ft_putnbr_fd(philo->position + 1, 1);
		if (type >= TYPE_DIED)
			done = 1;
		write(1, get_message(type), ft_strlen(get_message(type)));
	}
	pthread_mutex_unlock(&philo->state->write_m);
}
