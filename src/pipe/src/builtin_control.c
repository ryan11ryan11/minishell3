/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:57:20 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/04 11:28:29 by junhhong         ###   ########.fr       */
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

int	builtin_exception(t_argv *argvt)
{
	if (ft_strlcmp_limited(argvt->argv[0], "echo") == 0)
		return (1);
	if (ft_strlcmp_limited(argvt->argv[0], "cd") == 0)
		return (1);
	if (ft_strlcmp_limited(argvt->argv[0], "pwd") == 0)
		return (1);
	if (ft_strlcmp_limited(argvt->argv[0], "export") == 0)
		return (1);
	if (ft_strlcmp_limited(argvt->argv[0], "env") == 0)
		return (1);
	if (ft_strlcmp_limited(argvt->argv[0], "unset") == 0)
		return (1);
	return (0);
}

int	builtin_exception2(char *arr)
{
	if (ft_strlcmp_limited(arr, "echo") == 0)
		return (1);
	if (ft_strlcmp_limited(arr, "cd") == 0)
		return (1);
	if (ft_strlcmp_limited(arr, "pwd") == 0)
		return (1);
	if (ft_strlcmp_limited(arr, "export") == 0)
		return (1);
	if (ft_strlcmp_limited(arr, "env") == 0)
		return (1);
	if (ft_strlcmp_limited(arr, "unset") == 0)
		return (1);
	return (0);
}

int	ft_strcmp2(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++ ;
	}
	return (0);
}

int	builtin(t_argv *argvt, t_info *info, char *line)
{
	if (ft_strlcmp_limited(argvt->argv[0], "echo") == 0)
		return (ft_echo(argvt, line));
	if (ft_strlcmp_limited(argvt->argv[0], "cd") == 0)
		return (ft_cd(argvt, info));
	if (ft_strlcmp_limited(argvt->argv[0], "pwd") == 0)
		return(ft_pwd());
	if (ft_strlcmp_limited(argvt->argv[0], "export") == 0)
		return(ft_export(info, argvt));
	if (ft_strlcmp_limited(argvt->argv[0], "env") == 0)
		return(ft_env(info, argvt));
	if (ft_strlcmp_limited(argvt->argv[0], "unset") == 0)
		return(ft_unset(info, argvt));
	return (0);
}

int	count_arg(t_argv *argvt)
{
	int	i;

	i = 0;
	while (argvt->argv[i] != NULL)
		i++;
	return (i);
}
