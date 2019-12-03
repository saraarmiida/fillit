/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:27:32 by spentti           #+#    #+#             */
/*   Updated: 2019/12/03 18:57:12 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_result(const char *grid, int grid_length)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (i < grid_length * grid_length)
	{
		x = 0;
		while (x <= grid_length)
		{
			if (x == grid_length)
				ft_putchar('\n');
			else
				ft_putchar(grid[i++]);
			x++;
		}
	}
}

void	print_usage(void)
{
	ft_putstr("usage: fillit [file_name]\n");
	exit(0);
}

void	open_validate(char *argv, t_saved *info)
{
	int fd;
	int i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	if (validate_file(fd, info))
	{
		ft_putstr("error\n");
		exit(-1);
	}
	i = info->total_lines;
	if (i > 130 || i < 4 || i % 5 != 0)
	{
		ft_putstr("error\n");
		exit(-1);
	}
}

int		main(int argc, char **argv)
{
	t_saved *info;
	char	*grid;

	if (argc != 2)
		print_usage();
	if (!(info = create_info()))
		return (1);
	open_validate(argv[1], info);
	grid = create_grid(info, 0);
	while (1)
	{
		if (solver(grid, info, info->head) == 0)
			break ;
		else
		{
			ft_strdel(&grid);
			(info->grid_length)++;
			grid = create_grid(info, 1);
		}
	}
	print_result(grid, info->grid_length);
	ft_strdel(&grid);
	return (0);
}
