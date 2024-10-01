/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:54:23 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/25 13:57:34 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		++src_len;
	if (size <= 0)
		return (src_len);
	if (size > src_len)
		size = src_len + 1;
	dest[--size] = '\0';
	while (size)
	{
		--size;
		dest[size] = src[size];
	}
	return (src_len);
}
