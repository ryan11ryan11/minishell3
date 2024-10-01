/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removehashnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:08:04 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:16:26 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"
#include "../E_Codes/e_codes.h"
#include <stdlib.h>

int	removenode(t_hashtable *hashtable, const char *key)
{
	int	i;

	i = findnode(hashtable, key);
	if (!(hashtable->table->table[i]))
		return (E_OK);
	free((void *)hashtable->table->table[i]->key);
	free((void *)hashtable->table->table[i]->data);
	hashtable->table->table[i]->key = NULL;
	hashtable->table->table[i]->data = NULL;
	hashtable->table->table[i]->state = E_FALSE;
	return (E_OK);
}
