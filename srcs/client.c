/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:25:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/06 01:45:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	char	*str;

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
		usleep(500);
	}
}
