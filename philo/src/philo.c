/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/19 02:56:21 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	philosophers(char **argv, bool optional_option)
{
	t_philo			*philo;
	t_time			*time_info;
	pthread_mutex_t	print_access;

	if (!parsing(argv, &time_info, optional_option))
		return ;
	/* Check */
	// printf("%d\n", time_info->nb_philo);
	// printf("%d\n", time_info->time_to_die);
	// printf("%d\n", time_info->time_to_eat);
	// printf("%d\n", time_info->time_to_sleep);
	// printf("%d\n", time_info->limit_eat);
	// printf("%d\n", optional_option);


	init(&philo, time_info, &print_access);
	/* Check */
	// while (philo || philo->id >= time_info->nb_philo)
	// {
	// 	printf("The id is : %d\n", philo->id);
	// 	printf("The time_info is : %p\n", philo->time_info);
	// 	printf("The fork is : %p\n", &philo->fork);
	// 	philo = philo->next;
	// }


	// run philo
	int i = -1;
	while (++i < time_info->nb_philo)
	{
		printf("Philo %d is Started\n", philo->id);
		if (pthread_create(&philo->philo, NULL, &routine, philo) != 0)
			printf(ERROR);
		philo = philo->next;
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
