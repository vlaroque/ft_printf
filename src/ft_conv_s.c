/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:35:14 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/21 13:01:44 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_conv_s(char *lol, int *h, t_parsedata data, va_list *ap)
{
	char	*str;
	int		i;

	i = 0;
	str = (void *)va_arg(*ap, void *);
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}