/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:51:15 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/18 16:22:31 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>	//pour les args
# include <stdlib.h>	//pour le malloc
# include <stdio.h>
#include "ft_color.h"

# define NB_SPE_CHARS 2
# define NB_CONV_CHARS 18
int				ft_printf(char *str, ...);
int				ft_conversion(char *str, int *h, va_list *ap, int fd);

// from libft
void			ft_putchar(char c);
int				ft_isdigit(int c);
int				ft_strlen(const char *c);
int				ft_putstrcmpt(char *str);
char			*ft_strdup(const char *s1);
char			*ft_itoabase(int value, char *basechars);

/* pour les characteres speciaux conversio ou couleur */
typedef struct s_special_chars t_spe_chars;
struct	s_special_chars
{
	char	c;
	int		(*f)(char *str, int *h, va_list *ap, int fd);
};

typedef	struct s_parsedata t_parsedata;
struct	s_parsedata
{
	char	flags;
	int		index;
	int		width;
	int		precision;
	char	size;
	int		fd;
};

/* pour les conversions comme dioux...*/
typedef struct s_conversion_chars t_conv_chars;
struct	s_conversion_chars
{
	char	c;
	int		(*f)(t_parsedata data, va_list *ap);
};

t_spe_chars		*init_spe_chars(void);
t_conv_chars	*init_conv_chars(void);
int				put_pc(t_parsedata data, va_list *ap);
int				put_c(t_parsedata data, va_list *ap);
int				put_s(t_parsedata data, va_list *ap);
int				put_di(t_parsedata data, va_list *ap);
int				put_u(t_parsedata data, va_list *ap);
int				put_o(t_parsedata data, va_list *ap);
int				put_x(t_parsedata data, va_list *ap);
int				put_X(t_parsedata data, va_list *ap);
int				put_p(t_parsedata data, va_list *ap);
int				put_f(t_parsedata data, va_list *ap);
int				put_b(t_parsedata data, va_list *ap);
int				put_r(t_parsedata data, va_list *ap);

int				put_D(t_parsedata data, va_list *ap);
int				put_I(t_parsedata data, va_list *ap);
int				put_O(t_parsedata data, va_list *ap);
int				put_U(t_parsedata data, va_list *ap);
int				put_F(t_parsedata data, va_list *ap);

#endif