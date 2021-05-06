/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:52:08 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/05 09:56:42 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	i = swritestr(str, ap);
	if (!i)
		return (-1);
	va_end(ap);
	return (i);
}

//written var : 0 = nothing written, 1 = everything written, 2 = only - written