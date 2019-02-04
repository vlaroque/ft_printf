/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/04 14:21:45 by vlaroque         ###   ########.fr       */
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
	char	str[] = {"lolilol123\n"};
	printf("v|%10s|\n", str);
	ft_printf("f|%10s|\n", str);
}
