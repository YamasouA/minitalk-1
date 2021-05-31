/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:10:19 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 00:06:42 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

/*!
** @brief	check if Server ProcessID is digit
** @param	pid_server	wanna check if "pid_server" is degit
** @return	none
*/
static bool	check_pid_server_is_digit(char *pid_server)
{
	size_t	len;

	len = ft_strlen(pid_server);
	while (len--)
	{
		if (!ft_isdigit(pid_server[len]))
			return (false);
	}
	return (true);
}

/*!
** @brief	check if Server ProcessID is in range
** @param	pid_server	wanna check if "pid_server" is in range
** @return	none
*/
static bool	check_pid_server_is_in_range(int32_t pid_server)
{
	if (pid_server <= 0 || INT32_MAX < pid_server)
		return (false);
	return (true);
}

/*!
** @brief	check if Message is string
** @param	send_message	wanna check if "pid_server" is in range
** @return	none
*/
static bool	check_message_is_string(char *send_message)
{
	// size_t	message_len;

	// message_len = ft_strlen(send_message);

	if (!send_message)
		return (false);
	if (!(*send_message))
		return (false);
	return (true);
}

/*!
** @brief	check argument
** @param	argc	argument count
** @param	argv	argument contents
** @return	none
*/
void	check_argument(int argc, char **argv)
{
	if (argc != 3)
		exit_client(USAGE_MSG_HEADER USAGE_MSG_DESCRIPTION);
	if (!check_pid_server_is_digit(argv[1]))
		exit_client(ERROR_MSG_HEADER ERROR_MSG_PID_TYPE);
	if (!check_pid_server_is_in_range(ft_atoi(argv[1])))
		exit_client(ERROR_MSG_HEADER ERROR_MSG_PID_RANGE);
	if (!check_message_is_string(argv[2]))
		exit_client(ERROR_MSG_HEADER ERROR_MSG_MSG_INVALID);
}
