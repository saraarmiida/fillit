/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:24:22 by spentti           #+#    #+#             */
/*   Updated: 2019/11/15 12:51:43 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
#include "fillit.h"

int		check_line(char *str, int lines)
{
	int i;

	i = 0;
	if (ft_strlen(str) != 4 && ft_strlen(str) != 0)
		return (1);
	if (lines >= 0 && lines % 5 != 0)
	{
		while (str[i])
		{
			if (str[i] != '#' && str[i] != '.')
				return (1);
			i++;
		}
	}
	else if (lines % 5 == 0)
	{
		if (str[i] != '\0' && str[i] != '\n')
			return (1);
	}
	return (0);
}

int		validate_block(char *tetr)
{
	int i;
	int val;
	int k;

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
	printf("k : %d, val : %d\n", k, val);
	if (k == 4 && (val == 8 || val == 6))
		return (0);
	return (1);
}

int	make_blocks(t_saved *info)
{
	t_block *block;

	if (info->block_lines % 4 == 0 && info->block_lines != 0)
	{
		if (info->head == NULL)
		{
			if (!(block = (t_block *)malloc(sizeof(t_block))))
				return (1);
			info->head = block;
		}
		else
		{
			block = info->head;
			while (block->next != NULL)
				block = block->next;
			block = block->next;
			if (!(block = (t_block *)malloc(sizeof(t_block))))
				return (1);

		}
		if (!(block->str = ft_strnew(16)))
			return (1);
		block->str = ft_strdup(info->single_block);
		ft_strclr(info->single_block);
		if (validate_block(block->str) == 1)
			return (1);
		info->block_lines = 0;
		info->block_i++;
	}
	return (0);
}

t_saved	*create_info(void)
{
	t_saved	*info;

	if (!(info = malloc(sizeof(t_saved))))
		return (NULL);
	info->block_lines = 0;
	info->total_lines = 0;
	info->block_i = 0;
	info->single_block = NULL;
	info->head = NULL;
	return (info);
}

int	validate_file(int fd, t_saved *info)
{
	char	*line;
	char	*tmp;

	if (!(info = create_info()))
		return (1);
	while ((get_next_line(fd, &line)) > 0)
	{
		info->total_lines++;
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
		if (ft_strlen(line) == 4)
			info->block_lines++;
		if (make_blocks(info))
			return (1);
	}
	return (0);
}
