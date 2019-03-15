/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:08:43 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/15 19:28:25 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdint.h>
#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"
#include	"getdata_varg.h"

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
	data = flag_cleaner(data);
	nbr = getint(data, ap);
	sign = what_a_sign(nbr, data);
	posinbr = positive_me(nbr);
	if (posinbr == 0 && (data.precision == 0 || data.precision == -42))
		return(zero(data));
	len = mega_nbrlen_base_unsigned(posinbr, "0123456789");
	printedchars += put_spaces(printedchars, data, len, is_prefix(sign));
	if (sign && (printedchars++ || 1))
		ft_putchar(sign);
	printedchars += put_zeros(data, len, is_prefix(sign));
	mega_putnbr_base_unsigned(posinbr, "0123456789");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, is_prefix(sign));
	return (printedchars);
}
