/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:48:20 by spentti           #+#    #+#             */
/*   Updated: 2019/11/13 16:48:20 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
#include "fillit.h"

t_block *make_list(char *blocks, t_block node)
{
	int i;
	t_block head;

	if (!(node = malloc(sizeof(t_block))))
		return (NULL);
	head = node;
	i = 0;
	while (i < 4)
	{
		node->block = blocks[i];
		if (!(node->next = malloc(sizeof(t_block))))
			return (NULL);
		node = node->next;
		i++;
	}
	// count x, y and size and put them to list
}