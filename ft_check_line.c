/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:53:23 by tndziman          #+#    #+#             */
/*   Updated: 2018/08/15 14:51:18 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			val_return(int y, int nb, int save)
{
	if (y == 0)
		return (nb);
	else if (save == nb)
		return (save);
	else
		return (-1);
}

int			check_line(char *str, int y, int save)
{
	int		i;
	int		k;
	int		nb;

	i = 0;
	k = 0;
	nb = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (str[i] != ' ')
				return (-1);
			k = 0;
		}
		else
		{
			if (k == 0)
				nb++;
			k++;
		}
		i++;
	}
	return (val_return(y, nb, save));
}
