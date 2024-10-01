/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:53:18 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/24 19:34:59 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uchar	getbit(t_uchar *data, t_uint bit)
{
	if (bit > FT_BIT_MAX)
		return (FT_BITERROR);
	return (*data & ((t_uchar)1 << bit));
}
