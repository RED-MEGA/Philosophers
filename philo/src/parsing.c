/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:52:47 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/20 02:23:01 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

static bool	before_nb(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i + 1]) == 1
			&& ft_isdigit(arg[i]) == 0
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
		if (ft_isdigit(arg[i]) == 1
			&& ft_isdigit(arg[i + 1]) == 0
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
	(*info)->nb_philo = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atoi(argv[2]);
	(*info)->time_to_eat = ft_atoi(argv[3]);
	(*info)->time_to_sleep = ft_atoi(argv[4]);
	if (optional_arg)
		(*info)->limit_eat = ft_atoi(argv[5]);
	else
		(*info)->limit_eat = FAIL;
	return (true);
}

bool	init(t_philo **philo, t_info *info, pthread_mutex_t *print_access)
{
	t_philo	*new_philo;
	int		id;

	pthread_mutex_init(print_access, NULL);
	(*philo) = NULL;
	id = 0;
	while (id++ < info->nb_philo)
	{
		new_philo = ft_lstnew(id, info);
		new_philo->print_access = print_access;
		new_philo->meal_count = 0;
		new_philo->life_stat = true;
		pthread_mutex_init(&(new_philo->fork), NULL);
		ft_lstadd_back(philo, new_philo);
	}
	ft_lstlast(*philo)->next = *philo;
	return (true);
}
