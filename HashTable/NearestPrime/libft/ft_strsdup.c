/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:07:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/20 14:19:23 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsdup(const char **src)
{
	int		size;
	char	**res;

	if (!src)
		return (NULL);
	size = ft_matsize(src);
	res = malloc((size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[size] = NULL;
	while (size)
	{
		--size;
		res[size] = ft_strdup(src[size]);
	}
	return (res);
}
