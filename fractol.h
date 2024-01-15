/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassab <anassab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:44:58 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/15 11:04:35 by anassab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

#include "mlx/mlx.h"
// #include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct  vector_coor
{
    double  x;
    double  y;
}   t_vec;

typedef struct img_data
{
    void    *ptr;
    void    *addr;
    int     pbits;
    int     sline;
    int     e;
}   t_img;

typedef struct fractal_data
{
    double  zoom;
    double  radius;
    int     id;
    int     max_i;
    t_vec   o;
    t_vec   c;
}   t_fractal;

typedef struct mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
    t_fractal   f;
}   t_mlx;

//STRING UTILS
float   ft_atof(char *s);
void    ft_putstr(char *str);
int     ft_strcmp(char *s1, char *s2);
int		check_constant(char *x);

//MATH UTILS
double  check_convergence(t_mlx mlx, t_vec z, t_vec c);

//MLX UTILS
void    my_put_pixel(t_mlx *mlx, int color, int px);
int     keypress_handler(int key, t_mlx *mlx);
int     stop_connection(t_mlx *mlx);
int     zoom(int button, int x, int y, t_mlx *mlx);

//DRAWING UTILS
void    render_fractal(t_mlx *mlx, int nb);

#endif