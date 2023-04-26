/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:52:47 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/26 21:54:17 by reben-ha         ###   ########.fr       */
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
	t_philo	*new_philo;
	int		id;

	(*philo) = NULL;
	new_sem(&info->fork, info->nb_philo, ft_strjoin("fork-", "0", false));
	new_sem(&info->print_access, 1, ft_strjoin("print_access-", "0", false));
	new_sem(&info->life_stat, 1, ft_strjoin("life_stat-", "0", false));
	id = 0;
	while (id++ < info->nb_philo)
	{
		new_philo = new_node(id, info);
		new_sem(&new_philo->last_meal, 1, ft_strjoin("last_meal-", ft_itoa(id), false));
		new_sem(&new_philo->meal_count, 1, ft_strjoin("meal_count-", ft_itoa(id), false));
		new_philo->meal_count.value = 0;
		add_back(philo, new_philo);
	}
	last_node(*philo)->next = *philo;
	return (true);
}
