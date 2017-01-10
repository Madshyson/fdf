/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 19:23:13 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 17:30:33 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char				**set_line(char **split)
{
	int i;
	int j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (split[i][j] == ',')
				split[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (split);
}

static int				data_len(char **data)
{
	int i;

	i = 0;
	while (data[i] != NULL)
		i++;
	return (i);
}

static	t_mapdata		cpy_data(t_mapdata data)
{
	t_mapdata	tmp;
	int			i;
	int			j;

	i = 0;
	tmp.nbl = data.nbl;
	tmp.nbc = data.nbc;
	tmp.map = malloc(sizeof(int *) * tmp.nbl + 1);
	while (i < tmp.nbl)
	{
		j = 0;
		tmp.map[i] = malloc(sizeof(int) * tmp.nbc);
		while (j < tmp.nbc)
		{
			tmp.map[i][j] = data.map[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

static	t_mapdata		get_data(char **line, t_mapdata data, int nl)
{
	int			i;
	int			j;
	t_mapdata	tmp;

	tmp = cpy_data(data);
	tmp.rl = data.rl;
	tmp.zm = data.zm;
	tmp.showmenu = data.showmenu;
	tmp.map[nl] = malloc(sizeof(int) * tmp.nbc);
	i = 0;
	j = 0;
	while (i < tmp.nbc)
	{
		tmp.map[nl][i] = ft_atoi(line[i]);
		i++;
	}
	return (tmp);
}

t_mapdata				setmap(char *line, int nl, t_mapdata data)
{
	char	**split;

	if (testline(line))
	{
		split = ft_strsplit(line, ' ');
		split = set_line(split);
		if (data.nbc == -1)
			data.nbc = data_len(split);
		if (data.nbc != data_len(split))
		{
			data.nbl = -2;
			return (data);
		}
		data = get_data(split, data, nl);
		data.nbl = nl + 1;
	}
	else
		data.nbl = -2;
	return (data);
}
