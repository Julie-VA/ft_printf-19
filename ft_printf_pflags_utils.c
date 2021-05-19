/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pflags_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:21:11 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 09:23:19 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	pprintzero(int len, int *count)
{
	write(1, "0", 1);
	len++;
	(*count)++;
	return (len);
}

int	pprcsn(int len, t_flags *flags, int *count)
{
	int	written;

	written = 0;
	len -= 2;
	if (flags->valp < 0 && flags->prcsn > len)
	{
		write(1, "-", 1);
		written = 2;
	}
	while (len < flags->prcsn)
		len = pprintzero(len, count);
	ft_putstr(flags->resultp);
	return (1);
}

void	pmfw(int len, int *count, t_flags *flags)
{
	if (flags->prcsn >= len)
		len = flags->prcsn + 2;
	while (len < flags->mfw)
	{
		write(1, " ", 1);
		len++;
		(*count)++;
	}
	if (flags->period == 1 && flags->prcsn == 0 && flags->valp == 0)
		write(1, " ", 1);
}
