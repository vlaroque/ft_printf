/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/20 17:54:25 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include <math.h>
#include "ft_printf.h"

void	ft_putchar(char c);
int		ft_printf(char *str, ...);


int		main(int ac, char **av)
{
	int i;
	char	str[2];

	str[1] = '\0';
	i = 0;
	while (i < 128)
	{
		str[0] = i;
		ft_printf("%r\n", str);
		i++;
	}
	return (0);
}
