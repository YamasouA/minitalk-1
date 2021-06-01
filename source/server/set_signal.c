/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 03:56:30 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/02 07:06:24 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

static void	handle_sigusr1(int signal)
{
	g_receive_signal = signal;
}

static void	handle_sigusr2(int signal)
{
	g_receive_signal = signal;
}

static void	handle_sigint(int signal)
{
	(void)signal;
	g_terminate_flag = true;
}

/*!
** @brief	set signal (sigusr1/sigusr2/sigint)
** @param	none
** @return	none
*/
void	set_signal(void)
{
	// signal(SIGUSR1, &handle_sigusr1);
	// signal(SIGUSR2, &handle_sigusr2);
	// signal(SIGINT, &handle_sigint);
	struct sigaction	sa_sigusr1;
	struct sigaction	sa_sigusr2;
	struct sigaction	sa_sigint;

	sa_sigusr1.sa_handler = &handle_sigusr1;
	sigemptyset(&sa_sigusr1.sa_mask);
	sigaddset(&sa_sigusr1.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa_sigusr1, NULL);
	sa_sigusr2.sa_handler = &handle_sigusr2;
	sigemptyset(&sa_sigusr2.sa_mask);
	sigaddset(&sa_sigusr2.sa_mask, SIGUSR2);
	sigaction(SIGUSR2, &sa_sigusr2, NULL);
	sa_sigint.sa_handler = &handle_sigint;
	sigemptyset(&sa_sigint.sa_mask);
	sigaddset(&sa_sigint.sa_mask, SIGINT);
	sigaction(SIGINT, &sa_sigint, NULL);
}
