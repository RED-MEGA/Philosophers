/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:00:18 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/17 05:52:27 by reben-ha         ###   ########.fr       */
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

	// init philo :
	// 		create Linked list
	// 		init time_info inside each node of philo
	// 		init mutex inside each node of philo
	// 		init mutex print
	init(&philo, time_info, &print_access);




	// run philo

	// while (1)
	// {
	// 	// while(i < num_ph)
	// 	// {
	// 	// 	// Check if some of philo day : use time
			
	// 	// }
	// }

}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
 		philosophers(argv, (argc == 6));
	else
		return ((void)printf("\033[31;1mError :\033[0m Invalid argument\n"), 1);
	return (0);
}
