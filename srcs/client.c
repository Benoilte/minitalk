/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:25:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/11 13:28:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	g_get_signal_back;

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
		{
			ft_printf("Error: Wrong pid format\n");
			exit (EXIT_FAILURE);
		}
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
		g_get_signal_back = 0;
		if (((c >> (7 - bit++)) & MASK) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		wait_signal_back();
		usleep(100);
	}
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
	(void)ucontext;
	(void)info;
	if (signum == SIGUSR1)
		g_get_signal_back = 1;
	else if (signum == SIGUSR2)
	{
		ft_printf("message is correctly send\n");
		exit (0);
	}
	return ;
}

void	wait_signal_back(void)
{
	int	i;

	i = 0;
	while ((i < 3000000) && !g_get_signal_back)
	{
		i += 10;
		usleep(10);
	}
	if (!g_get_signal_back)
	{
		ft_printf("Error: Server is not responding, check the Process ID\n");
		exit (EXIT_FAILURE);
	}
}
