# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 11:51:03 by rvan-aud          #+#    #+#              #
#    Updated: 2021/05/21 14:34:48 by rvan-aud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c					\
			ft_printf_cprcntflags.c		\
			ft_printf_cswrite.c			\
			ft_printf_genflags.c		\
			ft_printf_intflags.c		\
			ft_printf_intflags_utils.c	\
			ft_printf_intuscount.c		\
			ft_printf_intwrite.c		\
			ft_printf_legal.c			\
			ft_printf_pcount.c			\
			ft_printf_pflags.c			\
			ft_printf_pflags_utils.c	\
			ft_printf_putnbrs.c			\
			ft_printf_resetflags.c		\
			ft_printf_sflags.c			\
			ft_printf_uflags.c			\
			ft_printf_uflags_utils.c	\
			ft_printf_utils.c			\
			ft_printf_write.c			\
			ft_printf_xXcount.c			\
			ft_printf_xXflags.c			\
			ft_printf_xXflags_utils.c	\

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

${NAME}:	${OBJS} 
			@${CC} ${CFLAGS} -c ${SRCS}
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
