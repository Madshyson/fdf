/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fnct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:32:53 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 14:49:11 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		**tab_malloc(t_mapdata data)
{
	int **ret;
	int i;

	i = 0;
	ret = malloc(sizeof(int *) * data.nbc);
	while (i < data.nbc)
	{
		ret[i] = malloc(sizeof(int) * data.nbl);
		i++;
	}
	return (ret);
}

t_mapdata		camera_fnct(t_mapdata data)
{
	int **turn;
	int i;
	int j;

	turn = tab_malloc(data);
	i = 0;
	while (i < data.nbc)
	{
		j = 0;
		while (j < data.nbl)
		{
			turn[i][j] = data.map[data.nbl - (j + 1)][i];
			j++;
		}
		i++;
	}
	data.map = turn;
	i = data.nbc;
	data.nbc = data.nbl;
	data.nbl = i;
	return (data);
}

t_mapdata		move_fnct(t_mapdata data, int key)
{
	if (key == 123)
		data.start_x -= 50;
	if (key == 124)
		data.start_x += 50;
	if (key == 125)
		data.start_y += 50;
	if (key == 126)
		data.start_y -= 50;
	return (data);
}

t_mapdata		zoom_fnct(t_mapdata data, int key)
{
	if (key == 78 && data.zm > 0)
		data.zm -= 5;
	if (key == 69)
		data.zm += 5;
	return (data);
}

t_mapdata		relief_fnct(t_mapdata data, int key)
{
	if (key == 116)
		data.rl += 1;
	if (key == 121)
		data.rl -= 1;
	return (data);
}
