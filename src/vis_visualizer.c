/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_visualizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 02:17:40 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/02 23:28:17 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_pixel(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	pixel = vrs->img_data_addr + (x * vrs->bits_p_px / 8) + (y * vrs->ln_len);
	*(unsigned int *)pixel = color;
}


static void	draw_vert_line(int x, t_vars *vrs)
{
	int y = 0;
	int y_start = (0.5 * vrs->img_height) - (0.5 * vrs->wall_height);
	int y_stop = (0.5 * vrs->img_height) + (0.5 * vrs->wall_height);

	if (vrs->wall_side == FACING_NORTH)
		vrs->wall_color = 0x00FF0000;
	else if (vrs->wall_side == FACING_SOUTH)
		vrs->wall_color = 0x0000FF00;
	else if (vrs->wall_side == FACING_EAST)
		vrs->wall_color = 0x000000FF;
	else if (vrs->wall_side == FACING_WEST)
		vrs->wall_color = 0x0000FFFF;
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

	while(img_x < vrs->img_width)
	{
		vrs->wall_hit = 0;
		vrs->ray_len = 0;
		vrs->ray_angle = vrs->view_angle + (0.5 * vrs->fov_angle) - \
			(img_x * vrs->angle_betw_rays);
		// camera plane is distance 1 in view direction from player position
		vrs->cam_plane_ray_int_x = vrs->player_pos_x + cos(vrs->ray_angle);
		vrs->cam_plane_ray_int_y = vrs->player_pos_y + sin(vrs->ray_angle);
		vrs->ray_pos_x = vrs->cam_plane_ray_int_x;
		vrs->ray_pos_y = vrs->cam_plane_ray_int_y;
		vrs->ray_grid_x = (int)floor(vrs->ray_pos_x);
		vrs->ray_grid_y = (int)floor(vrs->ray_pos_y);
		// calculate fstep from current ray position to next intersecting gridline and check for wall in that grid block
		// printf("player_x: %f | player_y: %f | vrs->wall_hit: %i | vrs->ray_len: %f | vrs->ray_angle %f\n"
		// "vrs->cam_plane_ray_int_x: %f | vrs->cam_plane_ray_int_y: %f\n"
		// "vrs->ray_pos_x %f | vrs->ray_pos_y: %f | vrs->ray_grid_x: %i | vrs->ray_grid_y: %i\n", vrs->player_pos_x, vrs->player_pos_y, vrs->wall_hit, vrs->ray_len, vrs->ray_angle, vrs->cam_plane_ray_int_x, vrs->cam_plane_ray_int_y,vrs->ray_pos_x, vrs->ray_pos_y, vrs->ray_grid_x, vrs->ray_grid_y);
		while (!vrs->wall_hit)
		{
			// direction of ray normed (angles over 2pi will be treated as fraction of angle < 2pi)
			// and ray dist to gridline in y/x direction
			if (sin(vrs->ray_angle) >= 0)
			{
				vrs->ray_dir_ns = DIR_NORTH;
				vrs->ray_dist_gridline_y = vrs->ray_pos_y - floor(vrs->ray_pos_y);
				if(vrs->ray_dist_gridline_y == 0)
					vrs->ray_dist_gridline_y = 1;
			}
			else if	(sin(vrs->ray_angle) < 0)
			{
				vrs->ray_dir_ns = DIR_SOUTH;
				vrs->ray_dist_gridline_y = 1 - (vrs->ray_pos_y - floor(vrs->ray_pos_y));
				if(vrs->ray_dist_gridline_y == 0)
					vrs->ray_dist_gridline_y = 1;
			}
			if	(cos(vrs->ray_angle) >= 0)
			{
				vrs->ray_dir_ew = DIR_EAST;
				vrs->ray_dist_gridline_x = 1 - (vrs->ray_pos_x - floor(vrs->ray_pos_x));
				if(vrs->ray_dist_gridline_x == 0)
					vrs->ray_dist_gridline_x = 1;
			}
			else if	(cos(vrs->ray_angle) < 0)
			{
				vrs->ray_dir_ew = DIR_WEST;
				vrs->ray_dist_gridline_x = vrs->ray_pos_x - floor(vrs->ray_pos_x);
				if(vrs->ray_dist_gridline_x == 0)
					vrs->ray_dist_gridline_x = 1;
			}
			// printf("floor ray_pos_x: %f\n", floor(vrs->ray_pos_x));
			// printf("ray_angle: %f | ray_dir_ns: %i | ray_dir_ew: %i | ray_pos x | y: %f | %f   ray_dist x | y: %f | %f\n", vrs->ray_angle, vrs->ray_dir_ns, vrs->ray_dir_ew, vrs->ray_pos_x, vrs->ray_pos_y,vrs->ray_dist_gridline_x, vrs->ray_dist_gridline_y);
			// calculate distance to grid for both directions (making sure not to divide by 0)
			if (cos(vrs->ray_angle) == 0)
				vrs->ray_len_to_gridline_x = 100000.0;
			else
				vrs->ray_len_to_gridline_x = fabs(vrs->ray_dist_gridline_x / cos(vrs->ray_angle));
			if (sin(vrs->ray_angle) == 0)
				vrs->ray_len_to_gridline_y = 100000.0;
			else
				vrs->ray_len_to_gridline_y = fabs(vrs->ray_dist_gridline_y / sin(vrs->ray_angle));
			// printf("vrs->ray_len_to_gridline_x: %f | vrs->ray_len_to_gridline_y: %f\n", vrs->ray_len_to_gridline_x, vrs->ray_len_to_gridline_y);
			// if length to intersection with vertical (x-) grid line is closer,
			//calculate length and new position on x-grid line;
			if (vrs->ray_len_to_gridline_x < vrs->ray_len_to_gridline_y)
			{
				if (vrs->ray_dir_ew == DIR_EAST)
					vrs->wall_side = FACING_WEST;
				else
					vrs->wall_side = FACING_EAST;
				vrs->ray_len += vrs->ray_len_to_gridline_x;
				vrs->ray_pos_y -= (sin(vrs->ray_angle) * vrs->ray_len_to_gridline_x);
				vrs->ray_pos_x += (cos(vrs->ray_angle) * vrs->ray_len_to_gridline_x);
				// printf("Ray len: %f\n", vrs->ray_len);
				if (vrs->ray_dir_ew == DIR_EAST)
					vrs->ray_grid_x += 1;
				else if (vrs->ray_dir_ew == DIR_WEST)
					vrs->ray_grid_x -= 1;
			}
			// else if length to intersection with horizontal (y-) grid line is closer,
			//calculate length and new position on y-grid line;
			else if (vrs->ray_len_to_gridline_y < vrs->ray_len_to_gridline_x)
			{
				if (vrs->ray_dir_ns == DIR_NORTH)
					vrs->wall_side = FACING_SOUTH;
				else
					vrs->wall_side = FACING_NORTH;
				vrs->ray_len += vrs->ray_len_to_gridline_y;
				// printf("Ray len: %f\n", vrs->ray_len);
				vrs->ray_pos_y -= (sin(vrs->ray_angle) * vrs->ray_len_to_gridline_y);
				vrs->ray_pos_x += (cos(vrs->ray_angle) * vrs->ray_len_to_gridline_y);
				if (vrs->ray_dir_ns == DIR_NORTH)
					vrs->ray_grid_y -= 1;
				else if (vrs->ray_dir_ns == DIR_SOUTH)
					vrs->ray_grid_y += 1;
			}
			if (vrs->map[vrs->ray_grid_y][vrs->ray_grid_x] == '1')
				vrs->wall_hit = 1;
		}
		vrs->ray_len = sqrt(pow(vrs->ray_pos_x - vrs->cam_plane_ray_int_x, 2) + pow(vrs->ray_pos_y - vrs->cam_plane_ray_int_y, 2));
		vrs->ray_len = cos(vrs->ray_angle - vrs->view_angle) * vrs->ray_len;
		vrs->wall_height = (int)((vrs->img_height / vrs->ray_len) / 2);
		if (vrs->wall_height > vrs->img_height)
			vrs->wall_height = vrs->img_height;
		draw_vert_line(img_x, vrs);
		img_x++;
	}
}
//// easy version without calculating the intersection directions
//void	visualize(t_vars *vrs)
//{
//	int	img_x = 0; // x-value of image, for that distance to wall is calculated;
//	vrs->ray_precision = 1000;
//	while (img_x < vrs->img_width)
//	{
//		vrs->wall = 0;
//		vrs->ray_angle = vrs->view_angle - (0.5 * vrs->fov_angle) +
//						(img_x * vrs->angle_betw_rays);
//		vrs->ray_pos_x = vrs->player_pos_x;
//		vrs->ray_pos_y = vrs->player_pos_y;
//		while (!vrs->wall)
//		{
//			vrs->ray_pos_x += cos(vrs->ray_angle) / vrs->ray_precision;
//			vrs->ray_pos_y += sin(vrs->ray_angle) / vrs->ray_precision;
//			if (vrs->map[(int)(vrs->ray_pos_y)][(int)(vrs->ray_pos_x)] == '1')
//				vrs->wall = 1;
//		}
//		vrs->ray_dist = sqrt(pow(vrs->ray_pos_x - vrs->player_pos_x, 2) + pow(vrs->ray_pos_y - vrs->player_pos_y, 2));
//		vrs->wall_height = (int)((vrs->img_height / vrs->ray_dist) / 2);
//		draw_vert_line(img_x, vrs);
//		img_x++;
//	}
//}


