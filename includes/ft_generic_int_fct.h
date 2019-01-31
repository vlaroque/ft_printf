/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_int_fct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:42:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/01/31 14:45:01 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GENERIC_INT_FCT_H
# define FT_GENERIC_INT_FCT_H

int		print_char_x_times(char c, int times);
int		mega_nbrlen_base(intmax_t nbr, char *base);
void	mega_putnbr_base(intmax_t nbr, char *base);
void	mega_putnbr_base_unsigned(uintmax_t nbr, char *base);
int		put_zeros(t_parsedata data, int len, int prefix);
int		put_spaces(int printedchars, t_parsedata data, int len, int prefix);

#endif