/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lier.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:12:37 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 14:46:04 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_line1(t_windata swin, t_map p1, t_map p2, int max)
{
	int x;
	int y;

	x = p1.pos_x;
	while (x < p2.pos_x)
	{
		y = p1.pos_y + ((p2.pos_y - p1.pos_y) *
		(x - p1.pos_x)) / (p2.pos_x - p1.pos_x);
		if (p2.height < 0 || p1.height < 0)
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[29]);
		else if (p2.height == 0 || p1.height == 0)
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[28]);
		else if (p2.height <= (max / 3) || p1.height <= (max / 3))
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[27]);
		else if (p2.height < ((max / 3) * 2) || p1.height < ((max / 3) * 2))
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[25]);
		else
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[24]);
		x++;
	}
}

void			draw_line2(t_windata swin, t_map p1, t_map p2, int max)
{
	int x;
	int y;

	y = p1.pos_y;
	while (y < p2.pos_y)
	{
		x = p1.pos_x + ((p2.pos_x - p1.pos_x) *
		(y - p1.pos_y)) / (p2.pos_y - p1.pos_y);
		if (p2.height < 0 || p1.height < 0)
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[29]);
		else if (p1.height == 0)
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[28]);
		else if (p2.height <= (max / 3) || p1.height <= (max / 3))
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[27]);
		else if (p2.height < ((max / 3) * 2) || p1.height < ((max / 3) * 2))
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[25]);
		else
			mlx_pixel_put(swin.mlx, swin.win, x, y, swin.colors[24]);
		y++;
	}
}

void			lier(t_map p1, t_map p2, t_windata swin, t_mapdata data)
{
	int x;
	int y;

	x = p1.pos_x - p2.pos_x;
	y = p1.pos_y - p2.pos_y;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
	{
		if (p1.pos_x <= p2.pos_x)
			draw_line1(swin, p1, p2, data.maxheight);
		else
			draw_line1(swin, p2, p1, data.maxheight);
	}
	else
	{
		if (p1.pos_y < p2.pos_y)
			draw_line2(swin, p1, p2, data.maxheight);
		else
			draw_line2(swin, p2, p1, data.maxheight);
	}
}
