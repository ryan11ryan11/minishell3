/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters_hash_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:52:43 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:20:06 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"

int	get_tabsize(t_hash_table *_hash_table)
{
	return (_hash_table->tabsize);
}

int	get_nodecount(t_hash_table *_hash_table)
{
	return (_hash_table->nodecount);
}

int	get_datacount(t_hash_table *_hash_table)
{
	return (_hash_table->datacount);
}

t_hashnode	**get_hashnode(t_hash_table *_hash_table)
{
	return (_hash_table->table);
}

t_fhash	get_f_hash(t_hash_table *_hash_table)
{
	return (_hash_table->f_hash);
}
