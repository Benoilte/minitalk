/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:26:23 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/08 14:20:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	main(void)
{
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
	// act.sa_mask = NULL;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction =&sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static char	c;

	(void)ucontext;
	bit++;
	if (signum == SIGUSR1)
		c = c << 1;
	else if (signum == SIGUSR2)
		c = (c << 1) | FLAG_1;
	if (bit == 8)
	{
		bit = 0;
		if (c == 0)
		{
			ft_printf("\n");
			c = FLAG_0;
			usleep(100);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		else
		{
			ft_printf("%c", c);
			c = FLAG_0;
		}
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}
