/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:33:40 by tcaborde          #+#    #+#             */
/*   Updated: 2022/12/14 11:25:38 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_solong	solong;

	if (argc != 2)
		return (0);
	ft_memset(&solong, 0, sizeof(t_solong));
	read_map(&solong, argv);
}
