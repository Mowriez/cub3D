/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:19:17 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 23:19:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	get_debugging_values(t_vars *vrs)
{
	vrs->ol.d_dist_to_wall = vrs->rc.ray_len;
	vrs->ol.d_wall_hit_x = vrs->rc.ray_pos_x;
	vrs->ol.d_wall_hit_y = vrs->rc.ray_pos_y;
}

static void	print_helper_1(t_vars *vrs)
{
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 15,
		0x0039FF14, "player position x, y:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 15,
		0x0039FF14, vrs->ol.player_pos_x);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 230, 15,
		0x0039FF14, vrs->ol.player_pos_y);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 30,
		0x0039FF14, "wall intersection x, y:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 30,
		0x0039FF14, vrs->ol.wall_hit_x);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 230, 30,
		0x0039FF14, vrs->ol.wall_hit_y);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 45,
		0x0039FF14, "distance to wall:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 45,
		0x0039FF14, vrs->ol.dist_to_wall);
}

	// print_fps(vrs);
void	print_overlay_vars(t_vars *vrs)
{
	print_helper_1(vrs);
}
