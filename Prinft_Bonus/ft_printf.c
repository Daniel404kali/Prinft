/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:51:29 by descamil          #+#    #+#             */
/*   Updated: 2023/11/01 19:18:29 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (ft_strchr(" #+", *str) != NULL)
				size = ft_flags(str++, args, size);
			else
				size = ft_letter(str, args, size);
		}
		else
			size += ft_putchar(*str, size);
		str++;
	}
	va_end(args);
	return (size);
}
// int main()
// {
// 	int	digit = -2129874;
// 	int size = ft_printf(" %+d\n", digit);
// 	printf("%d\n", size);
// 	int size1 = printf(" %+d\n", digit);
// 	printf("%d\n", size1);
// 	return (0);
// }