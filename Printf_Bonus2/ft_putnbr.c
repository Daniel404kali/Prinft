/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:17:40 by descamil          #+#    #+#             */
/*   Updated: 2023/11/05 13:46:55 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb, int size, int plus)
{
	if (plus == 1 && nb >= 0)
	{
		plus = 0;
		size += ft_putchar('+');
	}
	else
		plus = 0;
	if (nb >= 0 && nb < 10)
		size += ft_putchar(nb + '0');
	else if (nb >= 10)
	{
		size = ft_putnbr(nb / 10, size, plus);
		size += ft_putchar((nb % 10) + '0');
	}
	else
	{
		size += ft_putchar('-');
		if (nb == INT_MIN)
			return (write (1, "2147483648", 10) + size);
		size = ft_putnbr(nb * -1, size, plus);
	}
	return (size);
}
