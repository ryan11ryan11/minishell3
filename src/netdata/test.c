/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:42:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/03 15:48:00 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/netdata.h"
#include "../splitter/hdrs/splitter.h"
#include "../../hdrs/commondata.h"
#include <stdio.h>
#include <readline/readline.h>
#include "../pipe/hdrs/pipe.h"
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
volatile sig_atomic_t	g_child;

void	printargvtllist(void *data)
{
	t_argv	*argvt;

	argvt = (t_argv *)data;
	printf("Operation code:\t%d;\tAPP status:\t%d;\n", (int)(argvt->oper), (int)(argvt->appnd));
	printf("Input file:\t%s\nOutput file:\t%s\n", argvt->infile, argvt->outfile);
	printmatrix(argvt->argv);
}

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	case_exit(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i ++ ;
	if (line[i] == 'e' && line[i + 1] == 'x' && line[i + 2] == 'i' \
	&& line[i + 3] == 't')
		return (1);
}

int	terminatation(char *line)
{
	if (case_exit(line) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int				hstsize = 64;
	t_strtosub		tmpt;
	char			*str;
	char			*line;
	t_hashtable		*hst;
	t_llist			*ndata;
	t_llist			*spliterll;
	t_splqt			*splqt;
	t_argv			*argvt;
	t_info			info;

	hst = crthashtable(hstsize);
	tmpt.qts = ft_strdup("\"\'");
	tmpt.substr = ft_split(SUBSTR, SPLTCH);
	tmpt.subend = ft_split(SUBEND, SPLTCH);
	splqt = crtsplqtt(QTS, RDR, SPLN, SPLTS);
	info.env_set = 0;
	info.new_envp = NULL;
	while (1)
	{
		info.errcode = 9999;
		ft_signal();
		line = readline("Pablo Escobar:\t");
		if (line == NULL || terminatation(line) == 1)
		{
			if (info.env_set == 1)
				envlistclear(info.envlist);
			set_terminal_print_on();
			exit(0) ;
		}
		add_history(line);
		if (info.env_set == 0)
			envlistmaker(&info, envp);
		envp_maker(&info);
		str = strhandler(line, &tmpt, hst);
		spliterll = spliter(str, splqt);
		ndata = netdata(str, spliterll, splqt);
		argvt = (t_argv *)(ndata->data);
		info_setting(ndata, &info);
		exec_command(ndata, &info, line);
		printf("End code:%d\n", info.errcode);
		//llistiter(ndata, printargvtllist);
		// if (ndata)
		// 	printmatrix(((t_argv *)(ndata->data))->argv);
		llistclear(&ndata, freeargvt);
		llistclear(&spliterll, freeargt);
		free(line);
		free(str);
		free_pipe(&info); 
		free(info.pid);
		doublearr_free(&info.new_envp);
		doublearr_free(&info.patharr);
	}
	freesplqtt(splqt);
	free(line);
	ft_free_d((void **)tmpt.subend);
	ft_free_d((void **)tmpt.substr);
	free(tmpt.qts);
	freehashtablet(hst);
	return (0);
}
