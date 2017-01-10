/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:23:59 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/14 18:44:55 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			fill_pallette1(int tab[30])
{
	tab[0] = 0xFFFFFF;
	tab[1] = 0x000000;
	tab[2] = 0x1199CE;
	tab[3] = 0x9E3030;
	tab[4] = 0xff6262;
	tab[5] = 0xff0030;
	tab[6] = 0xfb0000;
	tab[7] = 0xe7ffff;
	tab[8] = 0x0035E5;
	tab[9] = 0x95aeab;
	tab[10] = 0x01B0F0;
	tab[11] = 0xffeb7f;
	tab[12] = 0x71A12F;
	tab[13] = 0x65902a;
	tab[14] = 0x5a8025;
}

static void			fill_pallette2(int tab[30])
{
	tab[15] = 0x4f7020;
	tab[16] = 0x5a8025;
	tab[17] = 0x65902a;
	tab[18] = 0x71A12F;
	tab[19] = 0x8a745a;
	tab[20] = 0x8a745a;
	tab[21] = 0x7d6548;
	tab[22] = 0x7d6548;
	tab[23] = 0x705a40;
	tab[24] = 0xFFFFFF;
	tab[25] = 0xBBBBBB;
	tab[26] = 0x999999;
	tab[27] = 0x888888;
	tab[28] = 0x555555;
	tab[29] = 0x222222;
}

void				fill_palette(int tab[30])
{
	fill_pallette1(tab);
	fill_pallette2(tab);
}
