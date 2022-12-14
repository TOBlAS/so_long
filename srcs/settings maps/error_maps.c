/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:33:00 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/14 11:17:31 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_x_walls(t_solong *solong)
{
	int	i;
	int	j;

	i = solong->width;
	j = 0;
	while(j < i)
	{
		if (solong->map[0][i] == '1' && solong->map[solong->height - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_y_walls(t_solong *solong)
{
	int	y;
	int	width;

	y = 0;
	width = solong->width;
	while (y < solong->height)
	{
		if (!(solong->map[y][0] == '1' && solong->map[y][width - 1] == '1'))
			return (0);
		y++;
	}
	return (1);
}

int	check_if_walls(t_solong *solong)
{
	int	x; //horizontal
	int	y; //vertical

	y = check_y_walls(solong);
	x = check_x_walls(solong);
	if (!x || !y)
		error_msg(ERROR_WALLS);
}
