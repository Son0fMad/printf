# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 18:22:22 by dcloud            #+#    #+#              #
#    Updated: 2021/12/09 19:24:35 by dcloud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c		ft_decimal.c

OBJ		=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
HEADER	=	ft_printf.h

LIBC	=	ar rc
RM		=	rm -f
#
${NAME}	:	${OBJ} ${HEADER}
	${LIBC} ${NAME} $?
#
%.o	:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@
#
all		:	${NAME}
#
clean	:
	${RM} ${OBJ}
#
fclean	:	clean
	${RM} ${NAME}
#
re		:	fclean all
#
.PHONY	:	all clean fclean re


