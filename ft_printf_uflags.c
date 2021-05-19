/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:46:41 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/16 15:20:39 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uflagsminus(t_flags *flags, int len, int *count, int written)
{
	if (flags->mfw > 0 && flags->prcsn <= len)
	{
		ft_uputnbr(flags->valuxX, written);
		written = 1;
	}
	else if (flags->mfw > 0 || flags->prcsn > len)
	{
		while (len < flags->prcsn)
			len = uprintzero(len, count);
		written = 2;
		ft_uputnbr(flags->valuxX, written);
		written = 1;
	}
	if (flags->period == 0 && flags->prcsn <= 0 && flags->mfw >= flags->prcsn)
		umfw(len, count, flags);
	else if (flags->period == 1 && flags->mfw > flags->prcsn)
		umfw(len, count, flags);
	return (written);
}

static int	uflagsnormal(t_flags *flags, int len, int *count, int written)
{
	if (flags->mfw > 0 && flags->zero == 1 && flags->prcsn <= len)
	{
		written = 2;
		while (len < flags->mfw)
			len = uprintzero(len, count);
		ft_uputnbr(flags->valuxX, written);
	}
	else
	{
		if (flags->mfw > 0)
			umfw(len, count, flags);
		if (flags->prcsn > 0 && written != 1)
			written = uprcsn(len, flags, count);
	}
	return (written);
}

int	uapplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = dgetlen(ap, flags, count);
	if (flags->period == 1 && flags->prcsn == 0 && flags->valuxX == 0)
	{
		flags->notwrite = 2;
		flags->minus = 0;
	}
	if (flags->zero == 1 && flags->mfw > flags->prcsn
		&& flags->prcsn >= 0 && flags->period == 1)
		flags->zero = 0;
	if (flags->minus == 1)
		written = uflagsminus(flags, len, count, written);
	else if (flags->prcsn > 0 || flags->mfw > 0)
		written = uflagsnormal(flags, len, count, written);
	if (flags->valuxX == 0 && flags->notwrite == 2 && flags->mfw == 0)
		(*count)--;
	return (written);
}
