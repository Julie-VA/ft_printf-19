/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_resetflags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:32:04 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/05/21 14:32:06 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resetflags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->period = 0;
	flags->mfw = 0;
	flags->prcsn = 0;
	flags->star = 0;
	flags->ident = 0;
	flags->valdi = 0;
	flags->valuxX = 0;
	flags->valp = 0;
	flags->vals = NULL;
	flags->notwrite = 0;
}
