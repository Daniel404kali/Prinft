/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:41:05 by descamil          #+#    #+#             */
/*   Updated: 2023/11/05 12:36:29 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(const char *str);
int		ft_putnbr(long long nb, int size, int plus);
int		ft_putnbr_base(unsigned long long nbr, int size, int x);
int		ft_printf(char const *str, ...);
int		ft_flags(const char *str, va_list args, int size);
int		ft_letter(char const *str, va_list args, int size);
char	*ft_strchr(const char *s, int c);

#endif