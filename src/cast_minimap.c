/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:11:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 22:12:23 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_pixel_minimap(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	pixel = vrs->m_img_data_addr + (x * vrs->m_bits_p_px / 8)
		+ (y * vrs->m_ln_len);
	*(unsigned int *)pixel = color;
}

static void	draw_view_cone(int x_pos, int y_pos, t_vars *vrs)
{
	int i = 0;
	int wall_hit_temp = 0;
	double angle = 0;
	double ray_x = 0;
	double ray_y = 0;
	while (i < 50)
	{
		wall_hit_temp = 0;
		angle = vrs->view_angle - (0.5 * vrs->fov_angle) + (i * vrs->fov_angle / 50);
		ray_x = x_pos;
		ray_y = y_pos;
		int j = 0;
		while (!wall_hit_temp && j < 40)
		{
			ray_x += cos(angle);
			ray_y += sin(angle);
			double real_x = (ray_x / vrs->m_width) * vrs->map_width;
			double real_y = (ray_y / vrs->m_width) * vrs->map_width;
			if (vrs->map[(int)floor(real_y)][(int)floor(real_x)] == '1')
				wall_hit_temp = 1;
			print_pixel_minimap(ray_x, ray_y, vrs, 0x0039FF14);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_vars *vrs)
{
	int x_pos = (vrs->player_pos_x * vrs->m_width) / vrs->map_width;
	int y_pos = (vrs->player_pos_y * vrs->m_height) / vrs->map_height;
	int x;
	int y = y_pos - 2;

	while (y < y_pos + 2)
	{
		x = x_pos - 2;
		while(x < x_pos + 2)
		{
			print_pixel_minimap(x, y, vrs, 0x00FF0000);
			x++;
		}
		y++;
	}
	draw_view_cone(x_pos, y_pos, vrs);
}

void	draw_minimap(t_vars *vrs)
{
	int	map_y = 0;
	int	map_x = 0;
	while (map_y < vrs->m_height)
	{
		map_x = 0;
		while (map_x < vrs->m_width)
		{
			int x = (map_x * vrs->map_width) / vrs->m_width;
			int y = (map_y * vrs->map_height) /  vrs->m_height;
			if (vrs->map[y][x] == '1')
				print_pixel_minimap(map_x, map_y, vrs, vrs->m_color_wall);
			else if (vrs->map[y][x] == '0')
				print_pixel_minimap(map_x, map_y, vrs, vrs->m_color_floor);
			map_x++;
		}
		map_y++;
	}
	draw_player(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->m_img_ptr, 940, 15);
}