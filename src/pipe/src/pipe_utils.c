/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:35:18 by junhhong          #+#    #+#             */
/*   Updated: 2024/09/20 17:41:58 by junhhong         ###   ########.fr       */
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

int	count_envplist(t_info *info)
{
	int			i;
	t_envlist	*tmp;

	tmp = info->envlist;
	i = 0;
	while (tmp != NULL)
	{
		i ++ ;
		tmp = tmp->next;
	}
	return (i);
}

int	envp_setting(t_info *info)
{
	if (info->new_envp != NULL)
	{
		doublearr_free(&info->new_envp);
		info->new_envp = NULL;
	}
	info->num_envp = count_envplist(info);
	info->new_envp = (char **)malloc(sizeof(char *) * (info->num_envp + 1));
	info->new_envp[info->num_envp] = NULL;
	if (!info->new_envp)
	{
		perror("envp error");
		return (-1);
	}
	return (1);
}

void	envp_maker(t_info *info)
{
	int			i;
	t_envlist	*tmp;

	i = 0;
	if (envp_setting(info) == -1)
		return ;
	if (info->envlist != NULL)
		tmp = info->envlist;
	while (i < info->num_envp)
	{
		info->new_envp[i] = ft_strdup(tmp->value);
		if (!info->new_envp[i])
		{
			doublearr_free(&info->new_envp);
			return ;
		}
		i ++ ;
		tmp = tmp->next;
	}
}

char	*slashadd(char *path)
{
	char	*new;
	int		i;

	i = 0;
	while (path[i])
		i ++ ;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	ft_strlcpy(new, path, i + 1);
	new[i] = '/';
	new[i + 1] = '\0';
	return (new);
}

char	*commandadd(char *slashadded, char *command)
{
	int		len_slashadded;
	int		len_command;
	char	*result;

	len_slashadded = ft_strlen(slashadded);
	len_command = ft_strlen(command);
	result = (char *)malloc((len_slashadded + len_command + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, slashadded, len_slashadded + 1);
	ft_strlcpy(result + len_slashadded, command, len_command + 1);
	result[len_slashadded + len_command] = '\0';
	return (result);
}
