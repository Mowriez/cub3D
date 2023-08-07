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

#include <string.h>
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		l;
	char		*j;

	i = -1;
	l = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	j = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!j)
		return (NULL);
	while (s1[++i])
		j[i] = s1[i];
	while (i < ft_strlen(s1) + ft_strlen(s2) && s2[l])
		j[i++] = s2[l++];
	j[i] = '\0';
	free(s1);
	return (j);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	c = (unsigned char) c;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	return ((char *)s + i);
}

char	*ft_next_line(char *static_str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (!static_str[i])
		return (NULL);
	while (static_str[i] != '\0' && static_str[i] != '\n')
		i++;
	temp = (char *)malloc((i + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	while (static_str[j] != '\0' && static_str[j] != '\n')
	{
		temp[j] = static_str[j];
		j++;
	}
	if (static_str[j] == '\n')
	{
		temp[j] = '\n';
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str[10300];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_str[fd] = ft_read(fd, static_str[fd]);
	if (!static_str[fd])
		return (NULL);
	line = ft_next_line(static_str[fd]);
	static_str[fd] = ft_resize_static_str(static_str[fd]);
	// Remove newline character from the end of the line
	if (line != NULL) {
		size_t len = strlen(line);
		if (len > 0 && line[len - 1] == '\n') {
			line[len - 1] = '\0';
		}
	}
	return (line);
}

char	*ft_read(int fd, char *static_str)
{
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(static_str, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		static_str = ft_strjoin(static_str, temp);
	}
	free(temp);
	return (static_str);
}

char	*ft_resize_static_str(char *static_str)
{
	char	*temp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\0')
	{
		free(static_str);
		return (NULL);
	}
	temp = (char *)malloc((ft_strlen(static_str) - i) * sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	while (static_str[i])
		temp[k++] = static_str[i++];
	temp[k] = '\0';
	free(static_str);
	return (temp);
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
	char 			**line_array; // Array of lines
	int 			line_count;    // Number of lines in the array
} t_map;

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


static int	ft_get_rgb_color(char *s);


char	*ft_strdup_skip_white(const char *s)
{
	char	*output;

	while (*s == ' ')
		s++;
	(output = ft_strdup(s));
	return (output);
}


int	ft_assign_map_identifiers(t_map *map, char *input, int i)
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
	else if (ft_strncmp(&input[i], "NO ", 3) == 0 && !map->texture_no)
		map->texture_no = ft_strdup_skip_white(&input[i + 3]);
	else if (ft_strncmp(&input[i], "SO ", 3) == 0 && !map->texture_so)
		map->texture_so = ft_strdup_skip_white(&input[i + 3]);
	else if (ft_strncmp(&input[i], "WE ", 3) == 0 && !map->texture_we)
		map->texture_we = ft_strdup_skip_white(&input[i + 3]);
	else if (ft_strncmp(&input[i], "EA ", 3) == 0 && !map->texture_ea)
		map->texture_ea = ft_strdup_skip_white(&input[i + 3]);
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
	printf("Contents of rgb array: [%s] [%s] [%s]\n", rgb[0], rgb[1], rgb[2]);
	red = ft_check_number_rgb(rgb[0]);
	green = ft_check_number_rgb(rgb[1]);
	blue = ft_check_number_rgb(rgb[2]);
	ft_free_char_array(rgb);
	if (red == -1 || green == -1 || blue == -1)
		return (-1);
	return ((red << 16) | (green << 8) | blue);
}

void print_map(t_map *map)
{
	printf("Texture NO: %s\n", map->texture_no);
	printf("Texture SO: %s\n", map->texture_so);
	printf("Texture WE: %s\n", map->texture_we);
	printf("Texture EA: %s\n", map->texture_ea);
	printf("Color Ceiling usable int value: %d\n", map->color_ceiling);
	printf("Color Floor usable int value: %d\n", map->color_floor);
	printf("Rows: %d\n", map->rows);
	printf("Columns: %d\n", map->columns);
}

void ft_free_map(t_map *map) {
	free(map->texture_no);
	free(map->texture_so);
	free(map->texture_we);
	free(map->texture_ea);
	if (map->line_array != NULL) {
		for (int i = 0; i < map->line_count; i++) {
			free(map->line_array[i]);
		}
		free(map->line_array);
	}
}

/*
int main() {
	t_map map;
	ft_init_map_identifiers(&map);

	char input[] = "F 220,100,0\nC 225,30,0\nNO     ./texture_north.png\nSO      ./texture_south.png\nWE ./texture_west.png\nEA ./texture_east.png";
	char *token = strtok(input, "\n");

	while (token != NULL) {
		if (ft_assign_map_identifiers(&map, token, 0) == EXIT_FAILURE) {
			printf("Failed to assign identifiers.\n");
			return 1;
		}
		token = strtok(NULL, "\n");
	}

	printf("Assigned identifiers successfully.\n");

	if (ft_filled_map_identifiers(&map)) {
		printf("All map identifiers are filled.\n");
	} else {
		printf("Some map identifiers are missing.\n");
	}

	printf("Map Details:\n");
	print_map(&map);
	ft_free_map(&map);
	return 0;
}
*/

/*
// usable test main function without the strtok function. Just wanted proof of concept.
int main() {
	t_map map;
	ft_init_map_identifiers(&map);

	char input1[] = "F 255,255,255";
	char input2[] = "C 225,30,33";
	char input3[] = "NO ./path_to_the_north_texture";
	char input4[] = "SO ./path_to_the_south_texture";
	char input5[] = "WE ./path_to_the_west_texture";
	char input6[] = "EA ./path_to_the_east_text";

	if (ft_assign_map_identifiers(&map, input1, 0) == EXIT_SUCCESS &&
		ft_assign_map_identifiers(&map, input2, 0) == EXIT_SUCCESS &&
		ft_assign_map_identifiers(&map, input3, 0) == EXIT_SUCCESS &&
		ft_assign_map_identifiers(&map, input4, 0) == EXIT_SUCCESS &&
		ft_assign_map_identifiers(&map, input5, 0) == EXIT_SUCCESS &&
		ft_assign_map_identifiers(&map, input6, 0) == EXIT_SUCCESS) {
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
 	ft_free_map(&map);
	return 0;
}
*/

// NEW PART

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	while (s && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void *ft_realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
		return malloc(size);
	else if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	else
	{
		void *new_ptr = malloc(size);
		if (new_ptr == NULL)
			return NULL;
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
		return new_ptr;
	}
}

bool is_identifier(const char *line, const char *identifier)
{
	return ft_strncmp(line, identifier, ft_strlen(identifier)) == 0;
}

void process_line(t_map *map, char *line)
{
	// Skip spaces between the identifier and the information
	char *trimmed_line = line;
	while (*trimmed_line == ' ')
		trimmed_line++;

	// Process each identifier and assign information using ft_assign_map_identifiers
	if (is_identifier(trimmed_line, "NO") || is_identifier(trimmed_line, "SO") ||
		is_identifier(trimmed_line, "WE") || is_identifier(trimmed_line, "EA") ||
		is_identifier(trimmed_line, "F") || is_identifier(trimmed_line, "C")) {

		// Allocate memory and store the line as an element in the array
		if (map->line_array == NULL)
		{
			map->line_array = malloc(sizeof(char *));
			if (map->line_array == NULL) {
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			map->line_array = ft_realloc(map->line_array, sizeof(char *) * (map->line_count + 1));
			if (map->line_array == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
		map->line_array[map->line_count] = ft_strdup(line);
		if (map->line_array[map->line_count] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		map->line_count++;

		// Process the array element using ft_assign_map_identifiers
		ft_assign_map_identifiers(map, map->line_array[map->line_count - 1], 0);
	}
}


void parse_map_file(const char *filename, t_map *map) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char *line = NULL;

	while ((line = get_next_line(fd)) != NULL)
	{
		// Skip lines that do not start with NO, SO, WE, EA, F, or C
		char *trimmed_line = line;
		while (*trimmed_line == ' ' || *trimmed_line == '\t')
			trimmed_line++;

		if ((ft_strncmp(trimmed_line, "NO", 2) == 0 || ft_strncmp(trimmed_line, "SO", 2) == 0 ||
			 ft_strncmp(trimmed_line, "WE", 2) == 0 || ft_strncmp(trimmed_line, "EA", 2) == 0 ||
			 ft_strncmp(trimmed_line, "F", 1) == 0 || ft_strncmp(trimmed_line, "C", 1) == 0))
		{
			process_line(map, line);
		}

		// Free allocated memory for the current line
		free(line);
	}

	close(fd);
}


int main(int argc, char *argv[])
{
	t_map map;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file_path>\n", argv[0]);
		return EXIT_FAILURE;
	}

	ft_init_map_identifiers(&map);
	parse_map_file(argv[1], &map);


	if (ft_filled_map_identifiers(&map)) {
		printf("All map identifiers are filled.\n");
	} else {
		printf("Some map identifiers are missing.\n");
	}
	printf("Map Details:\n");
	print_map(&map);
	// Free allocated memory in the t_map structure
	ft_free_map(&map);

	return 0;
}