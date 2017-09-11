/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:02:07 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/06/20 12:02:46 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			cnt;
	unsigned char	*ptr;

	cnt = 0;
	ptr = (unsigned char *)s;
	while (cnt < n && n > 0)
	{
		ptr[cnt] = 0;
		cnt++;
	}
}
