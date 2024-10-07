/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:56:01 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/07 13:14:49 by junhhong         ###   ########.fr       */
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

int	no_argument(t_argv *argvt)
{
	char	*home;

	if (argvt->argv[1] == NULL)
	{
		home = getenv("HOME");
		if (chdir(home) == -1)
		{
			perror("Error:");
			return (errno);
		}
		return (0);
	}
	return (-1);
}

int	slash_up(t_argv *argvt, char *input)
{	
	if (input[0] == '/' || strcmp(input, "..") == 0)
	{
		if (chdir(argvt->argv[1]) == -1)
		{
			perror("Error:");
			return (errno);
		}
		else
			return (0);
	}
	return (-1);
}

int	ft_cd(t_argv *argvt)
{
	char	*new_path;
	char	*input;
	int		result;

	input = (char *)argvt->argv[1];
	result = no_argument(argvt);
	if (result >= 0)
		return (result);
	result = slash_up(argvt, input);
	if (result >= 0)
		return (result);
	new_path = new_path_maker(input);
	if (chdir(new_path) == -1)
	{
		perror("Error:");
		free (new_path);
		return (1);
	}
	free (new_path);
	return (0);
}
