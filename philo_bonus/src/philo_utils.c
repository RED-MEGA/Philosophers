/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:30:44 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/26 21:54:38 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

bool	new_sem(t_data *sem_node, int ini_value, const char *name)
{
	sem_node->name = ft_strjoin(ft_strdup("/"), name, true);
	sem_node->sem = sem_open(sem_node->name, O_CREAT, 0644, ini_value);
	return (false);
}
