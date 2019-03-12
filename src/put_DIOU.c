/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_DIOU.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:19:52 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/12 12:25:25 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_D(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_di(nostr, noh, data, ap));
}

int		put_I(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_di(nostr, noh, data, ap));
}

int		put_O(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_o(nostr, noh, data, ap));
}

int		put_U(char *nostr, int *noh, t_parsedata data, va_list *ap)
{
	data.size = 3;
	return (put_u(nostr, noh, data, ap));
}