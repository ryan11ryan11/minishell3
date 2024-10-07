/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:47:21 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/04 11:26:33 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"
#include "../hdrs/pipe.h"
#include <unistd.h>

char	*remove_quo(char *arr)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	j = 0;
	i = 0;
	if (ft_strchr(arr, '"') != NULL || ft_strchr(arr, '\'') != NULL)
	{
		len = ft_strlen(arr) - 2;
		new = (char *)malloc(sizeof(char) * (len + 1));
		new[len] = '\0';
		while (arr[i])
		{
			while (arr[i] == '"' || arr[i] == '\'')
				i ++ ;
			new[j] = arr[i];
			i ++ ;
			j ++ ;
		}
		free (arr);
	}
	return (new);
}

void	fix_arr(char **arr)
{
	int		i;
	char	*new;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_strchr(arr[i], '"') != NULL || ft_strchr(arr[i], '\'') != NULL)
		{
			new = remove_quo(arr[i]);
			arr[i] = new;
		}
		i ++ ;
	}
}

int	add_to_list(char **arr, t_info *info)
{
	int	i;

	i = 1;
	while (arr[i])
	{
		if (name_check(arr[i], info->envlist, info) != -1)
			add_newblock(&info->envlist, arr[i], info);
		i ++ ;
	}
	return (1);
}

int	ft_export(t_info *info, char *line)
{
	char	**new_arr;

	new_arr = new_arr_maker(line);
	if (new_arr[1] == NULL || ft_strlcmp_limited(new_arr[1], "|") == 0)
	{
		print_all(info->envlist);
		doublearr_free(&new_arr);
		return (0);
	}
	fix_arr(new_arr);
	add_to_list(new_arr, info);
	envp_maker(info);
	doublearr_free(&new_arr);
	return (0);
}
