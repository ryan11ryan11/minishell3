/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:09:11 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/24 21:31:45 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strldup(const char *src, int n)
{
	char	*tmp;

	if (!(*src))
		return (NULL);
	tmp = malloc((n + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[n] = '\0';
	while (n)
	{
		--n;
		tmp[n] = src[n];
	}
	return (tmp);
}
