/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:31:36 by spentti           #+#    #+#             */
/*   Updated: 2019/12/03 18:56:45 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block		*set_block(const char *block)
{
	t_block				*moi;
	static int			i;

	moi = (t_block *)malloc(sizeof(*moi));
	moi->str = ft_strdup(block);
	moi->next = NULL;
	moi->abc = 'A' + i++;
	return (moi);
}

int			make_blocks(t_saved *info, int id)
{
	static t_block		*block;

	if (id == 2)
		block = NULL;
	else if (info->block_lines % 4 == 0 && info->block_lines != 0)
	{
		if (info->head == NULL)
		{
			if (!(info->head = set_block(info->single_block)))
				return (1);
			block = info->head;
		}
		else
		{
			block->next = set_block(info->single_block);
			block = block->next;
		}
		ft_strclr(info->single_block);
		if (validate_block(block->str))
			return (1);
		get_xy(block->str, &(block->origo), block->offset);
		info->block_lines = 0;
	}
	return (0);
}
