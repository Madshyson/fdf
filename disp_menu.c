/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:03:18 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 14:58:18 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_input(t_windata swin)
{
	mlx_string_put(swin.mlx, swin.win, 27, 150,
	swin.colors[7], "swap camera:");
	mlx_string_put(swin.mlx, swin.win, 160, 150, swin.colors[7], "1");
	mlx_string_put(swin.mlx, swin.win, 35, 175,
	swin.colors[1], "-------------");
	mlx_string_put(swin.mlx, swin.win, 27, 200, swin.colors[7], "zoom :");
	mlx_string_put(swin.mlx, swin.win, 100, 200, swin.colors[7], "+");
	mlx_string_put(swin.mlx, swin.win, 140, 200, swin.colors[7], "-");
	mlx_string_put(swin.mlx, swin.win, 35, 225,
	swin.colors[1], "-------------");
	mlx_string_put(swin.mlx, swin.win, 27, 250, swin.colors[7], "relief:");
	mlx_string_put(swin.mlx, swin.win, 100, 250, swin.colors[7], "up");
	mlx_string_put(swin.mlx, swin.win, 135, 250, swin.colors[7], "down");
}

static void		put_info(t_mapdata data, t_windata swin, char *name)
{
	char *s1;
	char *s2;
	char *s3;
	char *s4;

	s1 = ft_strjoin("x:", ft_itoa(swin.size_x));
	s2 = ft_strjoin("y:", ft_itoa(swin.size_y));
	s3 = ft_strjoin("nbl:", ft_itoa(data.nbl));
	s4 = ft_strjoin("nbc:", ft_itoa(data.nbc));
	mlx_string_put(swin.mlx, swin.win, 35, 30, swin.colors[7], name);
	mlx_string_put(swin.mlx, swin.win, 35, 50,
	swin.colors[1], "-------------");
	mlx_string_put(swin.mlx, swin.win, 27, 75, swin.colors[7], s1);
	mlx_string_put(swin.mlx, swin.win, 102, 75, swin.colors[7], s2);
	mlx_string_put(swin.mlx, swin.win, 27, 100, swin.colors[7], s3);
	mlx_string_put(swin.mlx, swin.win, 102, 100, swin.colors[7], s4);
	mlx_string_put(swin.mlx, swin.win, 35, 125,
	swin.colors[1], "-------------");
}

static void		draw_box(t_windata swin)
{
	int x;
	int y;

	y = 20;
	while (y <= 280)
	{
		x = 20;
		while (x <= 180)
		{
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[8]);
			x++;
		}
		y++;
	}
}

void			disp_menu(t_mapdata data, t_windata swin, char *name)
{
	draw_box(swin);
	put_info(data, swin, name);
	put_input(swin);
}
