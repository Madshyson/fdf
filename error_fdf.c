/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 19:50:47 by mlavanan          #+#    #+#             */
/*   Updated: 2016/03/15 17:04:47 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_fdf(int erindex)
{
	if (erindex == -1)
		ft_putendl("----error----\n-The lecture didn't work properly-");
	else if (erindex == 0)
		ft_putendl("----error----\n-There is a wrong number of argument-");
	else if (erindex == -2)
		ft_putendl("----error----\n-File is not well formated-");
	return (0);
}
