/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 20:24:13 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	pan_view(t_vars *vrs, int keycode)
{
	if (keycode == KEY_RIGHT)
	{
		vrs->view_angle += ROT_SP * M_PI;
	}
	else if (keycode == KEY_LEFT)
	{
		vrs->view_angle -= ROT_SP * M_PI;
	}
}

static void	move_up_or_back(t_vars *vrs, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == KEY_W)
	{
		new_x = vrs->player_pos_x + cos(vrs->view_angle) * MV_SP;
		new_y = vrs->player_pos_y + sin(vrs->view_angle) * MV_SP;
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
	else if (keycode == KEY_S)
	{
		new_x = vrs->player_pos_x - cos(vrs->view_angle) * MV_SP;
		new_y = vrs->player_pos_y - sin(vrs->view_angle) * MV_SP;
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
}

static void	move_sideways(t_vars *vrs, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == KEY_A)
	{
		new_x = vrs->player_pos_x + cos(vrs->view_angle - 0.5 * M_PI) * MV_SP;
		new_y = vrs->player_pos_y + sin(vrs->view_angle - 0.5 * M_PI) * MV_SP;
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
	else if (keycode == KEY_D)
	{
		new_x = vrs->player_pos_x - cos(vrs->view_angle - 0.5 * M_PI) * MV_SP;
		new_y = vrs->player_pos_y - sin(vrs->view_angle - 0.5 * M_PI) * MV_SP;
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
}

static void	move(t_vars *vrs, int keycode)
{
	move_up_or_back(vrs, keycode);
	move_sideways(vrs, keycode);
}

int	keyboard_input(int keycode, t_vars *vrs)
{
	if ((keycode >= KEY_LEFT && keycode <= KEY_DOWN))
		pan_view(vrs, keycode);
	if (keycode >= KEY_A && keycode <= KEY_W)
		move(vrs, keycode);
	if (keycode == KEY_ESC)
		ft_free(vrs);
	if (keycode == KEY_O)
		vrs->overlay = !(vrs->overlay);
	return (0);
}
