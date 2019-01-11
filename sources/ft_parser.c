/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:51:01 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/11 16:15:35 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


unsigned char	size_parser(char *str, int *i)
{
	unsigned char	res;

	res = 0;
	if (str[*i] == '\0')
		return(-1);
	else if (str[*i] == 'h' && str[*i + 1] && str[*i + 1] == 'h')
		res = 1;
	else if (str[*i] == 'h')
		res = 2;
	else if (str[*i] == 'l' && str[*i + 1] && str[*i + 1] == 'l')
		res = 3;
	else if (str[*i] == 'l')
		res = 4;
	else if (str[*i] == 'L')
		res = 5;
	if (res == 0)
		return (0);
	else if (res == 1 || res == 3)
		(*i) = (*i) + 2;
	else
		(*i)++;
	return (res);
}

//-42 en cas de nombre supperieur a int max, -1 en cas de nombre negatif ou absence de nombre.

int			ft_mini_atoi(const char *str, int *i)
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
		(*i)++;
	}
	return ((int)(result));
}

int			ft_flagparser(char *str, int *i, t_arguments *args)
{
	char	ok;

	ok = 1;
	args->flags = 0x00;
	while (ok)
	{
		if (str[*i] == '\0')
			return (0);
		else if(str[*i] == '-')
			args->flags = (args->flags | 1);
		else if(str[*i] == '+')
			args->flags = (args->flags | (1 << 1));
		else if(str[*i] == '0')
			args->flags = (args->flags | (1 << 2));
		else if(str[*i] == ' ')
			args->flags = (args->flags | (1 << 3));
		else if(str[*i] == '#')
			args->flags = (args->flags | (1 << 4));
		else
			ok = 0;
		if (ok)
			(*i)++;
	}
	return (1);
}

/* -1 est une absence, -42 est une erreur */

int			ft_parser(char *str, int *i, t_arguments *args)
{
	if (str[*i] == '%')
	{
		ft_putchar('%');
		(*i)++;
		return(1);
	} 
	if(!ft_flagparser(str, i, args))
		return(-1);
	args->width = ft_mini_atoi(str, i);
	if(str[*i] == '.')
	{
		(*i)++;
		if((args->precision = ft_mini_atoi(str, i)) < 0)
			args->precision = -42;
	}
	else
		args->precision = -1;
	args->size = size_parser(str, i);
	
	
	
	printf("\nargs : %d | width : %d | preci : %d | size = %d | i = %d\n",
				(int)(args->flags), args->width, args->precision, args->size, *i);
	return (1);
}