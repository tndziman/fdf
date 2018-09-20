/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:50:20 by tndziman          #+#    #+#             */
/*   Updated: 2018/08/15 14:20:18 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			helper_all_tab(t_mlx *file, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (file->lines == 0)
		file->chars = x;
	else
	{
		if (x != file->chars)
			return (-1);
	}
	free(line);
	free(tab);
	file->lines++;
	return (0);
}

int			alloc_tab(t_mlx *file)
{
	char	*line;
	int		ret;

	line = NULL;
	file->lines = 0;
	file->chars = 0;
	while ((ret = get_next_line(file->fd, &line)) > 0)
	{
		if (helper_all_tab(file, line) == -1)
			return (-1);
	}
	free(line);
	file->map = ft_memalloc(sizeof(int*) * file->lines);
	close(file->fd);
	file->fd = open(file->name, O_RDONLY);
	return (0);
}

int			ft_getmap(t_mlx *file)
{
	char	*line;
	char	**tab;
	int		xytab[3];

	xytab[1] = 0;
	if (alloc_tab(file) == -1)
		return (-1);
	while ((xytab[2] = get_next_line(file->fd, &line)) > 0)
	{
		xytab[0] = 0;
		tab = ft_strsplit(line, ' ');
		free(line);
		file->map[xytab[1]] = ft_memalloc(sizeof(int) * file->chars);
		while (tab[xytab[0]] != NULL)
		{
			file->map[xytab[1]][xytab[0]] = ft_atoi(tab[xytab[0]]);
			free(tab[xytab[0]]);
			xytab[0]++;
		}
		free(tab);
		xytab[1]++;
	}
	free(line);
	return ((xytab[2] == -1) ? -1 : 0);
}
