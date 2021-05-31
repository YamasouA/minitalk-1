/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:10:19 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 00:04:09 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"


static void	send_bit(int32_t pid_server, int32_t send_bits, int bit_count)
{
	int		current_bit;
	int		send_signal;
// (void)pid_server;
// ft_putendl_fd("", STDOUT_FILENO);
// ft_putnbr_fd(send_bits, STDOUT_FILENO);

	while (0 <= --bit_count)
	{
		current_bit = (send_bits >> bit_count) & 0x1;
		if (current_bit == 0)
			send_signal = SIGUSR1;
			// ft_putchar_fd('0', STDOUT_FILENO);
		else
			send_signal = SIGUSR2;
			// ft_putchar_fd('1', STDOUT_FILENO);
		if (kill(pid_server, send_signal) == -1)
			exit_client(ERROR_MSG_HEADER ERROR_MSG_PID_INVALID);
	}
}

void	send_bit_pid(int32_t pid_server, int32_t send_pid_client)
{
// ft_putnbr_fd(send_pid_client, STDOUT_FILENO);
	send_bit(pid_server, send_pid_client, PID_BIT_COUNT);
}

void	send_bit_message(int32_t pid_server, char *send_message)
{
	while (*send_message)
	{
		send_bit(pid_server, (int32_t)(*send_message), MSG_BIT_COUNT);
		send_message++;
	}
}
