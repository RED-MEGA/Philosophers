/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:56:51 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/20 02:41:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

void	destroy_all(t_philo **philo)
{
	t_philo	*next;

	pthread_mutex_destroy((*philo)->print_access);
	free((*philo)->info);
	while (*philo)
	{
		pthread_mutex_destroy(&(*philo)->fork);
		next = (*philo)->next;
		free(*philo);
		*philo = NULL;
		*philo = next;
	}
}
