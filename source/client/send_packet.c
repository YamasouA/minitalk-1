/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:10:19 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 20:07:47 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

/*!
** @brief	CLIENT receive acknowledgement from SERVER
** 			to check if could pass Client ProcessID to SERVER
** @param	none
** @return	none
*/
static void	receive_ack_pid(void)
{
	if (g_receive_signal == SIGUSR1)
		print_success_message(SUCCESS_MSG_HEADER SUCCESS_MSG_DONE_SEND_PID);
	else
		exit_client_failure(ERROR_MSG_HEADER ERROR_MSG_FAIL_SEND_PID);
	g_receive_signal = 0;
}

/*!
** @brief	CLIENT receive acknowledgement from SERVER
** 			to check if could pass Message Bit to SERVER
** @param	send_signal		SIGUSR1 / SIGUSR2
** @return	none
*/
static void	receive_ack_message(int send_signal)
{
	while (g_receive_signal == 0)
	{
		if (g_terminate_flag)
			exit_client_failure(ERROR_MSG_TERM_CLIENT);
	}
	if (g_receive_signal != send_signal)
		exit_client_failure(ERROR_MSG_HEADER ERROR_MSG_FAIL_SEND_MSG);
	g_receive_signal = 0;
}

/*!
** @brief	send bits (use signal)
** 			SIGUSR1 -> ON BIT
** 			SIGUSR2 -> OFF BIT
** @param	pid_server		SERVER ProcessID to want to send to
** @param	send_bits		bits to want to send
** @param	send_bit_count	bit count to want to send
** @param	ack_mode		acknowledgement mode on / off
** @return	none
*/
static void	send_bits(int32_t pid_server, int32_t send_bits,
											int send_bit_count, bool ack_mode)
{
	int		current_bit;
	int		send_signal;

	while (0 <= --send_bit_count)
	{
		current_bit = (send_bits >> send_bit_count) & 0x1;
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
			usleep(2000);
	}
}

/*!
** @brief	send bits of CLIENT ProcessID (wrapper function of send_bits)
** @param	pid_server			SERVER ProcessID to want to send to
** @param	send_pid_client		bits (CLIENT ProcessID) to want to send
** @return	none
*/
void	send_bits_pid_client(int32_t pid_server, int32_t send_pid_client)
{
	send_bits(pid_server, send_pid_client, PID_BIT_COUNT, false);
	receive_ack_pid();
}

/*!
** @brief	send bits of Message (wrapper function of send_bits)
** @param	pid_server		SERVER ProcessID to want to send to
** @param	send_message	bits (Message) to want to send
** @return	none
*/
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
