/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:19:02 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/21 09:33:20 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	delay_maker(bool delay)
{
	if (delay)
		usleep(2 * 1000);
}

bool	print_stat(t_philo *philo, char *stat, char *color, int unlock)
{
	pthread_mutex_lock(philo->print_access);
	pthread_mutex_lock(&philo->info->life_stat.mutex);
	if (!philo->info->life_stat.value)
		return (false);
	pthread_mutex_unlock(&philo->info->life_stat.mutex);
	printf("%s%lld : Hi I'm philo %d : %s\n", color, (current_time() - philo->t0), philo->id, stat);
	if (unlock)
		pthread_mutex_unlock(philo->print_access);
	return (true);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);

	
	pthread_mutex_lock(&philo->meal_count.mutex);
	philo->meal_count.value += 1;
	pthread_mutex_unlock(&philo->meal_count.mutex);

	pthread_mutex_lock(&philo->last_meal.mutex);
	philo->last_meal.value = current_time();
	pthread_mutex_unlock(&philo->last_meal.mutex);

	if (print_stat(philo, "Take fork", C_EAT, true) == false)
		return ;
	if (print_stat(philo, "Eating", C_EAT, true) == false)
		return ;
	usleep_x(philo->info->time_to_eat);

	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

static void	sleeping(t_philo *philo)
{
	if (print_stat(philo, "sleeping", C_SLEEP, true) == false)
		return ;
	usleep_x(philo->info->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	print_stat(philo, "thinking", C_THINK, true);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	delay_maker(philo->id % 2 == 0);
	while (1)
	{
		eating(philo);
		pthread_mutex_lock(&philo->info->life_stat.mutex);
		if (!philo->info->life_stat.value)
			break ;
		pthread_mutex_unlock(&philo->info->life_stat.mutex);

		sleeping(philo);
		pthread_mutex_lock(&philo->info->life_stat.mutex);
		if (!philo->info->life_stat.value)
			break ;
		pthread_mutex_unlock(&philo->info->life_stat.mutex);

		thinking(philo);
		pthread_mutex_lock(&philo->info->life_stat.mutex);
		if (!philo->info->life_stat.value)
			break ;
		pthread_mutex_unlock(&philo->info->life_stat.mutex);

	}
	return (NULL);
}
