/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:25:32 by tndziman          #+#    #+#             */
/*   Updated: 2018/08/15 15:52:28 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# define WIDTH 1280
# define HEIGHT 1040

typedef struct		s_mlx
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				check;
	int				chars;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	unsigned long	color;
}					t_mlx;

void				draw(t_mlx *draw);
void				draw_lines(t_mlx *draw, int x, int y);
void				check_env(t_mlx *draw);
void				draw_line(t_mlx *draw, int *tabxy, int x, int y);
void				mlx(t_mlx *key);
int					keyboard(int keycode, t_mlx *key);
void				decal(int keycode, t_mlx *key);
int					cross(void);
void				zoom(int keycode, t_mlx *key);
void				error_handle(t_mlx *file);
int					ft_getmap(t_mlx *file);
int					alloc_tab(t_mlx *file);
int					helper_all_tab(t_mlx *parse, char *line);
int					check_line(char *str, int y, int save);
int					val_return(int y, int nb, int save);

#endif
