/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/21 18:58:46 by vlaroque         ###   ########.fr       */
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

int		main(void)
{
	int res = 123456789;

//	printf("lol |%7f| |%5f| |%d|\n", 12345.123456, 67890.6789);
//	res = ft_printf("lol%%|%%|%c|%s\n", 'z', "ceci est une phrase", 'f');
	printf("%10%res = |%x|\n", (int)0);
}
