/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:43:08 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 14:44:48 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdint.h>
#include	"ft_printf.h"

void	mega_putnbr_base(intmax_t nbr, char *base)
{
	int		basesize;

	basesize = ft_strlen(base);
	if (nbr < 0)
	{
		if (nbr <= -basesize)
			mega_putnbr_base(-(nbr / basesize), base);
		ft_putchar(base[-(nbr % basesize)]);
	}
	else if (nbr >= basesize)
	{
		mega_putnbr_base(nbr / basesize, base);
		ft_putchar(base[nbr % basesize]);
	}
	else
		ft_putchar(base[nbr % basesize]);
}

void	mega_putnbr_base_unsigned(uintmax_t nbr, char *base)
{
	int		basesize;

	basesize = ft_strlen(base);
	if (nbr >= basesize)
	{
		mega_putnbr_base_unsigned(nbr / basesize, base);
		ft_putchar(base[nbr % basesize]);
	}
	else
		ft_putchar(base[nbr % basesize]);
}