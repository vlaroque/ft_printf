/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:54:08 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/21 18:45:32 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_rintxtime(char c, int x)
{
	while(x)
	{
		ft_putchar(c);
		x--;
	}
	return(0);
}

int		ft_printer(char *res_str, char isnbr, t_parsedata data)
{
	int		negnbr;
	int		i;
	int		res_strlen;
	int		printedchars;

	i = 0;
	printedchars = 0;
	negnbr = 0;
	if (isnbr && res_str[0] == '-')
		negnbr = 1;
	res_strlen = (int)ft_strlen(res_str);
	//impression des espaces avant la str
	if(data.width > res_strlen)
	{
		while (data.width > res_strlen + printedchars)
		putchar(' ');
		printedchars++;
	}
	if(negnbr)
	{
		ft_putchar('-');
		printedchars++;
	}
	//signe
	//impression de la str sur la sorite standart
	printedchars += ft_putstrcmpt(res_str);
	//impression des espaces apres la str
}