/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbrs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:46:27 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/19 10:14:53 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbrneg(int written)
{
	if (written == 2)
		write(1, "2147483648", 10);
	else
		write(1, "-2147483648", 11);
}

void	ft_putnbr(int nb, int written)
{
	if (nb == -2147483648)
		ft_putnbrneg(written);
	else
	{
		if (nb < 0)
		{
			if (written != 2)
				ft_putchar('-');
			nb = nb * (-1);
			ft_putnbr(nb, written);
		}
		else if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			ft_putnbr(nb / 10, written);
			ft_putchar((nb % 10) + '0');
		}
	}
}

void	ft_uputnbr(unsigned int nb, int written)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10, written);
		ft_putchar((nb % 10) + '0');
	}
}
