/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:25:03 by descamil          #+#    #+#             */
/*   Updated: 2023/11/01 18:24:34 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_letter(char const *str, va_list args, int size)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int), size) + size);
	else if (*str == 's')
		return (size + ft_putstr(va_arg(args, char *), size));
	else if (*str == 'p')
		return (ft_putstr("0x", size) + ft_putnbr_base(va_arg(args, unsigned long long), size, 0));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int), size, 0));
	else if (*str == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), size, 0));
	else if (*str == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), size, 0));
	else if (*str == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), size, 1));
	else if (*str == '%')
	{
		str++;
		if (*str == '%' && ft_strchr("csdipuxX", *str) == NULL)
			size = ft_letter(str, args, size);
		else
			size += ft_putchar('%', size);
		return (size);
	}
	return (size);
}
