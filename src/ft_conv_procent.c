/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_procent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:25:06 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/23 17:28:35 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_conv_procent(char *str, int *h, t_parsedata data, va_list *ap)
{
	char *res_str;

	res_str = ft_strdup("%");
	return (ft_printer(res_str, 0, data));
}