/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:50:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/20 16:01:49 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_f.h"
#include "ft_generic_int_fct.h"
#include "ft_meganbr.h"
#include "getdata_varg.h"
#include "ft_writings.h"

int		ft_ldbl_is_neg(long double nbr)
{
	unsigned int *nbrmask;

	nbrmask = (unsigned int *)&nbr;
	if (nbrmask[2] & 32768)
		return (1);
	else
		return (0);
}

int		put_f_specials(long double nbr, t_parsedata *data, char *str, int *neg)
{
	if (nbr != nbr)
	{
		(*data).precision = -42;
		if ((*data).flags & (1 << 2))
			(*data).flags = (*data).flags - (1 << 2);
		str[4949 - 2] = 'n';
		str[4949 - 1] = 'a';
		str[4949] = 'n';
		*neg = 0;
		return (3);
	}
	if (nbr == 1.0 / 0.0 || nbr == -1.0 / 0.0)
	{
		(*data).precision = -42;
		if ((*data).flags & (1 << 2))
			(*data).flags = (*data).flags - (1 << 2);
		str[4949 - 2] = 'i';
		str[4949 - 1] = 'n';
		str[4949] = 'f';
		return (3);
	}
	return (0);
}

int		ft_is_special(long double nbr, t_parsedata *data, char **str, int *neg)
{
	int		intlen;

	if (nbr != nbr || nbr == 1.0 / 0.0 || nbr == -1.0 / 0.0)
	{
		if (!(*str = malloc(sizeof(t_ullong) * MEGALEN)))
			return (0);
		intlen = put_f_specials(nbr, data, *str, neg);
	}
	else
	{
		*str = ft_ldbl_2_str(nbr);
		intlen = int_len(*str);
		rounding(*data, *str);
	}
	return (intlen);
}

int		put_f(t_parsedata data, va_list *ap)
{
	long double	nbr;
	int			neg;
	char		*str;
	int			printed;
	int			intlen;

	printed = 0;
	data = flag_cleaner(data);
	if (data.precision == -1)
		data.precision = 6;
	nbr = get_float(data, ap);
	neg = ft_ldbl_is_neg(nbr);
	intlen = ft_is_special(nbr, &data, &str, &neg);
	printed += print_spaces_or_zeros(data, intlen, 1, neg);
	printed += printsign(data, neg);
	printed += print_spaces_or_zeros(data, intlen, 0, neg);
	printed += print_intpart(intlen, str, data);
	printed += print_precision(data, str);
	printed += print_spaces_or_zeros(data, intlen, 2, neg);
	free(str);
	return (printed);
}
