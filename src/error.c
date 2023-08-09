/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:34:05 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 08:50:49 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

/*	FCT:	prints "error: msg\n" to stderror. (automatic newline at the end)
	ARG:	string msg that contains the error message.
	RET:	true (=error) in all cases.
*/
int	err_msg(char *msg)
{
	int	len;
	int	res;

	len = 0;
	while (msg[len])
		len++;
	res = write(2, RED "error: ", sizeof(RED) + 7);
	res = write(2, msg, len);
	res = write(2, RES "\n", sizeof(RES) + 1);
	res = 1;
	return (res);
}

void	ft_custom_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
