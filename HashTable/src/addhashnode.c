/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addhashnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:35:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:15:45 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"
#include "../E_Codes/e_codes.h"
#include <stdlib.h>
#include <stdio.h>

void	checkhashtable(t_hashtable *hashtable)
{
	if (hashtable->table->tabsize <= hashtable->table->nodecount + 1)
		resizehashtable(hashtable, C_RESIZE);
	if (hashtable->table->datacount && hashtable->table->nodecount
		>= hashtable->table->datacount * C_RESIZE)
		rehash(hashtable);
}

int	findplace(const char *key, t_hashtable *hashtable, int hash, int step)
{
	int	i;
	int	atmp;

	i = hash;
	atmp = hashtable->table->tabsize * 2;
	while (hashtable->table->table[i] && hashtable->table->table[i]->state
		&& atmp)
	{
		if (!ft_strcmp(key, hashtable->table->table[i]->key))
			return (i);
		--atmp;
		i = (hash + atmp * step) % hashtable->table->tabsize;
	}
	if (!hashtable->table->table[i] || !hashtable->table->table[i]->state)
		return (i);
	resizehashtable(hashtable, C_RESIZE);
	return (findplace(key, hashtable, hash, step));
}

void	putdata(int place, t_cchar *key, t_cchar *data, t_hashtable *hashtable)
{
	if (!hashtable->table->table[place])
		hashtable->table->table[place] = crthashnodet(key, data);
	else
	{
		if (ft_strcmp(key, hashtable->table->table[place]->key))
		{
			free((void *)hashtable->table->table[place]->key);
			hashtable->table->table[place]->key = (t_cchar *)ft_strdup(key);
		}
		free((void *)hashtable->table->table[place]->data);
		hashtable->table->table[place]->data = (t_cchar *)ft_strdup(data);
		hashtable->table->table[place]->state = E_TRUE;
	}
	++hashtable->table->datacount;
	++hashtable->table->nodecount;
}

int	addnode(t_hashtable *hashtable, const char *key, const char *data)
{
	int	place;
	int	hash;
	int	step;

	checkhashtable(hashtable);
	hash = gethash(murmur3_32, key, hashtable->table->tabsize);
	step = getstephash(hash, hashtable->table->tabsize);
	place = findplace(key, hashtable, hash, step);
	putdata(place, key, data, hashtable);
	return (E_OK);
}
