/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_applyprcsn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:09:01 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/04/30 16:42:54 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	applyprcsn(t_flags *flags, int *len, int *count)
{
	int	written;
	int	i;

	written = 0;
	if (flags->ident == 's')
	{
		i = 0;
		while (i < flags->prcsn && flags->vals[i])
		{
			write(1, &flags->vals[i], 1);
			i++;
		}
		if (i < *len)
			*count += -(*len) + i;
		written = 1;
	}
	else
	{
		if ((flags->ident  == 'd' || flags->ident  == 'i') && flags->valdi < 0)
		{
			write(1, "-", 1);
			written = 2;
		}
		if (flags->written == 2)
		{
			*len -= 1;
			while (*len < flags->prcsn)
			{
				write(1, "0", 1);
				*len += 1;
				*count += 1;
			}
			*len += 1;
		}
	}
	return (written);
}