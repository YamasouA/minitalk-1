/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_packet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 06:04:38 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/07 18:31:38 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

/*!
** @brief	SERVER send acknowledgement to CLIENT
** 			to check if could receive bits from CLIENT
** @param	vars			server vars (structure)
** @param	send_signal		signal to want to send
** @return	none
*/
static void	send_ack(t_server_vars *vars, int send_signal)
{
	if (kill(vars->pid_client_bits, send_signal) == -1)
		exit_server(vars, ERROR_MSG_HEADER ERROR_MSG_FAIL_SEND_ACK, false);
}

/*!
** @brief	SERVER receive bit (Client ProcessID) from CLIENT
** @param	vars			server vars (structure)
** @param	send_signal		signal to receive
** @return	none
*/
static void	receive_bit_pid_client(t_server_vars *vars, int signal)
{
	vars->pid_client_bits <<= 1;
	if (signal == SIGUSR1)
		vars->pid_client_bits++;
	vars->pid_client_bit_count++;
}

/*!
** @brief	SERVER receive bit (Message) from CLIENT
** @param	vars			server vars (structure)
** @param	send_signal		signal to receive
** @return	none
*/
static void	receive_bit_message(t_server_vars *vars, int signal)
{
	vars->message_bits <<= 1;
	if (signal == SIGUSR1)
		vars->message_bits++;
	vars->message_bit_count++;
	if (vars->message_bit_count == MSG_BIT_COUNT)
	{
		if (vars->message_bits == ASCII_EOT)
		{
			print_receive_message(vars);
			free_receive_message(vars);
			send_ack(vars, signal);
			init_server_vars(vars);
		}
		else
		{
			append_receive_message(vars);
			send_ack(vars, signal);
			init_server_vars_message_bits(vars);
		}
	}
	else
		send_ack(vars, signal);
}

/*!
** @brief	SERVER receive bit from CLIENT
** @param	vars			server vars (structure)
** @param	send_signal		signal to receive
** @return	none
*/
void	receive_bit(t_server_vars *vars, int signal)
{
	if (vars->pid_client_bit_count < PID_BIT_COUNT)
	{
		receive_bit_pid_client(vars, signal);
		if (vars->pid_client_bit_count == PID_BIT_COUNT)
			send_ack(vars, SIGUSR1);
	}
	else
	{
		receive_bit_message(vars, signal);
	}
	g_receive_signal = 0;
}
