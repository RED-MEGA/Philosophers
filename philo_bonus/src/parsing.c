/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:52:47 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/24 20:50:53 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static bool	before_nb(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (isnb(arg[i + 1]) == 1
			&& isnb(arg[i]) == 0
			&& arg[i] != ' '
			&& arg[i] != '+')
			return (false);
		i++;
	}
	return (true);
}

static bool	after_nb(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (isnb(arg[i]) == 1
			&& isnb(arg[i + 1]) == 0
			&& arg[i + 1] != ' '
			&& arg[i + 1] != '\0')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_format(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		if (before_nb(argv[i]) == false || after_nb(argv[i]) == false)
			return (perror_x(ERRINVALID), false);
	return (true);
}

bool	parsing(char **argv, t_info **info, bool optional_arg)
{
	if (check_format(&argv[1]) == false)
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
	sem_t			*fork_sem;
	int				id;

	fork_sem = sem_open("fork", O_CREAT, 0644, info->nb_philo);

	info.
// continue
	(*philo) = NULL;
	id = 0;
	while (id++ < info->nb_philo)
	{
		new_philo = new_node(id, info);
		new_philo->meal_count.value = 0;
		new_philo->meal_count.mutex = sem_open("meal_count", O_CREAT, 0644, 1);
		new_philo->last_meal.value = current_time();
		new_philo->last_meal.mutex = sem_open("last_meal", O_CREAT, 0644, 1);
		add_back(philo, new_philo);
	}
	last_node(*philo)->next = *philo;
	return (true);
}
