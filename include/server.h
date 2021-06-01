/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/02 00:39:40 by mmizuno          ###   ########.fr       */
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

# define USAGE_MSG_DESCRIPTION	"./server"
# define ERROR_MSG_FAIL_MALLOC	"Fail to Allocate Memory !!"

/*
** ================================== library ==================================
*/

# include "common.h"




#include <stdio.h>




/*
** ============================== global variable ==============================
*/

extern int	g_receive_signal;
extern bool	g_terminate_flag;

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

void	set_signal(void);

void	recieve_bit(t_server_vars *v, int signal);

void	append_receive_message(t_server_vars *vars);
void	free_recieve_message(t_server_vars *vars);

void	print_recieve_message(t_server_vars *vars);


#endif
