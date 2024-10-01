/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:56:01 by junhhong          #+#    #+#             */
/*   Updated: 2024/09/21 17:57:25 by junhhong         ###   ########.fr       */
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

int	no_argument(t_argv *argvt, t_info *info)
{
	char	*home;

	if (argvt->argv[1] == NULL)
	{
		home = getenv("HOME");
		if (chdir(home) == -1)
		{
			info->errcode = 1;
			perror("chdir failed");
			return (-1);
		}
		else
		{
			info->errcode = 0;
			return (1);
		}
	}
	return (0);
}

int	slash_up(t_argv *argvt, t_info *info, char *input)
{	
	if (input[0] == '/' || strcmp(input, "..") == 0)
	{
		if (chdir(argvt->argv[1]) == -1)
		{
			perror("chdir failed");
			info->errcode = 1;
			return (-1);
		}
		else
		{
			info->errcode = 0;
			return (1);
		}
	}
	return (0);
}

void	ft_cd(t_argv *argvt, t_info *info)
{
	char	*new_path;
	char	*input;

	printf("ft_cd\n");
	input = (char *)argvt->argv[1];
	if (no_argument(argvt, info) || slash_up(argvt, info, input))
		return ;
	new_path = new_path_maker(input);
	if (chdir(new_path) == -1)
	{
		perror("chdir failed");
		info->errcode = 1;
		return ;
	}
	else
		info->errcode = 0;
	free (new_path);
}
