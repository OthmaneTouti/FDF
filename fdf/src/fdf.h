/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:58:03 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:35:18 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "../include/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
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
	int			width;
	int			height;
	t_img_data	img;
}				t_mlx_data;

//Contains point coordinates
typedef struct	s_point {
	int			x;
	int			y;
	int			z;
}				t_point;

//Contains point coordinates of two points that make an edge
typedef struct s_plot_line_tools {
	int			dx;
	int			dy;
	int			yi;
	int			xi;
	int			d;
}				t_plot_line_tools;

typedef struct s_map {
	t_point	**points;
	int			dimensions[2];
	int			min[2];
	int			max[2];
	float		scale;
}				t_map;

t_mlx_data *win_init();
t_map *get_coords(char *map_path);
int	key_press(int keycode, t_mlx_data *data);
int	close_win(t_mlx_data *data);
float ft_max(float a, float b);
void img_init(t_mlx_data *data);
void find_min_max(t_map *map);
void	ft_put_pixel(t_mlx_data *data, uint32_t x, uint32_t y, uint32_t color, t_map *map);
void	projection(t_map *map);
void plot_map(t_mlx_data *data, t_map *map);
void scale(t_map *map);
float	ft_min(float a, float b);
#endif