/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xXflags_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:50:17 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 09:54:29 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xprintzero(int len, int *count)
{
	write(1, "0", 1);
	len++;
	(*count)++;
	return (len);
}

int	xprcsn(int len, t_flags *flags, int *count)
{
	int	written;

	written = 0;
	if (flags->valuxX < 0 && flags->prcsn > len)
	{
		write(1, "-", 1);
		written = 2;
	}
	while (len < flags->prcsn)
		len = xprintzero(len, count);
	ft_putstr(flags->resultxX);
	return (1);
}

void	xmfw(int len, int *count, t_flags *flags)
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
		write(1, " ", 1);
}
