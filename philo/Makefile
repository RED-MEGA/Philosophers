# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:20:52 by reben-ha          #+#    #+#              #
#    Updated: 2023/04/21 10:17:48 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -g -pthread -fsanitize=thread#,address  #-Wall -Wextra -Werror

SRC = src/philo.c \
	src/parsing.c \
	src/routine.c \
	utils/ft_atoi.c \
	utils/ft_bzero.c \
	utils/ft_calloc.c \
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
	utils/ft_memchr.c \
	utils/ft_memcmp.c \
	utils/ft_memcpy.c \
	utils/ft_memmove.c \
	utils/ft_memset.c \
	utils/ft_printf.c \
	utils/ft_putchar_fd.c \
	utils/ft_putchar_printf.c \
	utils/ft_putendl_fd.c \
	utils/ft_putnbr_fd.c \
	utils/ft_putnbr_hex_printf.c \
	utils/ft_putnbr_pos_printf.c \
	utils/ft_putnbr_printf.c \
	utils/ft_putptr_printf.c \
	utils/ft_putstr_fd.c \
	utils/ft_putstr_printf.c \
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
	utils/get_next_line.c \
	utils/get_next_line_utils.c \
	utils/ft_error.c \
	utils/ft_matdup.c \
	utils/ft_free.c \
	utils/ft_index_list.c

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