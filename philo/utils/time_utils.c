/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:25:49 by reben-ha          #+#    #+#             */
/*   Updated: 2023/05/18 15:59:21 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

long long	current_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec * 1000ll) + (current.tv_usec / 1000ll));
}

void	usleep_x(long long time_to)
{
	long long	start;

	start = current_time();
	while (current_time() - start < time_to)
		usleep(100);
}

void	delay_maker(bool delay)
{
	if (delay)
		usleep(2 * 1000);
}
