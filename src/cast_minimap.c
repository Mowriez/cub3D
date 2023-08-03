/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:11:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/04 00:51:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_pixel_1(int x, int y, t_vars *vrs, unsigned int color)
{
	char	*pixel;

	pixel = vrs->m_img_data_addr + (x * vrs->m_bits_p_px / 8)
			+ (y * vrs->m_ln_len);
	*(unsigned int *)pixel = color;
}

void	init_minimap(t_vars *vrs)
{
	vrs->m_width = vrs->img_width / 5;
	vrs->m_height = vrs->img_height / 4;
	vrs->m_img_ptr = mlx_new_image(vrs->mlx_ptr, vrs->m_width, vrs->m_height);
	vrs->m_img_data_addr = mlx_get_data_addr(vrs->m_img_ptr, \
		&vrs->m_bits_p_px, &vrs->m_ln_len, &vrs->m_endian);
}

void	draw_minimap(t_vars *vrs)
{
	int	map_y = 0;
	int	map_x = 0;
	while (map_y < vrs->m_height)
	{
		map_x = 0;
		while (map_x < vrs->m_width)
		{
			if (vrs->map[(map_y / vrs->m_height) * vrs->map_height][(map_x / vrs->m_width) * vrs->map_width] == '0')
				print_pixel_1(map_x, map_y, vrs, 0x00b88428);
			else if (vrs->map[(map_y / vrs->m_height) * vrs->map_height][(map_x / vrs->m_width) * vrs->map_width] == '0')
				print_pixel_1(map_x, map_y, vrs, 0x00bebebe);
			map_x++;
		}
		map_y++;
	}
	print_pixel_1(((vrs->player_pos_x / vrs->map_width) * vrs->m_width), ((vrs->player_pos_y / vrs->map_height) \
			* vrs->m_height), vrs, 0x00FF0000);
}