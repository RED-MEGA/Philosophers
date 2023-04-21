/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:02:14 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/21 09:37:24 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "const.h"
# include "utils.h"

/* nb_philo time_to_die time_to_eat time_to_sleep
	option [number_of_times_each_philosopher_must_eat] */
bool	parsing(char **argv, t_info **info, bool optional_arg);
bool	init(t_philo **philo, t_info *info);
void	*routine(void *ptr);
bool	print_stat(t_philo *philo, char *stat, char *color, int unlock);
long long current_time();
void	delay_maker(bool delay);
void	usleep_x(int time_to);

#endif