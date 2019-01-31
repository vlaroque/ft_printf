/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:19:54 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 15:22:51 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdint.h>
#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"

static	uintmax_t	getint(t_parsedata data, va_list *ap)
{
	uintmax_t res;
	
	if (data.size == 0)
		res = (uintmax_t)va_arg(*ap, int);
	else if (data.size == 1)
		res = (uintmax_t)(unsigned char)va_arg(*ap, int);
	else if (data.size == 2)
		res = (uintmax_t)(unsigned short int)va_arg(*ap, int);
	else if (data.size == 3)
		res = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (data.size == 4)
		res = (uintmax_t)va_arg(*ap, unsigned long long int);
	return (res);
}

int			put_o(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	uintmax_t	nbr;
	int			len;
	int			printedchars;

	printedchars = 0;
	nbr = getint(data, ap);
	len = mega_nbrlen_base(nbr, "0123456789");
	printedchars += put_spaces(printedchars, data, len, 0);
	printedchars += put_zeros(data, len, 0);
	mega_putnbr_base_unsigned(nbr, "0123456789");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, 0);
	return (printedchars);
}

int			put_o(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	uintmax_t	nbr;
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
	printedchars += put_zeros(data, len, prefix);
	mega_putnbr_base(nbr, "0123456789");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, prefix);
	return (printedchars);
}