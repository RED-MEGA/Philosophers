/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:14:15 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/18 23:42:57 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

t_philo	*ft_lstnew(int id, t_time *time_info)
{
	t_philo	*newnode;

	newnode = (t_philo *)malloc(sizeof(t_philo));
	ft_error_str(newnode, 1);
	newnode->id = id;
	newnode->time_info = time_info;
	newnode->next = NULL;
	return (newnode);
}
