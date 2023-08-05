/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 02:17:40 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 07:24:50 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	get_wall_side(t_vars *vrs)
{
	if (floor(vrs->ray_last_pos_x) - floor(vrs->ray_pos_x) != 0
		&& floor(vrs->ray_last_pos_y) - floor(vrs->ray_pos_y) != 0)
		return ;
	if (floor(vrs->ray_last_pos_x) - floor(vrs->ray_pos_x) < 0)
		vrs->wall_side = FACING_WEST;
	else if (floor(vrs->ray_last_pos_x) - floor(vrs->ray_pos_x) > 0)
		vrs->wall_side = FACING_EAST;
	else if (floor(vrs->ray_last_pos_y) - floor(vrs->ray_pos_y) < 0)
		vrs->wall_side = FACING_NORTH;
	else if (floor(vrs->ray_last_pos_y) - floor(vrs->ray_pos_y) > 0)
		vrs->wall_side = FACING_SOUTH;
}

static void	calc_wall_height(t_vars *vrs)
{
	vrs->ray_len = sqrt(pow(vrs->ray_pos_x - vrs->player_pos_x, 2)
			+ pow(vrs->ray_pos_y - vrs->player_pos_y, 2));
	if (vrs->view_angle > vrs->ray_angle)
		vrs->ray_len = vrs->ray_len * cos(vrs->view_angle - vrs->ray_angle);
	else if (vrs->view_angle < vrs->ray_angle)
		vrs->ray_len = vrs->ray_len * cos(vrs->ray_angle - vrs->view_angle);
	// if (vrs->ray_len <= 1)
	// 	vrs->wall_height = (int)(vrs->img_height);
	// else
		vrs->wall_height = (int)(WALL_SCALE_FACTOR * (vrs->img_height / vrs->ray_len));
}

static void	cast_ray(t_vars *vrs, int img_x)
{
	vrs->wall_hit = 0;
	vrs->ray_angle = vrs->view_angle - (0.5 * vrs->fov_angle)
		+ (img_x * vrs->angle_betw_rays);
	vrs->ray_pos_x = vrs->player_pos_x;
	vrs->ray_pos_y = vrs->player_pos_y;
	while (!vrs->wall_hit)
	{
		vrs->ray_last_pos_x = vrs->ray_pos_x;
		vrs->ray_last_pos_y = vrs->ray_pos_y;
		vrs->ray_pos_x += cos(vrs->ray_angle) / vrs->ray_precision;
		vrs->ray_pos_y += sin(vrs->ray_angle) / vrs->ray_precision;
		if (vrs->map[(int)floor(vrs->ray_pos_y)][(int)floor(vrs->ray_pos_x)]
			== '1')
			vrs->wall_hit = 1;
	}
	calc_wall_height(vrs);
	get_wall_side(vrs);
}

int	visualizer(t_vars *vrs)
{
	int	img_x;

	img_x = 0;
	while (img_x < vrs->img_width)
	{
		cast_ray(vrs, img_x);
		draw_vert_line(img_x, vrs);
		if (img_x == vrs->img_width / 2)
			get_debugging_values(vrs);
		img_x++;
	}
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
	draw_minimap(vrs);
	if (vrs->overlay)
		draw_debugging_overlay(vrs);
	motion(vrs);
	return (0);
}
