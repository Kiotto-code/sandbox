/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:50:22 by jhii              #+#    #+#             */
/*   Updated: 2022/08/10 15:55:41 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define RAD	0.0174533

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	LEFT = 123,
	RIGHT = 124,
	ESC = 53
};

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_plyr
{
	t_coord	pos;
	t_coord	dist;
	double	angle;
}	t_plyr;

typedef struct s_ray
{
	t_coord	pos;
	t_coord	dist;
	double	angle;
}	t_ray;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_win
{
	void	*ptr;
	int		width;
	int		height;
}	t_win;

typedef struct s_cub
{
	int		color;
	void	*mlx;
	t_img	img;
	t_ray	ray;
	t_win	window;
	t_plyr	player;
	t_coord	line[2];
}	t_cub;

void	cub3d(t_cub *cub);


#endif