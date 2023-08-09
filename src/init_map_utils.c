/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:14:57 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 08:18:39 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	check_line_for_map_start(char *line, int *map_start)
{
	int i = 0;
	if (line[0] == '\0')
		return ;
	while (line[i] != '\0')
	{
		if (is_valid_character(line[i]))
			i++;
		else
			break;
	}
	if (line[i] == '\0')
	{
		*map_start = 1;
	}
}

static void	generate_blank_map_array(t_map *map)
{
	int	i;
	int j;

	i = 0;
	map->map = malloc(sizeof(char*) * (map->height + 1));
	map->map[map->height] = NULL;
	while (i < map->height)
	{
		j = 0;
		map->map[i] = malloc(sizeof(char) * (map->width + 1));
		while (j <= map->width)
		{
			if (j == map->width)
				map->map[i][j] = '\0';
			else
				map->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

static void fill_array_line(const char *line, int i, char **map)
{
	int	j = 0;
	while(line[j])
	{
		map[i][j] = line[j];
		j++;
	}
}

void	fill_map_array(t_map *map, char **av)
{
	char *line;
	int map_start;
	int i = 0;
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_custom_exit("Error opening file");

	map_start = 0;
	while (1)
	{
		line = parse_next_line(fd);
		if (line == NULL)
			break ;
		if (!map_start)
			check_line_for_map_start(line, &map_start);
		if (map_start)
		{
			fill_array_line(line, i, map->map);
			i++;
		}
		free(line);
	}
}

void	generate_map_layout(t_map *map, char **av)
{
	char *line;
	int map_start;
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_custom_exit("Error opening file");
	map->height = 0;
	map_start = 0;
	while (1)
	{
		line = parse_next_line(fd);
		if (line == NULL)
			break ;
		if (!map_start)
			check_line_for_map_start(line, &map_start);
		if (map_start)
		{
			map->height++;
			if ((int)ft_strlen(line) > map->width)
				map->width = (int)ft_strlen(line);
		}
		free(line);
	}
	generate_blank_map_array(map);
	close (fd);
}
