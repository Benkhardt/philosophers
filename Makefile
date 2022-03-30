# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 11:25:45 by dbenkhar          #+#    #+#              #
#    Updated: 2022/03/30 11:39:31 by dbenkhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= eat.c exit_clear.c forks.c init.c \
			main.c messages.c start_threads.c \
			utils.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lpthread

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclean re
