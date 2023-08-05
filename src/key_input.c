/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 21:39:31 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

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
		vrs->overlay = !(vrs->overlay);
	return (0);
}
