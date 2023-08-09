/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_map_identifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:15:19 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/09 20:09:42 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static char	*ft_strdup_skip_space(const char *s)
{
	char	*output;

	while (*s == ' ')
		s++;
	(output = ft_strdup(s));
	return (output);
}

static int	ft_check_number_rgb(char *s)
{
	int	value;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	value = ft_atoi(s);
	if (value > 255 || value < 0)
		return (-1);
	return (value);
}

int	ft_assign_map_identifiers(t_map *map, char *input, int i)
{
	if (ft_strncmp(&input[i], "C ", 2) == 0 && map->color_ceiling == -1)
	{
		map->color_ceiling = ft_get_rgb_color(&input[i + 2]);
		if (map->color_ceiling == -1)
			return (set_error_value(map, 1));
	}
	else if (ft_strncmp(&input[i], "F ", 2) == 0 && map->color_floor == -1)
	{
		map->color_floor = ft_get_rgb_color(&input[i + 2]);
		if (map->color_floor == -1)
			return (set_error_value(map, 2));
	}
	else if (ft_strncmp(&input[i], "NO ", 3) == 0 && !map->texture_no)
		map->texture_no = ft_strdup_skip_space(&input[i + 3]);
	else if (ft_strncmp(&input[i], "SO ", 3) == 0 && !map->texture_so)
		map->texture_so = ft_strdup_skip_space(&input[i + 3]);
	else if (ft_strncmp(&input[i], "WE ", 3) == 0 && !map->texture_we)
		map->texture_we = ft_strdup_skip_space(&input[i + 3]);
	else if (ft_strncmp(&input[i], "EA ", 3) == 0 && !map->texture_ea)
		map->texture_ea = ft_strdup_skip_space(&input[i + 3]);
	else
		return (set_error_value(map, 3));
	return (EXIT_SUCCESS);
}

int	ft_get_rgb_color(char *s)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	while (*s == ' ')
		s++;
	rgb = ft_split(s, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		ft_free_char_array(rgb);
		return (-1);
	}
	printf("Contents of rgb array: [%s] [%s] [%s]\n", rgb[0], rgb[1], rgb[2]);
	red = ft_check_number_rgb(rgb[0]);
	green = ft_check_number_rgb(rgb[1]);
	blue = ft_check_number_rgb(rgb[2]);
	ft_free_char_array(rgb);
	if (red == -1 || green == -1 || blue == -1)
		return (-1);
	return ((red << 16) | (green << 8) | blue);
}
