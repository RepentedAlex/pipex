/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:36:49 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/13 20:29:30 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * 
*/
void	exit_handler(int n_exit)
{
	if (n_exit == 1)
	{
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", STDERR_FILENO);
	}
	exit(0);
}

/**
 * 
*/
int	open_file(char *file, int io)
{
	int	ret;

	if (io == STDIN_FILENO)
	{
		ret = open(file, O_RDONLY, 0777);
	}
	if (io == STDOUT_FILENO)
	{
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	if (ret == -1)
	{
		exit(0);
	}
	return (ret);
}

/**
 * 
*/
void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/**
 * 
*/
char	*ft_get_env(char *name, char *envp[])
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
		{
			j++;
		}
		sub = ft_substr(envp[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

/**
 * 
*/
char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	*exec;
	char	**all_paths;
	char	*part_path;
	char	**s_cmd;

	i = -1;
	all_paths = ft_split(ft_get_env("PATH", envp), ':');
	s_cmd = ft_split(cmd, ' ');
	while (all_paths[++i])
	{
		part_path = ft_strjoin(all_paths[i], "/");
		exec = ft_strjoin(part_path, s_cmd[0]);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(all_paths);
	ft_free_tab(s_cmd);
	return (cmd);
}