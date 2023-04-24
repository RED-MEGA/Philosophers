/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:34:12 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/24 13:27:12 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "const.h"

int			to_int(const char *str);
int			isnb(int c);

t_philo		*new_node(int id, t_info *info);
void		add_back(t_philo **lst, t_philo *new);
t_philo		*last_node(t_philo *lst);
void		free_memory(t_philo *philo);

void		usleep_x(long long time_to);
void		delay_maker(bool delay);
long long	current_time(void);

void		ft_error_str(void *status, int code);
void		perror_x(char *error);

#endif