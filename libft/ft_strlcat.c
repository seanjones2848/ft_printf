/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:40:18 by sjones            #+#    #+#             */
/*   Updated: 2017/01/18 16:09:56 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	int		n;
	int		l;

	s = (char*)src;
	d = dst;
	n = size;
	while (*d && n--)
		d++;
	l = d - dst;
	if (l == (int)size)
		return (size + ft_strlen(src));
	while (*src)
	{
		if (n-- - 1 > 0)
			*d++ = *src;
		src++;
	}
	*d = '\0';
	return (l + (src - s));
}
