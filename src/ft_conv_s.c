/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:35:14 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/23 17:22:02 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_conv_s(char *lol, int *h, t_parsedata data, va_list *ap)
{
	char	*str;

	str = ft_strdup((void *)va_arg(*ap, void *));
	if (data.precision != -1 && data.precision < ft_strlen(str))
		str[data.precision] = '\0';
	return (ft_printer(str, 0, data));
}