/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:55:42 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/18 10:49:52 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data_init.h"

t_spe_chars		*init_spe_chars(void)
{
	static t_spe_chars	*spe_chars_tab = NULL;
	
	if (!(spe_chars_tab))
	{
		if (!(spe_chars_tab = malloc(sizeof(t_spe_chars) * NB_SPE_CHARS)))
			return (0);
	spe_chars_tab[0].c = '%';
	spe_chars_tab[0].f = ft_conversion;
	}
	return (spe_chars_tab);
}

t_conv_chars	*init_conv_chars(void)
{
	static t_conv_chars	*conv_chars_tab = NULL;
	
	if (!(conv_chars_tab))
	{
		if (!(conv_chars_tab = malloc(sizeof(t_spe_chars) * NB_SPE_CHARS)))
			return (0);
	conv_chars_tab[0].c = '%';
	conv_chars_tab[0].f = ft_conv_procent;
	conv_chars_tab[1].c = 'c';
	conv_chars_tab[1].f = ft_conv_c;
	conv_chars_tab[2].c = 's';
	conv_chars_tab[2].f = ft_conv_s;
	}
	return (conv_chars_tab);
}