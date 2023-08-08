/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:49:52 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/08 23:10:17 by mtrautne         ###   ########.fr       */
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
