/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:29:11 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/15 05:01:16 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*strx;

	i = 0;
	strx = (unsigned char *)str;
	while (i < len)
	{
		strx[i] = (unsigned char)c;
		i++;
	}
	return (strx);
}
