/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:38:21 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/03 14:59:10 by junhhong         ###   ########.fr       */
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

void	pipe_all_close(t_info *info)
{
	int	i;

	i = 0;
	while(i < info->num_pipe)
	{			
		close(info->pipe[i][0]);
		close(info->pipe[i][1]);
		i ++;
	}
}

void	exec_pipe(t_info *info, int i)
{
	if (i == 0)
	{
		dup2(info->pipe[0][1], STDOUT_FILENO);
		pipe_all_close(info);
		return ;
	}
	if (i == info->num_pipe)
	{
		dup2(info->pipe[i - 1][0], STDIN_FILENO);
		pipe_all_close(info);
		return ;
	}
	dup2(info->pipe[i - 1][0], STDIN_FILENO);
	dup2(info->pipe[i][1], STDOUT_FILENO);
	pipe_all_close(info);
	return ;
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
