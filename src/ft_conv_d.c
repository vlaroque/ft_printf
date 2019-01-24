/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:25:28 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/24 21:28:38 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdlib.h>

static char	*ft_d_precision(char *src, int neg, int precision)
{
	int		src_len;
	int		i;
	char	*dest;
	char	*save;

	i = 0;
	src_len = ft_strlen(src);
	save = src;
	if (!(dest = (char *)malloc(sizeof(char) * (precision + neg + 1))))
		return (NULL);
	if (neg)
	{
		dest[i++] = '-';
		src++;
	}
	while (precision > i - neg + src_len - neg)
		dest[i++] = '0';
	while (*src)
		dest[i++] = *(src++);
	dest[i] = '\0';
	free(save);
	return (dest);
}

int		ft_conv_d(char *str, int *h, t_parsedata data, va_list *ap)
{
	char	*res_str;
	int		res_len;
	int		neg;

	res_str = ft_itoabase((int)va_arg(*ap, int), "0123456789");
	res_len = ft_strlen(res_str);
	neg = 0;
	if (res_str[0] == '-')
		neg = 1;
	if(res_len - neg < data.precision)
		res_str = ft_d_precision(res_str, neg, data.precision);
	return (ft_printer(res_str, 0, data));
}