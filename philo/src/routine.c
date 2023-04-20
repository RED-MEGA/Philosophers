/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:19:02 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/20 00:29:37 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static void	delay_maker(bool delay)
{
	if (!delay)
		usleep(5 * 1000);
}

void	print_stat(t_philo *philo, char *stat, char *color)
{
	pthread_mutex_lock(philo->print_access);
	printf("%sHi I'm philo %d : %s\n", color, philo->id, stat);
	pthread_mutex_unlock(philo->print_access);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);

	print_stat(philo, "Take fork", C_EAT);
	print_stat(philo, "Eating", C_EAT);
	usleep(philo->info->time_to_eat);

	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);

	// Reset time
	// 		Update time stat
	//		Update eat time 
}

static void	sleeping(t_philo *philo)
{
	print_stat(philo, "sleeping", C_SLEEP);
	usleep(philo->info->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	print_stat(philo, "thinking", C_THINK);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	delay_maker(philo->id % 2 == 0);
	while (1)
	{
		eating(philo);

		sleeping(philo);

		thinking(philo);
	}
}
