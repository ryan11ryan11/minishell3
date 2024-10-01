/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmarkprimes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:02:57 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/24 20:21:44 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_uchar	*initprimearray(unsigned long size)
{
	t_ulong	i;
	t_uchar	*tmp;

	tmp = malloc((size + 1) * sizeof(t_uchar));
	if (!tmp)
	{
		ft_perror("ERROR: Bad alocation mammory");
		exit(-1);
	}
	i = -1;
	while (++i < size)
		tmp[i] = FT_UCHARMAXVAL;
	resetbit(&(*tmp), 0);
	resetbit(&(*tmp), 1);
	return (tmp);
}

static void	setnprm(t_uchar *primearr, t_ulong num, t_ulong prm, t_uint bit)
{
	t_ulong	j;

	prm = prm * FT_BIT_MAX + bit;
	j = prm * prm;
	while (j <= num)
	{
		resetbit(&(primearr[j / FT_BIT_MAX]), j % FT_BIT_MAX);
		j += prm;
	}
}

static t_uchar	*setprimebits(t_uchar *primearr, t_ulong num)
{
	t_uint	bit;
	t_ulong	i;

	i = 0;
	while (i * FT_BIT_MAX <= num)
	{
		bit = 0;
		while (bit < FT_BIT_MAX)
		{
			if (getbit(&(primearr[i]), bit))
				setnprm(primearr, num, i, bit);
			++bit;
		}
		++i;
	}
	return (primearr);
}

t_uchar	*ft_getmarkprimes(unsigned long num)
{
	if (num < 2)
		return (NULL);
	return (setprimebits(initprimearray(num / FT_BIT_MAX + 1), num));
}
