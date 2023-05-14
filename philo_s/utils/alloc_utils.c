/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:49:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/05/14 17:41:10 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

t_philo	*new_node(int id, t_info *info)
{
	t_philo	*newnode;

	newnode = (t_philo *)malloc(sizeof(t_philo));
	ft_error_str(newnode, 1);
	newnode->id = id;
	newnode->info = info;
	newnode->next = NULL;
	return (newnode);
}

t_philo	*last_node(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	add_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = last_node(*lst);
	last->next = new;
}

void	free_memory(t_philo *philo)
{
	t_philo	*tmp;

	// pthread_mutex_destroy(philo->print_access);
	// free(philo->info);
	// free(philo->print_access);
	while (1)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
		if (philo->id == 1)
			break ;
	}
}
