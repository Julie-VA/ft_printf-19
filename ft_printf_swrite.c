/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_swrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:55:09 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/11 17:25:14 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

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
