/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/05/31 23:49:29 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
** =================================== const ===================================
*/

# define PID_BIT_COUNT			32
# define MSG_BIT_COUNT			8

/*
** ---------------------------------- message ----------------------------------
*/

# define USAGE_MSG_HEADER		"USAGE: "
# define USAGE_MSG_DESCRIPTION	"./clinet [SERVER PID] [WANNA SEND MESSAGE]"
# define ERROR_MSG_HEADER		"ERROR: "
# define ERROR_MSG_PID_TYPE		"SERVER PID must be number!!"
# define ERROR_MSG_PID_RANGE	"SERVER PID is not in PID range!!"
# define ERROR_MSG_PID_INVALID	"SERVER PID is INVALID!!"
# define ERROR_MSG_MSG_INVALID	"WANNA SEND MESSAGE is INVALID!!"

/*
** ----------------------------------- color -----------------------------------
*/

# define ESC_FNT_RESET		"\033[0m"
# define ESC_FNT_BOLD		"\033[1m"
# define ESC_FNT_FINE		"\033[2m"
# define ESC_FNT_ITALIC		"\033[3m"
# define ESC_FNT_ULINE		"\033[4m"

# define ESC_CLR_RESET		"\033[00m"
# define ESC_CLR_BLACK		"\033[30m"
# define ESC_CLR_RED		"\033[31m"
# define ESC_CLR_GREEN		"\033[32m"
# define ESC_CLR_YELLOW		"\033[33m"
# define ESC_CLR_BLUE		"\033[34m"
# define ESC_CLR_MAGENTA	"\033[35m"
# define ESC_CLR_CYAN		"\033[36m"
# define ESC_CLR_WHITE		"\033[37m"

/*
** ============================== global variable ==============================
*/

// extern int	g_receive_signal;

/*
** ================================== library ==================================
*/

# define _GNU_SOURCE

# include "../library/libft/includes/libft.h"

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
