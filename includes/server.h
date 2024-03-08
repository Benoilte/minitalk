/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:08:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/07 14:08:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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

#endif
