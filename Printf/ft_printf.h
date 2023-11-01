/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:41:05 by descamil          #+#    #+#             */
/*   Updated: 2023/10/28 12:59:48 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar(char c, int size);
int		ft_putstr(char *str, int size);
int		ft_strlen(char *str);
int		ft_putnbr(long long nb, int size);
int		ft_putnbr_base(unsigned long long nbr, int size, int x);
int		ft_printf(char const *str, ...);

#endif