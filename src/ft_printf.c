/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:46:58 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/16 20:06:27 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spe_chars	*init_spe_chars(void)
{
	t_spe_chars	*spe_chars_tab;
	
	if (!(spe_chars_tab = malloc(sizeof(t_spe_chars) * NB_SPE_CHARS)))
		return (0);
	spe_chars_tab[0].c = '%';
	spe_chars_tab[0].f = ft_conversion;
	return (spe_chars_tab);
}

int		char_analyser(char *str, int *h, t_spe_chars *tab)
{
	int i;

	i = 0;
	while (i < NB_SPE_CHARS && str[*h] != tab[i].c)
		i++;
	if (str[*h] == tab[i].c)
		return (tab[i].f(str, h));
	else if (str[*h])
	{
		ft_putchar(str[*h]);
		(*h)++;
		return (1);
	}
	return (0);
}

int		ft_printf(char *str, ...)
{
	int			h;
	int			char_count;
	va_list		ap;
	t_spe_chars	*spe_char_tab;

	h = 0;
	char_count = 0;
	spe_char_tab = init_spe_chars();
	va_start(ap, str);
	while(str[h])
		char_count += char_analyser(str, &h, spe_char_tab);
	return(char_count);
}