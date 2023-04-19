/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:52:47 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/19 00:24:23 by reben-ha         ###   ########.fr       */
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

bool	parsing(char **argv, t_time **time_info, bool optional_option)
{
	if (check_format(&argv[1]) == false)
		return (false);
	(*time_info) = (t_time *)malloc(sizeof(t_time));
	if (!(*time_info))
		return (perror_x(ERRMALLOC), false);

	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	printf("%s\n", argv[3]);
	printf("%s\n", argv[4]);
	printf("%p\n", argv[5]);

	(*time_info)->nb_philo = ft_atoi(argv[1]);
	(*time_info)->time_to_die = ft_atoi(argv[2]);
	(*time_info)->time_to_eat = ft_atoi(argv[3]);
	(*time_info)->time_to_sleep = ft_atoi(argv[4]);
	if (optional_option)
		(*time_info)->limit_eat = ft_atoi(argv[5]);
	else
		(*time_info)->limit_eat = FAIL;
	return (true);
}

bool	init(t_philo **philo, t_time *time_info, pthread_mutex_t *print_access)
{
	t_philo	*new_philo;
	int		id;

	pthread_mutex_init(print_access, NULL);
	philo = NULL;
	id = 0;
	while (id++ <= time_info->nb_philo)
	{
		new_philo = ft_lstnew(id, time_info);
		pthread_mutex_init(&(new_philo->fork), NULL);
		ft_lstadd_back(philo, new_philo);
	}
	ft_lstlast(*philo)->next = *philo;
	return (true);
}
