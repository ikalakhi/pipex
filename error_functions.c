/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:20:55 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/20 10:20:57 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	f_error(int id)
{
	if (id == -1)
	{
		perror("invalid fork");
		exit(EXIT_FAILURE);
	}
}

void	error(void)
{
	perror("zsh");
	exit(EXIT_FAILURE);
}
