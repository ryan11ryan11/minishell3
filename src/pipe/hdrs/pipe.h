/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:09:11 by junhhong          #+#    #+#             */
/*   Updated: 2024/10/04 12:10:31 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ECHOCTL
#define ECHOCTL 0x00000040
#endif

#include <errno.h>
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../netdata/hdrs/netdata.h"
#include "../../strhandler/hdrs/strhandler.h"
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <signal.h>
#include <sys/wait.h>
#include <dirent.h>
#define PATH_MAX 4096

int		count_pipe(t_llist *netdata);
int		**assign_pipe(int num_pipe);
void	init_pipe(t_info *info);
void	exec_pipe(t_info *info, int i);
void	ft_pipe(t_llist *ndata, t_info *info);
void	free_pipe(t_info *info);
int		count_envp(char *envp[]);
void	envp_maker(t_info *info);
char	*slashadd(char *path);
char	*commandadd(char *slashadded, char *command);
pid_t	*assign_pid(int num_args);
char	*pathfinder(char *command, t_info *info, t_llist *ndata);
char	*absolute_path(t_llist *ndata, t_info *info);
void	count_ndata(t_llist *ndata, t_info *info);
void	doublearr_free(char ***arr);
void	info_setting(t_llist *ndata, t_info *info);
int		all_component_check(t_llist *ndata, t_info *info);
void	exec_command(t_llist *ndata, t_info *info, char *line);
void	all_pipe_close(t_info *info);
void	child_process(t_llist *ndata, t_info *info, int i, char *line);
void	parent_process(t_info *info);
int		ft_cd(t_argv *argvt, t_info *info);
int		no_argument(t_argv *argvt, t_info *info);
char	*new_path_maker(char *input);
int		ft_strcmp2(const char *s1, const char *s2);
int		builtin_exception(t_argv *argvt);
int		builtin_exception2(char *arr);
int		ft_strcmp2(const char *s1, const char *s2);
int		builtin(t_argv *argvt, t_info *info, char *line);
int 	ft_echo(t_argv *argvt, char *line);
int		ft_pwd(void);
int		count_arg(t_argv *argvt);
void	envlist_addback(t_envlist **lst, t_envlist *new);
t_envlist	*envlist_new(void *content);
int		env_size_checker(char *env[]);
int		envlistmaker(t_info *info, char *env[]);
t_envlist	*ft_envlast(t_envlist *lst);
int		ft_env(t_info *data, t_argv *argvt);
int		ft_unset(t_info *info, t_argv *argvt);
void	envlistclear(t_envlist *envlist);
int		ft_strlcmp_limited(const char *s1, const char *s2);
void	ft_signal(void);
void	heredoc_signal(void);

char	*remove_quo(char *arr);
void	fix_arr(char **arr);
int		add_to_list(char **arr, t_info *info);
int		ft_export(t_info *info, char *line);
int		is_duplicate(char *name, t_envlist *envlist, char *arr, t_info *info);
char	*quo_add(char *arr);
void	print_all(t_envlist *envlist);
int		underbar_alphabet(char *msg, t_info *info);
int		is_empty(char *msg, t_info *info);
int		is_alphabet(char *name, t_info *info);
int		name_check(char *arr, t_envlist *envlist, t_info *info);
void	ft_envlist_back(t_envlist **lst, t_envlist *new);
int		add_newblock(t_envlist **envlist, char *content, t_info *info);
int		newarr_counter(char *line);
char 	**new_arr_init(char *line);
char	*make_arr(char *line, int i, int j);
int		add_arr(char **arr, char *new);
int		quo_jump(int *i, int *j, char *line);
char	**new_arr_maker(char *line);
int		add_truespace(char *line, int *i, int *num_truespace);
void	builtin_situation(t_argv *argvt, t_info *info, char *line);
void	error_exit(char *msg, int error_number);

void	set_terminal_print_off(void);
void	set_terminal_print_on(void);
//void	ft_env2(t_info *data, t_argv *argvt);
//int		ft_pwd2(t_info *info);
//void	ft_echo2(t_argv *argvt, char *line, t_info *info);
char	*ft_get_env(t_info *info, char *name);
