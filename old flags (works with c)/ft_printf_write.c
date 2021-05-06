/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:06:16 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/05 11:24:15 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

static int	getlen(va_list ap, t_flags *flags, int *count)
{
	int	len;

	len = *count;
	if (flags->ident == 'c')
		*count += 1;
	else if (flags->ident == 's')
		counts(va_arg(ap, char *), count, flags);
	else if (flags->ident == 'd' || flags->ident == 'i')
		countint(ap, count, flags);
	else if (flags->ident == 'u')
		countuint(ap, count, flags);
	else if (flags->ident == 'x')
		countnputnbrhex(ap, 0, count, flags);
	else if (flags->ident == 'X')
		countnputnbrhex(ap, 1, count, flags);
	else if (flags->ident == 'p')
		countnputnbrlluhex(ap, count, flags);
	return (*count - len);
}

static int	applyflags(va_list ap, t_flags *flags, int *count, int *i)
{
	int	len;

	len = getlen(ap, flags, count);
	if (flags->valdi < 0 && flags->minus == 1)
	{
		write(1, "-", 1);
		flags->valdi = -flags->valdi;
		flags->written = 2;
	}
	if (flags->prcsn > 0)
	{
		flags->written = applyprcsn(flags, &len, count);
		if (flags->written == 1)
			*i += 1;
	}
	if (flags->mfw > 0)
	{
		flags->written = applymfw(ap, flags, len, count);
		if (flags->written == 1)
			*i += 1;
	}
	return (flags->written);
}

static int	writeident(va_list ap, int i, t_flags *flags)
{
	if (flags->ident == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (flags->ident == 's')
		ft_putstr(flags->vals);
	else if (flags->ident == 'd' || flags->ident == 'i')
		ft_putnbr(flags->valdi, flags->written);
	else if (flags->ident == 'u')
		ft_uputnbr(flags->valuxX);
	else if (flags->ident == 'x')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'X')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'p')
		ft_putstrp(flags->resultp);
	return (++i);
}

int	writestr(const char *str, va_list ap)
{
	int		i;
	int		icpy;
	t_flags	*flags;
	int		count;
	int		prcnts;
	int		tormv;

	i = 0;
	count = 0;
	prcnts = 0;
	tormv = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			icpy = i;
			prcnts++;
			flags = setflags(str, &i, ap, &tormv);
			// if (!checklegal(str, flags, i))
			// {
			// 	i = writenotlegal(str, icpy, &count);
			// 	resetflags(flags);
			// 	continue ;
			// }
			flags->written = applyflags(ap, flags, &count, &i);
			if (flags->written == 0)
				i = writeident(ap, i, flags);
			resetflags(flags);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i + count - (prcnts * 2) - tormv);
}
