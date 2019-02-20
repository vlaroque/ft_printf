/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:50:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/20 17:23:10 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"

long double				puiss10(int exponent)
{
	long double res;

	if (exponent == 0)
		return (1.0);
	res = 1.0;
	while (exponent--)
		res *= 10.0;
	return (res);
}

static char				*interger_part(long double nbr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (nbr > 0.5)
	{
		nbr /= 10.0;
		i++;
	}

	while (j < i)
	{

		j++;
	}
}

static long double		get_float(t_parsedata data, va_list *ap)
{
	long double res;
	
	if (data.size == 0)
		res = (long double)va_arg(*ap, float);
	else if (data.size == 3)
		res = (long double)va_arg(*ap, double);
	else if (data.size == 5)
		res = (long double)va_arg(*ap, long double);
	return (res);
}

int				put_f(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	long double	nbr;
	
	data = flag_cleaner(data);
	nbr = get_float(data, ap);
}