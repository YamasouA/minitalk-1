/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 03:56:30 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/07 18:14:59 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.h"

static void	handle_signal(int signal)
{
	g_receive_signal = signal;
}

/*!
** @brief	set signal (sigusr1/sigusr2/sigquit/sigint)
** @param	none
** @return	none
*/
void	set_signal(void)
{
	if (signal(SIGUSR1, &handle_signal) == SIG_ERR
		|| signal(SIGUSR2, &handle_signal) == SIG_ERR
		|| signal(SIGQUIT, &handle_signal) == SIG_ERR
		|| signal(SIGINT, &handle_signal) == SIG_ERR)
	{
		print_failure_message(ERROR_MSG_HEADER ERROR_MSG_FAIL_SET_SIGNAL);
		exit(EXIT_FAILURE);
	}
}
