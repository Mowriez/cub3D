/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:51:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/28 00:58:33 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	mapfile_to_arr(t_vars *vrs)
{
	int bytes_read;
	int	x;
	int	y;

	bytes_read = read(vrs->mapfile_fd, vrs->map_str, 2048);
	if (bytes_read == -1)
		return (err_msg("failed to read mapfile"));
	printf("%s\n", vrs->map_str);
	x = y = 0;
	vrs->map = 
	while(x < vrs->map_width && y < vrs->map_height)
	{
		if (x == vrs->map_width - 1)
		{
			x = 0;
			y++;
		}

		x++;
	}
	return (0);
}