/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:00:56 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 21:52:22 by mtrautne         ###   ########.fr       */
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

int	motion(t_vars *vrs)
{
	if (vrs->key_state[4] == KEY_PRESSED || vrs->key_state[5] == KEY_PRESSED)
		pan_view(vrs);
	if (vrs->key_state[0] == KEY_PRESSED || vrs->key_state[1] == KEY_PRESSED
		|| vrs->key_state[2] == KEY_PRESSED || vrs->key_state[3] == KEY_PRESSED)
		move(vrs);
	return (0);
}
