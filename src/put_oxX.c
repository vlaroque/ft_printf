/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:19:54 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/01 15:37:31 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdint.h>
#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"
#include	"getint.h"

int			put_o(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	uintmax_t	nbr;
	int			prefix;
	int			len;
	int			printedchars;

	printedchars = 0;
	data = flag_cleaner(data);
	nbr = getuint(data, ap);
	prefix = 0;
	if (data.flags & (1 << 4))
		prefix = 1;
	len = mega_nbrlen_base_unsigned(nbr, "01234567");
	printedchars += put_spaces(printedchars, data, len, prefix);
	if (prefix)
		printedchars += ft_putstrcmpt("0");
	printedchars += put_zeros(data, len, prefix);
	mega_putnbr_base_unsigned(nbr, "01234567");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, prefix);
	return (printedchars);
}

int			put_x(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	uintmax_t	nbr;
	int			prefix;
	int			len;
	int			printedchars;

	printedchars = 0;
	data = flag_cleaner(data);
	nbr = getuint(data, ap);
	prefix = 0;
	if (data.flags & (1 << 4))
		prefix = 2;
	len = mega_nbrlen_base_unsigned(nbr, "0123456789abcdef");
	printedchars += put_spaces(printedchars, data, len, prefix);
	if (prefix)
		printedchars += ft_putstrcmpt("0x");
	printedchars += put_zeros(data, len, prefix);
	mega_putnbr_base_unsigned(nbr, "0123456789abcdef");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, prefix);
	return (printedchars);
}

int			put_X(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	uintmax_t	nbr;
	int			prefix;
	int			len;
	int			printedchars;

	printedchars = 0;
	data = flag_cleaner(data);
	nbr = getuint(data, ap);
	prefix = 0;
	if (data.flags & (1 << 4))
		prefix = 2;
	len = mega_nbrlen_base_unsigned(nbr, "0123456789ABCDEF");
	printedchars += put_spaces(printedchars, data, len, prefix);
	if (prefix)
		printedchars += ft_putstrcmpt("0X");
	printedchars += put_zeros(data, len, prefix);
	mega_putnbr_base_unsigned(nbr, "0123456789ABCDEF");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, prefix);
	return (printedchars);
}