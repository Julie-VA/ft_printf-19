/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_countxX.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:08:49 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/12 17:37:14 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	temp;

	temp = 0;
	i = 0;
	while (size != 0 && i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[(size - 1) - i];
		tab[(size - 1) - i] = temp;
		i++;
	}
}

char	convhex(int mod, int cap)
{
	if (mod <= 9 && mod >= 0)
		return (mod + '0');
	else if (cap == 0)
		return (mod - 10 + 'a');
	else
		return (mod - 10 + 'A');
}

static int	convnwrite(unsigned int nb, char *result, int cap, t_flags *flags)
{
	int	i;
	int	mod;

	i = 0;
	while (nb > 0)
	{
		mod = nb % 16;
		result[i++] = convhex(mod, cap);
		nb = nb / 16;
	}
	result[i] = '\0';
	i = ft_strlen(result);
	ft_rev_int_tab(result, i);
	i = 0;
	while (i < 9)
	{
		flags->resultxX[i] = result[i];
		i++;
	}
	return (ft_strlen(result));
}

void	countnputnbrhex(va_list ap, int cap, int *count, t_flags *flags)
{
	char	result[9];
	int		nb;

	nb = va_arg(ap, int);
	flags->valuxX = (unsigned int)nb;
	if (nb == 0)
	{
		flags->resultxX[0] = '0';
		flags->resultxX[1] = '\0';
		(*count)++;
		return ;
	}
	*count += convnwrite((unsigned int)nb, result, cap, flags);
}
