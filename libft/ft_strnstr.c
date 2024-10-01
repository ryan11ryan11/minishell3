/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:05:43 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/21 22:05:13 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *s, size_t len)
{
	size_t	i;
	size_t	len_str;

	if (*s == '\0')
		return ((char *)str);
	len_str = ft_strlen(str);
	if (len_str < len)
		len = len_str;
	while (*str && len > 0)
	{
		i = 0;
		while (s[i] && *(str + i) == s[i] && i < len)
			++i;
		if (!s[i])
			return ((char *)str);
		++str;
		--len;
	}
	return (NULL);
}
