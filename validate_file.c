/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:24:22 by spentti           #+#    #+#             */
/*   Updated: 2019/12/03 19:02:09 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_line(char *str, int lines)
{
	int					i;

	i = 0;
	if (lines >= 0 && lines % 5 != 0)
	{
		if (ft_strlen(str) != 4)
			return (1);
		while (str[i])
		{
			if (str[i] != '#' && str[i] != '.')
				return (1);
			i++;
		}
	}
	else if (lines % 5 == 0)
	{
		if (ft_strlen(str) != 0)
			return (1);
		if (str[i] != '\0' && str[i] != '\n')
			return (1);
	}
	return (0);
}

int			validate_block(char *tetr)
{
	int					i;
	int					val;
	int					k;

	k = 0;
	val = 0;
	i = -1;
	while (tetr[++i] != '\0')
	{
		if (tetr[i] == '#')
		{
			k++;
			if (tetr[i - 1] == '#' && i - 1 >= 0)
				val++;
			if (tetr[i - 4] == '#' && i - 4 >= 0)
				val++;
			if (tetr[i + 1] == '#' && i + 1 <= 15)
				val++;
			if (tetr[i + 4] == '#' && i + 4 <= 15)
				val++;
		}
	}
	if (k == 4 && (val == 8 || val == 6))
		return (0);
	return (1);
}

t_saved		*create_info(void)
{
	t_saved				*info;

	if (!(info = malloc(sizeof(t_saved))))
		return (NULL);
	info->block_lines = 0;
	info->total_lines = 0;
	info->grid_length = 0;
	info->single_block = NULL;
	info->head = NULL;
	return (info);
}

int			test_valid(t_saved *info, const char *line)
{
	if (ft_strlen(line) == 4)
		info->block_lines += 1;
	if (info->block_lines % 4 == 0 && info->block_lines != 0)
	{
		if (make_blocks(info, 1))
			return (1);
	}
	return (0);
}

int			validate_file(int fd, t_saved *info)
{
	char				*line;
	char				*tmp;
	int					i;

	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		info->total_lines += 1;
		if (check_line(line, info->total_lines))
			return (1);
		if (!info->single_block)
			info->single_block = ft_strdup(line);
		else
		{
			tmp = ft_strjoin(info->single_block, line);
			free(info->single_block);
			info->single_block = tmp;
		}
		if (test_valid(info, line))
			return (1);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
