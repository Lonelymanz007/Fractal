/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-26 16:58:53 by tphuwian          #+#    #+#             */
/*   Updated: 2026-04-26 16:58:53 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	square(double num)
{
	return (num * num);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	handle_z(t_complex z, t_complex c)
{
	t_complex	z_next;

	z_next.real = (square(z.real) - square(z.i)) + c.real;
	z_next.i = 2 * (z.real * z.i) + c.i;
	return (z_next);
}
