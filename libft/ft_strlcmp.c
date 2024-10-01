/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:22:31 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/24 12:29:40 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

const char	*ft_strlcmp(const char *str, const char *cmp)
{
	while (*str && (*str == *cmp))
	{
		++str;
		++cmp;
	}
	if (!(*str) || !(*cmp))
		return (str);
	return (NULL);
}
