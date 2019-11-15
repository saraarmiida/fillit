/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:24:11 by spentti           #+#    #+#             */
/*   Updated: 2019/11/15 12:40:31 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct   s_block
{
    int				x[4];
    int				y[4];
	int				size;
    char			*str;
    struct s_block	*next;
}                t_block;

typedef struct   s_saved
{
    int 	total_lines;
	int 	block_lines;
	int 	block_i;
	char	*single_block;
    struct s_block	*head;
}                t_saved;

int		validate_file(int fd, t_saved *info);

#endif