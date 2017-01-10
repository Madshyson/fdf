/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:10:46 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 14:48:33 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_incr		set_incr(int zoom, int rl)
{
	t_incr incr;

	incr.rel = rl;
	incr.zoom = zoom;
	incr.incrx = cos(30 * M_PI / 180) * incr.zoom;
	incr.incry = sin(30 * M_PI / 180) * incr.zoom;
	incr.incrx = ceil(incr.incrx);
	incr.incry = ceil(incr.incry);
	return (incr);
}

static	t_mapdata	reset_pos(t_mapdata data, t_incr incr)
{
	data.start_y = data.start_y + ((data.nbc + 1) * incr.incry);
	data.start_x = data.start_x - ((data.nbc - 1) * incr.incrx);
	return (data);
}

static	t_map		setpoint(t_mapdata data, t_incr incr)
{
	t_map point;

	point.pos_y = data.start_y - ceil(data.map[incr.y][incr.x] * incr.rel);
	point.pos_x = data.start_x;
	point.height = data.map[incr.y][incr.x];
	return (point);
}

static t_map		**map_malloc(t_mapdata data)
{
	t_map		**init;
	int			i;

	i = 0;
	init = malloc(sizeof(t_map*) * data.nbl);
	while (i < data.nbl)
	{
		init[i] = malloc(sizeof(t_map) * data.nbc + 1);
		i++;
	}
	return (init);
}

t_map				**mapinit_iso(t_mapdata data)
{
	int		i;
	int		j;
	t_map	**map;
	t_incr	incr;

	i = 0;
	incr = set_incr(data.zm, data.rl);
	map = map_malloc(data);
	while (i < data.nbl)
	{
		j = 0;
		while (j < data.nbc)
		{
			incr.y = i;
			incr.x = j;
			map[i][j] = setpoint(data, incr);
			data.start_y = data.start_y - incr.incry;
			data.start_x = data.start_x + incr.incrx;
			j++;
		}
		data = reset_pos(data, incr);
		i++;
	}
	return (map);
}
