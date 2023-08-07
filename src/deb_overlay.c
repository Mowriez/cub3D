/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_overlay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:49:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 14:29:32 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	set_overlay_vars(t_overlay *ol, t_vars *vrs)
{
	ol->fps = ft_itoa(vrs->ol.fps_i);
	ol->player_pos_x = dtoa(vrs->rc->pl_pos_x, 3);
	ol->player_pos_y = dtoa(vrs->rc->pl_pos_y, 3);
	ol->dist_to_wall = dtoa(vrs->ol.d_dist_to_wall, 3);
	ol->wall_hit_x = dtoa(vrs->ol.d_wall_hit_x, 3);
	ol->wall_hit_y = dtoa(vrs->ol.d_wall_hit_y, 3);
}

static void	free_overlay_vars(t_overlay *ol)
{
	free(ol->fps);
	free(ol->player_pos_x);
	free(ol->player_pos_y);
	free(ol->dist_to_wall);
	free(ol->wall_hit_x);
	free(ol->wall_hit_y);
}

void	draw_debugging_overlay(t_vars *vrs)
{
	t_overlay	ol;

	set_overlay_vars(&ol, vrs);
	print_overlay_vars(&ol, vrs);
	free_overlay_vars(&ol);
}
