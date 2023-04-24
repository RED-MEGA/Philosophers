/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:34:12 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/24 12:14:21 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "const.h"

int			ft_atoi(const char *str);

t_philo		*ft_lstnew(int id, t_info *info);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		destroy_all(t_philo *philo);

void		usleep_x(long long time_to);
void		delay_maker(bool delay);
long long	current_time(void);

void		ft_error_str(void *status, int code);
void		perror_x(char *error);

#endif