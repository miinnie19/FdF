/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:17:37 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/06/20 12:17:41 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char*)s1);
	if (!n)
		return (NULL);
	while (*s1 != '\0' && n >= ft_strlen(s2))
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (0);
}
