/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cswrite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:55:09 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/21 14:13:59 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sgetlen(va_list ap, t_flags *flags, int *count)
{
	int	len;

	len = *count;
	scount(va_arg(ap, char *), count, flags);
	return (*count - len);
}

void	swrite(t_flags *flags, va_list ap, int *count)
{
	if (sapplyflags(ap, flags, count) == 0 && flags->notwrite == 0)
		ft_putstr(flags->vals);
}

int	cwrite(t_flags *flags, va_list ap, int *count)
{
	if (capplyflags(ap, flags, count) == 0)
	{
		if (flags->ident == 'c')
			ft_putchar(va_arg(ap, int));
		else
			ft_putchar(flags->ident);
	}
	(*count)++;
	return (1);
}

void	prcntwrite(t_flags *flags, int *count)
{
	if (prcntapplyflags(flags, count) == 0)
		ft_putchar('%');
	(*count)++;
}
