/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:38:20 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 19:01:38 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_result;

	if (!s || !f)
		return (0);
	i = 0;
	s_result = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s_result)
		return (0);
	while (s[i])
	{
		s_result[i] = f(i, (char)s[i]);
		i++;
	}
	s_result[i] = '\0';
	return (s_result);
}
