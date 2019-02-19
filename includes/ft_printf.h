/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:51:15 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/19 16:53:31 by vlaroque         ###   ########.fr       */
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
int				ft_strlen(const char *c);
int				ft_putstrcmpt(char *str);
char			*ft_strdup(const char *s1);
char			*ft_itoabase(int value, char *basechars);

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
int				put_pc(char *str, int *h, t_parsedata data, va_list *ap);
int				put_c(char *str, int *h, t_parsedata data, va_list *ap);
int				put_s(char *lol, int *h, t_parsedata data, va_list *ap);
int				put_di(char *str, int *h, t_parsedata data, va_list *ap);
int				put_u(char *str, int *h, t_parsedata data, va_list *ap);
int				put_o(char *nostr, int *noh, t_parsedata data, va_list *ap);
int				put_x(char *nostr, int *noh, t_parsedata data, va_list *ap);
int				put_X(char *nostr, int *noh, t_parsedata data, va_list *ap);
int				put_p(char *lol, int *h, t_parsedata data, va_list *ap);
int				put_f(char *nostr, int *noh, t_parsedata data, va_list *ap);

int				ft_printer(char *res_str, char isnbr, t_parsedata data);

# define NB_SPE_CHARS 1
# define NB_CONV_CHARS 11
#endif