/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_legal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:39:08 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/14 15:55:27 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	islegal(const char *s, int i)
{
	if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '.' || s[i] == '*')
		return (1);
	if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
		return (2);
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == '%')
		return (2);
	return (0);
}

int	compatibility(t_flags *flags)
{
	if (flags->zero == 1 && (flags->ident == 'p' || flags->ident == 'c'))
		return (0);
	if (flags->period == 1 && (flags->ident == 'p' || flags->ident == 'c'))
		return (0);
	if (flags->minus == 1 && flags->zero == 1)
		return (0);
	return (1);
}

int	writenotlegal(const char *str, int i, int *count)
{
	write(1, "%", 1);
	while (islegal(str, i) < 2)
	{
		write(1, &str[i], 1);
		i++;
		*count += 1;
	}
	write(1, &str[i], 1);
	return (++i);
}

static int	isperiod(const char *str, int i, int *check)
{
	if (*check == 1)
		return (0);
	if (str[i] == '.')
	{
		if (str[i + 1] == '.' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i + 1] == '*')
			return (0);
		i++;
	}
	*check = 1;
	return (i);
}

int	checklegal(const char *str, t_flags *flags, int i)
{
	int	check;

	check = 0;
	if (flags->zero == 1 && islegal(str, i) < 2)
		return (0);
	if (!compatibility(flags))
		return (0);
	if (!islegal(str, i))
		return (0);
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '0' && str[i + 1] == '*')
			return (0);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i + 1] == '*')
			return (0);
		i++;
	}
	if (str[i] == '.')
		i = isperiod(str, i, &check);
	if (str[i] == '*')
	{
		if (str[i + 1] == '.')
		{
			i++;
			i = isperiod(str, i, &check);
			if (!i)
				return (0);
		}
		if (islegal(str, i + 1) == 1)
			return (0);
	}
	if (!islegal(str, i))
		return (0);
	return (1);
}
