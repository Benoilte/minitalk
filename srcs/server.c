/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:26:23 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/11 14:37:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

pid_t	g_sender_pid;

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: Wrong number of argument\n");
		exit (EXIT_FAILURE);
	}
	g_sender_pid = 0;
	set_signal_action();
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}

void	set_signal_action(void)
{
	struct sigaction	act;

	act.sa_handler = NULL;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit_index;
	static char	current_char;

	(void)ucontext;
	set_sender_pid(info->si_pid);
	if (g_sender_pid != info->si_pid)
		return ;
	if (signum == SIGUSR1)
		current_char = current_char << 1;
	else if (signum == SIGUSR2)
		current_char = (current_char << 1) | FLAG_1;
	if (++bit_index == 8)
	{
		bit_index = 0;
		if (current_char == 0)
		{
			display_char('\n');
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		else
			display_char(current_char);
		current_char = FLAG_0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	display_char(char to_print)
{
	ft_putchar_fd(to_print, 1);
	if (to_print == '\n')
		g_sender_pid = 0;
	usleep(100);
}

void	set_sender_pid(pid_t s_pid)
{
	if (g_sender_pid == 0)
		g_sender_pid = s_pid;
}
