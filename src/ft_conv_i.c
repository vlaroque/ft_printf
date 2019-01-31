/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:08:43 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 12:23:50 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdint.h>
#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"

static	intmax_t	getint(t_parsedata data, va_list *ap)
{
	intmax_t res;
	if (data.size == 0)
		res = (intmax_t)va_arg(*ap, int);
	else if (data.size == 1)
		res = (intmax_t)va_arg(*ap, int);
	else if (data.size == 2)
		res = (intmax_t)va_arg(*ap, int);
	else if (data.size == 3)
		res = (intmax_t)va_arg(*ap, long int);
	else if (data.size == 4)
		res = (intmax_t)va_arg(*ap, long long int);
	return (res);
}

static int	put_zeros(t_parsedata data, int len, int prefix)
{
	int res;

	if (data.precision > len)
		res = print_char_x_times('0', data.precision - len);
	else if ((data.flags & (1 << 2)) && !(data.flags & 1) && data.precision == -1)
		res = print_char_x_times('0', data.width - (prefix + len));
	return (res);
}

static int	put_spaces(int printedchars, t_parsedata data, int len, int prefix)
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

static char	what_a_sign(intmax_t nbr, t_parsedata data, int *prefixlen)
{
	*prefixlen = 1;
	if (nbr < 0)
		return ('-');
	else if (data.flags & (1 << 1))
		return ('+');
	else if (data.flags & (1 << 3))
		return (' ');
	*prefixlen = 0;
	return ('\0');
}

int			ft_conv_i(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	intmax_t	nbr;
	char		sign;
	int			prefix;
	int			len;
	int			printedchars;

	printedchars = 0;
	nbr = getint(data, ap);
	sign = what_a_sign(nbr, data, &prefix);
	len = mega_nbrlen_base(nbr, "0123456789");
	printedchars += put_spaces(printedchars, data, len, prefix);
	if (sign)
	{
		ft_putchar(sign);
		printedchars++;
	}
	printedchars += put_zeros(data, len, sign);
	mega_putnbr_base(nbr, "0123456789");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, prefix);
	return (printedchars);
}
