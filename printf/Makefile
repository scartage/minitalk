# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 15:09:45 by scartage          #+#    #+#              #
#    Updated: 2022/03/24 15:21:47 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

CC = gcc

SRCS	= ft_printf.c ft_printf_tools.c ft_print_args.c ft_tools_hex.c ft_put_ptr.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

all:	${NAME}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
	
re:		fclean all

.PHONY: all clean fclean re
