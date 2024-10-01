/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crthashatable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:26:02 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:19:41 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"
#include <stdlib.h>

t_hashtable	*crthashtable(int size)
{
	t_hashtable	*hashtable;

	hashtable = malloc(sizeof(t_hashtable));
	if (!hashtable)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	hashtable->table = crt_hash_table(size);
	hashtable->add = addnode;
	hashtable->remove_node = removenode;
	hashtable->get_data = get_data;
	hashtable->get_key = get_key;
	hashtable->get_tabsize = get_tabsize;
	hashtable->set_f_hash = set_f_hash;
	hashtable->table->f_hash = murmur3_32;
	hashtable->get_place = get_place;
	return (hashtable);
}

t_hashtable	*crtnewhashtable(t_hashtable *table, int size)
{
	t_hashtable	*newtable;

	newtable = malloc(sizeof(t_hashtable));
	if (!newtable)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	newtable->table = crt_hash_table(size);
	newtable->add = table->add;
	newtable->remove_node = table->remove_node;
	newtable->get_data = table->get_data;
	newtable->get_key = table->get_key;
	newtable->get_tabsize = table->get_tabsize;
	newtable->set_f_hash(newtable->table, get_f_hash(table->table));
	newtable->get_place = table->get_place;
	return (newtable);
}

void	freehashtablet(t_hashtable *hashtable)
{
	freehash_table(hashtable->table);
	free(hashtable);
}
