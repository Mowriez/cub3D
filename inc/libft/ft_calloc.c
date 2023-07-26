/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 11:02:00 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
allocates memory. The allocated memory is aligned such that it can be used for 
any data type, including AltiVec- and SSE-related types.
contiguously allocates enough space for count objects that are size bytes of 
memory each and returns a pointer to the allocated memory. The allocated memory 
is filled with bytes of value zero.

Return value:
return a pointer to allocated memory. If there is an error, returns a NULL 
pointer and set errno to ENOMEM.

Particularities: malloc allocates memory whereever...so its paramount to fetch
the correct address to initialise with zeros for calloc.
SIZE_MAX (Maximum native integer size -> Max value of an object of size_t type) 
is a testcase that I don't fully understand - seems to trigger some problem in 
valgrind, but doesn't seem to be a problem for moulinette. 
Altivec: special vector data types to use in Altivec specific code. all types 
of constant size 16bit. e.g. "vector unsigned char" etc
SSE: ?*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*j;

	if (size == SIZE_MAX && count == SIZE_MAX)
		return (0);
	j = malloc(count * size);
	if (!j)
		return (0);
	ft_bzero(j, count * size);
	return (j);
}
