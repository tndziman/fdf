/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:33:54 by tndziman          #+#    #+#             */
/*   Updated: 2018/06/08 10:16:22 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (!str1 || !str2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (str1[i] != '\0' && i < (int)n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
