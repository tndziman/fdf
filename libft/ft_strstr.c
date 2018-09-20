/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:03:25 by tndziman          #+#    #+#             */
/*   Updated: 2018/06/04 13:39:25 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*hs;

	hs = (char*)haystack;
	if (*needle == '\0')
		return (hs);
	while (*hs != '\0')
	{
		i = 0;
		while (needle[i] == hs[i] && needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return (hs);
		hs++;
	}
	return (NULL);
}
