/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_map_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:51 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/08 15:33:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
	{
		return (1);
	}
	return (0);
}

static int	is_starting_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	is_ok_neighbor(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	closed_neighbor(char **map, int x, int y)
{
	if (is_ok_neighbor(map[y - 1][x - 1]) && is_ok_neighbor(map[y - 1][x])
		&& is_ok_neighbor(map[y - 1][x + 1]) && is_ok_neighbor(map[y][x - 1])
		&& is_ok_neighbor(map[y][x + 1]) && is_ok_neighbor(map[y + 1][x - 1])
		&& is_ok_neighbor(map[y + 1][x]) && is_ok_neighbor(map[y + 1][x + 1]))
		return (1);
	return (0);
}

static int	is_border(int x, int y, int width, int height)
{
	if (x == 0 || y == 0 || x == width - 1  || y == height - 1)
		return (1);
	return (0);
}

int	valid_map(char **map, int map_width, int map_height)
{
	int	x;
	int	y;
	int starting_pos;

	y = 0;
	starting_pos = 0;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			if (!is_valid_character(map[y][x]))
				return (err_msg("invalid character in map!"));
			if (is_starting_pos(map[y][x]))
				starting_pos++;
			if ((map[y][x] == '0' || is_starting_pos(map[y][x])))
			{
				if (is_border(x, y, map_width, map_height)
					|| !closed_neighbor(map, x, y))
				{
					return (err_msg("map not closed!"));
				}
			}
			x++;
		}
		y++;
	}
	if (starting_pos != 1)
		return (err_msg("Invalid amount of starting positions!"));
	printf("map valid\n");
	return (0);
}