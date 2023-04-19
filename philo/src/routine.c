/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:19:02 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/19 05:46:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	// Make delay
	pthread_mutex_lock(philo->print_access);
	printf("\033[31;1mHI I'M %d THREAD \033[0m\n", philo->id);
	pthread_mutex_unlock(philo->print_access);
	while (1)
	{
	

		// Fork
		// Print stat of philo : take fork
		// Print stat of philo

		
		// Reset time
		// 		Update time stat
		//		Update eat time 


		// Eating
		// unlock




		// Start timing

		// Print stat of philo
		// Sleeping

		// Print stat of philo
		// Thinking

	}
}
