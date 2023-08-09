/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:52:34 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 23:35:39 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	move_forwards(t_vars *vrs)
{
	double	new_x;
	double	new_y;
	double	hitbox_x;
	double	hitbox_y;

	new_x = vrs->rc.pl_pos_x + cos(vrs->rc.view_angle) * MV_SP;
	new_y = vrs->rc.pl_pos_y + sin(vrs->rc.view_angle) * MV_SP;
	hitbox_x = vrs->rc.pl_pos_x + (HIT_BOX * cos(vrs->rc.view_angle) * MV_SP);
	hitbox_y = vrs->rc.pl_pos_y + (HIT_BOX * sin(vrs->rc.view_angle) * MV_SP);
	if (vrs->map.map[(int)floor(hitbox_y)][(int)floor(hitbox_x)] == '0'
		&& vrs->map.map[(int)floor(new_y)][(int)floor(new_x)] == '0')
	{
		vrs->rc.pl_pos_x = new_x;
		vrs->rc.pl_pos_y = new_y;
	}
}

static void	move_backwards(t_vars *vrs)
{
	double	new_x;
	double	new_y;
	double	hitbox_x;
	double	hitbox_y;

	new_x = vrs->rc.pl_pos_x - cos(vrs->rc.view_angle) * MV_SP;
	new_y = vrs->rc.pl_pos_y - sin(vrs->rc.view_angle) * MV_SP;
	hitbox_x = vrs->rc.pl_pos_x - (HIT_BOX * cos(vrs->rc.view_angle) * MV_SP);
	hitbox_y = vrs->rc.pl_pos_y - (HIT_BOX * sin(vrs->rc.view_angle) * MV_SP);
	if (vrs->map.map[(int)floor(hitbox_y)][(int)floor(hitbox_x)] == '0'
			&& vrs->map.map[(int)floor(new_y)][(int)floor(new_x)] == '0')
	{
		vrs->rc.pl_pos_x = new_x;
		vrs->rc.pl_pos_y = new_y;
	}
}

static void	move_left(t_vars *vrs)
{
	double	new_x;
	double	new_y;
	double	hitbox_x;
	double	hitbox_y;

	new_x = vrs->rc.pl_pos_x + cos(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP;
	new_y = vrs->rc.pl_pos_y + sin(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP;
	hitbox_x = vrs->rc.pl_pos_x
		+ (HIT_BOX * cos(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP);
	hitbox_y = vrs->rc.pl_pos_y
		+ (HIT_BOX * sin(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP);
	if (vrs->map.map[(int)floor(hitbox_y)][(int)floor(hitbox_x)] == '0'
			&& vrs->map.map[(int)floor(new_y)][(int)floor(new_x)] == '0')
	{
		vrs->rc.pl_pos_x = new_x;
		vrs->rc.pl_pos_y = new_y;
	}
}

static void	move_right(t_vars *vrs)
{
	double	new_x;
	double	new_y;
	double	hitbox_x;
	double	hitbox_y;

	new_x = vrs->rc.pl_pos_x - cos(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP;
	new_y = vrs->rc.pl_pos_y - sin(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP;
	hitbox_x = vrs->rc.pl_pos_x
		- (HIT_BOX * cos(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP);
	hitbox_y = vrs->rc.pl_pos_y
		- (HIT_BOX * sin(vrs->rc.view_angle - 0.5 * M_PI) * MV_SP);
	if (vrs->map.map[(int)floor(hitbox_y)][(int)floor(hitbox_x)] == '0'
			&& vrs->map.map[(int)floor(new_y)][(int)floor(new_x)] == '0')
	{
		vrs->rc.pl_pos_x = new_x;
		vrs->rc.pl_pos_y = new_y;
	}
}

void	move_player(t_vars *vrs)
{
	if (vrs->key_state[0] == KEY_PRESSED)
		move_forwards(vrs);
	else if (vrs->key_state[1] == KEY_PRESSED)
		move_backwards(vrs);
	if (vrs->key_state[2] == KEY_PRESSED)
		move_left(vrs);
	else if (vrs->key_state[3] == KEY_PRESSED)
		move_right(vrs);
}
