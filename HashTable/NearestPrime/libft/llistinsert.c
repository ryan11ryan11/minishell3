/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llistinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:51:16 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/19 20:58:27 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist	*llistinsert(t_llist *pos, t_llist *newnode)
{
	if (!pos)
	{
		pos = newnode;
		return (pos);
	}
	if (pos->next)
		pos->next->previous = newnode;
	newnode->previous = pos;
	newnode->next = pos->next;
	pos->next = newnode;
	return (newnode);
}
