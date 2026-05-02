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

void	render_pixels(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	t_complex	z;
	int			i;

	if (ft_strncmp(fractol->name , "mandelbrot", 10) == 0)
	{
		c.real = (map(x, -2.0, 2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
		c.i = (map(y, 2.0, -2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
		z.real = 0.0;
		z.i = 0.0;
	}
	else
	{
		z.real = (map(x, -2.0, 2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
		z.i = (map(y, 2.0, -2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
		c.real = fractol->real;
		c.i = fractol->i;
	}
	i = 0;
	while (i < fractol->iterations && (z.real * z.real + z.i * z.i) < 4.0)
	{
		z = handle_z(z, c);
		i++;
	}
	mlx_put_pixel(fractol->img, x, y, get_color(i, fractol->iterations));
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

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

	fractol = (t_fractol *)param;
	if (ydelta > 0)
		fractol->zoom *= 0.9;
	else if (ydelta < 0)
		fractol->zoom *= 1.1;
	fractol_render(fractol);
	(void)xdelta;
}
