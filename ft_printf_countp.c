/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_countp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:34:01 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/17 15:16:29 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	lluconvnwrite(LLU nb, char *result, int *count, t_flags *flags)
{
	int	i;
	int	mod;

	i = 0;
	while (nb > 0)
	{
		mod = nb % 16;
		result[i++] = convhex(mod, 0);
		nb = nb / 16;
		(*count)++;
	}
	result[i] = '\0';
	i = ft_strlen(result);
	ft_rev_int_tab(result, i);
	i = 0;
	while (i < 16)
	{
		flags->resultp[i] = result[i];
		i++;
	}
}

void	countnputnbrlluhex(va_list ap, int *count, t_flags *flags)
{
	char	result[16];
	LLU		nb;

	*count += 2;
	nb = (LLU)(va_arg(ap, void *));
	flags->valp = (LLU)nb;
	if (nb == 0 && flags->period == 1 && flags->prcsn == 0 && flags->mfw < 3)
	{
		write(1, "0x", 2);
		return ;
	}
	if (nb == 0)
	{
		flags->resultp[0] = '0';
		flags->resultp[1] = '\0';
		(*count)++;
		return ;
	}
	lluconvnwrite(nb, result, count, flags);
}
