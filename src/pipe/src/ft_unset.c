/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:08:27 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/04 11:28:16 by junhhong         ###   ########.fr       */
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

void	delete_node(t_envlist **head, t_envlist *node_to_delete)
{
	t_envlist	*temp;
	t_envlist	*current;

	if (head == NULL || *head == NULL || node_to_delete == NULL)
		return ;
	if (*head == node_to_delete)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return ;
	}
	current = *head;
	while (current->next != NULL && current->next != node_to_delete)
		current = current->next;
	if (current->next == NULL)
		return ;
	current->next = node_to_delete->next;
	free(node_to_delete);
}

t_envlist	*find_value_envlist(t_envlist *envlist, char *arr)
{
	t_envlist	*tmp;
	char		**input;

	tmp = envlist;
	while (tmp != NULL)
	{
		input = ft_split(tmp->value, '=');
		if (!input)
			return (NULL);
		if (ft_strlcmp_limited(input[0], arr) == 0)
			return (tmp);
		doublearr_free(&input);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_unset(t_info *info, t_argv *argvt)
{
	int			i;
	t_envlist	*tmp;

	i = 0;
	while (argvt->argv[i])
	{
		tmp = find_value_envlist(info->envlist, (char *)argvt->argv[i]);
		if (tmp != NULL)
			delete_node(&info->envlist, tmp);
		i ++ ;
	}
	return (0);
}
