/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:05:46 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/14 01:05:47 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

size_t				strlen_safe(const char *s);
char				*ft_itoa_base(unsigned long long n, char *base);

#endif
