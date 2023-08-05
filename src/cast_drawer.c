/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:21:04 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 22:07:58 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_pixel(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= vrs->img_width || y >= vrs->img_height)
		return ;
	pixel = vrs->img_data_addr + (x * vrs->bits_p_px / 8) + (y * vrs->ln_len);
	*(unsigned int *)pixel = color;
}

static void	texture_color_helper(t_vars *vrs, double wall_y)
{
	int		tex_x;
	int		tex_y;
	char	*pixel;

	if (vrs->wall_side == FACING_EAST)
	{
		tex_x = (int)(vrs->tx_e->width
				* (vrs->ray_pos_y - floor(vrs->ray_pos_y)));
		tex_y = (int)floor(vrs->tx_e->height * wall_y);
		pixel = vrs->tx_e->img_data_addr + (tex_x * vrs->tx_e->bits_p_px / 8)
			+ (tex_y * vrs->tx_e->ln_len);
		vrs->wall_color = *(unsigned int *)pixel;
	}
	else if (vrs->wall_side == FACING_WEST)
	{
		tex_x = (int)(vrs->tx_w->width
				* (vrs->ray_pos_y - floor(vrs->ray_pos_y)));
		tex_y = (int)floor(vrs->tx_w->height * wall_y);
		pixel = vrs->tx_w->img_data_addr + (tex_x * vrs->tx_w->bits_p_px / 8)
			+ (tex_y * vrs->tx_w->ln_len);
		vrs->wall_color = *(unsigned int *)pixel;
	}
}

// wall_y is 0 at top of wall and is 1 at bottom of wall
static void	set_pixel_color(t_vars *vrs, double wall_y)
{
	int		tex_x;
	int		tex_y;
	char	*pixel;

	if (vrs->wall_side == FACING_NORTH)
	{
		tex_x = (int)(vrs->tx_n->width
				* (vrs->ray_pos_x - floor(vrs->ray_pos_x)));
		tex_y = (int)floor(vrs->tx_n->height * wall_y);
		pixel = vrs->tx_n->img_data_addr + (tex_x * vrs->tx_n->bits_p_px / 8)
			+ (tex_y * vrs->tx_n->ln_len);
		vrs->wall_color = *(unsigned int *)pixel;
	}
	else if (vrs->wall_side == FACING_SOUTH)
	{
		tex_x = (int)(vrs->tx_s->width
				* (vrs->ray_pos_x - floor(vrs->ray_pos_x)));
		tex_y = (int)floor(vrs->tx_s->height * wall_y);
		pixel = vrs->tx_s->img_data_addr + (tex_x * vrs->tx_s->bits_p_px / 8)
			+ (tex_y * vrs->tx_s->ln_len);
		vrs->wall_color = *(unsigned int *)pixel;
	}
	texture_color_helper(vrs, wall_y);
}

void	draw_vert_line(int x, t_vars *vrs)
{
	int		y;
	int		y_start;
	int		y_stop;

	y = 0;
	y_start = (0.5 * vrs->img_height) - (0.5 * vrs->wall_height);
	y_stop = (0.5 * vrs->img_height) + (0.5 * vrs->wall_height);
	while (y < y_start)
	{
		print_pixel(x, y, vrs, vrs->sky_clr);
		y++;
	}
	while (y < y_stop)
	{
		set_pixel_color(vrs, ((y - y_start) / (double)vrs->wall_height));
		print_pixel(x, y, vrs, vrs->wall_color);
		y++;
	}
	while (y < vrs->img_height)
	{
		print_pixel(x, y, vrs, vrs->floor_clr);
		y++;
	}
}
