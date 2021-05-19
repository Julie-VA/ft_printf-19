# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 11:51:03 by rvan-aud          #+#    #+#              #
#    Updated: 2021/05/19 09:24:37 by rvan-aud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c					\
			ft_printf_cprcntflags.c		\
			ft_printf_pcount.c			\
			ft_printf_intuscount.c		\
			ft_printf_xXcount.c			\
			ft_printf_intflags.c		\
			ft_printf_intflags_utils.c	\
			ft_printf_intwrite.c		\
			ft_printf_genflags.c		\
			ft_printf_sflags.c			\
			ft_printf_legal.c			\
			ft_printf_pflags.c			\
			ft_printf_pflags_utils.c	\
			ft_printf_putnbrs.c			\
			ft_printf_uflags.c			\
			ft_printf_utils.c			\
			ft_printf_cswrite.c			\
			ft_printf_write.c			\
			ft_printf_xXflags.c			\

SRCG	= ft_printf.o				\
			ft_printf_cprcntflags.o	\
			ft_printf_countp.o		\
			ft_printf_count.o		\
			ft_printf_countxX.o		\
			ft_printf_dflags.o		\
			ft_printf_intwrite.o	\
			ft_printf_sflags.o		\
			ft_printf_legal.o		\
			ft_printf_pflags.o		\
			ft_printf_putnbrs.o		\
			ft_printf_uflags.o		\
			ft_printf_utils.o		\
			ft_printf_cswrite.o		\
			ft_printf_write.o		\
			ft_printf_xflags.o		\

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

gitclean:
			git rm ${SRCG}

re:			fclean all

.PHONY:		all clean fclean re bonus

			# ft_printf_applymfw.c	\
			ft_printf_applyprcsn.c	\
			ft_printf_flags.c		\
			ft_printf_write.c		\
			