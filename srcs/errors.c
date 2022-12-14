/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:19:32 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/14 11:21:02 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(char *c, t_solong *solong)
{
	perror(c);
	exit_game(solong);
}

int	exit_game(t_solong *solong)
{
	int	ligne;

	ligne = 0;
	if (solong->window)
		mlx_destroy_window(solong->mlx, solong->window);
	free(solong->window);
	while (ligne < solong->height - 1)
		free(solong[ligne++]);
	free(solong->map);
	exit(0);
}
