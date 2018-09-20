/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:06:44 by tndziman          #+#    #+#             */
/*   Updated: 2018/06/04 15:11:29 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t x;
	size_t y;

	x = 0;
	while (x < len && haystack[x] != '\0')
	{
		y = 0;
		while (x + y < len && haystack[x + y] == needle[y] && needle[y] != '\0')
			y++;
		if (needle[y] == '\0')
			return ((char *)haystack + x);
		x++;
	}
	return (NULL);
}
