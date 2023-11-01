/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:17:40 by descamil          #+#    #+#             */
/*   Updated: 2023/10/28 12:50:37 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb, int size)
{
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0', size);
		size++;
	}
	else if (nb >= 10)
	{
		size = ft_putnbr(nb / 10, size);
		ft_putchar((nb % 10) + '0', size);
		size++;
	}
	else
	{
		ft_putchar('-', size);
		size++;
		if (nb == -2147483648)
		{
			ft_putchar('2', size);
			ft_putnbr(147483648, size);
			return (size + 10);
		}
		size = ft_putnbr(nb * -1, size);
	}
	return (size);
}

// int	main()
// {
// 	int	number = INT_MIN;
// 	int size = ft_putnbr(number, 2);
// 	printf("\n%d\n", size);
// 	return (0);
// }
