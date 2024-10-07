/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:01:32 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/07 12:13:16 by junhhong         ###   ########.fr       */
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

int		filenum_count(void)
{
	struct dirent	*t_dirent;
	DIR				*tmp;
	int	i;

	tmp = opendir(".");
	i = 1;
	t_dirent = readdir(tmp);
	while (t_dirent != NULL)
	{
		if (t_dirent->d_name[0] == '.')
		{
			t_dirent = readdir(tmp);
			continue;
		}
		i ++;
		t_dirent = readdir(tmp);
	}
	return (i);
}

char	**filearr_maker(int file_num)
{
	char **file_arr;
	
	file_arr = 	(char **)malloc(sizeof(char *) * (file_num + 1));
	file_arr[file_num] = NULL;
	return (file_arr);
}

char	**filename_arr_maker(DIR *dir)
{
	struct dirent	*t_dirent;
	char			**file_name_arr;
	int				file_num;
	int				i;

	i = 0;
	file_num = filenum_count();
	file_name_arr = filearr_maker(file_num);
	t_dirent = readdir(dir);
	while (t_dirent != NULL)
	{
		if (t_dirent->d_name[0] == '.')
		{
			t_dirent = readdir(dir);
			continue;
		}
		file_name_arr[i] = ft_strdup(t_dirent->d_name);
		i ++;
		t_dirent = readdir(dir);
	}
	if (i == 0)
		return (NULL);
	file_name_arr[i] = NULL;
	closedir(dir);
	return (file_name_arr);
}

int	print_directory()
{
	DIR				*dir;
	char			**filename_arr;
	int				i;

	i = 0;
	dir = opendir(".");
	if (!dir)
	{
		perror("Error:");
		return (1);
	}
	filename_arr = filename_arr_maker(dir);
	while(filename_arr[i] != NULL)
	{
		ft_putstr_fd(filename_arr[i], 1);
		write(1, " ", 1);
		i ++;
	}
	return (0);
}

int	print_argv(t_argv *argvt, int i)
{
	while (argvt->argv[i] != NULL)
	{
		if (ft_strlcmp_limited(argvt->argv[i], "*") == 0)
		{
			i ++ ;
			print_directory();
		}
		if (argvt->argv[i] == NULL)
			return (1);
		ft_putstr_fd(argvt->argv[i], 1);
		if (argvt->argv[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i ++ ;
	}
}

int	ft_echo(t_argv *argvt, char *line)
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
	print_argv(argvt, i);
	if (option == 0)
		write (1, "\n", 1);
	doublearr_free(&argva);
	return (0);
}
