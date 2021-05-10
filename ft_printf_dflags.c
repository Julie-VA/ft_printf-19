/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:09:13 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/09 17:09:13 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

static int	printzero(int len, int *count)
{
	write(1, "0", 1);
	len++;
	*count += 1;
	return (len);
}

static int	sprcsn(int len, t_flags *flags, int *count)
{
	int	written;

	written = 0;
	if (flags->valdi < 0 && flags->prcsn > len)
	{
		write(1, "-", 1);
		written = 2;
		len--;
	}
	while (len < flags->prcsn)
		len = printzero(len, count);
	ft_putnbr(flags->valdi, written);
	return (1);
}

static void	smfw(int len, int *count, t_flags *flags)
{
	while (len < flags->mfw)
	{
		write(1, " ", 1);
		len++;
		*count += 1;
	}
}

int	dapplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = dgetlen(ap, flags, count);
	if (flags->minus == 1)
	{
		if (written == 0 && flags->mfw > 0 && flags->mfw > flags->prcsn)
		{
			ft_putnbr(flags->valdi, written);
			written = 1;
		}
		else if (flags->prcsn > 0)
			flags->minus = 0;
		smfw(len, count, flags);
	}
	else if (flags->prcsn > 0 || flags->mfw > 0)
	{
		if (flags->mfw > 0 && flags->zero == 1 && flags->mfw > flags->prcsn)
		{
			if (flags->valdi < 0)
				write(1, "-", 1);
			while (len < flags->mfw)
				len = printzero(len, count);
			written = 2;
			ft_putnbr(flags->valdi, written);
		}
		else if (flags->mfw > 0 && flags->mfw > flags->prcsn)
			smfw(len, count, flags);
		else if (flags->prcsn > 0 && written == 0)
			written = sprcsn(len, flags, count);
	}
	return (written);
}
