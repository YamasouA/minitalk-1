/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 03:56:30 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/06 00:04:09 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.h"

static void	handle_sigusr1_sigusr2(int signal)
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
	if (signal(SIGUSR1, &handle_sigusr1_sigusr2) == SIG_ERR
		|| signal(SIGUSR2, &handle_sigusr1_sigusr2) == SIG_ERR
		|| signal(SIGINT, &handle_sigint) == SIG_ERR)
	{
		print_failure_message(ERROR_MSG_HEADER ERROR_MSG_FAIL_SET_SIGNAL);
		exit(EXIT_FAILURE);
	}
}
