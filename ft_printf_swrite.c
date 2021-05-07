/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_swrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:55:09 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/07 10:41:49 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	getlen(va_list ap, t_flags *flags, int *count)
{
	int	len;

	len = *count;
	scount(va_arg(ap, char *), count, flags);
	return (*count - len);
}

// static int	applyflags(va_list ap, t_flags *flags, int *count, int *i)
// {
// 	int	len;
// 	(void)*i;

// 	len = getlen(ap, flags, count);
// 	// if (flags->prcsn > 0)
// 	// {
// 	// 	flags->written = applyprcsn(flags, &len, count);
// 	// 	if (flags->written == 1)
// 	// 		*i += 1;
// 	// }
// 	if (flags->mfw > 0)
// 	{
// 		flags->written = sapplyflags(flags, len, count, i);
// 		// if (flags->written == 1)
// 		// 	*i += 1;
// 	}
// 	return (flags->written);
// }

// int	swriteident(int i, t_flags *flags)
// {
// 	ft_putstr(flags->vals);
// }

// static void	printflags(t_flags *flags)
// {
// 	printf("\n");
// 	printf("minus : %d\n", flags->minus);
// 	printf("zero : %d\n", flags->zero);
// 	printf("period : %d\n", flags->period);
// 	printf("mfw : %d\n", flags->mfw);
// 	printf("prcsn : %d\n", flags->prcsn);
// 	printf("ident : %c\n", flags->ident);
// 	printf("valdi : %d\n", flags->valdi);
// 	printf("valuxX : %d\n", flags->valuxX);
// 	printf("valp : %llu\n", flags->valp);
// 	printf("vals : %s\n", flags->vals);
// 	printf("resultxX : %s\n", flags->resultxX);
// 	printf("resultp : %s\n", flags->resultp);
// 	printf("notwrite : %d\n", flags->notwrite);
// 	printf("\n");
// }

int	swritestr(const char *str, va_list ap)
{
	int		i;
	t_flags	*flags;
	int		count;
	int		prcnts;
	int		tormv;

	i = 0;
	count = 0;
	prcnts = 0;
	tormv = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			prcnts++;
			flags = set_sflags(str, &i, ap, &tormv);
			// printflags(flags);
			if (sapplyflags(ap, flags, &count, &i) == 0 && flags->notwrite == 0)
			{
				ft_putstr(flags->vals);
				i++;
			}
			free(flags);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i + count - (prcnts * 2) - tormv);
}
