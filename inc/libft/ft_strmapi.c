/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:09:20 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 10:54:21 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Applies the function ’f’ to each character of the string ’s’, and passing its 
index as first argument to create a new string (with malloc(3)) resulting
from successive applications of ’f’.

Return value:
The string created from the successive applications of ’f’. NULL if the 
allocation fails.

Parameters:
s: The string on which to iterate.
f: The function to apply to each character.

External functions:
malloc

Particularities:
f is a pointer to function with return type char and parameters unsigned 
int and char. The only parameter for int that makes sense is the
index i. see the description.*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	new_str = ft_strdup(s);
	if (!s)
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (new_str);
}
