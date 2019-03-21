/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/21 16:59:38 by vlaroque         ###   ########.fr       */
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
	long double f;

	f = 2.123456789;
	ft_printf("%.7Lf\n\n", f);
	printf("%.7Lf\n", f);
	return (0);
}
