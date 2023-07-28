/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:51:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/28 09:59:07 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	mapfile_to_arr(t_vars *vrs)
{
	int bytes_read;
	int	grid_x;
	int	grid_y;

	bytes_read = read(vrs->mapfile_fd, vrs->map_str, 2048);
	if (bytes_read == -1)
		return (err_msg("failed to read mapfile"));
	printf("%s\n", vrs->map_str);
	grid_x = grid_y = 0;
	vrs->map = malloc(sizeof(int *) * vrs->map_height);
	if (!vrs->map)
		return (err_msg("failed to malloc map"));
	while(grid_x < vrs->map_width && grid_y < vrs->map_height)
	{
		vrs->map[y]
		if (x == vrs->map_width - 1)
		{
			x = 0;
			y++;
		}

		x++;
	}
	return (0);
}