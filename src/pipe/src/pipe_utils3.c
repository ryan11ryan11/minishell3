/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:41:00 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/04 11:28:38 by junhhong         ###   ########.fr       */
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

extern volatile sig_atomic_t	g_child;

void	child_process(t_llist *ndata, t_info *info, int i, char *line)
{
	char	*command;
	char	*path;
	t_argv	*prv_argvt;
	t_argv	*argvt;

	argvt = ndata->data;
	prv_argvt = NULL;
	if (ndata->previous)
		prv_argvt = ndata->previous->data;
	if ((argvt->oper == 6) || (prv_argvt && prv_argvt->oper == 6))
		exec_pipe(info, i);
	if (argvt->argv[0])
		command = (char *)argvt->argv[0];
	else
		perror("error");
	builtin_situation(argvt, info, line);
	path = pathfinder(command, info, ndata);
	if (!path)
		error_exit(command, 1);
	if (path && (char *const *)argvt->argv && info->new_envp)
	{
		envp_maker(info);
		execve(path, (char *const *)argvt->argv, info->new_envp);
		error_exit("execve error", 1);
	}
}

void	parent_process(t_info *info)
{
	int	j;
	int	status;
	int	exit_code;

	j = 0;
	while(j < info->num_pipe)
	{
		close(info->pipe[j][0]);
		close(info->pipe[j][1]);
		j ++;
	}
	j = 0;
	while(j < info->num_ndata)
	{
		waitpid(info->pid[j], &status, 0);
		j ++;
	}
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		info->errcode = exit_code;
	}
}

int	exec_command_errcheck(t_llist *ndata, t_info *info)
{
	t_argv	*argvt;

	argvt = (t_argv *)ndata->data;
	if (ft_get_env(info, "PATH=/") == NULL &&
	ft_strlcmp_limited(argvt->argv[0], "export") != 0)
	{
		info->errcode = 127;
		ft_putstr_fd("command not found\n", 1);
		return (-1);
	}
	if (all_component_check(ndata, info) == -1)
	{
		perror("ERROR");
		return (-1);
	}
	else
		return (1);
}

int	parent_process_exec(t_argv *argvt, t_info *info, char *line)
{
	if (ft_strlcmp_limited(argvt->argv[0], "export") == 0)
		ft_export(info, line);
	if (ft_strlcmp_limited(argvt->argv[0], "unset") == 0)
		ft_unset(info, argvt);
	if (ft_strlcmp_limited(argvt->argv[0], "cd") == 0)
		return (ft_cd(argvt, info));
	if (ft_strlcmp_limited(argvt->argv[0], "env") == 0)
		ft_env(info, argvt);
	if (ft_strlcmp_limited(argvt->argv[0], "pwd") == 0)
		ft_pwd();
	if (ft_strlcmp_limited(argvt->argv[0], "echo") == 0)
		ft_echo(argvt, line);
	return (1);
}

int		is_pipe(t_llist *ndata)
{
	t_argv *argvt;

	while(ndata)
	{
		argvt = (t_argv *)ndata->data;
		if (argvt->oper == 6)
			return (1);
		ndata = ndata->next;
	}
	return (-1);
}

void	exec_command(t_llist *ndata, t_info *info, char *line)
{
	int		i;
	t_argv	*argvt;
	t_argv	*prv_argvt;

	argvt = (t_argv *)ndata->data;
	if (exec_command_errcheck(ndata, info) == -1)
		return ;
	if (is_pipe(ndata) == -1 && builtin_exception(argvt) == 1)
	{
		info->errcode = parent_process_exec(argvt, info, line);
		return ;
	}
	i = -1;
	while (ndata)
	{
		i ++ ;
		argvt = (t_argv *)ndata->data;
		info->pid[i] = fork();
		if (info->pid[i] == 0)
			child_process(ndata, info, i, line);
		ndata = ndata->next;
	}
	parent_process(info);
}
