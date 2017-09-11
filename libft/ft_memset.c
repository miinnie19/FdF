/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:24:07 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/06/20 12:24:14 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*ptr;

	cnt = 0;
	ptr = (unsigned char *)b;
	while (cnt < len)
	{
		ptr[cnt] = (unsigned char)c;
		cnt++;
	}
	return (b);
}
