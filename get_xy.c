/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:35:22 by spentti           #+#    #+#             */
/*   Updated: 2019/11/29 15:27:19 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	int_bzero(int *array, size_t n)
{
	size_t	i;

	i = 0;
	if (array)
	{
		while (i < n)
		{
			array[i] = 0;
			i++;
		}
	}
}

void	set_xy(int *xy)
{
	if (xy[1] > xy[4])
		xy[4] = xy[1];
	if (xy[2] > xy[3])
		xy[3] = xy[2];
	if (xy[1] <= xy[6])
		xy[6] = xy[1];
	if (xy[2] <= xy[5])
		xy[5] = xy[2];
}

void	set_offset(int *offset, int *origo)
{
	int i;

	i = 0;
	while (i < 4)
	{
		offset[i] = offset[i] - *origo;
		i++;
	}
}

void	get_xy(const char *str, int *origo, int *offset)
{
	int		o;
	int		xy[7];

	o = 0;
	int_bzero(xy, 5);
	xy[5] = 3;
	xy[6] = 3;
	while (str[xy[0]])
	{
		if (str[xy[0]] == '#')
		{
			offset[o++] = xy[0];
			set_xy(xy);
		}
		xy[1]++;
		if (xy[1] % 4 == 0)
		{
			xy[2]++;
			xy[1] = 0;
		}
		xy[0]++;
	}
	*origo = xy[5] * 4 + xy[6];
	set_offset(offset, origo);
}
