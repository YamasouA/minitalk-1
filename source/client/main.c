/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:28:42 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/07 18:15:05 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

int		g_receive_signal;

/*!
** @brief	exit client
** @param	message		wanna print message
** @param	success		true: success / false: failure
** @return	none
*/
void	exit_client(char *message, bool success)
{
	if (success)
	{
		print_success_message(message);
		exit(EXIT_SUCCESS);
	}
	else
	{
		print_failure_message(message);
		exit(EXIT_FAILURE);
	}
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
	g_receive_signal = 0;
	set_signal();
	pid_server = ft_atoi(argv[1]);
	pid_client = getpid();
	print_pid("CLIENT", pid_client);
	send_bits_pid_client(pid_server, pid_client);
	send_bits_message(pid_server, argv[2]);
	return (EXIT_SUCCESS);
}
