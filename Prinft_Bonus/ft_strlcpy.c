/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:09:26 by descamil          #+#    #+#             */
/*   Updated: 2023/11/01 18:46:00 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlcpy(char *dest, const char *src, int len_dest)
{
	int	i;

	i = 0;
	if (len_dest <= ft_strlen(src))
	{
		if (len_dest == 0)
			return (ft_strlen(src));
		while (len_dest > 1)
		{	
			dest[i] = src[i];
			len_dest--;
			i++;
		}
		dest[i] = '\0';
		return (ft_strlen(src));
	}
	i = 0;
	while (i < len_dest - 1 && src[i] != '\0')
	{	
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
