/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_overlay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:49:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 20:57:28 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	count_fps(t_vars *vrs)
{
	struct timeval	s_cur_time;
	double			time_sec;

	gettimeofday(&s_cur_time, NULL);
	time_sec = s_cur_time.tv_sec;
	if (time_sec - vrs->last_sec_change == 0)
		vrs->frames++;
	else
	{
		vrs->fps = vrs->frames;
		vrs->frames = 0;
		vrs->last_sec_change = time_sec;
	}
}

static void	set_overlay_vars(t_overlay *ol, t_vars *vrs)
{
	ol->fps = ft_itoa(vrs->fps);
	ol->player_pos_x = dtoa(vrs->player_pos_x, 3);
	ol->player_pos_y = dtoa(vrs->player_pos_y, 3);
	ol->dist_to_wall = dtoa(vrs->debug_dist_to_wall, 3);
	ol->debug_wall_hit_x = dtoa(vrs->debug_wall_hit_x, 3);
	ol->debug_wall_hit_y = dtoa(vrs->debug_wall_hit_y, 3);
}

static void	free_overlay_vars(t_overlay *ol)
{
	free(ol->fps);
	free(ol->player_pos_x);
	free(ol->player_pos_y);
	free(ol->dist_to_wall);
	free(ol->debug_wall_hit_x);
	free(ol->debug_wall_hit_y);
}

void	draw_debugging_overlay(t_vars *vrs)
{
	t_overlay	ol;

	count_fps(vrs);
	set_overlay_vars(&ol, vrs);
	print_overlay_vars(&ol, vrs);
	free_overlay_vars(&ol);
}
