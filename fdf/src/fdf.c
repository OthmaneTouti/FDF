/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:57:10 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/08 14:28:44 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main()
{
	void	*mlx_connection;
	void	*mlx_window;
	
	mlx_connection = mlx_init();
	if (!mlx_connection)
		return (1);
	mlx_window = mlx_new_window(mlx_connection, 500, 500, "fdf");
	if (!mlx_window)
	{
		free(mlx_connection);
		return (1);
	}
	free(mlx_connection);
}