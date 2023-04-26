/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/26 20:04:54 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static void	run_philosophers(t_philo *philo)
{
	long long		t0;

	t0 = current_time();
	while (1)
	{
		philo->info->t0 = t0;
		philo->last_meal.value = t0;
		philo->philo = fork();
		ft_error(philo->philo, 1);
		if (philo->philo == 0)
			routine(philo);
		philo = philo->next;
		if (philo->id == 1)
			break ;
	}
}

static void	check_philosophers(t_philo *philo, bool optional_arg)
{
	while (philo)
	{
		sem_wait(philo->last_meal.sem);
		sem_wait(philo->meal_count.sem);
		if (current_time() - philo->last_meal.value >= philo->info->time_to_die
			|| (optional_arg == true
				&& philo->meal_count.value == philo->info->limit_eat))
		{
			print_stat(philo, "Dead 🧟‍", C_DEATH, false);
			break ;
		}
		sem_post(philo->last_meal.sem);
		sem_post(philo->meal_count.sem);
		philo = philo->next;
	}
	sem_wait(philo->info->life_stat.sem);
	philo->info->life_stat.value = false;
	sem_post(philo->info->life_stat.sem);
	sem_post(philo->info->print_access.sem);
}

static void	waiting_philosophers(t_philo *philo)
{
	philo = philo->next;
	while (philo->id != 1)
	{
		kill(philo->philo, SIGTERM);
		philo = philo->next;
	}
	while (waitpid(WAIT_ANY, NULL, 0) != -1)
		;
}

static void	philosophers(char **argv, bool optional_arg)
{
	t_philo			*philo;
	t_info			*info;

	if (!parsing(argv, &info, optional_arg) || !init(&philo, info))
		return ;
	run_philosophers(philo);
	check_philosophers(philo, optional_arg);
	waiting_philosophers(philo);
	free_memory(philo);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		philosophers(argv, (argc == 6));
	else
		return (perror_x(ERRINVALID), 1);
	return (0);
}
