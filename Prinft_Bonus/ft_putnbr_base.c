/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:22:46 by descamil          #+#    #+#             */
/*   Updated: 2023/10/28 12:53:28 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nbr, int size, int x)
{
	char	*base;

	if (x == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		size += ft_putchar('-', size);
		nbr = -nbr;
	}
	if (nbr < 16)
		ft_putchar(base[nbr % 16], size);
	else
	{
		size = ft_putnbr_base(nbr / 16, size, x);
		ft_putchar(base[nbr % 16], size);
	}
	size++;
	return (size);
}
