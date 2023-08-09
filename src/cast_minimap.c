/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:11:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 07:56:32 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_pixel_minimap(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	pixel = vrs->m_map.data_addr + (x * vrs->m_map.bpp / 8)
		+ (y * vrs->m_map.ln_len);
	*(unsigned int *)pixel = color;
}

static void	cast_view_cone_ray(double angle, double ray_x, double ray_y,
		t_vars *vrs)
{
	int		j;
	double	real_x;
	double	real_y;

	j = 0;
	while (j < 40)
	{
		ray_x += cos(angle);
		ray_y += sin(angle);
		real_x = (ray_x / vrs->m_map.width) * vrs->map.width;
		real_y = (ray_y / vrs->m_map.height) * vrs->map.height;
		if (vrs->map.map[(int)floor(real_y)][(int)floor(real_x)] == '1')
			return ;
		print_pixel_minimap(ray_x, ray_y, vrs, 0x0039FF14);
		j++;
	}
}

static void	draw_view_cone(int x_pos, int y_pos, t_vars *vrs)
{
	int		i;
	double	angle;
	double	ray_x;
	double	ray_y;

	i = 0;
	while (i < 50)
	{
		angle = vrs->rc.view_angle - (0.5 * vrs->rc.fov_angle)
			+ (i * vrs->rc.fov_angle / 50);
		ray_x = x_pos;
		ray_y = y_pos;
		cast_view_cone_ray(angle, ray_x, ray_y, vrs);
		i++;
	}
}

static void	draw_player(t_vars *vrs)
{
	int	x_pos;
	int	y_pos;
	int	x;
	int	y;

	x_pos = (vrs->rc.pl_pos_x * vrs->m_map.width) / vrs->map.width;
	y_pos = (vrs->rc.pl_pos_y * vrs->m_map.height) / vrs->map.height;
	y = y_pos - 2;
	while (y < y_pos + 2)
	{
		x = x_pos - 2;
		while (x < x_pos + 2)
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
	int	map_x;
	int	map_y;
	int	x;
	int	y;

	map_y = 0;
	while (map_y < vrs->m_map.height)
	{
		map_x = 0;
		while (map_x < vrs->m_map.width)
		{
			x = (map_x * vrs->map.width) / vrs->m_map.width;
			y = (map_y * vrs->map.height) / vrs->m_map.height;
			if (vrs->map.map[y][x] == '1')
				print_pixel_minimap(map_x, map_y, vrs, 0x004B0000);
			else if (vrs->map.map[y][x] == '0')
				print_pixel_minimap(map_x, map_y, vrs, 0x22333333);
			else
				print_pixel_minimap(map_x, map_y, vrs, 0x00000000);
			map_x++;
		}
		map_y++;
	}
	draw_player(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr,
		vrs->m_map.img_ptr, vrs->win_width - vrs->m_map.width - 20, 20);
}
