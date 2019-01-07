/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:51:01 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/07 20:07:32 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_mini_atoi(const char *str, int *i)
{
	long long int	result;

	result = 0;
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		return (-1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		if (result > 2147483647)
			return (-42);
		i++;
	}
	return ((int)(result));
}

int		ft_flagparser(char *str, int *i, t_arguments *args)
{
	char	ok;

	ok = 1;
	args->flags = 0x00000000;
	while (ok)
	{
		if (str[*i] == '\0')
			return (0);
		else if(str[*i] == '-')
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
	return (1);
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
	if(!ft_flagparser(str, i, args))
		return(-1);
	//args->width = ft_mini_atoi(str, i);
	if(str[*i] == '.')
	{
		(*i)++;
		//args->precision = ft_mini_atoi(str, i);
		printf("loltest\n");
	}
	printf("\n\nargs : %d | width : %d | preci : %d\n\n", (int)(args->flags), args->width, args->precision);
	*i = 0;
	char tab[]= "123456789"; 
	printf("\n%d\n", ft_mini_atoi(tab, i));
	return (printchars);
}