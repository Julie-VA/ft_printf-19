/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xXflags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:52:10 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 09:51:01 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	xflagscorner(t_flags *flags, int *len)
{
	if (flags->valuxX < 0 && len > 0)
		len--;
	if (flags->period == 1 && flags->prcsn == 0 && flags->valuxX == 0)
	{
		flags->minus = 0;
		flags->notwrite = 2;
	}
	if (flags->prcsn > 0 && flags->mfw == 0)
		flags->minus = 0;
	if (flags->zero == 1 && flags->mfw > flags->prcsn
		&& flags->prcsn >= 0 && flags->period == 1)
		flags->zero = 0;
}

static int	xflagsminus(t_flags *flags, int len, int *count, int written)
{
	if (flags->mfw > 0 && flags->prcsn <= len)
	{
		ft_putstr(flags->resultxX);
		written = 1;
	}
	else if (flags->mfw > 0 && flags->prcsn > len)
	{
		while (len < flags->prcsn)
			len = xprintzero(len, count);
		ft_putstr(flags->resultxX);
		written = 1;
	}
	xmfw(len, count, flags);
	return (written);
}

static int	xflagsnormal(t_flags *flags, int len, int *count, int written)
{
	if (flags->mfw > 0 && flags->zero == 1 && flags->prcsn <= len)
	{
		while (len < flags->mfw)
			len = xprintzero(len, count);
		ft_putstr(flags->resultxX);
		written = 1;
	}
	else
	{
		if (flags->mfw > 0)
			xmfw(len, count, flags);
		if (flags->prcsn > 0 && written != 1)
			written = xprcsn(len, flags, count);
	}
	return (written);
}

int	xapplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = dgetlen(ap, flags, count);
	xflagscorner(flags, &len);
	if (flags->minus == 1)
		written = xflagsminus(flags, len, count, written);
	else if (flags->prcsn > 0 || flags->mfw > 0)
		written = xflagsnormal(flags, len, count, written);
	if (flags->valuxX == 0 && flags->notwrite == 2 && flags->mfw == 0)
		(*count)--;
	return (written);
}
