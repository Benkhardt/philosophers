/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:52:02 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/14 21:14:24 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_thread.h"

void	*myturn(void *arg)
{
	while (1)
	{
		ft_putstr_fd((char *)arg, 1);
		sleep(1);
	}
	return (NULL);
}

void	yourturn(void *arg)
{
	while (1)
	{
		sleep(1);
		ft_putstr_fd((char *)arg, 1);
	}
}

int	main(void)
{
	pthread_t thread1;
	char one[] = "Hello ";
	char two[] = "...there!\n";

	pthread_create(&thread1, NULL, myturn, one);
	//pthread_create(&thread2, NULL, yourturn, two);
	yourturn(two);
	pthread_join(thread1, NULL);
	return (0);
}
