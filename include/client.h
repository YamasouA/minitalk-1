/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/03 21:32:13 by mmizuno          ###   ########.fr       */
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

# define USAGE_MSG_DESCRIPTION		"./clinet [SERVER PID] [SEND MESSAGE]"
# define ERROR_MSG_PID_TYPE			"SERVER ProcessID must be number !!"
# define ERROR_MSG_PID_RANGE		"SERVER ProcessID is not in PID range !!"
# define ERROR_MSG_PID_INVALID		"SERVER ProcessID is INVALID !!"
# define ERROR_MSG_MSG_INVALID		"SEND MESSAGE is INVALID !!"
# define ERROR_MSG_FAIL_SEND_SIGNAL	"Fail to send Signal !!"
# define SUCCESS_MSG_DONE_SEND_PID	"Done to send CLIENT ProcessID !!"
# define ERROR_MSG_FAIL_SEND_PID	"Fail to send CLIENT ProcessID !!"
# define ERROR_MSG_FAIL_SEND_MSG	"Fail to send Message !!"
# define SUCCESS_MSG_DONE_SEND_MSG	"Done to send Message !!"

/*
** ================================== library ==================================
*/

# include "common.h"

/*
** =========================== prototype declaration ===========================
*/

void	exit_client_failure(char *message);

void	check_argument(int argc, char **argv);

void	send_bits_pid(int32_t pid_server, int32_t send_pid_client);
void	send_bits_message(int32_t pid_server, char *send_message);

#endif
