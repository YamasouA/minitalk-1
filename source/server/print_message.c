/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:53 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 23:35:30 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

/*!
** @brief	print recieve message
** @param	recieve_message		recieve message
** @return	none
*/
void	print_recieve_message(t_server_vars *vars)
{
	ft_putstr_fd("[ From ", STDOUT_FILENO);
	ft_putnbr_fd(vars->pid_client_bits, STDOUT_FILENO);
	ft_putstr_fd(": ", STDOUT_FILENO);
	ft_putstr_fd(vars->message, STDOUT_FILENO);
	ft_putendl_fd(" ]", STDOUT_FILENO);
}
