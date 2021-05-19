/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uflags_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:39:19 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 09:43:59 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uprintzero(int len, int *count)
{
	write(1, "0", 1);
	len++;
	(*count)++;
	return (len);
}

int	uprcsn(int len, t_flags *flags, int *count)
{
	int	written;

	written = 0;
	while (len < flags->prcsn)
		len = uprintzero(len, count);
	ft_uputnbr(flags->valuxX, written);
	return (1);
}

static int	adjustlen(t_flags *flags, int *len, int *count)
{
	int	check;

	check = 0;
	if (*len < flags->prcsn)
		*len += flags->prcsn - *len;
	else if (flags->valuxX == 0 && flags->prcsn == 0 && flags->period == 1)
	{
		*len = 0;
		(*count)--;
		check++;
	}
	return (check);
}

void	umfw(int len, int *count, t_flags *flags)
{
	int	check;

	check = adjustlen(flags, &len, count);
	if (flags->valuxX == 0 && flags->prcsn > 0)
	{
		len = flags->mfw - flags->prcsn;
		while (len > 0)
		{
			write(1, " ", 1);
			len--;
			(*count)++;
		}
	}
	else
	{
		while (len < flags->mfw)
		{
			write(1, " ", 1);
			len++;
			(*count)++;
		}
	}
	if (check == 1 && flags->minus == 1)
		(*count)++;
}
