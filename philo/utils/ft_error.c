/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:17:22 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/24 12:14:12 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_error_str(void *status, int code)
{
	if (status == NULL)
		return (perror("Error "), exit(code));
}

void	perror_x(char *error)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}
