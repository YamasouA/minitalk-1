/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 20:06:56 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/*
** =================================== const ===================================
*/

/*
** ---------------------------------- message ----------------------------------
*/

# define USAGE_MSG_DESCRIPTION		"./server"
# define ERROR_MSG_FAIL_MALLOC		"Fail to Allocate Memory !!"
# define ERROR_MSG_FAIL_SEND_ACK	"Fail to send Packet !!"
# define SUCCESS_MSG_TERM_SERVER	"Terminating ..."

/*
** ================================== library ==================================
*/

# include "common.h"

/*
** ================================== struct ===================================
*/

typedef struct s_server_vars
{
	int32_t		pid_client_bits;
	int			pid_client_bit_count;
	int32_t		message_bits;
	int			message_bit_count;
	char		*message;
	int			message_count;
}				t_server_vars;

/*
** =========================== prototype declaration ===========================
*/

void	exit_server(t_server_vars *vars, char *message, bool success);

void	init_server_vars(t_server_vars *vars);
void	init_server_vars_message_bits(t_server_vars *vars);

void	receive_bit(t_server_vars *v, int signal);

void	append_receive_message(t_server_vars *vars);
void	free_receive_message(t_server_vars *vars);

void	print_receive_message(t_server_vars *vars);

#endif
