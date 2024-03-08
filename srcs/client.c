/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:25:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/07 14:50:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	char	*str;

	set_signal_action();
	if (argc == 3)
	{
		str = argv[2];
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			exit (0);
		i = 0;
		while (str[i])
		{
			send_char(pid, str[i++]);
		}
		send_char(pid, '\0');
	}
	else
		ft_printf("Error: Wrong number of argument\n");
	return (0);
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> (7 - bit++)) & MASK) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		usleep(100);
	}
}

void	set_signal_action(void)
{
	struct sigaction	act;

	act.sa_handler = NULL;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction =&sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGINT, &act, NULL);
}

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (signum == SIGUSR2)
	{
		ft_printf("message is correctly send\n");
		exit (0);
	}
	return ;
}
