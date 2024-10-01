/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtablesrvc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:06:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:36:38 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "hashtable.h"

#define HASHSEED		0
#define C_RESIZE		2
#define HT_MALLOCERROR	"ERRROR!!! BAD ALLOC MEMMORY"

typedef struct s_hashnode
{
	t_cchar		*key;
	t_cchar		*data;
	char		state;
}					t_hashnode;

/////////////////////////////////HASHTABLE METHODS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
int				findnode(t_hashtable *hashtable, t_cchar *key);
int				removenode(t_hashtable *hashtable, t_cchar *key);
int				addnode(t_hashtable *hashtable, t_cchar *key, t_cchar *data);
int				resizehashtable(t_hashtable *hashtable, int xsize);
int				rehash(t_hashtable *hashtable);
int				gethash(t_fhash fhash, t_cchar *key, int tabsize);
int				getstephash(t_ulong hash, int tabsize);
uint32_t		murmur3_32(t_cchar *str, int len, uint32_t hash);
/////////////////////////////////HASHNODE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hashnode		*crthashnodet(t_cchar *key, t_cchar *data);
void			freehashnodet(t_hashnode *node);
void			*delhashnodet(t_hashnode *node);
t_cchar			*get_data(t_hashtable *hashtable, t_cchar *key);
t_cchar			*get_key(t_hashtable *hashtable, t_cchar *key);
int				get_place(t_hashtable *hashtable, t_cchar *key);
/////////////////////////////////_HASH_TABLE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hash_table	*crt_hash_table(int size);
void			freehash_table(t_hash_table *hashtable);