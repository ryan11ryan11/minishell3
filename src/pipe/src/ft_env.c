/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:46:30 by junhhong          #+#    #+#             */
/*   Updated: 2024/09/21 18:11:57 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../strhandler/hdrs/strhandler.h"
#include "../hdrs/pipe.h"
#include <stdio.h>
#include <readline/readline.h>

void	ft_env2(t_info *data, t_argv *argvt)
{
	t_envlist	*tmp;

	tmp = data->envlist;
	if (argvt->argv[1])
	{
		data->errcode = 127;
		return ;
	}
	data->errcode = 0;
}

void	ft_env(t_info *data, t_argv *argvt)
{
	t_envlist	*tmp;

	tmp = data->envlist;
	if (argvt->argv[1])
	{
		ft_putstr_fd("env: No such file or directory\n", 2);
		data->errcode = 1;
		return ;
	}
	while (tmp != NULL)
	{
		if (ft_strchr(tmp->value, '=') != NULL)
		{
			write(1, tmp->value, ft_strlen(tmp->value));
			write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
	data->errcode = 0;
}
