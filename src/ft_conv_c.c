/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:22:56 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/18 10:19:25 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_conv_c(char *str, int *h, t_parsedata data, va_list *ap)
{
	char c;

	c = (char)va_arg(*ap, void *);
	ft_putchar(c);
	return (1);
}