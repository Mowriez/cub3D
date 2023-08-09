/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:48:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 23:54:03 by mtrautne         ###   ########.fr       */
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

// 00_timing.c
void	print_fps(t_vars *vrs);

// cast_drawer_scope.c
void	draw_scope(t_vars *vrs);

// cast_drawer.c
void	print_pixel(int x, int y, t_vars *vrs, unsigned int color);
void	draw_vert_line(int x, t_vars *vrs);

// cast_minimap.c
void	draw_minimap(t_vars *vrs);

// cast_raycaster.c
int		visualizer(t_vars *vrs);

// deb_overlay.c
void	draw_debugging_overlay(t_vars *vrs);

// deb_utils1.c
void	get_debugging_values(t_vars *vrs);
void	print_overlay_vars(t_vars *vrs);

// deb_utils2.c
char	*dtoa(double num_double, int precision);

// error.c
int		err_msg(char *msg);
void	ft_custom_exit(const char *message);

// init_key_input.c
void	init_input_keys(t_vars *vrs);
int		set_key_status_pressed(int keycode, t_vars *vrs);
int		set_key_status_free(int keycode, t_vars *vrs);
int		set_mouse_key_status(int keycode, int x, int y, t_vars *vrs);

// init_map_identifiers.c
int		set_error_value(t_map *map, int i);
void	ft_init_map_identifiers(t_map *map);
bool	ft_filled_map_identifiers(t_map *level);

// init_map_utils1.c
void	check_line_for_map_start(char *line, int *map_start);
void	fill_array_line(const char *line, int i, char **map);
void	generate_map_layout(t_map *map, char **av);

// init_map_utils2.c
int		check_line_valid(char *line, t_map *map);
void	print_map(t_map *map);

// init_map.c
int		init_map(t_vars *vrs, char **av);

// init_struct_utils.c
void	init_minimap(t_vars *vrs);
bool	is_specific_char(const char c, const char *char_set);

// init_struct.c
int		parse_init_struct(char**argv, t_vars *vrs);

// init_textures.c
void	init_textures(t_vars *vrs);

// main.c
int		ft_free(t_vars *vrs);

// motion_move.c
void	move_player(t_vars *vrs);

// motion_pan.c
void	pan_view_keyboard(t_vars *vrs);
int		pan_view_mouse(int x, int y, t_vars *vrs);

// motion.c
int		motion(t_vars *vrs);

// par_argv_check.c
int		check_input(int argc, char**argv);

// par_error_check.c
bool	ft_valid_file_ending(const char *filename, char *expected_end);
bool	ft_texture_exists(const char *file_path);
bool	ft_check_tex_exist(const char *tex_location);
bool	ft_check_all_tex(t_map *map);

// par_free.c
int		ft_free_map_identifiers(t_map *map);
int		ft_free_map_array(t_map *map);
int		ft_free_map(t_map *map);
void	ft_free_char_array(char **array);

// par_map_identifiers.c
int		ft_assign_map_identifiers(t_map *map, char *input, int i);
int		ft_get_rgb_color(char *s);

// par_map_identifiers1.c
bool	is_identifier(const char *line, const char *identifier);
void	parse_map_identifier(const char *filename, t_map *map);

// par_map_valid_utils.c
int		is_valid_character(char c);
int		is_starting_pos(char c);

// par_map_valid.c
int		is_map_invalid(char **map, int map_w, int map_h);

// par_utils.c
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_realloc(void *ptr, size_t orig_len, size_t new_len);
char	*parse_next_line(int fd);

#endif
