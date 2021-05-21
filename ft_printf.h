/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:15:07 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/21 14:13:50 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define LLU unsigned long long int

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				period;
	int				mfw;
	int				prcsn;
	int				star;
	char			ident;
	int				valdi;
	unsigned int	valuxX;
	LLU				valp;
	char			*vals;
	char			resultxX[9];
	char			resultp[16];
	int				notwrite;
}	t_flags;

int		ft_printf(const char *str, ...);

/*
** Flags
*/
t_flags	*setflags(const char *str, int *i, va_list ap, int *tormv);
void	resetflags(t_flags *flags);
t_flags	*set_sflags(const char *str, int *i, va_list ap, int *tormv);

/*
** Legal
*/
int		islegal(const char *s, int i);
int		charislegal(char c);

/*
** Write and len
*/
int		writestr(const char *str, va_list ap);
int		sgetlen(va_list ap, t_flags *flags, int *count);
int		dgetlen(va_list ap, t_flags *flags, int *count);

/*
** Utils etc
*/
t_flags	*ft_lstnew(void);
int		ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstrp(char *str);
void	ft_putnbr(int nb, int written);
void	ft_uputnbr(unsigned int nb, int written);
char	convhex(int mod, int cap);
void	ft_rev_int_tab(char *tab, int size);

/*
** Count
*/
int		countint(va_list ap, int *count, t_flags *flags);
int		countuint(va_list ap, int *count, t_flags *flags);
void	scount(char *s, int *count, t_flags *flags);
void	countnputnbrhex(va_list ap, int cap, int *count, t_flags *flags);
void	countnputnbrlluhex(va_list ap, int *count, t_flags *flags);

/*
** Cprcnt
*/
int		capplyflags(va_list ap, t_flags *flags, int *count);
int		cwrite(t_flags *flags, va_list ap, int *count);
int		prcntapplyflags(t_flags *flags, int *count);
void	prcntwrite(t_flags *flags, int *count);

/*
** S
*/
int		sapplyflags(va_list ap, t_flags *flags, int *count);
void	swrite(t_flags *flags, va_list ap, int *count);

/*
** Int
*/
int		intapplyflags(va_list ap, t_flags *flags, int *count);
void	intwrite(t_flags *flags, va_list ap, int *count);
int		intprintzero(int len, int *count);
int		intprcsn(int len, t_flags *flags, int *count);
void	intmfw(int len, int *count, t_flags *flags);

/*
** P
*/
int		papplyflags(va_list ap, t_flags *flags, int *count, int *check);
void	powrite(t_flags *flags, va_list ap, int *count);
int		pprintzero(int len, int *count);
int		pprcsn(int len, t_flags *flags, int *count);
void	pmfw(int len, int *count, t_flags *flags);

/*
** U
*/
int		uapplyflags(va_list ap, t_flags *flags, int *count);
void	uwrite(t_flags *flags, va_list ap, int *count);
int		uprintzero(int len, int *count);
int		uprcsn(int len, t_flags *flags, int *count);
void	umfw(int len, int *count, t_flags *flags);

/*
** X
*/
int		xapplyflags(va_list ap, t_flags *flags, int *count);
void	xwrite(t_flags *flags, va_list ap, int *count);
int		xprintzero(int len, int *count);
int		xprcsn(int len, t_flags *flags, int *count);
void	xmfw(int len, int *count, t_flags *flags);

#endif
