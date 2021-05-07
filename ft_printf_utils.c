/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:21:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/07 10:15:55 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putstrp(char *str)
{
	int i;

	i = 0;
	write(1, "0x", 2);
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
	new->minus = 0;
	new->zero = 0;
	new->period = 0;
	new->mfw = 0;
	new->ident = 0;
	return (new);
}
