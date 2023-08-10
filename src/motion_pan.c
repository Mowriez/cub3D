/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_pan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:12:57 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/10 11:27:03 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	pan_view_keyboard(t_vars *vrs)
{
	if (vrs->key_state[5] == KEY_PRESSED)
		vrs->rc.view_angle += ROT_SP * M_PI;
	if (vrs->key_state[4] == KEY_PRESSED)
		vrs->rc.view_angle -= ROT_SP * M_PI;
}

int	pan_view_mouse(int x, int y, t_vars *vrs)
{
	if (vrs->key_state[6] == KEY_PRESSED)
	{
		if (x < vrs->prev_x)
			vrs->rc.view_angle -= MOUSE_PAN_SP * vrs->rc.fov_angle;
		else if (x > vrs->prev_x)
			vrs->rc.view_angle += MOUSE_PAN_SP * vrs->rc.fov_angle;
		vrs->prev_x = x;
		if (x < 0 || x > vrs->win_width || y < 0 || y > vrs->win_height)
			mlx_mouse_move(vrs->win_ptr, (int)(vrs->win_width / 2),
				(int)(vrs->win_height / 2));
	}
	return (y - y);
}
