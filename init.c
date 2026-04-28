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
	int	a;

	if (i == max)
		return (0x000000FF);
	r = (i * 3) % 256;
	g = (i * 5) % 256;
	b = (i * 8) % 256;
	a = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	render_pixels(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	t_complex	z;
	uint32_t	color;
	int			i;

	i = 0;
	c.real = (map(x, -2.0, 2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
	c.i = (map(y, 2.0, -2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	z.real = 0.0;
	z.i = 0.0;
	while (i < fractol->iterations)
	{
		z = handle_z(z, c);
		if ((z.real * z.real) + (z.i * z.i) > 4.0)
			break ;
		i++;
	}
	color = get_color(i, fractol->iterations);
	mlx_put_pixel(fractol->img, x, y, color);
}

void	ft_hook(void *para)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)para;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
	{
		fractol->shift_y -= (0.1 * fractol->zoom);
		fractol_render(fractol);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
	{
		fractol->shift_y += (0.1 * fractol->zoom);
		fractol_render(fractol);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
	{
		fractol->shift_x -= (0.1 * fractol->zoom);
		fractol_render(fractol);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		fractol->shift_x += (0.1 * fractol->zoom);
		fractol_render(fractol);
	}
}
