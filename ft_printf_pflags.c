/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 09:57:40 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 09:21:27 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	pflagscorner(t_flags *flags)
{
	if (flags->valp == 0 && flags->period == 1
		&& flags->prcsn == 0 && flags->mfw < 3)
		return (1);
	if (flags->period == 1 && flags->prcsn == 0 && flags->valp == 0)
		flags->notwrite = 2;
	if (flags->prcsn > 0 && flags->mfw == 0)
		flags->minus = 0;
	if (flags->zero == 1 && flags->mfw > flags->prcsn && flags->period == 1)
		flags->zero = 0;
	return (0);
}

static int	pflagsminus(t_flags *flags, int len, int *count, int *check)
{
	int	written;

	written = 0;
	write(1, "0x", 2);
	*check = 1;
	if (flags->mfw > 0 && flags->prcsn <= len && flags->notwrite < 2)
	{
		ft_putstr(flags->resultp);
		written = 1;
	}
	else if (flags->mfw > 0 && flags->prcsn > len)
	{
		len -= 2;
		while (len < flags->prcsn)
			len = pprintzero(len, count);
		ft_putstr(flags->resultp);
		written = 1;
	}
	pmfw(len, count, flags);
	return (written);
}

static int	pflagsnormal(t_flags *flags, int len, int *count, int *check)
{
	int	written;

	written = 0;
	if (flags->mfw > 0 && flags->zero == 1 && flags->prcsn <= len)
	{
		write(1, "0x", 2);
		*check = 1;
		while (len < flags->mfw)
			len = pprintzero(len, count);
		ft_putstr(flags->resultp);
		written = 1;
	}
	else
	{
		if (flags->mfw > 0)
			pmfw(len, count, flags);
		write(1, "0x", 2);
		*check = 1;
		if (flags->prcsn > 0 && written != 1)
			written = pprcsn(len, flags, count);
	}
	return (written);
}

int	papplyflags(va_list ap, t_flags *flags, int *count, int *check)
{
	int	written;
	int	len;

	written = 0;
	len = dgetlen(ap, flags, count);
	if (pflagscorner(flags) == 1)
		return (1);
	if (flags->minus == 1)
		written = pflagsminus(flags, len, count, check);
	else if (flags->prcsn > 0 || flags->mfw > 0)
		written = pflagsnormal(flags, len, count, check);
	if (flags->valp == 0 && flags->notwrite == 2 && flags->mfw == 0)
		*count += 2;
	return (written);
}
