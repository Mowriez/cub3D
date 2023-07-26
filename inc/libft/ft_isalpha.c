/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:12:33 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 20:15:08 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
tests for any character for which isupper() or islower() is true.
parameter c is an int, the value of which must be representable as an unsigned 
char or the macro EOF. This means chars will implicitely converted to their 
ascii values.

Return value:
0 if character c tests false and 1 if c tests true.*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}
