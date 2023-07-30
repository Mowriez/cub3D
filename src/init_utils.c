/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:51:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/30 01:30:58 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	print_arr(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("map: %s\n", arr[i]);
		i++;
	}
}

int	mapfile_to_arr(t_vars *vrs)
{
	int bytes_read;
	int	grid_x;
	int	grid_y;
	int i;

	bytes_read = read(vrs->mapfile_fd, vrs->map_str, 2048);
	if (bytes_read == -1)
		return (err_msg("failed to read mapfile"));
	vrs->map = malloc(sizeof(char *) * (vrs->map_height + 1));
	if (!vrs->map)
		return (err_msg("failed to malloc map"));
	vrs->map[vrs->map_height] = NULL;
	grid_x = 0;
	grid_y = 0;
	i = 0;
	while(grid_y < vrs->map_height) // && (grid_x < vrs->map_width && grid_y < vrs->map_height
	{
		if (grid_x == 0)
			vrs->map[grid_y] = malloc(sizeof(char) * (vrs->map_width + 1));
		while (grid_x < vrs->map_width)
		{
			if (vrs->map_str[i] == '\n')
				i++;
			vrs->map[grid_y][grid_x] = vrs->map_str[i];
			grid_x++;
			i++;
		}
		printf("gx %i, wi %i\n", grid_x, vrs->map_width);
		vrs->map[grid_y][grid_x] = '\0';
		grid_x = 0;
		grid_y++;
	}
	print_arr(vrs->map);
	return (0);
}