/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:38:21 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/01 15:48:30 by junhhong         ###   ########.fr       */
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

void	init_pipe(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_pipe)
	{
		if (pipe(info->pipe[i]) == -1)
		{
			perror("pipe init failed");
			exit (1);
		}
		i ++ ;
	}
}

void	exec_pipe(t_info *info, int i)
{
	if (i > 0)
	{
		dup2(info->pipe[i - 1][0], STDIN_FILENO);
		close(info->pipe[i - 1][0]);
	}
	if (i != info->num_pipe)
	{
		dup2(info->pipe[i][1], STDOUT_FILENO);
		close(info->pipe[i][1]);
		close(info->pipe[i][0]);
	}
}

void	ft_pipe(t_llist *ndata, t_info *info)
{
	int		i;
	t_argv	*argvt;

	i = 0;
	init_pipe(info);
	while (ndata)
	{
		argvt = (t_argv *)ndata->data;
		if (argvt->oper == 6)
		{
			exec_pipe(info, i);
			i ++ ;
		}
		ndata = ndata->next;
	}
}

void	free_pipe(t_info *info)
{
	int	i;

	i = 0;
	if (info->pipe == NULL)
		return ;
	while (i < info->num_pipe)
	{
		free(info->pipe[i]);
		i ++ ;
	}
	free(info->pipe);
}
