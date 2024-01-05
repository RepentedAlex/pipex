/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:41:21 by apetitco          #+#    #+#             */
/*   Updated: 2024/01/05 18:10:33 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
 * argv[0]	= Executable
 * argv[1]	= file1	: Input file
 * argv[2]	= cmd1
 * argv[3]	= cmd2
 * argv[4]	= file2	: Output file
*/

parsing()
{
	char	*PATH_envp;
	char	**mypaths;
	char	**
}

child_process(f1, cmd1)
{
	dup2(0, f1);
	dup2(f1, 0);
	close(end[0]);
}

parent_process(f2, cmd2)
{

}

int	main(int argc, char *argv[], char *envp[])
{
	int		end[2];
	pid_t	parent;

	if (argc != 5)
	{
		printf("Usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n");
		return (1);
	}
	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		child_process(f1, cmd1);
	else
		parent_process(f2, cmd2);
	return (0);
}
