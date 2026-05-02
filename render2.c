/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 16:17:07 by tphuwian          #+#    #+#             */
/*   Updated: 2026-05-02 16:17:07 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	write_pixel(t_fractol *f, int x, int y, int i)
{
	int			offset;
	uint32_t	color;

	offset = (y * WIDTH + x) * 4;
	color = get_color(i, f->iterations);
	f->img->pixels[offset] = (color >> 24) & 0xFF;
	f->img->pixels[offset + 1] = (color >> 16) & 0xFF;
	f->img->pixels[offset + 2] = (color >> 8) & 0xFF;
	f->img->pixels[offset + 3] = color & 0xFF;
}

static int	get_mandel_iter(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		q;
	int			i;

	q = (c.real - 0.25) * (c.real - 0.25) + c.i * c.i;
	if (q * (q + (c.real - 0.25)) < 0.25 * c.i * c.i)
		return (f->iterations);
	z.real = 0.0;
	z.i = 0.0;
	i = 0;
	while (i < f->iterations && (z.real * z.real + z.i * z.i) < 4.0)
	{
		z = handle_z(z, c);
		i++;
	}
	return (i);
}

void	render_pixels(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	int			i;

	c.real = (map(x, -2.0, 2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
	c.i = (map(y, 2.0, -2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	i = get_mandel_iter(c, fractol);
	write_pixel(fractol, x, y, i);
}
