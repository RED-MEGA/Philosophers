/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/05/03 18:33:23 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static void	run_philosophers(t_philo *philo)
{
	long long		t0;

	t0 = current_time();
	while (true)
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

static void	waiting_philosophers(void)
{
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
	waiting_philosophers();
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
