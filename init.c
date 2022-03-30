/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:32:10 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/30 16:11:06 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutex(t_state *state)
{
	int	i;

	i = 0;
	pthread_mutex_init(&state->write_m, NULL);
	pthread_mutex_init(&state->somebody_dead_m, NULL);
	pthread_mutex_lock(&state->somebody_dead_m);
	state->forks_m = malloc(sizeof(*(state->forks_m)) * state->amount);
	if (!state->forks_m)
		return (1);
	while (i < state->amount)
		pthread_mutex_init(&state->forks_m[i++], NULL);
	return (0);
}

static void	init_philos(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->amount)
	{
		state->philos[i].is_eating = 0;
		state->philos[i].position = i;
		state->philos[i].eat_count = 0;
		state->philos[i].lfork = i;
		state->philos[i].rfork = (i + 1) % state->amount;
		state->philos[i].state = state;
		pthread_mutex_init(&state->philos[i].mutex, NULL);
		pthread_mutex_init(&state->philos[i].eat_m, NULL);
		pthread_mutex_lock(&state->philos[i].eat_m);
		i++;
	}
}

int	init(t_state *state, int argc, char const **argv)
{
	state->amount = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		state->must_eat_count = ft_atoi(argv[5]);
	else
		state->must_eat_count = 0;
	if (state->amount < 2 || state->amount > 200 || state->time_to_die < 60
		|| state->time_to_eat < 60 || state->time_to_sleep < 60
		|| state->must_eat_count < 0)
		return (1);
	state->forks_m = NULL;
	state->philos = NULL;
	state->philos = (t_philo *)malloc(sizeof(*(state->philos)) * state->amount);
	if (!state->philos)
		return (1);
	init_philos(state);
	return (init_mutex(state));
}
