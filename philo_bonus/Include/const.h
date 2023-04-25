/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:01:56 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/25 15:46:11 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>
# include <semaphore.h>

/* Macro */

# define ERROR  "\033[31;1mError :\033[0m "
# define FAIL -1
# define SUCCESS 0

# define ERRMALLOC "Cannot allocate memory"
# define ERRFORK "Failed to fork process"
# define ERRPERMISSION "Permission denied"
# define ERRINVALID "Invalid argument"

# define C_EAT "\e[1;35m"
# define C_SLEEP "\e[1;30m"
# define C_THINK "\e[1;33m"
# define C_DEATH "\033[1;31m"
# define C_RESET "\e[0m"
/* Struct */

typedef struct s_data
{
	char		*name;
	long long	value;
	sem_t		*sem;
}					t_data;

typedef struct s_info
{
	long long		t0;
	t_data			life_stat;
	t_data			fork;
	t_data			print_access;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				limit_eat;
}					t_info;

typedef struct s_philo
{
	int				id;
	pid_t			philo;
	t_data			last_meal;
	t_data			meal_count;
	t_info			*info;

	struct s_philo	*next;
}					t_philo;

#endif