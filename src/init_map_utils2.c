/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:28:06 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/10 00:05:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	check_line_valid(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (is_valid_character(line[i]))
			i++;
		else
			break ;
	}
	if (line && line[i] != '\0')
		map->err = 4;
	return (0);
}

void	print_map(t_map *map)
{
	printf(BLU"Map Details:\n"RES);
	printf(YEL"Texture NO: %s\n", map->texture_no);
	printf("Texture SO: %s\n", map->texture_so);
	printf("Texture WE: %s\n", map->texture_we);
	printf("Texture EA: %s\n"RES, map->texture_ea);
	printf(GRE"Color Ceiling usable int value: %d\n", map->color_ceiling);
	printf("Color Floor usable int value: %d\n"RES, map->color_floor);
	printf(CYA"Rows: %d\n", map->height);
	printf("Columns: %d\n"RES, map->width);
}
