/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:48:53 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/11 17:34:59 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_conversions.h"
#include "../includes/ft_printf.h"

int ft_percent(t_arguments *args)
{
	ft_putchar('%');
	return (1);
}

int ft_putc(t_arguments *args)
{
	printf("mettre un char\n");
	return (1);
}

int test(t_arguments args)
{
	ft_putchar('Z');
	return (0);
}

int		ft_conversions(char *str, int *i, t_arguments *args)
{
	int	j;
	int (*f)(t_arguments);

	j = 0;
	while (str[*i] != type_tab[j].typechar)
	{
		if (type_tab[j].typechar == '\0')
			return (-1);
		j++;
	}
	j--;
	f = type_tab[j].ptr_on_ft;
	return (f(*args));
}