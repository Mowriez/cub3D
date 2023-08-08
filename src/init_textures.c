/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:51:40 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/08 00:29:32 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	init_textures(t_vars *vrs)
{
	init_texture_n(vrs);
	init_texture_s(vrs);
	init_texture_w(vrs);
	init_texture_e(vrs);
}

void	init_texture_n(t_vars *vrs)
{
	vrs->tx_n = malloc(sizeof(t_tex));
	vrs->tx_n->path_to_file = vrs->map.texture_no;
	vrs->tx_n->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,
			vrs->tx_n->path_to_file, &vrs->tx_n->width, &vrs->tx_n->height);
	vrs->tx_n->img_data_addr = mlx_get_data_addr(vrs->tx_n->img_ptr,
			&vrs->tx_n->bits_p_px, &vrs->tx_n->ln_len, &vrs->tx_n->endian);
}

void	init_texture_s(t_vars *vrs)
{
	vrs->tx_s = malloc(sizeof(t_tex));
	vrs->tx_s->path_to_file = "./tex/texture_from_hell.xpm";
	vrs->tx_s->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,
			vrs->tx_s->path_to_file, &vrs->tx_s->width, &vrs->tx_s->height);
	vrs->tx_s->img_data_addr = mlx_get_data_addr(vrs->tx_s->img_ptr,
			&vrs->tx_s->bits_p_px, &vrs->tx_s->ln_len, &vrs->tx_s->endian);
}

void	init_texture_w(t_vars *vrs)
{
	vrs->tx_w = malloc(sizeof(t_tex));
	vrs->tx_w->path_to_file = "./tex/texture_from_hell.xpm";
	vrs->tx_w->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,
			vrs->tx_w->path_to_file, &vrs->tx_w->width, &vrs->tx_w->height);
	vrs->tx_w->img_data_addr = mlx_get_data_addr(vrs->tx_w->img_ptr,
			&vrs->tx_w->bits_p_px, &vrs->tx_w->ln_len, &vrs->tx_w->endian);
}

void	init_texture_e(t_vars *vrs)
{
	vrs->tx_e = malloc(sizeof(t_tex));
	vrs->tx_e->path_to_file = "./tex/texture_from_hell.xpm";
	vrs->tx_e->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,
			vrs->tx_e->path_to_file, &vrs->tx_e->width, &vrs->tx_e->height);
	vrs->tx_e->img_data_addr = mlx_get_data_addr(vrs->tx_e->img_ptr,
			&vrs->tx_e->bits_p_px, &vrs->tx_e->ln_len, &vrs->tx_e->endian);
}
