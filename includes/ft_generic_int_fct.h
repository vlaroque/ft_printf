/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_int_fct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:42:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/15 19:25:01 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GENERIC_INT_FCT_H
# define FT_GENERIC_INT_FCT_H

int			print_char_x_times(char c, int times);
int			mega_nbrlen_base_unsigned(uintmax_t nbr, char *base);
void		mega_putnbr_base(intmax_t nbr, char *base);
void		mega_putnbr_base_unsigned(uintmax_t nbr, char *base);
int			put_zeros(t_parsedata data, int len, int prefix);
int			put_spaces(int printedchars, t_parsedata data, int len, int prefix);
uintmax_t	positive_me(intmax_t nbr);
t_parsedata	flag_cleaner(t_parsedata data);
int			zero(t_parsedata data);

#endif