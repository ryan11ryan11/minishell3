/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_hash_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:04:35 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/26 23:10:25 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/hash_table.h"
#include <stdlib.h>

static t_hashnode	**crttable(int size)
{
	t_hashnode	**table;

	table = malloc(size * sizeof(t_hashnode *));
	if (!table)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	while (size)
	{
		--size;
		table[size] = NULL;
	}
	return (table);
}

t_hash_table	*crt_hash_table(int size)
{
	t_hash_table	*hash_table;

	hash_table = malloc(sizeof(t_hash_table));
	if (!hash_table)
	{
		ft_perror("MAMMORY ERROR ALOCATION!!!");
		exit(-1);
	}
	hash_table->table = crttable(size);
	hash_table->tabsize = size;
	hash_table->datacount = 0;
	hash_table->nodecount = 0;
	return (hash_table);
}

void	freetable(t_hashnode **table, int size)
{
	while (size)
	{
		--size;
		if (table[size])
		{
			free((void *)(table[size]->data));
			free((void *)(table[size]->key));
			free(table[size]);
		}
	}
	free(table);
}

void	freehash_table(t_hash_table *hashtable)
{
	freetable(hashtable->table, hashtable->tabsize);
	free(hashtable);
}
