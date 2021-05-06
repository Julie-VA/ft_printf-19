/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:35:29 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/04/30 17:22:28 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

void	resetflags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->period = 0;
	flags->mfw = 0;
	flags->prcsn = 0;
	flags->star = 0;
	flags->ident = 0;
	flags->valdi = 0;
	flags->valuxX = 0;
	flags->valp = 0;
	flags->vals = NULL;
	flags->written = 0;
	if (flags)
		free(flags);
}

static void	setprecision(const char *str, int *i, t_flags *flags, va_list ap)
{
	int	prcsn;

	prcsn = 0;
	if (str[*i] == '.')
	{
		flags->period = 1;
		*i += 1;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			prcsn = (prcsn * 10) + (str[*i] - '0');
			*i += 1;
		}
	}
	if (str[*i] == '*')
	{
		if (flags->period != 1)
			flags->mfw = va_arg(ap, int);
		else
			flags->prcsn = va_arg(ap, int);
		*i += 1;
	}
	if (str[*i] == '.' && flags->period != 1)
	{
		flags->period = 1;
		*i += 1;
	}
	if (str[*i] == '*' && flags->period == 1)
	{
		flags->prcsn = va_arg(ap, int);
		*i += 1;
	}
	if (!flags->prcsn)
		flags->prcsn = 0;
}

static int	setmfw(const char *str, int *i)
{
	int	mfw;

	mfw = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		mfw = (mfw * 10) + (str[*i] - '0');
		*i += 1;
	}
	return (mfw);
}

t_flags	*setflags(const char *str, int *i, va_list ap, int *tormv)
{
	t_flags	*flags;
	int		tormvcpy;

	flags = ft_lstnew();
	tormvcpy = *i;
	while (str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '-' && flags->minus != 1)
			flags->minus = 1;
		else if (str[*i] == '0' && flags->zero != 1 && flags->minus != 1)
			flags->zero = 1;
		*i += 1;
	}
	flags->mfw = setmfw(str, i);
	setprecision(str, i, flags, ap);
	flags->ident = str[*i];
	if (flags->mfw < 0)
	{
		flags->star = 1;
		flags->mfw = -flags->mfw;
	}
	*tormv += *i - tormvcpy;
	return (flags);
}
