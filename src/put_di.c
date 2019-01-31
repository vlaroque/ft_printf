/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:08:43 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 17:44:11 by vlaroque         ###   ########.fr       */
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
		res = (intmax_t)(char)va_arg(*ap, int);
	else if (data.size == 2)
		res = (intmax_t)(short int)va_arg(*ap, int);
	else if (data.size == 3)
		res = (intmax_t)va_arg(*ap, long int);
	else if (data.size == 4)
		res = (intmax_t)va_arg(*ap, long long int);
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

static int	is_prefix(char c)
{
	if (c == '\0')
		return (0);
	return (1);
}

int			put_di(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	intmax_t	nbr;
	uintmax_t	posinbr;
	char		sign;
	int			len;
	int			printedchars;

	printedchars = 0;
	nbr = getint(data, ap);
	sign = what_a_sign(nbr, data);
	posinbr = positive_me(nbr);
	len = mega_nbrlen_base_unsigned(nbr, "0123456789");
	printedchars += put_spaces(printedchars, data, len, is_prefix(sign));
	if (sign && printedchars++)
		ft_putchar(sign);
	printedchars += put_zeros(data, len, is_prefix(sign));
	mega_putnbr_base_unsigned(nbr, "0123456789");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, is_prefix(sign));
	return (printedchars);
}
