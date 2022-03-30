/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:34:48 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/30 14:49:25 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*monitor_count(void *state_v)
{
	t_state	*state;
	int		i;
	int		total;

	state = (t_state *)state_v;
	total = 0;
	while (total < state->must_eat_count)
	{
		i = 0;
		while (i < state->amount)
			pthread_mutex_lock(&state->philos[i++].eat_m);
		total++;
	}
	display_message(&state->philos[0], TYPE_OVER);
	pthread_mutex_unlock(&state->somebody_dead_m);
	return (NULL);
}

static void	*monitor(void *philo_v)
{
	t_philo	*philo;

	philo = (t_philo *)philo_v;
	while (TRUE)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && get_time() > philo->limit)
		{
			display_message(philo, TYPE_DIED);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->state->somebody_dead_m);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

static void	*routine(void *philo_v)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)philo_v;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	if (pthread_create(&tid, NULL, &monitor, philo_v) != 0)
		return (NULL);
	pthread_detach(tid);
	while (TRUE)
	{
		take_forks(philo);
		eat(philo);
		clear_forks(philo);
		display_message(philo, TYPE_THINK);
	}
	return (NULL);
}

int	start_threads(t_state *state)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	state->start = get_time();
	i = 0;
	if (state->must_eat_count > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void*)state) != 0)
			return (1);
		pthread_detach(tid);
	}
	while (i < state->amount)
	{
		philo = (void *)(&state->philos[i]);
		if (pthread_create(&tid, NULL, &routine, philo) != 0)
			return (1);
			pthread_detach(tid);
			usleep(100);
			i++;
	}
	return (0);
}
