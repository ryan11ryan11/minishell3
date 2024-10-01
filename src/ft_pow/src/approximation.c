/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   approximation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/19 18:23:03 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pow.h"
#include <stdlib.h>

double	approx_one(double num, long deg)
{
	double	res;
	double	tmp;

	tmp = 1.0 / deg;
	res = 1.0 + tmp;
	while (pow_long(res, deg) > num)
	{
		if (res > 1)
			res -= tmp / ((double)deg * num);
		if (res < 1)
		{
			tmp = pow_long((tmp / (num * (double)deg)), deg - 1);
			tmp /= pow_long(num * (double)deg, deg);
			res = 1.0 + tmp;
		}
	}
	while (pow_long(res * res, deg) < num)
		res *= res;
	return (res);
}

double	approx_pow(double num, long deg)
{
	double	res;

	deg = ft_abs(deg);
	num = ft_abs(num);
	res = num / (deg * deg);
	if (res <= 1)
		return (approx_one(num, deg));
	while (pow_long(res, deg) > num)
		res /= deg * deg;
	if (res <= 1)
		return (approx_one(num, deg));
	while (pow_long(res * res, deg) < num)
		res *= res;
	return (res);
}

long	*dennum(double num)
{
	long	*arr;
	long	tmp;

	arr = malloc(2 * sizeof(long));
	if (!arr)
		return (NULL);
	arr[1] = 1;
	while (arr[1] < MAXNUM && ft_abs(num - (long)num) > PRECISION)
	{
		num *= FTPOW_DEC;
		arr[1] *= FTPOW_DEC;
	}
	tmp = find_cmndv(num, arr[1]);
	arr[0] = round_num(num) / tmp;
	arr[1] = arr[1] / tmp;
	return (arr);
}

double	numlesone(double num, double deg)
{
	long	*arr;
	double	res;

	arr = dennum(num);
	if (!arr)
		return (-1.0);
	res = pow_float(arr[0], deg) / pow_float(arr[1], deg);
	free(arr);
	return (res);
}
