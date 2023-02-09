/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:55:33 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/02 03:06:59 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_get(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_get(char *s, char to_find)
{
	while (s && *s)
	{
		if (*s == to_find)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen_get(s1);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = (s1)[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_get(char *data, char *buff)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!data)
		return (ft_strdup(buff));
	new_str = malloc((ft_strlen_get(data) + ft_strlen_get(buff)) + 1);
	if (!new_str)
		return (free(data), free(buff), NULL);
	while (data[i])
	{
		new_str[i] = data[i];
		i++;
	}
	while (buff[j])
		new_str[i++] = buff[j++];
	new_str[i] = '\0';
	free(data);
	return (new_str);
}
