/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:52:05 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/12 11:55:33 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_color.h"

int		ft_chckclr(char *str, char *color, int colorlen, int *h)
{
	int		i;

	i = 0;
	while (str[i] == color[i] && i < colorlen - 1)
		i++;
	if (i == colorlen - 1)
	{
		*h += colorlen;
		return(1);
	}
	return (0);
}

int		ft_colortxt(char *str, int *h, va_list *ap)
{
	if (ft_chckclr(&str[*h], "{red}", 5, h))
		write(1, "\033[31m", 5);
	else if (ft_chckclr(&str[*h], "{green}", 7, h))
		write(1, "\033[32m", 5);
	else if (ft_chckclr(&str[*h], "{yellow}", 8, h))
		write(1, "\033[33m", 5);
	else if (ft_chckclr(&str[*h], "{blue}", 6, h))
		write(1, "\033[34m", 5);
	else if (ft_chckclr(&str[*h], "{pink}", 6, h))
		write(1, "\033[35m", 5);
	else if (ft_chckclr(&str[*h], "{cyan}", 6, h))
		write(1, "\033[36m", 5);
	else if (ft_chckclr(&str[*h], "{grey}", 6, h))
		write(1, "\033[37m", 5);
	else if (ft_chckclr(&str[*h], "{eoc}", 5, h))
	{	
		write(1, "\033[0m", 4);
		return (4);
	}
	else
	{
		write(1, &str[*h], 1);
		*h = *h + 1;
		return (1);
	}
	return (5);
}