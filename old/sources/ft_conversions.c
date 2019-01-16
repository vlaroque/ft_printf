/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:48:53 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/13 19:02:22 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_conversions.h"
#include "../includes/ft_printf.h"

int test(t_arguments args)
{
	(void)args;
	ft_putchar('~');
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
	f = type_tab[j].ptr_on_ft;
	(*i)++;
	return (f(*args));
}