/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:20:31 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/12 12:00:15 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	// char	str[] = "hello";
	// int		i = 1;
	// t_flags *flags;

	// printf("%d\n", ft_printf("%p\n%d\n%s\n%x\n%X\n%u\n\n", str, -85, str, 985, -985, UINT_MAX));
	// printf("%d\n", printf("%p\n%d\n%s\n%x\n%X\n%u\n\n", str, -85, str, 985, -985, UINT_MAX));
	// printf("%d\n", ft_printf("%u\n", UINT_MAX));
	// printf("%d\n", printf("%u\n", UINT_MAX));
	// printf("%d\n", printf("%.p\n", str));
	// printf("%d\n", ft_printf("%.p\n", str));
	// printf("%d\n", printf("%05d\n", 8));

	// printf("%d\n", ft_printf("Ma fonction écrit : |%*.*s|\n", -7, 1, "hello"));
	// printf("%d\n", printf("La fonction écrit : |%*.*s|\n", -7, 1, "hello"));
	// printf("%d\n", ft_printf("Ma fonction écrit : |%*.*s|\n", 7, 1, "hello"));
	// printf("%d\n", printf("La fonction écrit : |%*.*s|\n", 7, 1, "hello"));
	// printf("%d\n", ft_printf("Ma fonction écrit : |%*.*s|\n", -7, 0, "hello"));
	// printf("%d\n", printf("La fonction écrit : |%*.*s|\n", -7, 0, "hello"));
	// printf("%d\n", ft_printf("Ma fonction écrit : |%-0*.*s|\n", 7, 3, "hello"));
	// printf("%d\n", printf("La fonction écrit : |%-0*.*s|\n", 7, 3, "hello"));
	// printf("%d\n", ft_printf("Ma fonction écrit : |start-%.5s\t%s\t%.*s!|\n", "salutdnjsd", "ca va ?", 3, "wééééééééé"));
	// printf("%d\n", printf("La fonction écrit : |start-%.5s\t%s\t%.*s!|\n", "salutdnjsd", "ca va ?", 3, "wééééééééé"));
	// printf("%d\n", ft_printf("Ma fonction écrit : |%-0*.*s et %5s|\n", 7, 3, "hello", "ok"));
	// printf("%d\n", printf("La fonction écrit : |%-0*.*s et %5s|\n", 7, 3, "hello", "ok"));
	// printf("%d\n", ft_printf("Ma fonction écrit : |%*.*s|\n", 5, 1, "hello"));
	// printf("%d\n", printf("La fonction écrit : |%*.*s|\n", 5, 1, "hello"));
	// printf("%d\n", ft_printf("%-3.s", NULL));
	// printf("%d\n", printf("|%-5.3d|\n", 789));
	// printf("%d\n", ft_printf("%-*.82%\n", 5));
	// printf("%d\n", printf("%-*.82%\n", 5));
	printf("%d\n", ft_printf("|--0*%0*.0u*0 0*%0*.10u*0--|\n", -2, 0, 21, 1));
	printf("%d\n", printf("|--0*%0*.0u*0 0*%0*.10u*0--|\n", -2, 0, 21, 1));
	// printf("%d\n", ft_printf("%u\n", 5));
	// printf("%d\n", printf("%05u\n", 789));

	// c and s
	// printf("%d\n", printf("Syst printf writes : %c\n", 'e'));
	// printf("%d\n", ft_printf("My ftprintf writes : %c\n", 'e'));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %c\n", '\010'));
	// printf("%d\n", ft_printf("My ftprintf writes : %c\n", '\010'));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %s\n", "hello"));
	// printf("%d\n", ft_printf("My ftprintf writes : %s\n", "hello"));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %s\n", ""));
	// printf("%d\n", ft_printf("My ftprintf writes : %s\n", ""));
	// printf("\n");
	// //d, i and u
	// printf("%d\n", printf("Syst printf writes : %d\n", INT_MAX));
	// printf("%d\n", ft_printf("My ftprintf writes : %d\n", INT_MAX));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %d\n", INT_MIN));
	// printf("%d\n", ft_printf("My ftprintf writes : %d\n", INT_MIN));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %d\n", 0));
	// printf("%d\n", ft_printf("My ftprintf writes : %d\n", 0));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %i\n", INT_MAX));
	// printf("%d\n", ft_printf("My ftprintf writes : %i\n", INT_MAX));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %i\n", INT_MIN));
	// printf("%d\n", ft_printf("My ftprintf writes : %i\n", INT_MIN));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %i\n", 0));
	// printf("%d\n", ft_printf("My ftprintf writes : %i\n", 0));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %u\n", INT_MAX));
	// printf("%d\n", ft_printf("My ftprintf writes : %u\n", INT_MAX));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %u\n", INT_MIN));
	// printf("%d\n", ft_printf("My ftprintf writes : %u\n", INT_MIN));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %u\n", 0));
	// printf("%d\n", ft_printf("My ftprintf writes : %u\n", 0));
	// printf("\n");
	// //x and X
	// printf("%d\n", printf("Syst printf writes : %x\n", 28));
	// printf("%d\n", ft_printf("My ftprintf writes : %x\n", 28));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %x\n", INT_MAX));
	// printf("%d\n", ft_printf("My ftprintf writes : %x\n", INT_MAX));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %x\n", INT_MIN));
	// printf("%d\n", ft_printf("My ftprintf writes : %x\n", INT_MIN));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %X\n", 0));
	// printf("%d\n", ft_printf("My ftprintf writes : %X\n", 0));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %X\n", 28));
	// printf("%d\n", ft_printf("My ftprintf writes : %X\n", 28));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %X\n", INT_MAX));
	// printf("%d\n", ft_printf("My ftprintf writes : %X\n", INT_MAX));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %X\n", INT_MIN));
	// printf("%d\n", ft_printf("My ftprintf writes : %X\n", INT_MIN));
	// printf("\n");
	// printf("%d\n", printf("Syst printf writes : %X\n", 0));
	// printf("%d\n", ft_printf("My ftprintf writes : %X\n", 0));
	// printf("\n");
	// //p
	// printf("%d\n", printf("Syst printf writes : %p\n", str));
	// printf("%d\n", ft_printf("My ftprintf writes : %p\n", str));
	// printf("\n");

	// ft_printf("hello %u & %s & %i & %x\n", -1, "salut", 50, -28);
	// flags = setflags(str, &i);
	// printf("%d\n", flags->prcsn);
	// printf("%d\n", checklegal(str, flags, 1));
	// free(flags);
	return (0);
}


/*
NOTES :
si * = -5 -> flags->minus = 1

*/