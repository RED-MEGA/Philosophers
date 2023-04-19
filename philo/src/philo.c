/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/19 05:49:21 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	philosophers(char **argv, bool optional_arg)
{
	t_philo			*philo;
	t_time			*time_info;
	pthread_mutex_t	print_access;

	if (!parsing(argv, &time_info, optional_arg)
		|| !init(&philo, time_info, &print_access))
		return ;
	while (1)
	{
		if (pthread_create(&philo->philo, NULL, &routine, philo) != 0)
		{
			perror_x("Cannot create ");
			break;
		}
		philo = philo->next;
		if (philo->id == 1)
			break ;
	}





	// Wait for threads to end her execution
	while (philo)
	{
		// check life stat 
		// if optional arg enable : Check eat time
		if (pthread_join(philo->philo, NULL) != 0)
			printf("Thread is %d finish\n", philo->id);
		philo = philo->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
 		philosophers(argv, (argc == 6));
	else
		return (perror_x(ERRINVALID), 1);
	return (0);
}
