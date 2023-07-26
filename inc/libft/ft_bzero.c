/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 10:10:53 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
writes n zeroed bytes to the string s. If n is zero, bzero() does nothing.

Return value:
None.

Particularities:
Can't directly dereference void pointer s. I guess if its a pointer to void it 
just wouldn't make sense that there actually is something at that address. 
so instead of just setting s[i] = 0, it is neccessary to write to pointer to
typecast (char) pointers with an offset, which then can be written to. */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}
