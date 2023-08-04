/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:19:17 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/04 13:17:58 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	get_debugging_values(t_vars *vrs)
{
	vrs->debug_dist_to_wall = vrs->ray_len;
	vrs->debug_wall_hit_x = vrs->ray_pos_x;
	vrs->debug_wall_hit_y = vrs->ray_pos_y;
}

static void	print_helper_1(t_overlay *ol, t_vars *vrs)
{
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 15,
		0x0039FF14, "player position x, y:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 15,
		0x0039FF14, ol->player_pos_x);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 230, 15,
		0x0039FF14, ol->player_pos_y);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 30,
		0x0039FF14, "wall intersection x, y:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 30,
		0x0039FF14, ol->debug_wall_hit_x);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 230, 30,
		0x0039FF14, ol->debug_wall_hit_y);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 45,
		0x0039FF14, "distance to wall:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 45,
		0x0039FF14, ol->dist_to_wall);
}

void	print_overlay_vars(t_overlay *ol, t_vars *vrs)
{
	print_fps(ol, vrs);
	print_helper_1(ol, vrs);
}
