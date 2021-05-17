/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_intflags_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:28:42 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/17 17:36:15 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intprintzero(int len, int *count)
{
	write(1, "0", 1);
	len++;
	(*count)++;
	return (len);
}

int	intprcsn(int len, t_flags *flags, int *count)
{
	int	written;

	written = 0;
	if (flags->valdi < 0 && flags->prcsn > len)
	{
		write(1, "-", 1);
		written = 2;
	}
	while (len < flags->prcsn)
		len = intprintzero(len, count);
	ft_putnbr(flags->valdi, written);
	return (1);
}

void	intmfw(int len, int *count, t_flags *flags)
{
	if (flags->prcsn >= len)
		len = flags->prcsn;
	if (flags->valdi < 0)
		len++;
	while (len < flags->mfw)
	{
		write(1, " ", 1);
		len++;
		(*count)++;
	}
	if (flags->notwrite == 2)
	{
		write(1, " ", 1);
	}
}
