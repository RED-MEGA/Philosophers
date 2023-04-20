/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/20 02:59:12 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

long long current_time() 
{
	struct timeval current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec * 1000ll) + (current.tv_usec / 1000ll));
}

void	philosophers(char **argv, bool optional_arg)
{
	t_philo			*philo;
	t_info			*info;
	pthread_mutex_t	print_access;

	if (!parsing(argv, &info, optional_arg)
		|| !init(&philo, info, &print_access))
		return ;
	while (1)
	{
		if (pthread_create(&philo->philo, NULL, &routine, philo) != 0)
		{
			perror_x("Cannot create Thread");
			break;
		}
		philo = philo->next;
		if (philo->id == 1)
			break ;
	}


	// Wait for threads to end her execution
	delay_maker(true);
	while (philo)
	{
		if ((current_time() - philo->last_meal) >= philo->info->time_to_die
			|| (optional_arg == true && philo->meal_count == philo->info->limit_eat))
		{
			print_stat(philo, "Dead 🧟‍♂️", C_DEATH);
			break ;
		}
		philo = philo->next;
	}
	int i = philo->info->nb_philo;
	while (i-- != 0)
	{
		pthread_detach(philo->philo);
		philo = philo->next;
	}
	
	// destroy_all(&philo);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
 		philosophers(argv, (argc == 6));
	else
		return (perror_x(ERRINVALID), 1);
	return (0);
}
