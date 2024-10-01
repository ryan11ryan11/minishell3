/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:15:30 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/19 16:50:07 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*tmp;
	int		size;

	if (!src)
		return (NULL);
	size = 0;
	while (src[size] != '\0')
		++size;
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	size = 0;
	while (src[size] != '\0')
	{
		tmp[size] = src[size];
		++size;
	}
	tmp[size] = '\0';
	return (tmp);
}
