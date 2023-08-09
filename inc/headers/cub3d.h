/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:48:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 09:10:03 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// System Headers ------------------------------------------------------------
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <float.h>

// Project specific headers --------------------------------------------------
# include "../libft/libft.h"
# include "macros.h"
# include "structs.h"

// OS specific mlx headers ---------------------------------------------------
# ifdef __linux__
#  include "../mlx/minilibx-linux/mlx.h"

# elif defined(__APPLE__)
#  include "../mlx/minilibx_opengl_20191021/mlx.h"

# else
#  error "Unsupported operating system"
# endif

// function declarations -----------------------------------------------------
// cast_drawer.c
void	draw_vert_line(int x, t_vars *vrs);

// cast_minimap.c
void	draw_minimap(t_vars *vrs);

// cast_raycaster.c
int		visualizer(t_vars *vrs);

// deb_dtoa.c
char	*dtoa(double num_double, int precision);

// deb_helpers.c
void	get_debugging_values(t_vars *vrs);
void	print_overlay_vars(t_vars *vrs);

// deb_overlay.c
void	draw_debugging_overlay(t_vars *vrs);

// error.c
int		err_msg(char *msg);
void	ft_custom_exit(const char *message);

// init_helpers.c
bool	is_specific_char(const char c, const char *char_set);
void	init_minimap(t_vars *vrs);
void	init_textures(t_vars *vrs);
void	init_texture_n(t_vars *vrs);
void	init_texture_s(t_vars *vrs);
void	init_texture_w(t_vars *vrs);
void	init_texture_e(t_vars *vrs);

// init_map.c
int		init_map(t_vars *vrs, char **argv);

// init_struct.c
int		parse_init_struct(char**argv, t_vars *vrs);

// key_input_helpers.c
void	init_input_keys(t_vars *vrs);
int		motion(t_vars *vrs);

// key_input.c
int		keyboard_input(int keycode, t_vars *vrs); // never used!

// main.c
int		ft_free(t_vars *vrs);
int		set_key_status_pressed(int keycode, t_vars *vrs);
int		set_key_status_free(int keycode, t_vars *vrs);

// par_error_check.c
bool	ft_valid_file_ending(const char *filename, char *expected_end);
bool	ft_texture_exists(const char *file_path);
bool 	ft_check_tex_exist(const char *tex_location);
bool 	ft_check_all_tex(t_map *map);

// par_free.c
void	ft_free_map(t_map *map);
void	ft_free_char_array(char **array);

// par_identifier.c
int		ft_get_rgb_color(char *s);
int		ft_assign_map_identifiers(t_map *map, char *input, int i);

// par_identifier1.c
bool	is_identifier(const char *line, const char *identifier);
void	process_line(t_map *map, char *line);
void	parse_map_identifier(const char *filename, t_map *map);

// init_map_identifiers.c
void	ft_init_map_identifiers(t_map *map);
bool	ft_filled_map_identifiers(t_map *level);

// par_parser.c
int		check_input(int argc, char**argv);

// par_utils.c
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_realloc(void *ptr, size_t originalLength, size_t newLength);
char	*parse_next_line(int fd);


void	print_fps(t_vars *vrs);
void	move_forwards(t_vars *vrs);
void	move_backwards(t_vars *vrs);
void	move_left(t_vars *vrs);
void	move_right(t_vars *vrs);
void	move(t_vars *vrs);
int		set_mouse_key_status(int keycode, int x, int y, t_vars *vrs);
int		pan_view_mouse(int x, int y, t_vars *vrs);
void	draw_scope(t_vars *vrs);
void	print_pixel(int x, int y, t_vars *vrs, unsigned int color);
int		valid_map(char **map, int map_width, int map_height);
int		is_valid_character(char c);
void	pan_view_keyboard(t_vars *vrs);
void	generate_map_layout(t_map *map, char **av);
int		is_starting_pos(char c);
int		is_valid_character(char c);
void	fill_array_line(const char *line, int i, char **map);
void	check_line_for_map_start(char *line, int *map_start);

#endif
