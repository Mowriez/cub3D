/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_overlay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:49:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 15:51:00 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	set_overlay_vars(t_vars *vrs)
{
	vrs->ol.fps = ft_itoa(vrs->ol.fps_i);
	vrs->ol.player_pos_x = dtoa(vrs->rc.pl_pos_x, 3);
	vrs->ol.player_pos_y = dtoa(vrs->rc.pl_pos_y, 3);
	vrs->ol.dist_to_wall = dtoa(vrs->ol.d_dist_to_wall, 3);
	vrs->ol.wall_hit_x = dtoa(vrs->ol.d_wall_hit_x, 3);
	vrs->ol.wall_hit_y = dtoa(vrs->ol.d_wall_hit_y, 3);
}

static void	free_overlay_vars(t_vars *vrs)
{
	free(vrs->ol.fps);
	free(vrs->ol.player_pos_x);
	free(vrs->ol.player_pos_y);
	free(vrs->ol.dist_to_wall);
	free(vrs->ol.wall_hit_x);
	free(vrs->ol.wall_hit_y);
}

void	draw_debugging_overlay(t_vars *vrs)
{

	set_overlay_vars(vrs);
	print_overlay_vars(vrs);
	free_overlay_vars(vrs);
}
