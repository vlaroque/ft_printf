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
	
	ft_printf("%%lol %---123.456hhs poipoi\n", str);
	printf("\nle vrai : %050.lli %i %#o %hhc", i, -55550, 'c', 'd');

	return (0);
}