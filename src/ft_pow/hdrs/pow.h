/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:22:21 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/19 19:35:58 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MIN_DEV 1
#define DBL_MAX_ROOT_TEN	6690699980388652205836230197248.0
#define DBL_MAX_ROOT_HNDR	1209.336485
#define PRECISION			0.0000001
#define FTPOW_DEC			10
#define MAXNUM				1000000
#define C_SQRT				0.5

double	ft_pow(double num, double deg);
double	approx_one(double num, long deg);
double	approx_pow(double num, long deg);
double	pow_long(double num, long deg);
double	pow_float(double num, double deg);
double	newtroot(double num, double deg, double approx);
////////////////////////TOOLS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
long	round_num(double num);
double	ft_abs(double num);
double	find_nearestr(double num, long root);
long	isprime(long x);
long	find_cmndv(long deg, long root);
double	root_av(double num, double deg, long root);
long	*dennum(double num);
double	numlesone(double num, double deg);
