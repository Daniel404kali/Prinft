/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:54:32 by descamil          #+#    #+#             */
/*   Updated: 2023/11/05 14:01:33 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags2(const char *str, va_list args, int size)
{
	int				digit;
	char			*strstr;

	if (*str == ' ' && ft_strchr("di", *(str + 1)) != NULL)
	{
		digit = va_arg(args, int);
		if (digit >= 0)
			size += ft_putchar(' ');
		size = ft_putnbr(digit, size, 0);
	}
	else if (*str == ' ' && *(str + 1) == 's')
	{
		strstr = va_arg(args, char *);
		if (size == 0 && strstr == NULL)
			size += ft_putchar(' ');
		size += ft_putstr(strstr);
	}
	else if (*str == '+' && ft_strchr("di", *(str + 1)) != NULL)
	{
		digit = va_arg(args, int);
		size = ft_putnbr(digit, size, 1);
	}
	return (size);
}

int	ft_flags(const char *str, va_list args, int size)
{
	unsigned int	uplo;

	if (ft_strchr("dsi", *(str + 1)) != NULL)
		size = ft_flags2(str, args, size);
	else if (*str == '#' && *(str + 1) == 'x')
	{
		uplo = va_arg(args, unsigned int);
		if (uplo == 0)
			return (ft_putchar('0') + size);
		size = (ft_putstr("0x") + ft_putnbr_base(uplo, size, 0));
	}
	else if (*str == '#' && *(str + 1) == 'X')
	{
		uplo = va_arg(args, unsigned int);
		if (uplo == 0)
			return (ft_putchar('0') + size);
		size = (ft_putstr("0X") + ft_putnbr_base(uplo, size, 1));
	}
	return (size);
}
