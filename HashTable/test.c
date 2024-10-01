/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:03:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 20:54:35 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/hashtable.h"
#include <stdlib.h>
#include <stdio.h>

char  **crtstrs(int size, t_cchar *startkey)
{
	int    i;
	char  **keys;

	keys = malloc((size + 1) * sizeof(char *));
	keys[size] = NULL;
	i = 0;
	while (i < size)
	{
		keys[i] = ft_strjoinfree((char *)startkey, ft_itoa(i * i), 1);
		++i;
	}
	return (keys);
}

void	printm(const char **mat)
{
	while (*mat)
	{
		printf("%s\n", *mat);
		++mat;
	}
}

int main()
{
	int			size;
	int			count;
	char		**keys;
	char		**datas;
	t_cchar		*key;
	t_cchar		*data;
	t_hashtable	*hashtable;

	size = 1;
	count = 100;
	hashtable = crthashtable(size);
	keys = crtstrs(count, "KEY FOR HASHTABL: ");
	datas = crtstrs(count, "DATA: ");
	// printm((t_cchar **)keys);
	for (int i = 0; i < count; ++i)
	{
		hashtable->add(hashtable, (t_cchar *)keys[i], (t_cchar *)datas[i]);
		if (i)
			hashtable->add(hashtable, (t_cchar *)keys[i - 1], (t_cchar *)datas[i - 1]);
	}
	for (int i = 0; i < count; ++i)
	{
		key = hashtable->get_key(hashtable, keys[i]);
		data = hashtable->get_data(hashtable, keys[i]);
		printf("NODE[%d]:\tKEY: %s\tDATA: %s\tHASHTABLE[%d]\n",
			i, key, data, hashtable->get_place(hashtable, keys[i]));
		free((void *)key);
		free((void *)data);
	}
	for (int i = 0; i < count; ++i)
		if (i && !(i % 2))
			hashtable->remove_node(hashtable, keys[i]);
	printf("---------------------\n");
	for (int i = 0; i < count; ++i)
	{
		key = hashtable->get_key(hashtable, keys[i]);
		data = hashtable->get_data(hashtable, keys[i]);
		printf("NODE[%d]:\tKEY: %s\tDATA: %s\n", i, key, data);
		free((void *)key);
		free((void *)data);
	}
	ft_free_d((void **)keys);
	ft_free_d((void **)datas);
	keys = crtstrs(count, "KEY FOR HASHTABLA TEST: ");
	datas = crtstrs(count, "DATA TEST: ");
	for (int i = 0; i < count; ++i)
	{
		key = hashtable->get_key(hashtable, keys[i]);
		data = hashtable->get_data(hashtable, keys[i]);
		printf("NODE[%d]:\tKEY: %s\tDATA: %s\n", i, key, data);
		free((void *)key);
		free((void *)data);
	}
	ft_free_d((void **)keys);
	ft_free_d((void **)datas);
	freehashtablet(hashtable);
	return (0);
}