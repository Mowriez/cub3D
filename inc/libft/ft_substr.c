/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:07:54 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/19 10:13:33 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Allocates (with malloc(3)) and returns a substring from the string ’s’. The 
substring begins at index ’start’ and is of maximum size ’len’.

Return value:
The substring. NULL if the allocation fails.

Parameters:
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

External functions:
malloc

Particularities:
edge case i forgot about was the one where len is bigger than strlen(s). in 
that case my fct would have allocated and written up to len+1 * sizeof(char)
objects, without actually checking the maximum amount of objects in src
from s[start] till end of src.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*j;

	i = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (!s)
		return (0);
	if (len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	j = (char *)malloc((len + 1) * sizeof(char));
	if (!j)
		return (0);
	while (i < len)
	{
		j[i] = s[i + start];
		i++;
	}
	j[i] = '\0';
	return (j);
}
