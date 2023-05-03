/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:19:02 by reben-ha          #+#    #+#             */
/*   Updated: 2023/05/03 18:45:27 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static bool	get_life_state(t_philo *philo)
{
	bool	life_stat;

	sem_wait(philo->info->life_stat.sem);
	life_stat = philo->info->life_stat.value;
	sem_post(philo->info->life_stat.sem);
	return (life_stat);
}

bool	print_stat(t_philo *philo, char *stat, char *color, int unlock)
{
	sem_wait(philo->info->print_access.sem);
	if (!get_life_state(philo))
		return (false);
	printf("%s%lld : Hi I'm philo %d : %s\n",
		color, (current_time() - philo->info->t0), philo->id, stat);
	if (unlock)
		sem_post(philo->info->print_access.sem);
	return (true);
}

static void	eating(t_philo *philo)
{
	sem_wait(philo->info->fork.sem);
	sem_wait(philo->info->fork.sem);
	sem_wait(philo->meal_count.sem);
	philo->meal_count.value += 1;
	sem_post(philo->meal_count.sem);
	sem_wait(philo->last_meal.sem);
	philo->last_meal.value = current_time();
	sem_post(philo->last_meal.sem);
	if (print_stat(philo, "Take fork", C_EAT, true) == false)
		return ;
	if (print_stat(philo, "Eating", C_EAT, true) == false)
		return ;
	usleep_x(philo->info->time_to_eat);
	sem_post(philo->info->fork.sem);
	sem_post(philo->info->fork.sem);
}

static void	sleeping(t_philo *philo)
{
	if (print_stat(philo, "sleeping", C_SLEEP, true) == false)
		return ;
	usleep_x(philo->info->time_to_sleep);
}

static void	*check_philosophers(void *ptr)
{
	t_philo	*philo;
	bool	optional_arg;

	philo = (t_philo *)ptr;
	optional_arg = (philo->info->limit_eat != FAIL);
	while (true)
	{
		usleep_x(100);
		sem_wait(philo->last_meal.sem);
		sem_wait(philo->meal_count.sem);
		if (current_time() - philo->last_meal.value >= philo->info->time_to_die
			|| (optional_arg == true
				&& philo->meal_count.value == philo->info->limit_eat))
		{
			print_stat(philo, "Dead 🧟‍", C_DEATH, false);
			kill(0, SIGINT);
			break ;
		}
		sem_post(philo->last_meal.sem);
		sem_post(philo->meal_count.sem);
	}
	sem_wait(philo->info->life_stat.sem);
	philo->info->life_stat.value = false;
	sem_post(philo->info->life_stat.sem);
	return (sem_post(philo->info->print_access.sem), NULL);
}

void	routine(t_philo *philo)
{
	pthread_t	checker_thread;

	pthread_create(&checker_thread, NULL, &check_philosophers, philo);
	while (1)
	{
		eating(philo);
		if (!get_life_state(philo))
			break ;
		sleeping(philo);
		if (!get_life_state(philo))
			break ;
		print_stat(philo, "thinking", C_THINK, true);
		if (!get_life_state(philo))
			break ;
	}
	pthread_join(checker_thread, NULL);
	exit(0);
}
