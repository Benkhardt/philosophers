/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:39:20 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/30 11:41:25 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 5 || argc > 6)
		return (exit_error("bad arguments\n"));
	if (init(&state, argc, (const char **)argv))
		return (clear_state(&state) && exit_error("error...\n"));
	if (start_threads(&state))
		return (clear_state(&state) && exit_error("error...\n"));
	pthread_mutex_lock(&state.somebody_dead_m);
	pthread_mutex_unlock(&state.somebody_dead_m);
	clear_state(&state);
	return (0);
}
