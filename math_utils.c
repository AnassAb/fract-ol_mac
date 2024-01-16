/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassab <anassab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:18:12 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/16 17:54:10 by anassab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	check_convergence(t_mlx mlx, t_vec z, t_vec c)
{
	int		i;
	double	tmp_x;

	i = 0;
	while (i < mlx.f.max_i)
	{
		tmp_x = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * tmp_x * z.y + c.y;
		if ((z.x * z.x + z.y * z.y) > mlx.f.radius * mlx.f.radius)
			return (i);
		i++;
	}
	return (0);
}
