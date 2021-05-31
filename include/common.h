/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 01:16:39 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 02:21:26 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

/*
** =================================== const ===================================
*/

# define PID_BIT_COUNT			32
# define MSG_BIT_COUNT			8

/*
** ---------------------------------- message ----------------------------------
*/

# define USAGE_MSG_HEADER		"USAGE: "
# define ERROR_MSG_HEADER		"ERROR: "

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
** ================================== library ==================================
*/

# define _GNU_SOURCE
# include "../library/libft/includes/libft.h"

#endif
