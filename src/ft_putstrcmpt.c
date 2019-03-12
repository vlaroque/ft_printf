/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcmpt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:59:09 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/12 18:47:52 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_putstrcmpt(char *str)
{
	int		len;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}