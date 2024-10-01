/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:52:59 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/24 19:52:21 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uchar	resetbit(t_uchar *data, t_uint bit)
{
	if (bit > FT_BIT_MAX)
		return (FT_BITERROR);
	*data &= ~((t_uchar)1 << bit);
	return (*data);
}
