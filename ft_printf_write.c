/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:08:58 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/11 17:08:58 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

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

static void	startwrite(va_list ap, t_flags *flags, int *count)
{
	// if (flags->ident == 'c')
	// 	dosomething;
	if (flags->ident == 's')
		swrite(flags, ap, count);
	else if (flags->ident == 'd' || flags->ident == 'i')
		dwrite(flags, ap, count);
	else if (flags->ident == 'u')
		uwrite(flags, ap, count);
	else if (flags->ident == 'x' || flags->ident == 'X')
		xwrite(flags, ap, count);
	else if (flags->ident == 'p')
		powrite(flags, ap, count);
}

int	writestr(const char *str, va_list ap)
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
			if (flags->ident != '%')
			{
				// printflags(flags);
				startwrite(ap, flags, &count);
			}
			else
			{
				write(1, "%", 1);
				count++;
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
