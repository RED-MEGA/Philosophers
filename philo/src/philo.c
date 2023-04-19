/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/19 03:24:30 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	philosophers(char **argv, bool optional_option)
{
	t_philo			*philo;
	t_time			*time_info;
	pthread_mutex_t	print_access;

	if (!parsing(argv, &time_info, optional_option)
		|| !init(&philo, time_info, &print_access))
		return ;

	// run philo threads
	while (1)
	{
		printf("Philo %d is Started\n", philo->id);
		printf("%d \n", time_info->nb_philo);
		if (pthread_create(&philo->philo, NULL, &routine, philo) != 0)
		{
			perror_x(ERROR);
			break;
		}
		philo = philo->next;
		if (philo->id == 1)
			break ;
	}
	



	// Wait for threads to end her execution

	while (philo)
	{
		printf("Thread is %d Wait\n", philo->id);
		if (pthread_join(philo->philo, NULL) == 0)
			printf("Thread is %d finish\n", philo->id);
		philo = philo->next;

		// while(i < num_ph)
		// {
		// 	// Check if some of philo day : use time
			
		// }
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
