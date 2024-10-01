/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/10/01 10:18:17 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

# include "../../../libft/libft.h"
# include "../../strhandler/hdrs/strhandler.h"

typedef struct	s_crds
{
	int	i;
	int	size;
	int	strsize;
}				t_crds;

typedef struct	s_splts
{
	t_cchar	*hrdoc;
	t_cchar	**qts;
	t_cchar	**spln;
	t_cchar	**rdr;
	t_cchar	**splts;
}				t_splqt;

typedef struct	s_info
{
	int		**pipe;
	int		mainpipe[2];
	pid_t	*pid;
	char	**new_envp;
	int		num_pipe;
	int		num_ndata;
	char	**patharr;
	int		env_set;
	int		num_envp;
	int		errcode;
	struct s_envlist	*envlist;
}				t_info;

typedef struct s_envlist
{
	char				*value;
	struct s_envlist	*next;
}	t_envlist;


t_llist	*spliter(t_cchar *str, t_splqt *splt);
///////////////////////////////T_SPLQT///////////////////////////////
t_splqt	*crtsplqtt(char *qts, char *rdr, char *spln, char *splts);
void	*freesplqtt(t_splqt *splqt);
///////////////////////////////T_ARG///////////////////////////////
void	freeargt(void *data);;
///////////////////////////////TOOLS///////////////////////////////
int		cmpsav(t_cchar *str, t_cchar **qts);
int		cmpqts(t_cchar *str, t_cchar **qts);
int		cmpstrv(t_cchar *str, t_cchar **splt);
void	printmatrix(t_cchar **matrix);
void	printllist(void *data);
void    *pmsgsetern(char *msg, int *ern);

#endif