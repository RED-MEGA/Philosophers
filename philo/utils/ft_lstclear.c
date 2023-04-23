/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:56:51 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/23 19:53:39 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

void	destroy_all(t_philo *philo)
{
	t_philo	*tmp;

	pthread_mutex_destroy(philo->print_access);
	free(philo->info);
	free(philo->print_access);
	while (1)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
		if (philo->id == 1)
			break ;
	}
}
