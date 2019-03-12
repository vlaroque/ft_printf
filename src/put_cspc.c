/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cspc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:56:27 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/12 14:22:58 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"ft_generic_int_fct.h"
#include	<unistd.h>

static int	put_spaces_csppc(t_parsedata data, int len,int printedchars, char end)
{
	int	res;

	res = 0;
	if(data.width > len + printedchars && !(data.flags & 1))
	{
		while (data.width > len + printedchars + res)
		{
			ft_putchar(' ');
			res++;
		}
	}
	else if(data.width > len + printedchars && (data.flags & 1) && end)
	{
		while (data.width > printedchars + res)
		{
			ft_putchar(' ');
			res++;
		}
	}
	return (res);
}

int			put_pc(char *lol, int *h, t_parsedata data, va_list *ap)
{
	int		printedchars;
	int		len;

	printedchars = 0;
	len = 1;
	printedchars += put_spaces_csppc(data, len, printedchars, 0);
	printedchars += ft_putstrcmpt("%");
	printedchars += put_spaces_csppc(data, len, printedchars, 1);
	return (printedchars);
}

int			put_s(char *lol, int *h, t_parsedata data, va_list *ap)
{
	char	*str;
	int		printedchars;
	int		len;

	printedchars = 0;
	str = ft_strdup((char *)va_arg(*ap, void *));
	if (str)
	{
		if (data.precision >= 0 && data.precision < ft_strlen(str))
			str[data.precision] = '\0';
		len = ft_strlen(str);
	}
	else
		len = 6;
	printedchars += put_spaces_csppc(data, len, printedchars, 0);
	if (str)
		printedchars += ft_putstrcmpt(str);
	else
		printedchars += ft_putstrcmpt("(null)");
	printedchars += put_spaces_csppc(data, len, printedchars, 1);
	free(str);
	return (printedchars);
}

int			put_c(char *lol, int *h, t_parsedata data, va_list *ap)
{
	char	c;
	char	str[2];
	int		printedchars;
	int		len;

	printedchars = 0;
	c = (char)va_arg(*ap, int);
	if(c)
	{
		str[0] = c;
		str[1] = '\0';
	}
		len = 1;
	printedchars += put_spaces_csppc(data, len, printedchars, 0);
	if (c)
		printedchars += ft_putstrcmpt(str);
	else
	{
		printedchars += 1;
		ft_putchar('\0');
	}
	printedchars += put_spaces_csppc(data, len, printedchars, 1);
	return (printedchars);
}
