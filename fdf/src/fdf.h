/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:58:03 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/15 11:25:05 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "../include/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>

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

typedef struct s_map {
	t_point		**points;
	t_edge		**edges;
	int			dimensions[2];
}				t_map;

t_mlx_data *win_init(void);
t_map *get_coords(char *map_path, t_mlx_data *data);
int	key_press(int keycode, t_mlx_data *data);
int	close_win(t_mlx_data *data);
void img_init(t_mlx_data *data);
void	projection(t_map *map, t_mlx_data *data);
int	render_point(t_mlx_data *data, t_map *map);
#endif