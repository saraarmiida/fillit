/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:27:32 by spentti           #+#    #+#             */
/*   Updated: 2019/11/15 12:32:50 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/includes/libft.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
    int fd;
	t_saved info;
	t_block head;

	//if (argc != 2)
	//    usage something
	argc++;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (1);
	}
	if (validate_file(fd, &info))
	{
		ft_putendl("File not valid.");
		return (-1);
	}
	//make_list(&(info->blocks), &head);

	// solve_file();
	return (0);
}
