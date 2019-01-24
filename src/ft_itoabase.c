/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:47:38 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/24 21:32:40 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_char_cmpt(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_itoabase(int value, char *basechars)
{
	char	buff[70];
	char	*ptr;
	int		base;
	int		neg;

	base = ft_char_cmpt(basechars);
	ptr = &buff[69];
	neg = 0;
	*(ptr) = '\0';
	if (value < 0)
	{
		*(--ptr) = basechars[-(value % base)];
		value = -(value / base);
		neg = 1;
	}
	while (value)
	{
		*(--ptr) = basechars[value % base];
		value = value / base;
	}
	if(neg)
		*(--ptr) = '-';
	return (ft_strdup(ptr));
}