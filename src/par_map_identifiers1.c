/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_map_identifiers1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:56:40 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/10 10:58:14 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	ft_line_from_map(t_map *map, char *line)
{
	if (map->line_array == NULL)
	{
		map->line_array = malloc(sizeof(char *));
		if (map->line_array == NULL)
			ft_custom_exit("malloc failed");
	}
	else
	{
		map->line_array = ft_realloc(map->line_array, sizeof(char *)
				* (map->line_count),
				sizeof(char *) * (map->line_count + 1));
		if (map->line_array == NULL)
			ft_custom_exit("malloc failed");
	}
	map->line_array[map->line_count] = ft_strdup(line);
	if (map->line_array[map->line_count] == NULL)
		ft_custom_exit("malloc failed");
	map->line_count++;
	ft_assign_map_identifiers(map, map->line_array[map->line_count - 1], 0);
}

bool	is_identifier(const char *line, const char *identifier)
{
	return (ft_strncmp(line, identifier, ft_strlen(identifier)) == 0);
}

void	process_line(t_map *map, char *trimmed_line)
{
	if (is_identifier(trimmed_line, "NO")
		|| is_identifier(trimmed_line, "SO")
		|| is_identifier(trimmed_line, "WE")
		|| is_identifier(trimmed_line, "EA")
		|| is_identifier(trimmed_line, "F")
		|| is_identifier(trimmed_line, "C"))
	{
		ft_line_from_map(map, trimmed_line);
	}
}

void	parse_map_identifier(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	*trimmed_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_custom_exit("Error opening file");
	while (1)
	{
		line = parse_next_line(fd);
		if (line == NULL)
			break ;
		trimmed_line = line;
		while (*trimmed_line == ' ')
			trimmed_line++;
		if ((ft_strncmp(trimmed_line, "NO", 2) == 0
				|| ft_strncmp(trimmed_line, "SO", 2) == 0
				|| ft_strncmp(trimmed_line, "WE", 2) == 0
				|| ft_strncmp(trimmed_line, "EA", 2) == 0
				|| ft_strncmp(trimmed_line, "F", 1) == 0
				|| ft_strncmp(trimmed_line, "C", 1) == 0))
			process_line(map, trimmed_line);
		free(line);
	}
	close(fd);
}
