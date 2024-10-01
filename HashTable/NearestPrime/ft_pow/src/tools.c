/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:33:30 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/19 18:23:16 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pow.h"

long	round_num(double num)
{
	if (num - (long)num < 0.5)
		return ((long)num);
	return ((long)num + 1);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

long	isprime(long x)
{
	long	num;

	if (x < 2)
		return (0);
	num = 2;
	while (num * num <= x)
	{
		if (x % num == 0)
			return (0);
		++num;
	}
	return (num);
}

long	find_cmndv(long deg, long root)
{
	long	max;
	long	i;

	if (!deg)
		return (1);
	if (!(root % deg))
		return (deg);
	max = 1;
	i = 2;
	while (i * i <= deg)
	{
		if (!(root % i) && !(deg % i))
			max = i;
		++i;
	}
	return (max);
}

double	root_av(double num, double deg, long root)
{
	while (ft_abs(deg - round_num(deg)) > 0.0000001)
	{
		deg *= 10;
		root *= 10;
	}
	deg = round_num(deg);
	root = round_num((double)root / deg);
	return (newtroot(num, (double)root, approx_pow(num, root)));
}
