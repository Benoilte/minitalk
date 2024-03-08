/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:08:02 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/08 15:15:41 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <signal.h>

# define FLAG_0 0b00000000
# define FLAG_1 0b00000001
# define MASK   0b00000001

// client.c

void	set_signal_action(void);
void	sig_handler(int signum, siginfo_t *info, void *ucontext);
void	send_char(pid_t pid, char c);
void	wait_signal_back(void);

#endif
