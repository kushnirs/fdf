/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 23:37:27 by sergee            #+#    #+#             */
/*   Updated: 2018/01/10 01:05:07 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_hex_to_dec(char *str)
{
	long	num;
	int		power;

	if (!str)
		return (0);
	power = ft_strlen(str) - 4;
	num = 0;
	str += 3;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num += (*str - 48) * ft_pow(16, power--);
		else if (*str == 'A')
			num += 10 * ft_pow(16, power--);
		else if (*str == 'B')
			num += 11 * ft_pow(16, power--);
		else if (*str == 'C')
			num += 12 * ft_pow(16, power--);
		else if (*str == 'D')
			num += 13 * ft_pow(16, power--);
		else if (*str == 'E')
			num += 14 * ft_pow(16, power--);
		else if (*str == 'F')
			num += 15 * ft_pow(16, power--);
		str++;
	}
	return (num);
}