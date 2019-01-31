/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_int_fct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:36:00 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 13:16:33 by vlaroque         ###   ########.fr       */
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


int		put_zeros(t_parsedata data, int len, int prefix)
{
	int res;

	if (data.precision > len)
		res = print_char_x_times('0', data.precision - len);
	else if ((data.flags & (1 << 2)) && !(data.flags & 1) && data.precision == -1)
		res = print_char_x_times('0', data.width - (prefix + len));
	return (res);
}

int		put_spaces(int printedchars, t_parsedata data, int len, int prefix)
{
	int		res;

	res = 0;
	if (printedchars == 0 && data.width > (len + prefix) && !(data.flags & 1)
				&& !(data.flags & (1 << 2)))
	{
		if (data.precision > len)
			res = print_char_x_times(' ', data.width - (data.precision + prefix));
		else
			res = print_char_x_times(' ', data.width - (len + prefix));
	}
	else if (printedchars != 0 && data.width > (len + prefix) && (data.flags & 1))
	{
		if (data.precision > len)
			res = print_char_x_times(' ', data.width - (data.precision + prefix));
		else
			res = print_char_x_times(' ', data.width - (len + prefix));
	}
	return (res);
}