/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_common.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:53 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 19:39:45 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

/*!
** @brief	print success message
** @param	message		wanna print message
** @return	none
*/
void	print_success_message(char *message)
{
	ft_putstr_fd(ESC_FNT_BOLD ESC_CLR_GREEN, STDOUT_FILENO);
	ft_putendl_fd(message, STDOUT_FILENO);
	ft_putstr_fd(ESC_RESET, STDOUT_FILENO);
}

/*!
** @brief	print failure message
** @param	message		wanna print message
** @return	none
*/
void	print_failure_message(char *message)
{
	ft_putstr_fd(ESC_FNT_BOLD ESC_CLR_PINK, STDOUT_FILENO);
	ft_putendl_fd(message, STDOUT_FILENO);
	ft_putstr_fd(ESC_RESET, STDOUT_FILENO);
}

/*!
** @brief	print (client or server) ProcessID
** @param	client_or_server	who's ProcessID? (client or server)
** @param	pid					ProcessID
** @return	none
*/
void	print_pid(char *client_or_server, int32_t pid)
{
	ft_putstr_fd(ESC_FNT_BOLD ESC_CLR_YELLOW, STDOUT_FILENO);
	ft_putstr_fd("[ ", STDOUT_FILENO);
	ft_putstr_fd(client_or_server, STDOUT_FILENO);
	ft_putstr_fd(" ProcessID: ", STDOUT_FILENO);
	ft_putnbr_fd((int)pid, STDOUT_FILENO);
	ft_putendl_fd(" ]", STDOUT_FILENO);
	ft_putstr_fd(ESC_RESET, STDOUT_FILENO);
}
