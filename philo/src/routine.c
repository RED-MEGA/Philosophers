/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:19:02 by reben-ha          #+#    #+#             */
/*   Updated: 2023/05/14 16:11:23 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static bool	get_life_state(t_philo *philo)
{
	bool	life_stat;

	pthread_mutex_lock(&philo->info->life_stat.mutex);
	life_stat = philo->info->life_stat.value;
	pthread_mutex_unlock(&philo->info->life_stat.mutex);
	return (life_stat);
}

bool	print_stat(t_philo *philo, char *stat, char *color, int unlock)
{
	pthread_mutex_lock(philo->print_access);
	if (!get_life_state(philo))
		return (false);


	printf("%lld %d %s\n", (current_time() - philo->t0), philo->id, stat);


	// printf("%s%lld %d %s\e[0m\n",
	// 	color, (current_time() - philo->t0), philo->id, stat);
	if (unlock)
		pthread_mutex_unlock(philo->print_access);
	return (true);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (print_stat(philo, "has taken a fork", C_EAT, true) == false)
		return ;
	pthread_mutex_lock(&philo->next->fork);
	if (print_stat(philo, "has taken a fork", C_EAT, true) == false)
		return ;
	pthread_mutex_lock(&philo->meal_count.mutex);
	philo->meal_count.value += 1;
	pthread_mutex_unlock(&philo->meal_count.mutex);
	pthread_mutex_lock(&philo->last_meal.mutex);
	philo->last_meal.value = current_time();
	pthread_mutex_unlock(&philo->last_meal.mutex);
	if (print_stat(philo, "is eating", C_EAT, true) == false)
		return ;
	usleep_x(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

static void	sleeping(t_philo *philo)
{
	if (print_stat(philo, "is sleeping", C_SLEEP, true) == false)
		return ;
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
		if (!get_life_state(philo))
			break ;
		sleeping(philo);
		if (!get_life_state(philo))
			break ;
		print_stat(philo, "is thinking", C_THINK, true);
		if (!get_life_state(philo))
			break ;
	}
	return (NULL);
}
