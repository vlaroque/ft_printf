/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:55:55 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/07 17:56:06 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_arguments	args;
	int			i;
	//int			j;

	i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%')
			parser(str, &i, &args);
		else
			ft_putchar(str[i++]);
	}
	va_end(ap);
	return (0);
}
