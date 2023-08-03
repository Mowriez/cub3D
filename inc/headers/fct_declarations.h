/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_declarations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:26:12 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 13:30:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_DECLARATIONS_H
# define FCT_DECLARATIONS_H


// par_parser.c
int		parse_input(int argc, char**argv);

// par_utils.c

// error.c
int		err_msg(char *msg);

//not sorted yet;
int		init_struct(int argc, char**argv, t_vars **vrs);
int		ft_free(t_vars *vrs);
int		mapfile_to_arr(t_vars *vrs);
bool	is_specific_char(const char c, const char *char_set);
int		visualizer(t_vars *vrs);
void	cast_ray(t_vars *vrs, int img_x);
int		keyboard_input(int keycode, t_vars *vrs);
void	draw_debugging_overlay(t_vars *vrs);
void	dtostr(double num_double, char *buffer, int precision);
void	overlay_text(t_vars *vrs, char *player_x, char *player_y);

#endif
