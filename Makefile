# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 12:51:59 by scartage          #+#    #+#              #
#    Updated: 2022/03/25 17:03:19 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRC_S = server.c
SRC_C = client.c

SRC_S_BONUS = server_bonus.c
SRC_C_BONUS = client_bonus.c

OBJS_S = ${SRC_S:.c=.o}
OBJS_C = ${SRC_C:.c=.o}

OBJS_S_BONUS = ${SRC_S_BONUS:.c=.o}
OBJS_C_BONUS = ${SRC_C_BONUS:.c=.o}

#NAME = minitalk

NAME_S = server
NAME_C = client

NAME_S_BONUS = server_bonus
NAME_C_BONUS = client_bonus

RM = rm -f

.c.o:
	make -C libft
	make -C printf

all:	${NAME_S} ${NAME_C}

${NAME_S}: ${OBJS_S}
		${CC} ${CFLAGS} ${SRC_S} libft/libft.a printf/libftprintf.a -o server

${NAME_C}: ${OBJS_C}
		${CC} ${CFLAGS} ${SRC_C}  libft/libft.a printf/libftprintf.a -o client

bonus: ${NAME_S_BONUS} ${NAME_C_BONUS}

${NAME_S_BONUS}: ${OBJS_S_BONUS}
		${CC} ${CFLAGS} ${SRC_S_BONUS} libft/libft.a printf/libftprintf.a -o server_bonus

${NAME_C_BONUS}: ${OBJS_C_BONUS}
		${CC} ${CFLAGS} ${SRC_C_BONUS}  libft/libft.a printf/libftprintf.a -o client_bonus
clean:
		${RM} ${OBJS_C}
		${RM} ${OBJS_S}

		${RM} ${OBJS_C_BONUS}
		${RM} ${OBJS_S_BONUS}
		make clean -C libft
		make clean -C printf

fclean: clean
		${RM} ${NAME_S} ${NAME_C} ${NAME_S_BONUS} ${NAME_C_BONUS}
		make fclean -C libft
		make fclean -C printf
		
re:		fclean all

.PHONY: all clean fclean re bonus
