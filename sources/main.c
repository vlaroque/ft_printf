/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:56:19 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/06 18:56:19 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_printf(char *str, ...);

int		main(void)
{
	long long i = 321654987;
	char	str[10] = "lolilol\na\0";
	
	ft_printf("%%lol %#15.63s\n", str);
	printf("\nle vrai : %.5lld", i);

	return (0);
}