/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:17:40 by descamil          #+#    #+#             */
/*   Updated: 2023/11/01 19:20:23 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb, int size, int plus)
{
	char	*ptr;
	if (plus == 1 && nb > 0)
	{
		plus = 0;
		size += ft_putchar('+', size);
	}
	else
		plus = 0;
	if (nb >= 0 && nb < 10)
		size += ft_putchar(nb + '0', size);
	else if (nb >= 10)
	{
		size = ft_putnbr(nb / 10, size, plus);
		size += ft_putchar((nb % 10) + '0', size);
	}
	else
	{
		if (nb == INT_MIN)
		{
			ptr = ft_itoa(INT_MIN);
			size += ft_putstr(ptr, size);
			free(ptr);
			return (size);
		}
		size += ft_putchar('-', size);
		size = ft_putnbr(nb * -1, size, plus);
	}
	return (size);
}
