# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 20:45:49 by dbenkhar          #+#    #+#              #
#    Updated: 2022/03/14 21:00:10 by dbenkhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRCS = *.c

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT = ../libft/libft.a

all :
	$(MAKE) -C ../libft
	${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${LIBFT}

clean :
	$(MAKE) clean -C ../libft
	${RM} ${NAME}

fclean :
	$(MAKE) fclean -C ../libft
	${RM} ${NAME}

re : fclean all
