/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:24:11 by spentti           #+#    #+#             */
/*   Updated: 2019/12/03 18:52:48 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_block
{
	int				origo;
	int				offset[4];
	int				offset_mod[4];
	char			*str;
	char			abc;
	int				status;
	int				grid_length;
	struct s_block	*next;
}					t_block;

typedef struct		s_saved
{
	int				total_lines;
	int				block_lines;
	char			*single_block;
	int				grid_length;
	struct s_block	*head;
}					t_saved;

t_saved				*create_info(void);
int					validate_file(int fd, t_saved *info);
void				get_xy(const char *str, int *origo, int *offset);
char				*create_grid(t_saved *info, int id);
int					solver(char *grid, t_saved *info, t_block *head);
void				tester(char *grid, t_saved *info, t_block *head);
int					can_place(char *grid, int origo, \
					t_block *block, int grid_length);
int					make_blocks(t_saved *info, int id);
int					validate_block(char *tetr);
void				int_bzero(int *array, size_t n);
void				print_result(const char *grid, int grid_length);

#endif
