/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:26:41 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 14:55:57 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_env				*init_env(t_mapdata data, t_windata swin, char *n)
{
	t_env *env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->edata = data;
	env->eswin = swin;
	env->str = ft_strdup(n);
	if (!env->str)
		env->str = NULL;
	return (env);
}

static int					key_funct(int keycode, t_env *env)
{
	t_map **map;

	if (keycode == 53)
		exit(1);
	if (keycode == 18)
		env->edata = camera_fnct(env->edata);
	if (keycode == 78 || keycode == 69)
		env->edata = zoom_fnct(env->edata, keycode);
	if (keycode == 116 || keycode == 121)
		env->edata = relief_fnct(env->edata, keycode);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		env->edata = move_fnct(env->edata, keycode);
	if (keycode == 12)
		env->edata.showmenu += 1;
	map = mapinit_iso(env->edata);
	mlx_clear_window(env->eswin.mlx, env->eswin.win);
	draw(map, env->edata, env->eswin);
	if (env->edata.showmenu % 2 == 0)
		disp_menu(env->edata, env->eswin, env->str);
	return (0);
}

static t_windata			init_mlx(char *name, t_mapdata data)
{
	t_windata swin;

	swin.size_x = 400 + data.nbc * 50;
	swin.size_y = 300 + data.nbl * 50;
	if (swin.size_x > 2000)
		swin.size_x = 2000;
	if (swin.size_y > 1700)
		swin.size_y = 1700;
	fill_palette(swin.colors);
	swin.mlx = mlx_init(0);
	swin.win = mlx_new_window(swin.mlx, swin.size_x, swin.size_y, name);
	return (swin);
}

void						fdf(t_mapdata data, char *name)
{
	t_windata	swin;
	t_map		**map;
	t_env		*env;

	swin = init_mlx(name, data);
	data.start_x = 200;
	data.start_y = swin.size_y / 2;
	map = mapinit_iso(data);
	env = init_env(data, swin, name);
	mlx_key_hook(swin.win, key_funct, env);
	draw(map, data, swin);
	if (env->edata.showmenu % 2 == 0)
		disp_menu(env->edata, env->eswin, env->str);
	mlx_loop(swin.mlx);
}
