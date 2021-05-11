/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:15:07 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/11 18:56:30 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

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

int		ft_printf(const char *, ...);

//flags
t_flags	*setflags(const char *str, int *i, va_list ap, int *tormv);
void	resetflags(t_flags *flags);
t_flags	*set_sflags(const char *str, int *i, va_list ap, int *tormv);
int		sapplyflags(va_list ap, t_flags *flags, int *count);
int		dapplyflags(va_list ap, t_flags *flags, int *count);
int		uapplyflags(va_list ap, t_flags *flags, int *count);

//legal
int		checklegal(const char *str, t_flags *flags, int i);
int		islegal(const char *s, int i);
int		writenotlegal(const char *str, int i, int *count);

//write
int		writestr(const char *str, va_list ap);
void	swrite(t_flags *flags, va_list ap, int *count);
int		sgetlen(va_list ap, t_flags *flags, int *count);
void	dwrite(t_flags *flags, va_list ap, int *count);
int		dgetlen(va_list ap, t_flags *flags, int *count);
void	uwrite(t_flags *flags, va_list ap, int *count);

//utils
t_flags	*ft_lstnew(void);
int		ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstrp(char *str);

//diu
void	ft_putnbr(int nb, int written);
void	ft_uputnbr(unsigned int nb, int written);

//xX
char	convhex(int mod, int cap);
void	ft_rev_int_tab(char *tab, int size);

//counts
int		countint(va_list ap, int *count, t_flags *flags);
int		countuint(va_list ap, int *count, t_flags *flags);
int		scount(char *s, int *count, t_flags *flags);
void	countnputnbrhex(va_list ap, int cap, int *count, t_flags *flags);
void	countnputnbrlluhex(va_list ap, int *count, t_flags *flags);

//applyflags
int		applymfw(va_list ap, t_flags *flags, int len, int *count);
int		applyprcsn(t_flags *flags, int *len, int *count);

#endif
