/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:04:47 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/08 06:14:55 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parsing.h"
#include "getdata_varg.h"

static int	bonus_star(t_parsedata data, va_list *ap, int *h)
{
	(*h)++;
	return (next_int(ap));
}

int			ft_conversion(char *str, int *h, va_list *ap)
{
	t_parsedata		data;
	int				(*f)(char *str, int *h, t_parsedata data, va_list *ap);

	(*h)++;
	data.flags = ft_flagparser(str, h);
	data.width = -1;
	if (ft_isdigit(str[*h]))
		data.width = mini_atoi(str, h);
	else if (str[*h] == '*')
		data.width = bonus_star(data, ap, h);
	data.precision = -1;
	if (str[*h] == '.')
	{
		data.precision = -42;
		if (ft_isdigit(str[++(*h)]))
			data.precision = mini_atoi(str, h);
		else if (str[*h] == '*')
			data.precision = bonus_star(data, ap, h);
	}
	data.size = ft_typeparser(str, h);
	if (!(f = ft_char_to_func(str, h)))
		return (0);
	return ((f)(str, h, data, ap));
}
