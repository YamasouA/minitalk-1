/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 01:20:51 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
** =================================== const ===================================
*/


/*
** ============================== global variable ==============================
*/

// extern int	g_receive_signal;

/*
** ================================== library ==================================
*/

# include "common.h"

# include <signal.h>
# include <stdbool.h>
# include <stdint.h>


/*
** =========================== prototype declaration ===========================
*/

void	exit_client(char *error_message);

void	check_argument(int argc, char **argv);

void	send_bit_pid(int32_t pid_server, int32_t send_pid_client);
void	send_bit_message(int32_t pid_server, char *send_message);


void	print_error_message(char *error_message);





#endif