//! deprecated version, will maybe be revived later
// void	visualize(t_vars *vrs)
// {
	
// 	int	img_x = 0;
// 	int	wall_hit = 0;
// 	while(img_x < vrs->img_width)
// 	{
// 		// cam_x needs to be negative for the left side of the screen to 
// 		//correctly calc the ray direction;
// 		vrs->cam_x = (2 * img_x / vrs->img_width) - 1;
// 		// ray directions calculated from known values, basically forming
// 		// the field of view.
// 		vrs->r_dir_x = vrs->v_dir_x + (vrs->plane_x * vrs->cam_x);
// 		vrs->r_dir_y = vrs->v_dir_y + (vrs->plane_y * vrs->cam_x);

// 		// position block of the map the player is in
// 		vrs->grid_x = (int)(vrs->pos_x);
// 		vrs->grid_y = (int)(vrs->pos_y);

// 		// full distance for ray between grid intersections
// 		if (vrs->r_dir_x == 0)
// 			vrs->full_dist_x = DBL_MAX;
// 		else
// 			vrs->full_dist_x = sqrt(1 + (pow(vrs->r_dir_y, 2) / pow(vrs->r_dir_x, 2)));
// 		if (vrs->r_dir_y == 0)
// 			vrs->full_dist_y = DBL_MAX;
// 		else
// 			vrs->full_dist_y = sqrt(1 + (pow(vrs->r_dir_x, 2) / pow(vrs->r_dir_y, 2)));

