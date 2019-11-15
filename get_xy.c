/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:35:22 by spentti           #+#    #+#             */
/*   Updated: 2019/11/15 16:41:01 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	set_xy(int *x, int *y, int *y_max, int *x_max, int *y_min, int *x_min)
{
	if (*x > *x_max)
		*x_max = *x;
	if (*y > *y_max)
		*y_max = *y;
	if (*x <= *x_min)
		*x_min = *x;
	if (*y <= *y_min)
		*y_min = *y;
}

void	get_xy(const char *str, int *origo, int *offset)
{
	int		o;
	int		xy[7];

	o = 0;
	xy[0] = 0; //i
	xy[1] = 0; //x
	xy[2] = 0; //y
	xy[3] = xy[2]; //y_max
	xy[4] = xy[1]; //x_max
	xy[5] = 3; //y_min
	xy[6] = 3; //x_min
	while (str[xy[0]])
	{
		if (str[xy[0]] == '#')
		{
			offset[o++] = xy[0];
			set_xy(&xy[1], &xy[2], &xy[3], &xy[4], &xy[5], &xy[6]);
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
	xy[0] = 0;
	while (xy[0] < 4)
	{
		offset[xy[0]] = offset[xy[0]] - *origo;
		xy[0]++;
	}
	printf("Max x,y is %d,%d | Min x,y is %d,%d\n", xy[3], xy[4], xy[5], xy[6]);
}
