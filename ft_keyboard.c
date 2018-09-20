/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:11:19 by tndziman          #+#    #+#             */
/*   Updated: 2018/08/15 14:23:09 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cross(void)
{
	exit(0);
	return (0);
}

void	decal(int keycode, t_mlx *key)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 15)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 123)
			key->dx -= 10;
		if (keycode == 126)
			key->dy -= 10;
		if (keycode == 124)
			key->dx += 10;
		if (keycode == 125)
			key->dy += 10;
		if (keycode == 15)
			key->check = 0;
		draw(key);
	}
}

int		keyboard(int keycode, t_mlx *key)
{
	if (keycode == 53)
		cross();
	if (keycode == 121)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		draw(key);
	}
	if (keycode == 116)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		draw(key);
	}
	if (keycode == 8)
	{
		mlx_clear_window(key->mlx, key->win);
		if (key->check % 11 == 0)
			key->color = 0xFF000000;
		key->color = key->color >> 2;
		draw(key);
	}
	zoom(keycode, key);
	decal(keycode, key);
	return (0);
}

void	mlx(t_mlx *key)
{
	key->check = 0;
	key->mlx = mlx_init();
	key->win = mlx_new_window(key->mlx, WIDTH, HEIGHT, "Fdf");
	draw(key);
	mlx_key_hook(key->win, keyboard, key);
	mlx_hook(key->win, 17, (1L << 17), cross, key);
	mlx_loop(key->mlx);
}
