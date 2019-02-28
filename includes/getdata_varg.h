/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_varg.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:44:59 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/28 10:04:09 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETINT_H
# define GETINT_H

uintmax_t		getuint(t_parsedata data, va_list *ap);
intmax_t		getint(t_parsedata data, va_list *ap);
long double		get_float(t_parsedata data, va_list *ap);

#endif