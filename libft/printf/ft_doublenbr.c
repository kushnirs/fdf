/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublenbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 03:20:28 by sergee            #+#    #+#             */
/*   Updated: 2017/12/27 21:31:27 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	ft_pow(double i, double a)
{
	double res;

	if (a <= 0)
		return (1);
	res = i;
	while (a-- > 1)
		res *= i;
	return (res);
}

void			ft_f_nbr(double n, int i)
{
	double	fraction;

	if (n != n || n == INF)
	{
		if (!ft_strcmp("lf", g_f.conversion) ||
			!ft_strcmp("f", g_f.conversion))
			n == INF ? ft_putstr("inf") : ft_putstr("nan");
		else
			n == INF ? ft_putstr("INF") : ft_putstr("NAN");
		return ;
	}
	n > 0 ? n += 0.5 * ft_pow(0.1, (double)i) : 0;
	n < 0 ? n -= 0.5 * ft_pow(0.1, (double)i) : 0;
	ft_lnbr((long)n, 0);
	i != 0 ? ft_putchar('.') : 0;
	n < 0 ? n = -n : 0;
	fraction = n - (long)n;
	while (i-- > 0)
	{
		ft_unbr((fraction *= 10), 0);
		fraction -= (long)fraction;
	}
}

void			ft_fl_nbr(t_ld n, int i)
{
	t_ld	fraction;

	if (n != n || n == INF)
	{
		if (!ft_strcmp("Lf", g_f.conversion) ||
			!ft_strcmp("f", g_f.conversion))
			n == INF ? ft_putstr("inf") : ft_putstr("nan");
		else
			n == INF ? ft_putstr("INF") : ft_putstr("NAN");
		return ;
	}
	n > 0 ? n += 0.5 * ft_pow(0.1, (double)i) : 0;
	n < 0 ? n -= 0.5 * ft_pow(0.1, (double)i) : 0;
	ft_lnbr((uintmax_t)n, 0);
	i != 0 ? ft_putchar('.') : 0;
	n < 0 ? n = -n : 0;
	fraction = n - (uintmax_t)n;
	while (i-- > 0)
	{
		ft_unbr((fraction *= 10), 0);
		fraction -= (uintmax_t)fraction;
	}
}

size_t			ft_f_nbrlen(double n, int i)
{
	size_t len;

	if (n != n || n == INF)
		return (3);
	len = ft_lnbrlen((t_ul)n) + i + 1;
	return (len);
}

size_t			ft_fl_nbrlen(t_ld n, int i)
{
	size_t len;

	if (n != n || n == INF)
		return (3);
	len = ft_ulnbrlen((t_ui)n) + i + 1;
	return (len);
}