// 		// variables for ray prop calculation (which direction to calculate in and fractional distances to first intersection)
// 		if (vrs->r_dir_x < 0)
// 		{
// 			vrs->step_x = -1;
// 			vrs->side_dist_x = (vrs->pos_x - vrs->grid_x) * vrs->full_dist_x;
// 		}
// 		else
// 		{
// 			vrs->step_x = 1;
// 			vrs->side_dist_x = (1.0 - vrs->pos_x + vrs->grid_x) * vrs->full_dist_x;
// 		}
// 		if (vrs->r_dir_y < 0)
// 		{
// 			vrs->step_y = -1;
// 			vrs->side_dist_y = (vrs->pos_y - vrs->grid_y) * vrs->full_dist_y;
// 		}
// 		else
// 		{
// 			vrs->step_y = 1;
// 			vrs->side_dist_y = (1.0 - vrs->pos_y + vrs->grid_y) * vrs->full_dist_y;
// 		}
// 		// actual ray prop calculation
// 		while (!wall_hit)
// 		{
// 			// printf(RED"here\n"RES);
// 			//jump to next map square, either in x-direction, or in y-direction
// 			if (vrs->side_dist_x < vrs->side_dist_y) // if closer to gridline in x direction, jump into next x-block
// 			{
// 				vrs->side_dist_x += vrs->full_dist_x;
// 				vrs->grid_x += vrs->step_x;
// 				if (vrs->step_x > 0)
// 					vrs->side = 'w';
// 				else
// 					vrs->side = 'e';
// 			}
// 			else
// 			{
// 				vrs->side_dist_y += vrs->full_dist_y;
// 				vrs->grid_y += vrs->step_y;
// 				if (vrs->step_y > 0)
// 					vrs->side = 's';
// 				else
// 					vrs->side = 'n';
// 			}
// 			// printf("grid_x: %i, grid_y: %i\n", vrs->grid_x, vrs->grid_y);
// 			//Check if ray has hit a wall
// 			if (vrs->map[vrs->grid_y][vrs->grid_x] == '1')
// 				wall_hit = 1;
// 		}
// 		// printf(RED"here2\n"RES);
// 		if (vrs->side == 'w' || vrs->side == 'e') 
// 			vrs->p_w_dist = (vrs->side_dist_x - vrs->full_dist_x);
// 		else
// 			vrs->p_w_dist = (vrs->side_dist_y - vrs->full_dist_y);
// 		// calculate wall height and paint function
// 		vrs->wall_height = (int)((vrs->img_height / vrs->p_w_dist) / 2);
// 		draw_vert_line(img_x, vrs);
// 		wall_hit = 0;
// 		img_x++;
// 	}
// }