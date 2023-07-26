/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:16:14 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 20:15:05 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
tests for any character for which isalpha() or isdigit() is true. The value of 
the argument must be representable as an unsigned char or the value of EOF.

Return value:
0 if the character tests false and 1 if the character tests true.*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c < '0' || (c > '9' && c < 'A')
		|| (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}
