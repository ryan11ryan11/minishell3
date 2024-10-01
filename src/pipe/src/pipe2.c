/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:31:08 by junhhong          #+#    #+#             */
/*   Updated: 2024/09/20 18:31:22 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../strhandler/hdrs/strhandler.h"
#include "../hdrs/pipe.h"
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	count_pipe(t_llist *netdata)
{
	int		num_pipe;
	t_argv	*argvt;

	num_pipe = 0;
	while (netdata)
	{
		argvt = (t_argv *)netdata->data;
		if (argvt->oper == 6)
			num_pipe ++ ;
		netdata = netdata->next;
	}
	return (num_pipe);
}

int	**assign_pipe(int num_pipe)
{
	int	**tmp;
	int	i;

	i = 0;
	tmp = (int **)malloc(num_pipe * sizeof(int *));
	if (!tmp)
		return (NULL);
	while (i < num_pipe)
	{
		tmp[i] = (int *)malloc(2 * sizeof(int));
		if (!tmp[i])
		{
			while (i > 0)
				free(tmp[--i]);
			free (tmp);
			return (NULL);
		}
		i ++ ;
	}
	return (tmp);
}
