/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:50:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/27 19:10:58 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_generic_int_fct.h"
#include "ft_magenbr.h"

int		integerbegin(char *str)
{
	int i;

	i = 0;
	while(str[i] == '0')
		i++;
	return (i);
}

int		put_f(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	long double	nbr;
	int			sign;
	char		*str;

	data = flag_cleaner(data);
	nbr = get_float(data, ap);
	sign = 1;
	if (nbr < +0.0)
		sign = -1;
	str = ft_ldbl_2_str(nbr);
	free(str);
}
