// void	visualize(t_vars *vrs)
// {
// 	int	img_x = 0;

// 	while(img_x < vrs->img_width)
// 	{
// 		vrs->wall_hit = 0;
// 		vrs->ray_len = 0;
// 		vrs->ray_angle = vrs->view_angle + (0.5 * vrs->fov_angle) - 
// 			(img_x * vrs->angle_betw_rays);
// 		// camera plane is distance 1 in view direction from player position
// 		vrs->cam_plane_ray_int_x = vrs->player_pos_x + cos(vrs->ray_angle);
// 		vrs->cam_plane_ray_int_y = vrs->player_pos_y + sin(vrs->ray_angle);
// 		vrs->ray_pos_x = vrs->cam_plane_ray_int_x;
// 		vrs->ray_pos_y = vrs->cam_plane_ray_int_y;
// 		vrs->ray_grid_x = (int)floor(vrs->ray_pos_x);
// 		vrs->ray_grid_y = (int)floor(vrs->ray_pos_y);
// 		// calculate fstep from current ray position to next intersecting gridline and check for wall in that grid block
// 		// printf("player_x: %f | player_y: %f | vrs->wall_hit: %i | vrs->ray_len: %f | vrs->ray_angle %f\n"
// 		// "vrs->cam_plane_ray_int_x: %f | vrs->cam_plane_ray_int_y: %f\n"
// 		// "vrs->ray_pos_x %f | vrs->ray_pos_y: %f | vrs->ray_grid_x: %i | vrs->ray_grid_y: %i\n", vrs->player_pos_x, vrs->player_pos_y, vrs->wall_hit, vrs->ray_len, vrs->ray_angle, vrs->cam_plane_ray_int_x, vrs->cam_plane_ray_int_y,vrs->ray_pos_x, vrs->ray_pos_y, vrs->ray_grid_x, vrs->ray_grid_y);
// 		while (!vrs->wall_hit)
// 		{
// 			// direction of ray normed (angles over 2pi will be treated as fraction of angle < 2pi)
// 			// and ray dist to gridline in y/x direction
// 			if (sin(vrs->ray_angle) >= 0)
// 			{
// 				vrs->ray_dir_ns = DIR_NORTH;
// 				vrs->ray_dist_gridline_y = vrs->ray_pos_y - floor(vrs->ray_pos_y);
// 				if(vrs->ray_dist_gridline_y == 0)
// 					vrs->ray_dist_gridline_y = 1;
// 			}
// 			else if	(sin(vrs->ray_angle) < 0)
// 			{
// 				vrs->ray_dir_ns = DIR_SOUTH;
// 				vrs->ray_dist_gridline_y = 1 - (vrs->ray_pos_y - floor(vrs->ray_pos_y));
// 				if(vrs->ray_dist_gridline_y == 0)
// 					vrs->ray_dist_gridline_y = 1;
// 			}
// 			if	(cos(vrs->ray_angle) >= 0)
// 			{
// 				vrs->ray_dir_ew = DIR_EAST;
// 				vrs->ray_dist_gridline_x = 1 - (vrs->ray_pos_x - floor(vrs->ray_pos_x));
// 				if(vrs->ray_dist_gridline_x == 0)
// 					vrs->ray_dist_gridline_x = 1;
// 			}
// 			else if	(cos(vrs->ray_angle) < 0)
// 			{
// 				vrs->ray_dir_ew = DIR_WEST;
// 				vrs->ray_dist_gridline_x = vrs->ray_pos_x - floor(vrs->ray_pos_x);
// 				if(vrs->ray_dist_gridline_x == 0)
// 					vrs->ray_dist_gridline_x = 1;
// 			}
// 			// printf("floor ray_pos_x: %f\n", floor(vrs->ray_pos_x));
// 			// printf("ray_angle: %f | ray_dir_ns: %i | ray_dir_ew: %i | ray_pos x | y: %f | %f   ray_dist x | y: %f | %f\n", vrs->ray_angle, vrs->ray_dir_ns, vrs->ray_dir_ew, vrs->ray_pos_x, vrs->ray_pos_y,vrs->ray_dist_gridline_x, vrs->ray_dist_gridline_y);
// 			// calculate distance to grid for both directions (making sure not to divide by 0)
// 			if (cos(vrs->ray_angle) == 0)
// 				vrs->ray_len_to_gridline_x = 100000.0;
// 			else
// 				vrs->ray_len_to_gridline_x = fabs(vrs->ray_dist_gridline_x / cos(vrs->ray_angle));
// 			if (sin(vrs->ray_angle) == 0)
// 				vrs->ray_len_to_gridline_y = 100000.0;
// 			else
// 				vrs->ray_len_to_gridline_y = fabs(vrs->ray_dist_gridline_y / sin(vrs->ray_angle));
// 			// printf("vrs->ray_len_to_gridline_x: %f | vrs->ray_len_to_gridline_y: %f\n", vrs->ray_len_to_gridline_x, vrs->ray_len_to_gridline_y);
// 			// if length to intersection with vertical (x-) grid line is closer,
// 			//calculate length and new position on x-grid line;
// 			if (vrs->ray_len_to_gridline_x < vrs->ray_len_to_gridline_y)
// 			{
// 				if (vrs->ray_dir_ew == DIR_EAST)
// 					vrs->wall_side = FACING_WEST;
// 				else
// 					vrs->wall_side = FACING_EAST;
// 				vrs->ray_len += vrs->ray_len_to_gridline_x;
// 				vrs->ray_pos_y -= (sin(vrs->ray_angle) * vrs->ray_len_to_gridline_x);
// 				vrs->ray_pos_x += (cos(vrs->ray_angle) * vrs->ray_len_to_gridline_x);
// 				// printf("Ray len: %f\n", vrs->ray_len);
// 				if (vrs->ray_dir_ew == DIR_EAST)
// 					vrs->ray_grid_x += 1;
// 				else if (vrs->ray_dir_ew == DIR_WEST)
// 					vrs->ray_grid_x -= 1;
// 			}
// 			// else if length to intersection with horizontal (y-) grid line is closer,
// 			//calculate length and new position on y-grid line;
// 			else if (vrs->ray_len_to_gridline_y < vrs->ray_len_to_gridline_x)
// 			{
// 				if (vrs->ray_dir_ns == DIR_NORTH)
// 					vrs->wall_side = FACING_SOUTH;
// 				else
// 					vrs->wall_side = FACING_NORTH;
// 				vrs->ray_len += vrs->ray_len_to_gridline_y;
// 				// printf("Ray len: %f\n", vrs->ray_len);
// 				vrs->ray_pos_y -= (sin(vrs->ray_angle) * vrs->ray_len_to_gridline_y);
// 				vrs->ray_pos_x += (cos(vrs->ray_angle) * vrs->ray_len_to_gridline_y);
// 				if (vrs->ray_dir_ns == DIR_NORTH)
// 					vrs->ray_grid_y -= 1;
// 				else if (vrs->ray_dir_ns == DIR_SOUTH)
// 					vrs->ray_grid_y += 1;
// 			}
// 			if (vrs->map[vrs->ray_grid_y][vrs->ray_grid_x] == '1')
// 				vrs->wall_hit = 1;
// 		}
// 		vrs->ray_len = sqrt(pow(vrs->ray_pos_x - vrs->cam_plane_ray_int_x, 2) + pow(vrs->ray_pos_y - vrs->cam_plane_ray_int_y, 2));
// 		vrs->ray_len = cos(vrs->ray_angle - vrs->view_angle) * vrs->ray_len;
// 		vrs->wall_height = (int)((vrs->img_height / vrs->ray_len) / 2);
// 		if (vrs->wall_height > vrs->img_height)
// 			vrs->wall_height = vrs->img_height;
// 		draw_vert_line(img_x, vrs);
// 		img_x++;
// 	}
// }


