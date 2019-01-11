/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:08:42 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/11 17:34:57 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

#include "ft_printf.h"

typedef struct s_types t_types;

struct	s_types
{
	char	typechar;
	int		(*ptr_on_ft)(t_arguments);
};

int test(t_arguments args);

t_types type_tab[] = {
	{'%', &test},
	{'c', &test},
	{'s', &test},
	{'p', &test},
	{'\0', NULL}
};
#endif