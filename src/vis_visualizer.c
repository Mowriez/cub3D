/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_visualizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 02:17:40 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/31 14:20:18 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_pixel(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	pixel = vrs->img_data_addr + (x * vrs->bits_p_px / 8) \
			+ (y * vrs->ln_len);
	*(unsigned int *)pixel = color;
}


static void	draw_vert_line(int x, t_vars *vrs)
{
	int y = 0;
	int y_start = (0.5 * vrs->img_height) - (0.5 * vrs->wall_height);
	int y_stop = (0.5 * vrs->img_height) + (0.5 * vrs->wall_height);

	if (vrs->side == 'n' || vrs->side == 's')
		vrs->wall_color = 0x00FF0000;
	else if (vrs->side == 'w' || vrs->side == 'e')
		vrs->wall_color = 0x0000FF00;
	while (y < y_start)
	{
		print_pixel(x, y, vrs, vrs->sky_clr);
		y++;
	}
	while (y < y_stop)
	{
		print_pixel(x, y, vrs, vrs->wall_color);
		y++;
	}
	while (y < vrs->img_height)
	{
		print_pixel(x, y, vrs, vrs->floor_clr);
		y++;
	}
}

void	visualize(t_vars *vrs)
{
	
	int	img_x = 0;
	int	wall_hit = 0;
	while(img_x < vrs->img_width)
	{
		// cam_x needs to be negative for the left side of the screen to 
		//correctly calc the ray direction;
		vrs->cam_x = (2 * img_x / vrs->img_width) - 1;
		// ray directions calculated from known values, basically forming
		// the field of view.
		vrs->r_dir_x = vrs->v_dir_x + (vrs->plane_x * vrs->cam_x);
		vrs->r_dir_y = vrs->v_dir_y + (vrs->plane_y * vrs->cam_x);

		// position block of the map the player is in
		vrs->grid_x = (int)(vrs->pos_x);
		vrs->grid_y = (int)(vrs->pos_y);

		// full distance for ray between grid intersections
		if (vrs->r_dir_x == 0)
			vrs->full_dist_x = DBL_MAX;
		else
			vrs->full_dist_x = sqrt(1 + (pow(vrs->r_dir_y, 2) / pow(vrs->r_dir_x, 2)));
		if (vrs->r_dir_y == 0)
			vrs->full_dist_y = DBL_MAX;
		else
			vrs->full_dist_y = sqrt(1 + (pow(vrs->r_dir_x, 2) / pow(vrs->r_dir_y, 2)));

		// variables for ray prop calculation (which direction to calculate in and fractional distances to first intersection)
		if (vrs->r_dir_x < 0)
		{
			vrs->step_x = -1;
			vrs->side_dist_x = (vrs->pos_x - vrs->grid_x) * vrs->full_dist_x;
		}
		else
		{
			vrs->step_x = 1;
			vrs->side_dist_x = (1.0 - vrs->pos_x + vrs->grid_x) * vrs->full_dist_x;
		}
		if (vrs->r_dir_y < 0)
		{
			vrs->step_y = -1;
			vrs->side_dist_y = (vrs->pos_y - vrs->grid_y) * vrs->full_dist_y;
		}
		else
		{
			vrs->step_y = 1;
			vrs->side_dist_y = (1.0 - vrs->pos_y + vrs->grid_y) * vrs->full_dist_y;
		}
		// actual ray prop calculation
		while (!wall_hit)
		{
			// printf(RED"here\n"RES);
			//jump to next map square, either in x-direction, or in y-direction
			if (vrs->side_dist_x < vrs->side_dist_y) // if closer to gridline in x direction, jump into next x-block
			{
				vrs->side_dist_x += vrs->full_dist_x;
				vrs->grid_x += vrs->step_x;
				if (vrs->step_x > 0)
					vrs->side = 'w';
				else
					vrs->side = 'e';
			}
			else
			{
				vrs->side_dist_y += vrs->full_dist_y;
				vrs->grid_y += vrs->step_y;
				if (vrs->step_y > 0)
					vrs->side = 's';
				else
					vrs->side = 'n';
			}
			// printf("grid_x: %i, grid_y: %i\n", vrs->grid_x, vrs->grid_y);
			//Check if ray has hit a wall
			if (vrs->map[vrs->grid_y][vrs->grid_x] == '1')
				wall_hit = 1;
		}
		// printf(RED"here2\n"RES);
		if (vrs->side == 'w' || vrs->side == 'e') 
			vrs->p_w_dist = (vrs->side_dist_x - vrs->full_dist_x);
		else
			vrs->p_w_dist = (vrs->side_dist_y - vrs->full_dist_y);
		// calculate wall height and paint function
		vrs->wall_height = (int)((vrs->img_height / vrs->p_w_dist) / 2);
		draw_vert_line(img_x, vrs);
		wall_hit = 0;
		img_x++;
	}
}