// }
// void	which_side(t_vars *vrs)
// {
// 	if (sin(vrs->ray_angle) >= 0)
// 		vrs->ray_dir_ns = DIR_NORTH;
// 	else if	(sin(vrs->ray_angle) < 0)
// 		vrs->ray_dir_ns = DIR_SOUTH;
// 	if	(cos(vrs->ray_angle) >= 0)
// 		vrs->ray_dir_ew = DIR_EAST;
// 	else if	(cos(vrs->ray_angle) < 0)
// 		vrs->ray_dir_ew = DIR_WEST;
// 	if (vrs->ray_dir_ns == DIR_NORTH)
// 	{
// 		if (vrs->ray_dir_ew == DIR_EAST && fabs(vrs->ray_pos_x - round(vrs->ray_pos_x)) < fabs(vrs->ray_pos_y - round(vrs->ray_pos_y)))
// 			vrs->wall_side = FACING_WEST;
// 		if (vrs->ray_dir_ew == DIR_WEST && fabs(vrs->ray_pos_x - round(vrs->ray_pos_x)) < fabs(vrs->ray_pos_y - round(vrs->ray_pos_y)))
// 			vrs->wall_side = FACING_EAST;
// 		else
// 			vrs->wall_side = FACING_SOUTH;
// 	}
// 	if (vrs->ray_dir_ns == DIR_SOUTH)
// 	{
// 		if (vrs->ray_dir_ew == DIR_EAST && fabs(vrs->ray_pos_x - round(vrs->ray_pos_x)) < fabs(vrs->ray_pos_y - round(vrs->ray_pos_y)))
// 			vrs->wall_side = FACING_WEST;
// 		if (vrs->ray_dir_ew == DIR_WEST && fabs(vrs->ray_pos_x - round(vrs->ray_pos_x)) < fabs(vrs->ray_pos_y - round(vrs->ray_pos_y)))
// 			vrs->wall_side = FACING_EAST;
// 		else
// 			vrs->wall_side = FACING_NORTH;
// 	}

// }