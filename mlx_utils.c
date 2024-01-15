/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassab <anassab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:17:35 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/15 11:31:41 by anassab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_put_pixel(t_mlx *mlx, int color, int px)
{
	*(unsigned int*)(mlx->img.addr + px) = color;
}

int keypress_handler(int key, t_mlx *mlx)
{
    printf("key pressed : %d\n", key);
    if (key == 65307 || key == 53)
        stop_connection(mlx);
    if (key == 65361 || key == 123) //LEFT : <
		mlx->f.o.x -= 100;
	if (key == 65362 || key == 126) //UP : ^
		mlx->f.o.y -= 100;
	if (key == 65363 || key == 124) //RIGHT : >
		mlx->f.o.x += 100;
	if (key == 65364 || key == 125) //DOWN : v
		mlx->f.o.y += 100;
    render_fractal(mlx, 1);
    return (0);
}

int stop_connection(t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx_ptr, mlx->img.ptr);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_destroy_display(mlx->mlx_ptr);
    free(mlx->mlx_ptr);
    exit (0);
    return (0);
}

int zoom(int btn, int x, int y, t_mlx *mlx)
{
    printf("(%d, %d)\n", x, y);
    if (btn == 4 || btn == 5)
    {
        if (btn == 4)
            mlx->f.zoom *= 1.3;
        else
            mlx->f.zoom *= 0.7;
        render_fractal(mlx, 1);
    }
    return (0);
}
