/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:26:23 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/08 17:16:33 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

pid_t g_sender_pid;

int	main(void)
{
	g_sender_pid = 0;
	set_signal_action();
	ft_printf("PID: %d\n", getpid());
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
	act.sa_sigaction =&sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static char	byte;

	(void)ucontext;
	set_sender_pid(info->si_pid);
	if (g_sender_pid != info->si_pid)
		return ;
	if (signum == SIGUSR1)
		byte = byte << 1;
	else if (signum == SIGUSR2)
		byte = (byte << 1) | FLAG_1;
	if (++bit == 8)
	{
		bit = 0;
		if (byte == 0)
		{
			display_char(&byte, '\n');
			g_sender_pid = 0;
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		else
			display_char(&byte, byte);
	}
	kill(info->si_pid, SIGUSR1);
}

void	display_char(char *byte, char to_print)
{
	ft_putchar_fd(to_print, 1);
	byte = FLAG_0;
	usleep(100);
}

void	set_sender_pid(pid_t s_pid)
{
	if (g_sender_pid == 0)
		g_sender_pid = s_pid;
}
