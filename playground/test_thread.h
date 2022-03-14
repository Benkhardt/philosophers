/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_thread.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:52:36 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/14 22:22:23 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_THREAD_H
# define TEST_THREAD_H

// includes

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <strings.h>
# include <sys/time.h>
# include "../libft/libft.h"

// typedefs

// this is for my_malloc
typedef struct s_list{
	void			*ptr;
	struct s_list 	*next;
}	t_list;

// philo struct
typedef struct s_philo{
	unsigned int	ttd;		// time a philo needs to die without eating
	unsigned int	tte;		// time a philo needs to eat
	unsigned int	tts;		// time a philo needs to sleep
	unsigned int	notepme;	// number of must have eaten
}	t_philo;

// fork struct
typedef struct s_fork{
	int				in_use;
	unsigned int	fork_nbr;
}

void	free_list(t_list *last);

t_list	*malloc_list(void *ptr, t_list *last);

void	*my_malloc(size_t size, t_list *last);

// prototypes



#endif