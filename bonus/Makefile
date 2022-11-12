# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 16:10:48 by ajeanne           #+#    #+#              #
#    Updated: 2022/11/12 19:36:18 by ajeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = clang
CFLAGS = -g3 -Wall -Werror -Wextra
GNL_FOLD = gnl
SRCS = 	checker.c							\
		execute.c							\
		moving_calls.c						\
		moving_calls1.c						\
		moving.c							\
		utils.c								\
		utils1.c							\
		${GNL_FOLD}/get_next_line.c			\
		${GNL_FOLD}/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

.PHONY:all
all:	${NAME}

%.o:%.c
	${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.PHONY:clean
clean:
	rm -f *.o
	rm -f ${GNL_FOLD}/*.o

.PHONY:fclean
fclean:	clean
	rm -f ${NAME}

.PHONY:re
re:	fclean all
