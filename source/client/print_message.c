/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:21:53 by mmizuno           #+#    #+#             */
/*   Updated: 2021/05/31 01:28:32 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

/*!
** @brief	print error message
** @param	error_message:	wanna print error message
** @return	none
*/
void	print_error_message(char *error_message)
{
	ft_putstr_fd(ESC_CLR_YELLOW, STDOUT_FILENO);
	ft_putstr_fd("[ ", STDOUT_FILENO);
	ft_putstr_fd(error_message, STDOUT_FILENO);
	ft_putendl_fd(" ]", STDOUT_FILENO);
	ft_putstr_fd(ESC_CLR_RESET, STDOUT_FILENO);
}



