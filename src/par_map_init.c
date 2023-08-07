/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:28:27 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/07 18:28:28 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	ft_init_map_identifiers(t_map *map)
{
	map->texture_no = NULL;
	map->texture_so = NULL;
	map->texture_we = NULL;
	map->texture_ea = NULL;
	map->color_ceiling = -1;
	map->color_floor = -1;
	map->rows = -1;
	map->columns = -1;
	map->line_array = NULL;
	map->line_count = 0;
}

bool	ft_filled_map_identifiers(t_map *level)
{
	if (level->color_ceiling > -1
		&& level->color_floor > -1
		&& level->texture_no != NULL
		&& level->texture_so != NULL
		&& level->texture_we != NULL
		&& level->texture_ea != NULL)
		return (true);
	return (false);
}
