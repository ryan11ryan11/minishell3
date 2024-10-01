/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhashnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:48:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:19:55 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"
#include <stdlib.h>

int	findnode(t_hashtable *hashtable, const char *key)
{
	int	i;
	int	hash;
	int	step;
	int	atmp;

	hash = gethash(murmur3_32, key, hashtable->table->tabsize);
	step = getstephash(hash, hashtable->table->tabsize);
	i = hash;
	atmp = hashtable->table->tabsize * 2;
	while (atmp)
	{
		--atmp;
		if (hashtable->table->table[i] && hashtable->table->table[i]->state
			&& !ft_strcmp(key, hashtable->table->table[i]->key))
			return (i);
		i = (hash + atmp * step) % hashtable->table->tabsize;
	}
	return (hashtable->table->tabsize);
}
