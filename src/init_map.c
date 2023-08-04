/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:51:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/04 08:43:20 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	convert_to_arr(t_vars *vrs)
{
	int	grid_x;
	int	grid_y;
	int	i;

	grid_x = 0;
	grid_y = 0;
	i = 0;
	while (grid_y < vrs->map_height)
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
		vrs->map[grid_y][grid_x] = '\0';
		grid_x = 0;
		grid_y++;
	}
}

static int	mapfile_to_arr(t_vars *vrs)
{
	int	bytes_read;

	bytes_read = read(vrs->mapfile_fd, vrs->map_str, 2048);
	if (bytes_read == -1)
		return (err_msg("failed to read mapfile"));
	vrs->map = malloc(sizeof(char *) * (vrs->map_height + 1));
	if (!vrs->map)
		return (err_msg("failed to malloc map"));
	vrs->map[vrs->map_height] = NULL;
	convert_to_arr(vrs);
	return (0);
}

static void	set_player_param(t_vars *vrs, int x, int y)
{
	vrs->player_pos_x = x + 0.5;
	vrs->player_pos_y = y + 0.5;
	vrs->fov_angle = FOV_ANGLE_DEG * (M_PI / 180);
	if (vrs->map[y][x] == 'N')
		vrs->view_angle = 1.5 * M_PI;
	else if (vrs->map[y][x] == 'S')
		vrs->view_angle = 0.5 * M_PI;
	else if (vrs->map[y][x] == 'W')
		vrs->view_angle = 1.0 * M_PI;
	else if (vrs->map[y][x] == 'E')
		vrs->view_angle = 0;
	vrs->angle_betw_rays = vrs->fov_angle / vrs->img_width;
}

static void	find_player_pos(t_vars *vrs)
{
	int	x;
	int	y;

	y = 0;
	while (vrs->map[y])
	{
		x = 0;
		while (x < vrs->map_width)
		{
			if (is_specific_char(vrs->map[y][x], "NSEW"))
			{
				set_player_param(vrs, x, y);
				vrs->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

int	init_map(t_vars *vrs)
{
	vrs->mapfile_fd = open(vrs->av[1], O_RDONLY);
	if (vrs->mapfile_fd == -1)
		return (err_msg("couldn't open mapfile."));
	vrs->map_width = 24;
	vrs->map_height = 24;
	vrs->ray_precision = RAY_CAST_PRECISION;
	if (mapfile_to_arr(vrs))
		return (err_msg("this mapfile is garbage"));
	find_player_pos(vrs);
	return (0);
}
