/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:13:06 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:16:37 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"
#include "../E_Codes/e_codes.h"
#include <stdlib.h>

int	resizehashtable(t_hashtable *hashtable, int xsize)
{
	int				i;
	t_hash_table	*tmp;

	tmp = hashtable->table;
	hashtable->table = crt_hash_table(hashtable->table->tabsize * xsize);
	i = 0;
	while (i < tmp->tabsize)
	{
		if (tmp->table[i] && tmp->table[i]->state)
			addnode(hashtable, tmp->table[i]->key, tmp->table[i]->data);
		++i;
	}
	freehash_table(tmp);
	return (E_OK);
}
