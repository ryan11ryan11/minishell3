/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:41:00 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/07 18:50:35 by junhhong         ###   ########.fr       */
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
#include <fcntl.h>

extern volatile sig_atomic_t	g_child;

void	case_outfile(t_argv *argvt)
{
	int	fd;

	if (argvt->appnd == 0)
		fd = open(argvt->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (argvt->appnd == 1)
		fd = open(argvt->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close (fd);
}

char	*get_last_word(char *buffer, int index)
{
	char	**split;
	char	*last;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(buffer);
	tmp[index] ='\0';
	split = ft_split(tmp, '\n');
	if (!split)
		return (NULL);
	while(split[i + 1] != NULL)
	{
		printf("split[%d]:%s\n",i,split[i]);
		i ++;
	}
	last = ft_strdup(split[i]);
	printf("i:%d last:%s\n", i,last);
	doublearr_free(&split);
	free(tmp);
	return (last);
}

void	case_heredoc(t_llist *ndata)
{
	char	buffer[2048];
	int		total_byte;
	int		byte_read;
	char	*delimiter;
	char	*last_word;
	t_llist	*next_ndata;
	t_argv 	*next_argvt;

	next_ndata = ndata->next;
	next_argvt = next_ndata->data;
	delimiter = (char *)(next_argvt->argv[0]);
	printf("DELIMITER::%s\n",delimiter);
	total_byte = 0;
	int j = 0;
	while(j < 4)
	{	
		write(1, "OH>", 3);
		byte_read = read(STDIN_FILENO, buffer + total_byte, sizeof(buffer) - total_byte - 1);
		total_byte = total_byte + byte_read;
		last_word = get_last_word(buffer, total_byte - 1);
		printf("last_word:%s delimiter:%s\n",last_word, delimiter);
		if (ft_strlcmp_limited(last_word, delimiter == 0))
		{
			printf("#########broken##############\n");
			break;
		}
		j ++ ;
	}
	buffer[total_byte - 1] = '\0';
	printf("result :: %s\n", buffer);
}


int	case_infile(t_llist *ndata)
{
	int		fd;
	t_argv	*argvt;

	if (!ndata->next)
	{
		ft_putstr_fd("syntax error\n", 2);
		exit (2);
	}
	argvt = ndata->data;
	if (argvt->appnd == 0)
	{
		fd = open(argvt->infile, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close (fd);
	}
	return (0);
}

void	child_process(t_llist *ndata, t_info *info, int i, char *line)
{
	char	*command;
	char	*path;
	t_argv	*prv_argvt;
	t_argv	*argvt;

	argvt = ndata->data;
	if (ndata->previous)
		prv_argvt = ndata->previous->data;
	if (prv_argvt->oper == 1)
		exit (0);
	if (argvt->outfile != NULL)
		case_outfile(argvt);
	if (argvt->infile != NULL)
		case_infile(ndata);
	if (argvt->oper == 1)
		case_heredoc(ndata); // argv[0]이상 있을 경우?
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
	if (ft_get_env(info) == NULL &&
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
		return (ft_cd(argvt));
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
