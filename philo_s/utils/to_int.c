/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:42:01 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/24 12:43:32 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

int	isnb(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	to_int(const char *str)
{
	size_t	nb;
	int		i;
	int		sg;

	sg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sg = -1;
		i++;
	}
	nb = 0;
	while (isnb(str[i]))
	{
		nb = nb * 10 + (((int)str[i]) - 48);
		i++;
	}
	return (nb * sg);
}
