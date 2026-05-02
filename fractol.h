/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-26 16:44:33 by tphuwian          #+#    #+#             */
/*   Updated: 2026-04-26 16:44:33 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double		real;
	double		i;
}				t_complex;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	char		*name;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		real;
	double		i;
	double		iterations;
}				t_fractol;

// main.c
void			for_mandelbrot(t_fractol *fractol);
void			for_julia(t_fractol *fractol, char *av[]);

// utlis.c
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
double			get_decimal(char *str);
double			ft_atoi(char *str);

// math.c
double			square(double num);
t_complex		handle_z(t_complex z, t_complex c);
double			map(double unscaled_num, double new_min, double new_max,
					double old_max);

// init.c
void			fractol_init(t_fractol *fractol);
void			set_data_init(t_fractol *fractol);
int32_t			get_color(int i, int max);
void			ft_hook(void *para);

// render
void	    render_pixels(int x, int y, t_fractol *fractol);
void	    fractol_render(t_fractol *fractol);
void	    ft_scroll_hook(double xdelta, double ydelta, void *param);

#endif