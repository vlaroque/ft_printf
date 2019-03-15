/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:43:08 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/15 20:34:30 by vlaroque         ###   ########.fr       */
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

uintmax_t		ft_pow(uintmax_t nbr, uintmax_t pwr)
{
	uintmax_t res;

	res = 1;
	while (pwr > 0)
	{
		res = res * nbr;
		pwr--;
	}
	return (res);
}

int		put_unbr(uintmax_t nbr, int quote)
{
	int len;
	int i;
	uintmax_t denom;
	uintmax_t save;

	save = nbr;
	len = 0;
	while (nbr && ++len)
		nbr /= 10;
	i = len;
	denom = ft_pow(10, len - 1);
	while(denom)
	{
		putchar(((save / denom) % 10) + '0');
		if (quote && i % 3 == 1 && denom > 10 && ++len)
			putchar (',');
		denom /= 10;
		i--;
	}
	return (len);
}