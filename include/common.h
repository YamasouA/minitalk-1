/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 01:16:39 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 18:48:53 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

/*
** =================================== const ===================================
*/

# define PID_BIT_COUNT			32
# define MSG_BIT_COUNT			8

# define ASCII_EOT				0x4

/*
** ---------------------------------- message ----------------------------------
*/

# define USAGE_MSG_HEADER		"USAGE: "
# define ERROR_MSG_HEADER		"ERROR: "
# define SUCCESS_MSG_HEADER		"SUCCESS: "

/*
** ----------------------------------- color -----------------------------------
*/

# define ESC_RESET			"\033[0m"
# define ESC_FNT_BOLD		"\033[1m"
# define ESC_FNT_FINE		"\033[2m"
# define ESC_FNT_ITALIC		"\033[3m"
# define ESC_FNT_ULINE		"\033[4m"
# define ESC_CLR_BLACK		"\033[38;5;00m"
# define ESC_CLR_RED		"\033[38;5;01m"
# define ESC_CLR_GREEN		"\033[38;5;02m"
# define ESC_CLR_YELLOW		"\033[38;5;03m"
# define ESC_CLR_BLUE		"\033[38;5;04m"
# define ESC_CLR_MAGENTA	"\033[38;5;05m"
# define ESC_CLR_CYAN		"\033[38;5;06m"
# define ESC_CLR_WHITE		"\033[38;5;07m"
# define ESC_CLR_PINK		"\033[38;5;213m"

/*
** ================================== library ==================================
*/

# define _GNU_SOURCE
# include "../library/libft/includes/libft.h"
# include <signal.h>
# include <stdint.h>
# include <stdbool.h>

/*
** ============================== global variable ==============================
*/

extern int	g_receive_signal;
extern bool	g_terminate_flag;

/*
** =========================== prototype declaration ===========================
*/

void	print_success_message(char *message);
void	print_failure_message(char *error_message);
void	print_pid(char *client_or_server, int32_t pid);

void	set_signal(void);

#endif
