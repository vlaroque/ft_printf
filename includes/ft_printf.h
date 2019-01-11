/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:04:12 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/11 17:29:43 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

typedef struct s_arguments t_arguments;

struct	s_arguments
{
	unsigned char	flags;
	int		width;
	int		precision;
	unsigned char	size;
	char	typechar;
};

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_mini_atoi(const char *str, int *i);
int		ft_parser(char *str, int *i, t_arguments *args);
int		ft_conversions(char *str, int *i, t_arguments *args);

#endif