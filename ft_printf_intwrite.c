/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_intwrite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:06:16 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/05 11:24:15 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	writeident(t_flags *flags)
{
	if (flags->ident == 'd' || flags->ident == 'i')
		ft_putnbr(flags->valdi, 0);
	else if (flags->ident == 'u')
		ft_uputnbr(flags->valuxX, 0);
	else if (flags->ident == 'x')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'X')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'p')
		ft_putstr(flags->resultp);
}

void	intwrite(t_flags *flags, va_list ap, int *count)
{
	if (intapplyflags(ap, flags, count) == 0 && flags->notwrite < 2)
		writeident(flags);
}

void	uwrite(t_flags *flags, va_list ap, int *count)
{
	if (uapplyflags(ap, flags, count) == 0 && flags->notwrite < 2)
		writeident(flags);
}

void	xwrite(t_flags *flags, va_list ap, int *count)
{
	if (xapplyflags(ap, flags, count) == 0 && flags->notwrite < 2)
		writeident(flags);
}

void	powrite(t_flags *flags, va_list ap, int *count)
{
	int	check;

	check = 0;
	if (papplyflags(ap, flags, count, &check) == 0)
	{
		if (check == 0)
			write(1, "0x", 2);
		if (flags->notwrite < 2)
			writeident(flags);
	}
}
