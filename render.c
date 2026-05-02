/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-26 20:30:40 by tphuwian          #+#    #+#             */
/*   Updated: 2026-04-26 20:30:40 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixels(x, y, fractol);
			x++;
		}
		y++;
	}
}

void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = (t_fractol *)param;
	if (ydelta > 0)
	{
		fractol->zoom *= 0.9;
		fractol->iterations += 5;
	}
	else if (ydelta < 0)
	{
		fractol->zoom *= 1.1;
		fractol->iterations -= 5;
		if (fractol->iterations < 42)
			fractol->iterations = 42;
	}
	if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		fractol_render(fractol);
	else
		fractol_render_julia(fractol);
}

void	render_julia(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			offset;
	uint32_t	color;

	z.real = (map(x, -2.0, 2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.i = (map(y, 2.0, -2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	c.real = fractol->real;
	c.i = fractol->i;
	i = 0;
	while (i < fractol->iterations && (z.real * z.real + z.i * z.i) < 4.0)
	{
		z = handle_z(z, c);
		i++;
	}
	offset = (y * WIDTH + x) * 4;
	color = get_color(i, fractol->iterations);
	fractol->img->pixels[offset] = (color >> 24) & 0xFF;
	fractol->img->pixels[offset + 1] = (color >> 16) & 0xFF;
	fractol->img->pixels[offset + 2] = (color >> 8) & 0xFF;
	fractol->img->pixels[offset + 3] = color & 0xFF;
}

void	fractol_render_julia(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_julia(x, y, fractol);
			x++;
		}
		y++;
	}
}

void	ft_hook_julia(void *para)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)para;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
	{
		fractol->shift_y += (0.1 * fractol->zoom);
		fractol_render_julia(fractol);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
	{
		fractol->shift_y -= (0.1 * fractol->zoom);
		fractol_render_julia(fractol);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
	{
		fractol->shift_x -= (0.1 * fractol->zoom);
		fractol_render_julia(fractol);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		fractol->shift_x += (0.1 * fractol->zoom);
		fractol_render_julia(fractol);
	}
}
