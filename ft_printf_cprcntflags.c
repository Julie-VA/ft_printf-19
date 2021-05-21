/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cprcntflags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:51:59 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/21 14:50:25 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	writechar(va_list ap, t_flags *flags)
{
	if (flags->ident == 'c')
		ft_putchar(va_arg(ap, int));
	else
		ft_putchar(flags->ident);
	return (1);
}

static int	printzerononvalid(t_flags *flags, int *count)
{
	int	i;

	i = 0;
	if (flags->minus == 0)
	{
		while (i < flags->mfw - 1)
		{
			write(1, "0", 1);
			i++;
			(*count)++;
		}
		ft_putchar(flags->ident);
		return (1);
	}
	return (0);
}

int	capplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int	len;

	written = 0;
	len = 1;
	if (flags->mfw > 0)
	{
		if (flags->zero == 1 && (flags->ident != 2 || flags->ident != 3))
			written = printzerononvalid(flags, count);
		if (flags->minus == 1 && written == 0)
			written = writechar(ap, flags) + 1;
		while (len < flags->mfw && written != 1)
		{
			write(1, " ", 1);
			len++;
			(*count)++;
		}
		if (written == 0)
			written = writechar(ap, flags);
	}
	return (written);
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
		{
			ft_putchar('%');
			while (len < flags->mfw)
			{
				write(1, " ", 1);
				len++;
				(*count)++;
			}
			written = 1;
		}
		else
			written = prcntflagsnormal(flags, len, count);
	}
	return (written);
}
