/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:52:33 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/02 16:08:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *src, int n)
{
	char	*tmp;

	if (!(*src))
		n = 0;
	tmp = malloc((n + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, src, n);
	return (tmp);
}
