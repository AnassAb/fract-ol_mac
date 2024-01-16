/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassab <anassab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:22 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/16 17:56:38 by anassab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
}

static int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	check_constant(char *x)
{
	int	i;
	int	pts;

	i = 0;
	pts = 0;
	while (x[i])
	{
		if (!(ft_isdigit(x[i]) || (!pts && x[i] == '.')))
			return (0);
		if (x[i] == '.')
			pts = 1;
		i++;
	}
	return (1);
}
