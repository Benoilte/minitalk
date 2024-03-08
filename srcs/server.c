/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:26:23 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/08 11:46:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_code code;

int	main(void)
{
	code.n = 0;
	code.c = FLAG_0;
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
	(void)ucontext;
	code.n++;
	if (signum == SIGUSR1)
		code.c = code.c << 1;
	else if (signum == SIGUSR2)
		code.c = (code.c << 1) | FLAG_1;
	if (code.n == 8)
	{
		code.n = 0;
		if (code.c == 0)
		{
			ft_printf("\n");
			code.c = FLAG_0;
			usleep(100);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		else
		{
			ft_printf("%c", code.c);
			code.c = FLAG_0;
		}
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}
