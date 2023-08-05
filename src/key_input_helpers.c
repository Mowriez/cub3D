/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:49:52 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 21:57:17 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	init_input_keys(t_vars *vrs)
{
	int	i;

	i = 0;
	vrs->key_state = malloc(7 * sizeof(bool));
	while (i < 6)
	{
		vrs->key_state[i] = 0;
		i++;
	}
	vrs->key_state[i] = NULL;
}
