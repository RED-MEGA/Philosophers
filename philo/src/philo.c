/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/23 21:26:49 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static void	run_threads(t_philo *philo)
{
	long long		t0;

	t0 = current_time();
	while (1)
	{
		philo->t0 = t0;
		if (pthread_create(&philo->philo, NULL, &routine, philo) != 0)
		{
			perror_x("Cannot create Thread");
			break ;
		}
		philo = philo->next;
		if (philo->id == 1)
			break ;
	}
}

static void	check_threads(t_philo *philo, bool optional_arg)
{
	while (philo)
	{
		pthread_mutex_lock(&philo->last_meal.mutex);
		pthread_mutex_lock(&philo->meal_count.mutex);
		if (current_time() - philo->last_meal.value >= philo->info->time_to_die
			|| (optional_arg == true
				&& philo->meal_count.value == philo->info->limit_eat))
		{
			print_stat(philo, "Dead 🧟‍", C_DEATH, false);
			break ;
		}
		pthread_mutex_unlock(&philo->last_meal.mutex);
		pthread_mutex_unlock(&philo->meal_count.mutex);
		philo = philo->next;
	}
	pthread_mutex_lock(&philo->info->life_stat.mutex);
	philo->info->life_stat.value = false;
	pthread_mutex_unlock(&philo->info->life_stat.mutex);
	pthread_mutex_unlock(philo->print_access);
}

static void	waiting_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (++i <= philo->info->nb_philo)
	{
		if (pthread_join(philo->philo, NULL) != 0)
			perror_x("Unable to join");
		philo = philo->next;
	}
}

static void	philosophers(char **argv, bool optional_arg)
{
	t_philo			*philo;
	t_info			*info;

	if (!parsing(argv, &info, optional_arg) || !init(&philo, info))
		return ;
	run_threads(philo);
	check_threads(philo, optional_arg);
	waiting_threads(philo);
	destroy_all(philo);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		philosophers(argv, (argc == 6));
	else
		return (perror_x(ERRINVALID), 1);
	return (0);
}
