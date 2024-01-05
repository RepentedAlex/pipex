/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:36:49 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/05 17:47:20 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_file(char	*file, int io)
{
	int	ret;

	if (io == 0)
		ret = open(file, O_RDONLY, 0777);
	if (io == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (io == -1)
		exit(0);
	return (ret);
}

char	*get_env(char *name, char **envp)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (strcmp(sub, name) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}
