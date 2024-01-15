/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:58:03 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/15 13:17:42 by ottouti          ###   ########.fr       */
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
typedef struct s_plot_line_tools {
	int			dx;
	int			dy;
	int			yi;
	int			xi;
	int			d;
}				t_plot_line_tools;

typedef struct s_map {
	t_point		**points;
	int			dimensions[2];
}				t_map;

t_mlx_data *win_init(void);
t_map *get_coords(char *map_path, t_mlx_data *data);
int	key_press(int keycode, t_mlx_data *data);
int	close_win(t_mlx_data *data);
int ft_max(int a, int b);
void img_init(t_mlx_data *data);
void	ft_put_pixel(t_mlx_data *data, uint32_t x, uint32_t y, uint32_t color);
void	projection(t_map *map, t_mlx_data *data);
void	img_pix_put(t_img_data *img, int x, int y, int color);
void plot_map(t_mlx_data *data, t_map *map);
int	render_point(t_mlx_data *data, t_map *map);
#endif