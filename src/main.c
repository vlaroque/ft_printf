/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:35:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/18 10:53:11 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		ft_printf(char *str, ...);

int		main(void)
{
	int res;

//	printf("lol |%7f| |%5f| |%d|\n", 12345.123456, 67890.6789);
	res = ft_printf("lol%%|%%|%c|%s\n", 'z', "ceci est une phrase", 'f');
	printf("res = %d\n", res);
	return (0);
}
