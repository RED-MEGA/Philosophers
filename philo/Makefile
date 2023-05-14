# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:20:52 by reben-ha          #+#    #+#              #
#    Updated: 2023/05/14 15:00:28 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -g -pthread #-fsanitize=thread#thread#,address  #-Wall -Wextra -Werror

SRC = src/philo.c \
	src/parsing.c \
	src/routine.c \
	utils/to_int.c \
	utils/alloc_utils.c \
	utils/ft_error.c \
	utils/time_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c Include/const.h Include/philo.h Include/utils.h
	cc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

run : all clean

.PHONY : all clean fclean re