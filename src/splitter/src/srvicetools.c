/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srvicetools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:42:33 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/07/26 22:29:35 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"
#include <stdio.h>

void	printllist(void *data)
{
	printf("[0]: %d\t[1]: %d\t|%s|\n", ((t_arg *)(data))->x,
		((t_arg *)(data))->size, ((t_arg *)(data))->arg);
}

void	printmatrix(t_cchar **matrix)
{
	if (!matrix)
		return ;
	while (*matrix)
	{
		printf("%s\n", *matrix);
		++matrix;
	}
}
