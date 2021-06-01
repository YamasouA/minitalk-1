/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 22:53:50 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
** =================================== const ===================================
*/

/*
** ---------------------------------- message ----------------------------------
*/

# define USAGE_MSG_DESCRIPTION	"./clinet [SERVER PID] [WANNA SEND MESSAGE]"
# define ERROR_MSG_PID_TYPE		"SERVER PID must be number !!"
# define ERROR_MSG_PID_RANGE	"SERVER PID is not in PID range !!"
# define ERROR_MSG_PID_INVALID	"SERVER PID is INVALID !!"
# define ERROR_MSG_MSG_INVALID	"WANNA SEND MESSAGE is INVALID !!"
# define SUCCESS_MSG_SEND_DONE	"Done to send Massage !!"

/*
** ================================== library ==================================
*/

# include "common.h"

/*
** ============================== global variable ==============================
*/

// extern int	g_receive_signal;

/*
** =========================== prototype declaration ===========================
*/

void	exit_client_failure(char *message);

void	check_argument(int argc, char **argv);

void	send_bits_pid(int32_t pid_server, int32_t send_pid_client);
void	send_bits_message(int32_t pid_server, char *send_message);

#endif
