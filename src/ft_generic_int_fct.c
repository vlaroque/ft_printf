/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_int_fct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:36:00 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 09:24:09 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdint.h>
#include	"ft_printf.h"

int		print_char_x_times(char c, int times)
{
	int res;

	res = times;
	if (times < 0)
		return (0);
	while(times--)
		ft_putchar(c);
	return (res);
}

int		mega_nbrlen_base(intmax_t nbr, char *base)
{
	int	i;
	int	basesize;

	i = 0;
	basesize = ft_strlen(base);
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= basesize;
	}
	return (i);
}

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