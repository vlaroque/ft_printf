/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:04:47 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/24 11:57:21 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parsing.h"

int		ft_conversion(char *str, int *h, va_list *ap)
{
	t_parsedata		data;
	int				(*f)(char *str, int *h, t_parsedata data, va_list *ap);

	(*h)++;
	data.flags = ft_flagparser(str, h);
	data.width = -1;
	if (ft_isdigit(str[*h]))
		data.width = mini_atoi(str, h);
	data.precision = -1;
	if (str[*h] == '.')
	{
		data.precision = -42;
		if (ft_isdigit(str[++(*h)]))
			data.precision = mini_atoi(str, h);
	}
	data.size = ft_typeparser(str, h);
	if (!(f = ft_char_to_func(str, h)))
		return (0);
	return ((f)(str, h, data, ap));
}

//dans le cas present f est la fonction ft_conv_s