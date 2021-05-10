/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:06:16 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/05 11:24:15 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	dgetlen(va_list ap, t_flags *flags, int *count)
{
	int	len;

	len = *count;
	if (flags->ident == 'c')
		*count += 1;
	else if (flags->ident == 'd' || flags->ident == 'i')
		countint(ap, count, flags);
	else if (flags->ident == 'u')
		countuint(ap, count, flags);
	else if (flags->ident == 'x')
		countnputnbrhex(ap, 0, count, flags);
	else if (flags->ident == 'X')
		countnputnbrhex(ap, 1, count, flags);
	else if (flags->ident == 'p')
		countnputnbrlluhex(ap, count, flags);
	return (*count - len);
}

static void	writeident(va_list ap, t_flags *flags)
{
	if (flags->ident == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (flags->ident == 'd' || flags->ident == 'i')
		ft_putnbr(flags->valdi, 0);
	else if (flags->ident == 'u')
		ft_uputnbr(flags->valuxX);
	else if (flags->ident == 'x')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'X')
		ft_putstr(flags->resultxX);
	else if (flags->ident == 'p')
		ft_putstrp(flags->resultp);
}

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

int	dwritestr(const char *str, va_list ap)
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
			flags = setflags(str, &i, ap, &tormv);
			// printflags(flags);
			if (dapplyflags(ap, flags, &count) == 0 && flags->notwrite < 2)
			{
				// printflags(flags);
				writeident(ap, flags);
			}
			i--;
			while (str[i] != flags->ident)
				i++;
			i++;
			free(flags);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	// printf("i=%d", i);
	// printf("count=%d", count);
	// printf("prcnts=%d", prcnts);
	// printf("tormv=%d", tormv);
	return (i + count - (prcnts * 2) - tormv);
}
