/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:07:18 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/27 19:11:56 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_itoa_utils(int num)
{
	int		len;
	int		tmp_num;
	char	*str_num;

	len = 0;
	tmp_num = num;
	if (num <= 0)
		len++;
	while (tmp_num)
	{
		tmp_num /= 10;
		len++;
	}
	str_num = malloc(len + 1);
	while (len--)
	{
		str_num[len] = num % 10 + '0';
		num /= 10;
	}
	return (str_num);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	count_slash_n(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}
