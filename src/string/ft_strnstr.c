/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 06:12:56 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/03 01:47:02 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		len1;
	size_t		len2;

	if (str1[0] == '\0')
		return ((char *)str1);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	while (*str1 != '\0' && len1 >= len2 && len2 <= n)
	{
		if (*str1 == *str2)
		{
			if (ft_memcmp((char *)str1, str2, len2) == 0)
				return ((char *)str1);
		}
		n--;
		len1--;
		str1++;
	}
	return (NULL);
}