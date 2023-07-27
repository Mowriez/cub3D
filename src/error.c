/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:34:05 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/27 14:59:12 by mtrautne         ###   ########.fr       */
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
	len = 0;
	while (msg[len])
		len++;
	write(2, RED "error: ", sizeof(RED) + 7);
	write(2, msg, len);
	write(2, RES "\n" , sizeof(RES) + 1);
	return (1);
}
