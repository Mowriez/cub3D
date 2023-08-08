/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_mouse_pan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:12:57 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/08 12:30:21 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	mouse_actions(int x, int y, t_vars *vrs)
{
	if (vrs->key_state[6] == KEY_PRESSED)
	{

		if (x < vrs->prev_x)
			vrs->rc.view_angle -= MOUSE_PAN_SP * vrs->rc.fov_angle;
		else if (x > vrs->prev_x)
			vrs->rc.view_angle += MOUSE_PAN_SP * vrs->rc.fov_angle;
		vrs->prev_x = x;
		if (x < 0 || x > vrs->win_width || y < 0 || y > vrs->win_height)
			mlx_mouse_move(vrs->win_ptr, vrs->win_width / 2,
				vrs->win_height / 2);
	}
	return (y - y);
}

int	set_mouse_key_status(int keycode, int x, int y, t_vars *vrs)
{
	if (keycode == LEFT_MOUSE && y > 5)
		vrs->key_state[6] = !vrs->key_state[6];
	if (vrs->key_state[6] == KEY_PRESSED)
	{
		mlx_mouse_hide(vrs->mlx_ptr, vrs->win_ptr);
		mlx_mouse_move(vrs->win_ptr, vrs->win_width / 2,
			vrs->win_height / 2);
	}
	else if (vrs->key_state[6] == KEY_FREE)
		mlx_mouse_show(vrs->mlx_ptr, vrs->win_ptr);
	return (x + y - x - y);
}
