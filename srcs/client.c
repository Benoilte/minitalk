/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:25:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/05 22:39:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	int		bit;
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
			ft_printf("%c\n", str[i]);
			bit = 0;
			while (bit < 8)
			{
				ft_printf("bit[%d]: %d\n", bit, (str[i] >> (7 - bit)) & MASK);
				if (((str[i] >> (7 - bit)) & MASK) == 0)
					kill(ft_atoi(argv[1]), SIGUSR1);
				else 
					kill(ft_atoi(argv[1]), SIGUSR2);
				bit++;
				usleep(500);
			}
			i++;
		}
	}
	else
		ft_printf("Error: Wrong number of argument\n");
	return (0);
}
