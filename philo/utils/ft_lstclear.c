/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:56:51 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/19 00:20:23 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

void	destroy_all(t_philo **lst)
{
	t_philo	*next;

	pthread_mutex_destroy((*lst)->print_access);
	free((*lst)->time_info) ;
	while (*lst)
	{
		// (*lst)->philo; // destroy pthread_t
		pthread_mutex_destroy(&(*lst)->fork);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
