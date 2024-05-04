/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:37:26 by ydoumas           #+#    #+#             */
/*   Updated: 2024/05/04 17:52:33 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, 400, 400, "Fractol");
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, 400, 400);
	mlx->mlx_pixels = mlx_get_data_addr(mlx->mlx_img, &mlx->bit_per_pxl, &mlx->size_line, &mlx->endian);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}
void	help()
{
	ft_putstr_fd("Invalid Arguments\n", 2);
	ft_putstr_fd("Your Input Should Be As Follow: \n", 2);
	ft_putstr_fd("./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol julia real imaginary\n", 2);
	exit(1);
}
int	check_double(char *d)
{
	int	i;
	int j=0;

	i = 0;
	if (d[i] == '-' || d[i] == '+')
		i++;
	if (d[i] == '\0')
		return (0);
	while (d[i])
	{
		if (d[i]=='.')
			j++;
		i++;
	}
	if(j > 1 )
		return(0);
	i = 0;
	while (d[i])
	{
		if ((d[i] < '0' || d[i] > '9') && d[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
double atoid(char *str)
{
	
	size_t	i;
	double	af;
	size_t bef;
	
	int		sign;

	i = 0;
	bef = 0;
	sign = 1;
	af = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		bef = bef * 10 + str[i] - 48;
		i++;
	}
	if( str[i]=='.')
	{
		i++;
		while (str[i])
		{
			af = af * 10 + str[i] - 48;
			i++;
		}
	}
	return (sign*(bef+af/10));
}
int	main(int ac, char **av)
{
	t_data	mlx;
	
	if(!((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4 && !ft_strcmp(av[1], "julia"))))\
		help();
	if(ac ==4)
	{
		if(!check_double(av[2]) || !check_double(av[3]))
		{
			help();
		}
		mlx.real=atoid(av[2]);
		mlx.img=atoid(av[3]);
	}
}