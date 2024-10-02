/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:41:00 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/02 17:27:13 by junhhong         ###   ########.fr       */
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

void	parent_process(t_info *info, t_llist *ndata, int i)
{
	t_argv	*prv_argvt;
	t_argv	*argvt;

	prv_argvt = NULL;
	if (ndata->previous)
		prv_argvt = ndata->previous->data;
	argvt = ndata->data;
	g_child = i + 1;
	printf("wait for child\n");
	waitpid(info->pid[i], NULL, 0);
	g_child = 0;
	if (i == info->num_pipe && ((argvt->oper == 6) | (prv_argvt && prv_argvt->oper == 6)))
	{
		close(info->pipe[i - 1][1]);
	}
	if (i > 0 && i != info->num_pipe && ((argvt->oper == 6) | (prv_argvt && prv_argvt->oper == 6)))
	{
		printf("info->pipe[%d][0] closed\n",i-1);
		close(info->pipe[i - 1][0]);
	}
	if (i != info->num_pipe && ((argvt->oper == 6) || (prv_argvt && prv_argvt->oper == 6)))
	{
		printf("info->pipe[%d][1] closed\n",i);
		close(info->pipe[i][1]);
	}
	//printf("wait for child\n");
	// waitpid(info->pid[i], NULL, 0);
	printf("hello\n");
	// if (i == info->num_pipe && ((argvt->oper == 6) | (prv_argvt && prv_argvt->oper == 6)))
	// {
	// 	close(info->pipe[i - 1][1]);
	// 	return ;
	// }
	// if (i > 0 && ((argvt->oper == 6) | (prv_argvt && prv_argvt->oper == 6)))
	// 	close(info->pipe[i - 1][0]);
	// if (i != info->num_pipe && ((argvt->oper == 6) \
	// || (prv_argvt && prv_argvt->oper == 6)))
	// {
	// 	printf("pipe[%d][1] closed\n");
	// 	close(info->pipe[i][1]);
	// }
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
	{
		ft_cd(argvt, info);
		return (-1);
	}
	if (ft_strlcmp_limited(argvt->argv[0], "env") == 0)
		ft_env2(info, argvt);
	if (ft_strlcmp_limited(argvt->argv[0], "pwd") == 0)
		ft_pwd2(info);
	if (ft_strlcmp_limited(argvt->argv[0], "echo") == 0)
		ft_echo2(argvt, line, info);
	return (1);
}

void	exec_command(t_llist *ndata, t_info *info, char *line)
{
	int		i;
	t_argv	*argvt;

	t_argv	*prv_argvt;

	argvt = (t_argv *)ndata->data;
	if (exec_command_errcheck(ndata, info) == -1
	|| parent_process_exec(argvt, info, line) == -1)
	{
		if(info->errcode != 127)
			info->errcode = 1;
		return ;
	}
	i = -1;
	while (ndata)
	{
		i ++ ;
		argvt = (t_argv *)ndata->data;
		printf("i:%d\n",i);
		info->pid[i] = fork();
		if (info->pid[i] == 0)
		{
			printf("#1\n");
			child_process(ndata, info, i, line);
		}
		else
		{
			printf("#2\n");
			parent_process(info, ndata, i);
			printf("#3\n");
			ndata = ndata->next;
		}
	}
}
