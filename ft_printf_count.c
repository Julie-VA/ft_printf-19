/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:46:21 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/04/26 16:52:56 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	countint(va_list ap, int *count, t_flags *flags)
{
	unsigned int	val;
	int				valcpy;
	int				sign;
	int				len;

	sign = 1;
	len = *count;
	valcpy = va_arg(ap, int);
	if (valcpy < 0)
	{
		(*count)++;
		valcpy *= -1;
		sign = -1;
	}
	if (valcpy == -2147483648)
		val = 2147483648;
	val = (unsigned int)valcpy;
	if (val == 0)
		(*count)++;
	while (val > 0)
	{
		val /= 10;
		(*count)++;
	}
	flags->valdi = valcpy * sign;
	return (*count - len);
}

int	countuint(va_list ap, int *count, t_flags *flags)
{
	unsigned int	val;
	unsigned int	valcpy;
	int				len;

	val = va_arg(ap, unsigned int);
	len = *count;
	valcpy = val;
	if (val == 0)
		*count = 1;
	while (val > 0)
	{
		val /= 10;
		(*count)++;
	}
	flags->valuxX = valcpy;
	return (*count - len);
}

int	scount(char *s, int *count, t_flags *flags)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (flags->mfw > 0 && flags->prcsn == 0)
		{
			flags->vals = "";
			return (0);
		}
		else
		{
			flags->vals = "(null)";
			*count += 6;
			flags->notwrite = 0;
			return (0);
		}
	}
	while (s[i])
		i++;
	if (flags->notwrite == 0)
		*count += i;
	flags->vals = s;
	return (i);
}
