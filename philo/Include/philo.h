/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:02:14 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/17 04:52:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include "utils.h"

# define ERROR  "\033[31;1mError :\033[0m "

typedef struct s_time_info
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	limit_eat;
}		t_time;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	*print_access;
	t_time			*time_info;

	struct s_philo	*next;
}					t_philo;

/* nb_philo time_to_die time_to_eat time_to_sleep
	option [number_of_times_each_philosopher_must_eat] */
bool	parsing(char **argv, t_time *time_info, bool optional_option);
bool	init(t_philo **philo, t_time *time_info, pthread_mutex_t *print_access);

#endif