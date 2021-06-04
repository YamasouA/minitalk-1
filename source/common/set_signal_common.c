/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 03:56:30 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 22:01:31 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.h"

static void	handle_sigusr1(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_receive_signal = signal;
}

static void	handle_sigusr2(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_receive_signal = signal;
}

static void	handle_sigint(int signal, siginfo_t *info, void *ucontext)
{
	(void)signal;
	(void)info;
	(void)ucontext;
	g_terminate_flag = true;
}

/*!
** @brief	set signal (sigusr1/sigusr2/sigint)
** @param	none
** @return	none
*/
void	set_signal(void)
{
	struct sigaction	sa_sigusr1;
	struct sigaction	sa_sigusr2;
	struct sigaction	sa_sigint;

	sa_sigusr1.sa_sigaction = &handle_sigusr1;
	sigemptyset(&sa_sigusr1.sa_mask);
	sigaddset(&sa_sigusr1.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa_sigusr1, NULL);
	sa_sigusr2.sa_sigaction = &handle_sigusr2;
	sigemptyset(&sa_sigusr2.sa_mask);
	sigaddset(&sa_sigusr2.sa_mask, SIGUSR2);
	sigaction(SIGUSR2, &sa_sigusr2, NULL);
	sa_sigint.sa_sigaction = &handle_sigint;
	sigemptyset(&sa_sigint.sa_mask);
	sigaddset(&sa_sigint.sa_mask, SIGINT);
	sigaction(SIGINT, &sa_sigint, NULL);
}
