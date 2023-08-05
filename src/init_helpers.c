/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:01:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 20:09:44 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

bool	is_specific_char(const char c, const char *char_set)
{
	int	i;

	i = 0;
	while (char_set[i])
	{
		if (c == char_set[i])
			return (true);
		else
			i++;
	}
	return (false);
}

void	init_minimap(t_vars *vrs)
{
	vrs->m_width = vrs->img_width / 5;
	vrs->m_height = vrs->img_height / (5 / 1.77);
	vrs->m_img_ptr = mlx_new_image(vrs->mlx_ptr, vrs->m_width, vrs->m_height);
	vrs->m_img_data_addr = mlx_get_data_addr(vrs->m_img_ptr, \
		&vrs->m_bits_p_px, &vrs->m_ln_len, &vrs->m_endian);
	vrs->m_color_wall = 0x00b88428;
	vrs->m_color_floor = 0x00bebebe;
	vrs->m_color_player = 0x00223311;
	vrs->m_color_view_cone = 0x9939FF14;
}

void	init_textures(t_vars *vrs)
{
	init_texture_n(vrs);
	init_texture_s(vrs);
	init_texture_w(vrs);
	init_texture_e(vrs);

}

void	init_texture_n(t_vars *vrs)
{
	vrs->tx_n = malloc(sizeof(t_text));

	vrs->tx_n->path_to_file = "./tex/brick_north.xpm";
	printf("ptf: %s\n", vrs->tx_n->path_to_file);
	vrs->tx_n->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,
		vrs->tx_n->path_to_file, &vrs->tx_n->width, &vrs->tx_n->height);
	printf("img_ptr: %p, width: %i, height: %i\n",
		vrs->tx_n->img_ptr, vrs->tx_n->width, vrs->tx_n->height);
	vrs->tx_n->img_data_addr = mlx_get_data_addr(vrs->tx_n->img_ptr, \
		&vrs->tx_n->bits_p_px, &vrs->tx_n->ln_len, &vrs->tx_n->endian);
}

void	init_texture_s(t_vars *vrs)
{
	vrs->tx_s = malloc(sizeof(t_text));
	vrs->tx_s->path_to_file = "./tex/brick_south.xpm";
	printf("ptf: %s\n", vrs->tx_s->path_to_file);
	vrs->tx_s->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,vrs->tx_s->path_to_file, &vrs->tx_s->width, &vrs->tx_s->height);
	printf("img_ptr: %p, width: %i, height: %i\n",
	   vrs->tx_s->img_ptr, vrs->tx_s->width, vrs->tx_s->height);
	vrs->tx_s->img_data_addr = mlx_get_data_addr(vrs->tx_s->img_ptr, \
		&vrs->tx_s->bits_p_px, &vrs->tx_s->ln_len, &vrs->tx_s->endian);
}

void	init_texture_w(t_vars *vrs)
{
	vrs->tx_w = malloc(sizeof(t_text));
	vrs->tx_w->path_to_file = "./tex/brick_west.xpm";
	printf("ptf: %s\n", vrs->tx_w->path_to_file);
	vrs->tx_w->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,vrs->tx_w->path_to_file, &vrs->tx_w->width, &vrs->tx_w->height);
	printf("img_ptr: %p, width: %i, height: %i\n",
		   vrs->tx_w->img_ptr, vrs->tx_w->width, vrs->tx_w->height);
	vrs->tx_w->img_data_addr = mlx_get_data_addr(vrs->tx_w->img_ptr, \
		&vrs->tx_w->bits_p_px, &vrs->tx_w->ln_len, &vrs->tx_w->endian);
}

void	init_texture_e(t_vars *vrs)
{
	vrs->tx_e = malloc(sizeof(t_text));
	vrs->tx_e->path_to_file = "./tex/brick_east.xpm";
	printf("ptf: %s\n", vrs->tx_e->path_to_file);
	vrs->tx_e->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,vrs->tx_e->path_to_file, &vrs->tx_e->width, &vrs->tx_e->height);
	printf("img_ptr: %p, width: %i, height: %i\n",
		   vrs->tx_e->img_ptr, vrs->tx_e->width, vrs->tx_e->height);
	vrs->tx_e->img_data_addr = mlx_get_data_addr(vrs->tx_e->img_ptr, \
		&vrs->tx_e->bits_p_px, &vrs->tx_e->ln_len, &vrs->tx_e->endian);
}
