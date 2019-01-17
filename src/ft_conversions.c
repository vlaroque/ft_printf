/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:04:47 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/17 21:39:50 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parsing.h"

int		ft_conversion(char *str, int *h, va_list *ap)
{
	char		c;
	t_parsedata	data;

	(*h)++;
	data.flags = ft_flagparser(str, h);
	data.width = -1;
	if (ft_isdigit(str[*h]))
		data.width = mini_atoi(str, h);
	data.precision = -1;
	if (str[*h] == '.')
		if (ft_isdigit(str[++(*h)]))
			data.precision = mini_atoi(str, h);
	data.size = ft_typeparser(str, h);
	return (0);
}