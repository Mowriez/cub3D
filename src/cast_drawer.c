/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:21:04 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/08 22:45:23 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	print_pixel(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= vrs->main_img.width || y >= vrs->main_img.height)
		return ;
	pixel = vrs->main_img.data_addr + (x * vrs->main_img.bpp / 8)
		+ (y * vrs->main_img.ln_len);
	*(unsigned int *)pixel = color;
}

static void	texture_color_helper(t_vars *vrs, double wall_y)
{
	int		tex_x;
	int		tex_y;
	char	*pixel;

	if (vrs->rc.wall_side == FACING_EAST)
	{
		tex_x = (int)(vrs->tx_e.width
				* (vrs->rc.ray_pos_y - floor(vrs->rc.ray_pos_y)));
		tex_y = (int)floor(vrs->tx_e.height * wall_y);
		pixel = vrs->tx_e.img_data_addr + (tex_x * vrs->tx_e.bits_p_px / 8)
			+ (tex_y * vrs->tx_e.ln_len);
		vrs->rc.px_color = *(unsigned int *)pixel;
	}
	else if (vrs->rc.wall_side == FACING_WEST)
	{
		tex_x = (int)(vrs->tx_w.width
				* (vrs->rc.ray_pos_y - floor(vrs->rc.ray_pos_y)));
		tex_y = (int)floor(vrs->tx_w.height * wall_y);
		pixel = vrs->tx_w.img_data_addr + (tex_x * vrs->tx_w.bits_p_px / 8)
			+ (tex_y * vrs->tx_w.ln_len);
		vrs->rc.px_color = *(unsigned int *)pixel;
	}
}

// wall_y is 0 at top of wall and is 1 at bottom of wall
static void	set_pixel_color(t_vars *vrs, double wall_y)
{
	int		tex_x;
	int		tex_y;
	char	*pixel;

	if (vrs->rc.wall_side == FACING_NORTH)
	{
		tex_x = (int)(vrs->tx_n.width
				* (vrs->rc.ray_pos_x - floor(vrs->rc.ray_pos_x)));
		tex_y = (int)floor(vrs->tx_n.height * wall_y);
		pixel = vrs->tx_n.img_data_addr + (tex_x * vrs->tx_n.bits_p_px / 8)
			+ (tex_y * vrs->tx_n.ln_len);
		vrs->rc.px_color = *(unsigned int *)pixel;
	}
	else if (vrs->rc.wall_side == FACING_SOUTH)
	{
		tex_x = (int)(vrs->tx_s.width
				* (vrs->rc.ray_pos_x - floor(vrs->rc.ray_pos_x)));
		tex_y = (int)floor(vrs->tx_s.height * wall_y);
		pixel = vrs->tx_s.img_data_addr + (tex_x * vrs->tx_s.bits_p_px / 8)
			+ (tex_y * vrs->tx_s.ln_len);
		vrs->rc.px_color = *(unsigned int *)pixel;
	}
	texture_color_helper(vrs, wall_y);
}

void	draw_vert_line(int x, t_vars *vrs)
{
	int		y;
	int		y_start;
	int		y_stop;

	y = 0;
	y_start = (0.5 * vrs->main_img.height) - (0.5 * vrs->rc.wall_height);
	y_stop = (0.5 * vrs->main_img.height) + (0.5 * vrs->rc.wall_height);
	while (y < y_start)
	{
		print_pixel(x, y, vrs, vrs->map.color_ceiling);
		y++;
	}
	while (y < y_stop)
	{
		set_pixel_color(vrs, ((y - y_start) / (double)vrs->rc.wall_height));
		print_pixel(x, y, vrs, vrs->rc.px_color);
		y++;
	}
	while (y < vrs->main_img.height)
	{
		print_pixel(x, y, vrs, vrs->map.color_floor);
		y++;
	}
}
