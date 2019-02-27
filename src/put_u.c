/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:41:47 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/27 18:09:52 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdint.h>
#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"
#include	"getdata_varg.h"

int			put_u(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	uintmax_t	nbr;
	int			len;
	int			printedchars;

	printedchars = 0;
	data = flag_cleaner(data);
	nbr = getuint(data, ap);
	len = mega_nbrlen_base_unsigned(nbr, "0123456789");
	printedchars += put_spaces(printedchars, data, len, 0);
	printedchars += put_zeros(data, len, 0);
	mega_putnbr_base_unsigned(nbr, "0123456789");
	printedchars += len;
	printedchars += put_spaces(printedchars, data, len, 0);
	return (printedchars);
}