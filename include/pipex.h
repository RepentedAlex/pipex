/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:41:26 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/13 19:43:08 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

typedef enum s_bool
{
    flase,
    true
} t_bool;


typedef struct s_pipex
{
    int     in_fd;
    int     out_fd;
    t_bool  here_doc;
    t_bool  is_invalid_file;
    char    **cmd_paths;
    char    **cmd_args;
    int     cmd_count;
    t_pipex *next;
} t_pipex;


#endif
