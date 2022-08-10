/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:02:38 by jhii              #+#    #+#             */
/*   Updated: 2022/08/10 15:59:02 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_window(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->window.ptr);
	exit(0);
	return (0);
}

int	check_out_of_bounds(t_cub *cub, t_coord coord)
{
	if (coord.x <= 0 || coord.x >= cub->window.width ||
		coord.y <= 0 || coord.y >= cub->window.height)
		return (1);
	return (0);
}

void	draw_pixel(t_cub *cub, t_coord coord)
{
	int		dist;
	char	*dest;

	if (!check_out_of_bounds(cub, coord))
	{
		dist = coord.x * (cub->img.bbp / 8) + coord.y * cub->img.line_len;
		dest = cub->img.addr + dist;
		*(unsigned int *)dest = cub->color;
	}
}

void	draw_square(t_cub *cub, int x, int y, int size, int border)
{
	t_coord	coord;

	for (int i = y + border; i < y + (size - border); i++)
	{
		for (int j = x + border; j < x + (size - border); j++)
		{
			coord.x = j;
			coord.y = i;
			draw_pixel(cub, coord);
		}
	}
}

void	render_map_2d(t_cub *cub)
{
	char	map[10][12] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '0', '0', 'N', '1', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 12; x++) {
			if (map[y][x] == '1')
			{
				cub->color = 0xFFFFFF;
				draw_square(cub, x * 64, y * 64, 64, 1);
			}
		}
	}
}

int	render_game(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img.ptr);
	cub->img.ptr = mlx_new_image(cub->mlx, cub->window.width, cub->window.height);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bbp, &cub->img.line_len, &cub->img.endian);
	render_map_2d(cub);
	cub->color = 0xFFFF00;
	draw_square(cub, cub->player.pos.x, cub->player.pos.y, 12, 0);
	mlx_put_image_to_window(cub->mlx, cub->window.ptr, cub->img.ptr, 0, 0);
	return (0);
}

int	controls(int key, t_cub *cub)
{
	if (key == ESC)
		close_window(cub);
	else if (key == W)
	{
		cub->player.pos.x += cub->player.dist.x * 2;
		cub->player.pos.y += cub->player.dist.y * 2;
	}
	else if (key == S)
	{
		cub->player.pos.x -= cub->player.dist.x * 2;
		cub->player.pos.y -= cub->player.dist.y * 2;
	}
	else if (key == A)
	{
		cub->player.pos.x += cub->player.dist.y * 2;
		cub->player.pos.y += cub->player.dist.x * 2;
	}
	else if (key == D)
	{
		cub->player.pos.x -= cub->player.dist.y * 2;
		cub->player.pos.y -= cub->player.dist.x * 2;
	}
	else if (key == LEFT)
	{
		cub->player.angle -= 0.1;
		if (cub->player.angle < 0)
			cub->player.angle += 2 * M_PI;
		cub->player.dist.x = cos(cub->player.angle) * 2;
		cub->player.dist.y = sin(cub->player.angle) * 2;
	}
	else if (key == RIGHT)
	{
		cub->player.angle += 0.1;
		if (cub->player.angle > 2 * M_PI)
			cub->player.angle -= 2 * M_PI;
		cub->player.dist.x = cos(cub->player.angle) * 2;
		cub->player.dist.y = sin(cub->player.angle) * 2;
	}
	return (0);
}

void	cub3d(t_cub *cub)
{
	cub->window.width = 64 * 12;
	cub->window.height = 64 * 10;
	cub->player.pos.x = 4 * 64 + 27;
	cub->player.pos.y = 3 * 64 + 27;
	cub->player.angle = 3 * M_PI_2;
	cub->player.dist.x = cos(cub->player.angle) * 2;
	cub->player.dist.y = sin(cub->player.angle) * 2;
	cub->mlx = mlx_init();
	cub->window.ptr = mlx_new_window(cub->mlx, cub->window.width, cub->window.height, "cub->d");
	cub->img.ptr = mlx_new_image(cub->mlx, cub->window.width, cub->window.height);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bbp, &cub->img.line_len, &cub->img.endian);
	mlx_put_image_to_window(cub->mlx, cub->window.ptr, cub->img.ptr, 0, 0);
	mlx_hook(cub->window.ptr, 2, 1L<<0, controls, cub);
	mlx_hook(cub->window.ptr, 2, 1L<<0, controls, cub);
	mlx_hook(cub->window.ptr, 17, 1L<<1, close_window, cub);
	mlx_loop_hook(cub->mlx, render_game, cub);
	mlx_loop(cub->mlx);	
}
