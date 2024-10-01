/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistnewnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:47:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/18 20:06:49 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llist	*llistnewnode(void *data)
{
	t_llist	*tmp;

	tmp = malloc(sizeof(t_llist));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}
