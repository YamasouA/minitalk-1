/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:32:56 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/04 01:11:57 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

/*!
** @brief	append receive message (use malloc)
** @param	vars	server vars (structure)
** @return	none
*/
void	append_receive_message(t_server_vars *vars)
{
	char	*new_message;

	new_message = (char *)malloc(sizeof(char) * (vars->message_count + 2));
	if (!new_message)
		exit_server(vars, ERROR_MSG_HEADER ERROR_MSG_FAIL_MALLOC, false);
	ft_strlcpy(new_message, vars->message, vars->message_count + 2);
	new_message[vars->message_count] = vars->message_bits;
	new_message[vars->message_count + 1] = '\0';
	vars->message_count++;
	if (vars->message)
		free(vars->message);
	vars->message = new_message;
}

/*!
** @brief	free receive message (use free)
** @param	vars	server vars (structure)
** @return	none
*/
void	free_receive_message(t_server_vars *vars)
{
	if (vars->message)
		free(vars->message);
}
