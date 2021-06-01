/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recieve_packet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 06:04:38 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/02 00:53:14 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	recieve_bit_pid(t_server_vars *vars, int signal)
{
	vars->pid_client_bits <<= 1;
	if (signal == SIGUSR1)
		vars->pid_client_bits++;
	vars->pid_client_bit_count++;
// printf("%d|%d\n", vars->pid_client_bits, vars->pid_client_bit_count);
}

void	recieve_bit_message(t_server_vars *vars, int signal)
{
// puts("aho");
	vars->message_bits <<= 1;
	if (signal == SIGUSR1)
		vars->message_bits++;
	vars->message_bit_count++;
	if (vars->message_bit_count == MSG_BIT_COUNT)
	{
		if (vars->message_bits == ASCII_EOT)
		{
			print_recieve_message(vars);
			free_recieve_message(vars);
			init_server_vars(vars);
		}
		else
		{
			append_receive_message(vars);
			init_server_vars_message_bits(vars);
		}
	}
	// [ack]
}

void	recieve_bit(t_server_vars *vars, int signal)
{
	if (vars->pid_client_bit_count < PID_BIT_COUNT)
		recieve_bit_pid(vars, signal);
	else
		recieve_bit_message(vars, signal);
	g_receive_signal = 0;
}
