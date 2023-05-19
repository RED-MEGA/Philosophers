/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:52:47 by reben-ha          #+#    #+#             */
/*   Updated: 2023/05/19 16:25:23 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static bool	check_format(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isnb(argv[i][j]) == false)
				return (perror_x(ERRINVALID), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	parsing(char **argv, t_info **info, bool optional_arg)
{
	if (check_format(argv) == false)
		return (false);
	(*info) = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return (perror_x(ERRMALLOC), false);
	(*info)->life_stat.value = true;
	(*info)->nb_philo = to_int(argv[1]);
	(*info)->time_to_die = to_int(argv[2]);
	(*info)->time_to_eat = to_int(argv[3]);
	(*info)->time_to_sleep = to_int(argv[4]);
	if (optional_arg)
		(*info)->limit_eat = to_int(argv[5]);
	else
		(*info)->limit_eat = FAIL;
	return (true);
}

bool	init(t_philo **philo, t_info *info)
{
	t_philo			*new_philo;
	pthread_mutex_t	*print_access;
	int				id;

	print_access = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print_access, NULL);
	pthread_mutex_init(&info->life_stat.mutex, NULL);
	(*philo) = NULL;
	id = 0;
	while (id++ < info->nb_philo)
	{
		new_philo = new_node(id, info);
		new_philo->print_access = print_access;
		new_philo->meal_count.value = 0;
		pthread_mutex_init(&(new_philo->fork), NULL);
		pthread_mutex_init(&(new_philo->last_meal.mutex), NULL);
		pthread_mutex_init(&(new_philo->meal_count.mutex), NULL);
		add_back(philo, new_philo);
	}
	last_node(*philo)->next = *philo;
	return (true);
}
