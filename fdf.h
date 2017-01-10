/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:46:04 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 14:50:42 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

# define BUFFER 16

typedef struct		s_mapdata
{
	int nbl;
	int nbc;
	int rl;
	int zm;
	int maxheight;
	int start_x;
	int start_y;
	int **map;
	int showmenu;
}					t_mapdata;

typedef struct		s_windata
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		colors[30];
}					t_windata;

typedef struct		s_incr
{
	int		rel;
	int		zoom;
	int		x;
	int		y;
	double	incrx;
	double	incry;
}					t_incr;

typedef struct		s_map
{
	int		height;
	int		pos_x;
	int		pos_y;
}					t_map;

typedef struct		s_env
{
	t_mapdata	edata;
	t_windata	eswin;
	char		*str;
}					t_env;

int					main(int ac, char **av);
t_mapdata			setmap(char *line, int nl, t_mapdata data);
int					error_fdf(int erindex);
int					testline(char *line);
void				fdf(t_mapdata data, char *name);
t_map				**mapinit_iso(t_mapdata data);
void				draw(t_map **map, t_mapdata data, t_windata swin);
void				lier(t_map point1, t_map point2, t_windata swin,
					t_mapdata data);
void				fill_palette(int tab[30]);
void				disp_menu(t_mapdata data, t_windata swin, char *name);
t_mapdata			camera_fnct(t_mapdata data);
t_mapdata			move_fnct(t_mapdata data, int key);
t_mapdata			zoom_fnct(t_mapdata data, int key);
t_mapdata			relief_fnct(t_mapdata data, int key);

#endif
