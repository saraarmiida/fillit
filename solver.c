/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:25:32 by spentti           #+#    #+#             */
/*   Updated: 2019/12/03 18:57:20 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place(char *grid, int origo, t_block *block)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[origo + block->offset_mod[i]] = block->abc;
		i++;
	}
}

void	grid_remove(char *grid, int origo, t_block *block)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[origo + block->offset_mod[i]] = '.';
		i++;
	}
}

int		solver(char *grid, t_saved *info, t_block *head)
{
	int		index;
	int		i;

	index = 0;
	i = 0;
	if (head == NULL)
		return (0);
	while (index < info->grid_length * info->grid_length)
	{
		if (can_place(grid, index, head, info->grid_length))
		{
			place(grid, index, head);
			if (solver(grid, info, head->next) == 0)
				return (0);
			else
				grid_remove(grid, index, head);
		}
		index++;
	}
	return (-1);
}
