/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprimes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:46:03 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/24 20:13:18 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

static void	*crtint(unsigned long num)
{
	unsigned long	*tmp;

	tmp = malloc(sizeof(unsigned long));
	*tmp = num;
	return ((void *)tmp);
}

static t_llist	*setprimesllist(t_uchar *primearr, t_ulong num)
{
	t_uint	bit;
	t_ulong	i;
	t_llist	*primenums;

	primenums = NULL;
	i = 0;
	while (i * FT_BIT_MAX <= num)
	{
		bit = 0;
		while (bit < FT_BIT_MAX)
		{
			if (i * FT_BIT_MAX + bit > num)
				break ;
			if (getbit(&(primearr[i]), bit))
				llistadd_back(&primenums, llistnewnode(
						crtint(i * FT_BIT_MAX + bit)));
			++bit;
		}
		++i;
	}
	return (primenums);
}

t_llist	*ft_getprimes(unsigned long num)
{
	t_uchar			*primearr;
	t_llist			*primenums;

	if (num < 2)
		return (NULL);
	primearr = ft_getmarkprimes(num);
	if (!primearr)
		return (NULL);
	primenums = setprimesllist(primearr, num);
	free(primearr);
	return (primenums);
}

// void	printdata(void *data)
// {
// 	printf("PRIME NUMBER:\t%d\n", *(int *)data);
// }

// int	main()
// {
// 	int 	num = 15;
// 	t_llist	*llst;

// 	llst = ft_getprimes(num);
// 	llistiter(llst, printdata);
// 	llistclear(&llst, free);
// 	return (0);
// }