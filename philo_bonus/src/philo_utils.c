/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:30:44 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/25 16:49:24 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

bool	new_sem(t_data *sem_node, int ini_value, const char *name, bool include_id)
{
	static int id;

	if (include_id)
		sem_node->name = ft_strjoin(ft_itoa(++id), name);
	else
		sem_node->name = ft_strdup(name);
	sem_node->sem = sem_open(sem_node->name, O_CREAT, 0644, ini_value);
	return (false);
}
