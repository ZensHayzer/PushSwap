# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 16:10:48 by ajeanne           #+#    #+#              #
#    Updated: 2022/11/12 19:36:13 by ajeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -g3 -Wall -Werror -Wextra
SRCS = 	push_swap.c		\
		list_utils.c	\
		list_utils1.c	\
		list_utils2.c	\
		list_utils3.c	\
		list_utils4.c	\
		list_utils5.c	\
		list_utils6.c	\
		moving_func.c	\
		moving_func1.c	\
		sorting_func.c	\
		sort_neededs.c	\
		opti_func.c		\
		push_elements.c	\
		push_elements1.c\
		sorting_case.c	\
		sorting_exec.c

OBJS = ${SRCS:.c=.o}

.PHONY:all
all:	${NAME}

%.o:%.c
	${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.PHONY:bonus
bonus:
	make -C bonus

.PHONY:clean
clean:
	rm -f *.o
	make clean -C bonus

.PHONY:fclean
fclean:	clean
	rm -f ${NAME}
	make fclean -C bonus

.PHONY:re
re:	fclean all
