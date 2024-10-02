/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:38:21 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/02 17:01:59 by junhhong         ###   ########.fr       */
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
	if (i == 0)
	{
		close(info->pipe[0][0]);
		dup2(info->pipe[0][1], STDOUT_FILENO);
		close(info->pipe[0][1]);
		return ;
	}
	if (i == info->num_pipe)
	{
		close(info->pipe[i - 1][1]);
		dup2(info->pipe[i - 1][0], STDIN_FILENO);
		close(info->pipe[i - 1][0]);
		return ;
	}
	close(info->pipe[i - 1][1]);
	dup2(info->pipe[i - 1][0], STDIN_FILENO);
	close(info->pipe[i - 1][0]);
	close(info->pipe[i][0]);
	dup2(info->pipe[i][1], STDOUT_FILENO);
	close(info->pipe[i][1]);
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
