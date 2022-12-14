/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:34:10 by tcaborde          #+#    #+#             */
/*   Updated: 2022/12/14 11:23:29 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

typedef struct t_block
{
	int		fd;
	int		height;
	int		width;
	int		countplayer;
	int		column;
	int		exit;
	int		x;
	int		y;
	int		count;
	int		collectables;

	char	**map;

	void	*player;
	void	*exit;
	void	*collectables;
	void	*window;
	void	*mlx;
}	t_solong;

/*settings maps :
	1. error_maps.c :*/
int			check_x_walls(t_solong *solong);
int			check_y_walls(t_solong *solong);
int			check_if_walls(t_solong *solong);

/*maps.c :*/
static int	width_map(char	*string);
static int	add_line(t_solong *solong, char *line);
int			read_map(t_solong *solong, char **argv);
void		checker(t_solong *solong, int y, int width);
/*errors.c :*/
void		error_msg(char *c, t_solong *solong);
int			exit_game(t_solong *solong);

# define ERROR_WALLS "Map invalide - Mur troué"
# define ERROR_MAP "Maps invalide - Erreur"

#endif
