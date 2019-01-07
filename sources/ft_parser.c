/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:51:01 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/07 18:53:14 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flagparser(char *str, int *i, t_arguments *args)
{
	char	ok;

	ok = 1;
	args->flags = 0x00000000;
	while (ok && str[*i])
	{
		if(str[*i] == '-')
			args->flags = (args->flags | 0x01);
		else if(str[*i] == '+')
			args->flags = (args->flags | 0x02);
		else if(str[*i] == '0')
			args->flags = (args->flags | 0x04);
		else if(str[*i] == ' ')
			args->flags = (args->flags | 0x08);
		else if(str[*i] == '#')
			args->flags = (args->flags | 0x10);
		else
			ok = 0;
		(*i)++;
	}
	return (0);
}

/* -1 est une absence, -42 est une erreur */

int		ft_parser(char *str, int *i, t_arguments *args)
{
	int		printchars;

	printchars = 0;
	(*i)++;
	if (str[*i] == '%')
	{
		ft_putchar('%');
		(*i)++;
		return(1);
	} 
	flagparser(str, i, args);
	args->width = ft_mini_atoi(str, i);

	printf("args : %d", (int)(args->flags));
	return (printchars);
}