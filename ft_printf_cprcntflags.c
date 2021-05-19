/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cprcntflags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:51:59 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 09:57:13 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	capplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = 1;
	if (flags->mfw > 0)
	{
		if (flags->minus == 1)
		{
			ft_putchar(va_arg(ap, int));
			written = 1;
		}
		while (len < flags->mfw)
		{
			write(1, " ", 1);
			len++;
			(*count)++;
		}
		if (written == 0)
		{
			ft_putchar(va_arg(ap, int));
			written = 1;
		}
	}
	return (written);
}

static int	prcntflagsminus(t_flags *flags, int len, int *count)
{
	ft_putchar('%');
	while (len < flags->mfw)
	{
		write(1, " ", 1);
		len++;
		(*count)++;
	}
	return (1);
}

static int	prcntflagsnormal(t_flags *flags, int len, int *count)
{
	if (flags->zero == 1)
	{
		while (len < flags->mfw)
		{
			write(1, "0", 1);
			len++;
			(*count)++;
		}
	}
	while (len < flags->mfw)
	{
		write(1, " ", 1);
		len++;
		(*count)++;
	}
	ft_putchar('%');
	return (1);
}

int	prcntapplyflags(t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = 1;
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->mfw > 0)
	{
		if (flags->minus == 1)
			written = prcntflagsminus(flags, len, count);
		else
			written = prcntflagsnormal(flags, len, count);
	}
	return (written);
}
