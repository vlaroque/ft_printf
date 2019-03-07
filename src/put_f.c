/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:50:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/07 18:54:19 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_generic_int_fct.h"
#include "ft_meganbr.h"
#include "getdata_varg.h"

int		round_check(char *str, int i)
{
	i++;
	if (str[i] - '0' < 5)
		return (0);
	else if (str[i] - '0' == 5)
	{
		i++;
		while(str[i] == '0' && i < 21499)
		{
			i++;
		}
		if (str[i] - '0' != 0)
			return (1);
	}
	else if (str[i] - '0' > 5)
		return (1);
	return (0);

}
int		pre_len(int precision)
{
	int len;

	len = 0;
	if (precision == -42 || precision == 0)
		len = 0;
	else if(precision == -1)
		len = 7;
	else
		len = precision + 1;
	return (len);
}

int		rounding(t_parsedata data, char *str)
{
	int i;
	int carry;
	int tmp;
	
	carry = 1;
	i = -1;
	if (pre_len(data.precision) == 0 && round_check(str, 4949))
		i = 4949;
	else if (data.precision > 0 && round_check(str, 4949 + data.precision))
		i = 4949 + data.precision;
	while (carry)
	{
		tmp = (str[i] + carry - '0');
		str[i] = tmp % 10 + '0';
		carry = tmp / 10;
		i++;
	}
	return (1);
}


int		print_spaces_or_zeros(t_parsedata data, int intlen, int state, int neg)
{
	int i;
	int prelen;

	prelen = pre_len(data.precision);
	i = 0;
	if (state == 0 && data.width > intlen + prelen + neg && data.flags & (1 << 2))
	{
		while(i++ < data.width - (intlen + prelen + neg))
			ft_putchar('0');
	}
	else if (state == 2 && data.width > intlen + prelen + neg
		&& !(data.flags & (1 << 2)) && data.flags & 1)
	{
		while(i++ < data.width - (intlen + prelen + neg))
			ft_putchar(' ');
	}
	else if (state == 1 && data.width > intlen + prelen + neg
		&& !(data.flags & (1 << 2)) && !(data.flags & 1))
	{
		while(i++ < data.width - (intlen + prelen + neg))
			ft_putchar(' ');
	}
		return (i);
}

int		int_len(char *str)
{
	int i;

	i = 0;
	while(str[i] == '0')
		i++;
	if (i == 0)
		return (1);
	if (i < 4949)
		return (4950 - i);
	return (1);
}

int		printsign(t_parsedata data, int neg)
{
	if (neg == 1)
	{
		ft_putchar('-');
		return (1);
	}
	else if (data.flags & (1 << 1))
	{
		ft_putchar('+');
		return (1);
	}
	else if (data.flags & (1 << 3))
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

int		print_intpart(int len, char *str, t_parsedata data)
{
	int i;

	i = 4950 - len;
	while (i < 4949)
	{
		ft_putchar(str[i]);
		i++;
	}
		ft_putchar(str[i]);
	return(len);
}

int		print_precision(t_parsedata data, char *str)
{
	int		i;
	int		printed;
	int		prelen;

	printed = 0;
	i = 0;
	prelen = pre_len(data.precision);
	if (prelen)
	{
		ft_putchar('.');
		while(i++ < prelen - 1)
			ft_putchar(str[i + 4949]);
	}
	return (prelen);
}

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

int		put_f(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	long double	nbr;
	int			neg;
	char		*str;
	int			printed;
	int			intlen;

	printed = 0;
	data = flag_cleaner(data);
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
