/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:51:38 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 09:04:01 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	set_player_param(t_vars *vrs, int x, int y)
{
	vrs->rc.pl_pos_x = x + 0.5;
	vrs->rc.pl_pos_y = y + 0.5;
	vrs->rc.fov_angle = FOV_ANGLE_DEG * (M_PI / 180);
	if (vrs->map.map[y][x] == 'N')
		vrs->rc.view_angle = 1.5 * M_PI;
	else if (vrs->map.map[y][x] == 'S')
		vrs->rc.view_angle = 0.5 * M_PI;
	else if (vrs->map.map[y][x] == 'W')
		vrs->rc.view_angle = 1.0 * M_PI;
	else if (vrs->map.map[y][x] == 'E')
		vrs->rc.view_angle = 0;
	vrs->rc.angle_betw_rays = vrs->rc.fov_angle / vrs->main_img.width;
}

static void	find_player_pos(t_vars *vrs)
{
	int	x;
	int	y;

	y = 0;
	while (vrs->map.map[y])
	{
		x = 0;
		while (x < vrs->map.width)
		{
			if (is_specific_char(vrs->map.map[y][x], "NSEW"))
			{
				set_player_param(vrs, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	print_map(t_map *map)
{
	printf("Texture NO: %s\n", map->texture_no);
	printf("Texture SO: %s\n", map->texture_so);
	printf("Texture WE: %s\n", map->texture_we);
	printf("Texture EA: %s\n", map->texture_ea);
	printf("Color Ceiling usable int value: %d\n", map->color_ceiling);
	printf("Color Floor usable int value: %d\n", map->color_floor);
	printf("Rows: %d\n", map->height);
	printf("Columns: %d\n", map->width);
}

static void	fill_map_array(t_map *map, char **av)
{
	char	*line;
	int		map_start;
	int		i;
	int		fd;

	i = 0;
	map_start = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_custom_exit("Error opening file");
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
	close (fd);
}

int	init_map(t_vars *vrs, char **av)
{
	ft_init_map_identifiers(&(vrs->map));
	parse_map_identifier(av[1], &(vrs->map));
	if (!(ft_filled_map_identifiers(&(vrs->map))))
	{
		printf("Some map identifiers are missing.\n");
		ft_free_map(&vrs->map);
		return (1);
	}
	if (!ft_check_all_tex(&(vrs->map)))
	{
		ft_free_map(&vrs->map);
		return (1);
	}
	generate_map_layout(&vrs->map, av);
	fill_map_array(&vrs->map, av);
	printf("Map Details:\n");
	print_map(&vrs->map);
	if (valid_map(vrs->map.map, vrs->map.width, vrs->map.height) != 0)
	{
		ft_free_map(&vrs->map);
		ft_free_char_array(vrs->map.map);
		return (1);
	}
	find_player_pos(vrs);
	return (0);
}
