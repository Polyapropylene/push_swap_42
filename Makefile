# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhyhorn <rrhyhorn@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 18:20:41 by rrhyhorn          #+#    #+#              #
#    Updated: 2022/07/02 20:10:23 by rrhyhorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS =	push_swap.c\
		ps_big_sort.c\
		ps_find_place.c\
		ps_init.c\
		ps_mini_sort.c\
		ps_operations.c\
		ps_operations2.c\
		ps_operations3.c\
		ps_quick_sort.c\
		ps_separate.c\
		ps_utils.c\
		ps_utils2.c\
		ps_validation.c
		
SRCS_BONUS = checker.c\
			get_next_line.c\
			gnl_utils.c\
			ps_operations.c\
			ps_operations2.c\
			ps_operations3.c\
			ps_validation.c\
			ps_quick_sort.c\
			ps_init.c\
			ps_separate.c\
			ps_utils.c\
			ps_utils2.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o) 

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		gcc $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJS_BONUS) 
		gcc $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o : %.c push_swap.h
	gcc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		rm -f $(OBJS_BONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re