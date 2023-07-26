/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:09:20 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/19 10:13:40 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Allocates (with malloc(3)) and returns a copy of 's1’ with the characters 
specified in ’set’ removed from the beginning and the end of the string.

Return value:
The trimmed string. NULL if the allocation fails.

Parameters:
s1: The string to be trimmed. set: The reference set of characters to trim.

External functions:
malloc

Particularities:
All chars in set need to be tested individually. Dont need to be in order.
start is start of new string, stop is end of new string. Dont forget that 
the string still contains a \0, even if all the chars are in set!*/

#include "libft.h"

static size_t	ft_check_set(char i, char	const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (i == set[j])
			return (0);
		j++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		stop;
	size_t		k;
	char		*str;

	start = 0;
	stop = ft_strlen(s1);
	if (!s1)
		return ("");
	while (s1 && ft_check_set(s1[start], set) == 0)
		start++;
	while (stop > start && s1 && ft_check_set(s1[stop - 1], set) == 0)
		stop--;
	str = (char *)(malloc ((stop - start + 1) * sizeof(*s1)));
	if (!str)
		return (NULL);
	k = 0;
	while (start < stop)
		str[k++] = s1[start++];
	str[k] = '\0';
	return (str);
}
