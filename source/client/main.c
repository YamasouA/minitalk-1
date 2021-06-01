/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:28:42 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 22:46:09 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

/*!
** @brief	exit client (when error occared)
** @param	message		wanna print message
** @return	none
*/
void	exit_client_failure(char *message)
{
	print_failure_message(message);
	exit(EXIT_FAILURE);
}

/*!
** @brief	main (client entry point)
** @param	argc	argument count
** @param	argv	argument contents
** @return	status
*/
int	main(int argc, char **argv)
{
	int32_t		pid_server;
	int32_t		pid_client;

	check_argument(argc, argv);
	pid_server = ft_atoi(argv[1]);
	pid_client = getpid();
	print_pid("client", pid_client);
	send_bits_pid(pid_server, pid_client);
	send_bits_message(pid_server, argv[2]);
	print_success_message(SUCCESS_MSG_HEADER SUCCESS_MSG_SEND_DONE);
	return (EXIT_SUCCESS);
}
