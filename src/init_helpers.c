/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:01:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 21:55:12 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	init_minimap(t_vars *vrs)
{
	vrs->m_width = vrs->img_width / 5;
	vrs->m_height = vrs->img_height / (5 / 1.77);
	vrs->m_img_ptr = mlx_new_image(vrs->mlx_ptr, vrs->m_width, vrs->m_height);
	vrs->m_img_data_addr = mlx_get_data_addr(vrs->m_img_ptr, \
		&vrs->m_bits_p_px, &vrs->m_ln_len, &vrs->m_endian);
	vrs->m_color_wall = 0x00b88428;
	vrs->m_color_floor = 0xFF333333;
	vrs->m_color_player = 0x00223311;
	vrs->m_color_view_cone = 0x9939FF14;
}

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
