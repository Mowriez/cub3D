/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:49:52 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 09:08:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	init_input_keys(t_vars *vrs)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		vrs->key_state[i] = false;
		i++;
	}
}

int	set_key_status_pressed(int keycode, t_vars *vrs)
{
	if (keycode == KEY_W)
		vrs->key_state[0] = KEY_PRESSED;
	else if (keycode == KEY_S)
		vrs->key_state[1] = KEY_PRESSED;
	if (keycode == KEY_A)
		vrs->key_state[2] = KEY_PRESSED;
	else if (keycode == KEY_D)
		vrs->key_state[3] = KEY_PRESSED;
	if (keycode == KEY_LEFT)
		vrs->key_state[4] = KEY_PRESSED;
	else if (keycode == KEY_RIGHT)
		vrs->key_state[5] = KEY_PRESSED;
	return (0);
}

int	set_key_status_free(int keycode, t_vars *vrs)
{
	if (keycode == KEY_W)
		vrs->key_state[0] = KEY_FREE;
	if (keycode == KEY_S)
		vrs->key_state[1] = KEY_FREE;
	if (keycode == KEY_A)
		vrs->key_state[2] = KEY_FREE;
	if (keycode == KEY_D)
		vrs->key_state[3] = KEY_FREE;
	if (keycode == KEY_LEFT)
		vrs->key_state[4] = KEY_FREE;
	if (keycode == KEY_RIGHT)
		vrs->key_state[5] = KEY_FREE;
	if (keycode == KEY_ESC)
		ft_free(vrs);
	if (keycode == KEY_O)
		vrs->show_overlay = !(vrs->show_overlay);
	return (0);
}

int	set_mouse_key_status(int keycode, int x, int y, t_vars *vrs)
{
	if (keycode == LEFT_MOUSE && y > 5)
		vrs->key_state[6] = !vrs->key_state[6];
	// if (vrs->key_state[6] == KEY_PRESSED)
	// {
	// 	mlx_mouse_hide(vrs->mlx_ptr, vrs->win_ptr);
	// 	mlx_mouse_move(vrs->win_ptr, (int)(vrs->win_width / 2),
	// 		(int)(vrs->win_height / 2));
	// }
	else if (vrs->key_state[6] == KEY_FREE)
		mlx_mouse_show(vrs->mlx_ptr, vrs->win_ptr);
	return (x + y - x - y);
}
