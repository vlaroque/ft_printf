/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:08:43 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/25 16:33:57 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdlib.h>

typedef struct s_nbr_data	t_nbr_data;
struct		s_nbr_data
{
	int		neg;
	char	sign;
	int		nbr_len;
};

static char	ft_whatasign(t_parsedata data, va_list ap, t_nbr_data *nbr_data)
{
	if (nbr_data->neg)
		nbr_data->sign = '-';
	else if ()
}

static int	ft_char_cmpt(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_mini_itoabase(int value, char *basechars, int *neg)
{
	char	buff[70];
	char	*ptr;
	int		base;

	*neg = 0;
	base = ft_char_cmpt(basechars);
	ptr = &buff[69];
	*(ptr) = '\0';
	if (value < 0)
	{
		*(--ptr) = basechars[-(value % base)];
		value = -(value / base);
		*neg = 1;
	}
	while (value)
	{
		*(--ptr) = basechars[value % base];
		value = value / base;
	}
	return (ft_strdup(ptr));
}

int		ft_conv_i(char *str, int *h, t_parsedata data, va_list *ap)
{
	char		*res_str;
	t_nbr_data	nbr_data;

	res_str = ft_mini_itoabase((int)va_arg(*ap, int), "0123456789", &(nbr_data.neg));
	nbr_data.nbr_len = ft_strlen(res_str);
	
	return (ft_printer(res_str, 0, data));
}