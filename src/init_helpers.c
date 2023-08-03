/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:01:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 23:16:12 by mtrautne         ###   ########.fr       */
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

// void	init_textures(t_vars *vrs)
// {
// 	vrs->tx_n->path_to_file = "./tex/wall_tex.xmp";
// 	vrs->tx_n->addr = mlx_xpm_file_to_image(vrs->mlx_ptr, 
// 		vrs->tx_n->path_to_file, &vrs->tx_n->width, &vrs->tx_n->heigth);
	
	// vrs->tx_s->path_to_file = "./tex/texture_south.xmp";
	// vrs->tx_s->path_to_file = "./tex/texture_south.xmp";
// }