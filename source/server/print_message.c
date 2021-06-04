/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:53 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 18:35:34 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

/*!
** @brief	print receive message
** @param	receive_message		receive message
** @return	none
*/
void	print_receive_message(t_server_vars *vars)
{
	ft_putstr_fd(ESC_FNT_BOLD, STDOUT_FILENO);
	ft_putstr_fd("[ CLIENT ProcessID: ", STDOUT_FILENO);
	ft_putnbr_fd(vars->pid_client_bits, STDOUT_FILENO);
	ft_putstr_fd(" ]", STDOUT_FILENO);
	ft_putstr_fd(ESC_RESET, STDOUT_FILENO);
	ft_putendl_fd(vars->message, STDOUT_FILENO);
}
