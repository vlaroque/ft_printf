/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:49:34 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/15 12:53:27 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_F_H
# define PUT_F_H

int		round_check(char *str, int i);
int		pre_len(int precision);
int		rounding(t_parsedata data, char *str);
int		print_spaces_or_zeros(t_parsedata data, int intlen, int state, int neg);
int		int_len(char *str);
int		printsign(t_parsedata data, int neg);
int		print_intpart(int len, char *str, t_parsedata data);
int		ft_ldbl_is_neg(long double nbr);
int		put_f_specials(long double nbr, t_parsedata *data, char *str, int *neg);
int		ft_is_special(long double nbr, t_parsedata *data, char **str, int *neg);



#endif