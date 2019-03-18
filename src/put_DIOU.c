/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_DIOU.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:19:52 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/18 15:59:13 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_D(t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_di(data, ap));
}

int		put_I(t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_di(data, ap));
}

int		put_O(t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_o(data, ap));
}

int		put_U(t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_u(data, ap));
}

int		put_F(t_parsedata data, va_list *ap)
{
	data.size = 6;
	return (put_f(data, ap));
}