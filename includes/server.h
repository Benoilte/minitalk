/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:08:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/11 13:58:36 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <signal.h>

# define FLAG_0 0b00000000
# define FLAG_1 0b00000001

// server.c

void	set_signal_action(void);
void	sig_handler(int signum, siginfo_t *info, void *ucontext);
void	display_char(char to_print);
void	set_sender_pid(pid_t s_pid);

#endif
