/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_genflags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:46:20 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/21 14:00:42 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	flags->notwrite = 0;
}

static int	setprecision(const char *str, int *i, t_flags *flags)
{
	int	prcsn;
	int	check;

	prcsn = 0;
	check = 0;
	*i += 1;
	if (islegal(str, *i) == 2 || str[*i] == '-')
		flags->notwrite = 1;
	else
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			prcsn = (prcsn * 10) + (str[*i] - '0');
			*i += 1;
			check++;
		}
		if (check > 0 && prcsn == 0)
			flags->notwrite = 1;
	}
	*i -= 1;
	return (prcsn);
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

static void	setflagshelper(const char *str, int *i, va_list ap, t_flags *flags)
{
	if (str[*i] == '-')
		flags->minus = 1;
	else if (str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] == '0' && flags->zero == 0)
			flags->zero = 1;
		flags->mfw = setmfw(str, i);
		*i -= 1;
	}
	else if (str[*i] == '.')
	{
		flags->period = 1;
		flags->prcsn = setprecision(str, i, flags);
	}
	else if (str[*i] == '*')
	{
		if (flags->period == 0)
			flags->mfw = va_arg(ap, int);
		else if (flags->period == 1)
		{
			flags->prcsn = va_arg(ap, int);
			if (flags->prcsn == 0)
				flags->notwrite = 1;
		}
	}
}

t_flags	*setflags(const char *str, int *i, va_list ap, int *tormv)
{
	t_flags	*flags;
	int		tormvcpy;

	tormvcpy = *i;
	flags = ft_lstnew();
	if (!flags)
		return (NULL);
	resetflags(flags);
	while (islegal(str, *i) == 1)
	{
		setflagshelper(str, i, ap, flags);
		if (islegal(str, *i) == 1)
			*i += 1;
	}
	flags->ident = str[*i];
	if (flags->mfw < 0)
	{
		flags->minus = 1;
		flags->mfw = -flags->mfw;
	}
	if (flags->ident == 0)
		(*tormv)++;
	*tormv += *i - tormvcpy;
	return (flags);
}
