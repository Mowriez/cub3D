/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:21:04 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 20:37:19 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_pixel(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	pixel = vrs->img_data_addr + (x * vrs->bits_p_px / 8) + (y * vrs->ln_len);
	*(unsigned int *)pixel = color;
}

// wall_y is 0 at top of wall and is 1 at bottom of wall
static void	set_pixel_color(t_vars *vrs, double wall_y)
{
//	int tex_x;
//	int tex_y;

	if (vrs->wall_side == FACING_NORTH)
	{
//		tex_x = vrs->tx_n->width * (vrs->ray_pos_x - floor(vrs->ray_pos_x));
//		tex_y = vrs->tx_n->height * wall_y;
//		char *pixel = vrs->tx_n->img_data_addr + (tex_x * vrs->tx_n->bits_p_px / 8) \
//				+ (tex_y * vrs->tx_n->ln_len);
//		vrs->wall_color = *(unsigned int *)pixel;
		vrs->wall_color = 0x00FF0000;
	}
	else if (vrs->wall_side == FACING_SOUTH)
		vrs->wall_color = 0x0000FF00;
	else if (vrs->wall_side == FACING_EAST)
		vrs->wall_color = 0x000000FF;
	else if (vrs->wall_side == FACING_WEST)
		vrs->wall_color = 0x0000FFFF;
}

void	draw_vert_line(int x, t_vars *vrs)
{
	int	y;
	int	y_start;
	int	y_stop;

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
		set_pixel_color(vrs, (y - y_start) / vrs->wall_height);
		print_pixel(x, y, vrs, vrs->wall_color);
		y++;
	}
	while (y < vrs->img_height)
	{
		print_pixel(x, y, vrs, vrs->floor_clr);
		y++;
	}
}
