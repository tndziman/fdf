/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:45:35 by tndziman          #+#    #+#             */
/*   Updated: 2018/08/06 15:28:26 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_line(char *buf)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

int		get_line(const int fd, char *buf, char *ptr[fd])
{
	int			rn;
	char		*tmp_str;

	while ((find_line(buf) != 1) && ((rn = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[rn] = '\0';
		tmp_str = ptr[fd];
		ptr[fd] = ft_strjoin(tmp_str, buf);
		ft_strdel(&tmp_str);
	}
	ft_strdel(&buf);
	if (rn < 0)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			rn;
	char		*tmp_str;
	static char *ptr[2147483647];
	char		*buf;
	char		*str;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	if (!ptr[fd])
		ptr[fd] = ft_strnew(0);
	if ((rn = get_line(fd, buf, ptr)) == -1)
		return (-1);
	if ((str = ft_strchr(ptr[fd], '\n')))
	{
		*line = ft_strsub(ptr[fd], 0, str - ptr[fd]);
		tmp_str = ptr[fd];
		ptr[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp_str);
		return (1);
	}
	*line = ft_strdup(ptr[fd]);
	ft_strdel(&ptr[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
