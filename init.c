/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-26 19:32:27 by tphuwian          #+#    #+#             */
/*   Updated: 2026-04-26 19:32:27 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->name, false);
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->mlx)
	{
		mlx_terminate(fractol->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) == -1)
	{
		mlx_terminate(fractol->mlx);
		exit(EXIT_FAILURE);
	}
}

void	set_data_init(t_fractol *fractol)
{
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
	fractol->iterations = 42.0;
}

int32_t	get_color(int i, int max)
{
	int	r;
	int	g;
	int	b;

	if (i == max)
		return (0x000000FF);
	r = (i * 7) % 256;
	g = (i * 3) % 256;
	b = (i * 11) % 256;
	return (r << 24 | g << 16 | b << 8 | 255);
}

static void	handle_move(t_fractol *fractol)
{
	double	step;

	step = 0.1 * fractol->zoom;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->shift_y -= step;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->shift_y += step;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->shift_x -= step;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->shift_x += step;
    fractol_render(fractol);
}

void	ft_hook(void *para)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)para;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		handle_move(fractol);
	}
}
