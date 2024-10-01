/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:45:05 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:51:13 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "../NearestPrime/libft/libft.h"
# include <stdint.h>
# include <stdlib.h>

typedef struct s_hash_table	t_hash_table;
typedef struct s_hashtable	t_hashtable;
typedef uint32_t			(*t_fhash)(t_cchar *key, int tbsize, uint32_t seed);

struct	s_hashtable
{
	t_hash_table	*table;
	int				(*add)(t_hashtable *hashtable, t_cchar *key, t_cchar *data);
	int				(*remove_node)(t_hashtable *, t_cchar *key);
	const char		*(*get_data)(t_hashtable *, const char *key);
	const char		*(*get_key)(t_hashtable *, const char *key);
	int				(*get_tabsize)(t_hash_table *_hash_table);
	int				(*get_place)(t_hashtable *hashtable, const char *key);
	void			(*set_f_hash)(t_hash_table *_hash_table, t_fhash f_hash);
};

/////////////////////////////////CRT HASHTABLE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hashtable		*crthashtable(int size);
t_hashtable		*crtnewhashtable(t_hashtable *table, int xsize);
void			freehashtablet(t_hashtable *hashtable);

#endif