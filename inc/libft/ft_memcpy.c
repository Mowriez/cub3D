/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/06/09 12:52:10 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
copies n bytes from memory area src to memory area dst. If dst and src overlap, 
behavior is undefined. Applications in which dst and src might overlap should 
use memmove(3) instead.

Return value:
returns the original value of dst.*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	while (s && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
