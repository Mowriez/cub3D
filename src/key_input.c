/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 23:57:31 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	pan_view(t_vars *vrs)
{
	if (vrs->key_state[5] == KEY_PRESSED)
		vrs->view_angle += ROT_SP * M_PI;
	if (vrs->key_state[4] == KEY_PRESSED)
		vrs->view_angle -= ROT_SP * M_PI;
}

static void	move_up_or_back(t_vars *vrs)
{
	double	new_x;
	double	new_y;

	if (vrs->key_state[0] == KEY_PRESSED)
	{
		new_x = vrs->player_pos_x + cos(vrs->view_angle) * MV_SP;
		new_y = vrs->player_pos_y + sin(vrs->view_angle) * MV_SP;
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
	else if (vrs->key_state[1] == KEY_PRESSED)
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

static void	move_sideways(t_vars *vrs)
{
	double	new_x;
	double	new_y;

	if (vrs->key_state[2] == KEY_PRESSED)
	{
		new_x = vrs->player_pos_x + cos(vrs->view_angle - 0.5 * M_PI) * MV_SP;
		new_y = vrs->player_pos_y + sin(vrs->view_angle - 0.5 * M_PI) * MV_SP;
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
	else if (vrs->key_state[3] == KEY_PRESSED)
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

static void	move(t_vars *vrs)
{
	move_up_or_back(vrs);
	move_sideways(vrs);
}

int	motion(t_vars *vrs)
{
	// printf("motion\n");
	if (vrs->key_state[4] == KEY_PRESSED || vrs->key_state[5] == KEY_PRESSED)
		pan_view(vrs);
	if (vrs->key_state[0] == KEY_PRESSED || vrs->key_state[1] == KEY_PRESSED || vrs->key_state[2] == KEY_PRESSED || vrs->key_state[3] == KEY_PRESSED)
		move(vrs);
	return (0);
}
