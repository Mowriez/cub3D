/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:54:50 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 23:15:57 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

/*	FCT:	initialises vars-struct to starting values;
	ARG:	argv, argc and reference to vrs struct.
	RET:	ptr to vrs, if init succeeds, else NULL-ptr;
*/
static void	init_mlx_vars(t_vars *vrs)
{
	vrs->mlx_ptr = mlx_init();
	vrs->img_width = IMG_WIDTH;
	vrs->img_height = (double)round(vrs->img_width / 1.77);
	vrs->img_ptr = mlx_new_image(vrs->mlx_ptr, vrs->img_width, \
						vrs->img_height);
	vrs->img_data_addr = mlx_get_data_addr(vrs->img_ptr, \
							&vrs->bits_p_px, &vrs->ln_len, &vrs->endian);
	vrs->win_ptr = mlx_new_window(vrs->mlx_ptr, vrs->img_width, \
					vrs->img_height, "cub3d");
}

static void	set_game_vars(t_vars *vrs)
{
	vrs->floor_clr = 0x00000000;
	vrs->sky_clr = 0x00666666;
	vrs->overlay = false;
	vrs->last_sec_change = 0;
	vrs->fps = 60;
	vrs->frames = 0;
	init_input_keys(vrs);
}

int	init_struct(int argc, char**argv, t_vars **vrs)
{
	*vrs = malloc(sizeof(t_vars));
	if (!(*vrs))
		return (err_msg("fatal: malloc failed in struct vrs init."));
	(*vrs)->av = argv;
	(*vrs)->ac = argc;
	init_mlx_vars(*vrs);
	set_game_vars(*vrs);
	// init_textures(*vrs);
	if (init_map(*vrs))
		return (1);
	return (0);
}
