/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:19:02 by reben-ha          #+#    #+#             */
/*   Updated: 2023/05/14 20:53:02 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

bool	print_stat(t_philo *philo, char *stat, char *color, bool unlock)
{
	pthread_mutex_lock(philo->print_access);
	printf("%s%lld %d %s\e[0m\n",
		color, (current_time() - philo->t0), philo->id, stat);
	if (unlock)
		pthread_mutex_unlock(philo->print_access);
	return (true);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_stat(philo, "has taken a fork", C_EAT, true);
	pthread_mutex_lock(&philo->next->fork);
	print_stat(philo, "has taken a fork", C_EAT, true);

	pthread_mutex_lock(&philo->last_meal.mutex);
	pthread_mutex_lock(&philo->meal_count.mutex);
	print_stat(philo, "is eating", C_EAT, true);
	philo->last_meal.value = current_time();
	philo->meal_count.value += 1;
	pthread_mutex_unlock(&philo->last_meal.mutex);
	pthread_mutex_unlock(&philo->meal_count.mutex);

	usleep_x(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

static void	sleeping(t_philo *philo)
{
	print_stat(philo, "is sleeping", C_SLEEP, true);
	usleep_x(philo->info->time_to_sleep);
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
		print_stat(philo, "is thinking", C_THINK, true);
	}
	return (NULL);
}
