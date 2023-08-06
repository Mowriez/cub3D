/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:15:19 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/06 13:15:22 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*j;

	i = 0;
	j = malloc((ft_strlen(s1) + 1) * sizeof(char));
	while (i < ft_strlen(s1))
	{
		j[i] = s1[i];
		i++;
	}
	j[i] = '\0';
	return (j);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*j;

	i = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (!s)
		return (0);
	if (len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	j = (char *)malloc((len + 1) * sizeof(char));
	if (!j)
		return (0);
	while (i < len)
	{
		j[i] = s[i + start];
		i++;
	}
	j[i] = '\0';
	return (j);
}


static size_t	ft_word_count(char const *s, char c)
{
	size_t	word_nbr;
	size_t	switch_fct;
	size_t	i;

	word_nbr = 0;
	switch_fct = 0;
	i = 0;
	if (s[i] && s[i] != c)
		word_nbr = 1;
	while (s[i])
	{
		if (s[i] == c)
			switch_fct = 1;
		else if (s[i] != c && switch_fct == 1)
		{
			word_nbr++;
			switch_fct = 0;
		}
		i++;
	}
	return (word_nbr);
}

static size_t	ft_word_len(char const *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static char	**ft_free_if_fail(char **ret, size_t j)
{
	while (j != 0)
	{
		free(ret[j]);
		j--;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**ret;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ret = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (i < ft_strlen(s) && j < ft_word_count(s, c))
	{
		while (s[i] == c)
			i++;
		len = ft_word_len(s, i, c);
		ret[j] = ft_substr(s, i, len);
		if (!(ret[j]))
			return (ft_free_if_fail(ret, j));
		j++;
		i = i + len;
	}
	ret[j] = 0;
	return (ret);
}



int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
							  || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			k = (k * 10) + str[i] - '0';
		}
		else
			return (k * j);
		i++;
	}
	return (k * j);
}


// REMOVE HELPER FUNCTIONS OF LIBFT

typedef struct s_map {
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	int				color_ceiling;
	int				color_floor;
	int				rows;
	int				columns;
} t_map;

void	ft_init_map_identifiers(t_map *map)
{
	map->texture_no = NULL;
	map->texture_so = NULL;
	map->texture_we = NULL;
	map->texture_ea = NULL;
	map->color_ceiling = -1;
	map->color_floor = -1;
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


static int	ft_get_rgb_color(char *s);


int	ft_assign_map_identifier(t_map *map, char *input, int i)
{
	if (ft_strncmp(&input[i], "C ", 2) == 0 && map->color_ceiling == -1)
	{
		map->color_ceiling = ft_get_rgb_color(&input[i + 2]);
		if (map->color_ceiling == -1)
			return (EXIT_FAILURE);
	}
	else if (ft_strncmp(&input[i], "F ", 2) == 0 && map->color_floor == -1)
	{
		map->color_floor = ft_get_rgb_color(&input[i + 2]);
		if (map->color_floor == -1)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check_number_rgb(char *s)
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

void	ft_free_char_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

static int	ft_get_rgb_color(char *s)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	while (*s == ' ')
		s++;
	rgb = ft_split(s, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (-1);
	red = ft_check_number_rgb(rgb[0]);
	green = ft_check_number_rgb(rgb[1]);
	blue = ft_check_number_rgb(rgb[2]);
	ft_free_char_array(rgb);
	if (red == -1 || green == -1 || blue == -1)
		return (-1);
	return ((red << 16) | (green << 8) | blue);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (i + 1) < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void print_map(t_map *map) {
	printf("Texture NO: %s\n", map->texture_no);
	printf("Texture SO: %s\n", map->texture_so);
	printf("Texture WE: %s\n", map->texture_we);
	printf("Texture EA: %s\n", map->texture_ea);
	printf("Color Ceiling: %d\n", map->color_ceiling);
	printf("Color Floor: %d\n", map->color_floor);
	printf("Rows: %d\n", map->rows);
	printf("Columns: %d\n", map->columns);
}

int main() {
	t_map map;
	ft_init_map_identifiers(&map);

	char input1[] = "F 255,255,255";
	char input2[] = "C 225,30,33";

	if (ft_assign_map_identifier(&map, input1, 0) == EXIT_SUCCESS &&
		ft_assign_map_identifier(&map, input2, 0) == EXIT_SUCCESS) {
		printf("Assigned identifiers successfully.\n");

		if (ft_filled_map_identifiers(&map)) {
			printf("All map identifiers are filled.\n");
		} else {
			printf("Some map identifiers are missing.\n");
		}
	} else {
		printf("Failed to assign identifiers.\n");
	}
	printf("Map Details:\n");
	print_map(&map);



	int color_ceiling = map.color_ceiling;

	int redc = (color_ceiling >> 16) & 0xFF;
	int greenc = (color_ceiling >> 8) & 0xFF;
	int bluec = color_ceiling & 0xFF;

	int color_floor = map.color_floor;

	int redf = (color_floor >> 16) & 0xFF;
	int greenf = (color_floor >> 8) & 0xFF;
	int bluef = color_floor & 0xFF;

	printf("RGB values ceiling: R=%d, G=%d, B=%d\n", redc, greenc, bluec);
	printf("RGB values floor: R=%d, G=%d, B=%d\n", redf, greenf, bluef);

	return 0;
}