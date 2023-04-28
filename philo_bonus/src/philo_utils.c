/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:30:44 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/28 10:27:48 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static char	*generator_tmp(void)
{
	char		*gen_tmp;
	char		*tmp;
	int			*num;

	num = malloc(4);
	read(open("/dev/urandom", O_RDONLY), num, 4);
	tmp = ft_itoa(*num);
	gen_tmp = ft_strjoin("/sem-", tmp, false);
	return (free(num), free(tmp), gen_tmp);
}

bool	new_sem(t_data *sem_node, int ini_value, const char *name)
{
	// sem_node->name = ft_strjoin(ft_strdup("/"), name, true);
	sem_node->name = generator_tmp();
	sem_node->sem = sem_open(sem_node->name, O_CREAT, 0644, ini_value);
	return (false);
}
