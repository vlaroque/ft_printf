/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/01 18:11:36 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_putchar(char c);
int		ft_printf(char *str, ...);

int puiss10(int i)
{
	int res;
	res = 1;
	while (i)
	{
		res *=10;
	}
	return (res);
}

int		main(int ac, char **av)
{
	int res = 12345;
	char res2 = -120;
	unsigned long long reslong = 184467440737095516;

	printf("vrai printf:\n");
	printf(av[1], reslong);
	printf("\nfaux printf:\n");
	ft_printf(av[1], reslong);
	printf("%.3s", "Pomme");
//	printf("lol |%7f| |%5f| |%d|\n", 12345.123456, 67890.6789);
	//res = ft_printf("PHRASE%-20%ECRITE%20c|\n|%-30.5s|\n|%30.5s|\n", 'f', "ceci est une phrase", "ceci est une phrase");
	//res = ft_printf("Test de ftmbre : |%010i|\n", -12345);

	//printf("Test de nombre : |%.200000000d|\n", -12345);
	//res = ft_printf("Test de ftmbre : |%-.15d|\n", 12345);
	//printf("Test de nombre : |%#015x|\n", -12345);
	//printf("Test de nombre : |%hc|\n", 'c');
	//printf("%.200000000d", 123456789);
//	printf("res = %d\n", res);
}
