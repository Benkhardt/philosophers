/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:26:32 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/30 15:05:28 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
// states
# define TYPE_EAT	0
# define TYPE_SLEEP 1
# define TYPE_FORK	2
# define TYPE_THINK	3
# define TYPE_DIED	4
# define TYPE_OVER	5
// bool
# define TRUE		1
# define FALSE		0

struct	s_state;

typedef struct		s_time{
	long			t_min;
	long			tl_sec;
	long			t_hour;
	long			tl_min;
	long			t_day;
	long			tl_hour;
	long			dt_secs;
	long			u_secs;
}					t_time;

typedef struct		s_philo
{
	int				position;
	int				is_eating;
	uint64_t		limit;
	uint64_t		last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_state	*state;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
	t_time			ttime;
}					t_philo;

typedef struct		s_state
{
	int				amount;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat_count;
	uint64_t		start;
	//uint64_t		daytime;
	t_philo			*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	somebody_dead_m;
}					t_state;

int		start_threads(t_state *state);

size_t	ft_strlen(char const *str);

int		clear_state(t_state *state);

int		exit_error(char const *str);

int		clear_state(t_state *state);

int		init(t_state *state, int argc, char const **argv);

uint64_t	get_time(void);

t_time		get_dtime(void);

void	display_message(t_philo *philo, int type);

int		ft_atoi(char const *str);

void	ft_putnbr_fd(u_int64_t nbr, int fd);

void	take_forks(t_philo *philo);

void	eat(t_philo *philo);

void	clear_forks(t_philo *philo);

t_time	get_dtime(void);

void	ft_puttime_fd(t_time ttime, int fd);

void 	ft_putchar_fd(char c, int fd);

#endif
