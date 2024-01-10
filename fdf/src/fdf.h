/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:58:03 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/10 15:32:57 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "../include/libft.h"
# include <mlx.h>
# include <stdio.h>

//Contains image data
typedef	struct s_img_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img_data;

//Contains mlx data
typedef struct	s_mlx_data {
	void		*mlx;
	void		*win;
	t_img_data	img;
}				t_mlx_data;

//Contains point coordinates
typedef struct	s_point {
	int			x;
	int			y;
	int			z;
}				t_point;

//Contains point coordinates of two points that make an edge
typedef struct s_edge {
	t_point		*p1;
	t_point		*p2;
}				t_edge;

void win_init(void);
int get_map(char *file_name);
void img_init(t_mlx_data *data);

#endif