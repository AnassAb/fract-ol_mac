/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassab <anassab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:30:48 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/15 11:55:53 by anassab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

clock_t tic, toc;

static void draw_julia(t_mlx *mlx)
{
    int j;
    t_vec   z;

    j = 0;
    while (j < (WIDTH * HEIGHT))
    {
        z.x = ((j % WIDTH) - mlx->f.o.x) * ((mlx->f.radius * 2 / WIDTH) * mlx->f.zoom);
        z.y = ((j / WIDTH) - mlx->f.o.y) * ((mlx->f.radius * 2 / HEIGHT) * mlx->f.zoom);
        *(int*)(mlx->img.addr + (j * 4)) = check_convergence(*mlx, z, mlx->f.c) * 0x150033;
        j++;
    }
}

static void draw_mandelbrot(t_mlx *mlx)
{
    int j;
    t_vec   z;
    t_vec   v;

    v.x = 0;
    v.y = 0;
    j = 0;
    while (j < (WIDTH * HEIGHT))
    {
        z.x = ((j % WIDTH) - mlx->f.o.x) * ((mlx->f.radius * 2 / WIDTH) * mlx->f.zoom);
        z.y = ((j / WIDTH) - mlx->f.o.y) * ((mlx->f.radius * 2 / HEIGHT) * mlx->f.zoom);
        *(int*)(mlx->img.addr + (j * 4)) = check_convergence(*mlx, v, z) * 0x150033;
        j++;
    }
}

void render_fractal(t_mlx *mlx)
{
    mlx->img.ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
    mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.pbits, &mlx->img.sline, &mlx->img.e);
    tic = clock();
    if (mlx->f.id == 1)
        draw_mandelbrot(mlx);
    if (mlx->f.id == 2)
        draw_julia(mlx);
    toc = clock();
    printf("\t[DRAW] time spent: %f\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr,0,0);
}

