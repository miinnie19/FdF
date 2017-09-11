/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:40:23 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/06/11 18:25:53 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (little[k] != '\0')
		k++;
	if (k == 0)
		return ((char*)big);
	while (big[i])
	{
		while (little[j] == big[i + j])
		{
			if (j == k - 1)
				return ((char*)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
