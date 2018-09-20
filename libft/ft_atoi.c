/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:49:50 by tndziman          #+#    #+#             */
/*   Updated: 2018/06/07 16:47:47 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	s;

	n = 0;
	s = 1;
	if (*str == '\0')
		return (0);
	while ((*str >= '\t' && *str <= '\r') || (*str == 32))
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	i = 0;
	while (*str && ft_isdigit(*str))
	{
		n = (n * 10) + (*str++ - '0');
		if (i > 18)
			return (s == -1 ? 0 : -1);
		i++;
	}
	return (n * s);
}
