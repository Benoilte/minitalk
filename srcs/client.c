/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:25:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/05 18:43:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			exit (0);
		ft_printf("kill function: %d\n", kill(ft_atoi(argv[1]), SIGINT));
	}
	else
		ft_printf("Error: Wrong number of argument\n");
	return (0);
}
