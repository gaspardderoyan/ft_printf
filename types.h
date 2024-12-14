/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:08:32 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/14 01:08:33 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

void				p_char(va_list *ptr, int *ccount);
void				p_int(va_list *ptr, int *ccount);
void				p_percent(int *ccount);
void				p_else(const char *str, int *ccount);
void				p_str(va_list *ptr, int *ccount);
void				p_ptr(va_list *ptr, int *ccount);
void				p_ulong(va_list *ptr, int *ccount);
void				p_ubase(va_list *ptr, int *ccount, char *base);

#endif
