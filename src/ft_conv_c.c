/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:22:56 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/23 17:19:54 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_conv_c(char *str, int *h, t_parsedata data, va_list *ap)
{
	char *res_str;

	res_str = ft_strdup("@");
	res_str[0] = (char)va_arg(*ap, void *);
	return (ft_printer(res_str, 0, data));
}