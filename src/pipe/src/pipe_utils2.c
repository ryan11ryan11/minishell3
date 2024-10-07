/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:39:42 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/07 13:18:32 by junhhong         ###   ########.fr       */
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

pid_t	*assign_pid(int num_args)
{
	pid_t	*new_pid;
	int		i;

	i = 0;
	new_pid = (pid_t *)malloc(sizeof(pid_t) * num_args);
	if (!new_pid)
		return (NULL);
	while (i < num_args)
	{
		new_pid[i] = -1;
		i ++ ;
	}
	return (new_pid);
}

char	*absolute_path(t_llist *ndata)
{
	t_argv	*argvt;
	
	argvt = (t_argv *)ndata->data;
	if (access(argvt->argv[0], X_OK) == 0)
		return ((char *)argvt->argv[0]);
	return (NULL);
}

char	*pathfinder(char *command, t_info *info, t_llist *ndata)
{
	char	*slashadded;
	char	*commandadded;
	int		i;
	char	*tmp;

	i = 0;
	if (!info->patharr || !command || !info->patharr)
		return (NULL);
	tmp = absolute_path(ndata);
	if (tmp != NULL)
		return (ft_strdup(tmp));
	while (info->patharr[i] != NULL)
	{
		slashadded = slashadd(info->patharr[i]);
		if (!slashadded)
			return (NULL);
		commandadded = commandadd(slashadded, command);
		free(slashadded);
		if (!commandadded || access(commandadded, X_OK) == 0)
			return (commandadded);
		free(commandadded);
		i ++ ;
	}
	return (NULL);
}

void	count_ndata(t_llist *ndata, t_info *info)
{
	int	i;

	i = 0;
	while (ndata)
	{
		i ++ ;
		ndata = ndata->next;
	}
	info->num_ndata = i;
}

void	doublearr_free(char ***arr)
{
	int	i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while ((*arr)[i] != NULL)
	{
		free((*arr)[i]);
		i ++ ;
	}
	free (*arr);
	*arr = NULL;
}

char	*ft_get_env(t_info *info)
{
	t_envlist	*n_envlist;

	n_envlist = info->envlist;
	while(n_envlist)
	{
		if (n_envlist->value[0] == 'P' && n_envlist->value[1] == 'A' 
		&& n_envlist->value[2] == 'T' && n_envlist->value[3] == 'H' 
		&& n_envlist->value[4] == '=' && n_envlist->value[5] == '/')
			return (n_envlist->value);
		n_envlist = n_envlist->next;
	}
	return (NULL);
}

void	info_setting(t_llist *ndata, t_info *info)
{
	char	*originalpath;
	char	*fullpath;

	originalpath = ft_get_env(info);
	if (!originalpath)
		info->patharr = NULL;
	else
	{
		fullpath = ft_strdup(originalpath);
		info->patharr = ft_split(fullpath, ':');
		free(fullpath);
	}
	info->num_pipe = count_pipe(ndata);
	count_ndata(ndata, info);
	info->pid = assign_pid(info->num_ndata);
	info->pipe = assign_pipe(info->num_pipe);
	pipe(info->mainpipe);
	init_pipe(info);
}
