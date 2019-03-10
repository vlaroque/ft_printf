/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:55:42 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/09 22:59:53 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data_init.h"

t_spe_chars			*init_spe_chars(void)
{
	static t_spe_chars	*spe_chars_tab = NULL;

	if (!(spe_chars_tab))
	{
		if (!(spe_chars_tab = malloc(sizeof(t_spe_chars) * NB_SPE_CHARS)))
			return (0);
		spe_chars_tab[0].c = '%';
		spe_chars_tab[0].f = ft_conversion;
		spe_chars_tab[0].c = '{';
		spe_chars_tab[0].f = ft_colortxt;
	}
	return (spe_chars_tab);
}

static t_conv_chars	*init_conv_chars_filler(t_conv_chars *conv_chars_tab)
{
	conv_chars_tab[0].c = '%';
	conv_chars_tab[0].f = put_pc;
	conv_chars_tab[1].c = 'c';
	conv_chars_tab[1].f = put_c;
	conv_chars_tab[2].c = 's';
	conv_chars_tab[2].f = put_s;
	conv_chars_tab[3].c = 'd';
	conv_chars_tab[3].f = put_di;
	conv_chars_tab[4].c = 'i';
	conv_chars_tab[4].f = put_di;
	conv_chars_tab[5].c = 'u';
	conv_chars_tab[5].f = put_u;
	conv_chars_tab[6].c = 'o';
	conv_chars_tab[6].f = put_o;
	conv_chars_tab[7].c = 'x';
	conv_chars_tab[7].f = put_x;
	conv_chars_tab[8].c = 'X';
	conv_chars_tab[8].f = put_X;
	conv_chars_tab[9].c = 'p';
	conv_chars_tab[9].f = put_p;
	conv_chars_tab[10].c = 'f';
	conv_chars_tab[10].f = put_f;
	return (conv_chars_tab);
}

static t_conv_chars	*init_conv_chars_filler_second(t_conv_chars *conv_chars_tab)
{
	conv_chars_tab[11].c = 'b';
	conv_chars_tab[11].f = put_b;
	conv_chars_tab[12].c = 'r';
	conv_chars_tab[12].f = put_r;
	return (conv_chars_tab);
}

t_conv_chars		*init_conv_chars(void)
{
	static t_conv_chars	*conv_tab = NULL;

	if (!(conv_tab))
	{
		if (!(conv_tab = (t_conv_chars *)malloc(sizeof(t_conv_chars) * NB_CONV_CHARS)))
			return (0);
		conv_tab = init_conv_chars_filler(conv_tab);
		conv_tab = init_conv_chars_filler_second(conv_tab);
	}
	printf("%c\n",conv_tab[12].c);
	return (conv_tab);
}
