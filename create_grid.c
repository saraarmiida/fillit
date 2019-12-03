/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:28:16 by spentti           #+#    #+#             */
/*   Updated: 2019/12/03 18:33:49 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		else
			i++;
	}
	if (i != 0)
		return (i);
	return (0);
}

char	*create_grid(t_saved *info, int id)
{
	int		blocks;
	char	*grid;
	int		grid_total;

	if (info->total_lines)
		blocks = info->total_lines / 5;
	if (id == 0)
		info->grid_length = ft_sqrt(blocks * 4);
	grid_total = info->grid_length * info->grid_length;
	grid = ft_strnew(grid_total);
	ft_memset(grid, '.', grid_total);
	return (grid);
}

int		get_base(int offset)
{
	int	base;

	if (offset < 4)
		base = offset;
	if (offset >= 4 && offset < 8)
		base = 4;
	if (offset >= 8 && offset < 12)
		base = 4 * 2;
	if (offset >= 12 && offset < 16)
		base = 4 * 3;
	return (base);
}

int		check_offset(char *grid, int *i_origo, t_block *block, int grid_length)
{
	int base_origo;
	int	base;

	base_origo = i_origo[1];
	base = get_base(block->offset[i_origo[0]]);
	if (i_origo[1] >= grid_length)
		base_origo = i_origo[1] % grid_length;
	if (base < 4)
	{
		if (grid[i_origo[1] + block->offset_mod[i_origo[0]]] != '.' || \
		base_origo + block->offset_mod[i_origo[0]] >= grid_length \
		|| i_origo[1] + block->offset_mod[i_origo[0]] \
		>= (grid_length * grid_length))
			return (1);
	}
	else
	{
		if (grid[i_origo[1] + block->offset_mod[i_origo[0]]] != '.' || \
		base_origo + block->offset_mod[i_origo[0]] \
		>= grid_length * (base / 4 + 1) \
		|| i_origo[1] + block->offset_mod[i_origo[0]] \
		>= (grid_length * grid_length))
			return (1);
	}
	return (0);
}

int		can_place(char *grid, int origo, t_block *block, int grid_length)
{
	int				array[2];
	static int		base;

	array[0] = 0;
	array[1] = origo;
	int_bzero(block->offset_mod, 4);
	while (array[0] < 4)
	{
		base = get_base(block->offset[array[0]]);
		if (base >= 4)
		{
			block->offset_mod[array[0]] = block->offset[array[0]] - \
			base + (grid_length * (base / 4));
		}
		else
			block->offset_mod[array[0]] = block->offset[array[0]];
		if (check_offset(grid, array, block, grid_length))
			return (0);
		array[0]++;
	}
	return (1);
}
