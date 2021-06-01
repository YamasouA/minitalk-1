/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:24:32 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 23:39:13 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

/*!
** @brief	initialize variables
** @param	vars	server vars (structure)
** @return	none
*/
void	init_server_vars(t_server_vars *vars)
{
	vars->pid_client_bits = 0;
	vars->pid_client_bit_count = 0;
	vars->message_bits = 0;
	vars->message_bit_count = 0;
	vars->message = NULL;
	vars->message_count = 0;
}

/*!
** @brief	initialize variables (only message_bits)
** @param	vars	server vars (structure)
** @return	none
*/
void	init_server_vars_message_bits(t_server_vars *vars)
{
	vars->message_bits = 0;
	vars->message_bit_count = 0;
}
