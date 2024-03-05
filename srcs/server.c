/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:26:23 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/05 23:00:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

	act.sa_flags = 0;
	act.sa_mask = 0;
	act.sa_handler = 0;
	act.sa_sigaction = 0;
	act.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGINT, &act, NULL);
}

void	sig_handler(int signum)
{
	code.n++;
	if (signum == SIGUSR1)
		code.c = code.c << 1;
	else if (signum == SIGUSR2)
		code.c = (code.c << 1) | FLAG_1;
	if (code.n == 8)
	{
		ft_printf("%c", code.c);
		code.n = 0;
		code.c = FLAG_0;
	}
}
