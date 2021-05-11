# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 11:51:03 by rvan-aud          #+#    #+#              #
#    Updated: 2021/05/11 17:24:47 by rvan-aud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c				\
			ft_printf_countp.c		\
			ft_printf_count.c		\
			ft_printf_countxX.c		\
			ft_printf_dflags.c		\
			ft_printf_dwrite.c		\
			ft_printf_sflags.c		\
			ft_printf_legal.c		\
			ft_printf_putnbrs.c		\
			ft_printf_utils.c		\
			ft_printf_swrite.c		\
			ft_printf_write.c		\

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

			# ft_printf_applymfw.c	\
			ft_printf_applyprcsn.c	\
			ft_printf_flags.c		\
			ft_printf_write.c		\
			