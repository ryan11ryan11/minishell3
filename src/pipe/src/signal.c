/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:31:40 by junhhong          #+#    #+#             */
/*   Updated: 2024/09/21 12:34:07 by junhhong         ###   ########.fr       */
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
#include <termios.h>
#include <signal.h>
#include <sys/wait.h>
extern volatile sig_atomic_t	g_child;

void	set_terminal_print_on(void)
{
	struct termios	terminal_info;

	tcgetattr(1, &terminal_info);
	terminal_info.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &terminal_info);
}

void	set_terminal_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	ctrl_c(int signum)
{
	(void)signum;
	if (g_child == 0)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		kill(g_child, SIGINT);
}

void	ft_signal(void)
{
	set_terminal_print_off();
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
