/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:49:50 by descamil          #+#    #+#             */
/*   Updated: 2023/10/28 13:01:24 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int size)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{	
		ft_putchar(str[i], size);
		i++;
	}
	return (i);
}
