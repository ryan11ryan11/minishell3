/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rehash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:17:52 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:20:21 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtablesrvc.h"
#include <stdlib.h>

int	rehash(t_hashtable *hashtable)
{
	return (resizehashtable(hashtable, 1));
}
