#include "../inc/headers/cub3d.h"

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
//
///*int main() {
//	t_map map;
//	ft_init_map_identifiers(&map);
//
//	char input[] = "F 220,100,0\nC 225,30,0\nNO     ./texture_north.png\nSO      ./texture_south.png\nWE ./texture_west.png\nEA ./texture_east.png";
//	char *token = strtok(input, "\n");
//
//	while (token != NULL) {
//		if (ft_assign_map_identifiers(&map, token, 0) == EXIT_FAILURE) {
//			printf("Failed to assign identifiers.\n");
//			return 1;
//		}
//		token = strtok(NULL, "\n");
//	}
//
//	printf("Assigned identifiers successfully.\n");
//
//	if (ft_filled_map_identifiers(&map)) {
//		printf("All map identifiers are filled.\n");
//	} else {
//		printf("Some map identifiers are missing.\n");
//	}
//
//	printf("Map Details:\n");
//	print_map(&map);
//	ft_free_map(&map);
//	return 0;
//}*/

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file_path>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	ft_init_map_identifiers(&map);
	parse_map_file(argv[1], &map);
	if (ft_filled_map_identifiers(&map))
		printf("All map identifiers are filled.\n");
	else
		printf("Some map identifiers are missing.\n");
	printf("Map Details:\n");
	print_map(&map);
	ft_free_map(&map);
	return (0);
}
