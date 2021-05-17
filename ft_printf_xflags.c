/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:52:10 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/17 10:34:11 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

static int	printzero(int len, int *count)
{
	write(1, "0", 1);
	len++;
	(*count)++;
	return (len);
}

static int	dprcsn(int len, t_flags *flags, int *count)
{
	int	written;

	written = 0;
	if (flags->valuxX < 0 && flags->prcsn > len)
	{
		write(1, "-", 1);
		written = 2;
	}
	while (len < flags->prcsn)
		len = printzero(len, count);
	ft_putstr(flags->resultxX);
	return (1);
}

static void	dmfw(int len, int *count, t_flags *flags)
{
	if (flags->prcsn >= len)
		len = flags->prcsn;
	while (len < flags->mfw)
	{
		write(1, " ", 1);
		len++;
		(*count)++;
	}
	if (flags->period == 1 && flags->prcsn == 0 && flags->valuxX == 0)
	{
		write(1, " ", 1);
	}
}

int	xapplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = dgetlen(ap, flags, count);
	if (flags->valuxX < 0 && len > 0)
		len--;
	if (flags->period == 1 && flags->prcsn == 0 && flags->valuxX == 0)
	{
		flags->minus = 0;
		flags->notwrite = 2;
	}
	if (flags->prcsn > 0 && flags->mfw == 0)
		flags->minus = 0;
	if (flags->zero == 1 && flags->mfw > flags->prcsn && flags->prcsn >= 0 && flags->period == 1)
		flags->zero = 0;
	if (flags->minus == 1)
	{
		if (flags->mfw > 0 && flags->prcsn <= len)
		{
			ft_putstr(flags->resultxX);
			written = 1;
		}
		else if (flags->mfw > 0 && flags->prcsn > len)
		{
			while (len < flags->prcsn)
				len = printzero(len, count);
			ft_putstr(flags->resultxX);
			written = 1;
		}
		dmfw(len, count, flags);
	}
	else if (flags->prcsn > 0 || flags->mfw > 0)
	{
		if (flags->mfw > 0 && flags->zero == 1 && flags->prcsn <= len)
		{
			while (len < flags->mfw)
				len = printzero(len, count);
			ft_putstr(flags->resultxX);
			written = 1;
		}
		else
		{
			if (flags->mfw > 0)
			{
				dmfw(len, count, flags);
			}
			if (flags->prcsn > 0 && written != 1)
			{
				written = dprcsn(len, flags, count);
			}
		}
	}
	if (flags->valuxX == 0 && flags->notwrite == 2 && flags->mfw == 0)
		(*count)--;
	return (written);
}
