/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:27:53 by junhhong          #+#    #+#             */
/*   Updated: 2024/09/19 13:19:03 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"
#include "../hdrs/pipe.h"
#include <unistd.h>

t_envlist	*ft_envlast(t_envlist *lst)
{
	t_envlist	*temp;

	temp = lst;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	envlist_addback(t_envlist **lst, t_envlist *new)
{
	t_envlist	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!temp)
	{
		(*lst) = new;
		return ;
	}
	temp = ft_envlast(*lst);
	temp->next = new;
}

t_envlist	*envlist_new(void *content)
{
	t_envlist	*newlist;

	newlist = (t_envlist *)malloc(sizeof(t_envlist));
	if (!newlist)
		return (NULL);
	newlist -> value = ft_strdup((char *)content);
	newlist -> next = NULL;
	return (newlist);
}

int	env_size_checker(char *env[])
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i ++ ;
	return (i);
}

int	envlistmaker(t_info *info, char *env[])
{
	int			env_size;
	int			i;
	t_envlist	*last_block;

	i = 0;
	env_size = env_size_checker(env);
	info->envlist = envlist_new(env[0]);
	if (info->envlist == NULL)
		return (0);
	i = 1;
	while (i < env_size)
	{
		last_block = (t_envlist *)malloc(sizeof(t_envlist));
		last_block->value = ft_strdup(env[i]);
		last_block->next = NULL;
		envlist_addback(&info->envlist, last_block);
		i ++ ;
	}
	info->env_set = 1;
	return (1);
}
