/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 09:26:55 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	dgetlen(va_list ap, t_flags *flags, int *count)
{
	int	len;

	len = *count;
	if (flags->ident == 'c')
		(*count)++;
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_flags	*ft_lstnew(void)
{
	t_flags	*new;

	new = (t_flags *)malloc(sizeof(t_flags));
	if (!new)
		return (NULL);
	return (new);
}
