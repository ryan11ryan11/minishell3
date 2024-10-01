/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:58:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:14:13 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../hdrs/hashtablesrvc.h"

struct s_hash_table
{
	int				tabsize;
	int				nodecount;
	int				datacount;
	t_hashnode		**table;
	t_fhash			f_hash;
};

int			get_tabsize(t_hash_table *_hash_table);
int			get_nodecount(t_hash_table *_hash_table);
int			get_datacount(t_hash_table *_hash_table);
t_hashnode	**get_hashnode(t_hash_table *_hash_table);
t_fhash		get_f_hash(t_hash_table *_hash_table);
void		set_f_hash(t_hash_table *_hash_table, t_fhash f_hash);
