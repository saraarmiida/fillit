/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:24:11 by spentti           #+#    #+#             */
/*   Updated: 2019/11/13 13:43:45 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct   s_block
{
    int				x[4];
    int				y[4];
	int				size;
    char			block[16 + 1];
    struct s_block	*next;
}                t_block;

typedef struct   s_block
{
    int				x[4];
    int				y[4];
    char			*block;
    struct s_block	*next;
}                t_block;

typedef struct   s_saved
{
    int 	total_lines;
	int 	block_lines;
	int 	block_i;
	char	*single_block;
    char	*blocks[4];
}                t_saved;

int		validate_file(int fd);

#endif