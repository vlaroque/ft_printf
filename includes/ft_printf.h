/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:51:15 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/21 18:02:47 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>	//pour les args
# include <stdlib.h>	//pour le malloc
# include <stdio.h>

int				ft_conversion(char *str, int *h, va_list *ap);

// from libft
void			ft_putchar(char c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *c);
int				ft_putstrcmpt(char *str);

typedef struct s_special_chars t_spe_chars;
struct	s_special_chars
{
	char	c;
	int		(*f)(char *str, int *h, va_list *ap);
};

typedef	struct s_parsedata t_parsedata;
struct	s_parsedata
{
	char	flags;
	int		width;
	int		precision;
	char	size;
};

typedef struct s_conversion_chars t_conv_chars;
struct	s_conversion_chars
{
	char	c;
	int		(*f)(char *str, int *h, t_parsedata data, va_list *ap);
};

t_spe_chars		*init_spe_chars(void);
t_conv_chars	*init_conv_chars(void);
int				ft_conv_procent(char *str, int *h, t_parsedata data, va_list *ap);
int				ft_conv_c(char *str, int *h, t_parsedata data, va_list *ap);
int				ft_conv_s(char *str, int *h, t_parsedata data, va_list *ap);

# define NB_SPE_CHARS 1
# define NB_CONV_CHARS 3
#endif