/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:23:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/07 14:11:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <signal.h>

# define FLAG_0 0b00000000
# define FLAG_1 0b00000001
# define MASK   0b00000001

typedef struct s_code
{
	int		n;
	char	c;
}	t_code;

// server.c

void	set_signal_action(void);
void	sig_handler(int signum, siginfo_t *info, void *ucontext);

// client.c

void	send_char(pid_t pid, char c);

#endif
