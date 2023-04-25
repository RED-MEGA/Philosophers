/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:49:28 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/25 16:49:09 by reben-ha         ###   ########.fr       */
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

void	free_sem(t_data *node)
{
	sem_unlink(node->name);
	free(node->name);
}

void	free_memory(t_philo *philo)
{
	t_philo	*tmp;

	free_sem(&philo->info->fork);
	free_sem(&philo->info->print_access);
	free_sem(&philo->info->life_stat);
	while (1)
	{
		free_sem(&philo->meal_count);
		free_sem(&philo->last_meal);
		tmp = philo;
		philo = philo->next;
		free(tmp);
		if (philo->id == 1)
			break ;
	}
	free(philo->info);
}
