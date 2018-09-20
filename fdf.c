/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:19:29 by tndziman          #+#    #+#             */
/*   Updated: 2018/08/15 14:51:22 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	error_handle(t_mlx *file)
{
	if (ft_getmap(file) == -1)
	{
		ft_putendl("Error");
		return ;
	}
	mlx(file);
}

int		main(int argc, char **argv)
{
	t_mlx	mine;

	if (argc == 2)
	{
		mine.name = argv[1];
		mine.fd = open(mine.name, O_RDONLY);
		error_handle(&mine);
	}
	else
		ft_putendl("usage: ./fdf file");
	return (0);
}
