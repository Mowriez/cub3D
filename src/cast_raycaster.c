/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 02:17:40 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 18:07:24 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	get_wall_side(t_vars *vrs)
{
	if (floor(vrs->rc.ray_last_pos_x) - floor(vrs->rc.ray_pos_x) != 0
		&& floor(vrs->rc.ray_last_pos_y) - floor(vrs->rc.ray_pos_y) != 0)
		return ;
	if (floor(vrs->rc.ray_last_pos_x) - floor(vrs->rc.ray_pos_x) < 0)
		vrs->rc.wall_side = FACING_WEST;
	else if (floor(vrs->rc.ray_last_pos_x) - floor(vrs->rc.ray_pos_x) > 0)
		vrs->rc.wall_side = FACING_EAST;
	else if (floor(vrs->rc.ray_last_pos_y) - floor(vrs->rc.ray_pos_y) < 0)
		vrs->rc.wall_side = FACING_NORTH;
	else if (floor(vrs->rc.ray_last_pos_y) - floor(vrs->rc.ray_pos_y) > 0)
		vrs->rc.wall_side = FACING_SOUTH;
}

static void	calc_wall_height(double ray_angle, t_vars *vrs)
{
	vrs->rc.ray_len = sqrt(pow(vrs->rc.ray_pos_x - vrs->rc.pl_pos_x, 2)
			+ pow(vrs->rc.ray_pos_y - vrs->rc.pl_pos_y, 2));
	if (vrs->rc.view_angle > ray_angle)
		vrs->rc.ray_len = vrs->rc.ray_len * cos(vrs->rc.view_angle - ray_angle);
	else if (vrs->rc.view_angle < ray_angle)
		vrs->rc.ray_len = vrs->rc.ray_len * cos(ray_angle - vrs->rc.view_angle);
	vrs->rc.wall_height = (int)(vrs->main_img.height / vrs->rc.ray_len);
}

static void	cast_ray(int img_x, t_vars *vrs)
{
	bool	wall_hit;
	double	ray_angle;
	
	wall_hit = false;
	ray_angle = vrs->rc.view_angle - (0.5 * vrs->rc.fov_angle)
		+ (img_x * vrs->rc.angle_betw_rays);
	vrs->rc.ray_pos_x = vrs->rc.pl_pos_x;
	vrs->rc.ray_pos_y = vrs->rc.pl_pos_y;
	while (!wall_hit)
	{
		vrs->rc.ray_last_pos_x = vrs->rc.ray_pos_x;
		vrs->rc.ray_last_pos_y = vrs->rc.ray_pos_y;
		vrs->rc.ray_pos_x += cos(ray_angle) / RAY_CAST_PRECISION;
		vrs->rc.ray_pos_y += sin(ray_angle) / RAY_CAST_PRECISION;
		if ((vrs->map[(int)floor(vrs->rc.ray_pos_y)]
			[(int)floor(vrs->rc.ray_pos_x)]) == '1')
			wall_hit = true;
	}
	calc_wall_height(ray_angle, vrs);
	get_wall_side(vrs);
}

int	visualizer(t_vars *vrs)
{
	int	img_x;

	img_x = 0;
	while (img_x < vrs->main_img.width)
	{
		cast_ray(img_x, vrs);
		draw_vert_line(img_x, vrs);
		if (img_x == vrs->main_img.width / 2)
			get_debugging_values(vrs);
		img_x++;
	}
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr,
			vrs->main_img.img_ptr, 0, 0);
	draw_minimap(vrs);
	if (vrs->show_overlay)
		draw_debugging_overlay(vrs);
	motion(vrs);
	return (0);
}
