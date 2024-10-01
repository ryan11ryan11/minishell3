/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:01:32 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/01 10:45:57 by junhhong         ###   ########.fr       */
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

char	**argv_maker(char *line)
{
	char	**argv;

	argv = ft_split(line, ' ');
	return (argv);
}

int	ft_strcmp3(const char *s1, const char *s2, int size)
{
	int	i;

	i = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && i < size)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (1);
		i ++ ;
	}
	return (0);
}

int	all_n(char *txt, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (-1);
	while (i < len)
	{
		if (i > 0 && txt[i] != 'n')
			return (-1);
		i ++ ;
	}
	return (1);
}

void	ft_echo(t_argv *argvt, char *line)
{
	int		option;
	int		i;
	int		len;
	char	**argva;

	i = 1;
	option = 0;
	argva = argv_maker(line);
	len = ft_strlen(argva[i]);
	while (argvt->argv[i] && all_n((char *)argvt->argv[i], len) \
	== 1 && (ft_strcmp3(argvt->argv[i], "-n", 2) == 0))
	{
		i ++ ;
		len = ft_strlen(argva[i]);
		option = 1;
	}
	while (argvt->argv[i] != NULL)
	{
		if (argvt->argv[i] == NULL)
			return ;
		ft_putstr_fd(argvt->argv[i++], 1);
		ft_putstr_fd(" ", 1);
	}
	if (option == 0)
		write (1, "\n", 1);
	doublearr_free(&argva);
}

void	ft_echo2(t_argv *argvt, char *line, t_info *info)
{
	int		i;
	int		len;
	char	**argva;

	i = 1;
	argva = argv_maker(line);
	len = ft_strlen(argva[i]);
	while (argvt->argv[i] && all_n((char *)argvt->argv[i], len) \
	== 1 && (ft_strcmp3(argvt->argv[i], "-n", 2) == 0))
	{
		i ++ ;
		len = ft_strlen(argva[i]);
	}
	while (argvt->argv[i] != NULL)
	{
		if (argvt->argv[i] == NULL)
			return ;
		i ++ ;
	}
	info->errcode = 0;
	doublearr_free(&argva);
}
