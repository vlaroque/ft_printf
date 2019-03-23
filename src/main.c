/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/23 20:08:37 by vlaroque         ###   ########.fr       */
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
	float t = 20.24;
	int code1 = ft_printf("|%0 20.2f|\n", t);
	int code2 = printf("|%0 20.2f|\n", t);
	printf("1 = %i, 2 = %i\n", code1, code2);
	ft_printf("|%Lf|\n", LDBL_MAX);
	return (0);
}


/*
	int code1 = ft_printf("[%+010.2f]\n", f);
	int code2 = printf("[%+010.2f]\n", f);


	int code1 = ft_printf("[%+010.2f]\n", f);
	int code2 = printf("[%+010.2f]\n", f);

	int code1 = ft_printf("[%.2s]\n", t);
	int code2 = printf("[%.2s]\n", t);
*/