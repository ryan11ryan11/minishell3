/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:26:03 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/03 17:27:44 by junhhong         ###   ########.fr       */
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

int	all_component_check(t_llist *ndata, t_info *info)
{
	t_llist	*tmp;
	t_argv	*argvt;
	char	*command;
	char	*path;

	tmp = ndata;
	while (tmp)
	{
		argvt = (t_argv *)ndata->data;
		if (builtin_exception(argvt) == 1)
			return (0);
		if (argvt->argv[0])
			command = (char *)argvt->argv[0];
		else
			return (-1);
		path = pathfinder(command, info, ndata);
		if (!path)
			return (-1);
		free (path);
		tmp = tmp->next;
	}
	return (0);
}

void	all_pipe_close(t_info *info)
{
	int	i;

	i = info->num_pipe; 
	while (i > 0)
	{
		close(info->pipe[i][0]);
		close(info->pipe[i][1]);
		i -- ;
	}
}

char	*new_path_maker(char *input)
{
	char	currentpath[4096];
	char	*newpath;
	int		len;
	int		len_current;

	if (getcwd(currentpath, 4096) == NULL)
	{
		perror("getcwd failed");
		return (NULL);
	}
	len = ft_strlen(currentpath) + ft_strlen(input) + 2;
	newpath = (char *)malloc(sizeof(char) * len);
	if (!newpath)
		return (NULL);
	len_current = ft_strlen(currentpath);
	ft_memset(newpath, 0, len);
	ft_strlcat(newpath, currentpath, len);
	newpath[len_current] = '/';
	newpath[len_current + 1] = '\0';
	ft_strlcat(newpath, input, len);
	return (newpath);
}

void	error_exit(char *msg, int error_number)
{
	perror(msg);
	exit(error_number);
}

void	builtin_situation(t_argv *argvt, t_info *info, char *line)
{
	int	code;

	code = 0;
	if (builtin_exception(argvt) == 1)
	{
		code = builtin(argvt, info, line);
		exit(code);
	}
}
