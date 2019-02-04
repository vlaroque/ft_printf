/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:54:08 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/04 17:36:46 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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
	if(data.width > res_strlen + printedchars && !(data.flags & 1))
	{
		while (data.width > res_strlen + printedchars)
		{
			ft_putchar(' ');
			printedchars++;
		}
	}
	if(negnbr)
	{
		ft_putchar('-');
		printedchars++;
	}
	//signe
	//impression de la str sur la sortie standart (gestion de la precision se fait dans les fonctions specifiques)
	printedchars += ft_putstrcmpt(res_str);
	//impression des espaces apres la str
	if(data.width > res_strlen + printedchars && (data.flags & 1))
	{
		while (data.width >  printedchars)
		{
			ft_putchar(' ');
			printedchars++;
		}
	}
//	free(res_str);
	return(printedchars);
}