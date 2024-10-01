/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlistclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:12:53 by junhhong          #+#    #+#             */
/*   Updated: 2024/09/18 20:26:54 by junhhong         ###   ########.fr       */
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

void	envlistclear(t_envlist *envlist)
{
	t_envlist	*tmp;

	while (envlist != NULL)
	{
		tmp = envlist->next;
		free(envlist->value);
		free(envlist);
		envlist = tmp;
	}
}
