/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:51:29 by descamil          #+#    #+#             */
/*   Updated: 2023/10/30 16:51:34 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static int	ft_letter(char const *str, va_list args, int size)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int), size) + size);
	else if (*str == 's')
		return (size + ft_putstr(va_arg(args, char *), size));
	else if (*str == 'p')
		return (ft_putstr("0x", size)
			+ ft_putnbr_base(va_arg(args, unsigned long long), size, 0));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int), size));
	else if (*str == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), size));
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

int	ft_printf(char const *str, ...)
{
	int			size;
	va_list		args;

	va_start (args, str);
	size = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{	
			str++;
			size = ft_letter(str, args, size);
		}
		else
			size += ft_putchar(*str, size);
		str++;
	}
	va_end(args);
	return (size);
}
