/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:02:14 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/20 01:47:59 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "const.h"
# include "utils.h"

/* nb_philo time_to_die time_to_eat time_to_sleep
	option [number_of_times_each_philosopher_must_eat] */
bool	parsing(char **argv, t_info **info, bool optional_arg);
bool	init(t_philo **philo, t_info *info, pthread_mutex_t *print_access);
void	*routine(void *ptr);
void	print_stat(t_philo *philo, char *stat, char *color);
long long current_time();
void	delay_maker(bool delay);

#endif