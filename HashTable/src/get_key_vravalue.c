/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_vravalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:32:47 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:52:22 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"

const char	*get_data(t_hashtable *hashtable, const char *key)
{
	int	i;

	i = findnode(hashtable, key);
	if (i >= hashtable->table->tabsize)
		return (NULL);
	return (ft_strdup(hashtable->table->table[i]->data));
}

const char	*get_key(t_hashtable *hashtable, const char *key)
{
	int	i;

	i = findnode(hashtable, key);
	if (i >= hashtable->table->tabsize)
		return (NULL);
	return (ft_strdup(hashtable->table->table[i]->key));
}

int	get_place(t_hashtable *hashtable, const char *key)
{
	return (findnode(hashtable, key));
}
