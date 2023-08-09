/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:34:05 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 23:03:32 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	err_msg(char *msg)
{
	int	len;
	int	res;

	len = 0;
	while (msg[len])
		len++;
	res = write(2, RED "Error\n", sizeof(RED) + 6);
	res = write(2, msg, len);
	res = write(2, RES "\n", sizeof(RES) + 1);
	res = 1;
	return (res);
}

void	ft_custom_exit(const char *message)
{
	err_msg((char *)message);
	exit(EXIT_FAILURE);
}
