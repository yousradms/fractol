/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:39:49 by ydoumas           #+#    #+#             */
/*   Updated: 2024/05/04 17:37:12 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	char	*mlx_pixels;
	int		bit_per_pxl;
	int		size_line;
	int		endian;
	double real;
	double img;
} t_data;
int	ft_strcmp(const char *s1, const char *s2);

#endif
