/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:15:40 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/06/20 12:15:44 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	dest = ft_strdup(s);
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = f(dest[i]);
		i++;
	}
	return (dest);
}
