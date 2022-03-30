/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/28 14:56:58 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
	display_message(philo, TYPE_SLEEP);
	pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
	display_message(philo, TYPE_FORK);
}

void	clear_forks(t_philo *philo)
{
	display_message(philo, TYPE_SLEEP);
	pthread_mutex_unlock(&philo->state->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks_m[philo->rfork]);
	usleep(philo->state->time_to_sleep * 1000);
}
