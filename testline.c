/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 19:47:29 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 16:31:34 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		testline(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '-')
			i++;
		else if (line[i] == ',')
		{
			while (line[i] != '\0' && line[i] != ' ')
				i++;
		}
		else
			return (0);
	}
	return (1);
}
