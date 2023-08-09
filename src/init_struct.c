/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:54:50 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 22:16:35 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	init_mlx_session(t_vars *vrs)
{
	vrs->mlx_ptr = mlx_init();
	vrs->win_width = WIN_WIDTH;
	vrs->win_height = (double) round(WIN_WIDTH / 1.77);
	vrs->win_ptr = mlx_new_window(vrs->mlx_ptr, vrs->win_width,
			vrs->win_height, "cub3d");
}

static void	init_main_img(t_vars *vrs)
{
	vrs->main_img.width = vrs->win_width;
	vrs->main_img.height = vrs->win_height;
	vrs->main_img.img_ptr = mlx_new_image(vrs->mlx_ptr, vrs->main_img.width,
			vrs->main_img.height);
	vrs->main_img.data_addr = mlx_get_data_addr(vrs->main_img.img_ptr,
			&vrs->main_img.bpp, &vrs->main_img.ln_len,
			&vrs->main_img.endian);
}

static void	init_rc_vars(t_vars *vrs)
{
	vrs->rc.pl_pos_x = 0;
	vrs->rc.pl_pos_y = 0;
	vrs->rc.view_angle = 0;
	vrs->rc.fov_angle = 0;
	vrs->rc.ray_pos_x = 0;
	vrs->rc.ray_pos_y = 0;
	vrs->rc.ray_last_pos_x = 0;
	vrs->rc.ray_last_pos_y = 0;
	vrs->rc.ray_len = 0;
	vrs->rc.angle_betw_rays = 0;
	vrs->rc.wall_side = 0;
	vrs->rc.wall_height = 0;
	vrs->prev_x = 0;
}

static void	set_game_vars(t_vars *vrs)
{
	vrs->show_overlay = false;
	vrs->ol.last_sec_change = 0;
	vrs->ol.fps_i = 60;
	vrs->ol.last_loop_time = 0;
	vrs->ol.frames = 0;
	init_input_keys(vrs);
	init_rc_vars(vrs);
}

int	parse_init_struct(char**argv, t_vars *vrs)
{
	init_mlx_session(vrs);
	init_main_img(vrs);
	set_game_vars(vrs);
	if (init_map(vrs, argv))
	{
		mlx_destroy_image(vrs->mlx_ptr, vrs->main_img.img_ptr);
		mlx_destroy_window(vrs->mlx_ptr, vrs->win_ptr);
		free(vrs->mlx_ptr);
		return (1);
	}
	init_textures(vrs);
	init_minimap(vrs);
	vrs->map.map[(int)vrs->rc.pl_pos_y][(int)vrs->rc.pl_pos_x] = '0';
	return (0);
}
