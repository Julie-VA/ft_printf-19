/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:09:13 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/16 15:20:26 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	intflagscorner(t_flags *flags, int *len)
{
	if (flags->valdi < 0 && len > 0)
		(*len)--;
	if (flags->period == 1 && flags->prcsn == 0 && flags->valdi == 0)
	{
		flags->notwrite = 2;
		flags->minus = 0;
	}
	if (flags->prcsn > 0 && flags->mfw == 0)
		flags->minus = 0;
	if (flags->zero == 1 && flags->mfw > flags->prcsn
		&& flags->prcsn >= 0 && flags->period == 1)
		flags->zero = 0;
}

static int	intflagsminus(t_flags *flags, int len, int *count, int written)
{
	if (flags->mfw > 0 && flags->prcsn <= len)
	{
		ft_putnbr(flags->valdi, written);
		written = 1;
	}
	else if (flags->mfw > 0 && flags->prcsn > len)
	{
		if (flags->valdi < 0)
			write(1, "-", 1);
		while (len < flags->prcsn)
			len = intprintzero(len, count);
		written = 2;
		ft_putnbr(flags->valdi, written);
		written = 1;
	}
	intmfw(len, count, flags);
	return (written);
}

static int	intflagsnormal(t_flags *flags, int len, int *count, int written)
{
	if (flags->mfw > 0 && flags->zero == 1 && flags->prcsn <= len)
	{
		if (flags->valdi < 0)
		{
			write(1, "-", 1);
			len++;
		}
		written = 2;
		while (len < flags->mfw)
			len = intprintzero(len, count);
		ft_putnbr(flags->valdi, written);
	}
	else
	{
		if (flags->mfw > 0)
		{
			intmfw(len, count, flags);
		}
		if (flags->prcsn > 0 && written != 1)
		{
			written = intprcsn(len, flags, count);
		}
	}
	return (written);
}

int	intapplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = dgetlen(ap, flags, count);
	intflagscorner(flags, &len);
	if (flags->minus == 1)
		written = intflagsminus(flags, len, count, written);
	else if (flags->prcsn > 0 || flags->mfw > 0)
		written = intflagsnormal(flags, len, count, written);
	if (flags->valdi == 0 && flags->notwrite == 2 && flags->mfw == 0)
		(*count)--;
	return (written);
}
