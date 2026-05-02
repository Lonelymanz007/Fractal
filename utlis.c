/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-26 16:47:21 by tphuwian          #+#    #+#             */
/*   Updated: 2026-04-26 16:47:21 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && (s2[i] && i < n - 1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

double	get_decimal(char *str)
{
	int		i;
	double	fraction;
	double	ans;

	i = 0;
	ans = 0;
	fraction = 1.0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			fraction /= 10;
			ans = ans + ((str[i] - '0') * fraction);
			i++;
		}
	}
	return (ans);
}

double	ft_atoi(char *str)
{
	int		i;
	double	ans;
	double	sign;
	double	fraction;

	i = 0;
	sign = 1.0;
	ans = 0.0;
	fraction = get_decimal(str);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	return ((ans + fraction) * sign);
}
