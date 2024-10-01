/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:34:26 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/19 19:14:36 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_perror(const char *msg)
{
	ft_putstr(P_C_RED);
	ft_putstr(msg);
	ft_putstr(P_C_RED);
	ft_putchar('\n');
	return (NULL);
}
