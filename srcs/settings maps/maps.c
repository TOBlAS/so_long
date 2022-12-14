/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:23:11 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/14 13:11:55 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


/*Calcul de la largeur de la map*/
static int	width_map(char	*string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
			width++;
	if (string[width - 1] == '\n')
			width--;
	return (width);
}

static int	add_line(t_solong *solong, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	solong->height++;
	tmp = (char **)malloc(sizeof(char *) * (solong->height + 1));
	if (!tmp)
		return (NULL);
	tmp[solong->height] = NULL;
	while (i < solong->height - 1)
	{
		tmp[i] = solong->map[i];
		i++;
	}
	tmp[i] = line;
	if (solong->map)
		free(solong->map);
	solong->map = tmp;
	return (1);
}

int	read_map(t_solong *solong, char **argv)
{
	char	*readmap;

	solong->fd = open(argv[1], O_RDONLY);
	if (solong->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(solong->fd);
		if (!add_line(solong, readmap))
			break ;
	}
	close (solong->fd);
	solong->width = width_map(solong->map[0]);
	return (1);
}

void	checker(t_solong *solong, int y, int width)
{
	if (solong->map[y][width] != '1' &&
			solong->map[y][width] != '0' &&
			solong->map[y][width] != 'P' &&
			solong->map[y][width] != 'E' &&
			solong->map[y][width] != 'C' &&
			solong->map[y][width] != '\n')
		error_msg(ERROR_MAP, solong);
	if (solong->map[y][width] == 'C')
		solong->collectables++;
	if (solong->map[y][width] == 'P')
		solong->player++;
	if (solong->map[y][width] == 'E')
		solong->exit++;
}
