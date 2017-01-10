/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:08:59 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 14:49:48 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw(t_map **map, t_mapdata data, t_windata swin)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.nbl)
	{
		j = 0;
		while (j < data.nbc)
		{
			if (i != data.nbl - 1)
				lier(map[i][j], map[i + 1][j], swin, data);
			if (j != data.nbc - 1)
				lier(map[i][j], map[i][j + 1], swin, data);
			if (j != data.nbc - 1 && i != data.nbl - 1 && (j + i) % 2 == 1)
				lier(map[i][j], map[i + 1][j + 1], swin, data);
			if (j != data.nbc - 1 && i != data.nbl - 1 && (j + i) % 2 == 0)
				lier(map[i][j + 1], map[i + 1][j], swin, data);
			j++;
		}
		i++;
	}
}
