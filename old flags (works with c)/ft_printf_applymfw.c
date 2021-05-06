/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_applymfw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:02:33 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/04/30 16:33:57 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	modwriteident(va_list ap, t_flags *flags, int written)
{
	if (flags->ident == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (flags->ident == 's')
		ft_putstr(flags->vals);
	else if (flags->ident == 'd' || flags->ident == 'i')
		ft_putnbr(flags->valdi, written);
	else if (flags->ident == 'u')
		ft_uputnbr(flags->valuxX);
	else if (flags->ident == 'x')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'X')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'p')
		ft_putstrp(flags->resultp);
}

int	applymfw(va_list ap, t_flags *flags, int len, int *count)
{
	int	written;

	written = 0;
	if (flags->minus == 1 || flags->star == 1)
	{
		modwriteident(ap, flags, 0);
		while (len < flags->mfw)
		{
			write(1, " ", 1);
			len++;
			*count += 1;
		}
		written = 1;
	}
	else if (flags->zero == 1)
	{
		if ((flags->ident  == 'd' || flags->ident  == 'i') && flags->valdi < 0)
		{
			write(1, "-", 1);
			written = 2;
		}
		while (len < flags->mfw)
		{
			write(1, "0", 1);
			len++;
			*count += 1;
		}
	}
	else
	{
		while (len < flags->mfw)
		{
			write(1, " ", 1);
			len++;
			*count += 1;
		}
	}
	return (written);
}