/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:01:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 15:17:37 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	init_minimap(t_vars *vrs)
{
	vrs->m_map.width = vrs->win_width / 5;
	vrs->m_map.height = vrs->win_height / (5 / 1.77);
	vrs->m_map.img_ptr = mlx_new_image(vrs->mlx_ptr, vrs->m_map.width,
			vrs->m_map.height);
	vrs->m_map.data_addr = mlx_get_data_addr(vrs->m_map.img_ptr,
			&vrs->m_map.bpp, &vrs->m_map.ln_len, &vrs->m_map.endian);
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
