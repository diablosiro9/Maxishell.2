/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mla-rosa <mla-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:17:01 by mla-rosa          #+#    #+#             */
/*   Updated: 2022/12/06 15:55:07 by mla-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_str(char *s, char c)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (*s == '\0')
			break ;
		else if (s[i] != c)
		{
			nbr++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nbr);
}

static char	*ft_strndup(char const *s, size_t n)
{
	char	*stmp;
	size_t	i;

	i = 0;
	stmp = (char *)malloc(n + 1);
	if (stmp == NULL)
		return (NULL);
	while (i < n)
	{
		stmp[i] = s[i];
		i++;
	}
	stmp[i] = '\0';
	return (stmp);
}

char	**ft_split(char const *s, char c)
{
	
}
