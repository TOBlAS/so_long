/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:28:48 by tcaborde          #+#    #+#             */
/*   Updated: 2022/12/09 14:29:04 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	h_cpt;
	int	n_cpt;
	int	i;

	if (!ft_memcmp(needle, "", ft_strlen((char *)needle)))
		return ((char *)haystack);
	i = 0;
	while (i < ft_strlen((char *)haystack) && i != (int)len)
	{
		h_cpt = 0;
		n_cpt = 0;
		while (haystack[h_cpt + i] && needle[n_cpt] && h_cpt != (int)len - i)
		{
			if (haystack[h_cpt + i] == needle[n_cpt])
				n_cpt++;
			else
				n_cpt = 0;
			h_cpt++;
		}
		if (needle[n_cpt] == '\0')
			return ((char *)haystack + h_cpt + i - ft_strlen((char *) needle));
		i++;
	}
	return (NULL);
}
