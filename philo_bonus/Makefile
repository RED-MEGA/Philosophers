# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:20:52 by reben-ha          #+#    #+#              #
#    Updated: 2023/04/24 20:30:38 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -g -pthread -fsanitize=thread#thread#,address  #-Wall -Wextra -Werror

SRC = src/philo.c \
	src/parsing.c \
	src/routine.c \
	src/philo_utils.c \
	utils/ft_atoi.c \
	utils/alloc_utils.c \
	utils/ft_bzero.c \
	utils/ft_calloc.c \
	utils/ft_error.c \
	utils/ft_free.c \
	utils/ft_index_list.c \
	utils/ft_isalnum.c \
	utils/ft_isalpha.c \
	utils/ft_isascii.c \
	utils/ft_isdigit.c \
	utils/ft_isprint.c \
	utils/ft_itoa.c \
	utils/ft_lstadd_back.c \
	utils/ft_lstadd_front.c \
	utils/ft_lstclear.c \
	utils/ft_lstdelone.c \
	utils/ft_lstiter.c \
	utils/ft_lstlast.c \
	utils/ft_lstnew.c \
	utils/ft_lstsize.c \
	utils/ft_matdup.c \
	utils/ft_putstr_fd.c \
	utils/ft_split.c \
	utils/ft_strchr.c \
	utils/ft_strdup.c \
	utils/ft_striteri.c \
	utils/ft_strjoin.c \
	utils/ft_strlcat.c \
	utils/ft_strlcpy.c \
	utils/ft_strlen.c \
	utils/ft_strmapi.c \
	utils/ft_strncmp.c \
	utils/ft_strnstr.c \
	utils/ft_strrchr.c \
	utils/ft_substr.c \
	utils/time_utils.c \
	utils/to_int.c

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