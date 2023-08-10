/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_map_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:51 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 23:48:54 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static int	is_ok_neighbor(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	closed_nb(char **map, int x, int y)
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
	if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
		return (1);
	return (0);
}

static int	first_checks(char **map, int *x, int *y, int *starting_pos)
{
	if (!is_valid_character(map[*y][*x]))
		return (err_msg("Invalid character in map."));
	if (is_starting_pos(map[*y][*x]))
		(*starting_pos)++;
	return (0);
}

int	is_map_invalid(char **map, int map_w, int map_h)
{
	int	x;
	int	y;
	int	starting_pos;

	y = 0;
	starting_pos = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			if (first_checks(map, &x, &y, &starting_pos) != 0)
				return (1);
			if ((map[y][x] == '0' || is_starting_pos(map[y][x])))
			{
				if (is_border(x, y, map_w, map_h) || !closed_nb(map, x, y))
					return (err_msg("Map not closed."));
			}
			x++;
		}
		y++;
	}
	if (starting_pos != 1)
		return (err_msg("Invalid amount of starting positions."));
	return (0);
}
