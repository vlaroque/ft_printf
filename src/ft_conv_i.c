/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:08:43 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 10:57:58 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdint.h>
#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"

static int	put_zeros(t_parsedata data, int len, char sign)
{
	int res;
	int signlen;

	signlen = 1;
	if (sign == '\0')
		signlen = 0;
	if (data.precision > len)
		res = print_char_x_times('0', data.precision - len);
	else if ((data.flags & (1 << 2)) && !(data.flags & 1) && data.precision == -1)
		res = print_char_x_times('0', data.width - (signlen + len));
	return (res);
}

static int	put_spaces(int printedchars, t_parsedata data, int len, char sign)
{
	int		signlen;
	int		res;

	signlen = 1;
	res = 0;
	if (sign == '\0')
		signlen = 0;
	//if (data.flags & (1 << 2))
	//	return (0);
	//printf("lol\n");
	if (printedchars == 0 && data.width > (len + signlen) && !(data.flags & 1)
				&& !(data.flags & (1 << 2)))
	{
		if (data.precision > len)
			res = print_char_x_times(' ', data.width - (data.precision + signlen));
		else
			res = print_char_x_times(' ', data.width - (len + signlen));
	}
	else if (printedchars != 0 && data.width > (len + signlen) && (data.flags & 1))
	{
		if (data.precision > len)
			res = print_char_x_times(' ', data.width - (data.precision + signlen));
		else
			res = print_char_x_times(' ', data.width - (len + signlen));
	}
	return (res);
}

static char	what_a_sign(intmax_t nbr, t_parsedata data)
{
	if (nbr < 0)
		return ('-');
	else if (data.flags & (1 << 1))
		return ('+');
	else if (data.flags & (1 << 3))
		return (' ');
	return ('\0');
}

int			ft_conv_i(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	intmax_t	nbr;
	char		sign;
	int			len;
	int			printedchars;

	printedchars = 0;
	//ajouter la fonction qui gere les difft sizes
	nbr = va_arg(*ap, int);
	sign = what_a_sign(nbr, data);
	len = mega_nbrlen_base(nbr, "0123456789");
	printedchars += put_spaces(printedchars, data, len, sign);
	if (sign)
	{
		ft_putchar(sign);
		printedchars++;
	}
	printedchars += put_zeros(data, len, sign);
	mega_putnbr_base(nbr, "0123456789");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, sign);
	return (printedchars);
}
