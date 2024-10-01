/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seters_hash_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:42:09 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:20:36 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/hashtablesrvc.h"
#include "../hdrs/hash_table.h"

void	set_f_hash(t_hash_table *_hash_table, t_fhash f_hash)
{
	if (f_hash)
		_hash_table->f_hash = f_hash;
}
