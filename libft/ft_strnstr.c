/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:29:41 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/01 15:39:06 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_str(const char *hstk, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (hstk[i] && i < len)
	{
		if (ndl[0] == hstk[i])
		{
			j = 0;
			while (hstk[i + j] == ndl[j] && i + j < len)
			{
				if (ndl[j + 1] == '\0')
					return ((char *)(hstk + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hstk;
	char	*ndl;

	hstk = (char *)haystack;
	ndl = (char *)needle;
	if (len == 0 && !haystack)
		return (NULL);
	if (ndl[0] == '\0')
		return (hstk);
	return (get_str(hstk, ndl, len));
}
