/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:23:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/08 14:20:27 by bebrandt         ###   ########.fr       */
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

// server.c

void	set_signal_action(void);
void	sig_handler(int signum, siginfo_t *info, void *ucontext);

// client.c

void	send_char(pid_t pid, char c);

#endif
