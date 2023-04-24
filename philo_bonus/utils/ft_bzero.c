/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:16:24 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/15 05:01:16 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t	i;
	char	*destx;

	i = 0;
	destx = (char *)dest;
	while (i < size)
	{
		destx[i] = '\0';
		i++;
	}
}
