/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:42:40 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 17:04:14 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mapdata		init_mapdata(void)
{
	t_mapdata mapdata;

	mapdata.map = NULL;
	mapdata.nbc = -1;
	mapdata.nbl = 0;
	mapdata.rl = 5;
	mapdata.zm = 30;
	mapdata.showmenu = 0;
	return (mapdata);
}

static int				get_maxheight(t_mapdata data)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = data.map[0][0];
	while (i < data.nbl)
	{
		j = 0;
		while (j < data.nbc)
		{
			if (ret < data.map[i][j])
				ret = data.map[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}

static	int				datamanager(int fd, t_mapdata data, char *name)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		data = setmap(line, i, data);
		i++;
		if (data.nbl == -2)
			return (-2);
		free(line);
	}
	if (ret == -1)
		return (-1);
	if (data.nbc == -1)
		return (-2);
	data.maxheight = get_maxheight(data);
	fdf(data, name);
	return (1);
}

int						main(int ac, char **av)
{
	int				fd;
	int				ret;
	t_mapdata		data;

	data = init_mapdata();
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ret = datamanager(fd, data, av[1]);
		if (ret != 1)
			return (error_fdf(ret));
	}
	else
		return (error_fdf(0));
	return (0);
}
