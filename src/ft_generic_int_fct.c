/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_int_fct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:36:00 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/01 15:14:49 by vlaroque         ###   ########.fr       */
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

int		mega_nbrlen_base_unsigned(uintmax_t nbr, char *base)
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

uintmax_t	positive_me(intmax_t nbr)
{
	uintmax_t	res;
	
	if (nbr == INTMAX_MIN)
		res = ((uintmax_t)INTMAX_MAX) + 1;
	else if (nbr < 0)
		res = (uintmax_t)(-nbr);
	else
		res = (uintmax_t)(nbr);
	return (res);
}

int		put_zeros(t_parsedata data, int len, int prefix)
{
	int res;
//	printf ("pre = %d , len = %d\n", data.precision, len);
	res = 0;
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

t_parsedata	flag_cleaner(t_parsedata data)
{
	if ((data.flags & (1 << 2)) && (data.flags & 1))
		data.flags -= (1 << 2);
	if (data.flags & (1 << 2) && (data.precision >= 0 || data.precision == -42))
		data.flags -= (1 << 2);
	return (data);
}