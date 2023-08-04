/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:01:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/04 09:06:48 by mtrautne         ###   ########.fr       */
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
	vrs->m_color_view_cone = 0x0039FF14;
}

// void	init_textures(t_vars *vrs)
// {
//	t_text *tx_n;
//
//	tx_n = malloc(sizeof(t_text));
//	vrs->tx_n = tx_n;
//
// 	tx_n->path_to_file = "../tex/wall_tex.xpm";
// 	tx_n->img_ptr = mlx_xpm_file_to_image(vrs->mlx_ptr,
// 		tx_n->path_to_file, &tx_n->width, &vrs->tx_n->height);
//	tx_n->img_data_addr = mlx_get_data_addr(tx_n->img_ptr, \
//		&tx_n->bits_p_px, &tx_n->ln_len, &tx_n->endian);
// }