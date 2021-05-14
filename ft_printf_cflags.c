/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:51:59 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/14 15:44:42 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	capplyflags(va_list ap, t_flags *flags, int *count)
{
	int	written;
	int len;

	written = 0;
	len = 1;
	if (flags->mfw > 0)
	{
		if (flags->minus == 1)
		{
			if (flags->ident == '%')
				ft_putchar('%');
			else
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
			if (flags->ident == '%')
				ft_putchar('%');
			else
				ft_putchar(va_arg(ap, int));
			written = 1;
		}
	}
	return (written);
}
