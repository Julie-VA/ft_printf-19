/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:15:43 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/17 11:46:51 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

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
			(*count)++;
		}
		else
		{
			write(1, " ", 1);
			i++;
			(*count)++;
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
	len = sgetlen(ap, flags, count);
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
