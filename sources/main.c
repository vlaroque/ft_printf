/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:17:59 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/11 19:29:41 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int		ft_printf(char *str, ...);

int		main(void)
{
	char	str[10];

	ft_printf("%%lol %c %---123.456hhs poipoi \n", str);
	return (0);
}

/*
/	printf("\nle vrai : %050.lli %#o %hhc\n", -55550, 'c', 'd');
/	printf("|%-10]5d| plip\n", 12);
/	printf("|%10]5d| plip\n", 12);
/	printf("|%+++-+-+-++++-+-+--++10.5d|\n", -12);
/	printf("|%0+.5d|\n", 1);
/	printf("|%10d|\n", -12);
/	printf("|%010d|\n", -12); 
/	printf("|%-10.5d|\n", -12);
/	printf("|%-010.5d|\n", -12);
/	printf("%10000000000d\n", 1234567);
*/