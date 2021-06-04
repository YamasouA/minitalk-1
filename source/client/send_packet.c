/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:10:19 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 13:07:27 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

static void	receive_ack_pid(void)
{
	if (g_receive_signal == SIGUSR1)
		print_success_message(SUCCESS_MSG_HEADER SUCCESS_MSG_DONE_SEND_PID);
	else
		exit_client_failure(ERROR_MSG_HEADER ERROR_MSG_FAIL_SEND_PID);
	g_receive_signal = 0;
}

static void	receive_ack_message(int send_signal)
{
	while (g_receive_signal == 0)
	{
		if (g_terminate_flag)
			exit_client_failure("terminating...");
	}
	if (g_receive_signal != send_signal)
		exit_client_failure(ERROR_MSG_HEADER ERROR_MSG_FAIL_SEND_MSG);
	g_receive_signal = 0;
}

static void	send_bits(int32_t pid_server, int32_t send_bits,
												int bit_count, bool ack_mode)
{
	int		current_bit;
	int		send_signal;

	while (0 <= --bit_count)
	{
		current_bit = (send_bits >> bit_count) & 0x1;
		if (current_bit == 0)
			send_signal = SIGUSR2;
		else
			send_signal = SIGUSR1;
		if (kill(pid_server, send_signal) == -1)
			exit_client_failure(ERROR_MSG_HEADER ERROR_MSG_FAIL_SEND_SIGNAL);
		if (ack_mode)
		{
			receive_ack_message(send_signal);
			usleep(50);
		}
		else
			usleep(1000);
	}
}

void	send_bits_pid(int32_t pid_server, int32_t send_pid_client)
{
	send_bits(pid_server, send_pid_client, PID_BIT_COUNT, false);
	receive_ack_pid();
}

void	send_bits_message(int32_t pid_server, char *send_message)
{
	while (*send_message)
	{
		send_bits(pid_server, (int32_t)(*send_message), MSG_BIT_COUNT, true);
		send_message++;
	}
	send_bits(pid_server, (int32_t)ASCII_EOT, MSG_BIT_COUNT, true);
	print_success_message(SUCCESS_MSG_HEADER SUCCESS_MSG_DONE_SEND_MSG);
}
