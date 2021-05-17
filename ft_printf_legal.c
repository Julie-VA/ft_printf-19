/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_legal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:39:08 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/17 15:23:54 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	islegal(const char *s, int i)
{
	if ((s[i] >= 48 && s[i] <= 57) || s[i] == 45 || s[i] == '.' || s[i] == '*')
		return (1);
	if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
		return (2);
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == '%')
		return (2);
	return (0);
}

int	charislegal(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '.' || c == '*')
		return (1);
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (2);
	if (c == 'c' || c == 's' || c == 'p' || c == '%')
		return (2);
	return (0);
}
