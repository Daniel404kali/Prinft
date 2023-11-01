/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:54:32 by descamil          #+#    #+#             */
/*   Updated: 2023/11/01 19:17:35 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(const char *str, va_list args, int size)
{
	if (*str == ' ' && ft_strchr("sdi", *(str + 1)) != NULL)
	{
		size += ft_putchar(' ', size);
		size = ft_letter((str + 1), args, size);
	}
	else if (*str == '#' && ft_strchr("xX", *(str + 1)) != NULL)
	{
		size += ft_putstr("0x", size);
		size = ft_letter((str + 1), args, size);
	}
	else if (*str == '+' && ft_strchr("di", *(str + 1)) != NULL)
		size = ft_putnbr(va_arg(args, int), size, 1);
	return (size);
}
