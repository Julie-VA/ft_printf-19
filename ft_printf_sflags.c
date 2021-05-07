/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:15:43 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/07 15:25:22 by rvan-aud         ###   ########.fr       */
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
	flags->notwrite = 0;
}

static void	smfw(int len, int *count, t_flags *flags)
{
	int	i;

	i = len;
	if (flags->period && flags->prcsn < len && flags->prcsn >= 0)
		i -= len - flags->prcsn;
	while (i < flags->mfw)
	{
		if (flags->zero == 1 && flags->minus == 0)
		{
			write(1, "0", 1);
			i++;
			*count += 1;
		}
		else
		{
			write(1, " ", 1);
			i++;
			*count += 1;
		}
	}
}

static int	sprcsn(int len, t_flags *flags, int *count)
{
	int	written;
	int	i;

	written = 0;
	i = 0;
	while (i < flags->prcsn && flags->vals[i])
	{
		write(1, &flags->vals[i], 1);
		i++;
		written = 1;
	}
	if (i < len)
		*count -= len - i;
	return (written);
}

int	sapplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = getlen(ap, flags, count);
	if (flags->prcsn <= 0 && flags->notwrite == 1)
		flags->minus = 0;
	if (flags->minus == 1)
	{
		if (flags->prcsn > 0)
		{
			sprcsn(len, flags, count);
			written = 1;
		}
		if (written == 0)
			ft_putstr(flags->vals);
		written = 1;
		smfw(len, count, flags);
	}
	if (flags->prcsn >= 0 || flags->mfw > 0)
	{
		if (flags->mfw > 0 && flags->minus == 0)
			smfw(len, count, flags);
		if (flags->prcsn > 0 && flags->notwrite == 0 && written == 0)
			written = sprcsn(len, flags, count);
	}
	return (written);
}

static int	setprecision(const char *str, int *i, t_flags *flags)
{
	int	prcsn;
	int	check;

	prcsn = 0;
	check = 0;
	*i += 1;
	if (islegal(str, *i) == 3 || str[*i] == '-')
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

t_flags	*set_sflags(const char *str, int *i, va_list ap, int *tormv)
{
	t_flags	*flags;
	int		tormvcpy;

	tormvcpy = *i;
	flags = ft_lstnew();
	resetflags(flags);
	while (islegal(str, *i) < 2)
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
		if (islegal(str, *i) < 2)
			*i += 1;
	}
	flags->ident = str[*i];
	if (flags->mfw < 0)
	{
		flags->minus = 1;
		flags->mfw = -flags->mfw;
	}
	*tormv += *i - tormvcpy;
	return (flags);
}
