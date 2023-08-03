/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:48:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 21:40:15 by mtrautne         ###   ########.fr       */
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
# include <sys/time.h>

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

// cast_raycaster.c
int		visualizer(t_vars *vrs);

// deb_dtoa.c
char	*dtoa(double num_double, int precision);

// deb_helpers.c
void	get_debugging_values(t_vars *vrs);
void	print_overlay_vars(t_overlay *ol, t_vars *vrs);

// deb_overlay.c
void	draw_debugging_overlay(t_vars *vrs);

// error.c
int		err_msg(char *msg);

// init_helpers.c
bool	is_specific_char(const char c, const char *char_set);

// init_map.c
int		init_map(t_vars *vrs);

// init_struct.c
int		init_struct(int argc, char**argv, t_vars **vrs);

// key_input.c
int		keyboard_input(int keycode, t_vars *vrs);

// main.c
int		ft_free(t_vars *vrs);

// par_parser.c
int		parse_input(int argc, char**argv);

// par_utils.c
//empty

#endif
