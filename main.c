/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-26 16:45:36 by tphuwian          #+#    #+#             */
/*   Updated: 2026-04-26 16:45:36 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start_fractol(t_fractol *fractol)
{
	fractol_init(fractol);
	set_data_init(fractol);
	fractol_render(fractol);
	mlx_loop_hook(fractol->mlx, ft_hook, fractol);
	mlx_scroll_hook(fractol->mlx, ft_scroll_hook, fractol);
	mlx_loop(fractol->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		fractol.name = "mandelbrot";
		start_fractol(&fractol);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		fractol.name = "julia";
		fractol.real = ft_atoi(av[2]);
		fractol.i = ft_atoi(av[3]);
		start_fractol(&fractol);
	}
	else
		ft_putstr_fd("Please try again :( \n", 1);
}
